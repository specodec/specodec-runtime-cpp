import fs from "fs";
import path from "path";
import { fileURLToPath } from "url";

const __dir = path.dirname(fileURLToPath(import.meta.url));
const VEC_DIR = process.env.VEC_DIR || path.join(__dir, ".tests-cache", "vectors");
const EMIT_GEN = path.join(__dir, "emit_gen");

const manifestPath = path.join(VEC_DIR, "manifest.json");
const manifest = JSON.parse(fs.readFileSync(manifestPath, "utf-8"));

const models = manifest.testModels || [];
const scalars = manifest.scalars || {};
const modelNamespaces = manifest.modelNamespaces || {};

function snake(s) { return s.replace(/\./g, "_").replace(/([A-Z])/g, (c, i) => (i > 0 ? "_" : "") + c.toLowerCase()); }
function toPascalCase(name) { const r = name.replace(/\./g, '_').replace(/-/g, '_'); return r.charAt(0).toUpperCase() + r.slice(1); }

function getReadMethod(type) {
  const map = { "int32":"readInt32","int64":"readInt64","uint32":"readUint32","uint64":"readUint64","float32":"readFloat32","float64":"readFloat64","string":"readString","bytes":"readBytes","bool":"readBool" };
  return map[type] || "readInt32";
}
function getWriteMethod(type) {
  const map = { "int32":"writeInt32","int64":"writeInt64","uint32":"writeUint32","uint64":"writeUint64","float32":"writeFloat32","float64":"writeFloat64","string":"writeString","bytes":"writeBytes","bool":"writeBool" };
  return map[type] || "writeInt32";
}

// ── Group models by namespace ──────────────────────────────────────────────
const nsGroups = {};
for (const model of models) {
  const ns = modelNamespaces[model] || "AllTypes";
  if (!nsGroups[ns]) nsGroups[ns] = [];
  nsGroups[ns].push(model);
}

// ── Discover emitted modules ───────────────────────────────────────────────
const cppmFiles = fs.existsSync(EMIT_GEN) ? fs.readdirSync(EMIT_GEN).filter(f => f.endsWith('.cppm')) : [];
const cppModules = cppmFiles.map(f => f.replace('_types.cppm', ''));
const moduleImports = cppModules.map(m => `import ${m};`).join('\n');
const moduleUsings = cppModules.map(m => `using namespace ${m};`).join('\n');

// ── Scalar tests (always in main.cppm, only 41 functions) ──────────────────
let scalarFuncs = '', scalarCalls = '';
for (const [name, info] of Object.entries(scalars)) {
  const pascal = toPascalCase(name);
  scalarFuncs += `
void testScalar${pascal}(int& passed, int& failed) {
    try {
        auto data = readFile(vecDir + "/scalars/${name}.mp");
        specodec::MsgPackReader r(data);
        auto value = r.${getReadMethod(info.type)}();
        specodec::MsgPackWriter w;
        w.${getWriteMethod(info.type)}(value);
        writeFile(outDir + "/scalars/${name}.mp", w.toBytes());
        passed++;
    } catch (...) { failed++; std::cout << "FAIL ${name} mp" << std::endl; }
}
`;
  scalarCalls += `    testScalar${pascal}(passed, failed);\n`;
}

// ── Model test helpers ─────────────────────────────────────────────────────
function modelTestFunc(model) {
  return `
void testModel${model}(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/${model}.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = ${model}Codec.decode(r);
        specodec::MsgPackWriter w;
        ${model}Codec.encode(w, obj);
        writeFile(outDir + "/${model}.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ${model} mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ${model} mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/${model}.json");
        specodec::JsonReader r(data);
        auto obj = ${model}Codec.decode(r);
        specodec::JsonWriter w;
        ${model}Codec.encode(w, obj);
        writeFile(outDir + "/${model}.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ${model} json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ${model} json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/${model}.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = ${model}Codec.decode(r);
        specodec::JsonWriter w;
        ${model}Codec.encode(w, obj);
        writeFile(outDir + "/${model}.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ${model} unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ${model} unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/${model}.gron");
        specodec::GronReader r(data);
        auto obj = ${model}Codec.decode(r);
        specodec::GronWriter w;
        ${model}Codec.encode(w, obj);
        writeFile(outDir + "/${model}.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ${model} gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ${model} gron" << std::endl; }
}
`;
}

