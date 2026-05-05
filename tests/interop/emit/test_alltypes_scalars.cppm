module;
#include <cstdlib>
#include <fstream>
#include <filesystem>
export module test_alltypes_scalars;
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


void testModelSingleString(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/SingleString.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = SingleStringCodec.decode(r);
        specodec::MsgPackWriter w;
        SingleStringCodec.encode(w, obj);
        writeFile(outDir + "/SingleString.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL SingleString mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL SingleString mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/SingleString.json");
        specodec::JsonReader r(data);
        auto obj = SingleStringCodec.decode(r);
        specodec::JsonWriter w;
        SingleStringCodec.encode(w, obj);
        writeFile(outDir + "/SingleString.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL SingleString json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL SingleString json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/SingleString.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = SingleStringCodec.decode(r);
        specodec::JsonWriter w;
        SingleStringCodec.encode(w, obj);
        writeFile(outDir + "/SingleString.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL SingleString unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL SingleString unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/SingleString.gron");
        specodec::GronReader r(data);
        auto obj = SingleStringCodec.decode(r);
        specodec::GronWriter w;
        SingleStringCodec.encode(w, obj);
        writeFile(outDir + "/SingleString.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL SingleString gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL SingleString gron" << std::endl; }
}

void testModelSingleBoolean(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/SingleBoolean.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = SingleBooleanCodec.decode(r);
        specodec::MsgPackWriter w;
        SingleBooleanCodec.encode(w, obj);
        writeFile(outDir + "/SingleBoolean.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL SingleBoolean mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL SingleBoolean mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/SingleBoolean.json");
        specodec::JsonReader r(data);
        auto obj = SingleBooleanCodec.decode(r);
        specodec::JsonWriter w;
        SingleBooleanCodec.encode(w, obj);
        writeFile(outDir + "/SingleBoolean.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL SingleBoolean json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL SingleBoolean json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/SingleBoolean.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = SingleBooleanCodec.decode(r);
        specodec::JsonWriter w;
        SingleBooleanCodec.encode(w, obj);
        writeFile(outDir + "/SingleBoolean.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL SingleBoolean unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL SingleBoolean unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/SingleBoolean.gron");
        specodec::GronReader r(data);
        auto obj = SingleBooleanCodec.decode(r);
        specodec::GronWriter w;
        SingleBooleanCodec.encode(w, obj);
        writeFile(outDir + "/SingleBoolean.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL SingleBoolean gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL SingleBoolean gron" << std::endl; }
}

void testModelSingleInt8(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/SingleInt8.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = SingleInt8Codec.decode(r);
        specodec::MsgPackWriter w;
        SingleInt8Codec.encode(w, obj);
        writeFile(outDir + "/SingleInt8.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL SingleInt8 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL SingleInt8 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/SingleInt8.json");
        specodec::JsonReader r(data);
        auto obj = SingleInt8Codec.decode(r);
        specodec::JsonWriter w;
        SingleInt8Codec.encode(w, obj);
        writeFile(outDir + "/SingleInt8.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL SingleInt8 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL SingleInt8 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/SingleInt8.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = SingleInt8Codec.decode(r);
        specodec::JsonWriter w;
        SingleInt8Codec.encode(w, obj);
        writeFile(outDir + "/SingleInt8.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL SingleInt8 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL SingleInt8 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/SingleInt8.gron");
        specodec::GronReader r(data);
        auto obj = SingleInt8Codec.decode(r);
        specodec::GronWriter w;
        SingleInt8Codec.encode(w, obj);
        writeFile(outDir + "/SingleInt8.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL SingleInt8 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL SingleInt8 gron" << std::endl; }
}

void testModelSingleInt16(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/SingleInt16.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = SingleInt16Codec.decode(r);
        specodec::MsgPackWriter w;
        SingleInt16Codec.encode(w, obj);
        writeFile(outDir + "/SingleInt16.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL SingleInt16 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL SingleInt16 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/SingleInt16.json");
        specodec::JsonReader r(data);
        auto obj = SingleInt16Codec.decode(r);
        specodec::JsonWriter w;
        SingleInt16Codec.encode(w, obj);
        writeFile(outDir + "/SingleInt16.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL SingleInt16 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL SingleInt16 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/SingleInt16.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = SingleInt16Codec.decode(r);
        specodec::JsonWriter w;
        SingleInt16Codec.encode(w, obj);
        writeFile(outDir + "/SingleInt16.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL SingleInt16 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL SingleInt16 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/SingleInt16.gron");
        specodec::GronReader r(data);
        auto obj = SingleInt16Codec.decode(r);
        specodec::GronWriter w;
        SingleInt16Codec.encode(w, obj);
        writeFile(outDir + "/SingleInt16.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL SingleInt16 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL SingleInt16 gron" << std::endl; }
}

void testModelSingleInt32(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/SingleInt32.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = SingleInt32Codec.decode(r);
        specodec::MsgPackWriter w;
        SingleInt32Codec.encode(w, obj);
        writeFile(outDir + "/SingleInt32.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL SingleInt32 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL SingleInt32 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/SingleInt32.json");
        specodec::JsonReader r(data);
        auto obj = SingleInt32Codec.decode(r);
        specodec::JsonWriter w;
        SingleInt32Codec.encode(w, obj);
        writeFile(outDir + "/SingleInt32.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL SingleInt32 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL SingleInt32 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/SingleInt32.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = SingleInt32Codec.decode(r);
        specodec::JsonWriter w;
        SingleInt32Codec.encode(w, obj);
        writeFile(outDir + "/SingleInt32.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL SingleInt32 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL SingleInt32 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/SingleInt32.gron");
        specodec::GronReader r(data);
        auto obj = SingleInt32Codec.decode(r);
        specodec::GronWriter w;
        SingleInt32Codec.encode(w, obj);
        writeFile(outDir + "/SingleInt32.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL SingleInt32 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL SingleInt32 gron" << std::endl; }
}

void testModelSingleInt64(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/SingleInt64.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = SingleInt64Codec.decode(r);
        specodec::MsgPackWriter w;
        SingleInt64Codec.encode(w, obj);
        writeFile(outDir + "/SingleInt64.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL SingleInt64 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL SingleInt64 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/SingleInt64.json");
        specodec::JsonReader r(data);
        auto obj = SingleInt64Codec.decode(r);
        specodec::JsonWriter w;
        SingleInt64Codec.encode(w, obj);
        writeFile(outDir + "/SingleInt64.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL SingleInt64 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL SingleInt64 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/SingleInt64.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = SingleInt64Codec.decode(r);
        specodec::JsonWriter w;
        SingleInt64Codec.encode(w, obj);
        writeFile(outDir + "/SingleInt64.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL SingleInt64 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL SingleInt64 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/SingleInt64.gron");
        specodec::GronReader r(data);
        auto obj = SingleInt64Codec.decode(r);
        specodec::GronWriter w;
        SingleInt64Codec.encode(w, obj);
        writeFile(outDir + "/SingleInt64.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL SingleInt64 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL SingleInt64 gron" << std::endl; }
}

void testModelSingleUint8(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/SingleUint8.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = SingleUint8Codec.decode(r);
        specodec::MsgPackWriter w;
        SingleUint8Codec.encode(w, obj);
        writeFile(outDir + "/SingleUint8.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL SingleUint8 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL SingleUint8 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/SingleUint8.json");
        specodec::JsonReader r(data);
        auto obj = SingleUint8Codec.decode(r);
        specodec::JsonWriter w;
        SingleUint8Codec.encode(w, obj);
        writeFile(outDir + "/SingleUint8.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL SingleUint8 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL SingleUint8 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/SingleUint8.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = SingleUint8Codec.decode(r);
        specodec::JsonWriter w;
        SingleUint8Codec.encode(w, obj);
        writeFile(outDir + "/SingleUint8.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL SingleUint8 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL SingleUint8 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/SingleUint8.gron");
        specodec::GronReader r(data);
        auto obj = SingleUint8Codec.decode(r);
        specodec::GronWriter w;
        SingleUint8Codec.encode(w, obj);
        writeFile(outDir + "/SingleUint8.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL SingleUint8 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL SingleUint8 gron" << std::endl; }
}

void testModelSingleUint16(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/SingleUint16.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = SingleUint16Codec.decode(r);
        specodec::MsgPackWriter w;
        SingleUint16Codec.encode(w, obj);
        writeFile(outDir + "/SingleUint16.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL SingleUint16 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL SingleUint16 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/SingleUint16.json");
        specodec::JsonReader r(data);
        auto obj = SingleUint16Codec.decode(r);
        specodec::JsonWriter w;
        SingleUint16Codec.encode(w, obj);
        writeFile(outDir + "/SingleUint16.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL SingleUint16 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL SingleUint16 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/SingleUint16.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = SingleUint16Codec.decode(r);
        specodec::JsonWriter w;
        SingleUint16Codec.encode(w, obj);
        writeFile(outDir + "/SingleUint16.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL SingleUint16 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL SingleUint16 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/SingleUint16.gron");
        specodec::GronReader r(data);
        auto obj = SingleUint16Codec.decode(r);
        specodec::GronWriter w;
        SingleUint16Codec.encode(w, obj);
        writeFile(outDir + "/SingleUint16.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL SingleUint16 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL SingleUint16 gron" << std::endl; }
}

void testModelSingleUint32(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/SingleUint32.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = SingleUint32Codec.decode(r);
        specodec::MsgPackWriter w;
        SingleUint32Codec.encode(w, obj);
        writeFile(outDir + "/SingleUint32.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL SingleUint32 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL SingleUint32 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/SingleUint32.json");
        specodec::JsonReader r(data);
        auto obj = SingleUint32Codec.decode(r);
        specodec::JsonWriter w;
        SingleUint32Codec.encode(w, obj);
        writeFile(outDir + "/SingleUint32.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL SingleUint32 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL SingleUint32 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/SingleUint32.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = SingleUint32Codec.decode(r);
        specodec::JsonWriter w;
        SingleUint32Codec.encode(w, obj);
        writeFile(outDir + "/SingleUint32.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL SingleUint32 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL SingleUint32 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/SingleUint32.gron");
        specodec::GronReader r(data);
        auto obj = SingleUint32Codec.decode(r);
        specodec::GronWriter w;
        SingleUint32Codec.encode(w, obj);
        writeFile(outDir + "/SingleUint32.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL SingleUint32 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL SingleUint32 gron" << std::endl; }
}

void testModelSingleUint64(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/SingleUint64.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = SingleUint64Codec.decode(r);
        specodec::MsgPackWriter w;
        SingleUint64Codec.encode(w, obj);
        writeFile(outDir + "/SingleUint64.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL SingleUint64 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL SingleUint64 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/SingleUint64.json");
        specodec::JsonReader r(data);
        auto obj = SingleUint64Codec.decode(r);
        specodec::JsonWriter w;
        SingleUint64Codec.encode(w, obj);
        writeFile(outDir + "/SingleUint64.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL SingleUint64 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL SingleUint64 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/SingleUint64.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = SingleUint64Codec.decode(r);
        specodec::JsonWriter w;
        SingleUint64Codec.encode(w, obj);
        writeFile(outDir + "/SingleUint64.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL SingleUint64 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL SingleUint64 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/SingleUint64.gron");
        specodec::GronReader r(data);
        auto obj = SingleUint64Codec.decode(r);
        specodec::GronWriter w;
        SingleUint64Codec.encode(w, obj);
        writeFile(outDir + "/SingleUint64.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL SingleUint64 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL SingleUint64 gron" << std::endl; }
}

void testModelSingleFloat32(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/SingleFloat32.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = SingleFloat32Codec.decode(r);
        specodec::MsgPackWriter w;
        SingleFloat32Codec.encode(w, obj);
        writeFile(outDir + "/SingleFloat32.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL SingleFloat32 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL SingleFloat32 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/SingleFloat32.json");
        specodec::JsonReader r(data);
        auto obj = SingleFloat32Codec.decode(r);
        specodec::JsonWriter w;
        SingleFloat32Codec.encode(w, obj);
        writeFile(outDir + "/SingleFloat32.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL SingleFloat32 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL SingleFloat32 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/SingleFloat32.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = SingleFloat32Codec.decode(r);
        specodec::JsonWriter w;
        SingleFloat32Codec.encode(w, obj);
        writeFile(outDir + "/SingleFloat32.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL SingleFloat32 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL SingleFloat32 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/SingleFloat32.gron");
        specodec::GronReader r(data);
        auto obj = SingleFloat32Codec.decode(r);
        specodec::GronWriter w;
        SingleFloat32Codec.encode(w, obj);
        writeFile(outDir + "/SingleFloat32.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL SingleFloat32 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL SingleFloat32 gron" << std::endl; }
}

void testModelSingleFloat64(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/SingleFloat64.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = SingleFloat64Codec.decode(r);
        specodec::MsgPackWriter w;
        SingleFloat64Codec.encode(w, obj);
        writeFile(outDir + "/SingleFloat64.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL SingleFloat64 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL SingleFloat64 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/SingleFloat64.json");
        specodec::JsonReader r(data);
        auto obj = SingleFloat64Codec.decode(r);
        specodec::JsonWriter w;
        SingleFloat64Codec.encode(w, obj);
        writeFile(outDir + "/SingleFloat64.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL SingleFloat64 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL SingleFloat64 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/SingleFloat64.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = SingleFloat64Codec.decode(r);
        specodec::JsonWriter w;
        SingleFloat64Codec.encode(w, obj);
        writeFile(outDir + "/SingleFloat64.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL SingleFloat64 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL SingleFloat64 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/SingleFloat64.gron");
        specodec::GronReader r(data);
        auto obj = SingleFloat64Codec.decode(r);
        specodec::GronWriter w;
        SingleFloat64Codec.encode(w, obj);
        writeFile(outDir + "/SingleFloat64.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL SingleFloat64 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL SingleFloat64 gron" << std::endl; }
}

void testModelSingleBytes(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/SingleBytes.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = SingleBytesCodec.decode(r);
        specodec::MsgPackWriter w;
        SingleBytesCodec.encode(w, obj);
        writeFile(outDir + "/SingleBytes.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL SingleBytes mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL SingleBytes mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/SingleBytes.json");
        specodec::JsonReader r(data);
        auto obj = SingleBytesCodec.decode(r);
        specodec::JsonWriter w;
        SingleBytesCodec.encode(w, obj);
        writeFile(outDir + "/SingleBytes.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL SingleBytes json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL SingleBytes json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/SingleBytes.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = SingleBytesCodec.decode(r);
        specodec::JsonWriter w;
        SingleBytesCodec.encode(w, obj);
        writeFile(outDir + "/SingleBytes.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL SingleBytes unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL SingleBytes unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/SingleBytes.gron");
        specodec::GronReader r(data);
        auto obj = SingleBytesCodec.decode(r);
        specodec::GronWriter w;
        SingleBytesCodec.encode(w, obj);
        writeFile(outDir + "/SingleBytes.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL SingleBytes gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL SingleBytes gron" << std::endl; }
}


export void runAlltypes_scalars(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    testModelSingleString(passed, failed, vecDir, outDir);
    testModelSingleBoolean(passed, failed, vecDir, outDir);
    testModelSingleInt8(passed, failed, vecDir, outDir);
    testModelSingleInt16(passed, failed, vecDir, outDir);
    testModelSingleInt32(passed, failed, vecDir, outDir);
    testModelSingleInt64(passed, failed, vecDir, outDir);
    testModelSingleUint8(passed, failed, vecDir, outDir);
    testModelSingleUint16(passed, failed, vecDir, outDir);
    testModelSingleUint32(passed, failed, vecDir, outDir);
    testModelSingleUint64(passed, failed, vecDir, outDir);
    testModelSingleFloat32(passed, failed, vecDir, outDir);
    testModelSingleFloat64(passed, failed, vecDir, outDir);
    testModelSingleBytes(passed, failed, vecDir, outDir);

}
