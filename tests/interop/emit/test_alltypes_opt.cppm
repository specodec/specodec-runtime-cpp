module;
#include <cstdlib>
#include <fstream>
#include <filesystem>
export module test_alltypes_opt;
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


void testModelOptSingleString(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptSingleString.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptSingleStringCodec.decode(r);
        specodec::MsgPackWriter w;
        OptSingleStringCodec.encode(w, obj);
        writeFile(outDir + "/OptSingleString.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptSingleString mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptSingleString mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptSingleString.json");
        specodec::JsonReader r(data);
        auto obj = OptSingleStringCodec.decode(r);
        specodec::JsonWriter w;
        OptSingleStringCodec.encode(w, obj);
        writeFile(outDir + "/OptSingleString.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptSingleString json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptSingleString json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptSingleString.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptSingleStringCodec.decode(r);
        specodec::JsonWriter w;
        OptSingleStringCodec.encode(w, obj);
        writeFile(outDir + "/OptSingleString.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptSingleString unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptSingleString unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptSingleString.gron");
        specodec::GronReader r(data);
        auto obj = OptSingleStringCodec.decode(r);
        specodec::GronWriter w;
        OptSingleStringCodec.encode(w, obj);
        writeFile(outDir + "/OptSingleString.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptSingleString gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptSingleString gron" << std::endl; }
}

void testModelOptSingleBoolean(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptSingleBoolean.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptSingleBooleanCodec.decode(r);
        specodec::MsgPackWriter w;
        OptSingleBooleanCodec.encode(w, obj);
        writeFile(outDir + "/OptSingleBoolean.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptSingleBoolean mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptSingleBoolean mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptSingleBoolean.json");
        specodec::JsonReader r(data);
        auto obj = OptSingleBooleanCodec.decode(r);
        specodec::JsonWriter w;
        OptSingleBooleanCodec.encode(w, obj);
        writeFile(outDir + "/OptSingleBoolean.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptSingleBoolean json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptSingleBoolean json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptSingleBoolean.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptSingleBooleanCodec.decode(r);
        specodec::JsonWriter w;
        OptSingleBooleanCodec.encode(w, obj);
        writeFile(outDir + "/OptSingleBoolean.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptSingleBoolean unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptSingleBoolean unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptSingleBoolean.gron");
        specodec::GronReader r(data);
        auto obj = OptSingleBooleanCodec.decode(r);
        specodec::GronWriter w;
        OptSingleBooleanCodec.encode(w, obj);
        writeFile(outDir + "/OptSingleBoolean.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptSingleBoolean gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptSingleBoolean gron" << std::endl; }
}

void testModelOptSingleInt8(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptSingleInt8.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptSingleInt8Codec.decode(r);
        specodec::MsgPackWriter w;
        OptSingleInt8Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleInt8.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptSingleInt8 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptSingleInt8 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptSingleInt8.json");
        specodec::JsonReader r(data);
        auto obj = OptSingleInt8Codec.decode(r);
        specodec::JsonWriter w;
        OptSingleInt8Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleInt8.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptSingleInt8 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptSingleInt8 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptSingleInt8.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptSingleInt8Codec.decode(r);
        specodec::JsonWriter w;
        OptSingleInt8Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleInt8.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptSingleInt8 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptSingleInt8 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptSingleInt8.gron");
        specodec::GronReader r(data);
        auto obj = OptSingleInt8Codec.decode(r);
        specodec::GronWriter w;
        OptSingleInt8Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleInt8.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptSingleInt8 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptSingleInt8 gron" << std::endl; }
}

void testModelOptSingleInt16(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptSingleInt16.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptSingleInt16Codec.decode(r);
        specodec::MsgPackWriter w;
        OptSingleInt16Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleInt16.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptSingleInt16 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptSingleInt16 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptSingleInt16.json");
        specodec::JsonReader r(data);
        auto obj = OptSingleInt16Codec.decode(r);
        specodec::JsonWriter w;
        OptSingleInt16Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleInt16.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptSingleInt16 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptSingleInt16 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptSingleInt16.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptSingleInt16Codec.decode(r);
        specodec::JsonWriter w;
        OptSingleInt16Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleInt16.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptSingleInt16 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptSingleInt16 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptSingleInt16.gron");
        specodec::GronReader r(data);
        auto obj = OptSingleInt16Codec.decode(r);
        specodec::GronWriter w;
        OptSingleInt16Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleInt16.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptSingleInt16 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptSingleInt16 gron" << std::endl; }
}

void testModelOptSingleInt32(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptSingleInt32.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptSingleInt32Codec.decode(r);
        specodec::MsgPackWriter w;
        OptSingleInt32Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleInt32.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptSingleInt32 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptSingleInt32 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptSingleInt32.json");
        specodec::JsonReader r(data);
        auto obj = OptSingleInt32Codec.decode(r);
        specodec::JsonWriter w;
        OptSingleInt32Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleInt32.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptSingleInt32 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptSingleInt32 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptSingleInt32.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptSingleInt32Codec.decode(r);
        specodec::JsonWriter w;
        OptSingleInt32Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleInt32.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptSingleInt32 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptSingleInt32 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptSingleInt32.gron");
        specodec::GronReader r(data);
        auto obj = OptSingleInt32Codec.decode(r);
        specodec::GronWriter w;
        OptSingleInt32Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleInt32.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptSingleInt32 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptSingleInt32 gron" << std::endl; }
}

void testModelOptSingleInt64(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptSingleInt64.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptSingleInt64Codec.decode(r);
        specodec::MsgPackWriter w;
        OptSingleInt64Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleInt64.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptSingleInt64 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptSingleInt64 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptSingleInt64.json");
        specodec::JsonReader r(data);
        auto obj = OptSingleInt64Codec.decode(r);
        specodec::JsonWriter w;
        OptSingleInt64Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleInt64.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptSingleInt64 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptSingleInt64 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptSingleInt64.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptSingleInt64Codec.decode(r);
        specodec::JsonWriter w;
        OptSingleInt64Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleInt64.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptSingleInt64 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptSingleInt64 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptSingleInt64.gron");
        specodec::GronReader r(data);
        auto obj = OptSingleInt64Codec.decode(r);
        specodec::GronWriter w;
        OptSingleInt64Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleInt64.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptSingleInt64 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptSingleInt64 gron" << std::endl; }
}

void testModelOptSingleUint8(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptSingleUint8.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptSingleUint8Codec.decode(r);
        specodec::MsgPackWriter w;
        OptSingleUint8Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleUint8.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptSingleUint8 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptSingleUint8 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptSingleUint8.json");
        specodec::JsonReader r(data);
        auto obj = OptSingleUint8Codec.decode(r);
        specodec::JsonWriter w;
        OptSingleUint8Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleUint8.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptSingleUint8 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptSingleUint8 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptSingleUint8.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptSingleUint8Codec.decode(r);
        specodec::JsonWriter w;
        OptSingleUint8Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleUint8.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptSingleUint8 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptSingleUint8 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptSingleUint8.gron");
        specodec::GronReader r(data);
        auto obj = OptSingleUint8Codec.decode(r);
        specodec::GronWriter w;
        OptSingleUint8Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleUint8.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptSingleUint8 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptSingleUint8 gron" << std::endl; }
}

void testModelOptSingleUint16(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptSingleUint16.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptSingleUint16Codec.decode(r);
        specodec::MsgPackWriter w;
        OptSingleUint16Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleUint16.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptSingleUint16 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptSingleUint16 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptSingleUint16.json");
        specodec::JsonReader r(data);
        auto obj = OptSingleUint16Codec.decode(r);
        specodec::JsonWriter w;
        OptSingleUint16Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleUint16.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptSingleUint16 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptSingleUint16 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptSingleUint16.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptSingleUint16Codec.decode(r);
        specodec::JsonWriter w;
        OptSingleUint16Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleUint16.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptSingleUint16 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptSingleUint16 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptSingleUint16.gron");
        specodec::GronReader r(data);
        auto obj = OptSingleUint16Codec.decode(r);
        specodec::GronWriter w;
        OptSingleUint16Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleUint16.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptSingleUint16 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptSingleUint16 gron" << std::endl; }
}

void testModelOptSingleUint32(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptSingleUint32.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptSingleUint32Codec.decode(r);
        specodec::MsgPackWriter w;
        OptSingleUint32Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleUint32.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptSingleUint32 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptSingleUint32 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptSingleUint32.json");
        specodec::JsonReader r(data);
        auto obj = OptSingleUint32Codec.decode(r);
        specodec::JsonWriter w;
        OptSingleUint32Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleUint32.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptSingleUint32 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptSingleUint32 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptSingleUint32.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptSingleUint32Codec.decode(r);
        specodec::JsonWriter w;
        OptSingleUint32Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleUint32.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptSingleUint32 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptSingleUint32 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptSingleUint32.gron");
        specodec::GronReader r(data);
        auto obj = OptSingleUint32Codec.decode(r);
        specodec::GronWriter w;
        OptSingleUint32Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleUint32.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptSingleUint32 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptSingleUint32 gron" << std::endl; }
}

void testModelOptSingleUint64(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptSingleUint64.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptSingleUint64Codec.decode(r);
        specodec::MsgPackWriter w;
        OptSingleUint64Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleUint64.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptSingleUint64 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptSingleUint64 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptSingleUint64.json");
        specodec::JsonReader r(data);
        auto obj = OptSingleUint64Codec.decode(r);
        specodec::JsonWriter w;
        OptSingleUint64Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleUint64.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptSingleUint64 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptSingleUint64 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptSingleUint64.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptSingleUint64Codec.decode(r);
        specodec::JsonWriter w;
        OptSingleUint64Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleUint64.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptSingleUint64 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptSingleUint64 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptSingleUint64.gron");
        specodec::GronReader r(data);
        auto obj = OptSingleUint64Codec.decode(r);
        specodec::GronWriter w;
        OptSingleUint64Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleUint64.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptSingleUint64 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptSingleUint64 gron" << std::endl; }
}

void testModelOptSingleFloat32(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptSingleFloat32.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptSingleFloat32Codec.decode(r);
        specodec::MsgPackWriter w;
        OptSingleFloat32Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleFloat32.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptSingleFloat32 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptSingleFloat32 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptSingleFloat32.json");
        specodec::JsonReader r(data);
        auto obj = OptSingleFloat32Codec.decode(r);
        specodec::JsonWriter w;
        OptSingleFloat32Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleFloat32.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptSingleFloat32 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptSingleFloat32 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptSingleFloat32.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptSingleFloat32Codec.decode(r);
        specodec::JsonWriter w;
        OptSingleFloat32Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleFloat32.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptSingleFloat32 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptSingleFloat32 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptSingleFloat32.gron");
        specodec::GronReader r(data);
        auto obj = OptSingleFloat32Codec.decode(r);
        specodec::GronWriter w;
        OptSingleFloat32Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleFloat32.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptSingleFloat32 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptSingleFloat32 gron" << std::endl; }
}

void testModelOptSingleFloat64(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptSingleFloat64.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptSingleFloat64Codec.decode(r);
        specodec::MsgPackWriter w;
        OptSingleFloat64Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleFloat64.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptSingleFloat64 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptSingleFloat64 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptSingleFloat64.json");
        specodec::JsonReader r(data);
        auto obj = OptSingleFloat64Codec.decode(r);
        specodec::JsonWriter w;
        OptSingleFloat64Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleFloat64.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptSingleFloat64 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptSingleFloat64 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptSingleFloat64.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptSingleFloat64Codec.decode(r);
        specodec::JsonWriter w;
        OptSingleFloat64Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleFloat64.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptSingleFloat64 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptSingleFloat64 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptSingleFloat64.gron");
        specodec::GronReader r(data);
        auto obj = OptSingleFloat64Codec.decode(r);
        specodec::GronWriter w;
        OptSingleFloat64Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleFloat64.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptSingleFloat64 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptSingleFloat64 gron" << std::endl; }
}

void testModelOptSingleBytes(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptSingleBytes.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptSingleBytesCodec.decode(r);
        specodec::MsgPackWriter w;
        OptSingleBytesCodec.encode(w, obj);
        writeFile(outDir + "/OptSingleBytes.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptSingleBytes mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptSingleBytes mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptSingleBytes.json");
        specodec::JsonReader r(data);
        auto obj = OptSingleBytesCodec.decode(r);
        specodec::JsonWriter w;
        OptSingleBytesCodec.encode(w, obj);
        writeFile(outDir + "/OptSingleBytes.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptSingleBytes json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptSingleBytes json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptSingleBytes.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptSingleBytesCodec.decode(r);
        specodec::JsonWriter w;
        OptSingleBytesCodec.encode(w, obj);
        writeFile(outDir + "/OptSingleBytes.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptSingleBytes unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptSingleBytes unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptSingleBytes.gron");
        specodec::GronReader r(data);
        auto obj = OptSingleBytesCodec.decode(r);
        specodec::GronWriter w;
        OptSingleBytesCodec.encode(w, obj);
        writeFile(outDir + "/OptSingleBytes.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptSingleBytes gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptSingleBytes gron" << std::endl; }
}


export void runAlltypes_opt(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    testModelOptSingleString(passed, failed, vecDir, outDir);
    testModelOptSingleBoolean(passed, failed, vecDir, outDir);
    testModelOptSingleInt8(passed, failed, vecDir, outDir);
    testModelOptSingleInt16(passed, failed, vecDir, outDir);
    testModelOptSingleInt32(passed, failed, vecDir, outDir);
    testModelOptSingleInt64(passed, failed, vecDir, outDir);
    testModelOptSingleUint8(passed, failed, vecDir, outDir);
    testModelOptSingleUint16(passed, failed, vecDir, outDir);
    testModelOptSingleUint32(passed, failed, vecDir, outDir);
    testModelOptSingleUint64(passed, failed, vecDir, outDir);
    testModelOptSingleFloat32(passed, failed, vecDir, outDir);
    testModelOptSingleFloat64(passed, failed, vecDir, outDir);
    testModelOptSingleBytes(passed, failed, vecDir, outDir);

}
