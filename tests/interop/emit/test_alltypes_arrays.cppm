module;
#include <cstdlib>
#include <fstream>
#include <filesystem>
export module test_alltypes_arrays;
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


void testModelArrString(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/ArrString.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = ArrStringCodec.decode(r);
        specodec::MsgPackWriter w;
        ArrStringCodec.encode(w, obj);
        writeFile(outDir + "/ArrString.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ArrString mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ArrString mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/ArrString.json");
        specodec::JsonReader r(data);
        auto obj = ArrStringCodec.decode(r);
        specodec::JsonWriter w;
        ArrStringCodec.encode(w, obj);
        writeFile(outDir + "/ArrString.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ArrString json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ArrString json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/ArrString.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = ArrStringCodec.decode(r);
        specodec::JsonWriter w;
        ArrStringCodec.encode(w, obj);
        writeFile(outDir + "/ArrString.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ArrString unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ArrString unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/ArrString.gron");
        specodec::GronReader r(data);
        auto obj = ArrStringCodec.decode(r);
        specodec::GronWriter w;
        ArrStringCodec.encode(w, obj);
        writeFile(outDir + "/ArrString.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ArrString gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ArrString gron" << std::endl; }
}

void testModelArrInt32(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/ArrInt32.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = ArrInt32Codec.decode(r);
        specodec::MsgPackWriter w;
        ArrInt32Codec.encode(w, obj);
        writeFile(outDir + "/ArrInt32.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ArrInt32 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ArrInt32 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/ArrInt32.json");
        specodec::JsonReader r(data);
        auto obj = ArrInt32Codec.decode(r);
        specodec::JsonWriter w;
        ArrInt32Codec.encode(w, obj);
        writeFile(outDir + "/ArrInt32.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ArrInt32 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ArrInt32 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/ArrInt32.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = ArrInt32Codec.decode(r);
        specodec::JsonWriter w;
        ArrInt32Codec.encode(w, obj);
        writeFile(outDir + "/ArrInt32.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ArrInt32 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ArrInt32 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/ArrInt32.gron");
        specodec::GronReader r(data);
        auto obj = ArrInt32Codec.decode(r);
        specodec::GronWriter w;
        ArrInt32Codec.encode(w, obj);
        writeFile(outDir + "/ArrInt32.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ArrInt32 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ArrInt32 gron" << std::endl; }
}

void testModelArrBoolean(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/ArrBoolean.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = ArrBooleanCodec.decode(r);
        specodec::MsgPackWriter w;
        ArrBooleanCodec.encode(w, obj);
        writeFile(outDir + "/ArrBoolean.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ArrBoolean mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ArrBoolean mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/ArrBoolean.json");
        specodec::JsonReader r(data);
        auto obj = ArrBooleanCodec.decode(r);
        specodec::JsonWriter w;
        ArrBooleanCodec.encode(w, obj);
        writeFile(outDir + "/ArrBoolean.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ArrBoolean json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ArrBoolean json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/ArrBoolean.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = ArrBooleanCodec.decode(r);
        specodec::JsonWriter w;
        ArrBooleanCodec.encode(w, obj);
        writeFile(outDir + "/ArrBoolean.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ArrBoolean unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ArrBoolean unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/ArrBoolean.gron");
        specodec::GronReader r(data);
        auto obj = ArrBooleanCodec.decode(r);
        specodec::GronWriter w;
        ArrBooleanCodec.encode(w, obj);
        writeFile(outDir + "/ArrBoolean.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ArrBoolean gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ArrBoolean gron" << std::endl; }
}

void testModelArrFloat64(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/ArrFloat64.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = ArrFloat64Codec.decode(r);
        specodec::MsgPackWriter w;
        ArrFloat64Codec.encode(w, obj);
        writeFile(outDir + "/ArrFloat64.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ArrFloat64 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ArrFloat64 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/ArrFloat64.json");
        specodec::JsonReader r(data);
        auto obj = ArrFloat64Codec.decode(r);
        specodec::JsonWriter w;
        ArrFloat64Codec.encode(w, obj);
        writeFile(outDir + "/ArrFloat64.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ArrFloat64 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ArrFloat64 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/ArrFloat64.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = ArrFloat64Codec.decode(r);
        specodec::JsonWriter w;
        ArrFloat64Codec.encode(w, obj);
        writeFile(outDir + "/ArrFloat64.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ArrFloat64 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ArrFloat64 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/ArrFloat64.gron");
        specodec::GronReader r(data);
        auto obj = ArrFloat64Codec.decode(r);
        specodec::GronWriter w;
        ArrFloat64Codec.encode(w, obj);
        writeFile(outDir + "/ArrFloat64.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ArrFloat64 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ArrFloat64 gron" << std::endl; }
}

void testModelArrBytes(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/ArrBytes.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = ArrBytesCodec.decode(r);
        specodec::MsgPackWriter w;
        ArrBytesCodec.encode(w, obj);
        writeFile(outDir + "/ArrBytes.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ArrBytes mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ArrBytes mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/ArrBytes.json");
        specodec::JsonReader r(data);
        auto obj = ArrBytesCodec.decode(r);
        specodec::JsonWriter w;
        ArrBytesCodec.encode(w, obj);
        writeFile(outDir + "/ArrBytes.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ArrBytes json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ArrBytes json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/ArrBytes.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = ArrBytesCodec.decode(r);
        specodec::JsonWriter w;
        ArrBytesCodec.encode(w, obj);
        writeFile(outDir + "/ArrBytes.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ArrBytes unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ArrBytes unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/ArrBytes.gron");
        specodec::GronReader r(data);
        auto obj = ArrBytesCodec.decode(r);
        specodec::GronWriter w;
        ArrBytesCodec.encode(w, obj);
        writeFile(outDir + "/ArrBytes.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ArrBytes gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ArrBytes gron" << std::endl; }
}

void testModelArrInt64(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/ArrInt64.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = ArrInt64Codec.decode(r);
        specodec::MsgPackWriter w;
        ArrInt64Codec.encode(w, obj);
        writeFile(outDir + "/ArrInt64.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ArrInt64 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ArrInt64 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/ArrInt64.json");
        specodec::JsonReader r(data);
        auto obj = ArrInt64Codec.decode(r);
        specodec::JsonWriter w;
        ArrInt64Codec.encode(w, obj);
        writeFile(outDir + "/ArrInt64.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ArrInt64 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ArrInt64 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/ArrInt64.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = ArrInt64Codec.decode(r);
        specodec::JsonWriter w;
        ArrInt64Codec.encode(w, obj);
        writeFile(outDir + "/ArrInt64.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ArrInt64 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ArrInt64 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/ArrInt64.gron");
        specodec::GronReader r(data);
        auto obj = ArrInt64Codec.decode(r);
        specodec::GronWriter w;
        ArrInt64Codec.encode(w, obj);
        writeFile(outDir + "/ArrInt64.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ArrInt64 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ArrInt64 gron" << std::endl; }
}

void testModelArrUint64(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/ArrUint64.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = ArrUint64Codec.decode(r);
        specodec::MsgPackWriter w;
        ArrUint64Codec.encode(w, obj);
        writeFile(outDir + "/ArrUint64.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ArrUint64 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ArrUint64 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/ArrUint64.json");
        specodec::JsonReader r(data);
        auto obj = ArrUint64Codec.decode(r);
        specodec::JsonWriter w;
        ArrUint64Codec.encode(w, obj);
        writeFile(outDir + "/ArrUint64.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ArrUint64 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ArrUint64 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/ArrUint64.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = ArrUint64Codec.decode(r);
        specodec::JsonWriter w;
        ArrUint64Codec.encode(w, obj);
        writeFile(outDir + "/ArrUint64.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ArrUint64 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ArrUint64 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/ArrUint64.gron");
        specodec::GronReader r(data);
        auto obj = ArrUint64Codec.decode(r);
        specodec::GronWriter w;
        ArrUint64Codec.encode(w, obj);
        writeFile(outDir + "/ArrUint64.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ArrUint64 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ArrUint64 gron" << std::endl; }
}

void testModelMultiArr1(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/MultiArr1.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = MultiArr1Codec.decode(r);
        specodec::MsgPackWriter w;
        MultiArr1Codec.encode(w, obj);
        writeFile(outDir + "/MultiArr1.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL MultiArr1 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL MultiArr1 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/MultiArr1.json");
        specodec::JsonReader r(data);
        auto obj = MultiArr1Codec.decode(r);
        specodec::JsonWriter w;
        MultiArr1Codec.encode(w, obj);
        writeFile(outDir + "/MultiArr1.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL MultiArr1 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL MultiArr1 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/MultiArr1.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = MultiArr1Codec.decode(r);
        specodec::JsonWriter w;
        MultiArr1Codec.encode(w, obj);
        writeFile(outDir + "/MultiArr1.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL MultiArr1 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL MultiArr1 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/MultiArr1.gron");
        specodec::GronReader r(data);
        auto obj = MultiArr1Codec.decode(r);
        specodec::GronWriter w;
        MultiArr1Codec.encode(w, obj);
        writeFile(outDir + "/MultiArr1.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL MultiArr1 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL MultiArr1 gron" << std::endl; }
}

void testModelMultiArr2(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/MultiArr2.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = MultiArr2Codec.decode(r);
        specodec::MsgPackWriter w;
        MultiArr2Codec.encode(w, obj);
        writeFile(outDir + "/MultiArr2.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL MultiArr2 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL MultiArr2 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/MultiArr2.json");
        specodec::JsonReader r(data);
        auto obj = MultiArr2Codec.decode(r);
        specodec::JsonWriter w;
        MultiArr2Codec.encode(w, obj);
        writeFile(outDir + "/MultiArr2.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL MultiArr2 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL MultiArr2 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/MultiArr2.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = MultiArr2Codec.decode(r);
        specodec::JsonWriter w;
        MultiArr2Codec.encode(w, obj);
        writeFile(outDir + "/MultiArr2.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL MultiArr2 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL MultiArr2 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/MultiArr2.gron");
        specodec::GronReader r(data);
        auto obj = MultiArr2Codec.decode(r);
        specodec::GronWriter w;
        MultiArr2Codec.encode(w, obj);
        writeFile(outDir + "/MultiArr2.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL MultiArr2 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL MultiArr2 gron" << std::endl; }
}

void testModelMultiArr3(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/MultiArr3.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = MultiArr3Codec.decode(r);
        specodec::MsgPackWriter w;
        MultiArr3Codec.encode(w, obj);
        writeFile(outDir + "/MultiArr3.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL MultiArr3 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL MultiArr3 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/MultiArr3.json");
        specodec::JsonReader r(data);
        auto obj = MultiArr3Codec.decode(r);
        specodec::JsonWriter w;
        MultiArr3Codec.encode(w, obj);
        writeFile(outDir + "/MultiArr3.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL MultiArr3 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL MultiArr3 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/MultiArr3.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = MultiArr3Codec.decode(r);
        specodec::JsonWriter w;
        MultiArr3Codec.encode(w, obj);
        writeFile(outDir + "/MultiArr3.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL MultiArr3 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL MultiArr3 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/MultiArr3.gron");
        specodec::GronReader r(data);
        auto obj = MultiArr3Codec.decode(r);
        specodec::GronWriter w;
        MultiArr3Codec.encode(w, obj);
        writeFile(outDir + "/MultiArr3.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL MultiArr3 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL MultiArr3 gron" << std::endl; }
}

void testModelMultiArr4(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/MultiArr4.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = MultiArr4Codec.decode(r);
        specodec::MsgPackWriter w;
        MultiArr4Codec.encode(w, obj);
        writeFile(outDir + "/MultiArr4.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL MultiArr4 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL MultiArr4 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/MultiArr4.json");
        specodec::JsonReader r(data);
        auto obj = MultiArr4Codec.decode(r);
        specodec::JsonWriter w;
        MultiArr4Codec.encode(w, obj);
        writeFile(outDir + "/MultiArr4.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL MultiArr4 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL MultiArr4 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/MultiArr4.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = MultiArr4Codec.decode(r);
        specodec::JsonWriter w;
        MultiArr4Codec.encode(w, obj);
        writeFile(outDir + "/MultiArr4.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL MultiArr4 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL MultiArr4 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/MultiArr4.gron");
        specodec::GronReader r(data);
        auto obj = MultiArr4Codec.decode(r);
        specodec::GronWriter w;
        MultiArr4Codec.encode(w, obj);
        writeFile(outDir + "/MultiArr4.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL MultiArr4 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL MultiArr4 gron" << std::endl; }
}

void testModelMultiArr5(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/MultiArr5.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = MultiArr5Codec.decode(r);
        specodec::MsgPackWriter w;
        MultiArr5Codec.encode(w, obj);
        writeFile(outDir + "/MultiArr5.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL MultiArr5 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL MultiArr5 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/MultiArr5.json");
        specodec::JsonReader r(data);
        auto obj = MultiArr5Codec.decode(r);
        specodec::JsonWriter w;
        MultiArr5Codec.encode(w, obj);
        writeFile(outDir + "/MultiArr5.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL MultiArr5 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL MultiArr5 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/MultiArr5.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = MultiArr5Codec.decode(r);
        specodec::JsonWriter w;
        MultiArr5Codec.encode(w, obj);
        writeFile(outDir + "/MultiArr5.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL MultiArr5 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL MultiArr5 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/MultiArr5.gron");
        specodec::GronReader r(data);
        auto obj = MultiArr5Codec.decode(r);
        specodec::GronWriter w;
        MultiArr5Codec.encode(w, obj);
        writeFile(outDir + "/MultiArr5.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL MultiArr5 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL MultiArr5 gron" << std::endl; }
}

void testModelOptCombo1(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptCombo1.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptCombo1Codec.decode(r);
        specodec::MsgPackWriter w;
        OptCombo1Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo1.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptCombo1 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptCombo1 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptCombo1.json");
        specodec::JsonReader r(data);
        auto obj = OptCombo1Codec.decode(r);
        specodec::JsonWriter w;
        OptCombo1Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo1.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptCombo1 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptCombo1 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptCombo1.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptCombo1Codec.decode(r);
        specodec::JsonWriter w;
        OptCombo1Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo1.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptCombo1 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptCombo1 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptCombo1.gron");
        specodec::GronReader r(data);
        auto obj = OptCombo1Codec.decode(r);
        specodec::GronWriter w;
        OptCombo1Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo1.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptCombo1 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptCombo1 gron" << std::endl; }
}

void testModelOptCombo2(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptCombo2.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptCombo2Codec.decode(r);
        specodec::MsgPackWriter w;
        OptCombo2Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo2.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptCombo2 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptCombo2 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptCombo2.json");
        specodec::JsonReader r(data);
        auto obj = OptCombo2Codec.decode(r);
        specodec::JsonWriter w;
        OptCombo2Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo2.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptCombo2 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptCombo2 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptCombo2.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptCombo2Codec.decode(r);
        specodec::JsonWriter w;
        OptCombo2Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo2.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptCombo2 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptCombo2 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptCombo2.gron");
        specodec::GronReader r(data);
        auto obj = OptCombo2Codec.decode(r);
        specodec::GronWriter w;
        OptCombo2Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo2.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptCombo2 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptCombo2 gron" << std::endl; }
}

void testModelOptCombo3(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptCombo3.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptCombo3Codec.decode(r);
        specodec::MsgPackWriter w;
        OptCombo3Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo3.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptCombo3 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptCombo3 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptCombo3.json");
        specodec::JsonReader r(data);
        auto obj = OptCombo3Codec.decode(r);
        specodec::JsonWriter w;
        OptCombo3Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo3.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptCombo3 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptCombo3 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptCombo3.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptCombo3Codec.decode(r);
        specodec::JsonWriter w;
        OptCombo3Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo3.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptCombo3 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptCombo3 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptCombo3.gron");
        specodec::GronReader r(data);
        auto obj = OptCombo3Codec.decode(r);
        specodec::GronWriter w;
        OptCombo3Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo3.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptCombo3 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptCombo3 gron" << std::endl; }
}

void testModelOptCombo4(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptCombo4.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptCombo4Codec.decode(r);
        specodec::MsgPackWriter w;
        OptCombo4Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo4.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptCombo4 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptCombo4 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptCombo4.json");
        specodec::JsonReader r(data);
        auto obj = OptCombo4Codec.decode(r);
        specodec::JsonWriter w;
        OptCombo4Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo4.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptCombo4 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptCombo4 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptCombo4.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptCombo4Codec.decode(r);
        specodec::JsonWriter w;
        OptCombo4Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo4.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptCombo4 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptCombo4 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptCombo4.gron");
        specodec::GronReader r(data);
        auto obj = OptCombo4Codec.decode(r);
        specodec::GronWriter w;
        OptCombo4Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo4.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptCombo4 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptCombo4 gron" << std::endl; }
}

void testModelOptCombo5(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptCombo5.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptCombo5Codec.decode(r);
        specodec::MsgPackWriter w;
        OptCombo5Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo5.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptCombo5 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptCombo5 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptCombo5.json");
        specodec::JsonReader r(data);
        auto obj = OptCombo5Codec.decode(r);
        specodec::JsonWriter w;
        OptCombo5Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo5.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptCombo5 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptCombo5 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptCombo5.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptCombo5Codec.decode(r);
        specodec::JsonWriter w;
        OptCombo5Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo5.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptCombo5 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptCombo5 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptCombo5.gron");
        specodec::GronReader r(data);
        auto obj = OptCombo5Codec.decode(r);
        specodec::GronWriter w;
        OptCombo5Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo5.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptCombo5 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptCombo5 gron" << std::endl; }
}

void testModelOptCombo6(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptCombo6.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptCombo6Codec.decode(r);
        specodec::MsgPackWriter w;
        OptCombo6Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo6.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptCombo6 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptCombo6 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptCombo6.json");
        specodec::JsonReader r(data);
        auto obj = OptCombo6Codec.decode(r);
        specodec::JsonWriter w;
        OptCombo6Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo6.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptCombo6 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptCombo6 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptCombo6.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptCombo6Codec.decode(r);
        specodec::JsonWriter w;
        OptCombo6Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo6.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptCombo6 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptCombo6 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptCombo6.gron");
        specodec::GronReader r(data);
        auto obj = OptCombo6Codec.decode(r);
        specodec::GronWriter w;
        OptCombo6Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo6.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptCombo6 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptCombo6 gron" << std::endl; }
}

void testModelOptCombo7(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptCombo7.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptCombo7Codec.decode(r);
        specodec::MsgPackWriter w;
        OptCombo7Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo7.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptCombo7 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptCombo7 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptCombo7.json");
        specodec::JsonReader r(data);
        auto obj = OptCombo7Codec.decode(r);
        specodec::JsonWriter w;
        OptCombo7Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo7.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptCombo7 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptCombo7 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptCombo7.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptCombo7Codec.decode(r);
        specodec::JsonWriter w;
        OptCombo7Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo7.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptCombo7 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptCombo7 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptCombo7.gron");
        specodec::GronReader r(data);
        auto obj = OptCombo7Codec.decode(r);
        specodec::GronWriter w;
        OptCombo7Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo7.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptCombo7 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptCombo7 gron" << std::endl; }
}

void testModelOptCombo8(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptCombo8.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptCombo8Codec.decode(r);
        specodec::MsgPackWriter w;
        OptCombo8Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo8.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptCombo8 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptCombo8 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptCombo8.json");
        specodec::JsonReader r(data);
        auto obj = OptCombo8Codec.decode(r);
        specodec::JsonWriter w;
        OptCombo8Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo8.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptCombo8 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptCombo8 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptCombo8.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptCombo8Codec.decode(r);
        specodec::JsonWriter w;
        OptCombo8Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo8.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptCombo8 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptCombo8 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptCombo8.gron");
        specodec::GronReader r(data);
        auto obj = OptCombo8Codec.decode(r);
        specodec::GronWriter w;
        OptCombo8Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo8.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptCombo8 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptCombo8 gron" << std::endl; }
}

void testModelOptCombo9(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptCombo9.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptCombo9Codec.decode(r);
        specodec::MsgPackWriter w;
        OptCombo9Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo9.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptCombo9 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptCombo9 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptCombo9.json");
        specodec::JsonReader r(data);
        auto obj = OptCombo9Codec.decode(r);
        specodec::JsonWriter w;
        OptCombo9Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo9.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptCombo9 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptCombo9 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptCombo9.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptCombo9Codec.decode(r);
        specodec::JsonWriter w;
        OptCombo9Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo9.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptCombo9 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptCombo9 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptCombo9.gron");
        specodec::GronReader r(data);
        auto obj = OptCombo9Codec.decode(r);
        specodec::GronWriter w;
        OptCombo9Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo9.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptCombo9 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptCombo9 gron" << std::endl; }
}

void testModelOptCombo10(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptCombo10.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptCombo10Codec.decode(r);
        specodec::MsgPackWriter w;
        OptCombo10Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo10.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptCombo10 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptCombo10 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptCombo10.json");
        specodec::JsonReader r(data);
        auto obj = OptCombo10Codec.decode(r);
        specodec::JsonWriter w;
        OptCombo10Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo10.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptCombo10 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptCombo10 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptCombo10.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptCombo10Codec.decode(r);
        specodec::JsonWriter w;
        OptCombo10Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo10.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptCombo10 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptCombo10 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptCombo10.gron");
        specodec::GronReader r(data);
        auto obj = OptCombo10Codec.decode(r);
        specodec::GronWriter w;
        OptCombo10Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo10.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptCombo10 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptCombo10 gron" << std::endl; }
}


export void runAlltypes_arrays(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    testModelArrString(passed, failed, vecDir, outDir);
    testModelArrInt32(passed, failed, vecDir, outDir);
    testModelArrBoolean(passed, failed, vecDir, outDir);
    testModelArrFloat64(passed, failed, vecDir, outDir);
    testModelArrBytes(passed, failed, vecDir, outDir);
    testModelArrInt64(passed, failed, vecDir, outDir);
    testModelArrUint64(passed, failed, vecDir, outDir);
    testModelMultiArr1(passed, failed, vecDir, outDir);
    testModelMultiArr2(passed, failed, vecDir, outDir);
    testModelMultiArr3(passed, failed, vecDir, outDir);
    testModelMultiArr4(passed, failed, vecDir, outDir);
    testModelMultiArr5(passed, failed, vecDir, outDir);
    testModelOptCombo1(passed, failed, vecDir, outDir);
    testModelOptCombo2(passed, failed, vecDir, outDir);
    testModelOptCombo3(passed, failed, vecDir, outDir);
    testModelOptCombo4(passed, failed, vecDir, outDir);
    testModelOptCombo5(passed, failed, vecDir, outDir);
    testModelOptCombo6(passed, failed, vecDir, outDir);
    testModelOptCombo7(passed, failed, vecDir, outDir);
    testModelOptCombo8(passed, failed, vecDir, outDir);
    testModelOptCombo9(passed, failed, vecDir, outDir);
    testModelOptCombo10(passed, failed, vecDir, outDir);

}
