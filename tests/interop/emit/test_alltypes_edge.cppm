module;
#include <cstdlib>
#include <fstream>
#include <filesystem>
export module test_alltypes_edge;
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


void testModelEdgeEmpty(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/EdgeEmpty.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = EdgeEmptyCodec.decode(r);
        specodec::MsgPackWriter w;
        EdgeEmptyCodec.encode(w, obj);
        writeFile(outDir + "/EdgeEmpty.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL EdgeEmpty mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL EdgeEmpty mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/EdgeEmpty.json");
        specodec::JsonReader r(data);
        auto obj = EdgeEmptyCodec.decode(r);
        specodec::JsonWriter w;
        EdgeEmptyCodec.encode(w, obj);
        writeFile(outDir + "/EdgeEmpty.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL EdgeEmpty json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL EdgeEmpty json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/EdgeEmpty.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = EdgeEmptyCodec.decode(r);
        specodec::JsonWriter w;
        EdgeEmptyCodec.encode(w, obj);
        writeFile(outDir + "/EdgeEmpty.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL EdgeEmpty unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL EdgeEmpty unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/EdgeEmpty.gron");
        specodec::GronReader r(data);
        auto obj = EdgeEmptyCodec.decode(r);
        specodec::GronWriter w;
        EdgeEmptyCodec.encode(w, obj);
        writeFile(outDir + "/EdgeEmpty.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL EdgeEmpty gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL EdgeEmpty gron" << std::endl; }
}

void testModelEdgeOneOpt(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/EdgeOneOpt.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = EdgeOneOptCodec.decode(r);
        specodec::MsgPackWriter w;
        EdgeOneOptCodec.encode(w, obj);
        writeFile(outDir + "/EdgeOneOpt.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL EdgeOneOpt mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL EdgeOneOpt mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/EdgeOneOpt.json");
        specodec::JsonReader r(data);
        auto obj = EdgeOneOptCodec.decode(r);
        specodec::JsonWriter w;
        EdgeOneOptCodec.encode(w, obj);
        writeFile(outDir + "/EdgeOneOpt.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL EdgeOneOpt json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL EdgeOneOpt json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/EdgeOneOpt.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = EdgeOneOptCodec.decode(r);
        specodec::JsonWriter w;
        EdgeOneOptCodec.encode(w, obj);
        writeFile(outDir + "/EdgeOneOpt.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL EdgeOneOpt unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL EdgeOneOpt unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/EdgeOneOpt.gron");
        specodec::GronReader r(data);
        auto obj = EdgeOneOptCodec.decode(r);
        specodec::GronWriter w;
        EdgeOneOptCodec.encode(w, obj);
        writeFile(outDir + "/EdgeOneOpt.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL EdgeOneOpt gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL EdgeOneOpt gron" << std::endl; }
}

void testModelEdgeBigNums(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/EdgeBigNums.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = EdgeBigNumsCodec.decode(r);
        specodec::MsgPackWriter w;
        EdgeBigNumsCodec.encode(w, obj);
        writeFile(outDir + "/EdgeBigNums.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL EdgeBigNums mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL EdgeBigNums mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/EdgeBigNums.json");
        specodec::JsonReader r(data);
        auto obj = EdgeBigNumsCodec.decode(r);
        specodec::JsonWriter w;
        EdgeBigNumsCodec.encode(w, obj);
        writeFile(outDir + "/EdgeBigNums.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL EdgeBigNums json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL EdgeBigNums json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/EdgeBigNums.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = EdgeBigNumsCodec.decode(r);
        specodec::JsonWriter w;
        EdgeBigNumsCodec.encode(w, obj);
        writeFile(outDir + "/EdgeBigNums.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL EdgeBigNums unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL EdgeBigNums unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/EdgeBigNums.gron");
        specodec::GronReader r(data);
        auto obj = EdgeBigNumsCodec.decode(r);
        specodec::GronWriter w;
        EdgeBigNumsCodec.encode(w, obj);
        writeFile(outDir + "/EdgeBigNums.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL EdgeBigNums gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL EdgeBigNums gron" << std::endl; }
}

void testModelEdgeZeroVals(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/EdgeZeroVals.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = EdgeZeroValsCodec.decode(r);
        specodec::MsgPackWriter w;
        EdgeZeroValsCodec.encode(w, obj);
        writeFile(outDir + "/EdgeZeroVals.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL EdgeZeroVals mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL EdgeZeroVals mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/EdgeZeroVals.json");
        specodec::JsonReader r(data);
        auto obj = EdgeZeroValsCodec.decode(r);
        specodec::JsonWriter w;
        EdgeZeroValsCodec.encode(w, obj);
        writeFile(outDir + "/EdgeZeroVals.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL EdgeZeroVals json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL EdgeZeroVals json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/EdgeZeroVals.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = EdgeZeroValsCodec.decode(r);
        specodec::JsonWriter w;
        EdgeZeroValsCodec.encode(w, obj);
        writeFile(outDir + "/EdgeZeroVals.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL EdgeZeroVals unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL EdgeZeroVals unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/EdgeZeroVals.gron");
        specodec::GronReader r(data);
        auto obj = EdgeZeroValsCodec.decode(r);
        specodec::GronWriter w;
        EdgeZeroValsCodec.encode(w, obj);
        writeFile(outDir + "/EdgeZeroVals.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL EdgeZeroVals gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL EdgeZeroVals gron" << std::endl; }
}

void testModelEdgeNullable(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/EdgeNullable.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = EdgeNullableCodec.decode(r);
        specodec::MsgPackWriter w;
        EdgeNullableCodec.encode(w, obj);
        writeFile(outDir + "/EdgeNullable.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL EdgeNullable mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL EdgeNullable mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/EdgeNullable.json");
        specodec::JsonReader r(data);
        auto obj = EdgeNullableCodec.decode(r);
        specodec::JsonWriter w;
        EdgeNullableCodec.encode(w, obj);
        writeFile(outDir + "/EdgeNullable.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL EdgeNullable json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL EdgeNullable json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/EdgeNullable.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = EdgeNullableCodec.decode(r);
        specodec::JsonWriter w;
        EdgeNullableCodec.encode(w, obj);
        writeFile(outDir + "/EdgeNullable.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL EdgeNullable unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL EdgeNullable unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/EdgeNullable.gron");
        specodec::GronReader r(data);
        auto obj = EdgeNullableCodec.decode(r);
        specodec::GronWriter w;
        EdgeNullableCodec.encode(w, obj);
        writeFile(outDir + "/EdgeNullable.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL EdgeNullable gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL EdgeNullable gron" << std::endl; }
}

void testModelEdgeNegZero(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/EdgeNegZero.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = EdgeNegZeroCodec.decode(r);
        specodec::MsgPackWriter w;
        EdgeNegZeroCodec.encode(w, obj);
        writeFile(outDir + "/EdgeNegZero.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL EdgeNegZero mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL EdgeNegZero mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/EdgeNegZero.json");
        specodec::JsonReader r(data);
        auto obj = EdgeNegZeroCodec.decode(r);
        specodec::JsonWriter w;
        EdgeNegZeroCodec.encode(w, obj);
        writeFile(outDir + "/EdgeNegZero.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL EdgeNegZero json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL EdgeNegZero json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/EdgeNegZero.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = EdgeNegZeroCodec.decode(r);
        specodec::JsonWriter w;
        EdgeNegZeroCodec.encode(w, obj);
        writeFile(outDir + "/EdgeNegZero.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL EdgeNegZero unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL EdgeNegZero unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/EdgeNegZero.gron");
        specodec::GronReader r(data);
        auto obj = EdgeNegZeroCodec.decode(r);
        specodec::GronWriter w;
        EdgeNegZeroCodec.encode(w, obj);
        writeFile(outDir + "/EdgeNegZero.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL EdgeNegZero gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL EdgeNegZero gron" << std::endl; }
}

void testModelEdgeNullByte(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/EdgeNullByte.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = EdgeNullByteCodec.decode(r);
        specodec::MsgPackWriter w;
        EdgeNullByteCodec.encode(w, obj);
        writeFile(outDir + "/EdgeNullByte.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL EdgeNullByte mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL EdgeNullByte mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/EdgeNullByte.json");
        specodec::JsonReader r(data);
        auto obj = EdgeNullByteCodec.decode(r);
        specodec::JsonWriter w;
        EdgeNullByteCodec.encode(w, obj);
        writeFile(outDir + "/EdgeNullByte.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL EdgeNullByte json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL EdgeNullByte json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/EdgeNullByte.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = EdgeNullByteCodec.decode(r);
        specodec::JsonWriter w;
        EdgeNullByteCodec.encode(w, obj);
        writeFile(outDir + "/EdgeNullByte.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL EdgeNullByte unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL EdgeNullByte unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/EdgeNullByte.gron");
        specodec::GronReader r(data);
        auto obj = EdgeNullByteCodec.decode(r);
        specodec::GronWriter w;
        EdgeNullByteCodec.encode(w, obj);
        writeFile(outDir + "/EdgeNullByte.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL EdgeNullByte gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL EdgeNullByte gron" << std::endl; }
}

void testModelEdgeBoundary(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/EdgeBoundary.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = EdgeBoundaryCodec.decode(r);
        specodec::MsgPackWriter w;
        EdgeBoundaryCodec.encode(w, obj);
        writeFile(outDir + "/EdgeBoundary.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL EdgeBoundary mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL EdgeBoundary mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/EdgeBoundary.json");
        specodec::JsonReader r(data);
        auto obj = EdgeBoundaryCodec.decode(r);
        specodec::JsonWriter w;
        EdgeBoundaryCodec.encode(w, obj);
        writeFile(outDir + "/EdgeBoundary.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL EdgeBoundary json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL EdgeBoundary json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/EdgeBoundary.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = EdgeBoundaryCodec.decode(r);
        specodec::JsonWriter w;
        EdgeBoundaryCodec.encode(w, obj);
        writeFile(outDir + "/EdgeBoundary.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL EdgeBoundary unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL EdgeBoundary unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/EdgeBoundary.gron");
        specodec::GronReader r(data);
        auto obj = EdgeBoundaryCodec.decode(r);
        specodec::GronWriter w;
        EdgeBoundaryCodec.encode(w, obj);
        writeFile(outDir + "/EdgeBoundary.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL EdgeBoundary gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL EdgeBoundary gron" << std::endl; }
}

void testModelEdgeStrLen(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/EdgeStrLen.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = EdgeStrLenCodec.decode(r);
        specodec::MsgPackWriter w;
        EdgeStrLenCodec.encode(w, obj);
        writeFile(outDir + "/EdgeStrLen.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL EdgeStrLen mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL EdgeStrLen mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/EdgeStrLen.json");
        specodec::JsonReader r(data);
        auto obj = EdgeStrLenCodec.decode(r);
        specodec::JsonWriter w;
        EdgeStrLenCodec.encode(w, obj);
        writeFile(outDir + "/EdgeStrLen.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL EdgeStrLen json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL EdgeStrLen json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/EdgeStrLen.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = EdgeStrLenCodec.decode(r);
        specodec::JsonWriter w;
        EdgeStrLenCodec.encode(w, obj);
        writeFile(outDir + "/EdgeStrLen.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL EdgeStrLen unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL EdgeStrLen unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/EdgeStrLen.gron");
        specodec::GronReader r(data);
        auto obj = EdgeStrLenCodec.decode(r);
        specodec::GronWriter w;
        EdgeStrLenCodec.encode(w, obj);
        writeFile(outDir + "/EdgeStrLen.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL EdgeStrLen gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL EdgeStrLen gron" << std::endl; }
}

void testModelEdgeBytesLen(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/EdgeBytesLen.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = EdgeBytesLenCodec.decode(r);
        specodec::MsgPackWriter w;
        EdgeBytesLenCodec.encode(w, obj);
        writeFile(outDir + "/EdgeBytesLen.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL EdgeBytesLen mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL EdgeBytesLen mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/EdgeBytesLen.json");
        specodec::JsonReader r(data);
        auto obj = EdgeBytesLenCodec.decode(r);
        specodec::JsonWriter w;
        EdgeBytesLenCodec.encode(w, obj);
        writeFile(outDir + "/EdgeBytesLen.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL EdgeBytesLen json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL EdgeBytesLen json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/EdgeBytesLen.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = EdgeBytesLenCodec.decode(r);
        specodec::JsonWriter w;
        EdgeBytesLenCodec.encode(w, obj);
        writeFile(outDir + "/EdgeBytesLen.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL EdgeBytesLen unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL EdgeBytesLen unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/EdgeBytesLen.gron");
        specodec::GronReader r(data);
        auto obj = EdgeBytesLenCodec.decode(r);
        specodec::GronWriter w;
        EdgeBytesLenCodec.encode(w, obj);
        writeFile(outDir + "/EdgeBytesLen.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL EdgeBytesLen gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL EdgeBytesLen gron" << std::endl; }
}

void testModelEdgeArrEmpty(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/EdgeArrEmpty.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = EdgeArrEmptyCodec.decode(r);
        specodec::MsgPackWriter w;
        EdgeArrEmptyCodec.encode(w, obj);
        writeFile(outDir + "/EdgeArrEmpty.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL EdgeArrEmpty mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL EdgeArrEmpty mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/EdgeArrEmpty.json");
        specodec::JsonReader r(data);
        auto obj = EdgeArrEmptyCodec.decode(r);
        specodec::JsonWriter w;
        EdgeArrEmptyCodec.encode(w, obj);
        writeFile(outDir + "/EdgeArrEmpty.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL EdgeArrEmpty json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL EdgeArrEmpty json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/EdgeArrEmpty.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = EdgeArrEmptyCodec.decode(r);
        specodec::JsonWriter w;
        EdgeArrEmptyCodec.encode(w, obj);
        writeFile(outDir + "/EdgeArrEmpty.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL EdgeArrEmpty unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL EdgeArrEmpty unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/EdgeArrEmpty.gron");
        specodec::GronReader r(data);
        auto obj = EdgeArrEmptyCodec.decode(r);
        specodec::GronWriter w;
        EdgeArrEmptyCodec.encode(w, obj);
        writeFile(outDir + "/EdgeArrEmpty.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL EdgeArrEmpty gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL EdgeArrEmpty gron" << std::endl; }
}

void testModelEdgeArrBoundary(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/EdgeArrBoundary.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = EdgeArrBoundaryCodec.decode(r);
        specodec::MsgPackWriter w;
        EdgeArrBoundaryCodec.encode(w, obj);
        writeFile(outDir + "/EdgeArrBoundary.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL EdgeArrBoundary mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL EdgeArrBoundary mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/EdgeArrBoundary.json");
        specodec::JsonReader r(data);
        auto obj = EdgeArrBoundaryCodec.decode(r);
        specodec::JsonWriter w;
        EdgeArrBoundaryCodec.encode(w, obj);
        writeFile(outDir + "/EdgeArrBoundary.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL EdgeArrBoundary json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL EdgeArrBoundary json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/EdgeArrBoundary.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = EdgeArrBoundaryCodec.decode(r);
        specodec::JsonWriter w;
        EdgeArrBoundaryCodec.encode(w, obj);
        writeFile(outDir + "/EdgeArrBoundary.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL EdgeArrBoundary unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL EdgeArrBoundary unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/EdgeArrBoundary.gron");
        specodec::GronReader r(data);
        auto obj = EdgeArrBoundaryCodec.decode(r);
        specodec::GronWriter w;
        EdgeArrBoundaryCodec.encode(w, obj);
        writeFile(outDir + "/EdgeArrBoundary.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL EdgeArrBoundary gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL EdgeArrBoundary gron" << std::endl; }
}


export void runAlltypes_edge(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    testModelEdgeEmpty(passed, failed, vecDir, outDir);
    testModelEdgeOneOpt(passed, failed, vecDir, outDir);
    testModelEdgeBigNums(passed, failed, vecDir, outDir);
    testModelEdgeZeroVals(passed, failed, vecDir, outDir);
    testModelEdgeNullable(passed, failed, vecDir, outDir);
    testModelEdgeNegZero(passed, failed, vecDir, outDir);
    testModelEdgeNullByte(passed, failed, vecDir, outDir);
    testModelEdgeBoundary(passed, failed, vecDir, outDir);
    testModelEdgeStrLen(passed, failed, vecDir, outDir);
    testModelEdgeBytesLen(passed, failed, vecDir, outDir);
    testModelEdgeArrEmpty(passed, failed, vecDir, outDir);
    testModelEdgeArrBoundary(passed, failed, vecDir, outDir);

}
