module;
#include <cstdlib>
#include <fstream>
#include <filesystem>
export module emit_runner;
import std;
import specodec;
import alltypes;

using namespace alltypes;

static std::string getEnv(const char* name) {
    const char* val = std::getenv(name);
    return val ? val : "";
}

const std::string vecDir = getEnv("VEC_DIR");
const std::string outDir = getEnv("OUT_DIR");

static std::vector<std::uint8_t> readFile(const std::string& path) {
    std::ifstream file(path, std::ios::binary | std::ios::ate);
    if (!file) throw std::runtime_error("cannot open file: " + path);
    std::streamsize size = file.tellg();
    file.seekg(0, std::ios::beg);
    std::vector<std::uint8_t> buffer(static_cast<std::size_t>(size));
    if (!file.read(reinterpret_cast<char*>(buffer.data()), size)) {
        throw std::runtime_error("cannot read file: " + path);
    }
    return buffer;
}

static void writeFile(const std::string& path, const std::vector<std::uint8_t>& data) {
    std::filesystem::create_directories(std::filesystem::path(path).parent_path());
    std::ofstream file(path, std::ios::binary);
    if (!file) throw std::runtime_error("cannot write file: " + path);
    file.write(reinterpret_cast<const char*>(data.data()), static_cast<std::streamsize>(data.size()));
}


void testScalarInt8_min(int& passed, int& failed) {
    try {
        auto data = readFile(vecDir + "/scalars/int8_min.mp");
        specodec::MsgPackReader r(data);
        auto value = r.readInt32();
        specodec::MsgPackWriter w;
        w.writeInt32(value);
        writeFile(outDir + "/scalars/int8_min.mp", w.toBytes());
        passed++;
    } catch (...) { failed++; std::cout << "FAIL int8_min mp" << std::endl; }
}

void testScalarInt8_max(int& passed, int& failed) {
    try {
        auto data = readFile(vecDir + "/scalars/int8_max.mp");
        specodec::MsgPackReader r(data);
        auto value = r.readInt32();
        specodec::MsgPackWriter w;
        w.writeInt32(value);
        writeFile(outDir + "/scalars/int8_max.mp", w.toBytes());
        passed++;
    } catch (...) { failed++; std::cout << "FAIL int8_max mp" << std::endl; }
}

void testScalarInt16_min(int& passed, int& failed) {
    try {
        auto data = readFile(vecDir + "/scalars/int16_min.mp");
        specodec::MsgPackReader r(data);
        auto value = r.readInt32();
        specodec::MsgPackWriter w;
        w.writeInt32(value);
        writeFile(outDir + "/scalars/int16_min.mp", w.toBytes());
        passed++;
    } catch (...) { failed++; std::cout << "FAIL int16_min mp" << std::endl; }
}

void testScalarInt16_max(int& passed, int& failed) {
    try {
        auto data = readFile(vecDir + "/scalars/int16_max.mp");
        specodec::MsgPackReader r(data);
        auto value = r.readInt32();
        specodec::MsgPackWriter w;
        w.writeInt32(value);
        writeFile(outDir + "/scalars/int16_max.mp", w.toBytes());
        passed++;
    } catch (...) { failed++; std::cout << "FAIL int16_max mp" << std::endl; }
}

void testScalarInt32_min(int& passed, int& failed) {
    try {
        auto data = readFile(vecDir + "/scalars/int32_min.mp");
        specodec::MsgPackReader r(data);
        auto value = r.readInt32();
        specodec::MsgPackWriter w;
        w.writeInt32(value);
        writeFile(outDir + "/scalars/int32_min.mp", w.toBytes());
        passed++;
    } catch (...) { failed++; std::cout << "FAIL int32_min mp" << std::endl; }
}

void testScalarInt32_max(int& passed, int& failed) {
    try {
        auto data = readFile(vecDir + "/scalars/int32_max.mp");
        specodec::MsgPackReader r(data);
        auto value = r.readInt32();
        specodec::MsgPackWriter w;
        w.writeInt32(value);
        writeFile(outDir + "/scalars/int32_max.mp", w.toBytes());
        passed++;
    } catch (...) { failed++; std::cout << "FAIL int32_max mp" << std::endl; }
}

void testScalarInt64_min(int& passed, int& failed) {
    try {
        auto data = readFile(vecDir + "/scalars/int64_min.mp");
        specodec::MsgPackReader r(data);
        auto value = r.readInt64();
        specodec::MsgPackWriter w;
        w.writeInt64(value);
        writeFile(outDir + "/scalars/int64_min.mp", w.toBytes());
        passed++;
    } catch (...) { failed++; std::cout << "FAIL int64_min mp" << std::endl; }
}

void testScalarInt64_max(int& passed, int& failed) {
    try {
        auto data = readFile(vecDir + "/scalars/int64_max.mp");
        specodec::MsgPackReader r(data);
        auto value = r.readInt64();
        specodec::MsgPackWriter w;
        w.writeInt64(value);
        writeFile(outDir + "/scalars/int64_max.mp", w.toBytes());
        passed++;
    } catch (...) { failed++; std::cout << "FAIL int64_max mp" << std::endl; }
}

void testScalarUint8_max(int& passed, int& failed) {
    try {
        auto data = readFile(vecDir + "/scalars/uint8_max.mp");
        specodec::MsgPackReader r(data);
        auto value = r.readUint32();
        specodec::MsgPackWriter w;
        w.writeUint32(value);
        writeFile(outDir + "/scalars/uint8_max.mp", w.toBytes());
        passed++;
    } catch (...) { failed++; std::cout << "FAIL uint8_max mp" << std::endl; }
}

void testScalarUint16_max(int& passed, int& failed) {
    try {
        auto data = readFile(vecDir + "/scalars/uint16_max.mp");
        specodec::MsgPackReader r(data);
        auto value = r.readUint32();
        specodec::MsgPackWriter w;
        w.writeUint32(value);
        writeFile(outDir + "/scalars/uint16_max.mp", w.toBytes());
        passed++;
    } catch (...) { failed++; std::cout << "FAIL uint16_max mp" << std::endl; }
}

void testScalarUint32_max(int& passed, int& failed) {
    try {
        auto data = readFile(vecDir + "/scalars/uint32_max.mp");
        specodec::MsgPackReader r(data);
        auto value = r.readUint32();
        specodec::MsgPackWriter w;
        w.writeUint32(value);
        writeFile(outDir + "/scalars/uint32_max.mp", w.toBytes());
        passed++;
    } catch (...) { failed++; std::cout << "FAIL uint32_max mp" << std::endl; }
}

void testScalarUint64_max(int& passed, int& failed) {
    try {
        auto data = readFile(vecDir + "/scalars/uint64_max.mp");
        specodec::MsgPackReader r(data);
        auto value = r.readUint64();
        specodec::MsgPackWriter w;
        w.writeUint64(value);
        writeFile(outDir + "/scalars/uint64_max.mp", w.toBytes());
        passed++;
    } catch (...) { failed++; std::cout << "FAIL uint64_max mp" << std::endl; }
}

void testScalarFloat32_1_5(int& passed, int& failed) {
    try {
        auto data = readFile(vecDir + "/scalars/float32_1.5.mp");
        specodec::MsgPackReader r(data);
        auto value = r.readFloat32();
        specodec::MsgPackWriter w;
        w.writeFloat32(value);
        writeFile(outDir + "/scalars/float32_1.5.mp", w.toBytes());
        passed++;
    } catch (...) { failed++; std::cout << "FAIL float32_1.5 mp" << std::endl; }
}

void testScalarFloat32_neg_zero(int& passed, int& failed) {
    try {
        auto data = readFile(vecDir + "/scalars/float32_neg_zero.mp");
        specodec::MsgPackReader r(data);
        auto value = r.readFloat32();
        specodec::MsgPackWriter w;
        w.writeFloat32(value);
        writeFile(outDir + "/scalars/float32_neg_zero.mp", w.toBytes());
        passed++;
    } catch (...) { failed++; std::cout << "FAIL float32_neg_zero mp" << std::endl; }
}

void testScalarFloat32_inf(int& passed, int& failed) {
    try {
        auto data = readFile(vecDir + "/scalars/float32_inf.mp");
        specodec::MsgPackReader r(data);
        auto value = r.readFloat32();
        specodec::MsgPackWriter w;
        w.writeFloat32(value);
        writeFile(outDir + "/scalars/float32_inf.mp", w.toBytes());
        passed++;
    } catch (...) { failed++; std::cout << "FAIL float32_inf mp" << std::endl; }
}

void testScalarFloat32_neg_inf(int& passed, int& failed) {
    try {
        auto data = readFile(vecDir + "/scalars/float32_neg_inf.mp");
        specodec::MsgPackReader r(data);
        auto value = r.readFloat32();
        specodec::MsgPackWriter w;
        w.writeFloat32(value);
        writeFile(outDir + "/scalars/float32_neg_inf.mp", w.toBytes());
        passed++;
    } catch (...) { failed++; std::cout << "FAIL float32_neg_inf mp" << std::endl; }
}

void testScalarFloat32_nan(int& passed, int& failed) {
    try {
        auto data = readFile(vecDir + "/scalars/float32_nan.mp");
        specodec::MsgPackReader r(data);
        auto value = r.readFloat32();
        specodec::MsgPackWriter w;
        w.writeFloat32(value);
        writeFile(outDir + "/scalars/float32_nan.mp", w.toBytes());
        passed++;
    } catch (...) { failed++; std::cout << "FAIL float32_nan mp" << std::endl; }
}

void testScalarFloat64_pi(int& passed, int& failed) {
    try {
        auto data = readFile(vecDir + "/scalars/float64_pi.mp");
        specodec::MsgPackReader r(data);
        auto value = r.readFloat64();
        specodec::MsgPackWriter w;
        w.writeFloat64(value);
        writeFile(outDir + "/scalars/float64_pi.mp", w.toBytes());
        passed++;
    } catch (...) { failed++; std::cout << "FAIL float64_pi mp" << std::endl; }
}

void testScalarFloat64_neg_zero(int& passed, int& failed) {
    try {
        auto data = readFile(vecDir + "/scalars/float64_neg_zero.mp");
        specodec::MsgPackReader r(data);
        auto value = r.readFloat64();
        specodec::MsgPackWriter w;
        w.writeFloat64(value);
        writeFile(outDir + "/scalars/float64_neg_zero.mp", w.toBytes());
        passed++;
    } catch (...) { failed++; std::cout << "FAIL float64_neg_zero mp" << std::endl; }
}

void testScalarFloat64_inf(int& passed, int& failed) {
    try {
        auto data = readFile(vecDir + "/scalars/float64_inf.mp");
        specodec::MsgPackReader r(data);
        auto value = r.readFloat64();
        specodec::MsgPackWriter w;
        w.writeFloat64(value);
        writeFile(outDir + "/scalars/float64_inf.mp", w.toBytes());
        passed++;
    } catch (...) { failed++; std::cout << "FAIL float64_inf mp" << std::endl; }
}

void testScalarFloat64_neg_inf(int& passed, int& failed) {
    try {
        auto data = readFile(vecDir + "/scalars/float64_neg_inf.mp");
        specodec::MsgPackReader r(data);
        auto value = r.readFloat64();
        specodec::MsgPackWriter w;
        w.writeFloat64(value);
        writeFile(outDir + "/scalars/float64_neg_inf.mp", w.toBytes());
        passed++;
    } catch (...) { failed++; std::cout << "FAIL float64_neg_inf mp" << std::endl; }
}

void testScalarFloat64_nan(int& passed, int& failed) {
    try {
        auto data = readFile(vecDir + "/scalars/float64_nan.mp");
        specodec::MsgPackReader r(data);
        auto value = r.readFloat64();
        specodec::MsgPackWriter w;
        w.writeFloat64(value);
        writeFile(outDir + "/scalars/float64_nan.mp", w.toBytes());
        passed++;
    } catch (...) { failed++; std::cout << "FAIL float64_nan mp" << std::endl; }
}

void testScalarStr_empty(int& passed, int& failed) {
    try {
        auto data = readFile(vecDir + "/scalars/str_empty.mp");
        specodec::MsgPackReader r(data);
        auto value = r.readString();
        specodec::MsgPackWriter w;
        w.writeString(value);
        writeFile(outDir + "/scalars/str_empty.mp", w.toBytes());
        passed++;
    } catch (...) { failed++; std::cout << "FAIL str_empty mp" << std::endl; }
}

void testScalarStr_ascii(int& passed, int& failed) {
    try {
        auto data = readFile(vecDir + "/scalars/str_ascii.mp");
        specodec::MsgPackReader r(data);
        auto value = r.readString();
        specodec::MsgPackWriter w;
        w.writeString(value);
        writeFile(outDir + "/scalars/str_ascii.mp", w.toBytes());
        passed++;
    } catch (...) { failed++; std::cout << "FAIL str_ascii mp" << std::endl; }
}

void testScalarStr_null_byte(int& passed, int& failed) {
    try {
        auto data = readFile(vecDir + "/scalars/str_null_byte.mp");
        specodec::MsgPackReader r(data);
        auto value = r.readString();
        specodec::MsgPackWriter w;
        w.writeString(value);
        writeFile(outDir + "/scalars/str_null_byte.mp", w.toBytes());
        passed++;
    } catch (...) { failed++; std::cout << "FAIL str_null_byte mp" << std::endl; }
}

void testScalarStr_escape(int& passed, int& failed) {
    try {
        auto data = readFile(vecDir + "/scalars/str_escape.mp");
        specodec::MsgPackReader r(data);
        auto value = r.readString();
        specodec::MsgPackWriter w;
        w.writeString(value);
        writeFile(outDir + "/scalars/str_escape.mp", w.toBytes());
        passed++;
    } catch (...) { failed++; std::cout << "FAIL str_escape mp" << std::endl; }
}

void testScalarStr_unicode(int& passed, int& failed) {
    try {
        auto data = readFile(vecDir + "/scalars/str_unicode.mp");
        specodec::MsgPackReader r(data);
        auto value = r.readString();
        specodec::MsgPackWriter w;
        w.writeString(value);
        writeFile(outDir + "/scalars/str_unicode.mp", w.toBytes());
        passed++;
    } catch (...) { failed++; std::cout << "FAIL str_unicode mp" << std::endl; }
}

void testScalarStr_31(int& passed, int& failed) {
    try {
        auto data = readFile(vecDir + "/scalars/str_31.mp");
        specodec::MsgPackReader r(data);
        auto value = r.readString();
        specodec::MsgPackWriter w;
        w.writeString(value);
        writeFile(outDir + "/scalars/str_31.mp", w.toBytes());
        passed++;
    } catch (...) { failed++; std::cout << "FAIL str_31 mp" << std::endl; }
}

void testScalarStr_32(int& passed, int& failed) {
    try {
        auto data = readFile(vecDir + "/scalars/str_32.mp");
        specodec::MsgPackReader r(data);
        auto value = r.readString();
        specodec::MsgPackWriter w;
        w.writeString(value);
        writeFile(outDir + "/scalars/str_32.mp", w.toBytes());
        passed++;
    } catch (...) { failed++; std::cout << "FAIL str_32 mp" << std::endl; }
}

void testScalarStr_255(int& passed, int& failed) {
    try {
        auto data = readFile(vecDir + "/scalars/str_255.mp");
        specodec::MsgPackReader r(data);
        auto value = r.readString();
        specodec::MsgPackWriter w;
        w.writeString(value);
        writeFile(outDir + "/scalars/str_255.mp", w.toBytes());
        passed++;
    } catch (...) { failed++; std::cout << "FAIL str_255 mp" << std::endl; }
}

void testScalarStr_256(int& passed, int& failed) {
    try {
        auto data = readFile(vecDir + "/scalars/str_256.mp");
        specodec::MsgPackReader r(data);
        auto value = r.readString();
        specodec::MsgPackWriter w;
        w.writeString(value);
        writeFile(outDir + "/scalars/str_256.mp", w.toBytes());
        passed++;
    } catch (...) { failed++; std::cout << "FAIL str_256 mp" << std::endl; }
}

void testScalarBytes_empty(int& passed, int& failed) {
    try {
        auto data = readFile(vecDir + "/scalars/bytes_empty.mp");
        specodec::MsgPackReader r(data);
        auto value = r.readBytes();
        specodec::MsgPackWriter w;
        w.writeBytes(value);
        writeFile(outDir + "/scalars/bytes_empty.mp", w.toBytes());
        passed++;
    } catch (...) { failed++; std::cout << "FAIL bytes_empty mp" << std::endl; }
}

void testScalarBytes_small(int& passed, int& failed) {
    try {
        auto data = readFile(vecDir + "/scalars/bytes_small.mp");
        specodec::MsgPackReader r(data);
        auto value = r.readBytes();
        specodec::MsgPackWriter w;
        w.writeBytes(value);
        writeFile(outDir + "/scalars/bytes_small.mp", w.toBytes());
        passed++;
    } catch (...) { failed++; std::cout << "FAIL bytes_small mp" << std::endl; }
}

void testScalarBytes_31(int& passed, int& failed) {
    try {
        auto data = readFile(vecDir + "/scalars/bytes_31.mp");
        specodec::MsgPackReader r(data);
        auto value = r.readBytes();
        specodec::MsgPackWriter w;
        w.writeBytes(value);
        writeFile(outDir + "/scalars/bytes_31.mp", w.toBytes());
        passed++;
    } catch (...) { failed++; std::cout << "FAIL bytes_31 mp" << std::endl; }
}

void testScalarBytes_32(int& passed, int& failed) {
    try {
        auto data = readFile(vecDir + "/scalars/bytes_32.mp");
        specodec::MsgPackReader r(data);
        auto value = r.readBytes();
        specodec::MsgPackWriter w;
        w.writeBytes(value);
        writeFile(outDir + "/scalars/bytes_32.mp", w.toBytes());
        passed++;
    } catch (...) { failed++; std::cout << "FAIL bytes_32 mp" << std::endl; }
}

void testScalarBytes_255(int& passed, int& failed) {
    try {
        auto data = readFile(vecDir + "/scalars/bytes_255.mp");
        specodec::MsgPackReader r(data);
        auto value = r.readBytes();
        specodec::MsgPackWriter w;
        w.writeBytes(value);
        writeFile(outDir + "/scalars/bytes_255.mp", w.toBytes());
        passed++;
    } catch (...) { failed++; std::cout << "FAIL bytes_255 mp" << std::endl; }
}

void testScalarBytes_256(int& passed, int& failed) {
    try {
        auto data = readFile(vecDir + "/scalars/bytes_256.mp");
        specodec::MsgPackReader r(data);
        auto value = r.readBytes();
        specodec::MsgPackWriter w;
        w.writeBytes(value);
        writeFile(outDir + "/scalars/bytes_256.mp", w.toBytes());
        passed++;
    } catch (...) { failed++; std::cout << "FAIL bytes_256 mp" << std::endl; }
}

void testScalarBytes_zeros(int& passed, int& failed) {
    try {
        auto data = readFile(vecDir + "/scalars/bytes_zeros.mp");
        specodec::MsgPackReader r(data);
        auto value = r.readBytes();
        specodec::MsgPackWriter w;
        w.writeBytes(value);
        writeFile(outDir + "/scalars/bytes_zeros.mp", w.toBytes());
        passed++;
    } catch (...) { failed++; std::cout << "FAIL bytes_zeros mp" << std::endl; }
}

void testScalarBytes_ff(int& passed, int& failed) {
    try {
        auto data = readFile(vecDir + "/scalars/bytes_ff.mp");
        specodec::MsgPackReader r(data);
        auto value = r.readBytes();
        specodec::MsgPackWriter w;
        w.writeBytes(value);
        writeFile(outDir + "/scalars/bytes_ff.mp", w.toBytes());
        passed++;
    } catch (...) { failed++; std::cout << "FAIL bytes_ff mp" << std::endl; }
}

void testScalarBool_true(int& passed, int& failed) {
    try {
        auto data = readFile(vecDir + "/scalars/bool_true.mp");
        specodec::MsgPackReader r(data);
        auto value = r.readBool();
        specodec::MsgPackWriter w;
        w.writeBool(value);
        writeFile(outDir + "/scalars/bool_true.mp", w.toBytes());
        passed++;
    } catch (...) { failed++; std::cout << "FAIL bool_true mp" << std::endl; }
}

void testScalarBool_false(int& passed, int& failed) {
    try {
        auto data = readFile(vecDir + "/scalars/bool_false.mp");
        specodec::MsgPackReader r(data);
        auto value = r.readBool();
        specodec::MsgPackWriter w;
        w.writeBool(value);
        writeFile(outDir + "/scalars/bool_false.mp", w.toBytes());
        passed++;
    } catch (...) { failed++; std::cout << "FAIL bool_false mp" << std::endl; }
}