// ── Generate test_*.cppm per namespace ─────────────────────────────────────
const testModuleNames = [];
for (const [ns, nsModels] of Object.entries(nsGroups)) {
  const nsSnake = snake(ns).replace(/\^/g, '').replace(/\./g, '_');
  const modName = `test_${nsSnake}`;
  testModuleNames.push(modName);

  let funcs = '', calls = '';
  for (const model of nsModels) {
    funcs += modelTestFunc(model);
    calls += `    testModel${model}(passed, failed, vecDir, outDir);\n`;
  }

  const testCode = `module;
#include <cstdlib>
#include <fstream>
#include <filesystem>
export module ${modName};
import std;
import specodec;
${moduleImports}

${moduleUsings}

static std::vector<std::uint8_t> readFile(const std::string& path) {
    std::ifstream file(path, std::ios::binary | std::ios::ate);
    if (!file) throw std::runtime_error("cannot open file: " + path);
    std::streamsize size = file.tellg();
    file.seekg(0, std::ios::beg);
    std::vector<std::uint8_t> buffer(static_cast<std::size_t>(size));
    if (!file.read(reinterpret_cast<char*>(buffer.data()), size))
        throw std::runtime_error("cannot read file: " + path);
    return buffer;
}

static void writeFile(const std::string& path, const std::vector<std::uint8_t>& data) {
    std::filesystem::create_directories(std::filesystem::path(path).parent_path());
    std::ofstream file(path, std::ios::binary);
    if (!file) throw std::runtime_error("cannot write file: " + path);
    file.write(reinterpret_cast<const char*>(data.data()), static_cast<std::streamsize>(data.size()));
}

${funcs}

export void run${toPascalCase(nsSnake)}(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
${calls}
}
`;
  const outDirPath = path.join(__dir, "emit");
  fs.mkdirSync(outDirPath, { recursive: true });
  fs.writeFileSync(path.join(outDirPath, `${modName}.cppm`), testCode);
}

// ── Generate main.cppm ─────────────────────────────────────────────────────
const testImports = testModuleNames.map(m => `import ${m};`).join('\n');
const testCalls = testModuleNames.map(m => `    run${toPascalCase(m.replace('test_',''))}(passed, failed, vecDir, outDir);`).join('\n');

const mainCode = `module;
#include <cstdlib>
#include <fstream>
#include <filesystem>
export module emit_runner;
import std;
import specodec;
${testImports}

static std::string getEnv(const char* name) { const char* val = std::getenv(name); return val ? val : ""; }

static std::vector<std::uint8_t> readFile(const std::string& path) {
    std::ifstream file(path, std::ios::binary | std::ios::ate);
    if (!file) throw std::runtime_error("cannot open file: " + path);
    std::streamsize size = file.tellg();
    file.seekg(0, std::ios::beg);
    std::vector<std::uint8_t> buffer(static_cast<std::size_t>(size));
    if (!file.read(reinterpret_cast<char*>(buffer.data()), size))
        throw std::runtime_error("cannot read file: " + path);
    return buffer;
}

static void writeFile(const std::string& path, const std::vector<std::uint8_t>& data) {
    std::filesystem::create_directories(std::filesystem::path(path).parent_path());
    std::ofstream file(path, std::ios::binary);
    if (!file) throw std::runtime_error("cannot write file: " + path);
    file.write(reinterpret_cast<const char*>(data.data()), static_cast<std::streamsize>(data.size()));
}

static std::string vecDir;
static std::string outDir;

${scalarFuncs}

int main() {
    int passed = 0, failed = 0;
    vecDir = getEnv("VEC_DIR");
    outDir = getEnv("OUT_DIR");

    // Scalar tests
${scalarCalls}
    // Model tests (per namespace)
${testCalls}

    std::cout << "emit-cpp: " << passed << " passed, " << failed << " failed" << std::endl;
    return failed > 0 ? 1 : 0;
}
`;

const outDirPath = path.join(__dir, "emit");
fs.mkdirSync(outDirPath, { recursive: true });
fs.writeFileSync(path.join(outDirPath, "main.cppm"), mainCode);
console.log(`Generated emit/ with ${testModuleNames.length} test modules + main.cppm, ${models.length} models + ${Object.keys(scalars).length} scalars`);
