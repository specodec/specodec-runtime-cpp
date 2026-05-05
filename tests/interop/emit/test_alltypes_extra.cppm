module;
#include <cstdlib>
#include <fstream>
#include <filesystem>
export module test_alltypes_extra;
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


void testModelOptArr1(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptArr1.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptArr1Codec.decode(r);
        specodec::MsgPackWriter w;
        OptArr1Codec.encode(w, obj);
        writeFile(outDir + "/OptArr1.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptArr1 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptArr1 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptArr1.json");
        specodec::JsonReader r(data);
        auto obj = OptArr1Codec.decode(r);
        specodec::JsonWriter w;
        OptArr1Codec.encode(w, obj);
        writeFile(outDir + "/OptArr1.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptArr1 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptArr1 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptArr1.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptArr1Codec.decode(r);
        specodec::JsonWriter w;
        OptArr1Codec.encode(w, obj);
        writeFile(outDir + "/OptArr1.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptArr1 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptArr1 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptArr1.gron");
        specodec::GronReader r(data);
        auto obj = OptArr1Codec.decode(r);
        specodec::GronWriter w;
        OptArr1Codec.encode(w, obj);
        writeFile(outDir + "/OptArr1.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptArr1 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptArr1 gron" << std::endl; }
}

void testModelOptArr2(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptArr2.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptArr2Codec.decode(r);
        specodec::MsgPackWriter w;
        OptArr2Codec.encode(w, obj);
        writeFile(outDir + "/OptArr2.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptArr2 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptArr2 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptArr2.json");
        specodec::JsonReader r(data);
        auto obj = OptArr2Codec.decode(r);
        specodec::JsonWriter w;
        OptArr2Codec.encode(w, obj);
        writeFile(outDir + "/OptArr2.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptArr2 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptArr2 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptArr2.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptArr2Codec.decode(r);
        specodec::JsonWriter w;
        OptArr2Codec.encode(w, obj);
        writeFile(outDir + "/OptArr2.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptArr2 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptArr2 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptArr2.gron");
        specodec::GronReader r(data);
        auto obj = OptArr2Codec.decode(r);
        specodec::GronWriter w;
        OptArr2Codec.encode(w, obj);
        writeFile(outDir + "/OptArr2.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptArr2 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptArr2 gron" << std::endl; }
}

void testModelOptArr3(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptArr3.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptArr3Codec.decode(r);
        specodec::MsgPackWriter w;
        OptArr3Codec.encode(w, obj);
        writeFile(outDir + "/OptArr3.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptArr3 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptArr3 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptArr3.json");
        specodec::JsonReader r(data);
        auto obj = OptArr3Codec.decode(r);
        specodec::JsonWriter w;
        OptArr3Codec.encode(w, obj);
        writeFile(outDir + "/OptArr3.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptArr3 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptArr3 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptArr3.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptArr3Codec.decode(r);
        specodec::JsonWriter w;
        OptArr3Codec.encode(w, obj);
        writeFile(outDir + "/OptArr3.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptArr3 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptArr3 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptArr3.gron");
        specodec::GronReader r(data);
        auto obj = OptArr3Codec.decode(r);
        specodec::GronWriter w;
        OptArr3Codec.encode(w, obj);
        writeFile(outDir + "/OptArr3.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptArr3 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptArr3 gron" << std::endl; }
}

void testModelOptArr4(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptArr4.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptArr4Codec.decode(r);
        specodec::MsgPackWriter w;
        OptArr4Codec.encode(w, obj);
        writeFile(outDir + "/OptArr4.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptArr4 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptArr4 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptArr4.json");
        specodec::JsonReader r(data);
        auto obj = OptArr4Codec.decode(r);
        specodec::JsonWriter w;
        OptArr4Codec.encode(w, obj);
        writeFile(outDir + "/OptArr4.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptArr4 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptArr4 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptArr4.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptArr4Codec.decode(r);
        specodec::JsonWriter w;
        OptArr4Codec.encode(w, obj);
        writeFile(outDir + "/OptArr4.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptArr4 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptArr4 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptArr4.gron");
        specodec::GronReader r(data);
        auto obj = OptArr4Codec.decode(r);
        specodec::GronWriter w;
        OptArr4Codec.encode(w, obj);
        writeFile(outDir + "/OptArr4.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptArr4 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptArr4 gron" << std::endl; }
}

void testModelOptArr5(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptArr5.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptArr5Codec.decode(r);
        specodec::MsgPackWriter w;
        OptArr5Codec.encode(w, obj);
        writeFile(outDir + "/OptArr5.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptArr5 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptArr5 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptArr5.json");
        specodec::JsonReader r(data);
        auto obj = OptArr5Codec.decode(r);
        specodec::JsonWriter w;
        OptArr5Codec.encode(w, obj);
        writeFile(outDir + "/OptArr5.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptArr5 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptArr5 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptArr5.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptArr5Codec.decode(r);
        specodec::JsonWriter w;
        OptArr5Codec.encode(w, obj);
        writeFile(outDir + "/OptArr5.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptArr5 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptArr5 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptArr5.gron");
        specodec::GronReader r(data);
        auto obj = OptArr5Codec.decode(r);
        specodec::GronWriter w;
        OptArr5Codec.encode(w, obj);
        writeFile(outDir + "/OptArr5.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptArr5 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptArr5 gron" << std::endl; }
}

void testModelNestOpt1(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/NestOpt1.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = NestOpt1Codec.decode(r);
        specodec::MsgPackWriter w;
        NestOpt1Codec.encode(w, obj);
        writeFile(outDir + "/NestOpt1.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestOpt1 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestOpt1 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/NestOpt1.json");
        specodec::JsonReader r(data);
        auto obj = NestOpt1Codec.decode(r);
        specodec::JsonWriter w;
        NestOpt1Codec.encode(w, obj);
        writeFile(outDir + "/NestOpt1.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestOpt1 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestOpt1 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/NestOpt1.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = NestOpt1Codec.decode(r);
        specodec::JsonWriter w;
        NestOpt1Codec.encode(w, obj);
        writeFile(outDir + "/NestOpt1.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestOpt1 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestOpt1 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/NestOpt1.gron");
        specodec::GronReader r(data);
        auto obj = NestOpt1Codec.decode(r);
        specodec::GronWriter w;
        NestOpt1Codec.encode(w, obj);
        writeFile(outDir + "/NestOpt1.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestOpt1 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestOpt1 gron" << std::endl; }
}

void testModelNestOpt2(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/NestOpt2.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = NestOpt2Codec.decode(r);
        specodec::MsgPackWriter w;
        NestOpt2Codec.encode(w, obj);
        writeFile(outDir + "/NestOpt2.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestOpt2 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestOpt2 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/NestOpt2.json");
        specodec::JsonReader r(data);
        auto obj = NestOpt2Codec.decode(r);
        specodec::JsonWriter w;
        NestOpt2Codec.encode(w, obj);
        writeFile(outDir + "/NestOpt2.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestOpt2 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestOpt2 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/NestOpt2.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = NestOpt2Codec.decode(r);
        specodec::JsonWriter w;
        NestOpt2Codec.encode(w, obj);
        writeFile(outDir + "/NestOpt2.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestOpt2 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestOpt2 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/NestOpt2.gron");
        specodec::GronReader r(data);
        auto obj = NestOpt2Codec.decode(r);
        specodec::GronWriter w;
        NestOpt2Codec.encode(w, obj);
        writeFile(outDir + "/NestOpt2.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestOpt2 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestOpt2 gron" << std::endl; }
}

void testModelNestOpt3(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/NestOpt3.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = NestOpt3Codec.decode(r);
        specodec::MsgPackWriter w;
        NestOpt3Codec.encode(w, obj);
        writeFile(outDir + "/NestOpt3.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestOpt3 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestOpt3 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/NestOpt3.json");
        specodec::JsonReader r(data);
        auto obj = NestOpt3Codec.decode(r);
        specodec::JsonWriter w;
        NestOpt3Codec.encode(w, obj);
        writeFile(outDir + "/NestOpt3.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestOpt3 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestOpt3 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/NestOpt3.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = NestOpt3Codec.decode(r);
        specodec::JsonWriter w;
        NestOpt3Codec.encode(w, obj);
        writeFile(outDir + "/NestOpt3.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestOpt3 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestOpt3 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/NestOpt3.gron");
        specodec::GronReader r(data);
        auto obj = NestOpt3Codec.decode(r);
        specodec::GronWriter w;
        NestOpt3Codec.encode(w, obj);
        writeFile(outDir + "/NestOpt3.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestOpt3 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestOpt3 gron" << std::endl; }
}

void testModelNestOpt4(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/NestOpt4.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = NestOpt4Codec.decode(r);
        specodec::MsgPackWriter w;
        NestOpt4Codec.encode(w, obj);
        writeFile(outDir + "/NestOpt4.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestOpt4 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestOpt4 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/NestOpt4.json");
        specodec::JsonReader r(data);
        auto obj = NestOpt4Codec.decode(r);
        specodec::JsonWriter w;
        NestOpt4Codec.encode(w, obj);
        writeFile(outDir + "/NestOpt4.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestOpt4 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestOpt4 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/NestOpt4.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = NestOpt4Codec.decode(r);
        specodec::JsonWriter w;
        NestOpt4Codec.encode(w, obj);
        writeFile(outDir + "/NestOpt4.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestOpt4 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestOpt4 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/NestOpt4.gron");
        specodec::GronReader r(data);
        auto obj = NestOpt4Codec.decode(r);
        specodec::GronWriter w;
        NestOpt4Codec.encode(w, obj);
        writeFile(outDir + "/NestOpt4.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestOpt4 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestOpt4 gron" << std::endl; }
}

void testModelNestOpt5(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/NestOpt5.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = NestOpt5Codec.decode(r);
        specodec::MsgPackWriter w;
        NestOpt5Codec.encode(w, obj);
        writeFile(outDir + "/NestOpt5.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestOpt5 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestOpt5 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/NestOpt5.json");
        specodec::JsonReader r(data);
        auto obj = NestOpt5Codec.decode(r);
        specodec::JsonWriter w;
        NestOpt5Codec.encode(w, obj);
        writeFile(outDir + "/NestOpt5.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestOpt5 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestOpt5 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/NestOpt5.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = NestOpt5Codec.decode(r);
        specodec::JsonWriter w;
        NestOpt5Codec.encode(w, obj);
        writeFile(outDir + "/NestOpt5.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestOpt5 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestOpt5 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/NestOpt5.gron");
        specodec::GronReader r(data);
        auto obj = NestOpt5Codec.decode(r);
        specodec::GronWriter w;
        NestOpt5Codec.encode(w, obj);
        writeFile(outDir + "/NestOpt5.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestOpt5 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestOpt5 gron" << std::endl; }
}

void testModelNestOptInner1(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/NestOptInner1.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = NestOptInner1Codec.decode(r);
        specodec::MsgPackWriter w;
        NestOptInner1Codec.encode(w, obj);
        writeFile(outDir + "/NestOptInner1.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestOptInner1 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestOptInner1 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/NestOptInner1.json");
        specodec::JsonReader r(data);
        auto obj = NestOptInner1Codec.decode(r);
        specodec::JsonWriter w;
        NestOptInner1Codec.encode(w, obj);
        writeFile(outDir + "/NestOptInner1.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestOptInner1 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestOptInner1 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/NestOptInner1.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = NestOptInner1Codec.decode(r);
        specodec::JsonWriter w;
        NestOptInner1Codec.encode(w, obj);
        writeFile(outDir + "/NestOptInner1.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestOptInner1 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestOptInner1 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/NestOptInner1.gron");
        specodec::GronReader r(data);
        auto obj = NestOptInner1Codec.decode(r);
        specodec::GronWriter w;
        NestOptInner1Codec.encode(w, obj);
        writeFile(outDir + "/NestOptInner1.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestOptInner1 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestOptInner1 gron" << std::endl; }
}

void testModelNestOptInner2(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/NestOptInner2.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = NestOptInner2Codec.decode(r);
        specodec::MsgPackWriter w;
        NestOptInner2Codec.encode(w, obj);
        writeFile(outDir + "/NestOptInner2.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestOptInner2 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestOptInner2 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/NestOptInner2.json");
        specodec::JsonReader r(data);
        auto obj = NestOptInner2Codec.decode(r);
        specodec::JsonWriter w;
        NestOptInner2Codec.encode(w, obj);
        writeFile(outDir + "/NestOptInner2.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestOptInner2 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestOptInner2 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/NestOptInner2.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = NestOptInner2Codec.decode(r);
        specodec::JsonWriter w;
        NestOptInner2Codec.encode(w, obj);
        writeFile(outDir + "/NestOptInner2.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestOptInner2 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestOptInner2 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/NestOptInner2.gron");
        specodec::GronReader r(data);
        auto obj = NestOptInner2Codec.decode(r);
        specodec::GronWriter w;
        NestOptInner2Codec.encode(w, obj);
        writeFile(outDir + "/NestOptInner2.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestOptInner2 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestOptInner2 gron" << std::endl; }
}

void testModelNestOptInner3(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/NestOptInner3.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = NestOptInner3Codec.decode(r);
        specodec::MsgPackWriter w;
        NestOptInner3Codec.encode(w, obj);
        writeFile(outDir + "/NestOptInner3.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestOptInner3 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestOptInner3 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/NestOptInner3.json");
        specodec::JsonReader r(data);
        auto obj = NestOptInner3Codec.decode(r);
        specodec::JsonWriter w;
        NestOptInner3Codec.encode(w, obj);
        writeFile(outDir + "/NestOptInner3.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestOptInner3 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestOptInner3 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/NestOptInner3.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = NestOptInner3Codec.decode(r);
        specodec::JsonWriter w;
        NestOptInner3Codec.encode(w, obj);
        writeFile(outDir + "/NestOptInner3.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestOptInner3 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestOptInner3 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/NestOptInner3.gron");
        specodec::GronReader r(data);
        auto obj = NestOptInner3Codec.decode(r);
        specodec::GronWriter w;
        NestOptInner3Codec.encode(w, obj);
        writeFile(outDir + "/NestOptInner3.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestOptInner3 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestOptInner3 gron" << std::endl; }
}

void testModelDeepNest1(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/DeepNest1.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = DeepNest1Codec.decode(r);
        specodec::MsgPackWriter w;
        DeepNest1Codec.encode(w, obj);
        writeFile(outDir + "/DeepNest1.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DeepNest1 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DeepNest1 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/DeepNest1.json");
        specodec::JsonReader r(data);
        auto obj = DeepNest1Codec.decode(r);
        specodec::JsonWriter w;
        DeepNest1Codec.encode(w, obj);
        writeFile(outDir + "/DeepNest1.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DeepNest1 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DeepNest1 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/DeepNest1.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = DeepNest1Codec.decode(r);
        specodec::JsonWriter w;
        DeepNest1Codec.encode(w, obj);
        writeFile(outDir + "/DeepNest1.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DeepNest1 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DeepNest1 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/DeepNest1.gron");
        specodec::GronReader r(data);
        auto obj = DeepNest1Codec.decode(r);
        specodec::GronWriter w;
        DeepNest1Codec.encode(w, obj);
        writeFile(outDir + "/DeepNest1.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DeepNest1 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DeepNest1 gron" << std::endl; }
}

void testModelDeepNest2(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/DeepNest2.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = DeepNest2Codec.decode(r);
        specodec::MsgPackWriter w;
        DeepNest2Codec.encode(w, obj);
        writeFile(outDir + "/DeepNest2.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DeepNest2 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DeepNest2 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/DeepNest2.json");
        specodec::JsonReader r(data);
        auto obj = DeepNest2Codec.decode(r);
        specodec::JsonWriter w;
        DeepNest2Codec.encode(w, obj);
        writeFile(outDir + "/DeepNest2.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DeepNest2 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DeepNest2 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/DeepNest2.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = DeepNest2Codec.decode(r);
        specodec::JsonWriter w;
        DeepNest2Codec.encode(w, obj);
        writeFile(outDir + "/DeepNest2.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DeepNest2 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DeepNest2 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/DeepNest2.gron");
        specodec::GronReader r(data);
        auto obj = DeepNest2Codec.decode(r);
        specodec::GronWriter w;
        DeepNest2Codec.encode(w, obj);
        writeFile(outDir + "/DeepNest2.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DeepNest2 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DeepNest2 gron" << std::endl; }
}

void testModelDeepNest3(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/DeepNest3.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = DeepNest3Codec.decode(r);
        specodec::MsgPackWriter w;
        DeepNest3Codec.encode(w, obj);
        writeFile(outDir + "/DeepNest3.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DeepNest3 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DeepNest3 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/DeepNest3.json");
        specodec::JsonReader r(data);
        auto obj = DeepNest3Codec.decode(r);
        specodec::JsonWriter w;
        DeepNest3Codec.encode(w, obj);
        writeFile(outDir + "/DeepNest3.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DeepNest3 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DeepNest3 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/DeepNest3.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = DeepNest3Codec.decode(r);
        specodec::JsonWriter w;
        DeepNest3Codec.encode(w, obj);
        writeFile(outDir + "/DeepNest3.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DeepNest3 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DeepNest3 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/DeepNest3.gron");
        specodec::GronReader r(data);
        auto obj = DeepNest3Codec.decode(r);
        specodec::GronWriter w;
        DeepNest3Codec.encode(w, obj);
        writeFile(outDir + "/DeepNest3.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DeepNest3 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DeepNest3 gron" << std::endl; }
}

void testModelDeepNest4(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/DeepNest4.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = DeepNest4Codec.decode(r);
        specodec::MsgPackWriter w;
        DeepNest4Codec.encode(w, obj);
        writeFile(outDir + "/DeepNest4.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DeepNest4 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DeepNest4 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/DeepNest4.json");
        specodec::JsonReader r(data);
        auto obj = DeepNest4Codec.decode(r);
        specodec::JsonWriter w;
        DeepNest4Codec.encode(w, obj);
        writeFile(outDir + "/DeepNest4.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DeepNest4 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DeepNest4 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/DeepNest4.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = DeepNest4Codec.decode(r);
        specodec::JsonWriter w;
        DeepNest4Codec.encode(w, obj);
        writeFile(outDir + "/DeepNest4.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DeepNest4 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DeepNest4 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/DeepNest4.gron");
        specodec::GronReader r(data);
        auto obj = DeepNest4Codec.decode(r);
        specodec::GronWriter w;
        DeepNest4Codec.encode(w, obj);
        writeFile(outDir + "/DeepNest4.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DeepNest4 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DeepNest4 gron" << std::endl; }
}

void testModelDeepNest5(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/DeepNest5.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = DeepNest5Codec.decode(r);
        specodec::MsgPackWriter w;
        DeepNest5Codec.encode(w, obj);
        writeFile(outDir + "/DeepNest5.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DeepNest5 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DeepNest5 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/DeepNest5.json");
        specodec::JsonReader r(data);
        auto obj = DeepNest5Codec.decode(r);
        specodec::JsonWriter w;
        DeepNest5Codec.encode(w, obj);
        writeFile(outDir + "/DeepNest5.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DeepNest5 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DeepNest5 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/DeepNest5.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = DeepNest5Codec.decode(r);
        specodec::JsonWriter w;
        DeepNest5Codec.encode(w, obj);
        writeFile(outDir + "/DeepNest5.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DeepNest5 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DeepNest5 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/DeepNest5.gron");
        specodec::GronReader r(data);
        auto obj = DeepNest5Codec.decode(r);
        specodec::GronWriter w;
        DeepNest5Codec.encode(w, obj);
        writeFile(outDir + "/DeepNest5.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DeepNest5 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DeepNest5 gron" << std::endl; }
}

void testModelDeepNest6(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/DeepNest6.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = DeepNest6Codec.decode(r);
        specodec::MsgPackWriter w;
        DeepNest6Codec.encode(w, obj);
        writeFile(outDir + "/DeepNest6.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DeepNest6 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DeepNest6 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/DeepNest6.json");
        specodec::JsonReader r(data);
        auto obj = DeepNest6Codec.decode(r);
        specodec::JsonWriter w;
        DeepNest6Codec.encode(w, obj);
        writeFile(outDir + "/DeepNest6.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DeepNest6 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DeepNest6 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/DeepNest6.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = DeepNest6Codec.decode(r);
        specodec::JsonWriter w;
        DeepNest6Codec.encode(w, obj);
        writeFile(outDir + "/DeepNest6.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DeepNest6 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DeepNest6 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/DeepNest6.gron");
        specodec::GronReader r(data);
        auto obj = DeepNest6Codec.decode(r);
        specodec::GronWriter w;
        DeepNest6Codec.encode(w, obj);
        writeFile(outDir + "/DeepNest6.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DeepNest6 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DeepNest6 gron" << std::endl; }
}

void testModelDeepNest7(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/DeepNest7.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = DeepNest7Codec.decode(r);
        specodec::MsgPackWriter w;
        DeepNest7Codec.encode(w, obj);
        writeFile(outDir + "/DeepNest7.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DeepNest7 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DeepNest7 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/DeepNest7.json");
        specodec::JsonReader r(data);
        auto obj = DeepNest7Codec.decode(r);
        specodec::JsonWriter w;
        DeepNest7Codec.encode(w, obj);
        writeFile(outDir + "/DeepNest7.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DeepNest7 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DeepNest7 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/DeepNest7.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = DeepNest7Codec.decode(r);
        specodec::JsonWriter w;
        DeepNest7Codec.encode(w, obj);
        writeFile(outDir + "/DeepNest7.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DeepNest7 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DeepNest7 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/DeepNest7.gron");
        specodec::GronReader r(data);
        auto obj = DeepNest7Codec.decode(r);
        specodec::GronWriter w;
        DeepNest7Codec.encode(w, obj);
        writeFile(outDir + "/DeepNest7.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DeepNest7 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DeepNest7 gron" << std::endl; }
}

void testModelTimestampEntry(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/TimestampEntry.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = TimestampEntryCodec.decode(r);
        specodec::MsgPackWriter w;
        TimestampEntryCodec.encode(w, obj);
        writeFile(outDir + "/TimestampEntry.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL TimestampEntry mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL TimestampEntry mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/TimestampEntry.json");
        specodec::JsonReader r(data);
        auto obj = TimestampEntryCodec.decode(r);
        specodec::JsonWriter w;
        TimestampEntryCodec.encode(w, obj);
        writeFile(outDir + "/TimestampEntry.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL TimestampEntry json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL TimestampEntry json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/TimestampEntry.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = TimestampEntryCodec.decode(r);
        specodec::JsonWriter w;
        TimestampEntryCodec.encode(w, obj);
        writeFile(outDir + "/TimestampEntry.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL TimestampEntry unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL TimestampEntry unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/TimestampEntry.gron");
        specodec::GronReader r(data);
        auto obj = TimestampEntryCodec.decode(r);
        specodec::GronWriter w;
        TimestampEntryCodec.encode(w, obj);
        writeFile(outDir + "/TimestampEntry.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL TimestampEntry gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL TimestampEntry gron" << std::endl; }
}

void testModelConfigEntry(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/ConfigEntry.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = ConfigEntryCodec.decode(r);
        specodec::MsgPackWriter w;
        ConfigEntryCodec.encode(w, obj);
        writeFile(outDir + "/ConfigEntry.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ConfigEntry mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ConfigEntry mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/ConfigEntry.json");
        specodec::JsonReader r(data);
        auto obj = ConfigEntryCodec.decode(r);
        specodec::JsonWriter w;
        ConfigEntryCodec.encode(w, obj);
        writeFile(outDir + "/ConfigEntry.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ConfigEntry json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ConfigEntry json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/ConfigEntry.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = ConfigEntryCodec.decode(r);
        specodec::JsonWriter w;
        ConfigEntryCodec.encode(w, obj);
        writeFile(outDir + "/ConfigEntry.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ConfigEntry unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ConfigEntry unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/ConfigEntry.gron");
        specodec::GronReader r(data);
        auto obj = ConfigEntryCodec.decode(r);
        specodec::GronWriter w;
        ConfigEntryCodec.encode(w, obj);
        writeFile(outDir + "/ConfigEntry.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ConfigEntry gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ConfigEntry gron" << std::endl; }
}


export void runAlltypes_extra(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    testModelOptArr1(passed, failed, vecDir, outDir);
    testModelOptArr2(passed, failed, vecDir, outDir);
    testModelOptArr3(passed, failed, vecDir, outDir);
    testModelOptArr4(passed, failed, vecDir, outDir);
    testModelOptArr5(passed, failed, vecDir, outDir);
    testModelNestOpt1(passed, failed, vecDir, outDir);
    testModelNestOpt2(passed, failed, vecDir, outDir);
    testModelNestOpt3(passed, failed, vecDir, outDir);
    testModelNestOpt4(passed, failed, vecDir, outDir);
    testModelNestOpt5(passed, failed, vecDir, outDir);
    testModelNestOptInner1(passed, failed, vecDir, outDir);
    testModelNestOptInner2(passed, failed, vecDir, outDir);
    testModelNestOptInner3(passed, failed, vecDir, outDir);
    testModelDeepNest1(passed, failed, vecDir, outDir);
    testModelDeepNest2(passed, failed, vecDir, outDir);
    testModelDeepNest3(passed, failed, vecDir, outDir);
    testModelDeepNest4(passed, failed, vecDir, outDir);
    testModelDeepNest5(passed, failed, vecDir, outDir);
    testModelDeepNest6(passed, failed, vecDir, outDir);
    testModelDeepNest7(passed, failed, vecDir, outDir);
    testModelTimestampEntry(passed, failed, vecDir, outDir);
    testModelConfigEntry(passed, failed, vecDir, outDir);

}