void testModelOptInner(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptInner.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptInnerCodec.decode(r);
        specodec::MsgPackWriter w;
        OptInnerCodec.encode(w, obj);
        writeFile(outDir + "/OptInner.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptInner mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptInner mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptInner.json");
        specodec::JsonReader r(data);
        auto obj = OptInnerCodec.decode(r);
        specodec::JsonWriter w;
        OptInnerCodec.encode(w, obj);
        writeFile(outDir + "/OptInner.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptInner json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptInner json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptInner.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptInnerCodec.decode(r);
        specodec::JsonWriter w;
        OptInnerCodec.encode(w, obj);
        writeFile(outDir + "/OptInner.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptInner unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptInner unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptInner.gron");
        specodec::GronReader r(data);
        auto obj = OptInnerCodec.decode(r);
        specodec::GronWriter w;
        OptInnerCodec.encode(w, obj);
        writeFile(outDir + "/OptInner.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptInner gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptInner gron" << std::endl; }
}

void testModelSingleString(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/SingleString.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = SingleStringCodec.decode(r);
        specodec::MsgPackWriter w;
        SingleStringCodec.encode(w, obj);
        writeFile(outDir + "/SingleString.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL SingleString mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL SingleString mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/SingleString.json");
        specodec::JsonReader r(data);
        auto obj = SingleStringCodec.decode(r);
        specodec::JsonWriter w;
        SingleStringCodec.encode(w, obj);
        writeFile(outDir + "/SingleString.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL SingleString json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL SingleString json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/SingleString.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = SingleStringCodec.decode(r);
        specodec::JsonWriter w;
        SingleStringCodec.encode(w, obj);
        writeFile(outDir + "/SingleString.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL SingleString unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL SingleString unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/SingleString.gron");
        specodec::GronReader r(data);
        auto obj = SingleStringCodec.decode(r);
        specodec::GronWriter w;
        SingleStringCodec.encode(w, obj);
        writeFile(outDir + "/SingleString.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL SingleString gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL SingleString gron" << std::endl; }
}

void testModelSingleBoolean(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/SingleBoolean.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = SingleBooleanCodec.decode(r);
        specodec::MsgPackWriter w;
        SingleBooleanCodec.encode(w, obj);
        writeFile(outDir + "/SingleBoolean.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL SingleBoolean mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL SingleBoolean mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/SingleBoolean.json");
        specodec::JsonReader r(data);
        auto obj = SingleBooleanCodec.decode(r);
        specodec::JsonWriter w;
        SingleBooleanCodec.encode(w, obj);
        writeFile(outDir + "/SingleBoolean.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL SingleBoolean json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL SingleBoolean json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/SingleBoolean.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = SingleBooleanCodec.decode(r);
        specodec::JsonWriter w;
        SingleBooleanCodec.encode(w, obj);
        writeFile(outDir + "/SingleBoolean.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL SingleBoolean unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL SingleBoolean unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/SingleBoolean.gron");
        specodec::GronReader r(data);
        auto obj = SingleBooleanCodec.decode(r);
        specodec::GronWriter w;
        SingleBooleanCodec.encode(w, obj);
        writeFile(outDir + "/SingleBoolean.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL SingleBoolean gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL SingleBoolean gron" << std::endl; }
}

void testModelSingleInt8(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/SingleInt8.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = SingleInt8Codec.decode(r);
        specodec::MsgPackWriter w;
        SingleInt8Codec.encode(w, obj);
        writeFile(outDir + "/SingleInt8.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL SingleInt8 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL SingleInt8 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/SingleInt8.json");
        specodec::JsonReader r(data);
        auto obj = SingleInt8Codec.decode(r);
        specodec::JsonWriter w;
        SingleInt8Codec.encode(w, obj);
        writeFile(outDir + "/SingleInt8.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL SingleInt8 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL SingleInt8 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/SingleInt8.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = SingleInt8Codec.decode(r);
        specodec::JsonWriter w;
        SingleInt8Codec.encode(w, obj);
        writeFile(outDir + "/SingleInt8.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL SingleInt8 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL SingleInt8 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/SingleInt8.gron");
        specodec::GronReader r(data);
        auto obj = SingleInt8Codec.decode(r);
        specodec::GronWriter w;
        SingleInt8Codec.encode(w, obj);
        writeFile(outDir + "/SingleInt8.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL SingleInt8 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL SingleInt8 gron" << std::endl; }
}

void testModelSingleInt16(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/SingleInt16.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = SingleInt16Codec.decode(r);
        specodec::MsgPackWriter w;
        SingleInt16Codec.encode(w, obj);
        writeFile(outDir + "/SingleInt16.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL SingleInt16 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL SingleInt16 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/SingleInt16.json");
        specodec::JsonReader r(data);
        auto obj = SingleInt16Codec.decode(r);
        specodec::JsonWriter w;
        SingleInt16Codec.encode(w, obj);
        writeFile(outDir + "/SingleInt16.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL SingleInt16 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL SingleInt16 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/SingleInt16.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = SingleInt16Codec.decode(r);
        specodec::JsonWriter w;
        SingleInt16Codec.encode(w, obj);
        writeFile(outDir + "/SingleInt16.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL SingleInt16 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL SingleInt16 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/SingleInt16.gron");
        specodec::GronReader r(data);
        auto obj = SingleInt16Codec.decode(r);
        specodec::GronWriter w;
        SingleInt16Codec.encode(w, obj);
        writeFile(outDir + "/SingleInt16.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL SingleInt16 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL SingleInt16 gron" << std::endl; }
}

void testModelSingleInt32(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/SingleInt32.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = SingleInt32Codec.decode(r);
        specodec::MsgPackWriter w;
        SingleInt32Codec.encode(w, obj);
        writeFile(outDir + "/SingleInt32.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL SingleInt32 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL SingleInt32 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/SingleInt32.json");
        specodec::JsonReader r(data);
        auto obj = SingleInt32Codec.decode(r);
        specodec::JsonWriter w;
        SingleInt32Codec.encode(w, obj);
        writeFile(outDir + "/SingleInt32.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL SingleInt32 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL SingleInt32 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/SingleInt32.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = SingleInt32Codec.decode(r);
        specodec::JsonWriter w;
        SingleInt32Codec.encode(w, obj);
        writeFile(outDir + "/SingleInt32.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL SingleInt32 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL SingleInt32 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/SingleInt32.gron");
        specodec::GronReader r(data);
        auto obj = SingleInt32Codec.decode(r);
        specodec::GronWriter w;
        SingleInt32Codec.encode(w, obj);
        writeFile(outDir + "/SingleInt32.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL SingleInt32 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL SingleInt32 gron" << std::endl; }
}

void testModelSingleInt64(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/SingleInt64.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = SingleInt64Codec.decode(r);
        specodec::MsgPackWriter w;
        SingleInt64Codec.encode(w, obj);
        writeFile(outDir + "/SingleInt64.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL SingleInt64 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL SingleInt64 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/SingleInt64.json");
        specodec::JsonReader r(data);
        auto obj = SingleInt64Codec.decode(r);
        specodec::JsonWriter w;
        SingleInt64Codec.encode(w, obj);
        writeFile(outDir + "/SingleInt64.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL SingleInt64 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL SingleInt64 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/SingleInt64.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = SingleInt64Codec.decode(r);
        specodec::JsonWriter w;
        SingleInt64Codec.encode(w, obj);
        writeFile(outDir + "/SingleInt64.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL SingleInt64 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL SingleInt64 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/SingleInt64.gron");
        specodec::GronReader r(data);
        auto obj = SingleInt64Codec.decode(r);
        specodec::GronWriter w;
        SingleInt64Codec.encode(w, obj);
        writeFile(outDir + "/SingleInt64.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL SingleInt64 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL SingleInt64 gron" << std::endl; }
}

void testModelSingleUint8(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/SingleUint8.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = SingleUint8Codec.decode(r);
        specodec::MsgPackWriter w;
        SingleUint8Codec.encode(w, obj);
        writeFile(outDir + "/SingleUint8.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL SingleUint8 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL SingleUint8 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/SingleUint8.json");
        specodec::JsonReader r(data);
        auto obj = SingleUint8Codec.decode(r);
        specodec::JsonWriter w;
        SingleUint8Codec.encode(w, obj);
        writeFile(outDir + "/SingleUint8.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL SingleUint8 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL SingleUint8 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/SingleUint8.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = SingleUint8Codec.decode(r);
        specodec::JsonWriter w;
        SingleUint8Codec.encode(w, obj);
        writeFile(outDir + "/SingleUint8.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL SingleUint8 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL SingleUint8 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/SingleUint8.gron");
        specodec::GronReader r(data);
        auto obj = SingleUint8Codec.decode(r);
        specodec::GronWriter w;
        SingleUint8Codec.encode(w, obj);
        writeFile(outDir + "/SingleUint8.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL SingleUint8 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL SingleUint8 gron" << std::endl; }
}

void testModelSingleUint16(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/SingleUint16.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = SingleUint16Codec.decode(r);
        specodec::MsgPackWriter w;
        SingleUint16Codec.encode(w, obj);
        writeFile(outDir + "/SingleUint16.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL SingleUint16 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL SingleUint16 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/SingleUint16.json");
        specodec::JsonReader r(data);
        auto obj = SingleUint16Codec.decode(r);
        specodec::JsonWriter w;
        SingleUint16Codec.encode(w, obj);
        writeFile(outDir + "/SingleUint16.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL SingleUint16 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL SingleUint16 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/SingleUint16.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = SingleUint16Codec.decode(r);
        specodec::JsonWriter w;
        SingleUint16Codec.encode(w, obj);
        writeFile(outDir + "/SingleUint16.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL SingleUint16 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL SingleUint16 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/SingleUint16.gron");
        specodec::GronReader r(data);
        auto obj = SingleUint16Codec.decode(r);
        specodec::GronWriter w;
        SingleUint16Codec.encode(w, obj);
        writeFile(outDir + "/SingleUint16.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL SingleUint16 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL SingleUint16 gron" << std::endl; }
}

void testModelSingleUint32(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/SingleUint32.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = SingleUint32Codec.decode(r);
        specodec::MsgPackWriter w;
        SingleUint32Codec.encode(w, obj);
        writeFile(outDir + "/SingleUint32.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL SingleUint32 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL SingleUint32 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/SingleUint32.json");
        specodec::JsonReader r(data);
        auto obj = SingleUint32Codec.decode(r);
        specodec::JsonWriter w;
        SingleUint32Codec.encode(w, obj);
        writeFile(outDir + "/SingleUint32.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL SingleUint32 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL SingleUint32 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/SingleUint32.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = SingleUint32Codec.decode(r);
        specodec::JsonWriter w;
        SingleUint32Codec.encode(w, obj);
        writeFile(outDir + "/SingleUint32.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL SingleUint32 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL SingleUint32 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/SingleUint32.gron");
        specodec::GronReader r(data);
        auto obj = SingleUint32Codec.decode(r);
        specodec::GronWriter w;
        SingleUint32Codec.encode(w, obj);
        writeFile(outDir + "/SingleUint32.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL SingleUint32 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL SingleUint32 gron" << std::endl; }
}

void testModelSingleUint64(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/SingleUint64.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = SingleUint64Codec.decode(r);
        specodec::MsgPackWriter w;
        SingleUint64Codec.encode(w, obj);
        writeFile(outDir + "/SingleUint64.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL SingleUint64 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL SingleUint64 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/SingleUint64.json");
        specodec::JsonReader r(data);
        auto obj = SingleUint64Codec.decode(r);
        specodec::JsonWriter w;
        SingleUint64Codec.encode(w, obj);
        writeFile(outDir + "/SingleUint64.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL SingleUint64 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL SingleUint64 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/SingleUint64.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = SingleUint64Codec.decode(r);
        specodec::JsonWriter w;
        SingleUint64Codec.encode(w, obj);
        writeFile(outDir + "/SingleUint64.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL SingleUint64 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL SingleUint64 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/SingleUint64.gron");
        specodec::GronReader r(data);
        auto obj = SingleUint64Codec.decode(r);
        specodec::GronWriter w;
        SingleUint64Codec.encode(w, obj);
        writeFile(outDir + "/SingleUint64.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL SingleUint64 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL SingleUint64 gron" << std::endl; }
}

void testModelSingleFloat32(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/SingleFloat32.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = SingleFloat32Codec.decode(r);
        specodec::MsgPackWriter w;
        SingleFloat32Codec.encode(w, obj);
        writeFile(outDir + "/SingleFloat32.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL SingleFloat32 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL SingleFloat32 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/SingleFloat32.json");
        specodec::JsonReader r(data);
        auto obj = SingleFloat32Codec.decode(r);
        specodec::JsonWriter w;
        SingleFloat32Codec.encode(w, obj);
        writeFile(outDir + "/SingleFloat32.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL SingleFloat32 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL SingleFloat32 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/SingleFloat32.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = SingleFloat32Codec.decode(r);
        specodec::JsonWriter w;
        SingleFloat32Codec.encode(w, obj);
        writeFile(outDir + "/SingleFloat32.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL SingleFloat32 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL SingleFloat32 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/SingleFloat32.gron");
        specodec::GronReader r(data);
        auto obj = SingleFloat32Codec.decode(r);
        specodec::GronWriter w;
        SingleFloat32Codec.encode(w, obj);
        writeFile(outDir + "/SingleFloat32.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL SingleFloat32 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL SingleFloat32 gron" << std::endl; }
}

void testModelSingleFloat64(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/SingleFloat64.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = SingleFloat64Codec.decode(r);
        specodec::MsgPackWriter w;
        SingleFloat64Codec.encode(w, obj);
        writeFile(outDir + "/SingleFloat64.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL SingleFloat64 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL SingleFloat64 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/SingleFloat64.json");
        specodec::JsonReader r(data);
        auto obj = SingleFloat64Codec.decode(r);
        specodec::JsonWriter w;
        SingleFloat64Codec.encode(w, obj);
        writeFile(outDir + "/SingleFloat64.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL SingleFloat64 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL SingleFloat64 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/SingleFloat64.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = SingleFloat64Codec.decode(r);
        specodec::JsonWriter w;
        SingleFloat64Codec.encode(w, obj);
        writeFile(outDir + "/SingleFloat64.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL SingleFloat64 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL SingleFloat64 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/SingleFloat64.gron");
        specodec::GronReader r(data);
        auto obj = SingleFloat64Codec.decode(r);
        specodec::GronWriter w;
        SingleFloat64Codec.encode(w, obj);
        writeFile(outDir + "/SingleFloat64.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL SingleFloat64 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL SingleFloat64 gron" << std::endl; }
}

void testModelSingleBytes(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/SingleBytes.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = SingleBytesCodec.decode(r);
        specodec::MsgPackWriter w;
        SingleBytesCodec.encode(w, obj);
        writeFile(outDir + "/SingleBytes.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL SingleBytes mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL SingleBytes mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/SingleBytes.json");
        specodec::JsonReader r(data);
        auto obj = SingleBytesCodec.decode(r);
        specodec::JsonWriter w;
        SingleBytesCodec.encode(w, obj);
        writeFile(outDir + "/SingleBytes.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL SingleBytes json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL SingleBytes json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/SingleBytes.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = SingleBytesCodec.decode(r);
        specodec::JsonWriter w;
        SingleBytesCodec.encode(w, obj);
        writeFile(outDir + "/SingleBytes.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL SingleBytes unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL SingleBytes unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/SingleBytes.gron");
        specodec::GronReader r(data);
        auto obj = SingleBytesCodec.decode(r);
        specodec::GronWriter w;
        SingleBytesCodec.encode(w, obj);
        writeFile(outDir + "/SingleBytes.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL SingleBytes gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL SingleBytes gron" << std::endl; }
}

void testModelOptSingleString(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptSingleString.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptSingleStringCodec.decode(r);
        specodec::MsgPackWriter w;
        OptSingleStringCodec.encode(w, obj);
        writeFile(outDir + "/OptSingleString.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptSingleString mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptSingleString mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptSingleString.json");
        specodec::JsonReader r(data);
        auto obj = OptSingleStringCodec.decode(r);
        specodec::JsonWriter w;
        OptSingleStringCodec.encode(w, obj);
        writeFile(outDir + "/OptSingleString.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptSingleString json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptSingleString json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptSingleString.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptSingleStringCodec.decode(r);
        specodec::JsonWriter w;
        OptSingleStringCodec.encode(w, obj);
        writeFile(outDir + "/OptSingleString.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptSingleString unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptSingleString unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptSingleString.gron");
        specodec::GronReader r(data);
        auto obj = OptSingleStringCodec.decode(r);
        specodec::GronWriter w;
        OptSingleStringCodec.encode(w, obj);
        writeFile(outDir + "/OptSingleString.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptSingleString gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptSingleString gron" << std::endl; }
}

void testModelOptSingleBoolean(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptSingleBoolean.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptSingleBooleanCodec.decode(r);
        specodec::MsgPackWriter w;
        OptSingleBooleanCodec.encode(w, obj);
        writeFile(outDir + "/OptSingleBoolean.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptSingleBoolean mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptSingleBoolean mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptSingleBoolean.json");
        specodec::JsonReader r(data);
        auto obj = OptSingleBooleanCodec.decode(r);
        specodec::JsonWriter w;
        OptSingleBooleanCodec.encode(w, obj);
        writeFile(outDir + "/OptSingleBoolean.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptSingleBoolean json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptSingleBoolean json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptSingleBoolean.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptSingleBooleanCodec.decode(r);
        specodec::JsonWriter w;
        OptSingleBooleanCodec.encode(w, obj);
        writeFile(outDir + "/OptSingleBoolean.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptSingleBoolean unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptSingleBoolean unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptSingleBoolean.gron");
        specodec::GronReader r(data);
        auto obj = OptSingleBooleanCodec.decode(r);
        specodec::GronWriter w;
        OptSingleBooleanCodec.encode(w, obj);
        writeFile(outDir + "/OptSingleBoolean.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptSingleBoolean gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptSingleBoolean gron" << std::endl; }
}

void testModelOptSingleInt8(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptSingleInt8.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptSingleInt8Codec.decode(r);
        specodec::MsgPackWriter w;
        OptSingleInt8Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleInt8.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptSingleInt8 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptSingleInt8 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptSingleInt8.json");
        specodec::JsonReader r(data);
        auto obj = OptSingleInt8Codec.decode(r);
        specodec::JsonWriter w;
        OptSingleInt8Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleInt8.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptSingleInt8 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptSingleInt8 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptSingleInt8.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptSingleInt8Codec.decode(r);
        specodec::JsonWriter w;
        OptSingleInt8Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleInt8.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptSingleInt8 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptSingleInt8 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptSingleInt8.gron");
        specodec::GronReader r(data);
        auto obj = OptSingleInt8Codec.decode(r);
        specodec::GronWriter w;
        OptSingleInt8Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleInt8.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptSingleInt8 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptSingleInt8 gron" << std::endl; }
}

void testModelOptSingleInt16(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptSingleInt16.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptSingleInt16Codec.decode(r);
        specodec::MsgPackWriter w;
        OptSingleInt16Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleInt16.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptSingleInt16 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptSingleInt16 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptSingleInt16.json");
        specodec::JsonReader r(data);
        auto obj = OptSingleInt16Codec.decode(r);
        specodec::JsonWriter w;
        OptSingleInt16Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleInt16.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptSingleInt16 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptSingleInt16 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptSingleInt16.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptSingleInt16Codec.decode(r);
        specodec::JsonWriter w;
        OptSingleInt16Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleInt16.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptSingleInt16 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptSingleInt16 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptSingleInt16.gron");
        specodec::GronReader r(data);
        auto obj = OptSingleInt16Codec.decode(r);
        specodec::GronWriter w;
        OptSingleInt16Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleInt16.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptSingleInt16 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptSingleInt16 gron" << std::endl; }
}

void testModelOptSingleInt32(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptSingleInt32.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptSingleInt32Codec.decode(r);
        specodec::MsgPackWriter w;
        OptSingleInt32Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleInt32.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptSingleInt32 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptSingleInt32 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptSingleInt32.json");
        specodec::JsonReader r(data);
        auto obj = OptSingleInt32Codec.decode(r);
        specodec::JsonWriter w;
        OptSingleInt32Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleInt32.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptSingleInt32 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptSingleInt32 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptSingleInt32.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptSingleInt32Codec.decode(r);
        specodec::JsonWriter w;
        OptSingleInt32Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleInt32.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptSingleInt32 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptSingleInt32 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptSingleInt32.gron");
        specodec::GronReader r(data);
        auto obj = OptSingleInt32Codec.decode(r);
        specodec::GronWriter w;
        OptSingleInt32Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleInt32.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptSingleInt32 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptSingleInt32 gron" << std::endl; }
}

void testModelOptSingleInt64(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptSingleInt64.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptSingleInt64Codec.decode(r);
        specodec::MsgPackWriter w;
        OptSingleInt64Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleInt64.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptSingleInt64 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptSingleInt64 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptSingleInt64.json");
        specodec::JsonReader r(data);
        auto obj = OptSingleInt64Codec.decode(r);
        specodec::JsonWriter w;
        OptSingleInt64Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleInt64.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptSingleInt64 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptSingleInt64 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptSingleInt64.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptSingleInt64Codec.decode(r);
        specodec::JsonWriter w;
        OptSingleInt64Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleInt64.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptSingleInt64 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptSingleInt64 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptSingleInt64.gron");
        specodec::GronReader r(data);
        auto obj = OptSingleInt64Codec.decode(r);
        specodec::GronWriter w;
        OptSingleInt64Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleInt64.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptSingleInt64 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptSingleInt64 gron" << std::endl; }
}

void testModelOptSingleUint8(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptSingleUint8.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptSingleUint8Codec.decode(r);
        specodec::MsgPackWriter w;
        OptSingleUint8Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleUint8.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptSingleUint8 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptSingleUint8 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptSingleUint8.json");
        specodec::JsonReader r(data);
        auto obj = OptSingleUint8Codec.decode(r);
        specodec::JsonWriter w;
        OptSingleUint8Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleUint8.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptSingleUint8 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptSingleUint8 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptSingleUint8.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptSingleUint8Codec.decode(r);
        specodec::JsonWriter w;
        OptSingleUint8Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleUint8.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptSingleUint8 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptSingleUint8 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptSingleUint8.gron");
        specodec::GronReader r(data);
        auto obj = OptSingleUint8Codec.decode(r);
        specodec::GronWriter w;
        OptSingleUint8Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleUint8.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptSingleUint8 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptSingleUint8 gron" << std::endl; }
}

void testModelOptSingleUint16(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptSingleUint16.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptSingleUint16Codec.decode(r);
        specodec::MsgPackWriter w;
        OptSingleUint16Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleUint16.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptSingleUint16 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptSingleUint16 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptSingleUint16.json");
        specodec::JsonReader r(data);
        auto obj = OptSingleUint16Codec.decode(r);
        specodec::JsonWriter w;
        OptSingleUint16Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleUint16.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptSingleUint16 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptSingleUint16 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptSingleUint16.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptSingleUint16Codec.decode(r);
        specodec::JsonWriter w;
        OptSingleUint16Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleUint16.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptSingleUint16 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptSingleUint16 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptSingleUint16.gron");
        specodec::GronReader r(data);
        auto obj = OptSingleUint16Codec.decode(r);
        specodec::GronWriter w;
        OptSingleUint16Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleUint16.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptSingleUint16 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptSingleUint16 gron" << std::endl; }
}

void testModelOptSingleUint32(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptSingleUint32.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptSingleUint32Codec.decode(r);
        specodec::MsgPackWriter w;
        OptSingleUint32Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleUint32.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptSingleUint32 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptSingleUint32 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptSingleUint32.json");
        specodec::JsonReader r(data);
        auto obj = OptSingleUint32Codec.decode(r);
        specodec::JsonWriter w;
        OptSingleUint32Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleUint32.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptSingleUint32 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptSingleUint32 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptSingleUint32.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptSingleUint32Codec.decode(r);
        specodec::JsonWriter w;
        OptSingleUint32Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleUint32.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptSingleUint32 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptSingleUint32 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptSingleUint32.gron");
        specodec::GronReader r(data);
        auto obj = OptSingleUint32Codec.decode(r);
        specodec::GronWriter w;
        OptSingleUint32Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleUint32.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptSingleUint32 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptSingleUint32 gron" << std::endl; }
}

void testModelOptSingleUint64(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptSingleUint64.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptSingleUint64Codec.decode(r);
        specodec::MsgPackWriter w;
        OptSingleUint64Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleUint64.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptSingleUint64 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptSingleUint64 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptSingleUint64.json");
        specodec::JsonReader r(data);
        auto obj = OptSingleUint64Codec.decode(r);
        specodec::JsonWriter w;
        OptSingleUint64Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleUint64.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptSingleUint64 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptSingleUint64 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptSingleUint64.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptSingleUint64Codec.decode(r);
        specodec::JsonWriter w;
        OptSingleUint64Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleUint64.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptSingleUint64 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptSingleUint64 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptSingleUint64.gron");
        specodec::GronReader r(data);
        auto obj = OptSingleUint64Codec.decode(r);
        specodec::GronWriter w;
        OptSingleUint64Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleUint64.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptSingleUint64 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptSingleUint64 gron" << std::endl; }
}

void testModelOptSingleFloat32(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptSingleFloat32.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptSingleFloat32Codec.decode(r);
        specodec::MsgPackWriter w;
        OptSingleFloat32Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleFloat32.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptSingleFloat32 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptSingleFloat32 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptSingleFloat32.json");
        specodec::JsonReader r(data);
        auto obj = OptSingleFloat32Codec.decode(r);
        specodec::JsonWriter w;
        OptSingleFloat32Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleFloat32.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptSingleFloat32 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptSingleFloat32 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptSingleFloat32.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptSingleFloat32Codec.decode(r);
        specodec::JsonWriter w;
        OptSingleFloat32Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleFloat32.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptSingleFloat32 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptSingleFloat32 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptSingleFloat32.gron");
        specodec::GronReader r(data);
        auto obj = OptSingleFloat32Codec.decode(r);
        specodec::GronWriter w;
        OptSingleFloat32Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleFloat32.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptSingleFloat32 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptSingleFloat32 gron" << std::endl; }
}

void testModelOptSingleFloat64(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptSingleFloat64.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptSingleFloat64Codec.decode(r);
        specodec::MsgPackWriter w;
        OptSingleFloat64Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleFloat64.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptSingleFloat64 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptSingleFloat64 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptSingleFloat64.json");
        specodec::JsonReader r(data);
        auto obj = OptSingleFloat64Codec.decode(r);
        specodec::JsonWriter w;
        OptSingleFloat64Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleFloat64.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptSingleFloat64 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptSingleFloat64 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptSingleFloat64.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptSingleFloat64Codec.decode(r);
        specodec::JsonWriter w;
        OptSingleFloat64Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleFloat64.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptSingleFloat64 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptSingleFloat64 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptSingleFloat64.gron");
        specodec::GronReader r(data);
        auto obj = OptSingleFloat64Codec.decode(r);
        specodec::GronWriter w;
        OptSingleFloat64Codec.encode(w, obj);
        writeFile(outDir + "/OptSingleFloat64.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptSingleFloat64 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptSingleFloat64 gron" << std::endl; }
}

void testModelOptSingleBytes(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptSingleBytes.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptSingleBytesCodec.decode(r);
        specodec::MsgPackWriter w;
        OptSingleBytesCodec.encode(w, obj);
        writeFile(outDir + "/OptSingleBytes.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptSingleBytes mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptSingleBytes mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptSingleBytes.json");
        specodec::JsonReader r(data);
        auto obj = OptSingleBytesCodec.decode(r);
        specodec::JsonWriter w;
        OptSingleBytesCodec.encode(w, obj);
        writeFile(outDir + "/OptSingleBytes.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptSingleBytes json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptSingleBytes json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptSingleBytes.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptSingleBytesCodec.decode(r);
        specodec::JsonWriter w;
        OptSingleBytesCodec.encode(w, obj);
        writeFile(outDir + "/OptSingleBytes.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptSingleBytes unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptSingleBytes unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptSingleBytes.gron");
        specodec::GronReader r(data);
        auto obj = OptSingleBytesCodec.decode(r);
        specodec::GronWriter w;
        OptSingleBytesCodec.encode(w, obj);
        writeFile(outDir + "/OptSingleBytes.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptSingleBytes gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptSingleBytes gron" << std::endl; }
}

void testModelPairString(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/PairString.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = PairStringCodec.decode(r);
        specodec::MsgPackWriter w;
        PairStringCodec.encode(w, obj);
        writeFile(outDir + "/PairString.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL PairString mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL PairString mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/PairString.json");
        specodec::JsonReader r(data);
        auto obj = PairStringCodec.decode(r);
        specodec::JsonWriter w;
        PairStringCodec.encode(w, obj);
        writeFile(outDir + "/PairString.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL PairString json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL PairString json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/PairString.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = PairStringCodec.decode(r);
        specodec::JsonWriter w;
        PairStringCodec.encode(w, obj);
        writeFile(outDir + "/PairString.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL PairString unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL PairString unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/PairString.gron");
        specodec::GronReader r(data);
        auto obj = PairStringCodec.decode(r);
        specodec::GronWriter w;
        PairStringCodec.encode(w, obj);
        writeFile(outDir + "/PairString.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL PairString gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL PairString gron" << std::endl; }
}

void testModelPairBoolean(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/PairBoolean.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = PairBooleanCodec.decode(r);
        specodec::MsgPackWriter w;
        PairBooleanCodec.encode(w, obj);
        writeFile(outDir + "/PairBoolean.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL PairBoolean mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL PairBoolean mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/PairBoolean.json");
        specodec::JsonReader r(data);
        auto obj = PairBooleanCodec.decode(r);
        specodec::JsonWriter w;
        PairBooleanCodec.encode(w, obj);
        writeFile(outDir + "/PairBoolean.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL PairBoolean json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL PairBoolean json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/PairBoolean.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = PairBooleanCodec.decode(r);
        specodec::JsonWriter w;
        PairBooleanCodec.encode(w, obj);
        writeFile(outDir + "/PairBoolean.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL PairBoolean unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL PairBoolean unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/PairBoolean.gron");
        specodec::GronReader r(data);
        auto obj = PairBooleanCodec.decode(r);
        specodec::GronWriter w;
        PairBooleanCodec.encode(w, obj);
        writeFile(outDir + "/PairBoolean.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL PairBoolean gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL PairBoolean gron" << std::endl; }
}

void testModelPairInt8(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/PairInt8.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = PairInt8Codec.decode(r);
        specodec::MsgPackWriter w;
        PairInt8Codec.encode(w, obj);
        writeFile(outDir + "/PairInt8.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL PairInt8 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL PairInt8 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/PairInt8.json");
        specodec::JsonReader r(data);
        auto obj = PairInt8Codec.decode(r);
        specodec::JsonWriter w;
        PairInt8Codec.encode(w, obj);
        writeFile(outDir + "/PairInt8.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL PairInt8 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL PairInt8 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/PairInt8.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = PairInt8Codec.decode(r);
        specodec::JsonWriter w;
        PairInt8Codec.encode(w, obj);
        writeFile(outDir + "/PairInt8.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL PairInt8 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL PairInt8 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/PairInt8.gron");
        specodec::GronReader r(data);
        auto obj = PairInt8Codec.decode(r);
        specodec::GronWriter w;
        PairInt8Codec.encode(w, obj);
        writeFile(outDir + "/PairInt8.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL PairInt8 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL PairInt8 gron" << std::endl; }
}

void testModelPairInt16(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/PairInt16.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = PairInt16Codec.decode(r);
        specodec::MsgPackWriter w;
        PairInt16Codec.encode(w, obj);
        writeFile(outDir + "/PairInt16.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL PairInt16 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL PairInt16 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/PairInt16.json");
        specodec::JsonReader r(data);
        auto obj = PairInt16Codec.decode(r);
        specodec::JsonWriter w;
        PairInt16Codec.encode(w, obj);
        writeFile(outDir + "/PairInt16.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL PairInt16 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL PairInt16 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/PairInt16.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = PairInt16Codec.decode(r);
        specodec::JsonWriter w;
        PairInt16Codec.encode(w, obj);
        writeFile(outDir + "/PairInt16.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL PairInt16 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL PairInt16 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/PairInt16.gron");
        specodec::GronReader r(data);
        auto obj = PairInt16Codec.decode(r);
        specodec::GronWriter w;
        PairInt16Codec.encode(w, obj);
        writeFile(outDir + "/PairInt16.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL PairInt16 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL PairInt16 gron" << std::endl; }
}

void testModelPairInt32(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/PairInt32.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = PairInt32Codec.decode(r);
        specodec::MsgPackWriter w;
        PairInt32Codec.encode(w, obj);
        writeFile(outDir + "/PairInt32.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL PairInt32 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL PairInt32 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/PairInt32.json");
        specodec::JsonReader r(data);
        auto obj = PairInt32Codec.decode(r);
        specodec::JsonWriter w;
        PairInt32Codec.encode(w, obj);
        writeFile(outDir + "/PairInt32.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL PairInt32 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL PairInt32 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/PairInt32.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = PairInt32Codec.decode(r);
        specodec::JsonWriter w;
        PairInt32Codec.encode(w, obj);
        writeFile(outDir + "/PairInt32.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL PairInt32 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL PairInt32 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/PairInt32.gron");
        specodec::GronReader r(data);
        auto obj = PairInt32Codec.decode(r);
        specodec::GronWriter w;
        PairInt32Codec.encode(w, obj);
        writeFile(outDir + "/PairInt32.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL PairInt32 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL PairInt32 gron" << std::endl; }
}

void testModelPairInt64(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/PairInt64.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = PairInt64Codec.decode(r);
        specodec::MsgPackWriter w;
        PairInt64Codec.encode(w, obj);
        writeFile(outDir + "/PairInt64.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL PairInt64 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL PairInt64 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/PairInt64.json");
        specodec::JsonReader r(data);
        auto obj = PairInt64Codec.decode(r);
        specodec::JsonWriter w;
        PairInt64Codec.encode(w, obj);
        writeFile(outDir + "/PairInt64.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL PairInt64 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL PairInt64 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/PairInt64.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = PairInt64Codec.decode(r);
        specodec::JsonWriter w;
        PairInt64Codec.encode(w, obj);
        writeFile(outDir + "/PairInt64.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL PairInt64 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL PairInt64 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/PairInt64.gron");
        specodec::GronReader r(data);
        auto obj = PairInt64Codec.decode(r);
        specodec::GronWriter w;
        PairInt64Codec.encode(w, obj);
        writeFile(outDir + "/PairInt64.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL PairInt64 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL PairInt64 gron" << std::endl; }
}

void testModelPairUint8(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/PairUint8.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = PairUint8Codec.decode(r);
        specodec::MsgPackWriter w;
        PairUint8Codec.encode(w, obj);
        writeFile(outDir + "/PairUint8.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL PairUint8 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL PairUint8 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/PairUint8.json");
        specodec::JsonReader r(data);
        auto obj = PairUint8Codec.decode(r);
        specodec::JsonWriter w;
        PairUint8Codec.encode(w, obj);
        writeFile(outDir + "/PairUint8.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL PairUint8 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL PairUint8 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/PairUint8.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = PairUint8Codec.decode(r);
        specodec::JsonWriter w;
        PairUint8Codec.encode(w, obj);
        writeFile(outDir + "/PairUint8.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL PairUint8 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL PairUint8 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/PairUint8.gron");
        specodec::GronReader r(data);
        auto obj = PairUint8Codec.decode(r);
        specodec::GronWriter w;
        PairUint8Codec.encode(w, obj);
        writeFile(outDir + "/PairUint8.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL PairUint8 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL PairUint8 gron" << std::endl; }
}

void testModelPairUint16(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/PairUint16.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = PairUint16Codec.decode(r);
        specodec::MsgPackWriter w;
        PairUint16Codec.encode(w, obj);
        writeFile(outDir + "/PairUint16.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL PairUint16 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL PairUint16 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/PairUint16.json");
        specodec::JsonReader r(data);
        auto obj = PairUint16Codec.decode(r);
        specodec::JsonWriter w;
        PairUint16Codec.encode(w, obj);
        writeFile(outDir + "/PairUint16.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL PairUint16 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL PairUint16 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/PairUint16.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = PairUint16Codec.decode(r);
        specodec::JsonWriter w;
        PairUint16Codec.encode(w, obj);
        writeFile(outDir + "/PairUint16.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL PairUint16 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL PairUint16 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/PairUint16.gron");
        specodec::GronReader r(data);
        auto obj = PairUint16Codec.decode(r);
        specodec::GronWriter w;
        PairUint16Codec.encode(w, obj);
        writeFile(outDir + "/PairUint16.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL PairUint16 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL PairUint16 gron" << std::endl; }
}

void testModelPairUint32(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/PairUint32.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = PairUint32Codec.decode(r);
        specodec::MsgPackWriter w;
        PairUint32Codec.encode(w, obj);
        writeFile(outDir + "/PairUint32.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL PairUint32 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL PairUint32 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/PairUint32.json");
        specodec::JsonReader r(data);
        auto obj = PairUint32Codec.decode(r);
        specodec::JsonWriter w;
        PairUint32Codec.encode(w, obj);
        writeFile(outDir + "/PairUint32.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL PairUint32 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL PairUint32 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/PairUint32.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = PairUint32Codec.decode(r);
        specodec::JsonWriter w;
        PairUint32Codec.encode(w, obj);
        writeFile(outDir + "/PairUint32.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL PairUint32 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL PairUint32 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/PairUint32.gron");
        specodec::GronReader r(data);
        auto obj = PairUint32Codec.decode(r);
        specodec::GronWriter w;
        PairUint32Codec.encode(w, obj);
        writeFile(outDir + "/PairUint32.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL PairUint32 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL PairUint32 gron" << std::endl; }
}

void testModelPairUint64(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/PairUint64.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = PairUint64Codec.decode(r);
        specodec::MsgPackWriter w;
        PairUint64Codec.encode(w, obj);
        writeFile(outDir + "/PairUint64.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL PairUint64 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL PairUint64 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/PairUint64.json");
        specodec::JsonReader r(data);
        auto obj = PairUint64Codec.decode(r);
        specodec::JsonWriter w;
        PairUint64Codec.encode(w, obj);
        writeFile(outDir + "/PairUint64.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL PairUint64 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL PairUint64 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/PairUint64.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = PairUint64Codec.decode(r);
        specodec::JsonWriter w;
        PairUint64Codec.encode(w, obj);
        writeFile(outDir + "/PairUint64.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL PairUint64 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL PairUint64 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/PairUint64.gron");
        specodec::GronReader r(data);
        auto obj = PairUint64Codec.decode(r);
        specodec::GronWriter w;
        PairUint64Codec.encode(w, obj);
        writeFile(outDir + "/PairUint64.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL PairUint64 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL PairUint64 gron" << std::endl; }
}

void testModelPairFloat32(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/PairFloat32.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = PairFloat32Codec.decode(r);
        specodec::MsgPackWriter w;
        PairFloat32Codec.encode(w, obj);
        writeFile(outDir + "/PairFloat32.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL PairFloat32 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL PairFloat32 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/PairFloat32.json");
        specodec::JsonReader r(data);
        auto obj = PairFloat32Codec.decode(r);
        specodec::JsonWriter w;
        PairFloat32Codec.encode(w, obj);
        writeFile(outDir + "/PairFloat32.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL PairFloat32 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL PairFloat32 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/PairFloat32.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = PairFloat32Codec.decode(r);
        specodec::JsonWriter w;
        PairFloat32Codec.encode(w, obj);
        writeFile(outDir + "/PairFloat32.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL PairFloat32 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL PairFloat32 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/PairFloat32.gron");
        specodec::GronReader r(data);
        auto obj = PairFloat32Codec.decode(r);
        specodec::GronWriter w;
        PairFloat32Codec.encode(w, obj);
        writeFile(outDir + "/PairFloat32.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL PairFloat32 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL PairFloat32 gron" << std::endl; }
}

void testModelPairFloat64(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/PairFloat64.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = PairFloat64Codec.decode(r);
        specodec::MsgPackWriter w;
        PairFloat64Codec.encode(w, obj);
        writeFile(outDir + "/PairFloat64.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL PairFloat64 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL PairFloat64 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/PairFloat64.json");
        specodec::JsonReader r(data);
        auto obj = PairFloat64Codec.decode(r);
        specodec::JsonWriter w;
        PairFloat64Codec.encode(w, obj);
        writeFile(outDir + "/PairFloat64.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL PairFloat64 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL PairFloat64 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/PairFloat64.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = PairFloat64Codec.decode(r);
        specodec::JsonWriter w;
        PairFloat64Codec.encode(w, obj);
        writeFile(outDir + "/PairFloat64.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL PairFloat64 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL PairFloat64 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/PairFloat64.gron");
        specodec::GronReader r(data);
        auto obj = PairFloat64Codec.decode(r);
        specodec::GronWriter w;
        PairFloat64Codec.encode(w, obj);
        writeFile(outDir + "/PairFloat64.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL PairFloat64 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL PairFloat64 gron" << std::endl; }
}

void testModelPairBytes(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/PairBytes.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = PairBytesCodec.decode(r);
        specodec::MsgPackWriter w;
        PairBytesCodec.encode(w, obj);
        writeFile(outDir + "/PairBytes.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL PairBytes mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL PairBytes mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/PairBytes.json");
        specodec::JsonReader r(data);
        auto obj = PairBytesCodec.decode(r);
        specodec::JsonWriter w;
        PairBytesCodec.encode(w, obj);
        writeFile(outDir + "/PairBytes.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL PairBytes json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL PairBytes json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/PairBytes.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = PairBytesCodec.decode(r);
        specodec::JsonWriter w;
        PairBytesCodec.encode(w, obj);
        writeFile(outDir + "/PairBytes.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL PairBytes unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL PairBytes unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/PairBytes.gron");
        specodec::GronReader r(data);
        auto obj = PairBytesCodec.decode(r);
        specodec::GronWriter w;
        PairBytesCodec.encode(w, obj);
        writeFile(outDir + "/PairBytes.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL PairBytes gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL PairBytes gron" << std::endl; }
}

void testModelDualStringInt32(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/DualStringInt32.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = DualStringInt32Codec.decode(r);
        specodec::MsgPackWriter w;
        DualStringInt32Codec.encode(w, obj);
        writeFile(outDir + "/DualStringInt32.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualStringInt32 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualStringInt32 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/DualStringInt32.json");
        specodec::JsonReader r(data);
        auto obj = DualStringInt32Codec.decode(r);
        specodec::JsonWriter w;
        DualStringInt32Codec.encode(w, obj);
        writeFile(outDir + "/DualStringInt32.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualStringInt32 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualStringInt32 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/DualStringInt32.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = DualStringInt32Codec.decode(r);
        specodec::JsonWriter w;
        DualStringInt32Codec.encode(w, obj);
        writeFile(outDir + "/DualStringInt32.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualStringInt32 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualStringInt32 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/DualStringInt32.gron");
        specodec::GronReader r(data);
        auto obj = DualStringInt32Codec.decode(r);
        specodec::GronWriter w;
        DualStringInt32Codec.encode(w, obj);
        writeFile(outDir + "/DualStringInt32.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualStringInt32 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualStringInt32 gron" << std::endl; }
}

void testModelDualStringBoolean(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/DualStringBoolean.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = DualStringBooleanCodec.decode(r);
        specodec::MsgPackWriter w;
        DualStringBooleanCodec.encode(w, obj);
        writeFile(outDir + "/DualStringBoolean.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualStringBoolean mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualStringBoolean mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/DualStringBoolean.json");
        specodec::JsonReader r(data);
        auto obj = DualStringBooleanCodec.decode(r);
        specodec::JsonWriter w;
        DualStringBooleanCodec.encode(w, obj);
        writeFile(outDir + "/DualStringBoolean.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualStringBoolean json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualStringBoolean json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/DualStringBoolean.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = DualStringBooleanCodec.decode(r);
        specodec::JsonWriter w;
        DualStringBooleanCodec.encode(w, obj);
        writeFile(outDir + "/DualStringBoolean.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualStringBoolean unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualStringBoolean unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/DualStringBoolean.gron");
        specodec::GronReader r(data);
        auto obj = DualStringBooleanCodec.decode(r);
        specodec::GronWriter w;
        DualStringBooleanCodec.encode(w, obj);
        writeFile(outDir + "/DualStringBoolean.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualStringBoolean gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualStringBoolean gron" << std::endl; }
}

void testModelDualStringFloat64(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/DualStringFloat64.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = DualStringFloat64Codec.decode(r);
        specodec::MsgPackWriter w;
        DualStringFloat64Codec.encode(w, obj);
        writeFile(outDir + "/DualStringFloat64.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualStringFloat64 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualStringFloat64 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/DualStringFloat64.json");
        specodec::JsonReader r(data);
        auto obj = DualStringFloat64Codec.decode(r);
        specodec::JsonWriter w;
        DualStringFloat64Codec.encode(w, obj);
        writeFile(outDir + "/DualStringFloat64.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualStringFloat64 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualStringFloat64 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/DualStringFloat64.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = DualStringFloat64Codec.decode(r);
        specodec::JsonWriter w;
        DualStringFloat64Codec.encode(w, obj);
        writeFile(outDir + "/DualStringFloat64.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualStringFloat64 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualStringFloat64 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/DualStringFloat64.gron");
        specodec::GronReader r(data);
        auto obj = DualStringFloat64Codec.decode(r);
        specodec::GronWriter w;
        DualStringFloat64Codec.encode(w, obj);
        writeFile(outDir + "/DualStringFloat64.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualStringFloat64 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualStringFloat64 gron" << std::endl; }
}

void testModelDualStringBytes(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/DualStringBytes.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = DualStringBytesCodec.decode(r);
        specodec::MsgPackWriter w;
        DualStringBytesCodec.encode(w, obj);
        writeFile(outDir + "/DualStringBytes.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualStringBytes mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualStringBytes mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/DualStringBytes.json");
        specodec::JsonReader r(data);
        auto obj = DualStringBytesCodec.decode(r);
        specodec::JsonWriter w;
        DualStringBytesCodec.encode(w, obj);
        writeFile(outDir + "/DualStringBytes.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualStringBytes json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualStringBytes json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/DualStringBytes.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = DualStringBytesCodec.decode(r);
        specodec::JsonWriter w;
        DualStringBytesCodec.encode(w, obj);
        writeFile(outDir + "/DualStringBytes.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualStringBytes unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualStringBytes unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/DualStringBytes.gron");
        specodec::GronReader r(data);
        auto obj = DualStringBytesCodec.decode(r);
        specodec::GronWriter w;
        DualStringBytesCodec.encode(w, obj);
        writeFile(outDir + "/DualStringBytes.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualStringBytes gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualStringBytes gron" << std::endl; }
}

void testModelDualInt32Boolean(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/DualInt32Boolean.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = DualInt32BooleanCodec.decode(r);
        specodec::MsgPackWriter w;
        DualInt32BooleanCodec.encode(w, obj);
        writeFile(outDir + "/DualInt32Boolean.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualInt32Boolean mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualInt32Boolean mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/DualInt32Boolean.json");
        specodec::JsonReader r(data);
        auto obj = DualInt32BooleanCodec.decode(r);
        specodec::JsonWriter w;
        DualInt32BooleanCodec.encode(w, obj);
        writeFile(outDir + "/DualInt32Boolean.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualInt32Boolean json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualInt32Boolean json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/DualInt32Boolean.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = DualInt32BooleanCodec.decode(r);
        specodec::JsonWriter w;
        DualInt32BooleanCodec.encode(w, obj);
        writeFile(outDir + "/DualInt32Boolean.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualInt32Boolean unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualInt32Boolean unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/DualInt32Boolean.gron");
        specodec::GronReader r(data);
        auto obj = DualInt32BooleanCodec.decode(r);
        specodec::GronWriter w;
        DualInt32BooleanCodec.encode(w, obj);
        writeFile(outDir + "/DualInt32Boolean.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualInt32Boolean gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualInt32Boolean gron" << std::endl; }
}

void testModelDualInt32Float64(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/DualInt32Float64.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = DualInt32Float64Codec.decode(r);
        specodec::MsgPackWriter w;
        DualInt32Float64Codec.encode(w, obj);
        writeFile(outDir + "/DualInt32Float64.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualInt32Float64 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualInt32Float64 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/DualInt32Float64.json");
        specodec::JsonReader r(data);
        auto obj = DualInt32Float64Codec.decode(r);
        specodec::JsonWriter w;
        DualInt32Float64Codec.encode(w, obj);
        writeFile(outDir + "/DualInt32Float64.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualInt32Float64 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualInt32Float64 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/DualInt32Float64.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = DualInt32Float64Codec.decode(r);
        specodec::JsonWriter w;
        DualInt32Float64Codec.encode(w, obj);
        writeFile(outDir + "/DualInt32Float64.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualInt32Float64 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualInt32Float64 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/DualInt32Float64.gron");
        specodec::GronReader r(data);
        auto obj = DualInt32Float64Codec.decode(r);
        specodec::GronWriter w;
        DualInt32Float64Codec.encode(w, obj);
        writeFile(outDir + "/DualInt32Float64.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualInt32Float64 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualInt32Float64 gron" << std::endl; }
}

void testModelDualInt32Int64(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/DualInt32Int64.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = DualInt32Int64Codec.decode(r);
        specodec::MsgPackWriter w;
        DualInt32Int64Codec.encode(w, obj);
        writeFile(outDir + "/DualInt32Int64.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualInt32Int64 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualInt32Int64 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/DualInt32Int64.json");
        specodec::JsonReader r(data);
        auto obj = DualInt32Int64Codec.decode(r);
        specodec::JsonWriter w;
        DualInt32Int64Codec.encode(w, obj);
        writeFile(outDir + "/DualInt32Int64.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualInt32Int64 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualInt32Int64 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/DualInt32Int64.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = DualInt32Int64Codec.decode(r);
        specodec::JsonWriter w;
        DualInt32Int64Codec.encode(w, obj);
        writeFile(outDir + "/DualInt32Int64.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualInt32Int64 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualInt32Int64 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/DualInt32Int64.gron");
        specodec::GronReader r(data);
        auto obj = DualInt32Int64Codec.decode(r);
        specodec::GronWriter w;
        DualInt32Int64Codec.encode(w, obj);
        writeFile(outDir + "/DualInt32Int64.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualInt32Int64 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualInt32Int64 gron" << std::endl; }
}

void testModelDualInt32Uint32(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/DualInt32Uint32.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = DualInt32Uint32Codec.decode(r);
        specodec::MsgPackWriter w;
        DualInt32Uint32Codec.encode(w, obj);
        writeFile(outDir + "/DualInt32Uint32.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualInt32Uint32 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualInt32Uint32 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/DualInt32Uint32.json");
        specodec::JsonReader r(data);
        auto obj = DualInt32Uint32Codec.decode(r);
        specodec::JsonWriter w;
        DualInt32Uint32Codec.encode(w, obj);
        writeFile(outDir + "/DualInt32Uint32.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualInt32Uint32 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualInt32Uint32 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/DualInt32Uint32.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = DualInt32Uint32Codec.decode(r);
        specodec::JsonWriter w;
        DualInt32Uint32Codec.encode(w, obj);
        writeFile(outDir + "/DualInt32Uint32.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualInt32Uint32 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualInt32Uint32 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/DualInt32Uint32.gron");
        specodec::GronReader r(data);
        auto obj = DualInt32Uint32Codec.decode(r);
        specodec::GronWriter w;
        DualInt32Uint32Codec.encode(w, obj);
        writeFile(outDir + "/DualInt32Uint32.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualInt32Uint32 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualInt32Uint32 gron" << std::endl; }
}

void testModelDualInt64Uint64(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/DualInt64Uint64.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = DualInt64Uint64Codec.decode(r);
        specodec::MsgPackWriter w;
        DualInt64Uint64Codec.encode(w, obj);
        writeFile(outDir + "/DualInt64Uint64.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualInt64Uint64 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualInt64Uint64 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/DualInt64Uint64.json");
        specodec::JsonReader r(data);
        auto obj = DualInt64Uint64Codec.decode(r);
        specodec::JsonWriter w;
        DualInt64Uint64Codec.encode(w, obj);
        writeFile(outDir + "/DualInt64Uint64.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualInt64Uint64 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualInt64Uint64 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/DualInt64Uint64.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = DualInt64Uint64Codec.decode(r);
        specodec::JsonWriter w;
        DualInt64Uint64Codec.encode(w, obj);
        writeFile(outDir + "/DualInt64Uint64.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualInt64Uint64 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualInt64Uint64 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/DualInt64Uint64.gron");
        specodec::GronReader r(data);
        auto obj = DualInt64Uint64Codec.decode(r);
        specodec::GronWriter w;
        DualInt64Uint64Codec.encode(w, obj);
        writeFile(outDir + "/DualInt64Uint64.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualInt64Uint64 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualInt64Uint64 gron" << std::endl; }
}

void testModelDualFloat32Float64(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/DualFloat32Float64.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = DualFloat32Float64Codec.decode(r);
        specodec::MsgPackWriter w;
        DualFloat32Float64Codec.encode(w, obj);
        writeFile(outDir + "/DualFloat32Float64.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualFloat32Float64 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualFloat32Float64 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/DualFloat32Float64.json");
        specodec::JsonReader r(data);
        auto obj = DualFloat32Float64Codec.decode(r);
        specodec::JsonWriter w;
        DualFloat32Float64Codec.encode(w, obj);
        writeFile(outDir + "/DualFloat32Float64.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualFloat32Float64 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualFloat32Float64 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/DualFloat32Float64.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = DualFloat32Float64Codec.decode(r);
        specodec::JsonWriter w;
        DualFloat32Float64Codec.encode(w, obj);
        writeFile(outDir + "/DualFloat32Float64.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualFloat32Float64 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualFloat32Float64 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/DualFloat32Float64.gron");
        specodec::GronReader r(data);
        auto obj = DualFloat32Float64Codec.decode(r);
        specodec::GronWriter w;
        DualFloat32Float64Codec.encode(w, obj);
        writeFile(outDir + "/DualFloat32Float64.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualFloat32Float64 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualFloat32Float64 gron" << std::endl; }
}

void testModelDualFloat64Boolean(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/DualFloat64Boolean.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = DualFloat64BooleanCodec.decode(r);
        specodec::MsgPackWriter w;
        DualFloat64BooleanCodec.encode(w, obj);
        writeFile(outDir + "/DualFloat64Boolean.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualFloat64Boolean mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualFloat64Boolean mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/DualFloat64Boolean.json");
        specodec::JsonReader r(data);
        auto obj = DualFloat64BooleanCodec.decode(r);
        specodec::JsonWriter w;
        DualFloat64BooleanCodec.encode(w, obj);
        writeFile(outDir + "/DualFloat64Boolean.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualFloat64Boolean json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualFloat64Boolean json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/DualFloat64Boolean.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = DualFloat64BooleanCodec.decode(r);
        specodec::JsonWriter w;
        DualFloat64BooleanCodec.encode(w, obj);
        writeFile(outDir + "/DualFloat64Boolean.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualFloat64Boolean unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualFloat64Boolean unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/DualFloat64Boolean.gron");
        specodec::GronReader r(data);
        auto obj = DualFloat64BooleanCodec.decode(r);
        specodec::GronWriter w;
        DualFloat64BooleanCodec.encode(w, obj);
        writeFile(outDir + "/DualFloat64Boolean.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualFloat64Boolean gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualFloat64Boolean gron" << std::endl; }
}

void testModelDualFloat64Bytes(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/DualFloat64Bytes.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = DualFloat64BytesCodec.decode(r);
        specodec::MsgPackWriter w;
        DualFloat64BytesCodec.encode(w, obj);
        writeFile(outDir + "/DualFloat64Bytes.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualFloat64Bytes mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualFloat64Bytes mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/DualFloat64Bytes.json");
        specodec::JsonReader r(data);
        auto obj = DualFloat64BytesCodec.decode(r);
        specodec::JsonWriter w;
        DualFloat64BytesCodec.encode(w, obj);
        writeFile(outDir + "/DualFloat64Bytes.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualFloat64Bytes json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualFloat64Bytes json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/DualFloat64Bytes.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = DualFloat64BytesCodec.decode(r);
        specodec::JsonWriter w;
        DualFloat64BytesCodec.encode(w, obj);
        writeFile(outDir + "/DualFloat64Bytes.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualFloat64Bytes unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualFloat64Bytes unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/DualFloat64Bytes.gron");
        specodec::GronReader r(data);
        auto obj = DualFloat64BytesCodec.decode(r);
        specodec::GronWriter w;
        DualFloat64BytesCodec.encode(w, obj);
        writeFile(outDir + "/DualFloat64Bytes.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualFloat64Bytes gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualFloat64Bytes gron" << std::endl; }
}

void testModelDualUint32Uint64(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/DualUint32Uint64.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = DualUint32Uint64Codec.decode(r);
        specodec::MsgPackWriter w;
        DualUint32Uint64Codec.encode(w, obj);
        writeFile(outDir + "/DualUint32Uint64.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualUint32Uint64 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualUint32Uint64 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/DualUint32Uint64.json");
        specodec::JsonReader r(data);
        auto obj = DualUint32Uint64Codec.decode(r);
        specodec::JsonWriter w;
        DualUint32Uint64Codec.encode(w, obj);
        writeFile(outDir + "/DualUint32Uint64.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualUint32Uint64 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualUint32Uint64 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/DualUint32Uint64.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = DualUint32Uint64Codec.decode(r);
        specodec::JsonWriter w;
        DualUint32Uint64Codec.encode(w, obj);
        writeFile(outDir + "/DualUint32Uint64.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualUint32Uint64 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualUint32Uint64 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/DualUint32Uint64.gron");
        specodec::GronReader r(data);
        auto obj = DualUint32Uint64Codec.decode(r);
        specodec::GronWriter w;
        DualUint32Uint64Codec.encode(w, obj);
        writeFile(outDir + "/DualUint32Uint64.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualUint32Uint64 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualUint32Uint64 gron" << std::endl; }
}

void testModelDualBooleanBytes(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/DualBooleanBytes.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = DualBooleanBytesCodec.decode(r);
        specodec::MsgPackWriter w;
        DualBooleanBytesCodec.encode(w, obj);
        writeFile(outDir + "/DualBooleanBytes.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualBooleanBytes mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualBooleanBytes mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/DualBooleanBytes.json");
        specodec::JsonReader r(data);
        auto obj = DualBooleanBytesCodec.decode(r);
        specodec::JsonWriter w;
        DualBooleanBytesCodec.encode(w, obj);
        writeFile(outDir + "/DualBooleanBytes.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualBooleanBytes json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualBooleanBytes json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/DualBooleanBytes.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = DualBooleanBytesCodec.decode(r);
        specodec::JsonWriter w;
        DualBooleanBytesCodec.encode(w, obj);
        writeFile(outDir + "/DualBooleanBytes.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualBooleanBytes unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualBooleanBytes unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/DualBooleanBytes.gron");
        specodec::GronReader r(data);
        auto obj = DualBooleanBytesCodec.decode(r);
        specodec::GronWriter w;
        DualBooleanBytesCodec.encode(w, obj);
        writeFile(outDir + "/DualBooleanBytes.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualBooleanBytes gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualBooleanBytes gron" << std::endl; }
}

void testModelDualInt8Uint8(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/DualInt8Uint8.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = DualInt8Uint8Codec.decode(r);
        specodec::MsgPackWriter w;
        DualInt8Uint8Codec.encode(w, obj);
        writeFile(outDir + "/DualInt8Uint8.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualInt8Uint8 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualInt8Uint8 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/DualInt8Uint8.json");
        specodec::JsonReader r(data);
        auto obj = DualInt8Uint8Codec.decode(r);
        specodec::JsonWriter w;
        DualInt8Uint8Codec.encode(w, obj);
        writeFile(outDir + "/DualInt8Uint8.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualInt8Uint8 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualInt8Uint8 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/DualInt8Uint8.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = DualInt8Uint8Codec.decode(r);
        specodec::JsonWriter w;
        DualInt8Uint8Codec.encode(w, obj);
        writeFile(outDir + "/DualInt8Uint8.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualInt8Uint8 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualInt8Uint8 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/DualInt8Uint8.gron");
        specodec::GronReader r(data);
        auto obj = DualInt8Uint8Codec.decode(r);
        specodec::GronWriter w;
        DualInt8Uint8Codec.encode(w, obj);
        writeFile(outDir + "/DualInt8Uint8.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualInt8Uint8 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualInt8Uint8 gron" << std::endl; }
}

void testModelDualInt16Uint16(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/DualInt16Uint16.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = DualInt16Uint16Codec.decode(r);
        specodec::MsgPackWriter w;
        DualInt16Uint16Codec.encode(w, obj);
        writeFile(outDir + "/DualInt16Uint16.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualInt16Uint16 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualInt16Uint16 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/DualInt16Uint16.json");
        specodec::JsonReader r(data);
        auto obj = DualInt16Uint16Codec.decode(r);
        specodec::JsonWriter w;
        DualInt16Uint16Codec.encode(w, obj);
        writeFile(outDir + "/DualInt16Uint16.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualInt16Uint16 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualInt16Uint16 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/DualInt16Uint16.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = DualInt16Uint16Codec.decode(r);
        specodec::JsonWriter w;
        DualInt16Uint16Codec.encode(w, obj);
        writeFile(outDir + "/DualInt16Uint16.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualInt16Uint16 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualInt16Uint16 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/DualInt16Uint16.gron");
        specodec::GronReader r(data);
        auto obj = DualInt16Uint16Codec.decode(r);
        specodec::GronWriter w;
        DualInt16Uint16Codec.encode(w, obj);
        writeFile(outDir + "/DualInt16Uint16.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualInt16Uint16 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualInt16Uint16 gron" << std::endl; }
}

void testModelDualStringInt64(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/DualStringInt64.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = DualStringInt64Codec.decode(r);
        specodec::MsgPackWriter w;
        DualStringInt64Codec.encode(w, obj);
        writeFile(outDir + "/DualStringInt64.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualStringInt64 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualStringInt64 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/DualStringInt64.json");
        specodec::JsonReader r(data);
        auto obj = DualStringInt64Codec.decode(r);
        specodec::JsonWriter w;
        DualStringInt64Codec.encode(w, obj);
        writeFile(outDir + "/DualStringInt64.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualStringInt64 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualStringInt64 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/DualStringInt64.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = DualStringInt64Codec.decode(r);
        specodec::JsonWriter w;
        DualStringInt64Codec.encode(w, obj);
        writeFile(outDir + "/DualStringInt64.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualStringInt64 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualStringInt64 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/DualStringInt64.gron");
        specodec::GronReader r(data);
        auto obj = DualStringInt64Codec.decode(r);
        specodec::GronWriter w;
        DualStringInt64Codec.encode(w, obj);
        writeFile(outDir + "/DualStringInt64.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualStringInt64 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualStringInt64 gron" << std::endl; }
}

void testModelDualStringUint64(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/DualStringUint64.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = DualStringUint64Codec.decode(r);
        specodec::MsgPackWriter w;
        DualStringUint64Codec.encode(w, obj);
        writeFile(outDir + "/DualStringUint64.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualStringUint64 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualStringUint64 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/DualStringUint64.json");
        specodec::JsonReader r(data);
        auto obj = DualStringUint64Codec.decode(r);
        specodec::JsonWriter w;
        DualStringUint64Codec.encode(w, obj);
        writeFile(outDir + "/DualStringUint64.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualStringUint64 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualStringUint64 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/DualStringUint64.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = DualStringUint64Codec.decode(r);
        specodec::JsonWriter w;
        DualStringUint64Codec.encode(w, obj);
        writeFile(outDir + "/DualStringUint64.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualStringUint64 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualStringUint64 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/DualStringUint64.gron");
        specodec::GronReader r(data);
        auto obj = DualStringUint64Codec.decode(r);
        specodec::GronWriter w;
        DualStringUint64Codec.encode(w, obj);
        writeFile(outDir + "/DualStringUint64.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualStringUint64 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualStringUint64 gron" << std::endl; }
}

void testModelDualInt32Bytes(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/DualInt32Bytes.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = DualInt32BytesCodec.decode(r);
        specodec::MsgPackWriter w;
        DualInt32BytesCodec.encode(w, obj);
        writeFile(outDir + "/DualInt32Bytes.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualInt32Bytes mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualInt32Bytes mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/DualInt32Bytes.json");
        specodec::JsonReader r(data);
        auto obj = DualInt32BytesCodec.decode(r);
        specodec::JsonWriter w;
        DualInt32BytesCodec.encode(w, obj);
        writeFile(outDir + "/DualInt32Bytes.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualInt32Bytes json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualInt32Bytes json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/DualInt32Bytes.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = DualInt32BytesCodec.decode(r);
        specodec::JsonWriter w;
        DualInt32BytesCodec.encode(w, obj);
        writeFile(outDir + "/DualInt32Bytes.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualInt32Bytes unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualInt32Bytes unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/DualInt32Bytes.gron");
        specodec::GronReader r(data);
        auto obj = DualInt32BytesCodec.decode(r);
        specodec::GronWriter w;
        DualInt32BytesCodec.encode(w, obj);
        writeFile(outDir + "/DualInt32Bytes.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualInt32Bytes gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualInt32Bytes gron" << std::endl; }
}

void testModelDualFloat64Int32(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/DualFloat64Int32.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = DualFloat64Int32Codec.decode(r);
        specodec::MsgPackWriter w;
        DualFloat64Int32Codec.encode(w, obj);
        writeFile(outDir + "/DualFloat64Int32.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualFloat64Int32 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualFloat64Int32 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/DualFloat64Int32.json");
        specodec::JsonReader r(data);
        auto obj = DualFloat64Int32Codec.decode(r);
        specodec::JsonWriter w;
        DualFloat64Int32Codec.encode(w, obj);
        writeFile(outDir + "/DualFloat64Int32.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualFloat64Int32 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualFloat64Int32 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/DualFloat64Int32.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = DualFloat64Int32Codec.decode(r);
        specodec::JsonWriter w;
        DualFloat64Int32Codec.encode(w, obj);
        writeFile(outDir + "/DualFloat64Int32.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualFloat64Int32 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualFloat64Int32 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/DualFloat64Int32.gron");
        specodec::GronReader r(data);
        auto obj = DualFloat64Int32Codec.decode(r);
        specodec::GronWriter w;
        DualFloat64Int32Codec.encode(w, obj);
        writeFile(outDir + "/DualFloat64Int32.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualFloat64Int32 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualFloat64Int32 gron" << std::endl; }
}

void testModelDualBooleanInt32(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/DualBooleanInt32.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = DualBooleanInt32Codec.decode(r);
        specodec::MsgPackWriter w;
        DualBooleanInt32Codec.encode(w, obj);
        writeFile(outDir + "/DualBooleanInt32.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualBooleanInt32 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualBooleanInt32 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/DualBooleanInt32.json");
        specodec::JsonReader r(data);
        auto obj = DualBooleanInt32Codec.decode(r);
        specodec::JsonWriter w;
        DualBooleanInt32Codec.encode(w, obj);
        writeFile(outDir + "/DualBooleanInt32.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualBooleanInt32 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualBooleanInt32 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/DualBooleanInt32.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = DualBooleanInt32Codec.decode(r);
        specodec::JsonWriter w;
        DualBooleanInt32Codec.encode(w, obj);
        writeFile(outDir + "/DualBooleanInt32.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualBooleanInt32 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualBooleanInt32 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/DualBooleanInt32.gron");
        specodec::GronReader r(data);
        auto obj = DualBooleanInt32Codec.decode(r);
        specodec::GronWriter w;
        DualBooleanInt32Codec.encode(w, obj);
        writeFile(outDir + "/DualBooleanInt32.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualBooleanInt32 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualBooleanInt32 gron" << std::endl; }
}

void testModelDualBytesInt64(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/DualBytesInt64.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = DualBytesInt64Codec.decode(r);
        specodec::MsgPackWriter w;
        DualBytesInt64Codec.encode(w, obj);
        writeFile(outDir + "/DualBytesInt64.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualBytesInt64 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualBytesInt64 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/DualBytesInt64.json");
        specodec::JsonReader r(data);
        auto obj = DualBytesInt64Codec.decode(r);
        specodec::JsonWriter w;
        DualBytesInt64Codec.encode(w, obj);
        writeFile(outDir + "/DualBytesInt64.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualBytesInt64 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualBytesInt64 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/DualBytesInt64.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = DualBytesInt64Codec.decode(r);
        specodec::JsonWriter w;
        DualBytesInt64Codec.encode(w, obj);
        writeFile(outDir + "/DualBytesInt64.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualBytesInt64 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualBytesInt64 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/DualBytesInt64.gron");
        specodec::GronReader r(data);
        auto obj = DualBytesInt64Codec.decode(r);
        specodec::GronWriter w;
        DualBytesInt64Codec.encode(w, obj);
        writeFile(outDir + "/DualBytesInt64.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualBytesInt64 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualBytesInt64 gron" << std::endl; }
}

void testModelDualInt8Float32(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/DualInt8Float32.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = DualInt8Float32Codec.decode(r);
        specodec::MsgPackWriter w;
        DualInt8Float32Codec.encode(w, obj);
        writeFile(outDir + "/DualInt8Float32.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualInt8Float32 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualInt8Float32 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/DualInt8Float32.json");
        specodec::JsonReader r(data);
        auto obj = DualInt8Float32Codec.decode(r);
        specodec::JsonWriter w;
        DualInt8Float32Codec.encode(w, obj);
        writeFile(outDir + "/DualInt8Float32.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualInt8Float32 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualInt8Float32 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/DualInt8Float32.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = DualInt8Float32Codec.decode(r);
        specodec::JsonWriter w;
        DualInt8Float32Codec.encode(w, obj);
        writeFile(outDir + "/DualInt8Float32.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualInt8Float32 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualInt8Float32 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/DualInt8Float32.gron");
        specodec::GronReader r(data);
        auto obj = DualInt8Float32Codec.decode(r);
        specodec::GronWriter w;
        DualInt8Float32Codec.encode(w, obj);
        writeFile(outDir + "/DualInt8Float32.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualInt8Float32 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualInt8Float32 gron" << std::endl; }
}

void testModelDualUint8Int16(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/DualUint8Int16.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = DualUint8Int16Codec.decode(r);
        specodec::MsgPackWriter w;
        DualUint8Int16Codec.encode(w, obj);
        writeFile(outDir + "/DualUint8Int16.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualUint8Int16 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualUint8Int16 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/DualUint8Int16.json");
        specodec::JsonReader r(data);
        auto obj = DualUint8Int16Codec.decode(r);
        specodec::JsonWriter w;
        DualUint8Int16Codec.encode(w, obj);
        writeFile(outDir + "/DualUint8Int16.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualUint8Int16 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualUint8Int16 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/DualUint8Int16.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = DualUint8Int16Codec.decode(r);
        specodec::JsonWriter w;
        DualUint8Int16Codec.encode(w, obj);
        writeFile(outDir + "/DualUint8Int16.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualUint8Int16 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualUint8Int16 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/DualUint8Int16.gron");
        specodec::GronReader r(data);
        auto obj = DualUint8Int16Codec.decode(r);
        specodec::GronWriter w;
        DualUint8Int16Codec.encode(w, obj);
        writeFile(outDir + "/DualUint8Int16.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualUint8Int16 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualUint8Int16 gron" << std::endl; }
}

void testModelDualInt64Float64(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/DualInt64Float64.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = DualInt64Float64Codec.decode(r);
        specodec::MsgPackWriter w;
        DualInt64Float64Codec.encode(w, obj);
        writeFile(outDir + "/DualInt64Float64.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualInt64Float64 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualInt64Float64 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/DualInt64Float64.json");
        specodec::JsonReader r(data);
        auto obj = DualInt64Float64Codec.decode(r);
        specodec::JsonWriter w;
        DualInt64Float64Codec.encode(w, obj);
        writeFile(outDir + "/DualInt64Float64.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualInt64Float64 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualInt64Float64 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/DualInt64Float64.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = DualInt64Float64Codec.decode(r);
        specodec::JsonWriter w;
        DualInt64Float64Codec.encode(w, obj);
        writeFile(outDir + "/DualInt64Float64.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualInt64Float64 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualInt64Float64 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/DualInt64Float64.gron");
        specodec::GronReader r(data);
        auto obj = DualInt64Float64Codec.decode(r);
        specodec::GronWriter w;
        DualInt64Float64Codec.encode(w, obj);
        writeFile(outDir + "/DualInt64Float64.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualInt64Float64 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualInt64Float64 gron" << std::endl; }
}

void testModelDualUint64String(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/DualUint64String.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = DualUint64StringCodec.decode(r);
        specodec::MsgPackWriter w;
        DualUint64StringCodec.encode(w, obj);
        writeFile(outDir + "/DualUint64String.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualUint64String mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualUint64String mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/DualUint64String.json");
        specodec::JsonReader r(data);
        auto obj = DualUint64StringCodec.decode(r);
        specodec::JsonWriter w;
        DualUint64StringCodec.encode(w, obj);
        writeFile(outDir + "/DualUint64String.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualUint64String json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualUint64String json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/DualUint64String.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = DualUint64StringCodec.decode(r);
        specodec::JsonWriter w;
        DualUint64StringCodec.encode(w, obj);
        writeFile(outDir + "/DualUint64String.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualUint64String unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualUint64String unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/DualUint64String.gron");
        specodec::GronReader r(data);
        auto obj = DualUint64StringCodec.decode(r);
        specodec::GronWriter w;
        DualUint64StringCodec.encode(w, obj);
        writeFile(outDir + "/DualUint64String.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DualUint64String gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DualUint64String gron" << std::endl; }
}

void testModelTriple01(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Triple01.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Triple01Codec.decode(r);
        specodec::MsgPackWriter w;
        Triple01Codec.encode(w, obj);
        writeFile(outDir + "/Triple01.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Triple01 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Triple01 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Triple01.json");
        specodec::JsonReader r(data);
        auto obj = Triple01Codec.decode(r);
        specodec::JsonWriter w;
        Triple01Codec.encode(w, obj);
        writeFile(outDir + "/Triple01.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Triple01 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Triple01 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Triple01.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Triple01Codec.decode(r);
        specodec::JsonWriter w;
        Triple01Codec.encode(w, obj);
        writeFile(outDir + "/Triple01.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Triple01 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Triple01 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Triple01.gron");
        specodec::GronReader r(data);
        auto obj = Triple01Codec.decode(r);
        specodec::GronWriter w;
        Triple01Codec.encode(w, obj);
        writeFile(outDir + "/Triple01.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Triple01 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Triple01 gron" << std::endl; }
}

void testModelTriple02(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Triple02.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Triple02Codec.decode(r);
        specodec::MsgPackWriter w;
        Triple02Codec.encode(w, obj);
        writeFile(outDir + "/Triple02.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Triple02 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Triple02 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Triple02.json");
        specodec::JsonReader r(data);
        auto obj = Triple02Codec.decode(r);
        specodec::JsonWriter w;
        Triple02Codec.encode(w, obj);
        writeFile(outDir + "/Triple02.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Triple02 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Triple02 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Triple02.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Triple02Codec.decode(r);
        specodec::JsonWriter w;
        Triple02Codec.encode(w, obj);
        writeFile(outDir + "/Triple02.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Triple02 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Triple02 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Triple02.gron");
        specodec::GronReader r(data);
        auto obj = Triple02Codec.decode(r);
        specodec::GronWriter w;
        Triple02Codec.encode(w, obj);
        writeFile(outDir + "/Triple02.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Triple02 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Triple02 gron" << std::endl; }
}

void testModelTriple03(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Triple03.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Triple03Codec.decode(r);
        specodec::MsgPackWriter w;
        Triple03Codec.encode(w, obj);
        writeFile(outDir + "/Triple03.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Triple03 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Triple03 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Triple03.json");
        specodec::JsonReader r(data);
        auto obj = Triple03Codec.decode(r);
        specodec::JsonWriter w;
        Triple03Codec.encode(w, obj);
        writeFile(outDir + "/Triple03.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Triple03 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Triple03 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Triple03.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Triple03Codec.decode(r);
        specodec::JsonWriter w;
        Triple03Codec.encode(w, obj);
        writeFile(outDir + "/Triple03.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Triple03 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Triple03 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Triple03.gron");
        specodec::GronReader r(data);
        auto obj = Triple03Codec.decode(r);
        specodec::GronWriter w;
        Triple03Codec.encode(w, obj);
        writeFile(outDir + "/Triple03.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Triple03 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Triple03 gron" << std::endl; }
}

void testModelTriple04(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Triple04.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Triple04Codec.decode(r);
        specodec::MsgPackWriter w;
        Triple04Codec.encode(w, obj);
        writeFile(outDir + "/Triple04.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Triple04 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Triple04 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Triple04.json");
        specodec::JsonReader r(data);
        auto obj = Triple04Codec.decode(r);
        specodec::JsonWriter w;
        Triple04Codec.encode(w, obj);
        writeFile(outDir + "/Triple04.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Triple04 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Triple04 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Triple04.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Triple04Codec.decode(r);
        specodec::JsonWriter w;
        Triple04Codec.encode(w, obj);
        writeFile(outDir + "/Triple04.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Triple04 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Triple04 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Triple04.gron");
        specodec::GronReader r(data);
        auto obj = Triple04Codec.decode(r);
        specodec::GronWriter w;
        Triple04Codec.encode(w, obj);
        writeFile(outDir + "/Triple04.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Triple04 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Triple04 gron" << std::endl; }
}

void testModelTriple05(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Triple05.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Triple05Codec.decode(r);
        specodec::MsgPackWriter w;
        Triple05Codec.encode(w, obj);
        writeFile(outDir + "/Triple05.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Triple05 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Triple05 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Triple05.json");
        specodec::JsonReader r(data);
        auto obj = Triple05Codec.decode(r);
        specodec::JsonWriter w;
        Triple05Codec.encode(w, obj);
        writeFile(outDir + "/Triple05.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Triple05 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Triple05 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Triple05.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Triple05Codec.decode(r);
        specodec::JsonWriter w;
        Triple05Codec.encode(w, obj);
        writeFile(outDir + "/Triple05.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Triple05 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Triple05 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Triple05.gron");
        specodec::GronReader r(data);
        auto obj = Triple05Codec.decode(r);
        specodec::GronWriter w;
        Triple05Codec.encode(w, obj);
        writeFile(outDir + "/Triple05.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Triple05 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Triple05 gron" << std::endl; }
}

void testModelTriple06(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Triple06.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Triple06Codec.decode(r);
        specodec::MsgPackWriter w;
        Triple06Codec.encode(w, obj);
        writeFile(outDir + "/Triple06.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Triple06 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Triple06 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Triple06.json");
        specodec::JsonReader r(data);
        auto obj = Triple06Codec.decode(r);
        specodec::JsonWriter w;
        Triple06Codec.encode(w, obj);
        writeFile(outDir + "/Triple06.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Triple06 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Triple06 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Triple06.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Triple06Codec.decode(r);
        specodec::JsonWriter w;
        Triple06Codec.encode(w, obj);
        writeFile(outDir + "/Triple06.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Triple06 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Triple06 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Triple06.gron");
        specodec::GronReader r(data);
        auto obj = Triple06Codec.decode(r);
        specodec::GronWriter w;
        Triple06Codec.encode(w, obj);
        writeFile(outDir + "/Triple06.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Triple06 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Triple06 gron" << std::endl; }
}

void testModelTriple07(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Triple07.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Triple07Codec.decode(r);
        specodec::MsgPackWriter w;
        Triple07Codec.encode(w, obj);
        writeFile(outDir + "/Triple07.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Triple07 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Triple07 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Triple07.json");
        specodec::JsonReader r(data);
        auto obj = Triple07Codec.decode(r);
        specodec::JsonWriter w;
        Triple07Codec.encode(w, obj);
        writeFile(outDir + "/Triple07.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Triple07 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Triple07 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Triple07.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Triple07Codec.decode(r);
        specodec::JsonWriter w;
        Triple07Codec.encode(w, obj);
        writeFile(outDir + "/Triple07.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Triple07 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Triple07 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Triple07.gron");
        specodec::GronReader r(data);
        auto obj = Triple07Codec.decode(r);
        specodec::GronWriter w;
        Triple07Codec.encode(w, obj);
        writeFile(outDir + "/Triple07.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Triple07 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Triple07 gron" << std::endl; }
}

void testModelTriple08(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Triple08.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Triple08Codec.decode(r);
        specodec::MsgPackWriter w;
        Triple08Codec.encode(w, obj);
        writeFile(outDir + "/Triple08.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Triple08 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Triple08 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Triple08.json");
        specodec::JsonReader r(data);
        auto obj = Triple08Codec.decode(r);
        specodec::JsonWriter w;
        Triple08Codec.encode(w, obj);
        writeFile(outDir + "/Triple08.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Triple08 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Triple08 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Triple08.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Triple08Codec.decode(r);
        specodec::JsonWriter w;
        Triple08Codec.encode(w, obj);
        writeFile(outDir + "/Triple08.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Triple08 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Triple08 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Triple08.gron");
        specodec::GronReader r(data);
        auto obj = Triple08Codec.decode(r);
        specodec::GronWriter w;
        Triple08Codec.encode(w, obj);
        writeFile(outDir + "/Triple08.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Triple08 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Triple08 gron" << std::endl; }
}

void testModelTriple09(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Triple09.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Triple09Codec.decode(r);
        specodec::MsgPackWriter w;
        Triple09Codec.encode(w, obj);
        writeFile(outDir + "/Triple09.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Triple09 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Triple09 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Triple09.json");
        specodec::JsonReader r(data);
        auto obj = Triple09Codec.decode(r);
        specodec::JsonWriter w;
        Triple09Codec.encode(w, obj);
        writeFile(outDir + "/Triple09.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Triple09 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Triple09 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Triple09.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Triple09Codec.decode(r);
        specodec::JsonWriter w;
        Triple09Codec.encode(w, obj);
        writeFile(outDir + "/Triple09.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Triple09 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Triple09 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Triple09.gron");
        specodec::GronReader r(data);
        auto obj = Triple09Codec.decode(r);
        specodec::GronWriter w;
        Triple09Codec.encode(w, obj);
        writeFile(outDir + "/Triple09.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Triple09 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Triple09 gron" << std::endl; }
}

void testModelTriple10(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Triple10.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Triple10Codec.decode(r);
        specodec::MsgPackWriter w;
        Triple10Codec.encode(w, obj);
        writeFile(outDir + "/Triple10.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Triple10 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Triple10 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Triple10.json");
        specodec::JsonReader r(data);
        auto obj = Triple10Codec.decode(r);
        specodec::JsonWriter w;
        Triple10Codec.encode(w, obj);
        writeFile(outDir + "/Triple10.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Triple10 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Triple10 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Triple10.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Triple10Codec.decode(r);
        specodec::JsonWriter w;
        Triple10Codec.encode(w, obj);
        writeFile(outDir + "/Triple10.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Triple10 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Triple10 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Triple10.gron");
        specodec::GronReader r(data);
        auto obj = Triple10Codec.decode(r);
        specodec::GronWriter w;
        Triple10Codec.encode(w, obj);
        writeFile(outDir + "/Triple10.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Triple10 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Triple10 gron" << std::endl; }
}

void testModelTriple11(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Triple11.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Triple11Codec.decode(r);
        specodec::MsgPackWriter w;
        Triple11Codec.encode(w, obj);
        writeFile(outDir + "/Triple11.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Triple11 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Triple11 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Triple11.json");
        specodec::JsonReader r(data);
        auto obj = Triple11Codec.decode(r);
        specodec::JsonWriter w;
        Triple11Codec.encode(w, obj);
        writeFile(outDir + "/Triple11.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Triple11 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Triple11 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Triple11.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Triple11Codec.decode(r);
        specodec::JsonWriter w;
        Triple11Codec.encode(w, obj);
        writeFile(outDir + "/Triple11.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Triple11 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Triple11 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Triple11.gron");
        specodec::GronReader r(data);
        auto obj = Triple11Codec.decode(r);
        specodec::GronWriter w;
        Triple11Codec.encode(w, obj);
        writeFile(outDir + "/Triple11.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Triple11 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Triple11 gron" << std::endl; }
}

void testModelTriple12(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Triple12.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Triple12Codec.decode(r);
        specodec::MsgPackWriter w;
        Triple12Codec.encode(w, obj);
        writeFile(outDir + "/Triple12.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Triple12 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Triple12 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Triple12.json");
        specodec::JsonReader r(data);
        auto obj = Triple12Codec.decode(r);
        specodec::JsonWriter w;
        Triple12Codec.encode(w, obj);
        writeFile(outDir + "/Triple12.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Triple12 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Triple12 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Triple12.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Triple12Codec.decode(r);
        specodec::JsonWriter w;
        Triple12Codec.encode(w, obj);
        writeFile(outDir + "/Triple12.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Triple12 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Triple12 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Triple12.gron");
        specodec::GronReader r(data);
        auto obj = Triple12Codec.decode(r);
        specodec::GronWriter w;
        Triple12Codec.encode(w, obj);
        writeFile(outDir + "/Triple12.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Triple12 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Triple12 gron" << std::endl; }
}

void testModelTriple13(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Triple13.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Triple13Codec.decode(r);
        specodec::MsgPackWriter w;
        Triple13Codec.encode(w, obj);
        writeFile(outDir + "/Triple13.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Triple13 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Triple13 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Triple13.json");
        specodec::JsonReader r(data);
        auto obj = Triple13Codec.decode(r);
        specodec::JsonWriter w;
        Triple13Codec.encode(w, obj);
        writeFile(outDir + "/Triple13.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Triple13 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Triple13 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Triple13.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Triple13Codec.decode(r);
        specodec::JsonWriter w;
        Triple13Codec.encode(w, obj);
        writeFile(outDir + "/Triple13.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Triple13 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Triple13 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Triple13.gron");
        specodec::GronReader r(data);
        auto obj = Triple13Codec.decode(r);
        specodec::GronWriter w;
        Triple13Codec.encode(w, obj);
        writeFile(outDir + "/Triple13.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Triple13 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Triple13 gron" << std::endl; }
}

void testModelTriple14(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Triple14.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Triple14Codec.decode(r);
        specodec::MsgPackWriter w;
        Triple14Codec.encode(w, obj);
        writeFile(outDir + "/Triple14.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Triple14 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Triple14 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Triple14.json");
        specodec::JsonReader r(data);
        auto obj = Triple14Codec.decode(r);
        specodec::JsonWriter w;
        Triple14Codec.encode(w, obj);
        writeFile(outDir + "/Triple14.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Triple14 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Triple14 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Triple14.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Triple14Codec.decode(r);
        specodec::JsonWriter w;
        Triple14Codec.encode(w, obj);
        writeFile(outDir + "/Triple14.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Triple14 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Triple14 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Triple14.gron");
        specodec::GronReader r(data);
        auto obj = Triple14Codec.decode(r);
        specodec::GronWriter w;
        Triple14Codec.encode(w, obj);
        writeFile(outDir + "/Triple14.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Triple14 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Triple14 gron" << std::endl; }
}

void testModelTriple15(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Triple15.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Triple15Codec.decode(r);
        specodec::MsgPackWriter w;
        Triple15Codec.encode(w, obj);
        writeFile(outDir + "/Triple15.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Triple15 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Triple15 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Triple15.json");
        specodec::JsonReader r(data);
        auto obj = Triple15Codec.decode(r);
        specodec::JsonWriter w;
        Triple15Codec.encode(w, obj);
        writeFile(outDir + "/Triple15.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Triple15 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Triple15 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Triple15.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Triple15Codec.decode(r);
        specodec::JsonWriter w;
        Triple15Codec.encode(w, obj);
        writeFile(outDir + "/Triple15.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Triple15 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Triple15 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Triple15.gron");
        specodec::GronReader r(data);
        auto obj = Triple15Codec.decode(r);
        specodec::GronWriter w;
        Triple15Codec.encode(w, obj);
        writeFile(outDir + "/Triple15.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Triple15 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Triple15 gron" << std::endl; }
}

void testModelFive01(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Five01.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Five01Codec.decode(r);
        specodec::MsgPackWriter w;
        Five01Codec.encode(w, obj);
        writeFile(outDir + "/Five01.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Five01 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Five01 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Five01.json");
        specodec::JsonReader r(data);
        auto obj = Five01Codec.decode(r);
        specodec::JsonWriter w;
        Five01Codec.encode(w, obj);
        writeFile(outDir + "/Five01.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Five01 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Five01 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Five01.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Five01Codec.decode(r);
        specodec::JsonWriter w;
        Five01Codec.encode(w, obj);
        writeFile(outDir + "/Five01.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Five01 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Five01 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Five01.gron");
        specodec::GronReader r(data);
        auto obj = Five01Codec.decode(r);
        specodec::GronWriter w;
        Five01Codec.encode(w, obj);
        writeFile(outDir + "/Five01.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Five01 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Five01 gron" << std::endl; }
}

void testModelFive02(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Five02.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Five02Codec.decode(r);
        specodec::MsgPackWriter w;
        Five02Codec.encode(w, obj);
        writeFile(outDir + "/Five02.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Five02 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Five02 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Five02.json");
        specodec::JsonReader r(data);
        auto obj = Five02Codec.decode(r);
        specodec::JsonWriter w;
        Five02Codec.encode(w, obj);
        writeFile(outDir + "/Five02.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Five02 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Five02 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Five02.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Five02Codec.decode(r);
        specodec::JsonWriter w;
        Five02Codec.encode(w, obj);
        writeFile(outDir + "/Five02.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Five02 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Five02 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Five02.gron");
        specodec::GronReader r(data);
        auto obj = Five02Codec.decode(r);
        specodec::GronWriter w;
        Five02Codec.encode(w, obj);
        writeFile(outDir + "/Five02.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Five02 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Five02 gron" << std::endl; }
}

void testModelFive03(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Five03.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Five03Codec.decode(r);
        specodec::MsgPackWriter w;
        Five03Codec.encode(w, obj);
        writeFile(outDir + "/Five03.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Five03 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Five03 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Five03.json");
        specodec::JsonReader r(data);
        auto obj = Five03Codec.decode(r);
        specodec::JsonWriter w;
        Five03Codec.encode(w, obj);
        writeFile(outDir + "/Five03.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Five03 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Five03 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Five03.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Five03Codec.decode(r);
        specodec::JsonWriter w;
        Five03Codec.encode(w, obj);
        writeFile(outDir + "/Five03.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Five03 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Five03 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Five03.gron");
        specodec::GronReader r(data);
        auto obj = Five03Codec.decode(r);
        specodec::GronWriter w;
        Five03Codec.encode(w, obj);
        writeFile(outDir + "/Five03.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Five03 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Five03 gron" << std::endl; }
}

void testModelFive04(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Five04.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Five04Codec.decode(r);
        specodec::MsgPackWriter w;
        Five04Codec.encode(w, obj);
        writeFile(outDir + "/Five04.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Five04 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Five04 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Five04.json");
        specodec::JsonReader r(data);
        auto obj = Five04Codec.decode(r);
        specodec::JsonWriter w;
        Five04Codec.encode(w, obj);
        writeFile(outDir + "/Five04.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Five04 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Five04 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Five04.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Five04Codec.decode(r);
        specodec::JsonWriter w;
        Five04Codec.encode(w, obj);
        writeFile(outDir + "/Five04.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Five04 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Five04 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Five04.gron");
        specodec::GronReader r(data);
        auto obj = Five04Codec.decode(r);
        specodec::GronWriter w;
        Five04Codec.encode(w, obj);
        writeFile(outDir + "/Five04.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Five04 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Five04 gron" << std::endl; }
}

void testModelFive05(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Five05.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Five05Codec.decode(r);
        specodec::MsgPackWriter w;
        Five05Codec.encode(w, obj);
        writeFile(outDir + "/Five05.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Five05 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Five05 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Five05.json");
        specodec::JsonReader r(data);
        auto obj = Five05Codec.decode(r);
        specodec::JsonWriter w;
        Five05Codec.encode(w, obj);
        writeFile(outDir + "/Five05.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Five05 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Five05 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Five05.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Five05Codec.decode(r);
        specodec::JsonWriter w;
        Five05Codec.encode(w, obj);
        writeFile(outDir + "/Five05.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Five05 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Five05 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Five05.gron");
        specodec::GronReader r(data);
        auto obj = Five05Codec.decode(r);
        specodec::GronWriter w;
        Five05Codec.encode(w, obj);
        writeFile(outDir + "/Five05.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Five05 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Five05 gron" << std::endl; }
}

void testModelFive06(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Five06.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Five06Codec.decode(r);
        specodec::MsgPackWriter w;
        Five06Codec.encode(w, obj);
        writeFile(outDir + "/Five06.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Five06 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Five06 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Five06.json");
        specodec::JsonReader r(data);
        auto obj = Five06Codec.decode(r);
        specodec::JsonWriter w;
        Five06Codec.encode(w, obj);
        writeFile(outDir + "/Five06.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Five06 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Five06 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Five06.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Five06Codec.decode(r);
        specodec::JsonWriter w;
        Five06Codec.encode(w, obj);
        writeFile(outDir + "/Five06.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Five06 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Five06 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Five06.gron");
        specodec::GronReader r(data);
        auto obj = Five06Codec.decode(r);
        specodec::GronWriter w;
        Five06Codec.encode(w, obj);
        writeFile(outDir + "/Five06.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Five06 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Five06 gron" << std::endl; }
}

void testModelFive07(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Five07.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Five07Codec.decode(r);
        specodec::MsgPackWriter w;
        Five07Codec.encode(w, obj);
        writeFile(outDir + "/Five07.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Five07 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Five07 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Five07.json");
        specodec::JsonReader r(data);
        auto obj = Five07Codec.decode(r);
        specodec::JsonWriter w;
        Five07Codec.encode(w, obj);
        writeFile(outDir + "/Five07.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Five07 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Five07 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Five07.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Five07Codec.decode(r);
        specodec::JsonWriter w;
        Five07Codec.encode(w, obj);
        writeFile(outDir + "/Five07.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Five07 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Five07 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Five07.gron");
        specodec::GronReader r(data);
        auto obj = Five07Codec.decode(r);
        specodec::GronWriter w;
        Five07Codec.encode(w, obj);
        writeFile(outDir + "/Five07.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Five07 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Five07 gron" << std::endl; }
}

void testModelFive08(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Five08.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Five08Codec.decode(r);
        specodec::MsgPackWriter w;
        Five08Codec.encode(w, obj);
        writeFile(outDir + "/Five08.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Five08 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Five08 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Five08.json");
        specodec::JsonReader r(data);
        auto obj = Five08Codec.decode(r);
        specodec::JsonWriter w;
        Five08Codec.encode(w, obj);
        writeFile(outDir + "/Five08.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Five08 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Five08 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Five08.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Five08Codec.decode(r);
        specodec::JsonWriter w;
        Five08Codec.encode(w, obj);
        writeFile(outDir + "/Five08.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Five08 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Five08 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Five08.gron");
        specodec::GronReader r(data);
        auto obj = Five08Codec.decode(r);
        specodec::GronWriter w;
        Five08Codec.encode(w, obj);
        writeFile(outDir + "/Five08.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Five08 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Five08 gron" << std::endl; }
}

void testModelFive09(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Five09.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Five09Codec.decode(r);
        specodec::MsgPackWriter w;
        Five09Codec.encode(w, obj);
        writeFile(outDir + "/Five09.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Five09 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Five09 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Five09.json");
        specodec::JsonReader r(data);
        auto obj = Five09Codec.decode(r);
        specodec::JsonWriter w;
        Five09Codec.encode(w, obj);
        writeFile(outDir + "/Five09.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Five09 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Five09 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Five09.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Five09Codec.decode(r);
        specodec::JsonWriter w;
        Five09Codec.encode(w, obj);
        writeFile(outDir + "/Five09.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Five09 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Five09 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Five09.gron");
        specodec::GronReader r(data);
        auto obj = Five09Codec.decode(r);
        specodec::GronWriter w;
        Five09Codec.encode(w, obj);
        writeFile(outDir + "/Five09.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Five09 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Five09 gron" << std::endl; }
}

void testModelFive10(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Five10.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Five10Codec.decode(r);
        specodec::MsgPackWriter w;
        Five10Codec.encode(w, obj);
        writeFile(outDir + "/Five10.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Five10 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Five10 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Five10.json");
        specodec::JsonReader r(data);
        auto obj = Five10Codec.decode(r);
        specodec::JsonWriter w;
        Five10Codec.encode(w, obj);
        writeFile(outDir + "/Five10.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Five10 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Five10 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Five10.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Five10Codec.decode(r);
        specodec::JsonWriter w;
        Five10Codec.encode(w, obj);
        writeFile(outDir + "/Five10.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Five10 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Five10 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Five10.gron");
        specodec::GronReader r(data);
        auto obj = Five10Codec.decode(r);
        specodec::GronWriter w;
        Five10Codec.encode(w, obj);
        writeFile(outDir + "/Five10.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Five10 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Five10 gron" << std::endl; }
}

void testModelTen01(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Ten01.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Ten01Codec.decode(r);
        specodec::MsgPackWriter w;
        Ten01Codec.encode(w, obj);
        writeFile(outDir + "/Ten01.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Ten01 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Ten01 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Ten01.json");
        specodec::JsonReader r(data);
        auto obj = Ten01Codec.decode(r);
        specodec::JsonWriter w;
        Ten01Codec.encode(w, obj);
        writeFile(outDir + "/Ten01.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Ten01 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Ten01 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Ten01.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Ten01Codec.decode(r);
        specodec::JsonWriter w;
        Ten01Codec.encode(w, obj);
        writeFile(outDir + "/Ten01.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Ten01 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Ten01 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Ten01.gron");
        specodec::GronReader r(data);
        auto obj = Ten01Codec.decode(r);
        specodec::GronWriter w;
        Ten01Codec.encode(w, obj);
        writeFile(outDir + "/Ten01.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Ten01 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Ten01 gron" << std::endl; }
}

void testModelTen02(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Ten02.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Ten02Codec.decode(r);
        specodec::MsgPackWriter w;
        Ten02Codec.encode(w, obj);
        writeFile(outDir + "/Ten02.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Ten02 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Ten02 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Ten02.json");
        specodec::JsonReader r(data);
        auto obj = Ten02Codec.decode(r);
        specodec::JsonWriter w;
        Ten02Codec.encode(w, obj);
        writeFile(outDir + "/Ten02.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Ten02 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Ten02 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Ten02.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Ten02Codec.decode(r);
        specodec::JsonWriter w;
        Ten02Codec.encode(w, obj);
        writeFile(outDir + "/Ten02.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Ten02 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Ten02 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Ten02.gron");
        specodec::GronReader r(data);
        auto obj = Ten02Codec.decode(r);
        specodec::GronWriter w;
        Ten02Codec.encode(w, obj);
        writeFile(outDir + "/Ten02.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Ten02 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Ten02 gron" << std::endl; }
}

void testModelTen03(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Ten03.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Ten03Codec.decode(r);
        specodec::MsgPackWriter w;
        Ten03Codec.encode(w, obj);
        writeFile(outDir + "/Ten03.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Ten03 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Ten03 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Ten03.json");
        specodec::JsonReader r(data);
        auto obj = Ten03Codec.decode(r);
        specodec::JsonWriter w;
        Ten03Codec.encode(w, obj);
        writeFile(outDir + "/Ten03.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Ten03 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Ten03 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Ten03.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Ten03Codec.decode(r);
        specodec::JsonWriter w;
        Ten03Codec.encode(w, obj);
        writeFile(outDir + "/Ten03.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Ten03 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Ten03 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Ten03.gron");
        specodec::GronReader r(data);
        auto obj = Ten03Codec.decode(r);
        specodec::GronWriter w;
        Ten03Codec.encode(w, obj);
        writeFile(outDir + "/Ten03.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Ten03 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Ten03 gron" << std::endl; }
}

void testModelTen04(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Ten04.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Ten04Codec.decode(r);
        specodec::MsgPackWriter w;
        Ten04Codec.encode(w, obj);
        writeFile(outDir + "/Ten04.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Ten04 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Ten04 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Ten04.json");
        specodec::JsonReader r(data);
        auto obj = Ten04Codec.decode(r);
        specodec::JsonWriter w;
        Ten04Codec.encode(w, obj);
        writeFile(outDir + "/Ten04.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Ten04 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Ten04 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Ten04.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Ten04Codec.decode(r);
        specodec::JsonWriter w;
        Ten04Codec.encode(w, obj);
        writeFile(outDir + "/Ten04.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Ten04 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Ten04 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Ten04.gron");
        specodec::GronReader r(data);
        auto obj = Ten04Codec.decode(r);
        specodec::GronWriter w;
        Ten04Codec.encode(w, obj);
        writeFile(outDir + "/Ten04.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Ten04 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Ten04 gron" << std::endl; }
}

void testModelTen05(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Ten05.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Ten05Codec.decode(r);
        specodec::MsgPackWriter w;
        Ten05Codec.encode(w, obj);
        writeFile(outDir + "/Ten05.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Ten05 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Ten05 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Ten05.json");
        specodec::JsonReader r(data);
        auto obj = Ten05Codec.decode(r);
        specodec::JsonWriter w;
        Ten05Codec.encode(w, obj);
        writeFile(outDir + "/Ten05.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Ten05 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Ten05 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Ten05.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Ten05Codec.decode(r);
        specodec::JsonWriter w;
        Ten05Codec.encode(w, obj);
        writeFile(outDir + "/Ten05.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Ten05 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Ten05 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Ten05.gron");
        specodec::GronReader r(data);
        auto obj = Ten05Codec.decode(r);
        specodec::GronWriter w;
        Ten05Codec.encode(w, obj);
        writeFile(outDir + "/Ten05.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Ten05 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Ten05 gron" << std::endl; }
}

void testModelArrString(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/ArrString.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = ArrStringCodec.decode(r);
        specodec::MsgPackWriter w;
        ArrStringCodec.encode(w, obj);
        writeFile(outDir + "/ArrString.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL ArrString mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL ArrString mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/ArrString.json");
        specodec::JsonReader r(data);
        auto obj = ArrStringCodec.decode(r);
        specodec::JsonWriter w;
        ArrStringCodec.encode(w, obj);
        writeFile(outDir + "/ArrString.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL ArrString json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL ArrString json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/ArrString.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = ArrStringCodec.decode(r);
        specodec::JsonWriter w;
        ArrStringCodec.encode(w, obj);
        writeFile(outDir + "/ArrString.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL ArrString unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL ArrString unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/ArrString.gron");
        specodec::GronReader r(data);
        auto obj = ArrStringCodec.decode(r);
        specodec::GronWriter w;
        ArrStringCodec.encode(w, obj);
        writeFile(outDir + "/ArrString.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL ArrString gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL ArrString gron" << std::endl; }
}

void testModelArrInt32(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/ArrInt32.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = ArrInt32Codec.decode(r);
        specodec::MsgPackWriter w;
        ArrInt32Codec.encode(w, obj);
        writeFile(outDir + "/ArrInt32.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL ArrInt32 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL ArrInt32 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/ArrInt32.json");
        specodec::JsonReader r(data);
        auto obj = ArrInt32Codec.decode(r);
        specodec::JsonWriter w;
        ArrInt32Codec.encode(w, obj);
        writeFile(outDir + "/ArrInt32.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL ArrInt32 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL ArrInt32 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/ArrInt32.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = ArrInt32Codec.decode(r);
        specodec::JsonWriter w;
        ArrInt32Codec.encode(w, obj);
        writeFile(outDir + "/ArrInt32.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL ArrInt32 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL ArrInt32 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/ArrInt32.gron");
        specodec::GronReader r(data);
        auto obj = ArrInt32Codec.decode(r);
        specodec::GronWriter w;
        ArrInt32Codec.encode(w, obj);
        writeFile(outDir + "/ArrInt32.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL ArrInt32 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL ArrInt32 gron" << std::endl; }
}

void testModelArrBoolean(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/ArrBoolean.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = ArrBooleanCodec.decode(r);
        specodec::MsgPackWriter w;
        ArrBooleanCodec.encode(w, obj);
        writeFile(outDir + "/ArrBoolean.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL ArrBoolean mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL ArrBoolean mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/ArrBoolean.json");
        specodec::JsonReader r(data);
        auto obj = ArrBooleanCodec.decode(r);
        specodec::JsonWriter w;
        ArrBooleanCodec.encode(w, obj);
        writeFile(outDir + "/ArrBoolean.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL ArrBoolean json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL ArrBoolean json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/ArrBoolean.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = ArrBooleanCodec.decode(r);
        specodec::JsonWriter w;
        ArrBooleanCodec.encode(w, obj);
        writeFile(outDir + "/ArrBoolean.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL ArrBoolean unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL ArrBoolean unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/ArrBoolean.gron");
        specodec::GronReader r(data);
        auto obj = ArrBooleanCodec.decode(r);
        specodec::GronWriter w;
        ArrBooleanCodec.encode(w, obj);
        writeFile(outDir + "/ArrBoolean.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL ArrBoolean gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL ArrBoolean gron" << std::endl; }
}

void testModelArrFloat64(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/ArrFloat64.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = ArrFloat64Codec.decode(r);
        specodec::MsgPackWriter w;
        ArrFloat64Codec.encode(w, obj);
        writeFile(outDir + "/ArrFloat64.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL ArrFloat64 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL ArrFloat64 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/ArrFloat64.json");
        specodec::JsonReader r(data);
        auto obj = ArrFloat64Codec.decode(r);
        specodec::JsonWriter w;
        ArrFloat64Codec.encode(w, obj);
        writeFile(outDir + "/ArrFloat64.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL ArrFloat64 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL ArrFloat64 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/ArrFloat64.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = ArrFloat64Codec.decode(r);
        specodec::JsonWriter w;
        ArrFloat64Codec.encode(w, obj);
        writeFile(outDir + "/ArrFloat64.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL ArrFloat64 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL ArrFloat64 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/ArrFloat64.gron");
        specodec::GronReader r(data);
        auto obj = ArrFloat64Codec.decode(r);
        specodec::GronWriter w;
        ArrFloat64Codec.encode(w, obj);
        writeFile(outDir + "/ArrFloat64.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL ArrFloat64 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL ArrFloat64 gron" << std::endl; }
}

void testModelArrBytes(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/ArrBytes.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = ArrBytesCodec.decode(r);
        specodec::MsgPackWriter w;
        ArrBytesCodec.encode(w, obj);
        writeFile(outDir + "/ArrBytes.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL ArrBytes mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL ArrBytes mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/ArrBytes.json");
        specodec::JsonReader r(data);
        auto obj = ArrBytesCodec.decode(r);
        specodec::JsonWriter w;
        ArrBytesCodec.encode(w, obj);
        writeFile(outDir + "/ArrBytes.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL ArrBytes json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL ArrBytes json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/ArrBytes.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = ArrBytesCodec.decode(r);
        specodec::JsonWriter w;
        ArrBytesCodec.encode(w, obj);
        writeFile(outDir + "/ArrBytes.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL ArrBytes unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL ArrBytes unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/ArrBytes.gron");
        specodec::GronReader r(data);
        auto obj = ArrBytesCodec.decode(r);
        specodec::GronWriter w;
        ArrBytesCodec.encode(w, obj);
        writeFile(outDir + "/ArrBytes.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL ArrBytes gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL ArrBytes gron" << std::endl; }
}

void testModelArrInt64(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/ArrInt64.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = ArrInt64Codec.decode(r);
        specodec::MsgPackWriter w;
        ArrInt64Codec.encode(w, obj);
        writeFile(outDir + "/ArrInt64.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL ArrInt64 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL ArrInt64 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/ArrInt64.json");
        specodec::JsonReader r(data);
        auto obj = ArrInt64Codec.decode(r);
        specodec::JsonWriter w;
        ArrInt64Codec.encode(w, obj);
        writeFile(outDir + "/ArrInt64.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL ArrInt64 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL ArrInt64 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/ArrInt64.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = ArrInt64Codec.decode(r);
        specodec::JsonWriter w;
        ArrInt64Codec.encode(w, obj);
        writeFile(outDir + "/ArrInt64.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL ArrInt64 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL ArrInt64 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/ArrInt64.gron");
        specodec::GronReader r(data);
        auto obj = ArrInt64Codec.decode(r);
        specodec::GronWriter w;
        ArrInt64Codec.encode(w, obj);
        writeFile(outDir + "/ArrInt64.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL ArrInt64 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL ArrInt64 gron" << std::endl; }
}

void testModelArrUint64(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/ArrUint64.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = ArrUint64Codec.decode(r);
        specodec::MsgPackWriter w;
        ArrUint64Codec.encode(w, obj);
        writeFile(outDir + "/ArrUint64.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL ArrUint64 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL ArrUint64 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/ArrUint64.json");
        specodec::JsonReader r(data);
        auto obj = ArrUint64Codec.decode(r);
        specodec::JsonWriter w;
        ArrUint64Codec.encode(w, obj);
        writeFile(outDir + "/ArrUint64.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL ArrUint64 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL ArrUint64 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/ArrUint64.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = ArrUint64Codec.decode(r);
        specodec::JsonWriter w;
        ArrUint64Codec.encode(w, obj);
        writeFile(outDir + "/ArrUint64.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL ArrUint64 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL ArrUint64 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/ArrUint64.gron");
        specodec::GronReader r(data);
        auto obj = ArrUint64Codec.decode(r);
        specodec::GronWriter w;
        ArrUint64Codec.encode(w, obj);
        writeFile(outDir + "/ArrUint64.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL ArrUint64 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL ArrUint64 gron" << std::endl; }
}

void testModelMultiArr1(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/MultiArr1.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = MultiArr1Codec.decode(r);
        specodec::MsgPackWriter w;
        MultiArr1Codec.encode(w, obj);
        writeFile(outDir + "/MultiArr1.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL MultiArr1 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL MultiArr1 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/MultiArr1.json");
        specodec::JsonReader r(data);
        auto obj = MultiArr1Codec.decode(r);
        specodec::JsonWriter w;
        MultiArr1Codec.encode(w, obj);
        writeFile(outDir + "/MultiArr1.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL MultiArr1 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL MultiArr1 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/MultiArr1.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = MultiArr1Codec.decode(r);
        specodec::JsonWriter w;
        MultiArr1Codec.encode(w, obj);
        writeFile(outDir + "/MultiArr1.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL MultiArr1 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL MultiArr1 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/MultiArr1.gron");
        specodec::GronReader r(data);
        auto obj = MultiArr1Codec.decode(r);
        specodec::GronWriter w;
        MultiArr1Codec.encode(w, obj);
        writeFile(outDir + "/MultiArr1.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL MultiArr1 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL MultiArr1 gron" << std::endl; }
}

void testModelMultiArr2(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/MultiArr2.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = MultiArr2Codec.decode(r);
        specodec::MsgPackWriter w;
        MultiArr2Codec.encode(w, obj);
        writeFile(outDir + "/MultiArr2.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL MultiArr2 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL MultiArr2 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/MultiArr2.json");
        specodec::JsonReader r(data);
        auto obj = MultiArr2Codec.decode(r);
        specodec::JsonWriter w;
        MultiArr2Codec.encode(w, obj);
        writeFile(outDir + "/MultiArr2.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL MultiArr2 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL MultiArr2 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/MultiArr2.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = MultiArr2Codec.decode(r);
        specodec::JsonWriter w;
        MultiArr2Codec.encode(w, obj);
        writeFile(outDir + "/MultiArr2.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL MultiArr2 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL MultiArr2 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/MultiArr2.gron");
        specodec::GronReader r(data);
        auto obj = MultiArr2Codec.decode(r);
        specodec::GronWriter w;
        MultiArr2Codec.encode(w, obj);
        writeFile(outDir + "/MultiArr2.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL MultiArr2 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL MultiArr2 gron" << std::endl; }
}

void testModelMultiArr3(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/MultiArr3.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = MultiArr3Codec.decode(r);
        specodec::MsgPackWriter w;
        MultiArr3Codec.encode(w, obj);
        writeFile(outDir + "/MultiArr3.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL MultiArr3 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL MultiArr3 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/MultiArr3.json");
        specodec::JsonReader r(data);
        auto obj = MultiArr3Codec.decode(r);
        specodec::JsonWriter w;
        MultiArr3Codec.encode(w, obj);
        writeFile(outDir + "/MultiArr3.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL MultiArr3 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL MultiArr3 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/MultiArr3.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = MultiArr3Codec.decode(r);
        specodec::JsonWriter w;
        MultiArr3Codec.encode(w, obj);
        writeFile(outDir + "/MultiArr3.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL MultiArr3 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL MultiArr3 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/MultiArr3.gron");
        specodec::GronReader r(data);
        auto obj = MultiArr3Codec.decode(r);
        specodec::GronWriter w;
        MultiArr3Codec.encode(w, obj);
        writeFile(outDir + "/MultiArr3.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL MultiArr3 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL MultiArr3 gron" << std::endl; }
}

void testModelMultiArr4(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/MultiArr4.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = MultiArr4Codec.decode(r);
        specodec::MsgPackWriter w;
        MultiArr4Codec.encode(w, obj);
        writeFile(outDir + "/MultiArr4.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL MultiArr4 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL MultiArr4 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/MultiArr4.json");
        specodec::JsonReader r(data);
        auto obj = MultiArr4Codec.decode(r);
        specodec::JsonWriter w;
        MultiArr4Codec.encode(w, obj);
        writeFile(outDir + "/MultiArr4.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL MultiArr4 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL MultiArr4 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/MultiArr4.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = MultiArr4Codec.decode(r);
        specodec::JsonWriter w;
        MultiArr4Codec.encode(w, obj);
        writeFile(outDir + "/MultiArr4.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL MultiArr4 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL MultiArr4 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/MultiArr4.gron");
        specodec::GronReader r(data);
        auto obj = MultiArr4Codec.decode(r);
        specodec::GronWriter w;
        MultiArr4Codec.encode(w, obj);
        writeFile(outDir + "/MultiArr4.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL MultiArr4 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL MultiArr4 gron" << std::endl; }
}

void testModelMultiArr5(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/MultiArr5.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = MultiArr5Codec.decode(r);
        specodec::MsgPackWriter w;
        MultiArr5Codec.encode(w, obj);
        writeFile(outDir + "/MultiArr5.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL MultiArr5 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL MultiArr5 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/MultiArr5.json");
        specodec::JsonReader r(data);
        auto obj = MultiArr5Codec.decode(r);
        specodec::JsonWriter w;
        MultiArr5Codec.encode(w, obj);
        writeFile(outDir + "/MultiArr5.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL MultiArr5 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL MultiArr5 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/MultiArr5.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = MultiArr5Codec.decode(r);
        specodec::JsonWriter w;
        MultiArr5Codec.encode(w, obj);
        writeFile(outDir + "/MultiArr5.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL MultiArr5 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL MultiArr5 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/MultiArr5.gron");
        specodec::GronReader r(data);
        auto obj = MultiArr5Codec.decode(r);
        specodec::GronWriter w;
        MultiArr5Codec.encode(w, obj);
        writeFile(outDir + "/MultiArr5.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL MultiArr5 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL MultiArr5 gron" << std::endl; }
}

void testModelOptCombo1(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptCombo1.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptCombo1Codec.decode(r);
        specodec::MsgPackWriter w;
        OptCombo1Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo1.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptCombo1 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptCombo1 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptCombo1.json");
        specodec::JsonReader r(data);
        auto obj = OptCombo1Codec.decode(r);
        specodec::JsonWriter w;
        OptCombo1Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo1.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptCombo1 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptCombo1 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptCombo1.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptCombo1Codec.decode(r);
        specodec::JsonWriter w;
        OptCombo1Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo1.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptCombo1 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptCombo1 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptCombo1.gron");
        specodec::GronReader r(data);
        auto obj = OptCombo1Codec.decode(r);
        specodec::GronWriter w;
        OptCombo1Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo1.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptCombo1 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptCombo1 gron" << std::endl; }
}

void testModelOptCombo2(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptCombo2.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptCombo2Codec.decode(r);
        specodec::MsgPackWriter w;
        OptCombo2Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo2.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptCombo2 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptCombo2 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptCombo2.json");
        specodec::JsonReader r(data);
        auto obj = OptCombo2Codec.decode(r);
        specodec::JsonWriter w;
        OptCombo2Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo2.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptCombo2 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptCombo2 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptCombo2.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptCombo2Codec.decode(r);
        specodec::JsonWriter w;
        OptCombo2Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo2.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptCombo2 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptCombo2 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptCombo2.gron");
        specodec::GronReader r(data);
        auto obj = OptCombo2Codec.decode(r);
        specodec::GronWriter w;
        OptCombo2Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo2.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptCombo2 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptCombo2 gron" << std::endl; }
}

void testModelOptCombo3(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptCombo3.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptCombo3Codec.decode(r);
        specodec::MsgPackWriter w;
        OptCombo3Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo3.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptCombo3 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptCombo3 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptCombo3.json");
        specodec::JsonReader r(data);
        auto obj = OptCombo3Codec.decode(r);
        specodec::JsonWriter w;
        OptCombo3Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo3.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptCombo3 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptCombo3 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptCombo3.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptCombo3Codec.decode(r);
        specodec::JsonWriter w;
        OptCombo3Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo3.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptCombo3 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptCombo3 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptCombo3.gron");
        specodec::GronReader r(data);
        auto obj = OptCombo3Codec.decode(r);
        specodec::GronWriter w;
        OptCombo3Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo3.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptCombo3 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptCombo3 gron" << std::endl; }
}

void testModelOptCombo4(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptCombo4.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptCombo4Codec.decode(r);
        specodec::MsgPackWriter w;
        OptCombo4Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo4.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptCombo4 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptCombo4 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptCombo4.json");
        specodec::JsonReader r(data);
        auto obj = OptCombo4Codec.decode(r);
        specodec::JsonWriter w;
        OptCombo4Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo4.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptCombo4 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptCombo4 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptCombo4.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptCombo4Codec.decode(r);
        specodec::JsonWriter w;
        OptCombo4Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo4.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptCombo4 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptCombo4 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptCombo4.gron");
        specodec::GronReader r(data);
        auto obj = OptCombo4Codec.decode(r);
        specodec::GronWriter w;
        OptCombo4Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo4.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptCombo4 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptCombo4 gron" << std::endl; }
}

void testModelOptCombo5(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptCombo5.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptCombo5Codec.decode(r);
        specodec::MsgPackWriter w;
        OptCombo5Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo5.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptCombo5 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptCombo5 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptCombo5.json");
        specodec::JsonReader r(data);
        auto obj = OptCombo5Codec.decode(r);
        specodec::JsonWriter w;
        OptCombo5Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo5.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptCombo5 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptCombo5 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptCombo5.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptCombo5Codec.decode(r);
        specodec::JsonWriter w;
        OptCombo5Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo5.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptCombo5 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptCombo5 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptCombo5.gron");
        specodec::GronReader r(data);
        auto obj = OptCombo5Codec.decode(r);
        specodec::GronWriter w;
        OptCombo5Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo5.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptCombo5 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptCombo5 gron" << std::endl; }
}

void testModelOptCombo6(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptCombo6.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptCombo6Codec.decode(r);
        specodec::MsgPackWriter w;
        OptCombo6Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo6.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptCombo6 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptCombo6 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptCombo6.json");
        specodec::JsonReader r(data);
        auto obj = OptCombo6Codec.decode(r);
        specodec::JsonWriter w;
        OptCombo6Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo6.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptCombo6 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptCombo6 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptCombo6.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptCombo6Codec.decode(r);
        specodec::JsonWriter w;
        OptCombo6Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo6.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptCombo6 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptCombo6 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptCombo6.gron");
        specodec::GronReader r(data);
        auto obj = OptCombo6Codec.decode(r);
        specodec::GronWriter w;
        OptCombo6Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo6.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptCombo6 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptCombo6 gron" << std::endl; }
}

void testModelOptCombo7(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptCombo7.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptCombo7Codec.decode(r);
        specodec::MsgPackWriter w;
        OptCombo7Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo7.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptCombo7 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptCombo7 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptCombo7.json");
        specodec::JsonReader r(data);
        auto obj = OptCombo7Codec.decode(r);
        specodec::JsonWriter w;
        OptCombo7Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo7.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptCombo7 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptCombo7 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptCombo7.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptCombo7Codec.decode(r);
        specodec::JsonWriter w;
        OptCombo7Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo7.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptCombo7 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptCombo7 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptCombo7.gron");
        specodec::GronReader r(data);
        auto obj = OptCombo7Codec.decode(r);
        specodec::GronWriter w;
        OptCombo7Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo7.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptCombo7 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptCombo7 gron" << std::endl; }
}

void testModelOptCombo8(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptCombo8.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptCombo8Codec.decode(r);
        specodec::MsgPackWriter w;
        OptCombo8Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo8.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptCombo8 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptCombo8 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptCombo8.json");
        specodec::JsonReader r(data);
        auto obj = OptCombo8Codec.decode(r);
        specodec::JsonWriter w;
        OptCombo8Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo8.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptCombo8 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptCombo8 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptCombo8.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptCombo8Codec.decode(r);
        specodec::JsonWriter w;
        OptCombo8Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo8.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptCombo8 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptCombo8 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptCombo8.gron");
        specodec::GronReader r(data);
        auto obj = OptCombo8Codec.decode(r);
        specodec::GronWriter w;
        OptCombo8Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo8.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptCombo8 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptCombo8 gron" << std::endl; }
}

void testModelOptCombo9(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptCombo9.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptCombo9Codec.decode(r);
        specodec::MsgPackWriter w;
        OptCombo9Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo9.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptCombo9 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptCombo9 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptCombo9.json");
        specodec::JsonReader r(data);
        auto obj = OptCombo9Codec.decode(r);
        specodec::JsonWriter w;
        OptCombo9Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo9.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptCombo9 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptCombo9 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptCombo9.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptCombo9Codec.decode(r);
        specodec::JsonWriter w;
        OptCombo9Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo9.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptCombo9 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptCombo9 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptCombo9.gron");
        specodec::GronReader r(data);
        auto obj = OptCombo9Codec.decode(r);
        specodec::GronWriter w;
        OptCombo9Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo9.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptCombo9 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptCombo9 gron" << std::endl; }
}

void testModelOptCombo10(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptCombo10.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptCombo10Codec.decode(r);
        specodec::MsgPackWriter w;
        OptCombo10Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo10.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptCombo10 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptCombo10 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptCombo10.json");
        specodec::JsonReader r(data);
        auto obj = OptCombo10Codec.decode(r);
        specodec::JsonWriter w;
        OptCombo10Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo10.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptCombo10 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptCombo10 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptCombo10.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptCombo10Codec.decode(r);
        specodec::JsonWriter w;
        OptCombo10Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo10.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptCombo10 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptCombo10 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptCombo10.gron");
        specodec::GronReader r(data);
        auto obj = OptCombo10Codec.decode(r);
        specodec::GronWriter w;
        OptCombo10Codec.encode(w, obj);
        writeFile(outDir + "/OptCombo10.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptCombo10 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptCombo10 gron" << std::endl; }
}

void testModelNestInner(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/NestInner.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = NestInnerCodec.decode(r);
        specodec::MsgPackWriter w;
        NestInnerCodec.encode(w, obj);
        writeFile(outDir + "/NestInner.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL NestInner mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL NestInner mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/NestInner.json");
        specodec::JsonReader r(data);
        auto obj = NestInnerCodec.decode(r);
        specodec::JsonWriter w;
        NestInnerCodec.encode(w, obj);
        writeFile(outDir + "/NestInner.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL NestInner json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL NestInner json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/NestInner.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = NestInnerCodec.decode(r);
        specodec::JsonWriter w;
        NestInnerCodec.encode(w, obj);
        writeFile(outDir + "/NestInner.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL NestInner unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL NestInner unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/NestInner.gron");
        specodec::GronReader r(data);
        auto obj = NestInnerCodec.decode(r);
        specodec::GronWriter w;
        NestInnerCodec.encode(w, obj);
        writeFile(outDir + "/NestInner.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL NestInner gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL NestInner gron" << std::endl; }
}

void testModelNestCoord(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/NestCoord.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = NestCoordCodec.decode(r);
        specodec::MsgPackWriter w;
        NestCoordCodec.encode(w, obj);
        writeFile(outDir + "/NestCoord.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL NestCoord mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL NestCoord mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/NestCoord.json");
        specodec::JsonReader r(data);
        auto obj = NestCoordCodec.decode(r);
        specodec::JsonWriter w;
        NestCoordCodec.encode(w, obj);
        writeFile(outDir + "/NestCoord.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL NestCoord json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL NestCoord json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/NestCoord.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = NestCoordCodec.decode(r);
        specodec::JsonWriter w;
        NestCoordCodec.encode(w, obj);
        writeFile(outDir + "/NestCoord.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL NestCoord unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL NestCoord unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/NestCoord.gron");
        specodec::GronReader r(data);
        auto obj = NestCoordCodec.decode(r);
        specodec::GronWriter w;
        NestCoordCodec.encode(w, obj);
        writeFile(outDir + "/NestCoord.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL NestCoord gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL NestCoord gron" << std::endl; }
}

void testModelNestIdVal(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/NestIdVal.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = NestIdValCodec.decode(r);
        specodec::MsgPackWriter w;
        NestIdValCodec.encode(w, obj);
        writeFile(outDir + "/NestIdVal.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL NestIdVal mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL NestIdVal mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/NestIdVal.json");
        specodec::JsonReader r(data);
        auto obj = NestIdValCodec.decode(r);
        specodec::JsonWriter w;
        NestIdValCodec.encode(w, obj);
        writeFile(outDir + "/NestIdVal.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL NestIdVal json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL NestIdVal json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/NestIdVal.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = NestIdValCodec.decode(r);
        specodec::JsonWriter w;
        NestIdValCodec.encode(w, obj);
        writeFile(outDir + "/NestIdVal.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL NestIdVal unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL NestIdVal unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/NestIdVal.gron");
        specodec::GronReader r(data);
        auto obj = NestIdValCodec.decode(r);
        specodec::GronWriter w;
        NestIdValCodec.encode(w, obj);
        writeFile(outDir + "/NestIdVal.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL NestIdVal gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL NestIdVal gron" << std::endl; }
}

void testModelNestLabel(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/NestLabel.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = NestLabelCodec.decode(r);
        specodec::MsgPackWriter w;
        NestLabelCodec.encode(w, obj);
        writeFile(outDir + "/NestLabel.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL NestLabel mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL NestLabel mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/NestLabel.json");
        specodec::JsonReader r(data);
        auto obj = NestLabelCodec.decode(r);
        specodec::JsonWriter w;
        NestLabelCodec.encode(w, obj);
        writeFile(outDir + "/NestLabel.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL NestLabel json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL NestLabel json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/NestLabel.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = NestLabelCodec.decode(r);
        specodec::JsonWriter w;
        NestLabelCodec.encode(w, obj);
        writeFile(outDir + "/NestLabel.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL NestLabel unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL NestLabel unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/NestLabel.gron");
        specodec::GronReader r(data);
        auto obj = NestLabelCodec.decode(r);
        specodec::GronWriter w;
        NestLabelCodec.encode(w, obj);
        writeFile(outDir + "/NestLabel.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL NestLabel gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL NestLabel gron" << std::endl; }
}

void testModelNestMoney(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/NestMoney.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = NestMoneyCodec.decode(r);
        specodec::MsgPackWriter w;
        NestMoneyCodec.encode(w, obj);
        writeFile(outDir + "/NestMoney.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL NestMoney mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL NestMoney mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/NestMoney.json");
        specodec::JsonReader r(data);
        auto obj = NestMoneyCodec.decode(r);
        specodec::JsonWriter w;
        NestMoneyCodec.encode(w, obj);
        writeFile(outDir + "/NestMoney.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL NestMoney json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL NestMoney json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/NestMoney.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = NestMoneyCodec.decode(r);
        specodec::JsonWriter w;
        NestMoneyCodec.encode(w, obj);
        writeFile(outDir + "/NestMoney.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL NestMoney unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL NestMoney unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/NestMoney.gron");
        specodec::GronReader r(data);
        auto obj = NestMoneyCodec.decode(r);
        specodec::GronWriter w;
        NestMoneyCodec.encode(w, obj);
        writeFile(outDir + "/NestMoney.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL NestMoney gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL NestMoney gron" << std::endl; }
}

void testModelNestRange32(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/NestRange32.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = NestRange32Codec.decode(r);
        specodec::MsgPackWriter w;
        NestRange32Codec.encode(w, obj);
        writeFile(outDir + "/NestRange32.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL NestRange32 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL NestRange32 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/NestRange32.json");
        specodec::JsonReader r(data);
        auto obj = NestRange32Codec.decode(r);
        specodec::JsonWriter w;
        NestRange32Codec.encode(w, obj);
        writeFile(outDir + "/NestRange32.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL NestRange32 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL NestRange32 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/NestRange32.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = NestRange32Codec.decode(r);
        specodec::JsonWriter w;
        NestRange32Codec.encode(w, obj);
        writeFile(outDir + "/NestRange32.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL NestRange32 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL NestRange32 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/NestRange32.gron");
        specodec::GronReader r(data);
        auto obj = NestRange32Codec.decode(r);
        specodec::GronWriter w;
        NestRange32Codec.encode(w, obj);
        writeFile(outDir + "/NestRange32.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL NestRange32 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL NestRange32 gron" << std::endl; }
}

void testModelNestAddr(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/NestAddr.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = NestAddrCodec.decode(r);
        specodec::MsgPackWriter w;
        NestAddrCodec.encode(w, obj);
        writeFile(outDir + "/NestAddr.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL NestAddr mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL NestAddr mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/NestAddr.json");
        specodec::JsonReader r(data);
        auto obj = NestAddrCodec.decode(r);
        specodec::JsonWriter w;
        NestAddrCodec.encode(w, obj);
        writeFile(outDir + "/NestAddr.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL NestAddr json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL NestAddr json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/NestAddr.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = NestAddrCodec.decode(r);
        specodec::JsonWriter w;
        NestAddrCodec.encode(w, obj);
        writeFile(outDir + "/NestAddr.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL NestAddr unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL NestAddr unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/NestAddr.gron");
        specodec::GronReader r(data);
        auto obj = NestAddrCodec.decode(r);
        specodec::GronWriter w;
        NestAddrCodec.encode(w, obj);
        writeFile(outDir + "/NestAddr.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL NestAddr gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL NestAddr gron" << std::endl; }
}

void testModelNestPoint3(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/NestPoint3.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = NestPoint3Codec.decode(r);
        specodec::MsgPackWriter w;
        NestPoint3Codec.encode(w, obj);
        writeFile(outDir + "/NestPoint3.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL NestPoint3 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL NestPoint3 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/NestPoint3.json");
        specodec::JsonReader r(data);
        auto obj = NestPoint3Codec.decode(r);
        specodec::JsonWriter w;
        NestPoint3Codec.encode(w, obj);
        writeFile(outDir + "/NestPoint3.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL NestPoint3 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL NestPoint3 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/NestPoint3.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = NestPoint3Codec.decode(r);
        specodec::JsonWriter w;
        NestPoint3Codec.encode(w, obj);
        writeFile(outDir + "/NestPoint3.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL NestPoint3 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL NestPoint3 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/NestPoint3.gron");
        specodec::GronReader r(data);
        auto obj = NestPoint3Codec.decode(r);
        specodec::GronWriter w;
        NestPoint3Codec.encode(w, obj);
        writeFile(outDir + "/NestPoint3.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL NestPoint3 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL NestPoint3 gron" << std::endl; }
}

void testModelOptNestInner(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptNestInner.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptNestInnerCodec.decode(r);
        specodec::MsgPackWriter w;
        OptNestInnerCodec.encode(w, obj);
        writeFile(outDir + "/OptNestInner.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptNestInner mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptNestInner mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptNestInner.json");
        specodec::JsonReader r(data);
        auto obj = OptNestInnerCodec.decode(r);
        specodec::JsonWriter w;
        OptNestInnerCodec.encode(w, obj);
        writeFile(outDir + "/OptNestInner.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptNestInner json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptNestInner json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptNestInner.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptNestInnerCodec.decode(r);
        specodec::JsonWriter w;
        OptNestInnerCodec.encode(w, obj);
        writeFile(outDir + "/OptNestInner.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptNestInner unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptNestInner unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptNestInner.gron");
        specodec::GronReader r(data);
        auto obj = OptNestInnerCodec.decode(r);
        specodec::GronWriter w;
        OptNestInnerCodec.encode(w, obj);
        writeFile(outDir + "/OptNestInner.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptNestInner gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptNestInner gron" << std::endl; }
}

void testModelOptNestCoord(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptNestCoord.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptNestCoordCodec.decode(r);
        specodec::MsgPackWriter w;
        OptNestCoordCodec.encode(w, obj);
        writeFile(outDir + "/OptNestCoord.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptNestCoord mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptNestCoord mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptNestCoord.json");
        specodec::JsonReader r(data);
        auto obj = OptNestCoordCodec.decode(r);
        specodec::JsonWriter w;
        OptNestCoordCodec.encode(w, obj);
        writeFile(outDir + "/OptNestCoord.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptNestCoord json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptNestCoord json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptNestCoord.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptNestCoordCodec.decode(r);
        specodec::JsonWriter w;
        OptNestCoordCodec.encode(w, obj);
        writeFile(outDir + "/OptNestCoord.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptNestCoord unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptNestCoord unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptNestCoord.gron");
        specodec::GronReader r(data);
        auto obj = OptNestCoordCodec.decode(r);
        specodec::GronWriter w;
        OptNestCoordCodec.encode(w, obj);
        writeFile(outDir + "/OptNestCoord.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptNestCoord gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptNestCoord gron" << std::endl; }
}

void testModelOptNestIdVal(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptNestIdVal.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptNestIdValCodec.decode(r);
        specodec::MsgPackWriter w;
        OptNestIdValCodec.encode(w, obj);
        writeFile(outDir + "/OptNestIdVal.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptNestIdVal mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptNestIdVal mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptNestIdVal.json");
        specodec::JsonReader r(data);
        auto obj = OptNestIdValCodec.decode(r);
        specodec::JsonWriter w;
        OptNestIdValCodec.encode(w, obj);
        writeFile(outDir + "/OptNestIdVal.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptNestIdVal json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptNestIdVal json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptNestIdVal.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptNestIdValCodec.decode(r);
        specodec::JsonWriter w;
        OptNestIdValCodec.encode(w, obj);
        writeFile(outDir + "/OptNestIdVal.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptNestIdVal unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptNestIdVal unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptNestIdVal.gron");
        specodec::GronReader r(data);
        auto obj = OptNestIdValCodec.decode(r);
        specodec::GronWriter w;
        OptNestIdValCodec.encode(w, obj);
        writeFile(outDir + "/OptNestIdVal.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptNestIdVal gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptNestIdVal gron" << std::endl; }
}

void testModelOptNestLabel(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptNestLabel.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptNestLabelCodec.decode(r);
        specodec::MsgPackWriter w;
        OptNestLabelCodec.encode(w, obj);
        writeFile(outDir + "/OptNestLabel.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptNestLabel mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptNestLabel mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptNestLabel.json");
        specodec::JsonReader r(data);
        auto obj = OptNestLabelCodec.decode(r);
        specodec::JsonWriter w;
        OptNestLabelCodec.encode(w, obj);
        writeFile(outDir + "/OptNestLabel.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptNestLabel json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptNestLabel json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptNestLabel.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptNestLabelCodec.decode(r);
        specodec::JsonWriter w;
        OptNestLabelCodec.encode(w, obj);
        writeFile(outDir + "/OptNestLabel.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptNestLabel unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptNestLabel unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptNestLabel.gron");
        specodec::GronReader r(data);
        auto obj = OptNestLabelCodec.decode(r);
        specodec::GronWriter w;
        OptNestLabelCodec.encode(w, obj);
        writeFile(outDir + "/OptNestLabel.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptNestLabel gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptNestLabel gron" << std::endl; }
}

void testModelOptNestMoney(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptNestMoney.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptNestMoneyCodec.decode(r);
        specodec::MsgPackWriter w;
        OptNestMoneyCodec.encode(w, obj);
        writeFile(outDir + "/OptNestMoney.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptNestMoney mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptNestMoney mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptNestMoney.json");
        specodec::JsonReader r(data);
        auto obj = OptNestMoneyCodec.decode(r);
        specodec::JsonWriter w;
        OptNestMoneyCodec.encode(w, obj);
        writeFile(outDir + "/OptNestMoney.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptNestMoney json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptNestMoney json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptNestMoney.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptNestMoneyCodec.decode(r);
        specodec::JsonWriter w;
        OptNestMoneyCodec.encode(w, obj);
        writeFile(outDir + "/OptNestMoney.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptNestMoney unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptNestMoney unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptNestMoney.gron");
        specodec::GronReader r(data);
        auto obj = OptNestMoneyCodec.decode(r);
        specodec::GronWriter w;
        OptNestMoneyCodec.encode(w, obj);
        writeFile(outDir + "/OptNestMoney.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptNestMoney gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptNestMoney gron" << std::endl; }
}

void testModelOptNestRange32(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptNestRange32.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptNestRange32Codec.decode(r);
        specodec::MsgPackWriter w;
        OptNestRange32Codec.encode(w, obj);
        writeFile(outDir + "/OptNestRange32.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptNestRange32 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptNestRange32 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptNestRange32.json");
        specodec::JsonReader r(data);
        auto obj = OptNestRange32Codec.decode(r);
        specodec::JsonWriter w;
        OptNestRange32Codec.encode(w, obj);
        writeFile(outDir + "/OptNestRange32.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptNestRange32 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptNestRange32 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptNestRange32.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptNestRange32Codec.decode(r);
        specodec::JsonWriter w;
        OptNestRange32Codec.encode(w, obj);
        writeFile(outDir + "/OptNestRange32.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptNestRange32 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptNestRange32 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptNestRange32.gron");
        specodec::GronReader r(data);
        auto obj = OptNestRange32Codec.decode(r);
        specodec::GronWriter w;
        OptNestRange32Codec.encode(w, obj);
        writeFile(outDir + "/OptNestRange32.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptNestRange32 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptNestRange32 gron" << std::endl; }
}

void testModelOptNestAddr(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptNestAddr.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptNestAddrCodec.decode(r);
        specodec::MsgPackWriter w;
        OptNestAddrCodec.encode(w, obj);
        writeFile(outDir + "/OptNestAddr.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptNestAddr mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptNestAddr mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptNestAddr.json");
        specodec::JsonReader r(data);
        auto obj = OptNestAddrCodec.decode(r);
        specodec::JsonWriter w;
        OptNestAddrCodec.encode(w, obj);
        writeFile(outDir + "/OptNestAddr.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptNestAddr json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptNestAddr json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptNestAddr.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptNestAddrCodec.decode(r);
        specodec::JsonWriter w;
        OptNestAddrCodec.encode(w, obj);
        writeFile(outDir + "/OptNestAddr.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptNestAddr unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptNestAddr unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptNestAddr.gron");
        specodec::GronReader r(data);
        auto obj = OptNestAddrCodec.decode(r);
        specodec::GronWriter w;
        OptNestAddrCodec.encode(w, obj);
        writeFile(outDir + "/OptNestAddr.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptNestAddr gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptNestAddr gron" << std::endl; }
}

void testModelOptNestPoint3(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptNestPoint3.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptNestPoint3Codec.decode(r);
        specodec::MsgPackWriter w;
        OptNestPoint3Codec.encode(w, obj);
        writeFile(outDir + "/OptNestPoint3.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptNestPoint3 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptNestPoint3 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptNestPoint3.json");
        specodec::JsonReader r(data);
        auto obj = OptNestPoint3Codec.decode(r);
        specodec::JsonWriter w;
        OptNestPoint3Codec.encode(w, obj);
        writeFile(outDir + "/OptNestPoint3.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptNestPoint3 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptNestPoint3 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptNestPoint3.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptNestPoint3Codec.decode(r);
        specodec::JsonWriter w;
        OptNestPoint3Codec.encode(w, obj);
        writeFile(outDir + "/OptNestPoint3.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptNestPoint3 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptNestPoint3 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptNestPoint3.gron");
        specodec::GronReader r(data);
        auto obj = OptNestPoint3Codec.decode(r);
        specodec::GronWriter w;
        OptNestPoint3Codec.encode(w, obj);
        writeFile(outDir + "/OptNestPoint3.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptNestPoint3 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptNestPoint3 gron" << std::endl; }
}

void testModelModelArr1(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/ModelArr1.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = ModelArr1Codec.decode(r);
        specodec::MsgPackWriter w;
        ModelArr1Codec.encode(w, obj);
        writeFile(outDir + "/ModelArr1.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL ModelArr1 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL ModelArr1 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/ModelArr1.json");
        specodec::JsonReader r(data);
        auto obj = ModelArr1Codec.decode(r);
        specodec::JsonWriter w;
        ModelArr1Codec.encode(w, obj);
        writeFile(outDir + "/ModelArr1.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL ModelArr1 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL ModelArr1 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/ModelArr1.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = ModelArr1Codec.decode(r);
        specodec::JsonWriter w;
        ModelArr1Codec.encode(w, obj);
        writeFile(outDir + "/ModelArr1.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL ModelArr1 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL ModelArr1 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/ModelArr1.gron");
        specodec::GronReader r(data);
        auto obj = ModelArr1Codec.decode(r);
        specodec::GronWriter w;
        ModelArr1Codec.encode(w, obj);
        writeFile(outDir + "/ModelArr1.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL ModelArr1 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL ModelArr1 gron" << std::endl; }
}

void testModelModelArr2(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/ModelArr2.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = ModelArr2Codec.decode(r);
        specodec::MsgPackWriter w;
        ModelArr2Codec.encode(w, obj);
        writeFile(outDir + "/ModelArr2.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL ModelArr2 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL ModelArr2 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/ModelArr2.json");
        specodec::JsonReader r(data);
        auto obj = ModelArr2Codec.decode(r);
        specodec::JsonWriter w;
        ModelArr2Codec.encode(w, obj);
        writeFile(outDir + "/ModelArr2.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL ModelArr2 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL ModelArr2 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/ModelArr2.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = ModelArr2Codec.decode(r);
        specodec::JsonWriter w;
        ModelArr2Codec.encode(w, obj);
        writeFile(outDir + "/ModelArr2.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL ModelArr2 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL ModelArr2 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/ModelArr2.gron");
        specodec::GronReader r(data);
        auto obj = ModelArr2Codec.decode(r);
        specodec::GronWriter w;
        ModelArr2Codec.encode(w, obj);
        writeFile(outDir + "/ModelArr2.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL ModelArr2 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL ModelArr2 gron" << std::endl; }
}

void testModelModelArr3(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/ModelArr3.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = ModelArr3Codec.decode(r);
        specodec::MsgPackWriter w;
        ModelArr3Codec.encode(w, obj);
        writeFile(outDir + "/ModelArr3.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL ModelArr3 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL ModelArr3 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/ModelArr3.json");
        specodec::JsonReader r(data);
        auto obj = ModelArr3Codec.decode(r);
        specodec::JsonWriter w;
        ModelArr3Codec.encode(w, obj);
        writeFile(outDir + "/ModelArr3.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL ModelArr3 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL ModelArr3 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/ModelArr3.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = ModelArr3Codec.decode(r);
        specodec::JsonWriter w;
        ModelArr3Codec.encode(w, obj);
        writeFile(outDir + "/ModelArr3.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL ModelArr3 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL ModelArr3 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/ModelArr3.gron");
        specodec::GronReader r(data);
        auto obj = ModelArr3Codec.decode(r);
        specodec::GronWriter w;
        ModelArr3Codec.encode(w, obj);
        writeFile(outDir + "/ModelArr3.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL ModelArr3 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL ModelArr3 gron" << std::endl; }
}

void testModelModelArr4(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/ModelArr4.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = ModelArr4Codec.decode(r);
        specodec::MsgPackWriter w;
        ModelArr4Codec.encode(w, obj);
        writeFile(outDir + "/ModelArr4.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL ModelArr4 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL ModelArr4 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/ModelArr4.json");
        specodec::JsonReader r(data);
        auto obj = ModelArr4Codec.decode(r);
        specodec::JsonWriter w;
        ModelArr4Codec.encode(w, obj);
        writeFile(outDir + "/ModelArr4.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL ModelArr4 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL ModelArr4 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/ModelArr4.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = ModelArr4Codec.decode(r);
        specodec::JsonWriter w;
        ModelArr4Codec.encode(w, obj);
        writeFile(outDir + "/ModelArr4.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL ModelArr4 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL ModelArr4 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/ModelArr4.gron");
        specodec::GronReader r(data);
        auto obj = ModelArr4Codec.decode(r);
        specodec::GronWriter w;
        ModelArr4Codec.encode(w, obj);
        writeFile(outDir + "/ModelArr4.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL ModelArr4 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL ModelArr4 gron" << std::endl; }
}

void testModelModelArr5(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/ModelArr5.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = ModelArr5Codec.decode(r);
        specodec::MsgPackWriter w;
        ModelArr5Codec.encode(w, obj);
        writeFile(outDir + "/ModelArr5.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL ModelArr5 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL ModelArr5 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/ModelArr5.json");
        specodec::JsonReader r(data);
        auto obj = ModelArr5Codec.decode(r);
        specodec::JsonWriter w;
        ModelArr5Codec.encode(w, obj);
        writeFile(outDir + "/ModelArr5.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL ModelArr5 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL ModelArr5 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/ModelArr5.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = ModelArr5Codec.decode(r);
        specodec::JsonWriter w;
        ModelArr5Codec.encode(w, obj);
        writeFile(outDir + "/ModelArr5.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL ModelArr5 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL ModelArr5 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/ModelArr5.gron");
        specodec::GronReader r(data);
        auto obj = ModelArr5Codec.decode(r);
        specodec::GronWriter w;
        ModelArr5Codec.encode(w, obj);
        writeFile(outDir + "/ModelArr5.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL ModelArr5 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL ModelArr5 gron" << std::endl; }
}

void testModelMix01(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Mix01.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Mix01Codec.decode(r);
        specodec::MsgPackWriter w;
        Mix01Codec.encode(w, obj);
        writeFile(outDir + "/Mix01.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Mix01 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Mix01 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Mix01.json");
        specodec::JsonReader r(data);
        auto obj = Mix01Codec.decode(r);
        specodec::JsonWriter w;
        Mix01Codec.encode(w, obj);
        writeFile(outDir + "/Mix01.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Mix01 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Mix01 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Mix01.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Mix01Codec.decode(r);
        specodec::JsonWriter w;
        Mix01Codec.encode(w, obj);
        writeFile(outDir + "/Mix01.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Mix01 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Mix01 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Mix01.gron");
        specodec::GronReader r(data);
        auto obj = Mix01Codec.decode(r);
        specodec::GronWriter w;
        Mix01Codec.encode(w, obj);
        writeFile(outDir + "/Mix01.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Mix01 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Mix01 gron" << std::endl; }
}

void testModelMix02(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Mix02.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Mix02Codec.decode(r);
        specodec::MsgPackWriter w;
        Mix02Codec.encode(w, obj);
        writeFile(outDir + "/Mix02.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Mix02 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Mix02 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Mix02.json");
        specodec::JsonReader r(data);
        auto obj = Mix02Codec.decode(r);
        specodec::JsonWriter w;
        Mix02Codec.encode(w, obj);
        writeFile(outDir + "/Mix02.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Mix02 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Mix02 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Mix02.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Mix02Codec.decode(r);
        specodec::JsonWriter w;
        Mix02Codec.encode(w, obj);
        writeFile(outDir + "/Mix02.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Mix02 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Mix02 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Mix02.gron");
        specodec::GronReader r(data);
        auto obj = Mix02Codec.decode(r);
        specodec::GronWriter w;
        Mix02Codec.encode(w, obj);
        writeFile(outDir + "/Mix02.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Mix02 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Mix02 gron" << std::endl; }
}

void testModelMix03(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Mix03.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Mix03Codec.decode(r);
        specodec::MsgPackWriter w;
        Mix03Codec.encode(w, obj);
        writeFile(outDir + "/Mix03.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Mix03 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Mix03 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Mix03.json");
        specodec::JsonReader r(data);
        auto obj = Mix03Codec.decode(r);
        specodec::JsonWriter w;
        Mix03Codec.encode(w, obj);
        writeFile(outDir + "/Mix03.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Mix03 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Mix03 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Mix03.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Mix03Codec.decode(r);
        specodec::JsonWriter w;
        Mix03Codec.encode(w, obj);
        writeFile(outDir + "/Mix03.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Mix03 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Mix03 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Mix03.gron");
        specodec::GronReader r(data);
        auto obj = Mix03Codec.decode(r);
        specodec::GronWriter w;
        Mix03Codec.encode(w, obj);
        writeFile(outDir + "/Mix03.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Mix03 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Mix03 gron" << std::endl; }
}

void testModelMix04(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Mix04.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Mix04Codec.decode(r);
        specodec::MsgPackWriter w;
        Mix04Codec.encode(w, obj);
        writeFile(outDir + "/Mix04.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Mix04 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Mix04 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Mix04.json");
        specodec::JsonReader r(data);
        auto obj = Mix04Codec.decode(r);
        specodec::JsonWriter w;
        Mix04Codec.encode(w, obj);
        writeFile(outDir + "/Mix04.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Mix04 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Mix04 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Mix04.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Mix04Codec.decode(r);
        specodec::JsonWriter w;
        Mix04Codec.encode(w, obj);
        writeFile(outDir + "/Mix04.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Mix04 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Mix04 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Mix04.gron");
        specodec::GronReader r(data);
        auto obj = Mix04Codec.decode(r);
        specodec::GronWriter w;
        Mix04Codec.encode(w, obj);
        writeFile(outDir + "/Mix04.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Mix04 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Mix04 gron" << std::endl; }
}

void testModelMix05(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Mix05.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Mix05Codec.decode(r);
        specodec::MsgPackWriter w;
        Mix05Codec.encode(w, obj);
        writeFile(outDir + "/Mix05.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Mix05 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Mix05 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Mix05.json");
        specodec::JsonReader r(data);
        auto obj = Mix05Codec.decode(r);
        specodec::JsonWriter w;
        Mix05Codec.encode(w, obj);
        writeFile(outDir + "/Mix05.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Mix05 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Mix05 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Mix05.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Mix05Codec.decode(r);
        specodec::JsonWriter w;
        Mix05Codec.encode(w, obj);
        writeFile(outDir + "/Mix05.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Mix05 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Mix05 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Mix05.gron");
        specodec::GronReader r(data);
        auto obj = Mix05Codec.decode(r);
        specodec::GronWriter w;
        Mix05Codec.encode(w, obj);
        writeFile(outDir + "/Mix05.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Mix05 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Mix05 gron" << std::endl; }
}

void testModelMix06(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Mix06.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Mix06Codec.decode(r);
        specodec::MsgPackWriter w;
        Mix06Codec.encode(w, obj);
        writeFile(outDir + "/Mix06.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Mix06 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Mix06 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Mix06.json");
        specodec::JsonReader r(data);
        auto obj = Mix06Codec.decode(r);
        specodec::JsonWriter w;
        Mix06Codec.encode(w, obj);
        writeFile(outDir + "/Mix06.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Mix06 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Mix06 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Mix06.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Mix06Codec.decode(r);
        specodec::JsonWriter w;
        Mix06Codec.encode(w, obj);
        writeFile(outDir + "/Mix06.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Mix06 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Mix06 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Mix06.gron");
        specodec::GronReader r(data);
        auto obj = Mix06Codec.decode(r);
        specodec::GronWriter w;
        Mix06Codec.encode(w, obj);
        writeFile(outDir + "/Mix06.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Mix06 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Mix06 gron" << std::endl; }
}

void testModelMix07(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Mix07.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Mix07Codec.decode(r);
        specodec::MsgPackWriter w;
        Mix07Codec.encode(w, obj);
        writeFile(outDir + "/Mix07.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Mix07 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Mix07 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Mix07.json");
        specodec::JsonReader r(data);
        auto obj = Mix07Codec.decode(r);
        specodec::JsonWriter w;
        Mix07Codec.encode(w, obj);
        writeFile(outDir + "/Mix07.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Mix07 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Mix07 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Mix07.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Mix07Codec.decode(r);
        specodec::JsonWriter w;
        Mix07Codec.encode(w, obj);
        writeFile(outDir + "/Mix07.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Mix07 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Mix07 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Mix07.gron");
        specodec::GronReader r(data);
        auto obj = Mix07Codec.decode(r);
        specodec::GronWriter w;
        Mix07Codec.encode(w, obj);
        writeFile(outDir + "/Mix07.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Mix07 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Mix07 gron" << std::endl; }
}

void testModelMix08(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Mix08.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Mix08Codec.decode(r);
        specodec::MsgPackWriter w;
        Mix08Codec.encode(w, obj);
        writeFile(outDir + "/Mix08.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Mix08 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Mix08 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Mix08.json");
        specodec::JsonReader r(data);
        auto obj = Mix08Codec.decode(r);
        specodec::JsonWriter w;
        Mix08Codec.encode(w, obj);
        writeFile(outDir + "/Mix08.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Mix08 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Mix08 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Mix08.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Mix08Codec.decode(r);
        specodec::JsonWriter w;
        Mix08Codec.encode(w, obj);
        writeFile(outDir + "/Mix08.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Mix08 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Mix08 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Mix08.gron");
        specodec::GronReader r(data);
        auto obj = Mix08Codec.decode(r);
        specodec::GronWriter w;
        Mix08Codec.encode(w, obj);
        writeFile(outDir + "/Mix08.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Mix08 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Mix08 gron" << std::endl; }
}

void testModelMix09(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Mix09.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Mix09Codec.decode(r);
        specodec::MsgPackWriter w;
        Mix09Codec.encode(w, obj);
        writeFile(outDir + "/Mix09.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Mix09 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Mix09 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Mix09.json");
        specodec::JsonReader r(data);
        auto obj = Mix09Codec.decode(r);
        specodec::JsonWriter w;
        Mix09Codec.encode(w, obj);
        writeFile(outDir + "/Mix09.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Mix09 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Mix09 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Mix09.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Mix09Codec.decode(r);
        specodec::JsonWriter w;
        Mix09Codec.encode(w, obj);
        writeFile(outDir + "/Mix09.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Mix09 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Mix09 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Mix09.gron");
        specodec::GronReader r(data);
        auto obj = Mix09Codec.decode(r);
        specodec::GronWriter w;
        Mix09Codec.encode(w, obj);
        writeFile(outDir + "/Mix09.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Mix09 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Mix09 gron" << std::endl; }
}

void testModelMix10(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Mix10.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Mix10Codec.decode(r);
        specodec::MsgPackWriter w;
        Mix10Codec.encode(w, obj);
        writeFile(outDir + "/Mix10.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Mix10 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Mix10 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Mix10.json");
        specodec::JsonReader r(data);
        auto obj = Mix10Codec.decode(r);
        specodec::JsonWriter w;
        Mix10Codec.encode(w, obj);
        writeFile(outDir + "/Mix10.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Mix10 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Mix10 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Mix10.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Mix10Codec.decode(r);
        specodec::JsonWriter w;
        Mix10Codec.encode(w, obj);
        writeFile(outDir + "/Mix10.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Mix10 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Mix10 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Mix10.gron");
        specodec::GronReader r(data);
        auto obj = Mix10Codec.decode(r);
        specodec::GronWriter w;
        Mix10Codec.encode(w, obj);
        writeFile(outDir + "/Mix10.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Mix10 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Mix10 gron" << std::endl; }
}

void testModelMix11(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Mix11.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Mix11Codec.decode(r);
        specodec::MsgPackWriter w;
        Mix11Codec.encode(w, obj);
        writeFile(outDir + "/Mix11.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Mix11 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Mix11 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Mix11.json");
        specodec::JsonReader r(data);
        auto obj = Mix11Codec.decode(r);
        specodec::JsonWriter w;
        Mix11Codec.encode(w, obj);
        writeFile(outDir + "/Mix11.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Mix11 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Mix11 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Mix11.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Mix11Codec.decode(r);
        specodec::JsonWriter w;
        Mix11Codec.encode(w, obj);
        writeFile(outDir + "/Mix11.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Mix11 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Mix11 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Mix11.gron");
        specodec::GronReader r(data);
        auto obj = Mix11Codec.decode(r);
        specodec::GronWriter w;
        Mix11Codec.encode(w, obj);
        writeFile(outDir + "/Mix11.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Mix11 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Mix11 gron" << std::endl; }
}

void testModelMix12(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Mix12.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Mix12Codec.decode(r);
        specodec::MsgPackWriter w;
        Mix12Codec.encode(w, obj);
        writeFile(outDir + "/Mix12.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Mix12 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Mix12 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Mix12.json");
        specodec::JsonReader r(data);
        auto obj = Mix12Codec.decode(r);
        specodec::JsonWriter w;
        Mix12Codec.encode(w, obj);
        writeFile(outDir + "/Mix12.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Mix12 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Mix12 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Mix12.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Mix12Codec.decode(r);
        specodec::JsonWriter w;
        Mix12Codec.encode(w, obj);
        writeFile(outDir + "/Mix12.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Mix12 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Mix12 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Mix12.gron");
        specodec::GronReader r(data);
        auto obj = Mix12Codec.decode(r);
        specodec::GronWriter w;
        Mix12Codec.encode(w, obj);
        writeFile(outDir + "/Mix12.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Mix12 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Mix12 gron" << std::endl; }
}

void testModelMix13(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Mix13.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Mix13Codec.decode(r);
        specodec::MsgPackWriter w;
        Mix13Codec.encode(w, obj);
        writeFile(outDir + "/Mix13.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Mix13 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Mix13 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Mix13.json");
        specodec::JsonReader r(data);
        auto obj = Mix13Codec.decode(r);
        specodec::JsonWriter w;
        Mix13Codec.encode(w, obj);
        writeFile(outDir + "/Mix13.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Mix13 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Mix13 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Mix13.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Mix13Codec.decode(r);
        specodec::JsonWriter w;
        Mix13Codec.encode(w, obj);
        writeFile(outDir + "/Mix13.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Mix13 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Mix13 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Mix13.gron");
        specodec::GronReader r(data);
        auto obj = Mix13Codec.decode(r);
        specodec::GronWriter w;
        Mix13Codec.encode(w, obj);
        writeFile(outDir + "/Mix13.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Mix13 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Mix13 gron" << std::endl; }
}

void testModelMix14(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Mix14.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Mix14Codec.decode(r);
        specodec::MsgPackWriter w;
        Mix14Codec.encode(w, obj);
        writeFile(outDir + "/Mix14.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Mix14 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Mix14 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Mix14.json");
        specodec::JsonReader r(data);
        auto obj = Mix14Codec.decode(r);
        specodec::JsonWriter w;
        Mix14Codec.encode(w, obj);
        writeFile(outDir + "/Mix14.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Mix14 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Mix14 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Mix14.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Mix14Codec.decode(r);
        specodec::JsonWriter w;
        Mix14Codec.encode(w, obj);
        writeFile(outDir + "/Mix14.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Mix14 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Mix14 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Mix14.gron");
        specodec::GronReader r(data);
        auto obj = Mix14Codec.decode(r);
        specodec::GronWriter w;
        Mix14Codec.encode(w, obj);
        writeFile(outDir + "/Mix14.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Mix14 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Mix14 gron" << std::endl; }
}

void testModelMix15(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Mix15.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Mix15Codec.decode(r);
        specodec::MsgPackWriter w;
        Mix15Codec.encode(w, obj);
        writeFile(outDir + "/Mix15.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Mix15 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Mix15 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Mix15.json");
        specodec::JsonReader r(data);
        auto obj = Mix15Codec.decode(r);
        specodec::JsonWriter w;
        Mix15Codec.encode(w, obj);
        writeFile(outDir + "/Mix15.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Mix15 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Mix15 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Mix15.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Mix15Codec.decode(r);
        specodec::JsonWriter w;
        Mix15Codec.encode(w, obj);
        writeFile(outDir + "/Mix15.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Mix15 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Mix15 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Mix15.gron");
        specodec::GronReader r(data);
        auto obj = Mix15Codec.decode(r);
        specodec::GronWriter w;
        Mix15Codec.encode(w, obj);
        writeFile(outDir + "/Mix15.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Mix15 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Mix15 gron" << std::endl; }
}

void testModelAllOpt1(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/AllOpt1.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = AllOpt1Codec.decode(r);
        specodec::MsgPackWriter w;
        AllOpt1Codec.encode(w, obj);
        writeFile(outDir + "/AllOpt1.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL AllOpt1 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL AllOpt1 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/AllOpt1.json");
        specodec::JsonReader r(data);
        auto obj = AllOpt1Codec.decode(r);
        specodec::JsonWriter w;
        AllOpt1Codec.encode(w, obj);
        writeFile(outDir + "/AllOpt1.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL AllOpt1 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL AllOpt1 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/AllOpt1.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = AllOpt1Codec.decode(r);
        specodec::JsonWriter w;
        AllOpt1Codec.encode(w, obj);
        writeFile(outDir + "/AllOpt1.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL AllOpt1 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL AllOpt1 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/AllOpt1.gron");
        specodec::GronReader r(data);
        auto obj = AllOpt1Codec.decode(r);
        specodec::GronWriter w;
        AllOpt1Codec.encode(w, obj);
        writeFile(outDir + "/AllOpt1.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL AllOpt1 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL AllOpt1 gron" << std::endl; }
}

void testModelAllOpt2(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/AllOpt2.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = AllOpt2Codec.decode(r);
        specodec::MsgPackWriter w;
        AllOpt2Codec.encode(w, obj);
        writeFile(outDir + "/AllOpt2.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL AllOpt2 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL AllOpt2 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/AllOpt2.json");
        specodec::JsonReader r(data);
        auto obj = AllOpt2Codec.decode(r);
        specodec::JsonWriter w;
        AllOpt2Codec.encode(w, obj);
        writeFile(outDir + "/AllOpt2.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL AllOpt2 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL AllOpt2 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/AllOpt2.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = AllOpt2Codec.decode(r);
        specodec::JsonWriter w;
        AllOpt2Codec.encode(w, obj);
        writeFile(outDir + "/AllOpt2.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL AllOpt2 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL AllOpt2 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/AllOpt2.gron");
        specodec::GronReader r(data);
        auto obj = AllOpt2Codec.decode(r);
        specodec::GronWriter w;
        AllOpt2Codec.encode(w, obj);
        writeFile(outDir + "/AllOpt2.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL AllOpt2 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL AllOpt2 gron" << std::endl; }
}

void testModelAllOpt3(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/AllOpt3.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = AllOpt3Codec.decode(r);
        specodec::MsgPackWriter w;
        AllOpt3Codec.encode(w, obj);
        writeFile(outDir + "/AllOpt3.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL AllOpt3 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL AllOpt3 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/AllOpt3.json");
        specodec::JsonReader r(data);
        auto obj = AllOpt3Codec.decode(r);
        specodec::JsonWriter w;
        AllOpt3Codec.encode(w, obj);
        writeFile(outDir + "/AllOpt3.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL AllOpt3 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL AllOpt3 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/AllOpt3.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = AllOpt3Codec.decode(r);
        specodec::JsonWriter w;
        AllOpt3Codec.encode(w, obj);
        writeFile(outDir + "/AllOpt3.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL AllOpt3 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL AllOpt3 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/AllOpt3.gron");
        specodec::GronReader r(data);
        auto obj = AllOpt3Codec.decode(r);
        specodec::GronWriter w;
        AllOpt3Codec.encode(w, obj);
        writeFile(outDir + "/AllOpt3.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL AllOpt3 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL AllOpt3 gron" << std::endl; }
}

void testModelAllOpt4(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/AllOpt4.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = AllOpt4Codec.decode(r);
        specodec::MsgPackWriter w;
        AllOpt4Codec.encode(w, obj);
        writeFile(outDir + "/AllOpt4.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL AllOpt4 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL AllOpt4 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/AllOpt4.json");
        specodec::JsonReader r(data);
        auto obj = AllOpt4Codec.decode(r);
        specodec::JsonWriter w;
        AllOpt4Codec.encode(w, obj);
        writeFile(outDir + "/AllOpt4.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL AllOpt4 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL AllOpt4 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/AllOpt4.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = AllOpt4Codec.decode(r);
        specodec::JsonWriter w;
        AllOpt4Codec.encode(w, obj);
        writeFile(outDir + "/AllOpt4.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL AllOpt4 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL AllOpt4 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/AllOpt4.gron");
        specodec::GronReader r(data);
        auto obj = AllOpt4Codec.decode(r);
        specodec::GronWriter w;
        AllOpt4Codec.encode(w, obj);
        writeFile(outDir + "/AllOpt4.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL AllOpt4 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL AllOpt4 gron" << std::endl; }
}

void testModelAllOpt5(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/AllOpt5.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = AllOpt5Codec.decode(r);
        specodec::MsgPackWriter w;
        AllOpt5Codec.encode(w, obj);
        writeFile(outDir + "/AllOpt5.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL AllOpt5 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL AllOpt5 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/AllOpt5.json");
        specodec::JsonReader r(data);
        auto obj = AllOpt5Codec.decode(r);
        specodec::JsonWriter w;
        AllOpt5Codec.encode(w, obj);
        writeFile(outDir + "/AllOpt5.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL AllOpt5 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL AllOpt5 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/AllOpt5.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = AllOpt5Codec.decode(r);
        specodec::JsonWriter w;
        AllOpt5Codec.encode(w, obj);
        writeFile(outDir + "/AllOpt5.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL AllOpt5 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL AllOpt5 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/AllOpt5.gron");
        specodec::GronReader r(data);
        auto obj = AllOpt5Codec.decode(r);
        specodec::GronWriter w;
        AllOpt5Codec.encode(w, obj);
        writeFile(outDir + "/AllOpt5.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL AllOpt5 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL AllOpt5 gron" << std::endl; }
}

void testModelRecList(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/RecList.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = RecListCodec.decode(r);
        specodec::MsgPackWriter w;
        RecListCodec.encode(w, obj);
        writeFile(outDir + "/RecList.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL RecList mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL RecList mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/RecList.json");
        specodec::JsonReader r(data);
        auto obj = RecListCodec.decode(r);
        specodec::JsonWriter w;
        RecListCodec.encode(w, obj);
        writeFile(outDir + "/RecList.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL RecList json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL RecList json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/RecList.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = RecListCodec.decode(r);
        specodec::JsonWriter w;
        RecListCodec.encode(w, obj);
        writeFile(outDir + "/RecList.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL RecList unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL RecList unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/RecList.gron");
        specodec::GronReader r(data);
        auto obj = RecListCodec.decode(r);
        specodec::GronWriter w;
        RecListCodec.encode(w, obj);
        writeFile(outDir + "/RecList.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL RecList gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL RecList gron" << std::endl; }
}

void testModelRecTree(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/RecTree.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = RecTreeCodec.decode(r);
        specodec::MsgPackWriter w;
        RecTreeCodec.encode(w, obj);
        writeFile(outDir + "/RecTree.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL RecTree mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL RecTree mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/RecTree.json");
        specodec::JsonReader r(data);
        auto obj = RecTreeCodec.decode(r);
        specodec::JsonWriter w;
        RecTreeCodec.encode(w, obj);
        writeFile(outDir + "/RecTree.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL RecTree json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL RecTree json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/RecTree.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = RecTreeCodec.decode(r);
        specodec::JsonWriter w;
        RecTreeCodec.encode(w, obj);
        writeFile(outDir + "/RecTree.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL RecTree unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL RecTree unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/RecTree.gron");
        specodec::GronReader r(data);
        auto obj = RecTreeCodec.decode(r);
        specodec::GronWriter w;
        RecTreeCodec.encode(w, obj);
        writeFile(outDir + "/RecTree.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL RecTree gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL RecTree gron" << std::endl; }
}

void testModelRecChain(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/RecChain.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = RecChainCodec.decode(r);
        specodec::MsgPackWriter w;
        RecChainCodec.encode(w, obj);
        writeFile(outDir + "/RecChain.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL RecChain mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL RecChain mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/RecChain.json");
        specodec::JsonReader r(data);
        auto obj = RecChainCodec.decode(r);
        specodec::JsonWriter w;
        RecChainCodec.encode(w, obj);
        writeFile(outDir + "/RecChain.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL RecChain json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL RecChain json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/RecChain.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = RecChainCodec.decode(r);
        specodec::JsonWriter w;
        RecChainCodec.encode(w, obj);
        writeFile(outDir + "/RecChain.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL RecChain unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL RecChain unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/RecChain.gron");
        specodec::GronReader r(data);
        auto obj = RecChainCodec.decode(r);
        specodec::GronWriter w;
        RecChainCodec.encode(w, obj);
        writeFile(outDir + "/RecChain.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL RecChain gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL RecChain gron" << std::endl; }
}

void testModelRecWrap(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/RecWrap.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = RecWrapCodec.decode(r);
        specodec::MsgPackWriter w;
        RecWrapCodec.encode(w, obj);
        writeFile(outDir + "/RecWrap.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL RecWrap mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL RecWrap mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/RecWrap.json");
        specodec::JsonReader r(data);
        auto obj = RecWrapCodec.decode(r);
        specodec::JsonWriter w;
        RecWrapCodec.encode(w, obj);
        writeFile(outDir + "/RecWrap.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL RecWrap json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL RecWrap json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/RecWrap.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = RecWrapCodec.decode(r);
        specodec::JsonWriter w;
        RecWrapCodec.encode(w, obj);
        writeFile(outDir + "/RecWrap.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL RecWrap unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL RecWrap unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/RecWrap.gron");
        specodec::GronReader r(data);
        auto obj = RecWrapCodec.decode(r);
        specodec::GronWriter w;
        RecWrapCodec.encode(w, obj);
        writeFile(outDir + "/RecWrap.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL RecWrap gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL RecWrap gron" << std::endl; }
}

void testModelRecWide(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/RecWide.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = RecWideCodec.decode(r);
        specodec::MsgPackWriter w;
        RecWideCodec.encode(w, obj);
        writeFile(outDir + "/RecWide.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL RecWide mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL RecWide mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/RecWide.json");
        specodec::JsonReader r(data);
        auto obj = RecWideCodec.decode(r);
        specodec::JsonWriter w;
        RecWideCodec.encode(w, obj);
        writeFile(outDir + "/RecWide.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL RecWide json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL RecWide json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/RecWide.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = RecWideCodec.decode(r);
        specodec::JsonWriter w;
        RecWideCodec.encode(w, obj);
        writeFile(outDir + "/RecWide.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL RecWide unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL RecWide unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/RecWide.gron");
        specodec::GronReader r(data);
        auto obj = RecWideCodec.decode(r);
        specodec::GronWriter w;
        RecWideCodec.encode(w, obj);
        writeFile(outDir + "/RecWide.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL RecWide gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL RecWide gron" << std::endl; }
}

void testModelWide20(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Wide20.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Wide20Codec.decode(r);
        specodec::MsgPackWriter w;
        Wide20Codec.encode(w, obj);
        writeFile(outDir + "/Wide20.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Wide20 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Wide20 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Wide20.json");
        specodec::JsonReader r(data);
        auto obj = Wide20Codec.decode(r);
        specodec::JsonWriter w;
        Wide20Codec.encode(w, obj);
        writeFile(outDir + "/Wide20.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Wide20 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Wide20 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Wide20.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Wide20Codec.decode(r);
        specodec::JsonWriter w;
        Wide20Codec.encode(w, obj);
        writeFile(outDir + "/Wide20.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Wide20 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Wide20 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Wide20.gron");
        specodec::GronReader r(data);
        auto obj = Wide20Codec.decode(r);
        specodec::GronWriter w;
        Wide20Codec.encode(w, obj);
        writeFile(outDir + "/Wide20.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Wide20 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Wide20 gron" << std::endl; }
}

void testModelWide25(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Wide25.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Wide25Codec.decode(r);
        specodec::MsgPackWriter w;
        Wide25Codec.encode(w, obj);
        writeFile(outDir + "/Wide25.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Wide25 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Wide25 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Wide25.json");
        specodec::JsonReader r(data);
        auto obj = Wide25Codec.decode(r);
        specodec::JsonWriter w;
        Wide25Codec.encode(w, obj);
        writeFile(outDir + "/Wide25.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Wide25 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Wide25 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Wide25.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Wide25Codec.decode(r);
        specodec::JsonWriter w;
        Wide25Codec.encode(w, obj);
        writeFile(outDir + "/Wide25.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Wide25 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Wide25 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Wide25.gron");
        specodec::GronReader r(data);
        auto obj = Wide25Codec.decode(r);
        specodec::GronWriter w;
        Wide25Codec.encode(w, obj);
        writeFile(outDir + "/Wide25.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Wide25 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Wide25 gron" << std::endl; }
}

void testModelWide30(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Wide30.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Wide30Codec.decode(r);
        specodec::MsgPackWriter w;
        Wide30Codec.encode(w, obj);
        writeFile(outDir + "/Wide30.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Wide30 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Wide30 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Wide30.json");
        specodec::JsonReader r(data);
        auto obj = Wide30Codec.decode(r);
        specodec::JsonWriter w;
        Wide30Codec.encode(w, obj);
        writeFile(outDir + "/Wide30.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Wide30 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Wide30 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Wide30.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Wide30Codec.decode(r);
        specodec::JsonWriter w;
        Wide30Codec.encode(w, obj);
        writeFile(outDir + "/Wide30.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Wide30 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Wide30 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Wide30.gron");
        specodec::GronReader r(data);
        auto obj = Wide30Codec.decode(r);
        specodec::GronWriter w;
        Wide30Codec.encode(w, obj);
        writeFile(outDir + "/Wide30.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Wide30 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Wide30 gron" << std::endl; }
}

void testModelWide35(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Wide35.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Wide35Codec.decode(r);
        specodec::MsgPackWriter w;
        Wide35Codec.encode(w, obj);
        writeFile(outDir + "/Wide35.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Wide35 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Wide35 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Wide35.json");
        specodec::JsonReader r(data);
        auto obj = Wide35Codec.decode(r);
        specodec::JsonWriter w;
        Wide35Codec.encode(w, obj);
        writeFile(outDir + "/Wide35.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Wide35 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Wide35 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Wide35.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Wide35Codec.decode(r);
        specodec::JsonWriter w;
        Wide35Codec.encode(w, obj);
        writeFile(outDir + "/Wide35.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Wide35 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Wide35 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Wide35.gron");
        specodec::GronReader r(data);
        auto obj = Wide35Codec.decode(r);
        specodec::GronWriter w;
        Wide35Codec.encode(w, obj);
        writeFile(outDir + "/Wide35.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Wide35 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Wide35 gron" << std::endl; }
}

void testModelWide40(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/Wide40.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = Wide40Codec.decode(r);
        specodec::MsgPackWriter w;
        Wide40Codec.encode(w, obj);
        writeFile(outDir + "/Wide40.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Wide40 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Wide40 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/Wide40.json");
        specodec::JsonReader r(data);
        auto obj = Wide40Codec.decode(r);
        specodec::JsonWriter w;
        Wide40Codec.encode(w, obj);
        writeFile(outDir + "/Wide40.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Wide40 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Wide40 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/Wide40.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = Wide40Codec.decode(r);
        specodec::JsonWriter w;
        Wide40Codec.encode(w, obj);
        writeFile(outDir + "/Wide40.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Wide40 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Wide40 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/Wide40.gron");
        specodec::GronReader r(data);
        auto obj = Wide40Codec.decode(r);
        specodec::GronWriter w;
        Wide40Codec.encode(w, obj);
        writeFile(outDir + "/Wide40.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL Wide40 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL Wide40 gron" << std::endl; }
}

void testModelEdgeEmpty(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/EdgeEmpty.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = EdgeEmptyCodec.decode(r);
        specodec::MsgPackWriter w;
        EdgeEmptyCodec.encode(w, obj);
        writeFile(outDir + "/EdgeEmpty.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL EdgeEmpty mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL EdgeEmpty mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/EdgeEmpty.json");
        specodec::JsonReader r(data);
        auto obj = EdgeEmptyCodec.decode(r);
        specodec::JsonWriter w;
        EdgeEmptyCodec.encode(w, obj);
        writeFile(outDir + "/EdgeEmpty.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL EdgeEmpty json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL EdgeEmpty json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/EdgeEmpty.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = EdgeEmptyCodec.decode(r);
        specodec::JsonWriter w;
        EdgeEmptyCodec.encode(w, obj);
        writeFile(outDir + "/EdgeEmpty.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL EdgeEmpty unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL EdgeEmpty unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/EdgeEmpty.gron");
        specodec::GronReader r(data);
        auto obj = EdgeEmptyCodec.decode(r);
        specodec::GronWriter w;
        EdgeEmptyCodec.encode(w, obj);
        writeFile(outDir + "/EdgeEmpty.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL EdgeEmpty gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL EdgeEmpty gron" << std::endl; }
}

void testModelEdgeOneOpt(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/EdgeOneOpt.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = EdgeOneOptCodec.decode(r);
        specodec::MsgPackWriter w;
        EdgeOneOptCodec.encode(w, obj);
        writeFile(outDir + "/EdgeOneOpt.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL EdgeOneOpt mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL EdgeOneOpt mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/EdgeOneOpt.json");
        specodec::JsonReader r(data);
        auto obj = EdgeOneOptCodec.decode(r);
        specodec::JsonWriter w;
        EdgeOneOptCodec.encode(w, obj);
        writeFile(outDir + "/EdgeOneOpt.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL EdgeOneOpt json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL EdgeOneOpt json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/EdgeOneOpt.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = EdgeOneOptCodec.decode(r);
        specodec::JsonWriter w;
        EdgeOneOptCodec.encode(w, obj);
        writeFile(outDir + "/EdgeOneOpt.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL EdgeOneOpt unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL EdgeOneOpt unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/EdgeOneOpt.gron");
        specodec::GronReader r(data);
        auto obj = EdgeOneOptCodec.decode(r);
        specodec::GronWriter w;
        EdgeOneOptCodec.encode(w, obj);
        writeFile(outDir + "/EdgeOneOpt.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL EdgeOneOpt gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL EdgeOneOpt gron" << std::endl; }
}

void testModelEdgeBigNums(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/EdgeBigNums.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = EdgeBigNumsCodec.decode(r);
        specodec::MsgPackWriter w;
        EdgeBigNumsCodec.encode(w, obj);
        writeFile(outDir + "/EdgeBigNums.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL EdgeBigNums mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL EdgeBigNums mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/EdgeBigNums.json");
        specodec::JsonReader r(data);
        auto obj = EdgeBigNumsCodec.decode(r);
        specodec::JsonWriter w;
        EdgeBigNumsCodec.encode(w, obj);
        writeFile(outDir + "/EdgeBigNums.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL EdgeBigNums json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL EdgeBigNums json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/EdgeBigNums.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = EdgeBigNumsCodec.decode(r);
        specodec::JsonWriter w;
        EdgeBigNumsCodec.encode(w, obj);
        writeFile(outDir + "/EdgeBigNums.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL EdgeBigNums unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL EdgeBigNums unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/EdgeBigNums.gron");
        specodec::GronReader r(data);
        auto obj = EdgeBigNumsCodec.decode(r);
        specodec::GronWriter w;
        EdgeBigNumsCodec.encode(w, obj);
        writeFile(outDir + "/EdgeBigNums.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL EdgeBigNums gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL EdgeBigNums gron" << std::endl; }
}

void testModelEdgeZeroVals(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/EdgeZeroVals.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = EdgeZeroValsCodec.decode(r);
        specodec::MsgPackWriter w;
        EdgeZeroValsCodec.encode(w, obj);
        writeFile(outDir + "/EdgeZeroVals.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL EdgeZeroVals mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL EdgeZeroVals mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/EdgeZeroVals.json");
        specodec::JsonReader r(data);
        auto obj = EdgeZeroValsCodec.decode(r);
        specodec::JsonWriter w;
        EdgeZeroValsCodec.encode(w, obj);
        writeFile(outDir + "/EdgeZeroVals.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL EdgeZeroVals json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL EdgeZeroVals json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/EdgeZeroVals.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = EdgeZeroValsCodec.decode(r);
        specodec::JsonWriter w;
        EdgeZeroValsCodec.encode(w, obj);
        writeFile(outDir + "/EdgeZeroVals.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL EdgeZeroVals unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL EdgeZeroVals unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/EdgeZeroVals.gron");
        specodec::GronReader r(data);
        auto obj = EdgeZeroValsCodec.decode(r);
        specodec::GronWriter w;
        EdgeZeroValsCodec.encode(w, obj);
        writeFile(outDir + "/EdgeZeroVals.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL EdgeZeroVals gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL EdgeZeroVals gron" << std::endl; }
}

void testModelEdgeNullable(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/EdgeNullable.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = EdgeNullableCodec.decode(r);
        specodec::MsgPackWriter w;
        EdgeNullableCodec.encode(w, obj);
        writeFile(outDir + "/EdgeNullable.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL EdgeNullable mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL EdgeNullable mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/EdgeNullable.json");
        specodec::JsonReader r(data);
        auto obj = EdgeNullableCodec.decode(r);
        specodec::JsonWriter w;
        EdgeNullableCodec.encode(w, obj);
        writeFile(outDir + "/EdgeNullable.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL EdgeNullable json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL EdgeNullable json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/EdgeNullable.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = EdgeNullableCodec.decode(r);
        specodec::JsonWriter w;
        EdgeNullableCodec.encode(w, obj);
        writeFile(outDir + "/EdgeNullable.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL EdgeNullable unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL EdgeNullable unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/EdgeNullable.gron");
        specodec::GronReader r(data);
        auto obj = EdgeNullableCodec.decode(r);
        specodec::GronWriter w;
        EdgeNullableCodec.encode(w, obj);
        writeFile(outDir + "/EdgeNullable.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL EdgeNullable gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL EdgeNullable gron" << std::endl; }
}

void testModelEdgeNegZero(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/EdgeNegZero.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = EdgeNegZeroCodec.decode(r);
        specodec::MsgPackWriter w;
        EdgeNegZeroCodec.encode(w, obj);
        writeFile(outDir + "/EdgeNegZero.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL EdgeNegZero mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL EdgeNegZero mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/EdgeNegZero.json");
        specodec::JsonReader r(data);
        auto obj = EdgeNegZeroCodec.decode(r);
        specodec::JsonWriter w;
        EdgeNegZeroCodec.encode(w, obj);
        writeFile(outDir + "/EdgeNegZero.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL EdgeNegZero json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL EdgeNegZero json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/EdgeNegZero.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = EdgeNegZeroCodec.decode(r);
        specodec::JsonWriter w;
        EdgeNegZeroCodec.encode(w, obj);
        writeFile(outDir + "/EdgeNegZero.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL EdgeNegZero unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL EdgeNegZero unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/EdgeNegZero.gron");
        specodec::GronReader r(data);
        auto obj = EdgeNegZeroCodec.decode(r);
        specodec::GronWriter w;
        EdgeNegZeroCodec.encode(w, obj);
        writeFile(outDir + "/EdgeNegZero.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL EdgeNegZero gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL EdgeNegZero gron" << std::endl; }
}

void testModelEdgeNullByte(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/EdgeNullByte.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = EdgeNullByteCodec.decode(r);
        specodec::MsgPackWriter w;
        EdgeNullByteCodec.encode(w, obj);
        writeFile(outDir + "/EdgeNullByte.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL EdgeNullByte mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL EdgeNullByte mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/EdgeNullByte.json");
        specodec::JsonReader r(data);
        auto obj = EdgeNullByteCodec.decode(r);
        specodec::JsonWriter w;
        EdgeNullByteCodec.encode(w, obj);
        writeFile(outDir + "/EdgeNullByte.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL EdgeNullByte json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL EdgeNullByte json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/EdgeNullByte.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = EdgeNullByteCodec.decode(r);
        specodec::JsonWriter w;
        EdgeNullByteCodec.encode(w, obj);
        writeFile(outDir + "/EdgeNullByte.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL EdgeNullByte unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL EdgeNullByte unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/EdgeNullByte.gron");
        specodec::GronReader r(data);
        auto obj = EdgeNullByteCodec.decode(r);
        specodec::GronWriter w;
        EdgeNullByteCodec.encode(w, obj);
        writeFile(outDir + "/EdgeNullByte.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL EdgeNullByte gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL EdgeNullByte gron" << std::endl; }
}

void testModelEdgeBoundary(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/EdgeBoundary.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = EdgeBoundaryCodec.decode(r);
        specodec::MsgPackWriter w;
        EdgeBoundaryCodec.encode(w, obj);
        writeFile(outDir + "/EdgeBoundary.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL EdgeBoundary mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL EdgeBoundary mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/EdgeBoundary.json");
        specodec::JsonReader r(data);
        auto obj = EdgeBoundaryCodec.decode(r);
        specodec::JsonWriter w;
        EdgeBoundaryCodec.encode(w, obj);
        writeFile(outDir + "/EdgeBoundary.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL EdgeBoundary json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL EdgeBoundary json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/EdgeBoundary.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = EdgeBoundaryCodec.decode(r);
        specodec::JsonWriter w;
        EdgeBoundaryCodec.encode(w, obj);
        writeFile(outDir + "/EdgeBoundary.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL EdgeBoundary unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL EdgeBoundary unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/EdgeBoundary.gron");
        specodec::GronReader r(data);
        auto obj = EdgeBoundaryCodec.decode(r);
        specodec::GronWriter w;
        EdgeBoundaryCodec.encode(w, obj);
        writeFile(outDir + "/EdgeBoundary.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL EdgeBoundary gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL EdgeBoundary gron" << std::endl; }
}

void testModelEdgeStrLen(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/EdgeStrLen.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = EdgeStrLenCodec.decode(r);
        specodec::MsgPackWriter w;
        EdgeStrLenCodec.encode(w, obj);
        writeFile(outDir + "/EdgeStrLen.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL EdgeStrLen mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL EdgeStrLen mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/EdgeStrLen.json");
        specodec::JsonReader r(data);
        auto obj = EdgeStrLenCodec.decode(r);
        specodec::JsonWriter w;
        EdgeStrLenCodec.encode(w, obj);
        writeFile(outDir + "/EdgeStrLen.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL EdgeStrLen json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL EdgeStrLen json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/EdgeStrLen.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = EdgeStrLenCodec.decode(r);
        specodec::JsonWriter w;
        EdgeStrLenCodec.encode(w, obj);
        writeFile(outDir + "/EdgeStrLen.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL EdgeStrLen unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL EdgeStrLen unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/EdgeStrLen.gron");
        specodec::GronReader r(data);
        auto obj = EdgeStrLenCodec.decode(r);
        specodec::GronWriter w;
        EdgeStrLenCodec.encode(w, obj);
        writeFile(outDir + "/EdgeStrLen.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL EdgeStrLen gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL EdgeStrLen gron" << std::endl; }
}

void testModelEdgeBytesLen(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/EdgeBytesLen.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = EdgeBytesLenCodec.decode(r);
        specodec::MsgPackWriter w;
        EdgeBytesLenCodec.encode(w, obj);
        writeFile(outDir + "/EdgeBytesLen.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL EdgeBytesLen mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL EdgeBytesLen mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/EdgeBytesLen.json");
        specodec::JsonReader r(data);
        auto obj = EdgeBytesLenCodec.decode(r);
        specodec::JsonWriter w;
        EdgeBytesLenCodec.encode(w, obj);
        writeFile(outDir + "/EdgeBytesLen.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL EdgeBytesLen json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL EdgeBytesLen json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/EdgeBytesLen.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = EdgeBytesLenCodec.decode(r);
        specodec::JsonWriter w;
        EdgeBytesLenCodec.encode(w, obj);
        writeFile(outDir + "/EdgeBytesLen.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL EdgeBytesLen unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL EdgeBytesLen unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/EdgeBytesLen.gron");
        specodec::GronReader r(data);
        auto obj = EdgeBytesLenCodec.decode(r);
        specodec::GronWriter w;
        EdgeBytesLenCodec.encode(w, obj);
        writeFile(outDir + "/EdgeBytesLen.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL EdgeBytesLen gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL EdgeBytesLen gron" << std::endl; }
}

void testModelEdgeArrEmpty(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/EdgeArrEmpty.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = EdgeArrEmptyCodec.decode(r);
        specodec::MsgPackWriter w;
        EdgeArrEmptyCodec.encode(w, obj);
        writeFile(outDir + "/EdgeArrEmpty.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL EdgeArrEmpty mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL EdgeArrEmpty mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/EdgeArrEmpty.json");
        specodec::JsonReader r(data);
        auto obj = EdgeArrEmptyCodec.decode(r);
        specodec::JsonWriter w;
        EdgeArrEmptyCodec.encode(w, obj);
        writeFile(outDir + "/EdgeArrEmpty.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL EdgeArrEmpty json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL EdgeArrEmpty json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/EdgeArrEmpty.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = EdgeArrEmptyCodec.decode(r);
        specodec::JsonWriter w;
        EdgeArrEmptyCodec.encode(w, obj);
        writeFile(outDir + "/EdgeArrEmpty.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL EdgeArrEmpty unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL EdgeArrEmpty unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/EdgeArrEmpty.gron");
        specodec::GronReader r(data);
        auto obj = EdgeArrEmptyCodec.decode(r);
        specodec::GronWriter w;
        EdgeArrEmptyCodec.encode(w, obj);
        writeFile(outDir + "/EdgeArrEmpty.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL EdgeArrEmpty gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL EdgeArrEmpty gron" << std::endl; }
}

void testModelEdgeArrBoundary(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/EdgeArrBoundary.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = EdgeArrBoundaryCodec.decode(r);
        specodec::MsgPackWriter w;
        EdgeArrBoundaryCodec.encode(w, obj);
        writeFile(outDir + "/EdgeArrBoundary.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL EdgeArrBoundary mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL EdgeArrBoundary mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/EdgeArrBoundary.json");
        specodec::JsonReader r(data);
        auto obj = EdgeArrBoundaryCodec.decode(r);
        specodec::JsonWriter w;
        EdgeArrBoundaryCodec.encode(w, obj);
        writeFile(outDir + "/EdgeArrBoundary.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL EdgeArrBoundary json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL EdgeArrBoundary json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/EdgeArrBoundary.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = EdgeArrBoundaryCodec.decode(r);
        specodec::JsonWriter w;
        EdgeArrBoundaryCodec.encode(w, obj);
        writeFile(outDir + "/EdgeArrBoundary.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL EdgeArrBoundary unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL EdgeArrBoundary unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/EdgeArrBoundary.gron");
        specodec::GronReader r(data);
        auto obj = EdgeArrBoundaryCodec.decode(r);
        specodec::GronWriter w;
        EdgeArrBoundaryCodec.encode(w, obj);
        writeFile(outDir + "/EdgeArrBoundary.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL EdgeArrBoundary gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL EdgeArrBoundary gron" << std::endl; }
}

void testModelOptArr1(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptArr1.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptArr1Codec.decode(r);
        specodec::MsgPackWriter w;
        OptArr1Codec.encode(w, obj);
        writeFile(outDir + "/OptArr1.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptArr1 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptArr1 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptArr1.json");
        specodec::JsonReader r(data);
        auto obj = OptArr1Codec.decode(r);
        specodec::JsonWriter w;
        OptArr1Codec.encode(w, obj);
        writeFile(outDir + "/OptArr1.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptArr1 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptArr1 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptArr1.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptArr1Codec.decode(r);
        specodec::JsonWriter w;
        OptArr1Codec.encode(w, obj);
        writeFile(outDir + "/OptArr1.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptArr1 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptArr1 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptArr1.gron");
        specodec::GronReader r(data);
        auto obj = OptArr1Codec.decode(r);
        specodec::GronWriter w;
        OptArr1Codec.encode(w, obj);
        writeFile(outDir + "/OptArr1.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptArr1 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptArr1 gron" << std::endl; }
}

void testModelOptArr2(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptArr2.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptArr2Codec.decode(r);
        specodec::MsgPackWriter w;
        OptArr2Codec.encode(w, obj);
        writeFile(outDir + "/OptArr2.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptArr2 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptArr2 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptArr2.json");
        specodec::JsonReader r(data);
        auto obj = OptArr2Codec.decode(r);
        specodec::JsonWriter w;
        OptArr2Codec.encode(w, obj);
        writeFile(outDir + "/OptArr2.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptArr2 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptArr2 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptArr2.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptArr2Codec.decode(r);
        specodec::JsonWriter w;
        OptArr2Codec.encode(w, obj);
        writeFile(outDir + "/OptArr2.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptArr2 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptArr2 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptArr2.gron");
        specodec::GronReader r(data);
        auto obj = OptArr2Codec.decode(r);
        specodec::GronWriter w;
        OptArr2Codec.encode(w, obj);
        writeFile(outDir + "/OptArr2.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptArr2 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptArr2 gron" << std::endl; }
}

void testModelOptArr3(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptArr3.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptArr3Codec.decode(r);
        specodec::MsgPackWriter w;
        OptArr3Codec.encode(w, obj);
        writeFile(outDir + "/OptArr3.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptArr3 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptArr3 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptArr3.json");
        specodec::JsonReader r(data);
        auto obj = OptArr3Codec.decode(r);
        specodec::JsonWriter w;
        OptArr3Codec.encode(w, obj);
        writeFile(outDir + "/OptArr3.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptArr3 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptArr3 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptArr3.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptArr3Codec.decode(r);
        specodec::JsonWriter w;
        OptArr3Codec.encode(w, obj);
        writeFile(outDir + "/OptArr3.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptArr3 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptArr3 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptArr3.gron");
        specodec::GronReader r(data);
        auto obj = OptArr3Codec.decode(r);
        specodec::GronWriter w;
        OptArr3Codec.encode(w, obj);
        writeFile(outDir + "/OptArr3.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptArr3 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptArr3 gron" << std::endl; }
}

void testModelOptArr4(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptArr4.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptArr4Codec.decode(r);
        specodec::MsgPackWriter w;
        OptArr4Codec.encode(w, obj);
        writeFile(outDir + "/OptArr4.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptArr4 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptArr4 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptArr4.json");
        specodec::JsonReader r(data);
        auto obj = OptArr4Codec.decode(r);
        specodec::JsonWriter w;
        OptArr4Codec.encode(w, obj);
        writeFile(outDir + "/OptArr4.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptArr4 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptArr4 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptArr4.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptArr4Codec.decode(r);
        specodec::JsonWriter w;
        OptArr4Codec.encode(w, obj);
        writeFile(outDir + "/OptArr4.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptArr4 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptArr4 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptArr4.gron");
        specodec::GronReader r(data);
        auto obj = OptArr4Codec.decode(r);
        specodec::GronWriter w;
        OptArr4Codec.encode(w, obj);
        writeFile(outDir + "/OptArr4.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptArr4 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptArr4 gron" << std::endl; }
}

void testModelOptArr5(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/OptArr5.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = OptArr5Codec.decode(r);
        specodec::MsgPackWriter w;
        OptArr5Codec.encode(w, obj);
        writeFile(outDir + "/OptArr5.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptArr5 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptArr5 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/OptArr5.json");
        specodec::JsonReader r(data);
        auto obj = OptArr5Codec.decode(r);
        specodec::JsonWriter w;
        OptArr5Codec.encode(w, obj);
        writeFile(outDir + "/OptArr5.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptArr5 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptArr5 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/OptArr5.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = OptArr5Codec.decode(r);
        specodec::JsonWriter w;
        OptArr5Codec.encode(w, obj);
        writeFile(outDir + "/OptArr5.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptArr5 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptArr5 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/OptArr5.gron");
        specodec::GronReader r(data);
        auto obj = OptArr5Codec.decode(r);
        specodec::GronWriter w;
        OptArr5Codec.encode(w, obj);
        writeFile(outDir + "/OptArr5.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL OptArr5 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL OptArr5 gron" << std::endl; }
}

void testModelNestOpt1(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/NestOpt1.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = NestOpt1Codec.decode(r);
        specodec::MsgPackWriter w;
        NestOpt1Codec.encode(w, obj);
        writeFile(outDir + "/NestOpt1.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL NestOpt1 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL NestOpt1 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/NestOpt1.json");
        specodec::JsonReader r(data);
        auto obj = NestOpt1Codec.decode(r);
        specodec::JsonWriter w;
        NestOpt1Codec.encode(w, obj);
        writeFile(outDir + "/NestOpt1.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL NestOpt1 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL NestOpt1 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/NestOpt1.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = NestOpt1Codec.decode(r);
        specodec::JsonWriter w;
        NestOpt1Codec.encode(w, obj);
        writeFile(outDir + "/NestOpt1.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL NestOpt1 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL NestOpt1 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/NestOpt1.gron");
        specodec::GronReader r(data);
        auto obj = NestOpt1Codec.decode(r);
        specodec::GronWriter w;
        NestOpt1Codec.encode(w, obj);
        writeFile(outDir + "/NestOpt1.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL NestOpt1 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL NestOpt1 gron" << std::endl; }
}

void testModelNestOpt2(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/NestOpt2.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = NestOpt2Codec.decode(r);
        specodec::MsgPackWriter w;
        NestOpt2Codec.encode(w, obj);
        writeFile(outDir + "/NestOpt2.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL NestOpt2 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL NestOpt2 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/NestOpt2.json");
        specodec::JsonReader r(data);
        auto obj = NestOpt2Codec.decode(r);
        specodec::JsonWriter w;
        NestOpt2Codec.encode(w, obj);
        writeFile(outDir + "/NestOpt2.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL NestOpt2 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL NestOpt2 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/NestOpt2.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = NestOpt2Codec.decode(r);
        specodec::JsonWriter w;
        NestOpt2Codec.encode(w, obj);
        writeFile(outDir + "/NestOpt2.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL NestOpt2 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL NestOpt2 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/NestOpt2.gron");
        specodec::GronReader r(data);
        auto obj = NestOpt2Codec.decode(r);
        specodec::GronWriter w;
        NestOpt2Codec.encode(w, obj);
        writeFile(outDir + "/NestOpt2.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL NestOpt2 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL NestOpt2 gron" << std::endl; }
}

void testModelNestOpt3(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/NestOpt3.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = NestOpt3Codec.decode(r);
        specodec::MsgPackWriter w;
        NestOpt3Codec.encode(w, obj);
        writeFile(outDir + "/NestOpt3.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL NestOpt3 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL NestOpt3 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/NestOpt3.json");
        specodec::JsonReader r(data);
        auto obj = NestOpt3Codec.decode(r);
        specodec::JsonWriter w;
        NestOpt3Codec.encode(w, obj);
        writeFile(outDir + "/NestOpt3.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL NestOpt3 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL NestOpt3 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/NestOpt3.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = NestOpt3Codec.decode(r);
        specodec::JsonWriter w;
        NestOpt3Codec.encode(w, obj);
        writeFile(outDir + "/NestOpt3.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL NestOpt3 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL NestOpt3 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/NestOpt3.gron");
        specodec::GronReader r(data);
        auto obj = NestOpt3Codec.decode(r);
        specodec::GronWriter w;
        NestOpt3Codec.encode(w, obj);
        writeFile(outDir + "/NestOpt3.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL NestOpt3 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL NestOpt3 gron" << std::endl; }
}

void testModelNestOpt4(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/NestOpt4.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = NestOpt4Codec.decode(r);
        specodec::MsgPackWriter w;
        NestOpt4Codec.encode(w, obj);
        writeFile(outDir + "/NestOpt4.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL NestOpt4 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL NestOpt4 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/NestOpt4.json");
        specodec::JsonReader r(data);
        auto obj = NestOpt4Codec.decode(r);
        specodec::JsonWriter w;
        NestOpt4Codec.encode(w, obj);
        writeFile(outDir + "/NestOpt4.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL NestOpt4 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL NestOpt4 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/NestOpt4.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = NestOpt4Codec.decode(r);
        specodec::JsonWriter w;
        NestOpt4Codec.encode(w, obj);
        writeFile(outDir + "/NestOpt4.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL NestOpt4 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL NestOpt4 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/NestOpt4.gron");
        specodec::GronReader r(data);
        auto obj = NestOpt4Codec.decode(r);
        specodec::GronWriter w;
        NestOpt4Codec.encode(w, obj);
        writeFile(outDir + "/NestOpt4.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL NestOpt4 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL NestOpt4 gron" << std::endl; }
}

void testModelNestOpt5(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/NestOpt5.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = NestOpt5Codec.decode(r);
        specodec::MsgPackWriter w;
        NestOpt5Codec.encode(w, obj);
        writeFile(outDir + "/NestOpt5.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL NestOpt5 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL NestOpt5 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/NestOpt5.json");
        specodec::JsonReader r(data);
        auto obj = NestOpt5Codec.decode(r);
        specodec::JsonWriter w;
        NestOpt5Codec.encode(w, obj);
        writeFile(outDir + "/NestOpt5.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL NestOpt5 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL NestOpt5 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/NestOpt5.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = NestOpt5Codec.decode(r);
        specodec::JsonWriter w;
        NestOpt5Codec.encode(w, obj);
        writeFile(outDir + "/NestOpt5.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL NestOpt5 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL NestOpt5 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/NestOpt5.gron");
        specodec::GronReader r(data);
        auto obj = NestOpt5Codec.decode(r);
        specodec::GronWriter w;
        NestOpt5Codec.encode(w, obj);
        writeFile(outDir + "/NestOpt5.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL NestOpt5 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL NestOpt5 gron" << std::endl; }
}

void testModelNestOptInner1(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/NestOptInner1.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = NestOptInner1Codec.decode(r);
        specodec::MsgPackWriter w;
        NestOptInner1Codec.encode(w, obj);
        writeFile(outDir + "/NestOptInner1.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL NestOptInner1 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL NestOptInner1 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/NestOptInner1.json");
        specodec::JsonReader r(data);
        auto obj = NestOptInner1Codec.decode(r);
        specodec::JsonWriter w;
        NestOptInner1Codec.encode(w, obj);
        writeFile(outDir + "/NestOptInner1.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL NestOptInner1 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL NestOptInner1 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/NestOptInner1.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = NestOptInner1Codec.decode(r);
        specodec::JsonWriter w;
        NestOptInner1Codec.encode(w, obj);
        writeFile(outDir + "/NestOptInner1.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL NestOptInner1 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL NestOptInner1 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/NestOptInner1.gron");
        specodec::GronReader r(data);
        auto obj = NestOptInner1Codec.decode(r);
        specodec::GronWriter w;
        NestOptInner1Codec.encode(w, obj);
        writeFile(outDir + "/NestOptInner1.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL NestOptInner1 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL NestOptInner1 gron" << std::endl; }
}

void testModelNestOptInner2(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/NestOptInner2.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = NestOptInner2Codec.decode(r);
        specodec::MsgPackWriter w;
        NestOptInner2Codec.encode(w, obj);
        writeFile(outDir + "/NestOptInner2.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL NestOptInner2 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL NestOptInner2 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/NestOptInner2.json");
        specodec::JsonReader r(data);
        auto obj = NestOptInner2Codec.decode(r);
        specodec::JsonWriter w;
        NestOptInner2Codec.encode(w, obj);
        writeFile(outDir + "/NestOptInner2.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL NestOptInner2 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL NestOptInner2 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/NestOptInner2.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = NestOptInner2Codec.decode(r);
        specodec::JsonWriter w;
        NestOptInner2Codec.encode(w, obj);
        writeFile(outDir + "/NestOptInner2.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL NestOptInner2 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL NestOptInner2 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/NestOptInner2.gron");
        specodec::GronReader r(data);
        auto obj = NestOptInner2Codec.decode(r);
        specodec::GronWriter w;
        NestOptInner2Codec.encode(w, obj);
        writeFile(outDir + "/NestOptInner2.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL NestOptInner2 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL NestOptInner2 gron" << std::endl; }
}

void testModelNestOptInner3(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/NestOptInner3.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = NestOptInner3Codec.decode(r);
        specodec::MsgPackWriter w;
        NestOptInner3Codec.encode(w, obj);
        writeFile(outDir + "/NestOptInner3.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL NestOptInner3 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL NestOptInner3 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/NestOptInner3.json");
        specodec::JsonReader r(data);
        auto obj = NestOptInner3Codec.decode(r);
        specodec::JsonWriter w;
        NestOptInner3Codec.encode(w, obj);
        writeFile(outDir + "/NestOptInner3.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL NestOptInner3 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL NestOptInner3 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/NestOptInner3.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = NestOptInner3Codec.decode(r);
        specodec::JsonWriter w;
        NestOptInner3Codec.encode(w, obj);
        writeFile(outDir + "/NestOptInner3.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL NestOptInner3 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL NestOptInner3 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/NestOptInner3.gron");
        specodec::GronReader r(data);
        auto obj = NestOptInner3Codec.decode(r);
        specodec::GronWriter w;
        NestOptInner3Codec.encode(w, obj);
        writeFile(outDir + "/NestOptInner3.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL NestOptInner3 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL NestOptInner3 gron" << std::endl; }
}

void testModelDeepNest1(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/DeepNest1.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = DeepNest1Codec.decode(r);
        specodec::MsgPackWriter w;
        DeepNest1Codec.encode(w, obj);
        writeFile(outDir + "/DeepNest1.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DeepNest1 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DeepNest1 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/DeepNest1.json");
        specodec::JsonReader r(data);
        auto obj = DeepNest1Codec.decode(r);
        specodec::JsonWriter w;
        DeepNest1Codec.encode(w, obj);
        writeFile(outDir + "/DeepNest1.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DeepNest1 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DeepNest1 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/DeepNest1.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = DeepNest1Codec.decode(r);
        specodec::JsonWriter w;
        DeepNest1Codec.encode(w, obj);
        writeFile(outDir + "/DeepNest1.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DeepNest1 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DeepNest1 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/DeepNest1.gron");
        specodec::GronReader r(data);
        auto obj = DeepNest1Codec.decode(r);
        specodec::GronWriter w;
        DeepNest1Codec.encode(w, obj);
        writeFile(outDir + "/DeepNest1.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DeepNest1 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DeepNest1 gron" << std::endl; }
}

void testModelDeepNest2(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/DeepNest2.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = DeepNest2Codec.decode(r);
        specodec::MsgPackWriter w;
        DeepNest2Codec.encode(w, obj);
        writeFile(outDir + "/DeepNest2.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DeepNest2 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DeepNest2 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/DeepNest2.json");
        specodec::JsonReader r(data);
        auto obj = DeepNest2Codec.decode(r);
        specodec::JsonWriter w;
        DeepNest2Codec.encode(w, obj);
        writeFile(outDir + "/DeepNest2.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DeepNest2 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DeepNest2 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/DeepNest2.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = DeepNest2Codec.decode(r);
        specodec::JsonWriter w;
        DeepNest2Codec.encode(w, obj);
        writeFile(outDir + "/DeepNest2.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DeepNest2 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DeepNest2 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/DeepNest2.gron");
        specodec::GronReader r(data);
        auto obj = DeepNest2Codec.decode(r);
        specodec::GronWriter w;
        DeepNest2Codec.encode(w, obj);
        writeFile(outDir + "/DeepNest2.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DeepNest2 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DeepNest2 gron" << std::endl; }
}

void testModelDeepNest3(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/DeepNest3.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = DeepNest3Codec.decode(r);
        specodec::MsgPackWriter w;
        DeepNest3Codec.encode(w, obj);
        writeFile(outDir + "/DeepNest3.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DeepNest3 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DeepNest3 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/DeepNest3.json");
        specodec::JsonReader r(data);
        auto obj = DeepNest3Codec.decode(r);
        specodec::JsonWriter w;
        DeepNest3Codec.encode(w, obj);
        writeFile(outDir + "/DeepNest3.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DeepNest3 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DeepNest3 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/DeepNest3.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = DeepNest3Codec.decode(r);
        specodec::JsonWriter w;
        DeepNest3Codec.encode(w, obj);
        writeFile(outDir + "/DeepNest3.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DeepNest3 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DeepNest3 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/DeepNest3.gron");
        specodec::GronReader r(data);
        auto obj = DeepNest3Codec.decode(r);
        specodec::GronWriter w;
        DeepNest3Codec.encode(w, obj);
        writeFile(outDir + "/DeepNest3.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DeepNest3 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DeepNest3 gron" << std::endl; }
}

void testModelDeepNest4(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/DeepNest4.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = DeepNest4Codec.decode(r);
        specodec::MsgPackWriter w;
        DeepNest4Codec.encode(w, obj);
        writeFile(outDir + "/DeepNest4.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DeepNest4 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DeepNest4 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/DeepNest4.json");
        specodec::JsonReader r(data);
        auto obj = DeepNest4Codec.decode(r);
        specodec::JsonWriter w;
        DeepNest4Codec.encode(w, obj);
        writeFile(outDir + "/DeepNest4.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DeepNest4 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DeepNest4 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/DeepNest4.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = DeepNest4Codec.decode(r);
        specodec::JsonWriter w;
        DeepNest4Codec.encode(w, obj);
        writeFile(outDir + "/DeepNest4.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DeepNest4 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DeepNest4 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/DeepNest4.gron");
        specodec::GronReader r(data);
        auto obj = DeepNest4Codec.decode(r);
        specodec::GronWriter w;
        DeepNest4Codec.encode(w, obj);
        writeFile(outDir + "/DeepNest4.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DeepNest4 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DeepNest4 gron" << std::endl; }
}

void testModelDeepNest5(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/DeepNest5.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = DeepNest5Codec.decode(r);
        specodec::MsgPackWriter w;
        DeepNest5Codec.encode(w, obj);
        writeFile(outDir + "/DeepNest5.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DeepNest5 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DeepNest5 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/DeepNest5.json");
        specodec::JsonReader r(data);
        auto obj = DeepNest5Codec.decode(r);
        specodec::JsonWriter w;
        DeepNest5Codec.encode(w, obj);
        writeFile(outDir + "/DeepNest5.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DeepNest5 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DeepNest5 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/DeepNest5.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = DeepNest5Codec.decode(r);
        specodec::JsonWriter w;
        DeepNest5Codec.encode(w, obj);
        writeFile(outDir + "/DeepNest5.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DeepNest5 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DeepNest5 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/DeepNest5.gron");
        specodec::GronReader r(data);
        auto obj = DeepNest5Codec.decode(r);
        specodec::GronWriter w;
        DeepNest5Codec.encode(w, obj);
        writeFile(outDir + "/DeepNest5.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DeepNest5 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DeepNest5 gron" << std::endl; }
}

void testModelDeepNest6(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/DeepNest6.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = DeepNest6Codec.decode(r);
        specodec::MsgPackWriter w;
        DeepNest6Codec.encode(w, obj);
        writeFile(outDir + "/DeepNest6.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DeepNest6 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DeepNest6 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/DeepNest6.json");
        specodec::JsonReader r(data);
        auto obj = DeepNest6Codec.decode(r);
        specodec::JsonWriter w;
        DeepNest6Codec.encode(w, obj);
        writeFile(outDir + "/DeepNest6.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DeepNest6 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DeepNest6 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/DeepNest6.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = DeepNest6Codec.decode(r);
        specodec::JsonWriter w;
        DeepNest6Codec.encode(w, obj);
        writeFile(outDir + "/DeepNest6.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DeepNest6 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DeepNest6 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/DeepNest6.gron");
        specodec::GronReader r(data);
        auto obj = DeepNest6Codec.decode(r);
        specodec::GronWriter w;
        DeepNest6Codec.encode(w, obj);
        writeFile(outDir + "/DeepNest6.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DeepNest6 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DeepNest6 gron" << std::endl; }
}

void testModelDeepNest7(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/DeepNest7.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = DeepNest7Codec.decode(r);
        specodec::MsgPackWriter w;
        DeepNest7Codec.encode(w, obj);
        writeFile(outDir + "/DeepNest7.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DeepNest7 mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DeepNest7 mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/DeepNest7.json");
        specodec::JsonReader r(data);
        auto obj = DeepNest7Codec.decode(r);
        specodec::JsonWriter w;
        DeepNest7Codec.encode(w, obj);
        writeFile(outDir + "/DeepNest7.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DeepNest7 json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DeepNest7 json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/DeepNest7.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = DeepNest7Codec.decode(r);
        specodec::JsonWriter w;
        DeepNest7Codec.encode(w, obj);
        writeFile(outDir + "/DeepNest7.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DeepNest7 unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DeepNest7 unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/DeepNest7.gron");
        specodec::GronReader r(data);
        auto obj = DeepNest7Codec.decode(r);
        specodec::GronWriter w;
        DeepNest7Codec.encode(w, obj);
        writeFile(outDir + "/DeepNest7.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL DeepNest7 gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL DeepNest7 gron" << std::endl; }
}

void testModelTimestampEntry(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/TimestampEntry.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = TimestampEntryCodec.decode(r);
        specodec::MsgPackWriter w;
        TimestampEntryCodec.encode(w, obj);
        writeFile(outDir + "/TimestampEntry.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL TimestampEntry mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL TimestampEntry mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/TimestampEntry.json");
        specodec::JsonReader r(data);
        auto obj = TimestampEntryCodec.decode(r);
        specodec::JsonWriter w;
        TimestampEntryCodec.encode(w, obj);
        writeFile(outDir + "/TimestampEntry.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL TimestampEntry json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL TimestampEntry json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/TimestampEntry.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = TimestampEntryCodec.decode(r);
        specodec::JsonWriter w;
        TimestampEntryCodec.encode(w, obj);
        writeFile(outDir + "/TimestampEntry.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL TimestampEntry unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL TimestampEntry unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/TimestampEntry.gron");
        specodec::GronReader r(data);
        auto obj = TimestampEntryCodec.decode(r);
        specodec::GronWriter w;
        TimestampEntryCodec.encode(w, obj);
        writeFile(outDir + "/TimestampEntry.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL TimestampEntry gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL TimestampEntry gron" << std::endl; }
}

void testModelConfigEntry(int& passed, int& failed) {
    // msgpack
    try {
        auto data = readFile(vecDir + "/ConfigEntry.msgpack");
        specodec::MsgPackReader r(data);
        auto obj = ConfigEntryCodec.decode(r);
        specodec::MsgPackWriter w;
        ConfigEntryCodec.encode(w, obj);
        writeFile(outDir + "/ConfigEntry.msgpack", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL ConfigEntry mp: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL ConfigEntry mp" << std::endl; }
    // json
    try {
        auto data = readFile(vecDir + "/ConfigEntry.json");
        specodec::JsonReader r(data);
        auto obj = ConfigEntryCodec.decode(r);
        specodec::JsonWriter w;
        ConfigEntryCodec.encode(w, obj);
        writeFile(outDir + "/ConfigEntry.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL ConfigEntry json: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL ConfigEntry json" << std::endl; }
    // unformatted json
    try {
        auto data = readFile(vecDir + "/ConfigEntry.unformatted.json");
        specodec::JsonReader r(data);
        auto obj = ConfigEntryCodec.decode(r);
        specodec::JsonWriter w;
        ConfigEntryCodec.encode(w, obj);
        writeFile(outDir + "/ConfigEntry.unformatted.json", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL ConfigEntry unformatted: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL ConfigEntry unformatted" << std::endl; }
    // gron
    try {
        auto data = readFile(vecDir + "/ConfigEntry.gron");
        specodec::GronReader r(data);
        auto obj = ConfigEntryCodec.decode(r);
        specodec::GronWriter w;
        ConfigEntryCodec.encode(w, obj);
        writeFile(outDir + "/ConfigEntry.gron", w.toBytes());
        passed++;
    } catch (const std::exception& e) {
        std::cout << "FAIL ConfigEntry gron: " << e.what() << std::endl;
        failed++;
    } catch (...) { failed++; std::cout << "FAIL ConfigEntry gron" << std::endl; }
}


int main() {
    int passed = 0;
    int failed = 0;

    // Scalar tests
    testScalarInt8_min(passed, failed);
    testScalarInt8_max(passed, failed);
    testScalarInt16_min(passed, failed);
    testScalarInt16_max(passed, failed);
    testScalarInt32_min(passed, failed);
    testScalarInt32_max(passed, failed);
    testScalarInt64_min(passed, failed);
    testScalarInt64_max(passed, failed);
    testScalarUint8_max(passed, failed);
    testScalarUint16_max(passed, failed);
    testScalarUint32_max(passed, failed);
    testScalarUint64_max(passed, failed);
    testScalarFloat32_1_5(passed, failed);
    testScalarFloat32_neg_zero(passed, failed);
    testScalarFloat32_inf(passed, failed);
    testScalarFloat32_neg_inf(passed, failed);
    testScalarFloat32_nan(passed, failed);
    testScalarFloat64_pi(passed, failed);
    testScalarFloat64_neg_zero(passed, failed);
    testScalarFloat64_inf(passed, failed);
    testScalarFloat64_neg_inf(passed, failed);
    testScalarFloat64_nan(passed, failed);
    testScalarStr_empty(passed, failed);
    testScalarStr_ascii(passed, failed);
    testScalarStr_null_byte(passed, failed);
    testScalarStr_escape(passed, failed);
    testScalarStr_unicode(passed, failed);
    testScalarStr_31(passed, failed);
    testScalarStr_32(passed, failed);
    testScalarStr_255(passed, failed);
    testScalarStr_256(passed, failed);
    testScalarBytes_empty(passed, failed);
    testScalarBytes_small(passed, failed);
    testScalarBytes_31(passed, failed);
    testScalarBytes_32(passed, failed);
    testScalarBytes_255(passed, failed);
    testScalarBytes_256(passed, failed);
    testScalarBytes_zeros(passed, failed);
    testScalarBytes_ff(passed, failed);
    testScalarBool_true(passed, failed);
    testScalarBool_false(passed, failed);

    // Model tests
    testModelOptInner(passed, failed);
    testModelSingleString(passed, failed);
    testModelSingleBoolean(passed, failed);
    testModelSingleInt8(passed, failed);
    testModelSingleInt16(passed, failed);
    testModelSingleInt32(passed, failed);
    testModelSingleInt64(passed, failed);
    testModelSingleUint8(passed, failed);
    testModelSingleUint16(passed, failed);
    testModelSingleUint32(passed, failed);
    testModelSingleUint64(passed, failed);
    testModelSingleFloat32(passed, failed);
    testModelSingleFloat64(passed, failed);
    testModelSingleBytes(passed, failed);
    testModelOptSingleString(passed, failed);
    testModelOptSingleBoolean(passed, failed);
    testModelOptSingleInt8(passed, failed);
    testModelOptSingleInt16(passed, failed);
    testModelOptSingleInt32(passed, failed);
    testModelOptSingleInt64(passed, failed);
    testModelOptSingleUint8(passed, failed);
    testModelOptSingleUint16(passed, failed);
    testModelOptSingleUint32(passed, failed);
    testModelOptSingleUint64(passed, failed);
    testModelOptSingleFloat32(passed, failed);
    testModelOptSingleFloat64(passed, failed);
    testModelOptSingleBytes(passed, failed);
    testModelPairString(passed, failed);
    testModelPairBoolean(passed, failed);
    testModelPairInt8(passed, failed);
    testModelPairInt16(passed, failed);
    testModelPairInt32(passed, failed);
    testModelPairInt64(passed, failed);
    testModelPairUint8(passed, failed);
    testModelPairUint16(passed, failed);
    testModelPairUint32(passed, failed);
    testModelPairUint64(passed, failed);
    testModelPairFloat32(passed, failed);
    testModelPairFloat64(passed, failed);
    testModelPairBytes(passed, failed);
    testModelDualStringInt32(passed, failed);
    testModelDualStringBoolean(passed, failed);
    testModelDualStringFloat64(passed, failed);
    testModelDualStringBytes(passed, failed);
    testModelDualInt32Boolean(passed, failed);
    testModelDualInt32Float64(passed, failed);
    testModelDualInt32Int64(passed, failed);
    testModelDualInt32Uint32(passed, failed);
    testModelDualInt64Uint64(passed, failed);
    testModelDualFloat32Float64(passed, failed);
    testModelDualFloat64Boolean(passed, failed);
    testModelDualFloat64Bytes(passed, failed);
    testModelDualUint32Uint64(passed, failed);
    testModelDualBooleanBytes(passed, failed);
    testModelDualInt8Uint8(passed, failed);
    testModelDualInt16Uint16(passed, failed);
    testModelDualStringInt64(passed, failed);
    testModelDualStringUint64(passed, failed);
    testModelDualInt32Bytes(passed, failed);
    testModelDualFloat64Int32(passed, failed);
    testModelDualBooleanInt32(passed, failed);
    testModelDualBytesInt64(passed, failed);
    testModelDualInt8Float32(passed, failed);
    testModelDualUint8Int16(passed, failed);
    testModelDualInt64Float64(passed, failed);
    testModelDualUint64String(passed, failed);
    testModelTriple01(passed, failed);
    testModelTriple02(passed, failed);
    testModelTriple03(passed, failed);
    testModelTriple04(passed, failed);
    testModelTriple05(passed, failed);
    testModelTriple06(passed, failed);
    testModelTriple07(passed, failed);
    testModelTriple08(passed, failed);
    testModelTriple09(passed, failed);
    testModelTriple10(passed, failed);
    testModelTriple11(passed, failed);
    testModelTriple12(passed, failed);
    testModelTriple13(passed, failed);
    testModelTriple14(passed, failed);
    testModelTriple15(passed, failed);
    testModelFive01(passed, failed);
    testModelFive02(passed, failed);
    testModelFive03(passed, failed);
    testModelFive04(passed, failed);
    testModelFive05(passed, failed);
    testModelFive06(passed, failed);
    testModelFive07(passed, failed);
    testModelFive08(passed, failed);
    testModelFive09(passed, failed);
    testModelFive10(passed, failed);
    testModelTen01(passed, failed);
    testModelTen02(passed, failed);
    testModelTen03(passed, failed);
    testModelTen04(passed, failed);
    testModelTen05(passed, failed);
    testModelArrString(passed, failed);
    testModelArrInt32(passed, failed);
    testModelArrBoolean(passed, failed);
    testModelArrFloat64(passed, failed);
    testModelArrBytes(passed, failed);
    testModelArrInt64(passed, failed);
    testModelArrUint64(passed, failed);
    testModelMultiArr1(passed, failed);
    testModelMultiArr2(passed, failed);
    testModelMultiArr3(passed, failed);
    testModelMultiArr4(passed, failed);
    testModelMultiArr5(passed, failed);
    testModelOptCombo1(passed, failed);
    testModelOptCombo2(passed, failed);
    testModelOptCombo3(passed, failed);
    testModelOptCombo4(passed, failed);
    testModelOptCombo5(passed, failed);
    testModelOptCombo6(passed, failed);
    testModelOptCombo7(passed, failed);
    testModelOptCombo8(passed, failed);
    testModelOptCombo9(passed, failed);
    testModelOptCombo10(passed, failed);
    testModelNestInner(passed, failed);
    testModelNestCoord(passed, failed);
    testModelNestIdVal(passed, failed);
    testModelNestLabel(passed, failed);
    testModelNestMoney(passed, failed);
    testModelNestRange32(passed, failed);
    testModelNestAddr(passed, failed);
    testModelNestPoint3(passed, failed);
    testModelOptNestInner(passed, failed);
    testModelOptNestCoord(passed, failed);
    testModelOptNestIdVal(passed, failed);
    testModelOptNestLabel(passed, failed);
    testModelOptNestMoney(passed, failed);
    testModelOptNestRange32(passed, failed);
    testModelOptNestAddr(passed, failed);
    testModelOptNestPoint3(passed, failed);
    testModelModelArr1(passed, failed);
    testModelModelArr2(passed, failed);
    testModelModelArr3(passed, failed);
    testModelModelArr4(passed, failed);
    testModelModelArr5(passed, failed);
    testModelMix01(passed, failed);
    testModelMix02(passed, failed);
    testModelMix03(passed, failed);
    testModelMix04(passed, failed);
    testModelMix05(passed, failed);
    testModelMix06(passed, failed);
    testModelMix07(passed, failed);
    testModelMix08(passed, failed);
    testModelMix09(passed, failed);
    testModelMix10(passed, failed);
    testModelMix11(passed, failed);
    testModelMix12(passed, failed);
    testModelMix13(passed, failed);
    testModelMix14(passed, failed);
    testModelMix15(passed, failed);
    testModelAllOpt1(passed, failed);
    testModelAllOpt2(passed, failed);
    testModelAllOpt3(passed, failed);
    testModelAllOpt4(passed, failed);
    testModelAllOpt5(passed, failed);
    testModelRecList(passed, failed);
    testModelRecTree(passed, failed);
    testModelRecChain(passed, failed);
    testModelRecWrap(passed, failed);
    testModelRecWide(passed, failed);
    testModelWide20(passed, failed);
    testModelWide25(passed, failed);
    testModelWide30(passed, failed);
    testModelWide35(passed, failed);
    testModelWide40(passed, failed);
    testModelEdgeEmpty(passed, failed);
    testModelEdgeOneOpt(passed, failed);
    testModelEdgeBigNums(passed, failed);
    testModelEdgeZeroVals(passed, failed);
    testModelEdgeNullable(passed, failed);
    testModelEdgeNegZero(passed, failed);
    testModelEdgeNullByte(passed, failed);
    testModelEdgeBoundary(passed, failed);
    testModelEdgeStrLen(passed, failed);
    testModelEdgeBytesLen(passed, failed);
    testModelEdgeArrEmpty(passed, failed);
    testModelEdgeArrBoundary(passed, failed);
    testModelOptArr1(passed, failed);
    testModelOptArr2(passed, failed);
    testModelOptArr3(passed, failed);
    testModelOptArr4(passed, failed);
    testModelOptArr5(passed, failed);
    testModelNestOpt1(passed, failed);
    testModelNestOpt2(passed, failed);
    testModelNestOpt3(passed, failed);
    testModelNestOpt4(passed, failed);
    testModelNestOpt5(passed, failed);
    testModelNestOptInner1(passed, failed);
    testModelNestOptInner2(passed, failed);
    testModelNestOptInner3(passed, failed);
    testModelDeepNest1(passed, failed);
    testModelDeepNest2(passed, failed);
    testModelDeepNest3(passed, failed);
    testModelDeepNest4(passed, failed);
    testModelDeepNest5(passed, failed);
    testModelDeepNest6(passed, failed);
    testModelDeepNest7(passed, failed);
    testModelTimestampEntry(passed, failed);
    testModelConfigEntry(passed, failed);


    std::cout << "emit-cpp: " << passed << " passed, " << failed << " failed" << std::endl;
    return failed > 0 ? 1 : 0;
}
