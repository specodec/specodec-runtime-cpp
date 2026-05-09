module;
#include <cstdlib>
#include <fstream>
#include <filesystem>
export module test_alltypes_wide;
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


void testModelWide20(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Wide20.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Wide20Codec.decode(r);
        specodec::MsgPackWriter w;
        Wide20Codec.encode(w, obj);
        writeFile(outDir + "/Wide20.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Wide20 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Wide20 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Wide20.json");
        specodec::JsonReader r(data);
        auto obj = Wide20Codec.decode(r);
        specodec::JsonWriter w;
        Wide20Codec.encode(w, obj);
        writeFile(outDir + "/Wide20.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Wide20 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Wide20 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Wide20.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Wide20Codec.decode(r);
        specodec::JsonWriter w;
        Wide20Codec.encode(w, obj);
        writeFile(outDir + "/Wide20.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Wide20 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Wide20 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Wide20.gron");
        specodec::GronReader r(data);
        auto obj = Wide20Codec.decode(r);
        specodec::GronWriter w;
        Wide20Codec.encode(w, obj);
        writeFile(outDir + "/Wide20.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Wide20 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Wide20 gron" << std::endl; }
}

void testModelWide25(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Wide25.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Wide25Codec.decode(r);
        specodec::MsgPackWriter w;
        Wide25Codec.encode(w, obj);
        writeFile(outDir + "/Wide25.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Wide25 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Wide25 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Wide25.json");
        specodec::JsonReader r(data);
        auto obj = Wide25Codec.decode(r);
        specodec::JsonWriter w;
        Wide25Codec.encode(w, obj);
        writeFile(outDir + "/Wide25.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Wide25 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Wide25 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Wide25.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Wide25Codec.decode(r);
        specodec::JsonWriter w;
        Wide25Codec.encode(w, obj);
        writeFile(outDir + "/Wide25.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Wide25 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Wide25 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Wide25.gron");
        specodec::GronReader r(data);
        auto obj = Wide25Codec.decode(r);
        specodec::GronWriter w;
        Wide25Codec.encode(w, obj);
        writeFile(outDir + "/Wide25.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Wide25 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Wide25 gron" << std::endl; }
}

void testModelWide30(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Wide30.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Wide30Codec.decode(r);
        specodec::MsgPackWriter w;
        Wide30Codec.encode(w, obj);
        writeFile(outDir + "/Wide30.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Wide30 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Wide30 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Wide30.json");
        specodec::JsonReader r(data);
        auto obj = Wide30Codec.decode(r);
        specodec::JsonWriter w;
        Wide30Codec.encode(w, obj);
        writeFile(outDir + "/Wide30.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Wide30 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Wide30 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Wide30.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Wide30Codec.decode(r);
        specodec::JsonWriter w;
        Wide30Codec.encode(w, obj);
        writeFile(outDir + "/Wide30.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Wide30 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Wide30 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Wide30.gron");
        specodec::GronReader r(data);
        auto obj = Wide30Codec.decode(r);
        specodec::GronWriter w;
        Wide30Codec.encode(w, obj);
        writeFile(outDir + "/Wide30.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Wide30 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Wide30 gron" << std::endl; }
}

void testModelWide35(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Wide35.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Wide35Codec.decode(r);
        specodec::MsgPackWriter w;
        Wide35Codec.encode(w, obj);
        writeFile(outDir + "/Wide35.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Wide35 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Wide35 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Wide35.json");
        specodec::JsonReader r(data);
        auto obj = Wide35Codec.decode(r);
        specodec::JsonWriter w;
        Wide35Codec.encode(w, obj);
        writeFile(outDir + "/Wide35.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Wide35 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Wide35 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Wide35.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Wide35Codec.decode(r);
        specodec::JsonWriter w;
        Wide35Codec.encode(w, obj);
        writeFile(outDir + "/Wide35.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Wide35 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Wide35 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Wide35.gron");
        specodec::GronReader r(data);
        auto obj = Wide35Codec.decode(r);
        specodec::GronWriter w;
        Wide35Codec.encode(w, obj);
        writeFile(outDir + "/Wide35.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Wide35 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Wide35 gron" << std::endl; }
}

void testModelWide40(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Wide40.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Wide40Codec.decode(r);
        specodec::MsgPackWriter w;
        Wide40Codec.encode(w, obj);
        writeFile(outDir + "/Wide40.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Wide40 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Wide40 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Wide40.json");
        specodec::JsonReader r(data);
        auto obj = Wide40Codec.decode(r);
        specodec::JsonWriter w;
        Wide40Codec.encode(w, obj);
        writeFile(outDir + "/Wide40.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Wide40 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Wide40 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Wide40.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Wide40Codec.decode(r);
        specodec::JsonWriter w;
        Wide40Codec.encode(w, obj);
        writeFile(outDir + "/Wide40.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Wide40 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Wide40 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Wide40.gron");
        specodec::GronReader r(data);
        auto obj = Wide40Codec.decode(r);
        specodec::GronWriter w;
        Wide40Codec.encode(w, obj);
        writeFile(outDir + "/Wide40.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Wide40 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Wide40 gron" << std::endl; }
}


export void runAlltypes_wide(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    testModelWide20(passed, failed, vecDir, outDir);
    testModelWide25(passed, failed, vecDir, outDir);
    testModelWide30(passed, failed, vecDir, outDir);
    testModelWide35(passed, failed, vecDir, outDir);
    testModelWide40(passed, failed, vecDir, outDir);

}
