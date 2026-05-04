export module specodec.msgpack_reader;
import std;
import specodec.spec_reader;
import specodec.scodec_error;

namespace specodec {

export class MsgPackReader : public SpecReader {
public:
    explicit MsgPackReader(const std::vector<std::uint8_t>& data);
    ~MsgPackReader() override = default;

    void beginObject() override;
    bool hasNextField() override;
    std::string readFieldName() override;
    void endObject() override;
    void beginArray() override;
    bool hasNextElement() override;
    void endArray() override;
    std::string readString() override;
    bool readBool() override;
    std::int32_t readInt32() override;
    std::int64_t readInt64() override;
    std::uint32_t readUint32() override;
    std::uint64_t readUint64() override;
    float readFloat32() override;
    double readFloat64() override;
    void readNull() override;
    std::vector<std::uint8_t> readBytes() override;
    std::string readEnum() override;
    bool isNull() override;
    void skip() override;

private:
    std::vector<std::uint8_t> data;
    std::size_t pos;
    std::vector<int> containerCount;

    std::uint8_t readByte();
    std::uint16_t readU16();
    std::uint32_t readU32();
    std::int16_t readI16();
    std::int32_t readI32();
    float readF32();
    double readF64();
    int readMapHeader();
    int readArrayHeader();
    std::uint64_t readInt();
    double readFloat();
};

MsgPackReader::MsgPackReader(const std::vector<std::uint8_t>& data)
    : data(data), pos(0) {}

std::uint8_t MsgPackReader::readByte() {
    if (pos >= data.size()) throw SCodecError("internal", "msgpack: unexpected end of data");
    return data[pos++];
}

std::uint16_t MsgPackReader::readU16() {
    std::uint16_t v = ((std::uint16_t)data[pos] << 8) | (std::uint16_t)data[pos + 1];
    pos += 2;
    return v;
}

std::uint32_t MsgPackReader::readU32() {
    std::uint32_t v = ((std::uint32_t)data[pos] << 24) |
                 ((std::uint32_t)data[pos + 1] << 16) |
                 ((std::uint32_t)data[pos + 2] << 8) |
                 (std::uint32_t)data[pos + 3];
    pos += 4;
    return v;
}

std::int16_t MsgPackReader::readI16() {
    std::uint16_t v = readU16();
    return v > 0x7FFF ? (std::int16_t)(v - 0x10000) : (std::int16_t)v;
}

std::int32_t MsgPackReader::readI32() {
    std::uint64_t v = readU32();
    return v > 0x7FFFFFFF ? (std::int32_t)(v - 0x100000000ULL) : (std::int32_t)v;
}

float MsgPackReader::readF32() {
    std::uint32_t bits = readU32();
    float f;
    std::memcpy(&f, &bits, sizeof(f));
    return f;
}

double MsgPackReader::readF64() {
    std::uint64_t hi = readU32();
    std::uint64_t lo = readU32();
    std::uint64_t bits = (hi << 32) | lo;
    double d;
    std::memcpy(&d, &bits, sizeof(d));
    return d;
}

int MsgPackReader::readMapHeader() {
    std::uint8_t b = readByte();
    if ((b & 0xF0) == 0x80) return b & 0x0F;
    if (b == 0xDE) return readU16();
    if (b == 0xDF) return (int)readU32();
    char hex[10];
    std::snprintf(hex, sizeof(hex), "%x", b);
    throw SCodecError("internal", std::string("msgpack: expected map, got 0x") + hex);
}

int MsgPackReader::readArrayHeader() {
    std::uint8_t b = readByte();
    if ((b & 0xF0) == 0x90) return b & 0x0F;
    if (b == 0xDC) return readU16();
    if (b == 0xDD) return (int)readU32();
    char hex[10];
    std::snprintf(hex, sizeof(hex), "%x", b);
    throw SCodecError("internal", std::string("msgpack: expected array, got 0x") + hex);
}

std::string MsgPackReader::readString() {
    std::uint8_t b = readByte();
    int len;
    if ((b & 0xE0) == 0xA0) len = b & 0x1F;
    else if (b == 0xD9) len = readByte();
    else if (b == 0xDA) len = readU16();
    else if (b == 0xDB) len = (int)readU32();
    else {
        char hex[10];
        std::snprintf(hex, sizeof(hex), "%x", b);
        throw SCodecError("internal", std::string("msgpack: expected string, got 0x") + hex);
    }
    std::string s(data.begin() + pos, data.begin() + pos + len);
    pos += len;
    return s;
}

std::uint64_t MsgPackReader::readInt() {
    std::uint8_t b = readByte();
    if (b <= 0x7F) return b;
    if (b >= 0xE0) return (std::uint64_t)(std::int64_t)(b - 0x100);
    if (b == 0xCC) return readByte();
    if (b == 0xCD) return readU16();
    if (b == 0xCE) return readU32();
    if (b == 0xD0) return (std::uint64_t)(std::int64_t)(std::int8_t)readByte();
    if (b == 0xD1) return (std::uint64_t)(std::int64_t)readI16();
    if (b == 0xD2) return (std::uint64_t)(std::int64_t)readI32();
    if (b == 0xD3) {
        std::uint64_t hi = readU32();
        std::uint64_t lo = readU32();
        return (std::int64_t)((hi << 32) | lo);
    }
    if (b == 0xCF) {
        std::uint64_t hi = readU32();
        std::uint64_t lo = readU32();
        return (hi << 32) | lo;
    }
    char hex[10];
    std::snprintf(hex, sizeof(hex), "%x", b);
    throw SCodecError("internal", std::string("msgpack: expected int, got 0x") + hex);
}

double MsgPackReader::readFloat() {
    std::uint8_t b = readByte();
    if (b == 0xCA) return (double)readF32();
    if (b == 0xCB) return readF64();
    if (b <= 0x7F) return (double)b;
    if (b >= 0xE0) return (double)(std::int64_t)(b - 0x100);
    if (b == 0xCC) return (double)readByte();
    if (b == 0xCD) return (double)readU16();
    if (b == 0xCE) return (double)readU32();
    if (b == 0xCF) return (double)(std::int64_t)((std::uint64_t)readU32() << 32 | readU32());
    if (b == 0xD0) return (double)(std::int8_t)readByte();
    if (b == 0xD1) return (double)readI16();
    if (b == 0xD2) return (double)readI32();
    if (b == 0xD3) return (double)((std::int64_t)((std::uint64_t)readU32() << 32 | readU32()));
    char hex[10];
    std::snprintf(hex, sizeof(hex), "%x", b);
    throw SCodecError("internal", std::string("msgpack: expected float, got 0x") + hex);
}

bool MsgPackReader::readBool() {
    std::uint8_t b = readByte();
    if (b == 0xC3) return true;
    if (b == 0xC2) return false;
    char hex[10];
    std::snprintf(hex, sizeof(hex), "%x", b);
    throw SCodecError("internal", std::string("msgpack: expected bool, got 0x") + hex);
}

void MsgPackReader::readNull() {
    std::uint8_t b = readByte();
    if (b != 0xC0) {
        char hex[10];
        std::snprintf(hex, sizeof(hex), "%x", b);
        throw SCodecError("internal", std::string("msgpack: expected null, got 0x") + hex);
    }
}

std::int32_t MsgPackReader::readInt32() { return (std::int32_t)readInt(); }
std::uint32_t MsgPackReader::readUint32() { return (std::uint32_t)(readInt() & 0xFFFFFFFFULL); }
std::uint64_t MsgPackReader::readUint64() { return readInt(); }
std::int64_t MsgPackReader::readInt64() { return (std::int64_t)readInt(); }
float MsgPackReader::readFloat32() { return (float)readFloat(); }
double MsgPackReader::readFloat64() { return readFloat(); }

std::vector<std::uint8_t> MsgPackReader::readBytes() {
    std::uint8_t b = readByte();
    int len;
    if (b == 0xC4) len = readByte();
    else if (b == 0xC5) len = readU16();
    else if (b == 0xC6) len = (int)readU32();
    else {
        char hex[10];
        std::snprintf(hex, sizeof(hex), "%x", b);
        throw SCodecError("internal", std::string("msgpack: expected bin, got 0x") + hex);
    }
    std::vector<std::uint8_t> v(data.begin() + pos, data.begin() + pos + len);
    pos += len;
    return v;
}

std::string MsgPackReader::readEnum() { return readString(); }

bool MsgPackReader::isNull() {
    return pos < data.size() && data[pos] == 0xC0;
}

void MsgPackReader::skip() {
    std::uint8_t b = readByte();
    if (b <= 0x7F || b >= 0xE0) return;
    if ((b & 0xF0) == 0x80) {
        int n = b & 0x0F;
        for (int i = 0; i < n; i++) { skip(); skip(); }
        return;
    }
    if ((b & 0xF0) == 0x90) {
        int n = b & 0x0F;
        for (int i = 0; i < n; i++) { skip(); }
        return;
    }
    if ((b & 0xE0) == 0xA0) { pos += b & 0x1F; return; }
    switch (b) {
        case 0xC0: case 0xC2: case 0xC3: break;
        case 0xCC: case 0xD0: pos += 1; break;
        case 0xCD: case 0xD1: pos += 2; break;
        case 0xCE: case 0xD2: case 0xCA: pos += 4; break;
        case 0xCF: case 0xD3: case 0xCB: pos += 8; break;
        case 0xD9: pos += readByte(); break;
        case 0xDA: pos += readU16(); break;
        case 0xDB: pos += readU32(); break;
        case 0xC4: pos += readByte(); break;
        case 0xC5: pos += readU16(); break;
        case 0xC6: pos += readU32(); break;
        case 0xD4: pos += 2; break;
        case 0xD5: pos += 3; break;
        case 0xD6: pos += 5; break;
        case 0xD7: pos += 9; break;
        case 0xD8: pos += 17; break;
        case 0xC7: pos += 1 + readByte(); break;
        case 0xC8: pos += 1 + readU16(); break;
        case 0xC9: pos += 1 + readU32(); break;
        case 0xDC: { int n = readU16(); for (int i = 0; i < n; i++) skip(); break; }
        case 0xDD: { int n = (int)readU32(); for (int i = 0; i < n; i++) skip(); break; }
        case 0xDE: { int n = readU16(); for (int i = 0; i < n; i++) { skip(); skip(); } break; }
        case 0xDF: { int n = (int)readU32(); for (int i = 0; i < n; i++) { skip(); skip(); } break; }
        default: {
            char hex[10];
            std::snprintf(hex, sizeof(hex), "%x", b);
            throw SCodecError("internal", std::string("msgpack: unknown format 0x") + hex);
        }
    }
}

void MsgPackReader::beginObject() {
    int n = readMapHeader();
    containerCount.push_back(n);
}

bool MsgPackReader::hasNextField() {
    int top = (int)containerCount.size() - 1;
    if (containerCount[top] > 0) {
        containerCount[top]--;
        return true;
    }
    containerCount.pop_back();
    return false;
}

std::string MsgPackReader::readFieldName() { return readString(); }
void MsgPackReader::endObject() {}

void MsgPackReader::beginArray() {
    int n = readArrayHeader();
    containerCount.push_back(n);
}

bool MsgPackReader::hasNextElement() {
    int top = (int)containerCount.size() - 1;
    if (containerCount[top] > 0) {
        containerCount[top]--;
        return true;
    }
    containerCount.pop_back();
    return false;
}

void MsgPackReader::endArray() {}

} // namespace specodec
