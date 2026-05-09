module;
#include <cstdlib>
#include <fstream>
#include <filesystem>
export module test_alltypes_enums;
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


void testModelEnumHolder(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/EnumHolder.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = EnumHolderCodec.decode(r);
        specodec::MsgPackWriter w;
        EnumHolderCodec.encode(w, obj);
        writeFile(outDir + "/EnumHolder.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL EnumHolder mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL EnumHolder mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/EnumHolder.json");
        specodec::JsonReader r(data);
        auto obj = EnumHolderCodec.decode(r);
        specodec::JsonWriter w;
        EnumHolderCodec.encode(w, obj);
        writeFile(outDir + "/EnumHolder.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL EnumHolder json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL EnumHolder json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/EnumHolder.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = EnumHolderCodec.decode(r);
        specodec::JsonWriter w;
        EnumHolderCodec.encode(w, obj);
        writeFile(outDir + "/EnumHolder.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL EnumHolder unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL EnumHolder unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/EnumHolder.gron");
        specodec::GronReader r(data);
        auto obj = EnumHolderCodec.decode(r);
        specodec::GronWriter w;
        EnumHolderCodec.encode(w, obj);
        writeFile(outDir + "/EnumHolder.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL EnumHolder gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL EnumHolder gron" << std::endl; }
}

void testModelOptEnumHolder(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptEnumHolder.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptEnumHolderCodec.decode(r);
        specodec::MsgPackWriter w;
        OptEnumHolderCodec.encode(w, obj);
        writeFile(outDir + "/OptEnumHolder.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptEnumHolder mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptEnumHolder mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptEnumHolder.json");
        specodec::JsonReader r(data);
        auto obj = OptEnumHolderCodec.decode(r);
        specodec::JsonWriter w;
        OptEnumHolderCodec.encode(w, obj);
        writeFile(outDir + "/OptEnumHolder.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptEnumHolder json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptEnumHolder json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptEnumHolder.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptEnumHolderCodec.decode(r);
        specodec::JsonWriter w;
        OptEnumHolderCodec.encode(w, obj);
        writeFile(outDir + "/OptEnumHolder.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptEnumHolder unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptEnumHolder unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptEnumHolder.gron");
        specodec::GronReader r(data);
        auto obj = OptEnumHolderCodec.decode(r);
        specodec::GronWriter w;
        OptEnumHolderCodec.encode(w, obj);
        writeFile(outDir + "/OptEnumHolder.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptEnumHolder gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptEnumHolder gron" << std::endl; }
}

void testModelEnumArrayHolder(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/EnumArrayHolder.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = EnumArrayHolderCodec.decode(r);
        specodec::MsgPackWriter w;
        EnumArrayHolderCodec.encode(w, obj);
        writeFile(outDir + "/EnumArrayHolder.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL EnumArrayHolder mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL EnumArrayHolder mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/EnumArrayHolder.json");
        specodec::JsonReader r(data);
        auto obj = EnumArrayHolderCodec.decode(r);
        specodec::JsonWriter w;
        EnumArrayHolderCodec.encode(w, obj);
        writeFile(outDir + "/EnumArrayHolder.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL EnumArrayHolder json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL EnumArrayHolder json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/EnumArrayHolder.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = EnumArrayHolderCodec.decode(r);
        specodec::JsonWriter w;
        EnumArrayHolderCodec.encode(w, obj);
        writeFile(outDir + "/EnumArrayHolder.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL EnumArrayHolder unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL EnumArrayHolder unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/EnumArrayHolder.gron");
        specodec::GronReader r(data);
        auto obj = EnumArrayHolderCodec.decode(r);
        specodec::GronWriter w;
        EnumArrayHolderCodec.encode(w, obj);
        writeFile(outDir + "/EnumArrayHolder.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL EnumArrayHolder gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL EnumArrayHolder gron" << std::endl; }
}

void testModelEnumMixedHolder(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/EnumMixedHolder.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = EnumMixedHolderCodec.decode(r);
        specodec::MsgPackWriter w;
        EnumMixedHolderCodec.encode(w, obj);
        writeFile(outDir + "/EnumMixedHolder.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL EnumMixedHolder mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL EnumMixedHolder mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/EnumMixedHolder.json");
        specodec::JsonReader r(data);
        auto obj = EnumMixedHolderCodec.decode(r);
        specodec::JsonWriter w;
        EnumMixedHolderCodec.encode(w, obj);
        writeFile(outDir + "/EnumMixedHolder.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL EnumMixedHolder json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL EnumMixedHolder json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/EnumMixedHolder.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = EnumMixedHolderCodec.decode(r);
        specodec::JsonWriter w;
        EnumMixedHolderCodec.encode(w, obj);
        writeFile(outDir + "/EnumMixedHolder.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL EnumMixedHolder unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL EnumMixedHolder unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/EnumMixedHolder.gron");
        specodec::GronReader r(data);
        auto obj = EnumMixedHolderCodec.decode(r);
        specodec::GronWriter w;
        EnumMixedHolderCodec.encode(w, obj);
        writeFile(outDir + "/EnumMixedHolder.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL EnumMixedHolder gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL EnumMixedHolder gron" << std::endl; }
}


export void runAlltypes_enums(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    testModelEnumHolder(passed, failed, vecDir, outDir);
    testModelOptEnumHolder(passed, failed, vecDir, outDir);
    testModelEnumArrayHolder(passed, failed, vecDir, outDir);
    testModelEnumMixedHolder(passed, failed, vecDir, outDir);

}
