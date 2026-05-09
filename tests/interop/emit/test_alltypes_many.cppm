module;
#include <cstdlib>
#include <fstream>
#include <filesystem>
export module test_alltypes_many;
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


void testModelFive01(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Five01.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Five01Codec.decode(r);
        specodec::MsgPackWriter w;
        Five01Codec.encode(w, obj);
        writeFile(outDir + "/Five01.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Five01 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Five01 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Five01.json");
        specodec::JsonReader r(data);
        auto obj = Five01Codec.decode(r);
        specodec::JsonWriter w;
        Five01Codec.encode(w, obj);
        writeFile(outDir + "/Five01.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Five01 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Five01 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Five01.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Five01Codec.decode(r);
        specodec::JsonWriter w;
        Five01Codec.encode(w, obj);
        writeFile(outDir + "/Five01.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Five01 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Five01 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Five01.gron");
        specodec::GronReader r(data);
        auto obj = Five01Codec.decode(r);
        specodec::GronWriter w;
        Five01Codec.encode(w, obj);
        writeFile(outDir + "/Five01.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Five01 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Five01 gron" << std::endl; }
}

void testModelFive02(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Five02.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Five02Codec.decode(r);
        specodec::MsgPackWriter w;
        Five02Codec.encode(w, obj);
        writeFile(outDir + "/Five02.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Five02 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Five02 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Five02.json");
        specodec::JsonReader r(data);
        auto obj = Five02Codec.decode(r);
        specodec::JsonWriter w;
        Five02Codec.encode(w, obj);
        writeFile(outDir + "/Five02.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Five02 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Five02 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Five02.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Five02Codec.decode(r);
        specodec::JsonWriter w;
        Five02Codec.encode(w, obj);
        writeFile(outDir + "/Five02.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Five02 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Five02 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Five02.gron");
        specodec::GronReader r(data);
        auto obj = Five02Codec.decode(r);
        specodec::GronWriter w;
        Five02Codec.encode(w, obj);
        writeFile(outDir + "/Five02.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Five02 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Five02 gron" << std::endl; }
}

void testModelFive03(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Five03.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Five03Codec.decode(r);
        specodec::MsgPackWriter w;
        Five03Codec.encode(w, obj);
        writeFile(outDir + "/Five03.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Five03 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Five03 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Five03.json");
        specodec::JsonReader r(data);
        auto obj = Five03Codec.decode(r);
        specodec::JsonWriter w;
        Five03Codec.encode(w, obj);
        writeFile(outDir + "/Five03.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Five03 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Five03 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Five03.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Five03Codec.decode(r);
        specodec::JsonWriter w;
        Five03Codec.encode(w, obj);
        writeFile(outDir + "/Five03.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Five03 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Five03 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Five03.gron");
        specodec::GronReader r(data);
        auto obj = Five03Codec.decode(r);
        specodec::GronWriter w;
        Five03Codec.encode(w, obj);
        writeFile(outDir + "/Five03.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Five03 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Five03 gron" << std::endl; }
}

void testModelFive04(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Five04.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Five04Codec.decode(r);
        specodec::MsgPackWriter w;
        Five04Codec.encode(w, obj);
        writeFile(outDir + "/Five04.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Five04 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Five04 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Five04.json");
        specodec::JsonReader r(data);
        auto obj = Five04Codec.decode(r);
        specodec::JsonWriter w;
        Five04Codec.encode(w, obj);
        writeFile(outDir + "/Five04.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Five04 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Five04 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Five04.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Five04Codec.decode(r);
        specodec::JsonWriter w;
        Five04Codec.encode(w, obj);
        writeFile(outDir + "/Five04.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Five04 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Five04 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Five04.gron");
        specodec::GronReader r(data);
        auto obj = Five04Codec.decode(r);
        specodec::GronWriter w;
        Five04Codec.encode(w, obj);
        writeFile(outDir + "/Five04.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Five04 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Five04 gron" << std::endl; }
}

void testModelFive05(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Five05.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Five05Codec.decode(r);
        specodec::MsgPackWriter w;
        Five05Codec.encode(w, obj);
        writeFile(outDir + "/Five05.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Five05 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Five05 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Five05.json");
        specodec::JsonReader r(data);
        auto obj = Five05Codec.decode(r);
        specodec::JsonWriter w;
        Five05Codec.encode(w, obj);
        writeFile(outDir + "/Five05.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Five05 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Five05 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Five05.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Five05Codec.decode(r);
        specodec::JsonWriter w;
        Five05Codec.encode(w, obj);
        writeFile(outDir + "/Five05.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Five05 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Five05 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Five05.gron");
        specodec::GronReader r(data);
        auto obj = Five05Codec.decode(r);
        specodec::GronWriter w;
        Five05Codec.encode(w, obj);
        writeFile(outDir + "/Five05.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Five05 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Five05 gron" << std::endl; }
}

void testModelFive06(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Five06.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Five06Codec.decode(r);
        specodec::MsgPackWriter w;
        Five06Codec.encode(w, obj);
        writeFile(outDir + "/Five06.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Five06 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Five06 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Five06.json");
        specodec::JsonReader r(data);
        auto obj = Five06Codec.decode(r);
        specodec::JsonWriter w;
        Five06Codec.encode(w, obj);
        writeFile(outDir + "/Five06.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Five06 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Five06 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Five06.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Five06Codec.decode(r);
        specodec::JsonWriter w;
        Five06Codec.encode(w, obj);
        writeFile(outDir + "/Five06.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Five06 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Five06 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Five06.gron");
        specodec::GronReader r(data);
        auto obj = Five06Codec.decode(r);
        specodec::GronWriter w;
        Five06Codec.encode(w, obj);
        writeFile(outDir + "/Five06.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Five06 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Five06 gron" << std::endl; }
}

void testModelFive07(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Five07.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Five07Codec.decode(r);
        specodec::MsgPackWriter w;
        Five07Codec.encode(w, obj);
        writeFile(outDir + "/Five07.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Five07 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Five07 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Five07.json");
        specodec::JsonReader r(data);
        auto obj = Five07Codec.decode(r);
        specodec::JsonWriter w;
        Five07Codec.encode(w, obj);
        writeFile(outDir + "/Five07.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Five07 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Five07 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Five07.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Five07Codec.decode(r);
        specodec::JsonWriter w;
        Five07Codec.encode(w, obj);
        writeFile(outDir + "/Five07.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Five07 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Five07 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Five07.gron");
        specodec::GronReader r(data);
        auto obj = Five07Codec.decode(r);
        specodec::GronWriter w;
        Five07Codec.encode(w, obj);
        writeFile(outDir + "/Five07.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Five07 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Five07 gron" << std::endl; }
}

void testModelFive08(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Five08.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Five08Codec.decode(r);
        specodec::MsgPackWriter w;
        Five08Codec.encode(w, obj);
        writeFile(outDir + "/Five08.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Five08 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Five08 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Five08.json");
        specodec::JsonReader r(data);
        auto obj = Five08Codec.decode(r);
        specodec::JsonWriter w;
        Five08Codec.encode(w, obj);
        writeFile(outDir + "/Five08.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Five08 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Five08 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Five08.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Five08Codec.decode(r);
        specodec::JsonWriter w;
        Five08Codec.encode(w, obj);
        writeFile(outDir + "/Five08.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Five08 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Five08 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Five08.gron");
        specodec::GronReader r(data);
        auto obj = Five08Codec.decode(r);
        specodec::GronWriter w;
        Five08Codec.encode(w, obj);
        writeFile(outDir + "/Five08.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Five08 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Five08 gron" << std::endl; }
}

void testModelFive09(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Five09.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Five09Codec.decode(r);
        specodec::MsgPackWriter w;
        Five09Codec.encode(w, obj);
        writeFile(outDir + "/Five09.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Five09 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Five09 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Five09.json");
        specodec::JsonReader r(data);
        auto obj = Five09Codec.decode(r);
        specodec::JsonWriter w;
        Five09Codec.encode(w, obj);
        writeFile(outDir + "/Five09.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Five09 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Five09 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Five09.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Five09Codec.decode(r);
        specodec::JsonWriter w;
        Five09Codec.encode(w, obj);
        writeFile(outDir + "/Five09.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Five09 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Five09 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Five09.gron");
        specodec::GronReader r(data);
        auto obj = Five09Codec.decode(r);
        specodec::GronWriter w;
        Five09Codec.encode(w, obj);
        writeFile(outDir + "/Five09.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Five09 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Five09 gron" << std::endl; }
}

void testModelFive10(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Five10.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Five10Codec.decode(r);
        specodec::MsgPackWriter w;
        Five10Codec.encode(w, obj);
        writeFile(outDir + "/Five10.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Five10 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Five10 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Five10.json");
        specodec::JsonReader r(data);
        auto obj = Five10Codec.decode(r);
        specodec::JsonWriter w;
        Five10Codec.encode(w, obj);
        writeFile(outDir + "/Five10.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Five10 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Five10 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Five10.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Five10Codec.decode(r);
        specodec::JsonWriter w;
        Five10Codec.encode(w, obj);
        writeFile(outDir + "/Five10.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Five10 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Five10 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Five10.gron");
        specodec::GronReader r(data);
        auto obj = Five10Codec.decode(r);
        specodec::GronWriter w;
        Five10Codec.encode(w, obj);
        writeFile(outDir + "/Five10.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Five10 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Five10 gron" << std::endl; }
}

void testModelTen01(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Ten01.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Ten01Codec.decode(r);
        specodec::MsgPackWriter w;
        Ten01Codec.encode(w, obj);
        writeFile(outDir + "/Ten01.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Ten01 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Ten01 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Ten01.json");
        specodec::JsonReader r(data);
        auto obj = Ten01Codec.decode(r);
        specodec::JsonWriter w;
        Ten01Codec.encode(w, obj);
        writeFile(outDir + "/Ten01.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Ten01 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Ten01 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Ten01.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Ten01Codec.decode(r);
        specodec::JsonWriter w;
        Ten01Codec.encode(w, obj);
        writeFile(outDir + "/Ten01.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Ten01 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Ten01 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Ten01.gron");
        specodec::GronReader r(data);
        auto obj = Ten01Codec.decode(r);
        specodec::GronWriter w;
        Ten01Codec.encode(w, obj);
        writeFile(outDir + "/Ten01.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Ten01 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Ten01 gron" << std::endl; }
}

void testModelTen02(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Ten02.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Ten02Codec.decode(r);
        specodec::MsgPackWriter w;
        Ten02Codec.encode(w, obj);
        writeFile(outDir + "/Ten02.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Ten02 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Ten02 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Ten02.json");
        specodec::JsonReader r(data);
        auto obj = Ten02Codec.decode(r);
        specodec::JsonWriter w;
        Ten02Codec.encode(w, obj);
        writeFile(outDir + "/Ten02.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Ten02 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Ten02 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Ten02.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Ten02Codec.decode(r);
        specodec::JsonWriter w;
        Ten02Codec.encode(w, obj);
        writeFile(outDir + "/Ten02.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Ten02 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Ten02 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Ten02.gron");
        specodec::GronReader r(data);
        auto obj = Ten02Codec.decode(r);
        specodec::GronWriter w;
        Ten02Codec.encode(w, obj);
        writeFile(outDir + "/Ten02.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Ten02 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Ten02 gron" << std::endl; }
}

void testModelTen03(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Ten03.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Ten03Codec.decode(r);
        specodec::MsgPackWriter w;
        Ten03Codec.encode(w, obj);
        writeFile(outDir + "/Ten03.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Ten03 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Ten03 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Ten03.json");
        specodec::JsonReader r(data);
        auto obj = Ten03Codec.decode(r);
        specodec::JsonWriter w;
        Ten03Codec.encode(w, obj);
        writeFile(outDir + "/Ten03.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Ten03 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Ten03 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Ten03.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Ten03Codec.decode(r);
        specodec::JsonWriter w;
        Ten03Codec.encode(w, obj);
        writeFile(outDir + "/Ten03.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Ten03 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Ten03 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Ten03.gron");
        specodec::GronReader r(data);
        auto obj = Ten03Codec.decode(r);
        specodec::GronWriter w;
        Ten03Codec.encode(w, obj);
        writeFile(outDir + "/Ten03.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Ten03 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Ten03 gron" << std::endl; }
}

void testModelTen04(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Ten04.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Ten04Codec.decode(r);
        specodec::MsgPackWriter w;
        Ten04Codec.encode(w, obj);
        writeFile(outDir + "/Ten04.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Ten04 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Ten04 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Ten04.json");
        specodec::JsonReader r(data);
        auto obj = Ten04Codec.decode(r);
        specodec::JsonWriter w;
        Ten04Codec.encode(w, obj);
        writeFile(outDir + "/Ten04.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Ten04 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Ten04 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Ten04.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Ten04Codec.decode(r);
        specodec::JsonWriter w;
        Ten04Codec.encode(w, obj);
        writeFile(outDir + "/Ten04.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Ten04 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Ten04 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Ten04.gron");
        specodec::GronReader r(data);
        auto obj = Ten04Codec.decode(r);
        specodec::GronWriter w;
        Ten04Codec.encode(w, obj);
        writeFile(outDir + "/Ten04.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Ten04 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Ten04 gron" << std::endl; }
}

void testModelTen05(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Ten05.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Ten05Codec.decode(r);
        specodec::MsgPackWriter w;
        Ten05Codec.encode(w, obj);
        writeFile(outDir + "/Ten05.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Ten05 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Ten05 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Ten05.json");
        specodec::JsonReader r(data);
        auto obj = Ten05Codec.decode(r);
        specodec::JsonWriter w;
        Ten05Codec.encode(w, obj);
        writeFile(outDir + "/Ten05.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Ten05 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Ten05 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Ten05.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Ten05Codec.decode(r);
        specodec::JsonWriter w;
        Ten05Codec.encode(w, obj);
        writeFile(outDir + "/Ten05.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Ten05 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Ten05 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Ten05.gron");
        specodec::GronReader r(data);
        auto obj = Ten05Codec.decode(r);
        specodec::GronWriter w;
        Ten05Codec.encode(w, obj);
        writeFile(outDir + "/Ten05.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Ten05 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Ten05 gron" << std::endl; }
}


export void runAlltypes_many(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    testModelFive01(passed, failed, vecDir, outDir);
    testModelFive02(passed, failed, vecDir, outDir);
    testModelFive03(passed, failed, vecDir, outDir);
    testModelFive04(passed, failed, vecDir, outDir);
    testModelFive05(passed, failed, vecDir, outDir);
    testModelFive06(passed, failed, vecDir, outDir);
    testModelFive07(passed, failed, vecDir, outDir);
    testModelFive08(passed, failed, vecDir, outDir);
    testModelFive09(passed, failed, vecDir, outDir);
    testModelFive10(passed, failed, vecDir, outDir);
    testModelTen01(passed, failed, vecDir, outDir);
    testModelTen02(passed, failed, vecDir, outDir);
    testModelTen03(passed, failed, vecDir, outDir);
    testModelTen04(passed, failed, vecDir, outDir);
    testModelTen05(passed, failed, vecDir, outDir);

}
