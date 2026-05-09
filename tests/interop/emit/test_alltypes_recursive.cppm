module;
#include <cstdlib>
#include <fstream>
#include <filesystem>
export module test_alltypes_recursive;
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


void testModelRecList(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/RecList.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = RecListCodec.decode(r);
        specodec::MsgPackWriter w;
        RecListCodec.encode(w, obj);
        writeFile(outDir + "/RecList.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL RecList mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL RecList mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/RecList.json");
        specodec::JsonReader r(data);
        auto obj = RecListCodec.decode(r);
        specodec::JsonWriter w;
        RecListCodec.encode(w, obj);
        writeFile(outDir + "/RecList.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL RecList json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL RecList json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/RecList.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = RecListCodec.decode(r);
        specodec::JsonWriter w;
        RecListCodec.encode(w, obj);
        writeFile(outDir + "/RecList.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL RecList unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL RecList unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/RecList.gron");
        specodec::GronReader r(data);
        auto obj = RecListCodec.decode(r);
        specodec::GronWriter w;
        RecListCodec.encode(w, obj);
        writeFile(outDir + "/RecList.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL RecList gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL RecList gron" << std::endl; }
}

void testModelRecTree(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/RecTree.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = RecTreeCodec.decode(r);
        specodec::MsgPackWriter w;
        RecTreeCodec.encode(w, obj);
        writeFile(outDir + "/RecTree.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL RecTree mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL RecTree mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/RecTree.json");
        specodec::JsonReader r(data);
        auto obj = RecTreeCodec.decode(r);
        specodec::JsonWriter w;
        RecTreeCodec.encode(w, obj);
        writeFile(outDir + "/RecTree.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL RecTree json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL RecTree json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/RecTree.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = RecTreeCodec.decode(r);
        specodec::JsonWriter w;
        RecTreeCodec.encode(w, obj);
        writeFile(outDir + "/RecTree.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL RecTree unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL RecTree unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/RecTree.gron");
        specodec::GronReader r(data);
        auto obj = RecTreeCodec.decode(r);
        specodec::GronWriter w;
        RecTreeCodec.encode(w, obj);
        writeFile(outDir + "/RecTree.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL RecTree gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL RecTree gron" << std::endl; }
}

void testModelRecChain(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/RecChain.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = RecChainCodec.decode(r);
        specodec::MsgPackWriter w;
        RecChainCodec.encode(w, obj);
        writeFile(outDir + "/RecChain.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL RecChain mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL RecChain mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/RecChain.json");
        specodec::JsonReader r(data);
        auto obj = RecChainCodec.decode(r);
        specodec::JsonWriter w;
        RecChainCodec.encode(w, obj);
        writeFile(outDir + "/RecChain.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL RecChain json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL RecChain json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/RecChain.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = RecChainCodec.decode(r);
        specodec::JsonWriter w;
        RecChainCodec.encode(w, obj);
        writeFile(outDir + "/RecChain.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL RecChain unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL RecChain unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/RecChain.gron");
        specodec::GronReader r(data);
        auto obj = RecChainCodec.decode(r);
        specodec::GronWriter w;
        RecChainCodec.encode(w, obj);
        writeFile(outDir + "/RecChain.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL RecChain gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL RecChain gron" << std::endl; }
}

void testModelRecWrap(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/RecWrap.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = RecWrapCodec.decode(r);
        specodec::MsgPackWriter w;
        RecWrapCodec.encode(w, obj);
        writeFile(outDir + "/RecWrap.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL RecWrap mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL RecWrap mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/RecWrap.json");
        specodec::JsonReader r(data);
        auto obj = RecWrapCodec.decode(r);
        specodec::JsonWriter w;
        RecWrapCodec.encode(w, obj);
        writeFile(outDir + "/RecWrap.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL RecWrap json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL RecWrap json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/RecWrap.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = RecWrapCodec.decode(r);
        specodec::JsonWriter w;
        RecWrapCodec.encode(w, obj);
        writeFile(outDir + "/RecWrap.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL RecWrap unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL RecWrap unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/RecWrap.gron");
        specodec::GronReader r(data);
        auto obj = RecWrapCodec.decode(r);
        specodec::GronWriter w;
        RecWrapCodec.encode(w, obj);
        writeFile(outDir + "/RecWrap.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL RecWrap gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL RecWrap gron" << std::endl; }
}

void testModelRecWide(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/RecWide.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = RecWideCodec.decode(r);
        specodec::MsgPackWriter w;
        RecWideCodec.encode(w, obj);
        writeFile(outDir + "/RecWide.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL RecWide mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL RecWide mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/RecWide.json");
        specodec::JsonReader r(data);
        auto obj = RecWideCodec.decode(r);
        specodec::JsonWriter w;
        RecWideCodec.encode(w, obj);
        writeFile(outDir + "/RecWide.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL RecWide json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL RecWide json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/RecWide.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = RecWideCodec.decode(r);
        specodec::JsonWriter w;
        RecWideCodec.encode(w, obj);
        writeFile(outDir + "/RecWide.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL RecWide unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL RecWide unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/RecWide.gron");
        specodec::GronReader r(data);
        auto obj = RecWideCodec.decode(r);
        specodec::GronWriter w;
        RecWideCodec.encode(w, obj);
        writeFile(outDir + "/RecWide.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL RecWide gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL RecWide gron" << std::endl; }
}


export void runAlltypes_recursive(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    testModelRecList(passed, failed, vecDir, outDir);
    testModelRecTree(passed, failed, vecDir, outDir);
    testModelRecChain(passed, failed, vecDir, outDir);
    testModelRecWrap(passed, failed, vecDir, outDir);
    testModelRecWide(passed, failed, vecDir, outDir);

}
