import { readFileSync } from 'fs';
import { execSync } from 'child_process';
import { existsSync, mkdirSync, rmSync, readdirSync, writeFileSync } from 'fs';
import { join, dirname } from 'path';
import { fileURLToPath } from 'url';

const __dir = dirname(fileURLToPath(import.meta.url));
const CACHE = join(__dir, '.tests-cache');
const EMIT_GEN = join(__dir, 'emit_gen');
const OUT_DIR = join(__dir, 'output');

function run(cmd) {
  console.log('  >', cmd);
  execSync(cmd, { stdio: 'inherit' });
}

console.log('\n=== Step 1: Install dependencies ===');
run(`npm install`);

console.log('\n=== Step 2: Using cached .tests-cache ===');

console.log('\n=== Step 3: Generate vectors ===');
run(`cd ${CACHE} && npm install --silent && node gen_types.mjs`);
const VEC_DIR = join(CACHE, 'vectors');

console.log('\n=== Step 4: Generate emit code ===');
if (existsSync(EMIT_GEN)) rmSync(EMIT_GEN, { recursive: true });
mkdirSync(EMIT_GEN, { recursive: true });
run(`npx tsp compile ${CACHE}/alltypes.tsp --emit=@specodec/typespec-emitter-cpp --option @specodec/typespec-emitter-cpp.emitter-output-dir=${EMIT_GEN}`);
console.log('  Emit OK');

console.log('\n=== Step 5: Generate test runner ===');
const srcDir = join(__dir, 'emit');
if (!existsSync(srcDir)) mkdirSync(srcDir, { recursive: true });
run(`VEC_DIR=${VEC_DIR} node generate_emit_runner.mjs`);

console.log('\n=== Step 6: Fetch runtime from Forgejo generic registry ===');
const cppUrl = "http://10.199.64.20:3000/api/packages/specodec/generic/specodec-runtime-cpp/1.0.0/libspecodec.a";
run(`curl -sfL -o /tmp/libspecodec.a "${cppUrl}"`);


// Set LD_LIBRARY_PATH so the binary can find libc++.so
const LIBCXX_LIB = '/root/.local/share/mise/installs/conda-libcxx/21.1.8/lib';

console.log('\n=== Step 7: Run tests ===');
if (existsSync(OUT_DIR)) rmSync(OUT_DIR, { recursive: true });
mkdirSync(OUT_DIR, { recursive: true });

const emitDir = join(__dir, 'emit');
if (existsSync(join(emitDir, 'build'))) rmSync(join(emitDir, 'build'), { recursive: true });
try { run(`VEC_DIR=${VEC_DIR} OUT_DIR=${OUT_DIR} node run_test.mjs`); } catch (e) { console.log("C++ tests completed (some failures expected)"); }

console.log('\n=== Step 8: Compare output ===');
const manifest = JSON.parse(readFileSync(join(VEC_DIR, 'manifest.json'), 'utf-8'));
let match = 0, mismatch = 0;

for (const [name] of Object.entries(manifest.scalars || {})) {
  const exp = join(VEC_DIR, 'scalars', name + '.mp');
  const act = join(OUT_DIR, 'scalars', name + '.mp');
  if (!existsSync(act)) { mismatch++; console.log('MISSING: ' + name + '.mp'); continue; }
  if (readFileSync(exp).equals(readFileSync(act))) match++;
  else { mismatch++; console.log('MISMATCH: ' + name + '.mp'); }
}
for (const model of [...(manifest.testModels || []), ...(manifest.testUnions || [])]) {
  for (const [outExt, vecExt] of [['msgpack','msgpack'], ['json','json'], ['unformatted.json','json'], ['gron','gron']]) {
    const vec = join(VEC_DIR, model + '.' + vecExt);
    const out = join(OUT_DIR, model + '.' + outExt);
    if (!existsSync(vec)) continue;
    if (!existsSync(out)) { mismatch++; console.log('MISSING: ' + model + '.' + outExt); continue; }
    if (readFileSync(vec).equals(readFileSync(out))) match++;
    else { mismatch++; console.log('MISMATCH: ' + model + '.' + outExt); }
  }
}
const total = match + mismatch;
console.log(match + '/' + total + ' match, ' + mismatch + ' mismatch');
if (mismatch > 0) process.exit(1);
console.log('\n=== ALL PASSED ===');
