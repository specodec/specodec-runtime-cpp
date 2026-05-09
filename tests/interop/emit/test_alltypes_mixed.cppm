module;
#include <cstdlib>
#include <fstream>
#include <filesystem>
export module test_alltypes_mixed;
import std;
import specodec;
import all_types_arrays;
import all_types_edge;
import all_types_extra;
import all_types_many;
import all_types_mixed;
import all_types_nested_deep;
import all_types_nested;
import all_types_nests;
import all_types_opt;
import all_types_pairs;
import all_types_recursive;
import all_types_scalars;
import all_types;
import all_types_unions;
import all_types_wide;

using namespace all_types_arrays;
using namespace all_types_edge;
using namespace all_types_extra;
using namespace all_types_many;
using namespace all_types_mixed;
using namespace all_types_nested_deep;
using namespace all_types_nested;
using namespace all_types_nests;
using namespace all_types_opt;
using namespace all_types_pairs;
using namespace all_types_recursive;
using namespace all_types_scalars;
using namespace all_types;
using namespace all_types_unions;
using namespace all_types_wide;

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


void testModelModelArr1(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/ModelArr1.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = ModelArr1Codec.decode(r);
        specodec::MsgPackWriter w;
        ModelArr1Codec.encode(w, obj);
        writeFile(outDir + "/ModelArr1.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ModelArr1 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ModelArr1 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/ModelArr1.json");
        specodec::JsonReader r(data);
        auto obj = ModelArr1Codec.decode(r);
        specodec::JsonWriter w;
        ModelArr1Codec.encode(w, obj);
        writeFile(outDir + "/ModelArr1.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ModelArr1 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ModelArr1 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/ModelArr1.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = ModelArr1Codec.decode(r);
        specodec::JsonWriter w;
        ModelArr1Codec.encode(w, obj);
        writeFile(outDir + "/ModelArr1.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ModelArr1 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ModelArr1 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/ModelArr1.gron");
        specodec::GronReader r(data);
        auto obj = ModelArr1Codec.decode(r);
        specodec::GronWriter w;
        ModelArr1Codec.encode(w, obj);
        writeFile(outDir + "/ModelArr1.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ModelArr1 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ModelArr1 gron" << std::endl; }
}

void testModelModelArr2(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/ModelArr2.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = ModelArr2Codec.decode(r);
        specodec::MsgPackWriter w;
        ModelArr2Codec.encode(w, obj);
        writeFile(outDir + "/ModelArr2.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ModelArr2 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ModelArr2 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/ModelArr2.json");
        specodec::JsonReader r(data);
        auto obj = ModelArr2Codec.decode(r);
        specodec::JsonWriter w;
        ModelArr2Codec.encode(w, obj);
        writeFile(outDir + "/ModelArr2.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ModelArr2 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ModelArr2 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/ModelArr2.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = ModelArr2Codec.decode(r);
        specodec::JsonWriter w;
        ModelArr2Codec.encode(w, obj);
        writeFile(outDir + "/ModelArr2.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ModelArr2 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ModelArr2 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/ModelArr2.gron");
        specodec::GronReader r(data);
        auto obj = ModelArr2Codec.decode(r);
        specodec::GronWriter w;
        ModelArr2Codec.encode(w, obj);
        writeFile(outDir + "/ModelArr2.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ModelArr2 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ModelArr2 gron" << std::endl; }
}

void testModelModelArr3(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/ModelArr3.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = ModelArr3Codec.decode(r);
        specodec::MsgPackWriter w;
        ModelArr3Codec.encode(w, obj);
        writeFile(outDir + "/ModelArr3.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ModelArr3 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ModelArr3 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/ModelArr3.json");
        specodec::JsonReader r(data);
        auto obj = ModelArr3Codec.decode(r);
        specodec::JsonWriter w;
        ModelArr3Codec.encode(w, obj);
        writeFile(outDir + "/ModelArr3.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ModelArr3 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ModelArr3 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/ModelArr3.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = ModelArr3Codec.decode(r);
        specodec::JsonWriter w;
        ModelArr3Codec.encode(w, obj);
        writeFile(outDir + "/ModelArr3.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ModelArr3 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ModelArr3 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/ModelArr3.gron");
        specodec::GronReader r(data);
        auto obj = ModelArr3Codec.decode(r);
        specodec::GronWriter w;
        ModelArr3Codec.encode(w, obj);
        writeFile(outDir + "/ModelArr3.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ModelArr3 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ModelArr3 gron" << std::endl; }
}

void testModelModelArr4(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/ModelArr4.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = ModelArr4Codec.decode(r);
        specodec::MsgPackWriter w;
        ModelArr4Codec.encode(w, obj);
        writeFile(outDir + "/ModelArr4.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ModelArr4 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ModelArr4 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/ModelArr4.json");
        specodec::JsonReader r(data);
        auto obj = ModelArr4Codec.decode(r);
        specodec::JsonWriter w;
        ModelArr4Codec.encode(w, obj);
        writeFile(outDir + "/ModelArr4.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ModelArr4 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ModelArr4 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/ModelArr4.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = ModelArr4Codec.decode(r);
        specodec::JsonWriter w;
        ModelArr4Codec.encode(w, obj);
        writeFile(outDir + "/ModelArr4.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ModelArr4 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ModelArr4 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/ModelArr4.gron");
        specodec::GronReader r(data);
        auto obj = ModelArr4Codec.decode(r);
        specodec::GronWriter w;
        ModelArr4Codec.encode(w, obj);
        writeFile(outDir + "/ModelArr4.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ModelArr4 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ModelArr4 gron" << std::endl; }
}

void testModelModelArr5(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/ModelArr5.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = ModelArr5Codec.decode(r);
        specodec::MsgPackWriter w;
        ModelArr5Codec.encode(w, obj);
        writeFile(outDir + "/ModelArr5.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ModelArr5 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ModelArr5 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/ModelArr5.json");
        specodec::JsonReader r(data);
        auto obj = ModelArr5Codec.decode(r);
        specodec::JsonWriter w;
        ModelArr5Codec.encode(w, obj);
        writeFile(outDir + "/ModelArr5.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ModelArr5 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ModelArr5 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/ModelArr5.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = ModelArr5Codec.decode(r);
        specodec::JsonWriter w;
        ModelArr5Codec.encode(w, obj);
        writeFile(outDir + "/ModelArr5.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ModelArr5 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ModelArr5 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/ModelArr5.gron");
        specodec::GronReader r(data);
        auto obj = ModelArr5Codec.decode(r);
        specodec::GronWriter w;
        ModelArr5Codec.encode(w, obj);
        writeFile(outDir + "/ModelArr5.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ModelArr5 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ModelArr5 gron" << std::endl; }
}

void testModelMix01(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Mix01.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Mix01Codec.decode(r);
        specodec::MsgPackWriter w;
        Mix01Codec.encode(w, obj);
        writeFile(outDir + "/Mix01.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Mix01 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Mix01 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Mix01.json");
        specodec::JsonReader r(data);
        auto obj = Mix01Codec.decode(r);
        specodec::JsonWriter w;
        Mix01Codec.encode(w, obj);
        writeFile(outDir + "/Mix01.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Mix01 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Mix01 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Mix01.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Mix01Codec.decode(r);
        specodec::JsonWriter w;
        Mix01Codec.encode(w, obj);
        writeFile(outDir + "/Mix01.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Mix01 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Mix01 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Mix01.gron");
        specodec::GronReader r(data);
        auto obj = Mix01Codec.decode(r);
        specodec::GronWriter w;
        Mix01Codec.encode(w, obj);
        writeFile(outDir + "/Mix01.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Mix01 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Mix01 gron" << std::endl; }
}

void testModelMix02(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Mix02.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Mix02Codec.decode(r);
        specodec::MsgPackWriter w;
        Mix02Codec.encode(w, obj);
        writeFile(outDir + "/Mix02.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Mix02 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Mix02 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Mix02.json");
        specodec::JsonReader r(data);
        auto obj = Mix02Codec.decode(r);
        specodec::JsonWriter w;
        Mix02Codec.encode(w, obj);
        writeFile(outDir + "/Mix02.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Mix02 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Mix02 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Mix02.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Mix02Codec.decode(r);
        specodec::JsonWriter w;
        Mix02Codec.encode(w, obj);
        writeFile(outDir + "/Mix02.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Mix02 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Mix02 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Mix02.gron");
        specodec::GronReader r(data);
        auto obj = Mix02Codec.decode(r);
        specodec::GronWriter w;
        Mix02Codec.encode(w, obj);
        writeFile(outDir + "/Mix02.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Mix02 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Mix02 gron" << std::endl; }
}

void testModelMix03(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Mix03.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Mix03Codec.decode(r);
        specodec::MsgPackWriter w;
        Mix03Codec.encode(w, obj);
        writeFile(outDir + "/Mix03.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Mix03 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Mix03 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Mix03.json");
        specodec::JsonReader r(data);
        auto obj = Mix03Codec.decode(r);
        specodec::JsonWriter w;
        Mix03Codec.encode(w, obj);
        writeFile(outDir + "/Mix03.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Mix03 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Mix03 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Mix03.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Mix03Codec.decode(r);
        specodec::JsonWriter w;
        Mix03Codec.encode(w, obj);
        writeFile(outDir + "/Mix03.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Mix03 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Mix03 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Mix03.gron");
        specodec::GronReader r(data);
        auto obj = Mix03Codec.decode(r);
        specodec::GronWriter w;
        Mix03Codec.encode(w, obj);
        writeFile(outDir + "/Mix03.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Mix03 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Mix03 gron" << std::endl; }
}

void testModelMix04(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Mix04.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Mix04Codec.decode(r);
        specodec::MsgPackWriter w;
        Mix04Codec.encode(w, obj);
        writeFile(outDir + "/Mix04.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Mix04 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Mix04 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Mix04.json");
        specodec::JsonReader r(data);
        auto obj = Mix04Codec.decode(r);
        specodec::JsonWriter w;
        Mix04Codec.encode(w, obj);
        writeFile(outDir + "/Mix04.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Mix04 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Mix04 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Mix04.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Mix04Codec.decode(r);
        specodec::JsonWriter w;
        Mix04Codec.encode(w, obj);
        writeFile(outDir + "/Mix04.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Mix04 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Mix04 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Mix04.gron");
        specodec::GronReader r(data);
        auto obj = Mix04Codec.decode(r);
        specodec::GronWriter w;
        Mix04Codec.encode(w, obj);
        writeFile(outDir + "/Mix04.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Mix04 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Mix04 gron" << std::endl; }
}

void testModelMix05(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Mix05.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Mix05Codec.decode(r);
        specodec::MsgPackWriter w;
        Mix05Codec.encode(w, obj);
        writeFile(outDir + "/Mix05.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Mix05 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Mix05 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Mix05.json");
        specodec::JsonReader r(data);
        auto obj = Mix05Codec.decode(r);
        specodec::JsonWriter w;
        Mix05Codec.encode(w, obj);
        writeFile(outDir + "/Mix05.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Mix05 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Mix05 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Mix05.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Mix05Codec.decode(r);
        specodec::JsonWriter w;
        Mix05Codec.encode(w, obj);
        writeFile(outDir + "/Mix05.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Mix05 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Mix05 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Mix05.gron");
        specodec::GronReader r(data);
        auto obj = Mix05Codec.decode(r);
        specodec::GronWriter w;
        Mix05Codec.encode(w, obj);
        writeFile(outDir + "/Mix05.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Mix05 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Mix05 gron" << std::endl; }
}

void testModelMix06(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Mix06.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Mix06Codec.decode(r);
        specodec::MsgPackWriter w;
        Mix06Codec.encode(w, obj);
        writeFile(outDir + "/Mix06.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Mix06 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Mix06 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Mix06.json");
        specodec::JsonReader r(data);
        auto obj = Mix06Codec.decode(r);
        specodec::JsonWriter w;
        Mix06Codec.encode(w, obj);
        writeFile(outDir + "/Mix06.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Mix06 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Mix06 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Mix06.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Mix06Codec.decode(r);
        specodec::JsonWriter w;
        Mix06Codec.encode(w, obj);
        writeFile(outDir + "/Mix06.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Mix06 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Mix06 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Mix06.gron");
        specodec::GronReader r(data);
        auto obj = Mix06Codec.decode(r);
        specodec::GronWriter w;
        Mix06Codec.encode(w, obj);
        writeFile(outDir + "/Mix06.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Mix06 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Mix06 gron" << std::endl; }
}

void testModelMix07(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Mix07.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Mix07Codec.decode(r);
        specodec::MsgPackWriter w;
        Mix07Codec.encode(w, obj);
        writeFile(outDir + "/Mix07.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Mix07 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Mix07 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Mix07.json");
        specodec::JsonReader r(data);
        auto obj = Mix07Codec.decode(r);
        specodec::JsonWriter w;
        Mix07Codec.encode(w, obj);
        writeFile(outDir + "/Mix07.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Mix07 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Mix07 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Mix07.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Mix07Codec.decode(r);
        specodec::JsonWriter w;
        Mix07Codec.encode(w, obj);
        writeFile(outDir + "/Mix07.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Mix07 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Mix07 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Mix07.gron");
        specodec::GronReader r(data);
        auto obj = Mix07Codec.decode(r);
        specodec::GronWriter w;
        Mix07Codec.encode(w, obj);
        writeFile(outDir + "/Mix07.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Mix07 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Mix07 gron" << std::endl; }
}

void testModelMix08(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Mix08.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Mix08Codec.decode(r);
        specodec::MsgPackWriter w;
        Mix08Codec.encode(w, obj);
        writeFile(outDir + "/Mix08.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Mix08 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Mix08 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Mix08.json");
        specodec::JsonReader r(data);
        auto obj = Mix08Codec.decode(r);
        specodec::JsonWriter w;
        Mix08Codec.encode(w, obj);
        writeFile(outDir + "/Mix08.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Mix08 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Mix08 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Mix08.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Mix08Codec.decode(r);
        specodec::JsonWriter w;
        Mix08Codec.encode(w, obj);
        writeFile(outDir + "/Mix08.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Mix08 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Mix08 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Mix08.gron");
        specodec::GronReader r(data);
        auto obj = Mix08Codec.decode(r);
        specodec::GronWriter w;
        Mix08Codec.encode(w, obj);
        writeFile(outDir + "/Mix08.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Mix08 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Mix08 gron" << std::endl; }
}

void testModelMix09(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Mix09.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Mix09Codec.decode(r);
        specodec::MsgPackWriter w;
        Mix09Codec.encode(w, obj);
        writeFile(outDir + "/Mix09.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Mix09 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Mix09 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Mix09.json");
        specodec::JsonReader r(data);
        auto obj = Mix09Codec.decode(r);
        specodec::JsonWriter w;
        Mix09Codec.encode(w, obj);
        writeFile(outDir + "/Mix09.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Mix09 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Mix09 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Mix09.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Mix09Codec.decode(r);
        specodec::JsonWriter w;
        Mix09Codec.encode(w, obj);
        writeFile(outDir + "/Mix09.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Mix09 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Mix09 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Mix09.gron");
        specodec::GronReader r(data);
        auto obj = Mix09Codec.decode(r);
        specodec::GronWriter w;
        Mix09Codec.encode(w, obj);
        writeFile(outDir + "/Mix09.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Mix09 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Mix09 gron" << std::endl; }
}

void testModelMix10(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Mix10.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Mix10Codec.decode(r);
        specodec::MsgPackWriter w;
        Mix10Codec.encode(w, obj);
        writeFile(outDir + "/Mix10.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Mix10 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Mix10 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Mix10.json");
        specodec::JsonReader r(data);
        auto obj = Mix10Codec.decode(r);
        specodec::JsonWriter w;
        Mix10Codec.encode(w, obj);
        writeFile(outDir + "/Mix10.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Mix10 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Mix10 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Mix10.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Mix10Codec.decode(r);
        specodec::JsonWriter w;
        Mix10Codec.encode(w, obj);
        writeFile(outDir + "/Mix10.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Mix10 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Mix10 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Mix10.gron");
        specodec::GronReader r(data);
        auto obj = Mix10Codec.decode(r);
        specodec::GronWriter w;
        Mix10Codec.encode(w, obj);
        writeFile(outDir + "/Mix10.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Mix10 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Mix10 gron" << std::endl; }
}

void testModelMix11(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Mix11.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Mix11Codec.decode(r);
        specodec::MsgPackWriter w;
        Mix11Codec.encode(w, obj);
        writeFile(outDir + "/Mix11.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Mix11 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Mix11 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Mix11.json");
        specodec::JsonReader r(data);
        auto obj = Mix11Codec.decode(r);
        specodec::JsonWriter w;
        Mix11Codec.encode(w, obj);
        writeFile(outDir + "/Mix11.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Mix11 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Mix11 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Mix11.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Mix11Codec.decode(r);
        specodec::JsonWriter w;
        Mix11Codec.encode(w, obj);
        writeFile(outDir + "/Mix11.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Mix11 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Mix11 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Mix11.gron");
        specodec::GronReader r(data);
        auto obj = Mix11Codec.decode(r);
        specodec::GronWriter w;
        Mix11Codec.encode(w, obj);
        writeFile(outDir + "/Mix11.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Mix11 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Mix11 gron" << std::endl; }
}

void testModelMix12(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Mix12.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Mix12Codec.decode(r);
        specodec::MsgPackWriter w;
        Mix12Codec.encode(w, obj);
        writeFile(outDir + "/Mix12.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Mix12 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Mix12 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Mix12.json");
        specodec::JsonReader r(data);
        auto obj = Mix12Codec.decode(r);
        specodec::JsonWriter w;
        Mix12Codec.encode(w, obj);
        writeFile(outDir + "/Mix12.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Mix12 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Mix12 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Mix12.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Mix12Codec.decode(r);
        specodec::JsonWriter w;
        Mix12Codec.encode(w, obj);
        writeFile(outDir + "/Mix12.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Mix12 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Mix12 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Mix12.gron");
        specodec::GronReader r(data);
        auto obj = Mix12Codec.decode(r);
        specodec::GronWriter w;
        Mix12Codec.encode(w, obj);
        writeFile(outDir + "/Mix12.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Mix12 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Mix12 gron" << std::endl; }
}

void testModelMix13(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Mix13.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Mix13Codec.decode(r);
        specodec::MsgPackWriter w;
        Mix13Codec.encode(w, obj);
        writeFile(outDir + "/Mix13.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Mix13 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Mix13 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Mix13.json");
        specodec::JsonReader r(data);
        auto obj = Mix13Codec.decode(r);
        specodec::JsonWriter w;
        Mix13Codec.encode(w, obj);
        writeFile(outDir + "/Mix13.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Mix13 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Mix13 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Mix13.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Mix13Codec.decode(r);
        specodec::JsonWriter w;
        Mix13Codec.encode(w, obj);
        writeFile(outDir + "/Mix13.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Mix13 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Mix13 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Mix13.gron");
        specodec::GronReader r(data);
        auto obj = Mix13Codec.decode(r);
        specodec::GronWriter w;
        Mix13Codec.encode(w, obj);
        writeFile(outDir + "/Mix13.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Mix13 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Mix13 gron" << std::endl; }
}

void testModelMix14(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Mix14.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Mix14Codec.decode(r);
        specodec::MsgPackWriter w;
        Mix14Codec.encode(w, obj);
        writeFile(outDir + "/Mix14.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Mix14 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Mix14 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Mix14.json");
        specodec::JsonReader r(data);
        auto obj = Mix14Codec.decode(r);
        specodec::JsonWriter w;
        Mix14Codec.encode(w, obj);
        writeFile(outDir + "/Mix14.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Mix14 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Mix14 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Mix14.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Mix14Codec.decode(r);
        specodec::JsonWriter w;
        Mix14Codec.encode(w, obj);
        writeFile(outDir + "/Mix14.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Mix14 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Mix14 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Mix14.gron");
        specodec::GronReader r(data);
        auto obj = Mix14Codec.decode(r);
        specodec::GronWriter w;
        Mix14Codec.encode(w, obj);
        writeFile(outDir + "/Mix14.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Mix14 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Mix14 gron" << std::endl; }
}

void testModelMix15(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Mix15.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Mix15Codec.decode(r);
        specodec::MsgPackWriter w;
        Mix15Codec.encode(w, obj);
        writeFile(outDir + "/Mix15.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Mix15 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Mix15 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Mix15.json");
        specodec::JsonReader r(data);
        auto obj = Mix15Codec.decode(r);
        specodec::JsonWriter w;
        Mix15Codec.encode(w, obj);
        writeFile(outDir + "/Mix15.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Mix15 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Mix15 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Mix15.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Mix15Codec.decode(r);
        specodec::JsonWriter w;
        Mix15Codec.encode(w, obj);
        writeFile(outDir + "/Mix15.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Mix15 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Mix15 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Mix15.gron");
        specodec::GronReader r(data);
        auto obj = Mix15Codec.decode(r);
        specodec::GronWriter w;
        Mix15Codec.encode(w, obj);
        writeFile(outDir + "/Mix15.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Mix15 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Mix15 gron" << std::endl; }
}

void testModelAllOpt1(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/AllOpt1.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = AllOpt1Codec.decode(r);
        specodec::MsgPackWriter w;
        AllOpt1Codec.encode(w, obj);
        writeFile(outDir + "/AllOpt1.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL AllOpt1 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL AllOpt1 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/AllOpt1.json");
        specodec::JsonReader r(data);
        auto obj = AllOpt1Codec.decode(r);
        specodec::JsonWriter w;
        AllOpt1Codec.encode(w, obj);
        writeFile(outDir + "/AllOpt1.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL AllOpt1 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL AllOpt1 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/AllOpt1.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = AllOpt1Codec.decode(r);
        specodec::JsonWriter w;
        AllOpt1Codec.encode(w, obj);
        writeFile(outDir + "/AllOpt1.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL AllOpt1 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL AllOpt1 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/AllOpt1.gron");
        specodec::GronReader r(data);
        auto obj = AllOpt1Codec.decode(r);
        specodec::GronWriter w;
        AllOpt1Codec.encode(w, obj);
        writeFile(outDir + "/AllOpt1.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL AllOpt1 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL AllOpt1 gron" << std::endl; }
}

void testModelAllOpt2(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/AllOpt2.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = AllOpt2Codec.decode(r);
        specodec::MsgPackWriter w;
        AllOpt2Codec.encode(w, obj);
        writeFile(outDir + "/AllOpt2.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL AllOpt2 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL AllOpt2 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/AllOpt2.json");
        specodec::JsonReader r(data);
        auto obj = AllOpt2Codec.decode(r);
        specodec::JsonWriter w;
        AllOpt2Codec.encode(w, obj);
        writeFile(outDir + "/AllOpt2.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL AllOpt2 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL AllOpt2 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/AllOpt2.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = AllOpt2Codec.decode(r);
        specodec::JsonWriter w;
        AllOpt2Codec.encode(w, obj);
        writeFile(outDir + "/AllOpt2.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL AllOpt2 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL AllOpt2 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/AllOpt2.gron");
        specodec::GronReader r(data);
        auto obj = AllOpt2Codec.decode(r);
        specodec::GronWriter w;
        AllOpt2Codec.encode(w, obj);
        writeFile(outDir + "/AllOpt2.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL AllOpt2 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL AllOpt2 gron" << std::endl; }
}

void testModelAllOpt3(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/AllOpt3.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = AllOpt3Codec.decode(r);
        specodec::MsgPackWriter w;
        AllOpt3Codec.encode(w, obj);
        writeFile(outDir + "/AllOpt3.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL AllOpt3 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL AllOpt3 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/AllOpt3.json");
        specodec::JsonReader r(data);
        auto obj = AllOpt3Codec.decode(r);
        specodec::JsonWriter w;
        AllOpt3Codec.encode(w, obj);
        writeFile(outDir + "/AllOpt3.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL AllOpt3 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL AllOpt3 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/AllOpt3.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = AllOpt3Codec.decode(r);
        specodec::JsonWriter w;
        AllOpt3Codec.encode(w, obj);
        writeFile(outDir + "/AllOpt3.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL AllOpt3 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL AllOpt3 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/AllOpt3.gron");
        specodec::GronReader r(data);
        auto obj = AllOpt3Codec.decode(r);
        specodec::GronWriter w;
        AllOpt3Codec.encode(w, obj);
        writeFile(outDir + "/AllOpt3.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL AllOpt3 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL AllOpt3 gron" << std::endl; }
}

void testModelAllOpt4(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/AllOpt4.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = AllOpt4Codec.decode(r);
        specodec::MsgPackWriter w;
        AllOpt4Codec.encode(w, obj);
        writeFile(outDir + "/AllOpt4.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL AllOpt4 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL AllOpt4 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/AllOpt4.json");
        specodec::JsonReader r(data);
        auto obj = AllOpt4Codec.decode(r);
        specodec::JsonWriter w;
        AllOpt4Codec.encode(w, obj);
        writeFile(outDir + "/AllOpt4.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL AllOpt4 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL AllOpt4 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/AllOpt4.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = AllOpt4Codec.decode(r);
        specodec::JsonWriter w;
        AllOpt4Codec.encode(w, obj);
        writeFile(outDir + "/AllOpt4.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL AllOpt4 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL AllOpt4 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/AllOpt4.gron");
        specodec::GronReader r(data);
        auto obj = AllOpt4Codec.decode(r);
        specodec::GronWriter w;
        AllOpt4Codec.encode(w, obj);
        writeFile(outDir + "/AllOpt4.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL AllOpt4 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL AllOpt4 gron" << std::endl; }
}

void testModelAllOpt5(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/AllOpt5.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = AllOpt5Codec.decode(r);
        specodec::MsgPackWriter w;
        AllOpt5Codec.encode(w, obj);
        writeFile(outDir + "/AllOpt5.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL AllOpt5 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL AllOpt5 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/AllOpt5.json");
        specodec::JsonReader r(data);
        auto obj = AllOpt5Codec.decode(r);
        specodec::JsonWriter w;
        AllOpt5Codec.encode(w, obj);
        writeFile(outDir + "/AllOpt5.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL AllOpt5 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL AllOpt5 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/AllOpt5.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = AllOpt5Codec.decode(r);
        specodec::JsonWriter w;
        AllOpt5Codec.encode(w, obj);
        writeFile(outDir + "/AllOpt5.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL AllOpt5 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL AllOpt5 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/AllOpt5.gron");
        specodec::GronReader r(data);
        auto obj = AllOpt5Codec.decode(r);
        specodec::GronWriter w;
        AllOpt5Codec.encode(w, obj);
        writeFile(outDir + "/AllOpt5.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL AllOpt5 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL AllOpt5 gron" << std::endl; }
}


export void runAlltypes_mixed(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    testModelModelArr1(passed, failed, vecDir, outDir);
    testModelModelArr2(passed, failed, vecDir, outDir);
    testModelModelArr3(passed, failed, vecDir, outDir);
    testModelModelArr4(passed, failed, vecDir, outDir);
    testModelModelArr5(passed, failed, vecDir, outDir);
    testModelMix01(passed, failed, vecDir, outDir);
    testModelMix02(passed, failed, vecDir, outDir);
    testModelMix03(passed, failed, vecDir, outDir);
    testModelMix04(passed, failed, vecDir, outDir);
    testModelMix05(passed, failed, vecDir, outDir);
    testModelMix06(passed, failed, vecDir, outDir);
    testModelMix07(passed, failed, vecDir, outDir);
    testModelMix08(passed, failed, vecDir, outDir);
    testModelMix09(passed, failed, vecDir, outDir);
    testModelMix10(passed, failed, vecDir, outDir);
    testModelMix11(passed, failed, vecDir, outDir);
    testModelMix12(passed, failed, vecDir, outDir);
    testModelMix13(passed, failed, vecDir, outDir);
    testModelMix14(passed, failed, vecDir, outDir);
    testModelMix15(passed, failed, vecDir, outDir);
    testModelAllOpt1(passed, failed, vecDir, outDir);
    testModelAllOpt2(passed, failed, vecDir, outDir);
    testModelAllOpt3(passed, failed, vecDir, outDir);
    testModelAllOpt4(passed, failed, vecDir, outDir);
    testModelAllOpt5(passed, failed, vecDir, outDir);

}
