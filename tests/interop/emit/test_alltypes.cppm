module;
#include <cstdlib>
#include <fstream>
#include <filesystem>
export module test_alltypes;
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


void testModelOptInner(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptInner.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptInnerCodec.decode(r);
        specodec::MsgPackWriter w;
        OptInnerCodec.encode(w, obj);
        writeFile(outDir + "/OptInner.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptInner mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptInner mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptInner.json");
        specodec::JsonReader r(data);
        auto obj = OptInnerCodec.decode(r);
        specodec::JsonWriter w;
        OptInnerCodec.encode(w, obj);
        writeFile(outDir + "/OptInner.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptInner json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptInner json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptInner.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptInnerCodec.decode(r);
        specodec::JsonWriter w;
        OptInnerCodec.encode(w, obj);
        writeFile(outDir + "/OptInner.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptInner unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptInner unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptInner.gron");
        specodec::GronReader r(data);
        auto obj = OptInnerCodec.decode(r);
        specodec::GronWriter w;
        OptInnerCodec.encode(w, obj);
        writeFile(outDir + "/OptInner.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptInner gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptInner gron" << std::endl; }
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

void testModelEnumOptHolder(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/EnumOptHolder.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = EnumOptHolderCodec.decode(r);
        specodec::MsgPackWriter w;
        EnumOptHolderCodec.encode(w, obj);
        writeFile(outDir + "/EnumOptHolder.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL EnumOptHolder mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL EnumOptHolder mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/EnumOptHolder.json");
        specodec::JsonReader r(data);
        auto obj = EnumOptHolderCodec.decode(r);
        specodec::JsonWriter w;
        EnumOptHolderCodec.encode(w, obj);
        writeFile(outDir + "/EnumOptHolder.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL EnumOptHolder json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL EnumOptHolder json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/EnumOptHolder.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = EnumOptHolderCodec.decode(r);
        specodec::JsonWriter w;
        EnumOptHolderCodec.encode(w, obj);
        writeFile(outDir + "/EnumOptHolder.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL EnumOptHolder unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL EnumOptHolder unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/EnumOptHolder.gron");
        specodec::GronReader r(data);
        auto obj = EnumOptHolderCodec.decode(r);
        specodec::GronWriter w;
        EnumOptHolderCodec.encode(w, obj);
        writeFile(outDir + "/EnumOptHolder.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL EnumOptHolder gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL EnumOptHolder gron" << std::endl; }
}

void testModelEnumArrHolder(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/EnumArrHolder.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = EnumArrHolderCodec.decode(r);
        specodec::MsgPackWriter w;
        EnumArrHolderCodec.encode(w, obj);
        writeFile(outDir + "/EnumArrHolder.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL EnumArrHolder mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL EnumArrHolder mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/EnumArrHolder.json");
        specodec::JsonReader r(data);
        auto obj = EnumArrHolderCodec.decode(r);
        specodec::JsonWriter w;
        EnumArrHolderCodec.encode(w, obj);
        writeFile(outDir + "/EnumArrHolder.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL EnumArrHolder json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL EnumArrHolder json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/EnumArrHolder.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = EnumArrHolderCodec.decode(r);
        specodec::JsonWriter w;
        EnumArrHolderCodec.encode(w, obj);
        writeFile(outDir + "/EnumArrHolder.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL EnumArrHolder unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL EnumArrHolder unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/EnumArrHolder.gron");
        specodec::GronReader r(data);
        auto obj = EnumArrHolderCodec.decode(r);
        specodec::GronWriter w;
        EnumArrHolderCodec.encode(w, obj);
        writeFile(outDir + "/EnumArrHolder.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL EnumArrHolder gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL EnumArrHolder gron" << std::endl; }
}

void testModelNestedEnumHolder(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/NestedEnumHolder.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = NestedEnumHolderCodec.decode(r);
        specodec::MsgPackWriter w;
        NestedEnumHolderCodec.encode(w, obj);
        writeFile(outDir + "/NestedEnumHolder.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestedEnumHolder mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestedEnumHolder mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/NestedEnumHolder.json");
        specodec::JsonReader r(data);
        auto obj = NestedEnumHolderCodec.decode(r);
        specodec::JsonWriter w;
        NestedEnumHolderCodec.encode(w, obj);
        writeFile(outDir + "/NestedEnumHolder.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestedEnumHolder json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestedEnumHolder json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/NestedEnumHolder.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = NestedEnumHolderCodec.decode(r);
        specodec::JsonWriter w;
        NestedEnumHolderCodec.encode(w, obj);
        writeFile(outDir + "/NestedEnumHolder.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestedEnumHolder unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestedEnumHolder unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/NestedEnumHolder.gron");
        specodec::GronReader r(data);
        auto obj = NestedEnumHolderCodec.decode(r);
        specodec::GronWriter w;
        NestedEnumHolderCodec.encode(w, obj);
        writeFile(outDir + "/NestedEnumHolder.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestedEnumHolder gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestedEnumHolder gron" << std::endl; }
}


export void runAlltypes(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    testModelOptInner(passed, failed, vecDir, outDir);
    testModelEnumHolder(passed, failed, vecDir, outDir);
    testModelEnumOptHolder(passed, failed, vecDir, outDir);
    testModelEnumArrHolder(passed, failed, vecDir, outDir);
    testModelNestedEnumHolder(passed, failed, vecDir, outDir);

}
