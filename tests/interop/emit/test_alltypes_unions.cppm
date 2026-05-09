module;
#include <cstdlib>
#include <fstream>
#include <filesystem>
export module test_alltypes_unions;
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


void testModelShape_circle(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Shape_circle.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = ShapeCodec.decode(r);
        specodec::MsgPackWriter w;
        ShapeCodec.encode(w, obj);
        writeFile(outDir + "/Shape_circle.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Shape_circle mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Shape_circle mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Shape_circle.json");
        specodec::JsonReader r(data);
        auto obj = ShapeCodec.decode(r);
        specodec::JsonWriter w;
        ShapeCodec.encode(w, obj);
        writeFile(outDir + "/Shape_circle.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Shape_circle json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Shape_circle json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Shape_circle.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = ShapeCodec.decode(r);
        specodec::JsonWriter w;
        ShapeCodec.encode(w, obj);
        writeFile(outDir + "/Shape_circle.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Shape_circle unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Shape_circle unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Shape_circle.gron");
        specodec::GronReader r(data);
        auto obj = ShapeCodec.decode(r);
        specodec::GronWriter w;
        ShapeCodec.encode(w, obj);
        writeFile(outDir + "/Shape_circle.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Shape_circle gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Shape_circle gron" << std::endl; }
}

void testModelShape_rect(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Shape_rect.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = ShapeCodec.decode(r);
        specodec::MsgPackWriter w;
        ShapeCodec.encode(w, obj);
        writeFile(outDir + "/Shape_rect.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Shape_rect mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Shape_rect mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Shape_rect.json");
        specodec::JsonReader r(data);
        auto obj = ShapeCodec.decode(r);
        specodec::JsonWriter w;
        ShapeCodec.encode(w, obj);
        writeFile(outDir + "/Shape_rect.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Shape_rect json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Shape_rect json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Shape_rect.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = ShapeCodec.decode(r);
        specodec::JsonWriter w;
        ShapeCodec.encode(w, obj);
        writeFile(outDir + "/Shape_rect.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Shape_rect unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Shape_rect unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Shape_rect.gron");
        specodec::GronReader r(data);
        auto obj = ShapeCodec.decode(r);
        specodec::GronWriter w;
        ShapeCodec.encode(w, obj);
        writeFile(outDir + "/Shape_rect.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Shape_rect gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Shape_rect gron" << std::endl; }
}

void testModelIdent_name(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Ident_name.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = IdentCodec.decode(r);
        specodec::MsgPackWriter w;
        IdentCodec.encode(w, obj);
        writeFile(outDir + "/Ident_name.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Ident_name mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Ident_name mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Ident_name.json");
        specodec::JsonReader r(data);
        auto obj = IdentCodec.decode(r);
        specodec::JsonWriter w;
        IdentCodec.encode(w, obj);
        writeFile(outDir + "/Ident_name.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Ident_name json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Ident_name json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Ident_name.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = IdentCodec.decode(r);
        specodec::JsonWriter w;
        IdentCodec.encode(w, obj);
        writeFile(outDir + "/Ident_name.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Ident_name unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Ident_name unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Ident_name.gron");
        specodec::GronReader r(data);
        auto obj = IdentCodec.decode(r);
        specodec::GronWriter w;
        IdentCodec.encode(w, obj);
        writeFile(outDir + "/Ident_name.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Ident_name gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Ident_name gron" << std::endl; }
}

void testModelIdent_number(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Ident_number.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = IdentCodec.decode(r);
        specodec::MsgPackWriter w;
        IdentCodec.encode(w, obj);
        writeFile(outDir + "/Ident_number.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Ident_number mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Ident_number mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Ident_number.json");
        specodec::JsonReader r(data);
        auto obj = IdentCodec.decode(r);
        specodec::JsonWriter w;
        IdentCodec.encode(w, obj);
        writeFile(outDir + "/Ident_number.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Ident_number json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Ident_number json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Ident_number.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = IdentCodec.decode(r);
        specodec::JsonWriter w;
        IdentCodec.encode(w, obj);
        writeFile(outDir + "/Ident_number.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Ident_number unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Ident_number unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Ident_number.gron");
        specodec::GronReader r(data);
        auto obj = IdentCodec.decode(r);
        specodec::GronWriter w;
        IdentCodec.encode(w, obj);
        writeFile(outDir + "/Ident_number.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Ident_number gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Ident_number gron" << std::endl; }
}

void testModelResultMsg_ok(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/ResultMsg_ok.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = ResultMsgCodec.decode(r);
        specodec::MsgPackWriter w;
        ResultMsgCodec.encode(w, obj);
        writeFile(outDir + "/ResultMsg_ok.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ResultMsg_ok mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ResultMsg_ok mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/ResultMsg_ok.json");
        specodec::JsonReader r(data);
        auto obj = ResultMsgCodec.decode(r);
        specodec::JsonWriter w;
        ResultMsgCodec.encode(w, obj);
        writeFile(outDir + "/ResultMsg_ok.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ResultMsg_ok json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ResultMsg_ok json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/ResultMsg_ok.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = ResultMsgCodec.decode(r);
        specodec::JsonWriter w;
        ResultMsgCodec.encode(w, obj);
        writeFile(outDir + "/ResultMsg_ok.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ResultMsg_ok unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ResultMsg_ok unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/ResultMsg_ok.gron");
        specodec::GronReader r(data);
        auto obj = ResultMsgCodec.decode(r);
        specodec::GronWriter w;
        ResultMsgCodec.encode(w, obj);
        writeFile(outDir + "/ResultMsg_ok.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ResultMsg_ok gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ResultMsg_ok gron" << std::endl; }
}

void testModelResultMsg_err(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/ResultMsg_err.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = ResultMsgCodec.decode(r);
        specodec::MsgPackWriter w;
        ResultMsgCodec.encode(w, obj);
        writeFile(outDir + "/ResultMsg_err.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ResultMsg_err mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ResultMsg_err mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/ResultMsg_err.json");
        specodec::JsonReader r(data);
        auto obj = ResultMsgCodec.decode(r);
        specodec::JsonWriter w;
        ResultMsgCodec.encode(w, obj);
        writeFile(outDir + "/ResultMsg_err.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ResultMsg_err json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ResultMsg_err json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/ResultMsg_err.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = ResultMsgCodec.decode(r);
        specodec::JsonWriter w;
        ResultMsgCodec.encode(w, obj);
        writeFile(outDir + "/ResultMsg_err.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ResultMsg_err unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ResultMsg_err unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/ResultMsg_err.gron");
        specodec::GronReader r(data);
        auto obj = ResultMsgCodec.decode(r);
        specodec::GronWriter w;
        ResultMsgCodec.encode(w, obj);
        writeFile(outDir + "/ResultMsg_err.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ResultMsg_err gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ResultMsg_err gron" << std::endl; }
}

void testModelTagged_tag(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Tagged_tag.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = TaggedCodec.decode(r);
        specodec::MsgPackWriter w;
        TaggedCodec.encode(w, obj);
        writeFile(outDir + "/Tagged_tag.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Tagged_tag mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Tagged_tag mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Tagged_tag.json");
        specodec::JsonReader r(data);
        auto obj = TaggedCodec.decode(r);
        specodec::JsonWriter w;
        TaggedCodec.encode(w, obj);
        writeFile(outDir + "/Tagged_tag.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Tagged_tag json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Tagged_tag json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Tagged_tag.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = TaggedCodec.decode(r);
        specodec::JsonWriter w;
        TaggedCodec.encode(w, obj);
        writeFile(outDir + "/Tagged_tag.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Tagged_tag unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Tagged_tag unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Tagged_tag.gron");
        specodec::GronReader r(data);
        auto obj = TaggedCodec.decode(r);
        specodec::GronWriter w;
        TaggedCodec.encode(w, obj);
        writeFile(outDir + "/Tagged_tag.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Tagged_tag gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Tagged_tag gron" << std::endl; }
}

void testModelTagged_score(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Tagged_score.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = TaggedCodec.decode(r);
        specodec::MsgPackWriter w;
        TaggedCodec.encode(w, obj);
        writeFile(outDir + "/Tagged_score.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Tagged_score mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Tagged_score mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Tagged_score.json");
        specodec::JsonReader r(data);
        auto obj = TaggedCodec.decode(r);
        specodec::JsonWriter w;
        TaggedCodec.encode(w, obj);
        writeFile(outDir + "/Tagged_score.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Tagged_score json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Tagged_score json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Tagged_score.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = TaggedCodec.decode(r);
        specodec::JsonWriter w;
        TaggedCodec.encode(w, obj);
        writeFile(outDir + "/Tagged_score.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Tagged_score unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Tagged_score unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Tagged_score.gron");
        specodec::GronReader r(data);
        auto obj = TaggedCodec.decode(r);
        specodec::GronWriter w;
        TaggedCodec.encode(w, obj);
        writeFile(outDir + "/Tagged_score.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Tagged_score gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Tagged_score gron" << std::endl; }
}

void testModelTagged_active(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Tagged_active.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = TaggedCodec.decode(r);
        specodec::MsgPackWriter w;
        TaggedCodec.encode(w, obj);
        writeFile(outDir + "/Tagged_active.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Tagged_active mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Tagged_active mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Tagged_active.json");
        specodec::JsonReader r(data);
        auto obj = TaggedCodec.decode(r);
        specodec::JsonWriter w;
        TaggedCodec.encode(w, obj);
        writeFile(outDir + "/Tagged_active.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Tagged_active json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Tagged_active json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Tagged_active.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = TaggedCodec.decode(r);
        specodec::JsonWriter w;
        TaggedCodec.encode(w, obj);
        writeFile(outDir + "/Tagged_active.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Tagged_active unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Tagged_active unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Tagged_active.gron");
        specodec::GronReader r(data);
        auto obj = TaggedCodec.decode(r);
        specodec::GronWriter w;
        TaggedCodec.encode(w, obj);
        writeFile(outDir + "/Tagged_active.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL Tagged_active gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL Tagged_active gron" << std::endl; }
}

void testModelOptUnionHolder_shape(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptUnionHolder_shape.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptUnionHolderCodec.decode(r);
        specodec::MsgPackWriter w;
        OptUnionHolderCodec.encode(w, obj);
        writeFile(outDir + "/OptUnionHolder_shape.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptUnionHolder_shape mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptUnionHolder_shape mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptUnionHolder_shape.json");
        specodec::JsonReader r(data);
        auto obj = OptUnionHolderCodec.decode(r);
        specodec::JsonWriter w;
        OptUnionHolderCodec.encode(w, obj);
        writeFile(outDir + "/OptUnionHolder_shape.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptUnionHolder_shape json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptUnionHolder_shape json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptUnionHolder_shape.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptUnionHolderCodec.decode(r);
        specodec::JsonWriter w;
        OptUnionHolderCodec.encode(w, obj);
        writeFile(outDir + "/OptUnionHolder_shape.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptUnionHolder_shape unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptUnionHolder_shape unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptUnionHolder_shape.gron");
        specodec::GronReader r(data);
        auto obj = OptUnionHolderCodec.decode(r);
        specodec::GronWriter w;
        OptUnionHolderCodec.encode(w, obj);
        writeFile(outDir + "/OptUnionHolder_shape.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptUnionHolder_shape gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptUnionHolder_shape gron" << std::endl; }
}

void testModelOptUnionHolder_id(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptUnionHolder_id.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptUnionHolderCodec.decode(r);
        specodec::MsgPackWriter w;
        OptUnionHolderCodec.encode(w, obj);
        writeFile(outDir + "/OptUnionHolder_id.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptUnionHolder_id mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptUnionHolder_id mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptUnionHolder_id.json");
        specodec::JsonReader r(data);
        auto obj = OptUnionHolderCodec.decode(r);
        specodec::JsonWriter w;
        OptUnionHolderCodec.encode(w, obj);
        writeFile(outDir + "/OptUnionHolder_id.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptUnionHolder_id json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptUnionHolder_id json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptUnionHolder_id.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptUnionHolderCodec.decode(r);
        specodec::JsonWriter w;
        OptUnionHolderCodec.encode(w, obj);
        writeFile(outDir + "/OptUnionHolder_id.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptUnionHolder_id unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptUnionHolder_id unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptUnionHolder_id.gron");
        specodec::GronReader r(data);
        auto obj = OptUnionHolderCodec.decode(r);
        specodec::GronWriter w;
        OptUnionHolderCodec.encode(w, obj);
        writeFile(outDir + "/OptUnionHolder_id.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL OptUnionHolder_id gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL OptUnionHolder_id gron" << std::endl; }
}

void testModelMixedUnion_point(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/MixedUnion_point.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = MixedUnionCodec.decode(r);
        specodec::MsgPackWriter w;
        MixedUnionCodec.encode(w, obj);
        writeFile(outDir + "/MixedUnion_point.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL MixedUnion_point mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL MixedUnion_point mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/MixedUnion_point.json");
        specodec::JsonReader r(data);
        auto obj = MixedUnionCodec.decode(r);
        specodec::JsonWriter w;
        MixedUnionCodec.encode(w, obj);
        writeFile(outDir + "/MixedUnion_point.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL MixedUnion_point json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL MixedUnion_point json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/MixedUnion_point.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = MixedUnionCodec.decode(r);
        specodec::JsonWriter w;
        MixedUnionCodec.encode(w, obj);
        writeFile(outDir + "/MixedUnion_point.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL MixedUnion_point unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL MixedUnion_point unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/MixedUnion_point.gron");
        specodec::GronReader r(data);
        auto obj = MixedUnionCodec.decode(r);
        specodec::GronWriter w;
        MixedUnionCodec.encode(w, obj);
        writeFile(outDir + "/MixedUnion_point.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL MixedUnion_point gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL MixedUnion_point gron" << std::endl; }
}

void testModelMixedUnion_label(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/MixedUnion_label.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = MixedUnionCodec.decode(r);
        specodec::MsgPackWriter w;
        MixedUnionCodec.encode(w, obj);
        writeFile(outDir + "/MixedUnion_label.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL MixedUnion_label mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL MixedUnion_label mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/MixedUnion_label.json");
        specodec::JsonReader r(data);
        auto obj = MixedUnionCodec.decode(r);
        specodec::JsonWriter w;
        MixedUnionCodec.encode(w, obj);
        writeFile(outDir + "/MixedUnion_label.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL MixedUnion_label json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL MixedUnion_label json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/MixedUnion_label.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = MixedUnionCodec.decode(r);
        specodec::JsonWriter w;
        MixedUnionCodec.encode(w, obj);
        writeFile(outDir + "/MixedUnion_label.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL MixedUnion_label unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL MixedUnion_label unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/MixedUnion_label.gron");
        specodec::GronReader r(data);
        auto obj = MixedUnionCodec.decode(r);
        specodec::GronWriter w;
        MixedUnionCodec.encode(w, obj);
        writeFile(outDir + "/MixedUnion_label.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL MixedUnion_label gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL MixedUnion_label gron" << std::endl; }
}

void testModelMixedUnion_count(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/MixedUnion_count.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = MixedUnionCodec.decode(r);
        specodec::MsgPackWriter w;
        MixedUnionCodec.encode(w, obj);
        writeFile(outDir + "/MixedUnion_count.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL MixedUnion_count mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL MixedUnion_count mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/MixedUnion_count.json");
        specodec::JsonReader r(data);
        auto obj = MixedUnionCodec.decode(r);
        specodec::JsonWriter w;
        MixedUnionCodec.encode(w, obj);
        writeFile(outDir + "/MixedUnion_count.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL MixedUnion_count json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL MixedUnion_count json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/MixedUnion_count.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = MixedUnionCodec.decode(r);
        specodec::JsonWriter w;
        MixedUnionCodec.encode(w, obj);
        writeFile(outDir + "/MixedUnion_count.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL MixedUnion_count unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL MixedUnion_count unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/MixedUnion_count.gron");
        specodec::GronReader r(data);
        auto obj = MixedUnionCodec.decode(r);
        specodec::GronWriter w;
        MixedUnionCodec.encode(w, obj);
        writeFile(outDir + "/MixedUnion_count.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL MixedUnion_count gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL MixedUnion_count gron" << std::endl; }
}

void testModelNestedUnion_result(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/NestedUnion_result.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = NestedUnionCodec.decode(r);
        specodec::MsgPackWriter w;
        NestedUnionCodec.encode(w, obj);
        writeFile(outDir + "/NestedUnion_result.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestedUnion_result mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestedUnion_result mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/NestedUnion_result.json");
        specodec::JsonReader r(data);
        auto obj = NestedUnionCodec.decode(r);
        specodec::JsonWriter w;
        NestedUnionCodec.encode(w, obj);
        writeFile(outDir + "/NestedUnion_result.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestedUnion_result json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestedUnion_result json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/NestedUnion_result.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = NestedUnionCodec.decode(r);
        specodec::JsonWriter w;
        NestedUnionCodec.encode(w, obj);
        writeFile(outDir + "/NestedUnion_result.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestedUnion_result unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestedUnion_result unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/NestedUnion_result.gron");
        specodec::GronReader r(data);
        auto obj = NestedUnionCodec.decode(r);
        specodec::GronWriter w;
        NestedUnionCodec.encode(w, obj);
        writeFile(outDir + "/NestedUnion_result.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestedUnion_result gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestedUnion_result gron" << std::endl; }
}

void testModelNestedUnion_shape(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/NestedUnion_shape.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = NestedUnionCodec.decode(r);
        specodec::MsgPackWriter w;
        NestedUnionCodec.encode(w, obj);
        writeFile(outDir + "/NestedUnion_shape.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestedUnion_shape mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestedUnion_shape mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/NestedUnion_shape.json");
        specodec::JsonReader r(data);
        auto obj = NestedUnionCodec.decode(r);
        specodec::JsonWriter w;
        NestedUnionCodec.encode(w, obj);
        writeFile(outDir + "/NestedUnion_shape.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestedUnion_shape json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestedUnion_shape json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/NestedUnion_shape.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = NestedUnionCodec.decode(r);
        specodec::JsonWriter w;
        NestedUnionCodec.encode(w, obj);
        writeFile(outDir + "/NestedUnion_shape.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestedUnion_shape unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestedUnion_shape unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/NestedUnion_shape.gron");
        specodec::GronReader r(data);
        auto obj = NestedUnionCodec.decode(r);
        specodec::GronWriter w;
        NestedUnionCodec.encode(w, obj);
        writeFile(outDir + "/NestedUnion_shape.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL NestedUnion_shape gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL NestedUnion_shape gron" << std::endl; }
}

void testModelScalarUnion_s(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/ScalarUnion_s.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = ScalarUnionCodec.decode(r);
        specodec::MsgPackWriter w;
        ScalarUnionCodec.encode(w, obj);
        writeFile(outDir + "/ScalarUnion_s.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ScalarUnion_s mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ScalarUnion_s mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/ScalarUnion_s.json");
        specodec::JsonReader r(data);
        auto obj = ScalarUnionCodec.decode(r);
        specodec::JsonWriter w;
        ScalarUnionCodec.encode(w, obj);
        writeFile(outDir + "/ScalarUnion_s.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ScalarUnion_s json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ScalarUnion_s json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/ScalarUnion_s.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = ScalarUnionCodec.decode(r);
        specodec::JsonWriter w;
        ScalarUnionCodec.encode(w, obj);
        writeFile(outDir + "/ScalarUnion_s.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ScalarUnion_s unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ScalarUnion_s unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/ScalarUnion_s.gron");
        specodec::GronReader r(data);
        auto obj = ScalarUnionCodec.decode(r);
        specodec::GronWriter w;
        ScalarUnionCodec.encode(w, obj);
        writeFile(outDir + "/ScalarUnion_s.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ScalarUnion_s gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ScalarUnion_s gron" << std::endl; }
}

void testModelScalarUnion_i(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/ScalarUnion_i.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = ScalarUnionCodec.decode(r);
        specodec::MsgPackWriter w;
        ScalarUnionCodec.encode(w, obj);
        writeFile(outDir + "/ScalarUnion_i.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ScalarUnion_i mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ScalarUnion_i mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/ScalarUnion_i.json");
        specodec::JsonReader r(data);
        auto obj = ScalarUnionCodec.decode(r);
        specodec::JsonWriter w;
        ScalarUnionCodec.encode(w, obj);
        writeFile(outDir + "/ScalarUnion_i.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ScalarUnion_i json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ScalarUnion_i json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/ScalarUnion_i.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = ScalarUnionCodec.decode(r);
        specodec::JsonWriter w;
        ScalarUnionCodec.encode(w, obj);
        writeFile(outDir + "/ScalarUnion_i.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ScalarUnion_i unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ScalarUnion_i unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/ScalarUnion_i.gron");
        specodec::GronReader r(data);
        auto obj = ScalarUnionCodec.decode(r);
        specodec::GronWriter w;
        ScalarUnionCodec.encode(w, obj);
        writeFile(outDir + "/ScalarUnion_i.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ScalarUnion_i gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ScalarUnion_i gron" << std::endl; }
}

void testModelScalarUnion_f(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/ScalarUnion_f.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = ScalarUnionCodec.decode(r);
        specodec::MsgPackWriter w;
        ScalarUnionCodec.encode(w, obj);
        writeFile(outDir + "/ScalarUnion_f.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ScalarUnion_f mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ScalarUnion_f mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/ScalarUnion_f.json");
        specodec::JsonReader r(data);
        auto obj = ScalarUnionCodec.decode(r);
        specodec::JsonWriter w;
        ScalarUnionCodec.encode(w, obj);
        writeFile(outDir + "/ScalarUnion_f.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ScalarUnion_f json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ScalarUnion_f json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/ScalarUnion_f.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = ScalarUnionCodec.decode(r);
        specodec::JsonWriter w;
        ScalarUnionCodec.encode(w, obj);
        writeFile(outDir + "/ScalarUnion_f.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ScalarUnion_f unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ScalarUnion_f unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/ScalarUnion_f.gron");
        specodec::GronReader r(data);
        auto obj = ScalarUnionCodec.decode(r);
        specodec::GronWriter w;
        ScalarUnionCodec.encode(w, obj);
        writeFile(outDir + "/ScalarUnion_f.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ScalarUnion_f gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ScalarUnion_f gron" << std::endl; }
}

void testModelScalarUnion_b(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/ScalarUnion_b.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = ScalarUnionCodec.decode(r);
        specodec::MsgPackWriter w;
        ScalarUnionCodec.encode(w, obj);
        writeFile(outDir + "/ScalarUnion_b.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ScalarUnion_b mp: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ScalarUnion_b mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/ScalarUnion_b.json");
        specodec::JsonReader r(data);
        auto obj = ScalarUnionCodec.decode(r);
        specodec::JsonWriter w;
        ScalarUnionCodec.encode(w, obj);
        writeFile(outDir + "/ScalarUnion_b.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ScalarUnion_b json: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ScalarUnion_b json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/ScalarUnion_b.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = ScalarUnionCodec.decode(r);
        specodec::JsonWriter w;
        ScalarUnionCodec.encode(w, obj);
        writeFile(outDir + "/ScalarUnion_b.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ScalarUnion_b unformatted: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ScalarUnion_b unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/ScalarUnion_b.gron");
        specodec::GronReader r(data);
        auto obj = ScalarUnionCodec.decode(r);
        specodec::GronWriter w;
        ScalarUnionCodec.encode(w, obj);
        writeFile(outDir + "/ScalarUnion_b.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) { std::cout << "FAIL ScalarUnion_b gron: " << e.what() << std::endl; failed++; }
    catch (...) { failed++; std::cout << "FAIL ScalarUnion_b gron" << std::endl; }
}


export void runAlltypes_unions(int& passed, int& failed, const std::string& vecDir, const std::string& outDir) {
    testModelShape_circle(passed, failed, vecDir, outDir);
    testModelShape_rect(passed, failed, vecDir, outDir);
    testModelIdent_name(passed, failed, vecDir, outDir);
    testModelIdent_number(passed, failed, vecDir, outDir);
    testModelResultMsg_ok(passed, failed, vecDir, outDir);
    testModelResultMsg_err(passed, failed, vecDir, outDir);
    testModelTagged_tag(passed, failed, vecDir, outDir);
    testModelTagged_score(passed, failed, vecDir, outDir);
    testModelTagged_active(passed, failed, vecDir, outDir);
    testModelOptUnionHolder_shape(passed, failed, vecDir, outDir);
    testModelOptUnionHolder_id(passed, failed, vecDir, outDir);
    testModelMixedUnion_point(passed, failed, vecDir, outDir);
    testModelMixedUnion_label(passed, failed, vecDir, outDir);
    testModelMixedUnion_count(passed, failed, vecDir, outDir);
    testModelNestedUnion_result(passed, failed, vecDir, outDir);
    testModelNestedUnion_shape(passed, failed, vecDir, outDir);
    testModelScalarUnion_s(passed, failed, vecDir, outDir);
    testModelScalarUnion_i(passed, failed, vecDir, outDir);
    testModelScalarUnion_f(passed, failed, vecDir, outDir);
    testModelScalarUnion_b(passed, failed, vecDir, outDir);

}
