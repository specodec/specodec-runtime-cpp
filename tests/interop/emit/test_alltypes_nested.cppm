module;
#include <cstdlib>
#include <fstream>
#include <filesystem>
export module test_alltypes_nested;
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


void testModelNestedSimple(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/NestedSimple.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = NestedSimpleCodec.decode(r);
        specodec::MsgPackWriter w;
        NestedSimpleCodec.encode(w, obj);
        writeFile(outDir + "/NestedSimple.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestedSimple mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestedSimple mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/NestedSimple.json");
        specodec::JsonReader r(data);
        auto obj = NestedSimpleCodec.decode(r);
        specodec::JsonWriter w;
        NestedSimpleCodec.encode(w, obj);
        writeFile(outDir + "/NestedSimple.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestedSimple json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestedSimple json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/NestedSimple.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = NestedSimpleCodec.decode(r);
        specodec::JsonWriter w;
        NestedSimpleCodec.encode(w, obj);
        writeFile(outDir + "/NestedSimple.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestedSimple unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestedSimple unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/NestedSimple.gron");
        specodec::GronReader r(data);
        auto obj = NestedSimpleCodec.decode(r);
        specodec::GronWriter w;
        NestedSimpleCodec.encode(w, obj);
        writeFile(outDir + "/NestedSimple.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestedSimple gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestedSimple gron" << std::endl; }
}


export void runAlltypes_nested(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    testModelNestedSimple(passed, failed, vecDir, outDir);

}
