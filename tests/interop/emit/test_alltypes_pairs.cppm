module;
#include <cstdlib>
#include <fstream>
#include <filesystem>
export module test_alltypes_pairs;
import std;
import specodec;
import all_types_arrays;
import all_types_edge;
import all_types_enums;
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
using namespace all_types_enums;
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


void testModelPairString(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/PairString.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = PairStringCodec.decode(r);
        specodec::MsgPackWriter w;
        PairStringCodec.encode(w, obj);
        writeFile(outDir + "/PairString.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL PairString mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL PairString mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/PairString.json");
        specodec::JsonReader r(data);
        auto obj = PairStringCodec.decode(r);
        specodec::JsonWriter w;
        PairStringCodec.encode(w, obj);
        writeFile(outDir + "/PairString.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL PairString json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL PairString json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/PairString.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = PairStringCodec.decode(r);
        specodec::JsonWriter w;
        PairStringCodec.encode(w, obj);
        writeFile(outDir + "/PairString.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL PairString unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL PairString unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/PairString.gron");
        specodec::GronReader r(data);
        auto obj = PairStringCodec.decode(r);
        specodec::GronWriter w;
        PairStringCodec.encode(w, obj);
        writeFile(outDir + "/PairString.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL PairString gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL PairString gron" << std::endl; }
}

void testModelPairBoolean(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/PairBoolean.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = PairBooleanCodec.decode(r);
        specodec::MsgPackWriter w;
        PairBooleanCodec.encode(w, obj);
        writeFile(outDir + "/PairBoolean.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL PairBoolean mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL PairBoolean mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/PairBoolean.json");
        specodec::JsonReader r(data);
        auto obj = PairBooleanCodec.decode(r);
        specodec::JsonWriter w;
        PairBooleanCodec.encode(w, obj);
        writeFile(outDir + "/PairBoolean.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL PairBoolean json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL PairBoolean json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/PairBoolean.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = PairBooleanCodec.decode(r);
        specodec::JsonWriter w;
        PairBooleanCodec.encode(w, obj);
        writeFile(outDir + "/PairBoolean.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL PairBoolean unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL PairBoolean unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/PairBoolean.gron");
        specodec::GronReader r(data);
        auto obj = PairBooleanCodec.decode(r);
        specodec::GronWriter w;
        PairBooleanCodec.encode(w, obj);
        writeFile(outDir + "/PairBoolean.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL PairBoolean gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL PairBoolean gron" << std::endl; }
}

void testModelPairInt8(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/PairInt8.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = PairInt8Codec.decode(r);
        specodec::MsgPackWriter w;
        PairInt8Codec.encode(w, obj);
        writeFile(outDir + "/PairInt8.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL PairInt8 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL PairInt8 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/PairInt8.json");
        specodec::JsonReader r(data);
        auto obj = PairInt8Codec.decode(r);
        specodec::JsonWriter w;
        PairInt8Codec.encode(w, obj);
        writeFile(outDir + "/PairInt8.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL PairInt8 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL PairInt8 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/PairInt8.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = PairInt8Codec.decode(r);
        specodec::JsonWriter w;
        PairInt8Codec.encode(w, obj);
        writeFile(outDir + "/PairInt8.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL PairInt8 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL PairInt8 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/PairInt8.gron");
        specodec::GronReader r(data);
        auto obj = PairInt8Codec.decode(r);
        specodec::GronWriter w;
        PairInt8Codec.encode(w, obj);
        writeFile(outDir + "/PairInt8.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL PairInt8 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL PairInt8 gron" << std::endl; }
}

void testModelPairInt16(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/PairInt16.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = PairInt16Codec.decode(r);
        specodec::MsgPackWriter w;
        PairInt16Codec.encode(w, obj);
        writeFile(outDir + "/PairInt16.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL PairInt16 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL PairInt16 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/PairInt16.json");
        specodec::JsonReader r(data);
        auto obj = PairInt16Codec.decode(r);
        specodec::JsonWriter w;
        PairInt16Codec.encode(w, obj);
        writeFile(outDir + "/PairInt16.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL PairInt16 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL PairInt16 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/PairInt16.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = PairInt16Codec.decode(r);
        specodec::JsonWriter w;
        PairInt16Codec.encode(w, obj);
        writeFile(outDir + "/PairInt16.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL PairInt16 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL PairInt16 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/PairInt16.gron");
        specodec::GronReader r(data);
        auto obj = PairInt16Codec.decode(r);
        specodec::GronWriter w;
        PairInt16Codec.encode(w, obj);
        writeFile(outDir + "/PairInt16.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL PairInt16 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL PairInt16 gron" << std::endl; }
}

void testModelPairInt32(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/PairInt32.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = PairInt32Codec.decode(r);
        specodec::MsgPackWriter w;
        PairInt32Codec.encode(w, obj);
        writeFile(outDir + "/PairInt32.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL PairInt32 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL PairInt32 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/PairInt32.json");
        specodec::JsonReader r(data);
        auto obj = PairInt32Codec.decode(r);
        specodec::JsonWriter w;
        PairInt32Codec.encode(w, obj);
        writeFile(outDir + "/PairInt32.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL PairInt32 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL PairInt32 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/PairInt32.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = PairInt32Codec.decode(r);
        specodec::JsonWriter w;
        PairInt32Codec.encode(w, obj);
        writeFile(outDir + "/PairInt32.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL PairInt32 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL PairInt32 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/PairInt32.gron");
        specodec::GronReader r(data);
        auto obj = PairInt32Codec.decode(r);
        specodec::GronWriter w;
        PairInt32Codec.encode(w, obj);
        writeFile(outDir + "/PairInt32.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL PairInt32 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL PairInt32 gron" << std::endl; }
}

void testModelPairInt64(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/PairInt64.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = PairInt64Codec.decode(r);
        specodec::MsgPackWriter w;
        PairInt64Codec.encode(w, obj);
        writeFile(outDir + "/PairInt64.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL PairInt64 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL PairInt64 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/PairInt64.json");
        specodec::JsonReader r(data);
        auto obj = PairInt64Codec.decode(r);
        specodec::JsonWriter w;
        PairInt64Codec.encode(w, obj);
        writeFile(outDir + "/PairInt64.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL PairInt64 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL PairInt64 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/PairInt64.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = PairInt64Codec.decode(r);
        specodec::JsonWriter w;
        PairInt64Codec.encode(w, obj);
        writeFile(outDir + "/PairInt64.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL PairInt64 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL PairInt64 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/PairInt64.gron");
        specodec::GronReader r(data);
        auto obj = PairInt64Codec.decode(r);
        specodec::GronWriter w;
        PairInt64Codec.encode(w, obj);
        writeFile(outDir + "/PairInt64.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL PairInt64 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL PairInt64 gron" << std::endl; }
}

void testModelPairUint8(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/PairUint8.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = PairUint8Codec.decode(r);
        specodec::MsgPackWriter w;
        PairUint8Codec.encode(w, obj);
        writeFile(outDir + "/PairUint8.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL PairUint8 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL PairUint8 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/PairUint8.json");
        specodec::JsonReader r(data);
        auto obj = PairUint8Codec.decode(r);
        specodec::JsonWriter w;
        PairUint8Codec.encode(w, obj);
        writeFile(outDir + "/PairUint8.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL PairUint8 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL PairUint8 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/PairUint8.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = PairUint8Codec.decode(r);
        specodec::JsonWriter w;
        PairUint8Codec.encode(w, obj);
        writeFile(outDir + "/PairUint8.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL PairUint8 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL PairUint8 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/PairUint8.gron");
        specodec::GronReader r(data);
        auto obj = PairUint8Codec.decode(r);
        specodec::GronWriter w;
        PairUint8Codec.encode(w, obj);
        writeFile(outDir + "/PairUint8.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL PairUint8 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL PairUint8 gron" << std::endl; }
}

void testModelPairUint16(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/PairUint16.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = PairUint16Codec.decode(r);
        specodec::MsgPackWriter w;
        PairUint16Codec.encode(w, obj);
        writeFile(outDir + "/PairUint16.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL PairUint16 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL PairUint16 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/PairUint16.json");
        specodec::JsonReader r(data);
        auto obj = PairUint16Codec.decode(r);
        specodec::JsonWriter w;
        PairUint16Codec.encode(w, obj);
        writeFile(outDir + "/PairUint16.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL PairUint16 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL PairUint16 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/PairUint16.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = PairUint16Codec.decode(r);
        specodec::JsonWriter w;
        PairUint16Codec.encode(w, obj);
        writeFile(outDir + "/PairUint16.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL PairUint16 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL PairUint16 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/PairUint16.gron");
        specodec::GronReader r(data);
        auto obj = PairUint16Codec.decode(r);
        specodec::GronWriter w;
        PairUint16Codec.encode(w, obj);
        writeFile(outDir + "/PairUint16.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL PairUint16 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL PairUint16 gron" << std::endl; }
}

void testModelPairUint32(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/PairUint32.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = PairUint32Codec.decode(r);
        specodec::MsgPackWriter w;
        PairUint32Codec.encode(w, obj);
        writeFile(outDir + "/PairUint32.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL PairUint32 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL PairUint32 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/PairUint32.json");
        specodec::JsonReader r(data);
        auto obj = PairUint32Codec.decode(r);
        specodec::JsonWriter w;
        PairUint32Codec.encode(w, obj);
        writeFile(outDir + "/PairUint32.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL PairUint32 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL PairUint32 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/PairUint32.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = PairUint32Codec.decode(r);
        specodec::JsonWriter w;
        PairUint32Codec.encode(w, obj);
        writeFile(outDir + "/PairUint32.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL PairUint32 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL PairUint32 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/PairUint32.gron");
        specodec::GronReader r(data);
        auto obj = PairUint32Codec.decode(r);
        specodec::GronWriter w;
        PairUint32Codec.encode(w, obj);
        writeFile(outDir + "/PairUint32.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL PairUint32 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL PairUint32 gron" << std::endl; }
}

void testModelPairUint64(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/PairUint64.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = PairUint64Codec.decode(r);
        specodec::MsgPackWriter w;
        PairUint64Codec.encode(w, obj);
        writeFile(outDir + "/PairUint64.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL PairUint64 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL PairUint64 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/PairUint64.json");
        specodec::JsonReader r(data);
        auto obj = PairUint64Codec.decode(r);
        specodec::JsonWriter w;
        PairUint64Codec.encode(w, obj);
        writeFile(outDir + "/PairUint64.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL PairUint64 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL PairUint64 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/PairUint64.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = PairUint64Codec.decode(r);
        specodec::JsonWriter w;
        PairUint64Codec.encode(w, obj);
        writeFile(outDir + "/PairUint64.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL PairUint64 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL PairUint64 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/PairUint64.gron");
        specodec::GronReader r(data);
        auto obj = PairUint64Codec.decode(r);
        specodec::GronWriter w;
        PairUint64Codec.encode(w, obj);
        writeFile(outDir + "/PairUint64.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL PairUint64 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL PairUint64 gron" << std::endl; }
}

void testModelPairFloat32(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/PairFloat32.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = PairFloat32Codec.decode(r);
        specodec::MsgPackWriter w;
        PairFloat32Codec.encode(w, obj);
        writeFile(outDir + "/PairFloat32.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL PairFloat32 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL PairFloat32 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/PairFloat32.json");
        specodec::JsonReader r(data);
        auto obj = PairFloat32Codec.decode(r);
        specodec::JsonWriter w;
        PairFloat32Codec.encode(w, obj);
        writeFile(outDir + "/PairFloat32.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL PairFloat32 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL PairFloat32 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/PairFloat32.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = PairFloat32Codec.decode(r);
        specodec::JsonWriter w;
        PairFloat32Codec.encode(w, obj);
        writeFile(outDir + "/PairFloat32.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL PairFloat32 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL PairFloat32 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/PairFloat32.gron");
        specodec::GronReader r(data);
        auto obj = PairFloat32Codec.decode(r);
        specodec::GronWriter w;
        PairFloat32Codec.encode(w, obj);
        writeFile(outDir + "/PairFloat32.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL PairFloat32 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL PairFloat32 gron" << std::endl; }
}

void testModelPairFloat64(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/PairFloat64.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = PairFloat64Codec.decode(r);
        specodec::MsgPackWriter w;
        PairFloat64Codec.encode(w, obj);
        writeFile(outDir + "/PairFloat64.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL PairFloat64 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL PairFloat64 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/PairFloat64.json");
        specodec::JsonReader r(data);
        auto obj = PairFloat64Codec.decode(r);
        specodec::JsonWriter w;
        PairFloat64Codec.encode(w, obj);
        writeFile(outDir + "/PairFloat64.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL PairFloat64 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL PairFloat64 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/PairFloat64.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = PairFloat64Codec.decode(r);
        specodec::JsonWriter w;
        PairFloat64Codec.encode(w, obj);
        writeFile(outDir + "/PairFloat64.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL PairFloat64 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL PairFloat64 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/PairFloat64.gron");
        specodec::GronReader r(data);
        auto obj = PairFloat64Codec.decode(r);
        specodec::GronWriter w;
        PairFloat64Codec.encode(w, obj);
        writeFile(outDir + "/PairFloat64.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL PairFloat64 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL PairFloat64 gron" << std::endl; }
}

void testModelPairBytes(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/PairBytes.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = PairBytesCodec.decode(r);
        specodec::MsgPackWriter w;
        PairBytesCodec.encode(w, obj);
        writeFile(outDir + "/PairBytes.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL PairBytes mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL PairBytes mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/PairBytes.json");
        specodec::JsonReader r(data);
        auto obj = PairBytesCodec.decode(r);
        specodec::JsonWriter w;
        PairBytesCodec.encode(w, obj);
        writeFile(outDir + "/PairBytes.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL PairBytes json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL PairBytes json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/PairBytes.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = PairBytesCodec.decode(r);
        specodec::JsonWriter w;
        PairBytesCodec.encode(w, obj);
        writeFile(outDir + "/PairBytes.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL PairBytes unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL PairBytes unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/PairBytes.gron");
        specodec::GronReader r(data);
        auto obj = PairBytesCodec.decode(r);
        specodec::GronWriter w;
        PairBytesCodec.encode(w, obj);
        writeFile(outDir + "/PairBytes.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL PairBytes gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL PairBytes gron" << std::endl; }
}

void testModelDualStringInt32(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/DualStringInt32.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = DualStringInt32Codec.decode(r);
        specodec::MsgPackWriter w;
        DualStringInt32Codec.encode(w, obj);
        writeFile(outDir + "/DualStringInt32.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualStringInt32 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualStringInt32 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/DualStringInt32.json");
        specodec::JsonReader r(data);
        auto obj = DualStringInt32Codec.decode(r);
        specodec::JsonWriter w;
        DualStringInt32Codec.encode(w, obj);
        writeFile(outDir + "/DualStringInt32.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualStringInt32 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualStringInt32 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/DualStringInt32.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = DualStringInt32Codec.decode(r);
        specodec::JsonWriter w;
        DualStringInt32Codec.encode(w, obj);
        writeFile(outDir + "/DualStringInt32.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualStringInt32 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualStringInt32 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/DualStringInt32.gron");
        specodec::GronReader r(data);
        auto obj = DualStringInt32Codec.decode(r);
        specodec::GronWriter w;
        DualStringInt32Codec.encode(w, obj);
        writeFile(outDir + "/DualStringInt32.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualStringInt32 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualStringInt32 gron" << std::endl; }
}

void testModelDualStringBoolean(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/DualStringBoolean.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = DualStringBooleanCodec.decode(r);
        specodec::MsgPackWriter w;
        DualStringBooleanCodec.encode(w, obj);
        writeFile(outDir + "/DualStringBoolean.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualStringBoolean mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualStringBoolean mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/DualStringBoolean.json");
        specodec::JsonReader r(data);
        auto obj = DualStringBooleanCodec.decode(r);
        specodec::JsonWriter w;
        DualStringBooleanCodec.encode(w, obj);
        writeFile(outDir + "/DualStringBoolean.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualStringBoolean json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualStringBoolean json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/DualStringBoolean.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = DualStringBooleanCodec.decode(r);
        specodec::JsonWriter w;
        DualStringBooleanCodec.encode(w, obj);
        writeFile(outDir + "/DualStringBoolean.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualStringBoolean unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualStringBoolean unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/DualStringBoolean.gron");
        specodec::GronReader r(data);
        auto obj = DualStringBooleanCodec.decode(r);
        specodec::GronWriter w;
        DualStringBooleanCodec.encode(w, obj);
        writeFile(outDir + "/DualStringBoolean.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualStringBoolean gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualStringBoolean gron" << std::endl; }
}

void testModelDualStringFloat64(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/DualStringFloat64.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = DualStringFloat64Codec.decode(r);
        specodec::MsgPackWriter w;
        DualStringFloat64Codec.encode(w, obj);
        writeFile(outDir + "/DualStringFloat64.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualStringFloat64 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualStringFloat64 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/DualStringFloat64.json");
        specodec::JsonReader r(data);
        auto obj = DualStringFloat64Codec.decode(r);
        specodec::JsonWriter w;
        DualStringFloat64Codec.encode(w, obj);
        writeFile(outDir + "/DualStringFloat64.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualStringFloat64 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualStringFloat64 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/DualStringFloat64.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = DualStringFloat64Codec.decode(r);
        specodec::JsonWriter w;
        DualStringFloat64Codec.encode(w, obj);
        writeFile(outDir + "/DualStringFloat64.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualStringFloat64 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualStringFloat64 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/DualStringFloat64.gron");
        specodec::GronReader r(data);
        auto obj = DualStringFloat64Codec.decode(r);
        specodec::GronWriter w;
        DualStringFloat64Codec.encode(w, obj);
        writeFile(outDir + "/DualStringFloat64.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualStringFloat64 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualStringFloat64 gron" << std::endl; }
}

void testModelDualStringBytes(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/DualStringBytes.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = DualStringBytesCodec.decode(r);
        specodec::MsgPackWriter w;
        DualStringBytesCodec.encode(w, obj);
        writeFile(outDir + "/DualStringBytes.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualStringBytes mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualStringBytes mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/DualStringBytes.json");
        specodec::JsonReader r(data);
        auto obj = DualStringBytesCodec.decode(r);
        specodec::JsonWriter w;
        DualStringBytesCodec.encode(w, obj);
        writeFile(outDir + "/DualStringBytes.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualStringBytes json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualStringBytes json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/DualStringBytes.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = DualStringBytesCodec.decode(r);
        specodec::JsonWriter w;
        DualStringBytesCodec.encode(w, obj);
        writeFile(outDir + "/DualStringBytes.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualStringBytes unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualStringBytes unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/DualStringBytes.gron");
        specodec::GronReader r(data);
        auto obj = DualStringBytesCodec.decode(r);
        specodec::GronWriter w;
        DualStringBytesCodec.encode(w, obj);
        writeFile(outDir + "/DualStringBytes.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualStringBytes gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualStringBytes gron" << std::endl; }
}

void testModelDualInt32Boolean(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/DualInt32Boolean.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = DualInt32BooleanCodec.decode(r);
        specodec::MsgPackWriter w;
        DualInt32BooleanCodec.encode(w, obj);
        writeFile(outDir + "/DualInt32Boolean.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualInt32Boolean mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualInt32Boolean mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/DualInt32Boolean.json");
        specodec::JsonReader r(data);
        auto obj = DualInt32BooleanCodec.decode(r);
        specodec::JsonWriter w;
        DualInt32BooleanCodec.encode(w, obj);
        writeFile(outDir + "/DualInt32Boolean.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualInt32Boolean json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualInt32Boolean json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/DualInt32Boolean.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = DualInt32BooleanCodec.decode(r);
        specodec::JsonWriter w;
        DualInt32BooleanCodec.encode(w, obj);
        writeFile(outDir + "/DualInt32Boolean.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualInt32Boolean unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualInt32Boolean unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/DualInt32Boolean.gron");
        specodec::GronReader r(data);
        auto obj = DualInt32BooleanCodec.decode(r);
        specodec::GronWriter w;
        DualInt32BooleanCodec.encode(w, obj);
        writeFile(outDir + "/DualInt32Boolean.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualInt32Boolean gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualInt32Boolean gron" << std::endl; }
}

void testModelDualInt32Float64(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/DualInt32Float64.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = DualInt32Float64Codec.decode(r);
        specodec::MsgPackWriter w;
        DualInt32Float64Codec.encode(w, obj);
        writeFile(outDir + "/DualInt32Float64.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualInt32Float64 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualInt32Float64 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/DualInt32Float64.json");
        specodec::JsonReader r(data);
        auto obj = DualInt32Float64Codec.decode(r);
        specodec::JsonWriter w;
        DualInt32Float64Codec.encode(w, obj);
        writeFile(outDir + "/DualInt32Float64.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualInt32Float64 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualInt32Float64 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/DualInt32Float64.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = DualInt32Float64Codec.decode(r);
        specodec::JsonWriter w;
        DualInt32Float64Codec.encode(w, obj);
        writeFile(outDir + "/DualInt32Float64.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualInt32Float64 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualInt32Float64 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/DualInt32Float64.gron");
        specodec::GronReader r(data);
        auto obj = DualInt32Float64Codec.decode(r);
        specodec::GronWriter w;
        DualInt32Float64Codec.encode(w, obj);
        writeFile(outDir + "/DualInt32Float64.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualInt32Float64 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualInt32Float64 gron" << std::endl; }
}

void testModelDualInt32Int64(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/DualInt32Int64.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = DualInt32Int64Codec.decode(r);
        specodec::MsgPackWriter w;
        DualInt32Int64Codec.encode(w, obj);
        writeFile(outDir + "/DualInt32Int64.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualInt32Int64 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualInt32Int64 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/DualInt32Int64.json");
        specodec::JsonReader r(data);
        auto obj = DualInt32Int64Codec.decode(r);
        specodec::JsonWriter w;
        DualInt32Int64Codec.encode(w, obj);
        writeFile(outDir + "/DualInt32Int64.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualInt32Int64 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualInt32Int64 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/DualInt32Int64.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = DualInt32Int64Codec.decode(r);
        specodec::JsonWriter w;
        DualInt32Int64Codec.encode(w, obj);
        writeFile(outDir + "/DualInt32Int64.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualInt32Int64 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualInt32Int64 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/DualInt32Int64.gron");
        specodec::GronReader r(data);
        auto obj = DualInt32Int64Codec.decode(r);
        specodec::GronWriter w;
        DualInt32Int64Codec.encode(w, obj);
        writeFile(outDir + "/DualInt32Int64.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualInt32Int64 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualInt32Int64 gron" << std::endl; }
}

void testModelDualInt32Uint32(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/DualInt32Uint32.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = DualInt32Uint32Codec.decode(r);
        specodec::MsgPackWriter w;
        DualInt32Uint32Codec.encode(w, obj);
        writeFile(outDir + "/DualInt32Uint32.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualInt32Uint32 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualInt32Uint32 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/DualInt32Uint32.json");
        specodec::JsonReader r(data);
        auto obj = DualInt32Uint32Codec.decode(r);
        specodec::JsonWriter w;
        DualInt32Uint32Codec.encode(w, obj);
        writeFile(outDir + "/DualInt32Uint32.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualInt32Uint32 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualInt32Uint32 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/DualInt32Uint32.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = DualInt32Uint32Codec.decode(r);
        specodec::JsonWriter w;
        DualInt32Uint32Codec.encode(w, obj);
        writeFile(outDir + "/DualInt32Uint32.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualInt32Uint32 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualInt32Uint32 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/DualInt32Uint32.gron");
        specodec::GronReader r(data);
        auto obj = DualInt32Uint32Codec.decode(r);
        specodec::GronWriter w;
        DualInt32Uint32Codec.encode(w, obj);
        writeFile(outDir + "/DualInt32Uint32.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualInt32Uint32 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualInt32Uint32 gron" << std::endl; }
}

void testModelDualInt64Uint64(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/DualInt64Uint64.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = DualInt64Uint64Codec.decode(r);
        specodec::MsgPackWriter w;
        DualInt64Uint64Codec.encode(w, obj);
        writeFile(outDir + "/DualInt64Uint64.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualInt64Uint64 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualInt64Uint64 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/DualInt64Uint64.json");
        specodec::JsonReader r(data);
        auto obj = DualInt64Uint64Codec.decode(r);
        specodec::JsonWriter w;
        DualInt64Uint64Codec.encode(w, obj);
        writeFile(outDir + "/DualInt64Uint64.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualInt64Uint64 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualInt64Uint64 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/DualInt64Uint64.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = DualInt64Uint64Codec.decode(r);
        specodec::JsonWriter w;
        DualInt64Uint64Codec.encode(w, obj);
        writeFile(outDir + "/DualInt64Uint64.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualInt64Uint64 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualInt64Uint64 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/DualInt64Uint64.gron");
        specodec::GronReader r(data);
        auto obj = DualInt64Uint64Codec.decode(r);
        specodec::GronWriter w;
        DualInt64Uint64Codec.encode(w, obj);
        writeFile(outDir + "/DualInt64Uint64.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualInt64Uint64 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualInt64Uint64 gron" << std::endl; }
}

void testModelDualFloat32Float64(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/DualFloat32Float64.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = DualFloat32Float64Codec.decode(r);
        specodec::MsgPackWriter w;
        DualFloat32Float64Codec.encode(w, obj);
        writeFile(outDir + "/DualFloat32Float64.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualFloat32Float64 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualFloat32Float64 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/DualFloat32Float64.json");
        specodec::JsonReader r(data);
        auto obj = DualFloat32Float64Codec.decode(r);
        specodec::JsonWriter w;
        DualFloat32Float64Codec.encode(w, obj);
        writeFile(outDir + "/DualFloat32Float64.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualFloat32Float64 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualFloat32Float64 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/DualFloat32Float64.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = DualFloat32Float64Codec.decode(r);
        specodec::JsonWriter w;
        DualFloat32Float64Codec.encode(w, obj);
        writeFile(outDir + "/DualFloat32Float64.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualFloat32Float64 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualFloat32Float64 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/DualFloat32Float64.gron");
        specodec::GronReader r(data);
        auto obj = DualFloat32Float64Codec.decode(r);
        specodec::GronWriter w;
        DualFloat32Float64Codec.encode(w, obj);
        writeFile(outDir + "/DualFloat32Float64.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualFloat32Float64 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualFloat32Float64 gron" << std::endl; }
}

void testModelDualFloat64Boolean(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/DualFloat64Boolean.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = DualFloat64BooleanCodec.decode(r);
        specodec::MsgPackWriter w;
        DualFloat64BooleanCodec.encode(w, obj);
        writeFile(outDir + "/DualFloat64Boolean.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualFloat64Boolean mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualFloat64Boolean mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/DualFloat64Boolean.json");
        specodec::JsonReader r(data);
        auto obj = DualFloat64BooleanCodec.decode(r);
        specodec::JsonWriter w;
        DualFloat64BooleanCodec.encode(w, obj);
        writeFile(outDir + "/DualFloat64Boolean.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualFloat64Boolean json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualFloat64Boolean json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/DualFloat64Boolean.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = DualFloat64BooleanCodec.decode(r);
        specodec::JsonWriter w;
        DualFloat64BooleanCodec.encode(w, obj);
        writeFile(outDir + "/DualFloat64Boolean.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualFloat64Boolean unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualFloat64Boolean unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/DualFloat64Boolean.gron");
        specodec::GronReader r(data);
        auto obj = DualFloat64BooleanCodec.decode(r);
        specodec::GronWriter w;
        DualFloat64BooleanCodec.encode(w, obj);
        writeFile(outDir + "/DualFloat64Boolean.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualFloat64Boolean gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualFloat64Boolean gron" << std::endl; }
}

void testModelDualFloat64Bytes(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/DualFloat64Bytes.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = DualFloat64BytesCodec.decode(r);
        specodec::MsgPackWriter w;
        DualFloat64BytesCodec.encode(w, obj);
        writeFile(outDir + "/DualFloat64Bytes.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualFloat64Bytes mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualFloat64Bytes mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/DualFloat64Bytes.json");
        specodec::JsonReader r(data);
        auto obj = DualFloat64BytesCodec.decode(r);
        specodec::JsonWriter w;
        DualFloat64BytesCodec.encode(w, obj);
        writeFile(outDir + "/DualFloat64Bytes.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualFloat64Bytes json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualFloat64Bytes json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/DualFloat64Bytes.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = DualFloat64BytesCodec.decode(r);
        specodec::JsonWriter w;
        DualFloat64BytesCodec.encode(w, obj);
        writeFile(outDir + "/DualFloat64Bytes.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualFloat64Bytes unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualFloat64Bytes unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/DualFloat64Bytes.gron");
        specodec::GronReader r(data);
        auto obj = DualFloat64BytesCodec.decode(r);
        specodec::GronWriter w;
        DualFloat64BytesCodec.encode(w, obj);
        writeFile(outDir + "/DualFloat64Bytes.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualFloat64Bytes gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualFloat64Bytes gron" << std::endl; }
}

void testModelDualUint32Uint64(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/DualUint32Uint64.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = DualUint32Uint64Codec.decode(r);
        specodec::MsgPackWriter w;
        DualUint32Uint64Codec.encode(w, obj);
        writeFile(outDir + "/DualUint32Uint64.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualUint32Uint64 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualUint32Uint64 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/DualUint32Uint64.json");
        specodec::JsonReader r(data);
        auto obj = DualUint32Uint64Codec.decode(r);
        specodec::JsonWriter w;
        DualUint32Uint64Codec.encode(w, obj);
        writeFile(outDir + "/DualUint32Uint64.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualUint32Uint64 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualUint32Uint64 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/DualUint32Uint64.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = DualUint32Uint64Codec.decode(r);
        specodec::JsonWriter w;
        DualUint32Uint64Codec.encode(w, obj);
        writeFile(outDir + "/DualUint32Uint64.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualUint32Uint64 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualUint32Uint64 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/DualUint32Uint64.gron");
        specodec::GronReader r(data);
        auto obj = DualUint32Uint64Codec.decode(r);
        specodec::GronWriter w;
        DualUint32Uint64Codec.encode(w, obj);
        writeFile(outDir + "/DualUint32Uint64.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualUint32Uint64 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualUint32Uint64 gron" << std::endl; }
}

void testModelDualBooleanBytes(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/DualBooleanBytes.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = DualBooleanBytesCodec.decode(r);
        specodec::MsgPackWriter w;
        DualBooleanBytesCodec.encode(w, obj);
        writeFile(outDir + "/DualBooleanBytes.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualBooleanBytes mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualBooleanBytes mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/DualBooleanBytes.json");
        specodec::JsonReader r(data);
        auto obj = DualBooleanBytesCodec.decode(r);
        specodec::JsonWriter w;
        DualBooleanBytesCodec.encode(w, obj);
        writeFile(outDir + "/DualBooleanBytes.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualBooleanBytes json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualBooleanBytes json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/DualBooleanBytes.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = DualBooleanBytesCodec.decode(r);
        specodec::JsonWriter w;
        DualBooleanBytesCodec.encode(w, obj);
        writeFile(outDir + "/DualBooleanBytes.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualBooleanBytes unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualBooleanBytes unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/DualBooleanBytes.gron");
        specodec::GronReader r(data);
        auto obj = DualBooleanBytesCodec.decode(r);
        specodec::GronWriter w;
        DualBooleanBytesCodec.encode(w, obj);
        writeFile(outDir + "/DualBooleanBytes.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualBooleanBytes gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualBooleanBytes gron" << std::endl; }
}

void testModelDualInt8Uint8(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/DualInt8Uint8.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = DualInt8Uint8Codec.decode(r);
        specodec::MsgPackWriter w;
        DualInt8Uint8Codec.encode(w, obj);
        writeFile(outDir + "/DualInt8Uint8.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualInt8Uint8 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualInt8Uint8 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/DualInt8Uint8.json");
        specodec::JsonReader r(data);
        auto obj = DualInt8Uint8Codec.decode(r);
        specodec::JsonWriter w;
        DualInt8Uint8Codec.encode(w, obj);
        writeFile(outDir + "/DualInt8Uint8.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualInt8Uint8 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualInt8Uint8 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/DualInt8Uint8.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = DualInt8Uint8Codec.decode(r);
        specodec::JsonWriter w;
        DualInt8Uint8Codec.encode(w, obj);
        writeFile(outDir + "/DualInt8Uint8.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualInt8Uint8 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualInt8Uint8 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/DualInt8Uint8.gron");
        specodec::GronReader r(data);
        auto obj = DualInt8Uint8Codec.decode(r);
        specodec::GronWriter w;
        DualInt8Uint8Codec.encode(w, obj);
        writeFile(outDir + "/DualInt8Uint8.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualInt8Uint8 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualInt8Uint8 gron" << std::endl; }
}

void testModelDualInt16Uint16(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/DualInt16Uint16.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = DualInt16Uint16Codec.decode(r);
        specodec::MsgPackWriter w;
        DualInt16Uint16Codec.encode(w, obj);
        writeFile(outDir + "/DualInt16Uint16.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualInt16Uint16 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualInt16Uint16 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/DualInt16Uint16.json");
        specodec::JsonReader r(data);
        auto obj = DualInt16Uint16Codec.decode(r);
        specodec::JsonWriter w;
        DualInt16Uint16Codec.encode(w, obj);
        writeFile(outDir + "/DualInt16Uint16.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualInt16Uint16 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualInt16Uint16 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/DualInt16Uint16.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = DualInt16Uint16Codec.decode(r);
        specodec::JsonWriter w;
        DualInt16Uint16Codec.encode(w, obj);
        writeFile(outDir + "/DualInt16Uint16.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualInt16Uint16 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualInt16Uint16 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/DualInt16Uint16.gron");
        specodec::GronReader r(data);
        auto obj = DualInt16Uint16Codec.decode(r);
        specodec::GronWriter w;
        DualInt16Uint16Codec.encode(w, obj);
        writeFile(outDir + "/DualInt16Uint16.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualInt16Uint16 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualInt16Uint16 gron" << std::endl; }
}

void testModelDualStringInt64(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/DualStringInt64.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = DualStringInt64Codec.decode(r);
        specodec::MsgPackWriter w;
        DualStringInt64Codec.encode(w, obj);
        writeFile(outDir + "/DualStringInt64.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualStringInt64 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualStringInt64 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/DualStringInt64.json");
        specodec::JsonReader r(data);
        auto obj = DualStringInt64Codec.decode(r);
        specodec::JsonWriter w;
        DualStringInt64Codec.encode(w, obj);
        writeFile(outDir + "/DualStringInt64.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualStringInt64 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualStringInt64 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/DualStringInt64.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = DualStringInt64Codec.decode(r);
        specodec::JsonWriter w;
        DualStringInt64Codec.encode(w, obj);
        writeFile(outDir + "/DualStringInt64.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualStringInt64 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualStringInt64 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/DualStringInt64.gron");
        specodec::GronReader r(data);
        auto obj = DualStringInt64Codec.decode(r);
        specodec::GronWriter w;
        DualStringInt64Codec.encode(w, obj);
        writeFile(outDir + "/DualStringInt64.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualStringInt64 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualStringInt64 gron" << std::endl; }
}

void testModelDualStringUint64(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/DualStringUint64.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = DualStringUint64Codec.decode(r);
        specodec::MsgPackWriter w;
        DualStringUint64Codec.encode(w, obj);
        writeFile(outDir + "/DualStringUint64.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualStringUint64 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualStringUint64 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/DualStringUint64.json");
        specodec::JsonReader r(data);
        auto obj = DualStringUint64Codec.decode(r);
        specodec::JsonWriter w;
        DualStringUint64Codec.encode(w, obj);
        writeFile(outDir + "/DualStringUint64.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualStringUint64 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualStringUint64 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/DualStringUint64.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = DualStringUint64Codec.decode(r);
        specodec::JsonWriter w;
        DualStringUint64Codec.encode(w, obj);
        writeFile(outDir + "/DualStringUint64.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualStringUint64 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualStringUint64 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/DualStringUint64.gron");
        specodec::GronReader r(data);
        auto obj = DualStringUint64Codec.decode(r);
        specodec::GronWriter w;
        DualStringUint64Codec.encode(w, obj);
        writeFile(outDir + "/DualStringUint64.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualStringUint64 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualStringUint64 gron" << std::endl; }
}

void testModelDualInt32Bytes(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/DualInt32Bytes.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = DualInt32BytesCodec.decode(r);
        specodec::MsgPackWriter w;
        DualInt32BytesCodec.encode(w, obj);
        writeFile(outDir + "/DualInt32Bytes.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualInt32Bytes mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualInt32Bytes mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/DualInt32Bytes.json");
        specodec::JsonReader r(data);
        auto obj = DualInt32BytesCodec.decode(r);
        specodec::JsonWriter w;
        DualInt32BytesCodec.encode(w, obj);
        writeFile(outDir + "/DualInt32Bytes.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualInt32Bytes json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualInt32Bytes json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/DualInt32Bytes.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = DualInt32BytesCodec.decode(r);
        specodec::JsonWriter w;
        DualInt32BytesCodec.encode(w, obj);
        writeFile(outDir + "/DualInt32Bytes.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualInt32Bytes unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualInt32Bytes unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/DualInt32Bytes.gron");
        specodec::GronReader r(data);
        auto obj = DualInt32BytesCodec.decode(r);
        specodec::GronWriter w;
        DualInt32BytesCodec.encode(w, obj);
        writeFile(outDir + "/DualInt32Bytes.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualInt32Bytes gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualInt32Bytes gron" << std::endl; }
}

void testModelDualFloat64Int32(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/DualFloat64Int32.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = DualFloat64Int32Codec.decode(r);
        specodec::MsgPackWriter w;
        DualFloat64Int32Codec.encode(w, obj);
        writeFile(outDir + "/DualFloat64Int32.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualFloat64Int32 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualFloat64Int32 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/DualFloat64Int32.json");
        specodec::JsonReader r(data);
        auto obj = DualFloat64Int32Codec.decode(r);
        specodec::JsonWriter w;
        DualFloat64Int32Codec.encode(w, obj);
        writeFile(outDir + "/DualFloat64Int32.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualFloat64Int32 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualFloat64Int32 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/DualFloat64Int32.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = DualFloat64Int32Codec.decode(r);
        specodec::JsonWriter w;
        DualFloat64Int32Codec.encode(w, obj);
        writeFile(outDir + "/DualFloat64Int32.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualFloat64Int32 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualFloat64Int32 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/DualFloat64Int32.gron");
        specodec::GronReader r(data);
        auto obj = DualFloat64Int32Codec.decode(r);
        specodec::GronWriter w;
        DualFloat64Int32Codec.encode(w, obj);
        writeFile(outDir + "/DualFloat64Int32.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualFloat64Int32 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualFloat64Int32 gron" << std::endl; }
}

void testModelDualBooleanInt32(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/DualBooleanInt32.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = DualBooleanInt32Codec.decode(r);
        specodec::MsgPackWriter w;
        DualBooleanInt32Codec.encode(w, obj);
        writeFile(outDir + "/DualBooleanInt32.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualBooleanInt32 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualBooleanInt32 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/DualBooleanInt32.json");
        specodec::JsonReader r(data);
        auto obj = DualBooleanInt32Codec.decode(r);
        specodec::JsonWriter w;
        DualBooleanInt32Codec.encode(w, obj);
        writeFile(outDir + "/DualBooleanInt32.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualBooleanInt32 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualBooleanInt32 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/DualBooleanInt32.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = DualBooleanInt32Codec.decode(r);
        specodec::JsonWriter w;
        DualBooleanInt32Codec.encode(w, obj);
        writeFile(outDir + "/DualBooleanInt32.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualBooleanInt32 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualBooleanInt32 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/DualBooleanInt32.gron");
        specodec::GronReader r(data);
        auto obj = DualBooleanInt32Codec.decode(r);
        specodec::GronWriter w;
        DualBooleanInt32Codec.encode(w, obj);
        writeFile(outDir + "/DualBooleanInt32.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualBooleanInt32 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualBooleanInt32 gron" << std::endl; }
}

void testModelDualBytesInt64(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/DualBytesInt64.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = DualBytesInt64Codec.decode(r);
        specodec::MsgPackWriter w;
        DualBytesInt64Codec.encode(w, obj);
        writeFile(outDir + "/DualBytesInt64.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualBytesInt64 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualBytesInt64 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/DualBytesInt64.json");
        specodec::JsonReader r(data);
        auto obj = DualBytesInt64Codec.decode(r);
        specodec::JsonWriter w;
        DualBytesInt64Codec.encode(w, obj);
        writeFile(outDir + "/DualBytesInt64.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualBytesInt64 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualBytesInt64 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/DualBytesInt64.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = DualBytesInt64Codec.decode(r);
        specodec::JsonWriter w;
        DualBytesInt64Codec.encode(w, obj);
        writeFile(outDir + "/DualBytesInt64.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualBytesInt64 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualBytesInt64 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/DualBytesInt64.gron");
        specodec::GronReader r(data);
        auto obj = DualBytesInt64Codec.decode(r);
        specodec::GronWriter w;
        DualBytesInt64Codec.encode(w, obj);
        writeFile(outDir + "/DualBytesInt64.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualBytesInt64 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualBytesInt64 gron" << std::endl; }
}

void testModelDualInt8Float32(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/DualInt8Float32.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = DualInt8Float32Codec.decode(r);
        specodec::MsgPackWriter w;
        DualInt8Float32Codec.encode(w, obj);
        writeFile(outDir + "/DualInt8Float32.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualInt8Float32 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualInt8Float32 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/DualInt8Float32.json");
        specodec::JsonReader r(data);
        auto obj = DualInt8Float32Codec.decode(r);
        specodec::JsonWriter w;
        DualInt8Float32Codec.encode(w, obj);
        writeFile(outDir + "/DualInt8Float32.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualInt8Float32 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualInt8Float32 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/DualInt8Float32.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = DualInt8Float32Codec.decode(r);
        specodec::JsonWriter w;
        DualInt8Float32Codec.encode(w, obj);
        writeFile(outDir + "/DualInt8Float32.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualInt8Float32 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualInt8Float32 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/DualInt8Float32.gron");
        specodec::GronReader r(data);
        auto obj = DualInt8Float32Codec.decode(r);
        specodec::GronWriter w;
        DualInt8Float32Codec.encode(w, obj);
        writeFile(outDir + "/DualInt8Float32.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualInt8Float32 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualInt8Float32 gron" << std::endl; }
}

void testModelDualUint8Int16(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/DualUint8Int16.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = DualUint8Int16Codec.decode(r);
        specodec::MsgPackWriter w;
        DualUint8Int16Codec.encode(w, obj);
        writeFile(outDir + "/DualUint8Int16.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualUint8Int16 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualUint8Int16 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/DualUint8Int16.json");
        specodec::JsonReader r(data);
        auto obj = DualUint8Int16Codec.decode(r);
        specodec::JsonWriter w;
        DualUint8Int16Codec.encode(w, obj);
        writeFile(outDir + "/DualUint8Int16.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualUint8Int16 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualUint8Int16 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/DualUint8Int16.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = DualUint8Int16Codec.decode(r);
        specodec::JsonWriter w;
        DualUint8Int16Codec.encode(w, obj);
        writeFile(outDir + "/DualUint8Int16.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualUint8Int16 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualUint8Int16 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/DualUint8Int16.gron");
        specodec::GronReader r(data);
        auto obj = DualUint8Int16Codec.decode(r);
        specodec::GronWriter w;
        DualUint8Int16Codec.encode(w, obj);
        writeFile(outDir + "/DualUint8Int16.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualUint8Int16 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualUint8Int16 gron" << std::endl; }
}

void testModelDualInt64Float64(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/DualInt64Float64.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = DualInt64Float64Codec.decode(r);
        specodec::MsgPackWriter w;
        DualInt64Float64Codec.encode(w, obj);
        writeFile(outDir + "/DualInt64Float64.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualInt64Float64 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualInt64Float64 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/DualInt64Float64.json");
        specodec::JsonReader r(data);
        auto obj = DualInt64Float64Codec.decode(r);
        specodec::JsonWriter w;
        DualInt64Float64Codec.encode(w, obj);
        writeFile(outDir + "/DualInt64Float64.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualInt64Float64 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualInt64Float64 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/DualInt64Float64.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = DualInt64Float64Codec.decode(r);
        specodec::JsonWriter w;
        DualInt64Float64Codec.encode(w, obj);
        writeFile(outDir + "/DualInt64Float64.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualInt64Float64 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualInt64Float64 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/DualInt64Float64.gron");
        specodec::GronReader r(data);
        auto obj = DualInt64Float64Codec.decode(r);
        specodec::GronWriter w;
        DualInt64Float64Codec.encode(w, obj);
        writeFile(outDir + "/DualInt64Float64.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualInt64Float64 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualInt64Float64 gron" << std::endl; }
}

void testModelDualUint64String(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/DualUint64String.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = DualUint64StringCodec.decode(r);
        specodec::MsgPackWriter w;
        DualUint64StringCodec.encode(w, obj);
        writeFile(outDir + "/DualUint64String.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualUint64String mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualUint64String mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/DualUint64String.json");
        specodec::JsonReader r(data);
        auto obj = DualUint64StringCodec.decode(r);
        specodec::JsonWriter w;
        DualUint64StringCodec.encode(w, obj);
        writeFile(outDir + "/DualUint64String.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualUint64String json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualUint64String json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/DualUint64String.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = DualUint64StringCodec.decode(r);
        specodec::JsonWriter w;
        DualUint64StringCodec.encode(w, obj);
        writeFile(outDir + "/DualUint64String.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualUint64String unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualUint64String unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/DualUint64String.gron");
        specodec::GronReader r(data);
        auto obj = DualUint64StringCodec.decode(r);
        specodec::GronWriter w;
        DualUint64StringCodec.encode(w, obj);
        writeFile(outDir + "/DualUint64String.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL DualUint64String gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL DualUint64String gron" << std::endl; }
}

void testModelTriple01(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Triple01.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Triple01Codec.decode(r);
        specodec::MsgPackWriter w;
        Triple01Codec.encode(w, obj);
        writeFile(outDir + "/Triple01.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Triple01 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Triple01 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Triple01.json");
        specodec::JsonReader r(data);
        auto obj = Triple01Codec.decode(r);
        specodec::JsonWriter w;
        Triple01Codec.encode(w, obj);
        writeFile(outDir + "/Triple01.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Triple01 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Triple01 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Triple01.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Triple01Codec.decode(r);
        specodec::JsonWriter w;
        Triple01Codec.encode(w, obj);
        writeFile(outDir + "/Triple01.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Triple01 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Triple01 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Triple01.gron");
        specodec::GronReader r(data);
        auto obj = Triple01Codec.decode(r);
        specodec::GronWriter w;
        Triple01Codec.encode(w, obj);
        writeFile(outDir + "/Triple01.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Triple01 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Triple01 gron" << std::endl; }
}

void testModelTriple02(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Triple02.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Triple02Codec.decode(r);
        specodec::MsgPackWriter w;
        Triple02Codec.encode(w, obj);
        writeFile(outDir + "/Triple02.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Triple02 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Triple02 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Triple02.json");
        specodec::JsonReader r(data);
        auto obj = Triple02Codec.decode(r);
        specodec::JsonWriter w;
        Triple02Codec.encode(w, obj);
        writeFile(outDir + "/Triple02.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Triple02 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Triple02 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Triple02.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Triple02Codec.decode(r);
        specodec::JsonWriter w;
        Triple02Codec.encode(w, obj);
        writeFile(outDir + "/Triple02.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Triple02 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Triple02 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Triple02.gron");
        specodec::GronReader r(data);
        auto obj = Triple02Codec.decode(r);
        specodec::GronWriter w;
        Triple02Codec.encode(w, obj);
        writeFile(outDir + "/Triple02.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Triple02 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Triple02 gron" << std::endl; }
}

void testModelTriple03(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Triple03.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Triple03Codec.decode(r);
        specodec::MsgPackWriter w;
        Triple03Codec.encode(w, obj);
        writeFile(outDir + "/Triple03.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Triple03 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Triple03 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Triple03.json");
        specodec::JsonReader r(data);
        auto obj = Triple03Codec.decode(r);
        specodec::JsonWriter w;
        Triple03Codec.encode(w, obj);
        writeFile(outDir + "/Triple03.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Triple03 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Triple03 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Triple03.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Triple03Codec.decode(r);
        specodec::JsonWriter w;
        Triple03Codec.encode(w, obj);
        writeFile(outDir + "/Triple03.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Triple03 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Triple03 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Triple03.gron");
        specodec::GronReader r(data);
        auto obj = Triple03Codec.decode(r);
        specodec::GronWriter w;
        Triple03Codec.encode(w, obj);
        writeFile(outDir + "/Triple03.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Triple03 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Triple03 gron" << std::endl; }
}

void testModelTriple04(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Triple04.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Triple04Codec.decode(r);
        specodec::MsgPackWriter w;
        Triple04Codec.encode(w, obj);
        writeFile(outDir + "/Triple04.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Triple04 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Triple04 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Triple04.json");
        specodec::JsonReader r(data);
        auto obj = Triple04Codec.decode(r);
        specodec::JsonWriter w;
        Triple04Codec.encode(w, obj);
        writeFile(outDir + "/Triple04.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Triple04 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Triple04 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Triple04.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Triple04Codec.decode(r);
        specodec::JsonWriter w;
        Triple04Codec.encode(w, obj);
        writeFile(outDir + "/Triple04.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Triple04 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Triple04 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Triple04.gron");
        specodec::GronReader r(data);
        auto obj = Triple04Codec.decode(r);
        specodec::GronWriter w;
        Triple04Codec.encode(w, obj);
        writeFile(outDir + "/Triple04.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Triple04 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Triple04 gron" << std::endl; }
}

void testModelTriple05(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Triple05.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Triple05Codec.decode(r);
        specodec::MsgPackWriter w;
        Triple05Codec.encode(w, obj);
        writeFile(outDir + "/Triple05.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Triple05 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Triple05 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Triple05.json");
        specodec::JsonReader r(data);
        auto obj = Triple05Codec.decode(r);
        specodec::JsonWriter w;
        Triple05Codec.encode(w, obj);
        writeFile(outDir + "/Triple05.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Triple05 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Triple05 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Triple05.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Triple05Codec.decode(r);
        specodec::JsonWriter w;
        Triple05Codec.encode(w, obj);
        writeFile(outDir + "/Triple05.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Triple05 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Triple05 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Triple05.gron");
        specodec::GronReader r(data);
        auto obj = Triple05Codec.decode(r);
        specodec::GronWriter w;
        Triple05Codec.encode(w, obj);
        writeFile(outDir + "/Triple05.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Triple05 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Triple05 gron" << std::endl; }
}

void testModelTriple06(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Triple06.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Triple06Codec.decode(r);
        specodec::MsgPackWriter w;
        Triple06Codec.encode(w, obj);
        writeFile(outDir + "/Triple06.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Triple06 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Triple06 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Triple06.json");
        specodec::JsonReader r(data);
        auto obj = Triple06Codec.decode(r);
        specodec::JsonWriter w;
        Triple06Codec.encode(w, obj);
        writeFile(outDir + "/Triple06.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Triple06 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Triple06 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Triple06.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Triple06Codec.decode(r);
        specodec::JsonWriter w;
        Triple06Codec.encode(w, obj);
        writeFile(outDir + "/Triple06.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Triple06 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Triple06 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Triple06.gron");
        specodec::GronReader r(data);
        auto obj = Triple06Codec.decode(r);
        specodec::GronWriter w;
        Triple06Codec.encode(w, obj);
        writeFile(outDir + "/Triple06.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Triple06 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Triple06 gron" << std::endl; }
}

void testModelTriple07(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Triple07.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Triple07Codec.decode(r);
        specodec::MsgPackWriter w;
        Triple07Codec.encode(w, obj);
        writeFile(outDir + "/Triple07.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Triple07 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Triple07 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Triple07.json");
        specodec::JsonReader r(data);
        auto obj = Triple07Codec.decode(r);
        specodec::JsonWriter w;
        Triple07Codec.encode(w, obj);
        writeFile(outDir + "/Triple07.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Triple07 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Triple07 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Triple07.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Triple07Codec.decode(r);
        specodec::JsonWriter w;
        Triple07Codec.encode(w, obj);
        writeFile(outDir + "/Triple07.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Triple07 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Triple07 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Triple07.gron");
        specodec::GronReader r(data);
        auto obj = Triple07Codec.decode(r);
        specodec::GronWriter w;
        Triple07Codec.encode(w, obj);
        writeFile(outDir + "/Triple07.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Triple07 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Triple07 gron" << std::endl; }
}

void testModelTriple08(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Triple08.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Triple08Codec.decode(r);
        specodec::MsgPackWriter w;
        Triple08Codec.encode(w, obj);
        writeFile(outDir + "/Triple08.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Triple08 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Triple08 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Triple08.json");
        specodec::JsonReader r(data);
        auto obj = Triple08Codec.decode(r);
        specodec::JsonWriter w;
        Triple08Codec.encode(w, obj);
        writeFile(outDir + "/Triple08.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Triple08 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Triple08 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Triple08.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Triple08Codec.decode(r);
        specodec::JsonWriter w;
        Triple08Codec.encode(w, obj);
        writeFile(outDir + "/Triple08.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Triple08 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Triple08 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Triple08.gron");
        specodec::GronReader r(data);
        auto obj = Triple08Codec.decode(r);
        specodec::GronWriter w;
        Triple08Codec.encode(w, obj);
        writeFile(outDir + "/Triple08.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Triple08 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Triple08 gron" << std::endl; }
}

void testModelTriple09(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Triple09.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Triple09Codec.decode(r);
        specodec::MsgPackWriter w;
        Triple09Codec.encode(w, obj);
        writeFile(outDir + "/Triple09.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Triple09 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Triple09 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Triple09.json");
        specodec::JsonReader r(data);
        auto obj = Triple09Codec.decode(r);
        specodec::JsonWriter w;
        Triple09Codec.encode(w, obj);
        writeFile(outDir + "/Triple09.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Triple09 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Triple09 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Triple09.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Triple09Codec.decode(r);
        specodec::JsonWriter w;
        Triple09Codec.encode(w, obj);
        writeFile(outDir + "/Triple09.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Triple09 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Triple09 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Triple09.gron");
        specodec::GronReader r(data);
        auto obj = Triple09Codec.decode(r);
        specodec::GronWriter w;
        Triple09Codec.encode(w, obj);
        writeFile(outDir + "/Triple09.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Triple09 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Triple09 gron" << std::endl; }
}

void testModelTriple10(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Triple10.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Triple10Codec.decode(r);
        specodec::MsgPackWriter w;
        Triple10Codec.encode(w, obj);
        writeFile(outDir + "/Triple10.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Triple10 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Triple10 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Triple10.json");
        specodec::JsonReader r(data);
        auto obj = Triple10Codec.decode(r);
        specodec::JsonWriter w;
        Triple10Codec.encode(w, obj);
        writeFile(outDir + "/Triple10.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Triple10 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Triple10 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Triple10.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Triple10Codec.decode(r);
        specodec::JsonWriter w;
        Triple10Codec.encode(w, obj);
        writeFile(outDir + "/Triple10.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Triple10 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Triple10 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Triple10.gron");
        specodec::GronReader r(data);
        auto obj = Triple10Codec.decode(r);
        specodec::GronWriter w;
        Triple10Codec.encode(w, obj);
        writeFile(outDir + "/Triple10.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Triple10 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Triple10 gron" << std::endl; }
}

void testModelTriple11(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Triple11.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Triple11Codec.decode(r);
        specodec::MsgPackWriter w;
        Triple11Codec.encode(w, obj);
        writeFile(outDir + "/Triple11.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Triple11 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Triple11 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Triple11.json");
        specodec::JsonReader r(data);
        auto obj = Triple11Codec.decode(r);
        specodec::JsonWriter w;
        Triple11Codec.encode(w, obj);
        writeFile(outDir + "/Triple11.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Triple11 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Triple11 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Triple11.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Triple11Codec.decode(r);
        specodec::JsonWriter w;
        Triple11Codec.encode(w, obj);
        writeFile(outDir + "/Triple11.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Triple11 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Triple11 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Triple11.gron");
        specodec::GronReader r(data);
        auto obj = Triple11Codec.decode(r);
        specodec::GronWriter w;
        Triple11Codec.encode(w, obj);
        writeFile(outDir + "/Triple11.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Triple11 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Triple11 gron" << std::endl; }
}

void testModelTriple12(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Triple12.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Triple12Codec.decode(r);
        specodec::MsgPackWriter w;
        Triple12Codec.encode(w, obj);
        writeFile(outDir + "/Triple12.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Triple12 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Triple12 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Triple12.json");
        specodec::JsonReader r(data);
        auto obj = Triple12Codec.decode(r);
        specodec::JsonWriter w;
        Triple12Codec.encode(w, obj);
        writeFile(outDir + "/Triple12.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Triple12 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Triple12 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Triple12.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Triple12Codec.decode(r);
        specodec::JsonWriter w;
        Triple12Codec.encode(w, obj);
        writeFile(outDir + "/Triple12.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Triple12 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Triple12 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Triple12.gron");
        specodec::GronReader r(data);
        auto obj = Triple12Codec.decode(r);
        specodec::GronWriter w;
        Triple12Codec.encode(w, obj);
        writeFile(outDir + "/Triple12.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Triple12 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Triple12 gron" << std::endl; }
}

void testModelTriple13(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Triple13.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Triple13Codec.decode(r);
        specodec::MsgPackWriter w;
        Triple13Codec.encode(w, obj);
        writeFile(outDir + "/Triple13.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Triple13 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Triple13 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Triple13.json");
        specodec::JsonReader r(data);
        auto obj = Triple13Codec.decode(r);
        specodec::JsonWriter w;
        Triple13Codec.encode(w, obj);
        writeFile(outDir + "/Triple13.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Triple13 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Triple13 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Triple13.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Triple13Codec.decode(r);
        specodec::JsonWriter w;
        Triple13Codec.encode(w, obj);
        writeFile(outDir + "/Triple13.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Triple13 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Triple13 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Triple13.gron");
        specodec::GronReader r(data);
        auto obj = Triple13Codec.decode(r);
        specodec::GronWriter w;
        Triple13Codec.encode(w, obj);
        writeFile(outDir + "/Triple13.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Triple13 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Triple13 gron" << std::endl; }
}

void testModelTriple14(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Triple14.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Triple14Codec.decode(r);
        specodec::MsgPackWriter w;
        Triple14Codec.encode(w, obj);
        writeFile(outDir + "/Triple14.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Triple14 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Triple14 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Triple14.json");
        specodec::JsonReader r(data);
        auto obj = Triple14Codec.decode(r);
        specodec::JsonWriter w;
        Triple14Codec.encode(w, obj);
        writeFile(outDir + "/Triple14.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Triple14 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Triple14 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Triple14.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Triple14Codec.decode(r);
        specodec::JsonWriter w;
        Triple14Codec.encode(w, obj);
        writeFile(outDir + "/Triple14.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Triple14 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Triple14 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Triple14.gron");
        specodec::GronReader r(data);
        auto obj = Triple14Codec.decode(r);
        specodec::GronWriter w;
        Triple14Codec.encode(w, obj);
        writeFile(outDir + "/Triple14.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Triple14 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Triple14 gron" << std::endl; }
}

void testModelTriple15(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Triple15.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Triple15Codec.decode(r);
        specodec::MsgPackWriter w;
        Triple15Codec.encode(w, obj);
        writeFile(outDir + "/Triple15.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Triple15 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Triple15 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Triple15.json");
        specodec::JsonReader r(data);
        auto obj = Triple15Codec.decode(r);
        specodec::JsonWriter w;
        Triple15Codec.encode(w, obj);
        writeFile(outDir + "/Triple15.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Triple15 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Triple15 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Triple15.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Triple15Codec.decode(r);
        specodec::JsonWriter w;
        Triple15Codec.encode(w, obj);
        writeFile(outDir + "/Triple15.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Triple15 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Triple15 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Triple15.gron");
        specodec::GronReader r(data);
        auto obj = Triple15Codec.decode(r);
        specodec::GronWriter w;
        Triple15Codec.encode(w, obj);
        writeFile(outDir + "/Triple15.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Triple15 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Triple15 gron" << std::endl; }
}


export void runAlltypes_pairs(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    testModelPairString(passed, failed, vecDir, outDir);
    testModelPairBoolean(passed, failed, vecDir, outDir);
    testModelPairInt8(passed, failed, vecDir, outDir);
    testModelPairInt16(passed, failed, vecDir, outDir);
    testModelPairInt32(passed, failed, vecDir, outDir);
    testModelPairInt64(passed, failed, vecDir, outDir);
    testModelPairUint8(passed, failed, vecDir, outDir);
    testModelPairUint16(passed, failed, vecDir, outDir);
    testModelPairUint32(passed, failed, vecDir, outDir);
    testModelPairUint64(passed, failed, vecDir, outDir);
    testModelPairFloat32(passed, failed, vecDir, outDir);
    testModelPairFloat64(passed, failed, vecDir, outDir);
    testModelPairBytes(passed, failed, vecDir, outDir);
    testModelDualStringInt32(passed, failed, vecDir, outDir);
    testModelDualStringBoolean(passed, failed, vecDir, outDir);
    testModelDualStringFloat64(passed, failed, vecDir, outDir);
    testModelDualStringBytes(passed, failed, vecDir, outDir);
    testModelDualInt32Boolean(passed, failed, vecDir, outDir);
    testModelDualInt32Float64(passed, failed, vecDir, outDir);
    testModelDualInt32Int64(passed, failed, vecDir, outDir);
    testModelDualInt32Uint32(passed, failed, vecDir, outDir);
    testModelDualInt64Uint64(passed, failed, vecDir, outDir);
    testModelDualFloat32Float64(passed, failed, vecDir, outDir);
    testModelDualFloat64Boolean(passed, failed, vecDir, outDir);
    testModelDualFloat64Bytes(passed, failed, vecDir, outDir);
    testModelDualUint32Uint64(passed, failed, vecDir, outDir);
    testModelDualBooleanBytes(passed, failed, vecDir, outDir);
    testModelDualInt8Uint8(passed, failed, vecDir, outDir);
    testModelDualInt16Uint16(passed, failed, vecDir, outDir);
    testModelDualStringInt64(passed, failed, vecDir, outDir);
    testModelDualStringUint64(passed, failed, vecDir, outDir);
    testModelDualInt32Bytes(passed, failed, vecDir, outDir);
    testModelDualFloat64Int32(passed, failed, vecDir, outDir);
    testModelDualBooleanInt32(passed, failed, vecDir, outDir);
    testModelDualBytesInt64(passed, failed, vecDir, outDir);
    testModelDualInt8Float32(passed, failed, vecDir, outDir);
    testModelDualUint8Int16(passed, failed, vecDir, outDir);
    testModelDualInt64Float64(passed, failed, vecDir, outDir);
    testModelDualUint64String(passed, failed, vecDir, outDir);
    testModelTriple01(passed, failed, vecDir, outDir);
    testModelTriple02(passed, failed, vecDir, outDir);
    testModelTriple03(passed, failed, vecDir, outDir);
    testModelTriple04(passed, failed, vecDir, outDir);
    testModelTriple05(passed, failed, vecDir, outDir);
    testModelTriple06(passed, failed, vecDir, outDir);
    testModelTriple07(passed, failed, vecDir, outDir);
    testModelTriple08(passed, failed, vecDir, outDir);
    testModelTriple09(passed, failed, vecDir, outDir);
    testModelTriple10(passed, failed, vecDir, outDir);
    testModelTriple11(passed, failed, vecDir, outDir);
    testModelTriple12(passed, failed, vecDir, outDir);
    testModelTriple13(passed, failed, vecDir, outDir);
    testModelTriple14(passed, failed, vecDir, outDir);
    testModelTriple15(passed, failed, vecDir, outDir);

}
