module;
#include <cstdlib>
#include <fstream>
#include <filesystem>
export module emit_runner;
import std;
import specodec;
import test_alltypes;
import test_alltypes_scalars;
import test_alltypes_opt;
import test_alltypes_pairs;
import test_alltypes_many;
import test_alltypes_arrays;
import test_alltypes_nests;
import test_alltypes_mixed;
import test_alltypes_recursive;
import test_alltypes_wide;
import test_alltypes_edge;
import test_alltypes_extra;
import test_alltypes_nested;
import test_alltypes_nested_deep;
import test_alltypes_enums;
import test_alltypes_unions;

static std::string getEnv(const char* name) { const char* val = std::getenv(name); return val ? val : ""; }

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

static std::string vecDir;
static std::string outDir;


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


int main() {
    int passed = 0, failed = 0;
    vecDir = getEnv("VEC_DIR");
    outDir = getEnv("OUT_DIR");

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

    // Model tests (per namespace)
    runAlltypes(passed, failed, vecDir, outDir);
    runAlltypes_scalars(passed, failed, vecDir, outDir);
    runAlltypes_opt(passed, failed, vecDir, outDir);
    runAlltypes_pairs(passed, failed, vecDir, outDir);
    runAlltypes_many(passed, failed, vecDir, outDir);
    runAlltypes_arrays(passed, failed, vecDir, outDir);
    runAlltypes_nests(passed, failed, vecDir, outDir);
    runAlltypes_mixed(passed, failed, vecDir, outDir);
    runAlltypes_recursive(passed, failed, vecDir, outDir);
    runAlltypes_wide(passed, failed, vecDir, outDir);
    runAlltypes_edge(passed, failed, vecDir, outDir);
    runAlltypes_extra(passed, failed, vecDir, outDir);
    runAlltypes_nested(passed, failed, vecDir, outDir);
    runAlltypes_nested_deep(passed, failed, vecDir, outDir);
    runAlltypes_enums(passed, failed, vecDir, outDir);
    runAlltypes_unions(passed, failed, vecDir, outDir);

    std::cout << "emit-cpp: " << passed << " passed, " << failed << " failed" << std::endl;
    return failed > 0 ? 1 : 0;
}
