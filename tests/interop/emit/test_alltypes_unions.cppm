module;
#include <cstdlib>
#include <fstream>
#include <filesystem>
export module test_alltypes_unions;
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


void testModelUnionFieldHolder(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/UnionFieldHolder.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = UnionFieldHolderCodec.decode(r);
        specodec::MsgPackWriter w;
        UnionFieldHolderCodec.encode(w, obj);
        writeFile(outDir + "/UnionFieldHolder.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL UnionFieldHolder mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL UnionFieldHolder mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/UnionFieldHolder.json");
        specodec::JsonReader r(data);
        auto obj = UnionFieldHolderCodec.decode(r);
        specodec::JsonWriter w;
        UnionFieldHolderCodec.encode(w, obj);
        writeFile(outDir + "/UnionFieldHolder.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL UnionFieldHolder json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL UnionFieldHolder json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/UnionFieldHolder.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = UnionFieldHolderCodec.decode(r);
        specodec::JsonWriter w;
        UnionFieldHolderCodec.encode(w, obj);
        writeFile(outDir + "/UnionFieldHolder.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL UnionFieldHolder unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL UnionFieldHolder unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/UnionFieldHolder.gron");
        specodec::GronReader r(data);
        auto obj = UnionFieldHolderCodec.decode(r);
        specodec::GronWriter w;
        UnionFieldHolderCodec.encode(w, obj);
        writeFile(outDir + "/UnionFieldHolder.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL UnionFieldHolder gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL UnionFieldHolder gron" << std::endl; }
}

void testModelOptUnionFieldHolder(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptUnionFieldHolder.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptUnionFieldHolderCodec.decode(r);
        specodec::MsgPackWriter w;
        OptUnionFieldHolderCodec.encode(w, obj);
        writeFile(outDir + "/OptUnionFieldHolder.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptUnionFieldHolder mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptUnionFieldHolder mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptUnionFieldHolder.json");
        specodec::JsonReader r(data);
        auto obj = OptUnionFieldHolderCodec.decode(r);
        specodec::JsonWriter w;
        OptUnionFieldHolderCodec.encode(w, obj);
        writeFile(outDir + "/OptUnionFieldHolder.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptUnionFieldHolder json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptUnionFieldHolder json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptUnionFieldHolder.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptUnionFieldHolderCodec.decode(r);
        specodec::JsonWriter w;
        OptUnionFieldHolderCodec.encode(w, obj);
        writeFile(outDir + "/OptUnionFieldHolder.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptUnionFieldHolder unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptUnionFieldHolder unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptUnionFieldHolder.gron");
        specodec::GronReader r(data);
        auto obj = OptUnionFieldHolderCodec.decode(r);
        specodec::GronWriter w;
        OptUnionFieldHolderCodec.encode(w, obj);
        writeFile(outDir + "/OptUnionFieldHolder.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptUnionFieldHolder gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptUnionFieldHolder gron" << std::endl; }
}

void testModelUnionArrayHolder(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/UnionArrayHolder.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = UnionArrayHolderCodec.decode(r);
        specodec::MsgPackWriter w;
        UnionArrayHolderCodec.encode(w, obj);
        writeFile(outDir + "/UnionArrayHolder.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL UnionArrayHolder mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL UnionArrayHolder mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/UnionArrayHolder.json");
        specodec::JsonReader r(data);
        auto obj = UnionArrayHolderCodec.decode(r);
        specodec::JsonWriter w;
        UnionArrayHolderCodec.encode(w, obj);
        writeFile(outDir + "/UnionArrayHolder.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL UnionArrayHolder json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL UnionArrayHolder json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/UnionArrayHolder.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = UnionArrayHolderCodec.decode(r);
        specodec::JsonWriter w;
        UnionArrayHolderCodec.encode(w, obj);
        writeFile(outDir + "/UnionArrayHolder.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL UnionArrayHolder unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL UnionArrayHolder unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/UnionArrayHolder.gron");
        specodec::GronReader r(data);
        auto obj = UnionArrayHolderCodec.decode(r);
        specodec::GronWriter w;
        UnionArrayHolderCodec.encode(w, obj);
        writeFile(outDir + "/UnionArrayHolder.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL UnionArrayHolder gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL UnionArrayHolder gron" << std::endl; }
}

void testModelUnionMixedHolder(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/UnionMixedHolder.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = UnionMixedHolderCodec.decode(r);
        specodec::MsgPackWriter w;
        UnionMixedHolderCodec.encode(w, obj);
        writeFile(outDir + "/UnionMixedHolder.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL UnionMixedHolder mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL UnionMixedHolder mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/UnionMixedHolder.json");
        specodec::JsonReader r(data);
        auto obj = UnionMixedHolderCodec.decode(r);
        specodec::JsonWriter w;
        UnionMixedHolderCodec.encode(w, obj);
        writeFile(outDir + "/UnionMixedHolder.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL UnionMixedHolder json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL UnionMixedHolder json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/UnionMixedHolder.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = UnionMixedHolderCodec.decode(r);
        specodec::JsonWriter w;
        UnionMixedHolderCodec.encode(w, obj);
        writeFile(outDir + "/UnionMixedHolder.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL UnionMixedHolder unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL UnionMixedHolder unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/UnionMixedHolder.gron");
        specodec::GronReader r(data);
        auto obj = UnionMixedHolderCodec.decode(r);
        specodec::GronWriter w;
        UnionMixedHolderCodec.encode(w, obj);
        writeFile(outDir + "/UnionMixedHolder.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL UnionMixedHolder gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL UnionMixedHolder gron" << std::endl; }
}

void testModelUnionScalarHolder(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/UnionScalarHolder.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = UnionScalarHolderCodec.decode(r);
        specodec::MsgPackWriter w;
        UnionScalarHolderCodec.encode(w, obj);
        writeFile(outDir + "/UnionScalarHolder.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL UnionScalarHolder mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL UnionScalarHolder mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/UnionScalarHolder.json");
        specodec::JsonReader r(data);
        auto obj = UnionScalarHolderCodec.decode(r);
        specodec::JsonWriter w;
        UnionScalarHolderCodec.encode(w, obj);
        writeFile(outDir + "/UnionScalarHolder.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL UnionScalarHolder json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL UnionScalarHolder json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/UnionScalarHolder.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = UnionScalarHolderCodec.decode(r);
        specodec::JsonWriter w;
        UnionScalarHolderCodec.encode(w, obj);
        writeFile(outDir + "/UnionScalarHolder.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL UnionScalarHolder unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL UnionScalarHolder unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/UnionScalarHolder.gron");
        specodec::GronReader r(data);
        auto obj = UnionScalarHolderCodec.decode(r);
        specodec::GronWriter w;
        UnionScalarHolderCodec.encode(w, obj);
        writeFile(outDir + "/UnionScalarHolder.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL UnionScalarHolder gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL UnionScalarHolder gron" << std::endl; }
}


export void runAlltypes_unions(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    testModelUnionFieldHolder(passed, failed, vecDir, outDir);
    testModelOptUnionFieldHolder(passed, failed, vecDir, outDir);
    testModelUnionArrayHolder(passed, failed, vecDir, outDir);
    testModelUnionMixedHolder(passed, failed, vecDir, outDir);
    testModelUnionScalarHolder(passed, failed, vecDir, outDir);

}
