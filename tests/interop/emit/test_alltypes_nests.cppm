module;
#include <cstdlib>
#include <fstream>
#include <filesystem>
export module test_alltypes_nests;
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


void testModelNestInner(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/NestInner.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = NestInnerCodec.decode(r);
        specodec::MsgPackWriter w;
        NestInnerCodec.encode(w, obj);
        writeFile(outDir + "/NestInner.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestInner mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestInner mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/NestInner.json");
        specodec::JsonReader r(data);
        auto obj = NestInnerCodec.decode(r);
        specodec::JsonWriter w;
        NestInnerCodec.encode(w, obj);
        writeFile(outDir + "/NestInner.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestInner json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestInner json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/NestInner.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = NestInnerCodec.decode(r);
        specodec::JsonWriter w;
        NestInnerCodec.encode(w, obj);
        writeFile(outDir + "/NestInner.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestInner unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestInner unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/NestInner.gron");
        specodec::GronReader r(data);
        auto obj = NestInnerCodec.decode(r);
        specodec::GronWriter w;
        NestInnerCodec.encode(w, obj);
        writeFile(outDir + "/NestInner.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestInner gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestInner gron" << std::endl; }
}

void testModelNestCoord(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/NestCoord.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = NestCoordCodec.decode(r);
        specodec::MsgPackWriter w;
        NestCoordCodec.encode(w, obj);
        writeFile(outDir + "/NestCoord.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestCoord mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestCoord mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/NestCoord.json");
        specodec::JsonReader r(data);
        auto obj = NestCoordCodec.decode(r);
        specodec::JsonWriter w;
        NestCoordCodec.encode(w, obj);
        writeFile(outDir + "/NestCoord.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestCoord json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestCoord json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/NestCoord.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = NestCoordCodec.decode(r);
        specodec::JsonWriter w;
        NestCoordCodec.encode(w, obj);
        writeFile(outDir + "/NestCoord.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestCoord unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestCoord unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/NestCoord.gron");
        specodec::GronReader r(data);
        auto obj = NestCoordCodec.decode(r);
        specodec::GronWriter w;
        NestCoordCodec.encode(w, obj);
        writeFile(outDir + "/NestCoord.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestCoord gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestCoord gron" << std::endl; }
}

void testModelNestIdVal(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/NestIdVal.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = NestIdValCodec.decode(r);
        specodec::MsgPackWriter w;
        NestIdValCodec.encode(w, obj);
        writeFile(outDir + "/NestIdVal.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestIdVal mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestIdVal mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/NestIdVal.json");
        specodec::JsonReader r(data);
        auto obj = NestIdValCodec.decode(r);
        specodec::JsonWriter w;
        NestIdValCodec.encode(w, obj);
        writeFile(outDir + "/NestIdVal.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestIdVal json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestIdVal json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/NestIdVal.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = NestIdValCodec.decode(r);
        specodec::JsonWriter w;
        NestIdValCodec.encode(w, obj);
        writeFile(outDir + "/NestIdVal.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestIdVal unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestIdVal unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/NestIdVal.gron");
        specodec::GronReader r(data);
        auto obj = NestIdValCodec.decode(r);
        specodec::GronWriter w;
        NestIdValCodec.encode(w, obj);
        writeFile(outDir + "/NestIdVal.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestIdVal gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestIdVal gron" << std::endl; }
}

void testModelNestLabel(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/NestLabel.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = NestLabelCodec.decode(r);
        specodec::MsgPackWriter w;
        NestLabelCodec.encode(w, obj);
        writeFile(outDir + "/NestLabel.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestLabel mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestLabel mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/NestLabel.json");
        specodec::JsonReader r(data);
        auto obj = NestLabelCodec.decode(r);
        specodec::JsonWriter w;
        NestLabelCodec.encode(w, obj);
        writeFile(outDir + "/NestLabel.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestLabel json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestLabel json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/NestLabel.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = NestLabelCodec.decode(r);
        specodec::JsonWriter w;
        NestLabelCodec.encode(w, obj);
        writeFile(outDir + "/NestLabel.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestLabel unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestLabel unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/NestLabel.gron");
        specodec::GronReader r(data);
        auto obj = NestLabelCodec.decode(r);
        specodec::GronWriter w;
        NestLabelCodec.encode(w, obj);
        writeFile(outDir + "/NestLabel.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestLabel gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestLabel gron" << std::endl; }
}

void testModelNestMoney(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/NestMoney.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = NestMoneyCodec.decode(r);
        specodec::MsgPackWriter w;
        NestMoneyCodec.encode(w, obj);
        writeFile(outDir + "/NestMoney.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestMoney mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestMoney mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/NestMoney.json");
        specodec::JsonReader r(data);
        auto obj = NestMoneyCodec.decode(r);
        specodec::JsonWriter w;
        NestMoneyCodec.encode(w, obj);
        writeFile(outDir + "/NestMoney.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestMoney json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestMoney json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/NestMoney.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = NestMoneyCodec.decode(r);
        specodec::JsonWriter w;
        NestMoneyCodec.encode(w, obj);
        writeFile(outDir + "/NestMoney.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestMoney unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestMoney unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/NestMoney.gron");
        specodec::GronReader r(data);
        auto obj = NestMoneyCodec.decode(r);
        specodec::GronWriter w;
        NestMoneyCodec.encode(w, obj);
        writeFile(outDir + "/NestMoney.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestMoney gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestMoney gron" << std::endl; }
}

void testModelNestRange32(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/NestRange32.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = NestRange32Codec.decode(r);
        specodec::MsgPackWriter w;
        NestRange32Codec.encode(w, obj);
        writeFile(outDir + "/NestRange32.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestRange32 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestRange32 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/NestRange32.json");
        specodec::JsonReader r(data);
        auto obj = NestRange32Codec.decode(r);
        specodec::JsonWriter w;
        NestRange32Codec.encode(w, obj);
        writeFile(outDir + "/NestRange32.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestRange32 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestRange32 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/NestRange32.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = NestRange32Codec.decode(r);
        specodec::JsonWriter w;
        NestRange32Codec.encode(w, obj);
        writeFile(outDir + "/NestRange32.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestRange32 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestRange32 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/NestRange32.gron");
        specodec::GronReader r(data);
        auto obj = NestRange32Codec.decode(r);
        specodec::GronWriter w;
        NestRange32Codec.encode(w, obj);
        writeFile(outDir + "/NestRange32.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestRange32 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestRange32 gron" << std::endl; }
}

void testModelNestAddr(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/NestAddr.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = NestAddrCodec.decode(r);
        specodec::MsgPackWriter w;
        NestAddrCodec.encode(w, obj);
        writeFile(outDir + "/NestAddr.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestAddr mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestAddr mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/NestAddr.json");
        specodec::JsonReader r(data);
        auto obj = NestAddrCodec.decode(r);
        specodec::JsonWriter w;
        NestAddrCodec.encode(w, obj);
        writeFile(outDir + "/NestAddr.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestAddr json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestAddr json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/NestAddr.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = NestAddrCodec.decode(r);
        specodec::JsonWriter w;
        NestAddrCodec.encode(w, obj);
        writeFile(outDir + "/NestAddr.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestAddr unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestAddr unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/NestAddr.gron");
        specodec::GronReader r(data);
        auto obj = NestAddrCodec.decode(r);
        specodec::GronWriter w;
        NestAddrCodec.encode(w, obj);
        writeFile(outDir + "/NestAddr.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestAddr gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestAddr gron" << std::endl; }
}

void testModelNestPoint3(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/NestPoint3.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = NestPoint3Codec.decode(r);
        specodec::MsgPackWriter w;
        NestPoint3Codec.encode(w, obj);
        writeFile(outDir + "/NestPoint3.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestPoint3 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestPoint3 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/NestPoint3.json");
        specodec::JsonReader r(data);
        auto obj = NestPoint3Codec.decode(r);
        specodec::JsonWriter w;
        NestPoint3Codec.encode(w, obj);
        writeFile(outDir + "/NestPoint3.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestPoint3 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestPoint3 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/NestPoint3.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = NestPoint3Codec.decode(r);
        specodec::JsonWriter w;
        NestPoint3Codec.encode(w, obj);
        writeFile(outDir + "/NestPoint3.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestPoint3 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestPoint3 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/NestPoint3.gron");
        specodec::GronReader r(data);
        auto obj = NestPoint3Codec.decode(r);
        specodec::GronWriter w;
        NestPoint3Codec.encode(w, obj);
        writeFile(outDir + "/NestPoint3.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestPoint3 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestPoint3 gron" << std::endl; }
}

void testModelOptNestInner(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptNestInner.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptNestInnerCodec.decode(r);
        specodec::MsgPackWriter w;
        OptNestInnerCodec.encode(w, obj);
        writeFile(outDir + "/OptNestInner.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptNestInner mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptNestInner mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptNestInner.json");
        specodec::JsonReader r(data);
        auto obj = OptNestInnerCodec.decode(r);
        specodec::JsonWriter w;
        OptNestInnerCodec.encode(w, obj);
        writeFile(outDir + "/OptNestInner.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptNestInner json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptNestInner json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptNestInner.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptNestInnerCodec.decode(r);
        specodec::JsonWriter w;
        OptNestInnerCodec.encode(w, obj);
        writeFile(outDir + "/OptNestInner.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptNestInner unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptNestInner unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptNestInner.gron");
        specodec::GronReader r(data);
        auto obj = OptNestInnerCodec.decode(r);
        specodec::GronWriter w;
        OptNestInnerCodec.encode(w, obj);
        writeFile(outDir + "/OptNestInner.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptNestInner gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptNestInner gron" << std::endl; }
}

void testModelOptNestCoord(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptNestCoord.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptNestCoordCodec.decode(r);
        specodec::MsgPackWriter w;
        OptNestCoordCodec.encode(w, obj);
        writeFile(outDir + "/OptNestCoord.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptNestCoord mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptNestCoord mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptNestCoord.json");
        specodec::JsonReader r(data);
        auto obj = OptNestCoordCodec.decode(r);
        specodec::JsonWriter w;
        OptNestCoordCodec.encode(w, obj);
        writeFile(outDir + "/OptNestCoord.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptNestCoord json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptNestCoord json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptNestCoord.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptNestCoordCodec.decode(r);
        specodec::JsonWriter w;
        OptNestCoordCodec.encode(w, obj);
        writeFile(outDir + "/OptNestCoord.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptNestCoord unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptNestCoord unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptNestCoord.gron");
        specodec::GronReader r(data);
        auto obj = OptNestCoordCodec.decode(r);
        specodec::GronWriter w;
        OptNestCoordCodec.encode(w, obj);
        writeFile(outDir + "/OptNestCoord.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptNestCoord gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptNestCoord gron" << std::endl; }
}

void testModelOptNestIdVal(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptNestIdVal.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptNestIdValCodec.decode(r);
        specodec::MsgPackWriter w;
        OptNestIdValCodec.encode(w, obj);
        writeFile(outDir + "/OptNestIdVal.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptNestIdVal mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptNestIdVal mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptNestIdVal.json");
        specodec::JsonReader r(data);
        auto obj = OptNestIdValCodec.decode(r);
        specodec::JsonWriter w;
        OptNestIdValCodec.encode(w, obj);
        writeFile(outDir + "/OptNestIdVal.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptNestIdVal json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptNestIdVal json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptNestIdVal.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptNestIdValCodec.decode(r);
        specodec::JsonWriter w;
        OptNestIdValCodec.encode(w, obj);
        writeFile(outDir + "/OptNestIdVal.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptNestIdVal unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptNestIdVal unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptNestIdVal.gron");
        specodec::GronReader r(data);
        auto obj = OptNestIdValCodec.decode(r);
        specodec::GronWriter w;
        OptNestIdValCodec.encode(w, obj);
        writeFile(outDir + "/OptNestIdVal.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptNestIdVal gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptNestIdVal gron" << std::endl; }
}

void testModelOptNestLabel(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptNestLabel.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptNestLabelCodec.decode(r);
        specodec::MsgPackWriter w;
        OptNestLabelCodec.encode(w, obj);
        writeFile(outDir + "/OptNestLabel.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptNestLabel mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptNestLabel mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptNestLabel.json");
        specodec::JsonReader r(data);
        auto obj = OptNestLabelCodec.decode(r);
        specodec::JsonWriter w;
        OptNestLabelCodec.encode(w, obj);
        writeFile(outDir + "/OptNestLabel.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptNestLabel json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptNestLabel json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptNestLabel.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptNestLabelCodec.decode(r);
        specodec::JsonWriter w;
        OptNestLabelCodec.encode(w, obj);
        writeFile(outDir + "/OptNestLabel.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptNestLabel unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptNestLabel unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptNestLabel.gron");
        specodec::GronReader r(data);
        auto obj = OptNestLabelCodec.decode(r);
        specodec::GronWriter w;
        OptNestLabelCodec.encode(w, obj);
        writeFile(outDir + "/OptNestLabel.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptNestLabel gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptNestLabel gron" << std::endl; }
}

void testModelOptNestMoney(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptNestMoney.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptNestMoneyCodec.decode(r);
        specodec::MsgPackWriter w;
        OptNestMoneyCodec.encode(w, obj);
        writeFile(outDir + "/OptNestMoney.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptNestMoney mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptNestMoney mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptNestMoney.json");
        specodec::JsonReader r(data);
        auto obj = OptNestMoneyCodec.decode(r);
        specodec::JsonWriter w;
        OptNestMoneyCodec.encode(w, obj);
        writeFile(outDir + "/OptNestMoney.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptNestMoney json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptNestMoney json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptNestMoney.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptNestMoneyCodec.decode(r);
        specodec::JsonWriter w;
        OptNestMoneyCodec.encode(w, obj);
        writeFile(outDir + "/OptNestMoney.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptNestMoney unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptNestMoney unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptNestMoney.gron");
        specodec::GronReader r(data);
        auto obj = OptNestMoneyCodec.decode(r);
        specodec::GronWriter w;
        OptNestMoneyCodec.encode(w, obj);
        writeFile(outDir + "/OptNestMoney.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptNestMoney gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptNestMoney gron" << std::endl; }
}

void testModelOptNestRange32(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptNestRange32.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptNestRange32Codec.decode(r);
        specodec::MsgPackWriter w;
        OptNestRange32Codec.encode(w, obj);
        writeFile(outDir + "/OptNestRange32.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptNestRange32 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptNestRange32 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptNestRange32.json");
        specodec::JsonReader r(data);
        auto obj = OptNestRange32Codec.decode(r);
        specodec::JsonWriter w;
        OptNestRange32Codec.encode(w, obj);
        writeFile(outDir + "/OptNestRange32.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptNestRange32 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptNestRange32 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptNestRange32.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptNestRange32Codec.decode(r);
        specodec::JsonWriter w;
        OptNestRange32Codec.encode(w, obj);
        writeFile(outDir + "/OptNestRange32.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptNestRange32 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptNestRange32 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptNestRange32.gron");
        specodec::GronReader r(data);
        auto obj = OptNestRange32Codec.decode(r);
        specodec::GronWriter w;
        OptNestRange32Codec.encode(w, obj);
        writeFile(outDir + "/OptNestRange32.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptNestRange32 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptNestRange32 gron" << std::endl; }
}

void testModelOptNestAddr(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptNestAddr.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptNestAddrCodec.decode(r);
        specodec::MsgPackWriter w;
        OptNestAddrCodec.encode(w, obj);
        writeFile(outDir + "/OptNestAddr.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptNestAddr mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptNestAddr mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptNestAddr.json");
        specodec::JsonReader r(data);
        auto obj = OptNestAddrCodec.decode(r);
        specodec::JsonWriter w;
        OptNestAddrCodec.encode(w, obj);
        writeFile(outDir + "/OptNestAddr.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptNestAddr json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptNestAddr json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptNestAddr.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptNestAddrCodec.decode(r);
        specodec::JsonWriter w;
        OptNestAddrCodec.encode(w, obj);
        writeFile(outDir + "/OptNestAddr.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptNestAddr unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptNestAddr unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptNestAddr.gron");
        specodec::GronReader r(data);
        auto obj = OptNestAddrCodec.decode(r);
        specodec::GronWriter w;
        OptNestAddrCodec.encode(w, obj);
        writeFile(outDir + "/OptNestAddr.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptNestAddr gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptNestAddr gron" << std::endl; }
}

void testModelOptNestPoint3(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptNestPoint3.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptNestPoint3Codec.decode(r);
        specodec::MsgPackWriter w;
        OptNestPoint3Codec.encode(w, obj);
        writeFile(outDir + "/OptNestPoint3.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptNestPoint3 mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptNestPoint3 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptNestPoint3.json");
        specodec::JsonReader r(data);
        auto obj = OptNestPoint3Codec.decode(r);
        specodec::JsonWriter w;
        OptNestPoint3Codec.encode(w, obj);
        writeFile(outDir + "/OptNestPoint3.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptNestPoint3 json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptNestPoint3 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptNestPoint3.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptNestPoint3Codec.decode(r);
        specodec::JsonWriter w;
        OptNestPoint3Codec.encode(w, obj);
        writeFile(outDir + "/OptNestPoint3.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptNestPoint3 unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptNestPoint3 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptNestPoint3.gron");
        specodec::GronReader r(data);
        auto obj = OptNestPoint3Codec.decode(r);
        specodec::GronWriter w;
        OptNestPoint3Codec.encode(w, obj);
        writeFile(outDir + "/OptNestPoint3.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptNestPoint3 gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptNestPoint3 gron" << std::endl; }
}


export void runAlltypes_nests(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    testModelNestInner(passed, failed, vecDir, outDir);
    testModelNestCoord(passed, failed, vecDir, outDir);
    testModelNestIdVal(passed, failed, vecDir, outDir);
    testModelNestLabel(passed, failed, vecDir, outDir);
    testModelNestMoney(passed, failed, vecDir, outDir);
    testModelNestRange32(passed, failed, vecDir, outDir);
    testModelNestAddr(passed, failed, vecDir, outDir);
    testModelNestPoint3(passed, failed, vecDir, outDir);
    testModelOptNestInner(passed, failed, vecDir, outDir);
    testModelOptNestCoord(passed, failed, vecDir, outDir);
    testModelOptNestIdVal(passed, failed, vecDir, outDir);
    testModelOptNestLabel(passed, failed, vecDir, outDir);
    testModelOptNestMoney(passed, failed, vecDir, outDir);
    testModelOptNestRange32(passed, failed, vecDir, outDir);
    testModelOptNestAddr(passed, failed, vecDir, outDir);
    testModelOptNestPoint3(passed, failed, vecDir, outDir);

}
