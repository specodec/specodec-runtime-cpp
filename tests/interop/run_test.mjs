import { execSync } from 'child_process';
import { existsSync, mkdirSync, rmSync, readdirSync, copyFileSync } from 'fs';
import { join, dirname } from 'path';
import { fileURLToPath } from 'url';

const __dir = dirname(fileURLToPath(import.meta.url));
const VEC_DIR = process.env.VEC_DIR || join(__dir, '.tests-cache', 'vectors');
const OUT_DIR = process.env.OUT_DIR || join(__dir, 'output');
const EMIT_GEN = join(__dir, 'emit_gen');
const SRC = join(__dir, '..', '..', 'src', 'specodec');
const BUILD = join(__dir, 'emit', 'build');

function run(cmd) {
  console.log('  >', cmd);
  execSync(cmd, { stdio: 'inherit' });
}

function findMisePkg(pkgName, subpath) {
  const base = `/root/.local/share/mise/installs/${pkgName}`;
  const dirs = readdirSync(base).filter(d => d !== 'latest' && !d.startsWith('.')).sort();
  const latest = dirs[dirs.length - 1];
  return `${base}/${latest}/${subpath}`;
}

const CXX = process.env.CXX || 'clang --driver-mode=g++';
const LIBCXX_INCLUDE = process.env.LIBCXX_INCLUDE || findMisePkg('conda-libcxx-devel', 'include/c++/v1');
const STD_CPPM = process.env.STD_CPPM || findMisePkg('conda-libcxx-devel', 'share/libc++/v1/std.cppm');
const LIBCXX_LIB = process.env.LIBCXX_LIB || findMisePkg('conda-libcxx', 'lib');
const CXXFLAGS = `-std=c++23 -stdlib=libc++ -I${LIBCXX_INCLUDE} -L${LIBCXX_LIB}`;

if (!existsSync(BUILD)) mkdirSync(BUILD, { recursive: true });

console.log('=== Step 1: Precompile std module ===');
run(`${CXX} ${CXXFLAGS} --precompile -x c++-module "${STD_CPPM}" -o ${BUILD}/std.pcm`);

let MFLAGS = `${CXXFLAGS} -fmodule-file=std=${BUILD}/std.pcm`;

function compileModule(moduleName, src) {
  const pcm = join(BUILD, `${moduleName}.pcm`);
  const obj = join(BUILD, `${moduleName}.o`);
  console.log(`--- ${moduleName} ---`);
  run(`${CXX} ${MFLAGS} --precompile -x c++-module ${src} -o ${pcm}`);
  run(`${CXX} ${MFLAGS} -c ${pcm} -o ${obj}`);
  MFLAGS += ` -fmodule-file=${moduleName}=${pcm}`;
}

// Order matters
const runtimeModules = [
  ['specodec.scodec_error',      join(SRC, 'scodec_error.cppm')],
  ['specodec.spec_reader',       join(SRC, 'spec_reader.cppm')],
  ['specodec.spec_writer',       join(SRC, 'spec_writer.cppm')],
  ['specodec.ryu.tables_f32',    join(SRC, 'ryu', 'tables_f32.cppm')],
  ['specodec.ryu.tables_f64',    join(SRC, 'ryu', 'tables_f64.cppm')],
  ['specodec.ryu.math',          join(SRC, 'ryu', 'ryu_math.cppm')],
  ['specodec.ryu.f32',           join(SRC, 'ryu', 'ryu_f32.cppm')],
  ['specodec.ryu.f64',           join(SRC, 'ryu', 'ryu_f64.cppm')],
  ['specodec.float_fmt',         join(SRC, 'float_fmt.cppm')],
  ['specodec.json_reader',       join(SRC, 'json_reader.cppm')],
  ['specodec.json_writer',       join(SRC, 'json_writer.cppm')],
  ['specodec.gron_reader',       join(SRC, 'gron_reader.cppm')],
  ['specodec.gron_writer',       join(SRC, 'gron_writer.cppm')],
  ['specodec.msgpack_reader',    join(SRC, 'msgpack_reader.cppm')],
  ['specodec.msgpack_writer',    join(SRC, 'msgpack_writer.cppm')],
  ['specodec.spec_codec',        join(SRC, 'spec_codec.cppm')],
  ['specodec',                   join(SRC, 'specodec.cppm')],
];

console.log('\n=== Step 2: Build runtime modules ===');
for (const [name, src] of runtimeModules) {
  if (existsSync(src)) {
    compileModule(name, src);
  }
}

// Collect all .o files for linking
const runtimeObjs = readdirSync(BUILD).filter(f => f.startsWith('specodec') && f.endsWith('.o')).map(f => join(BUILD, f));

console.log('\n=== Step 3: Build generated alltypes module ===');
const alltypesDir = EMIT_GEN;
const alltypesFiles = existsSync(alltypesDir) ? readdirSync(alltypesDir).filter(f => f.endsWith('.cppm')) : [];
if (alltypesFiles.length > 0) {
  // Copy to build dir if needed
  for (const f of alltypesFiles) {
    const src = join(alltypesDir, f);
    const name = f.replace('.cppm', '');
    compileModule('alltypes', src);
  }
}

// If emitter outputs .cpp files (non-module), compile as objects
const cppFiles = existsSync(alltypesDir) ? readdirSync(alltypesDir).filter(f => f.endsWith('.cpp') && !f.endsWith('.cppm')) : [];
for (const f of cppFiles) {
  const src = join(alltypesDir, f);
  const name = 'alltypes_' + f.replace('.cpp', '');
  const obj = join(BUILD, `${name}.o`);
  run(`${CXX} ${MFLAGS} -c ${src} -o ${obj}`);
}

// Build emit_runner module
console.log('\n=== Step 4: Build emit_runner module ===');
const mainSrc = join(__dir, 'emit', 'main.cppm');
if (existsSync(mainSrc)) {
  compileModule('emit_runner', mainSrc);
}

console.log('\n=== Step 5: Link and run ===');
const allObjs = readdirSync(BUILD).filter(f => f.endsWith('.o')).map(f => join(BUILD, f));
const binary = join(BUILD, 'emit_runner');
const linkCmd = `${CXX} ${MFLAGS} -L${LIBCXX_LIB} ${allObjs.join(' ')} -lc++ -o ${binary}`;
console.log('  >', linkCmd);
execSync(linkCmd, { stdio: 'inherit' });

console.log('\n=== Step 6: Execute ===');
const runCmd = `VEC_DIR=${VEC_DIR} OUT_DIR=${OUT_DIR} LD_LIBRARY_PATH=${LIBCXX_LIB}:$LD_LIBRARY_PATH ${binary}`;
console.log('  >', runCmd);
try {
  execSync(runCmd, { stdio: 'inherit' });
  console.log('emit-cpp: PASSED');
} catch (e) {
  console.log('emit-cpp: some tests failed (exit code ' + (e.status || '?') + ')');
  process.exit(1);
}
