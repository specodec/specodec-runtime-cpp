export module specodec.msgpack_writer;
import std;
import specodec.spec_writer;

namespace specodec {

export class MsgPackWriter : public SpecWriter {
public:
    MsgPackWriter() = default;
    ~MsgPackWriter() override = default;

    void writeString(const std::string& value) override;
    void writeBool(bool value) override;
    void writeInt32(std::int32_t value) override;
    void writeInt64(std::int64_t value) override;
    void writeUint32(std::uint32_t value) override;
    void writeUint64(std::uint64_t value) override;
    void writeFloat32(float value) override;
    void writeFloat64(double value) override;
    void writeNull() override;
    void writeBytes(const std::vector<std::uint8_t>& value) override;
    void writeEnum(const std::string& value) override;
    void beginObject(int fieldCount) override;
    void writeField(const std::string& name) override;
    void endObject() override;
    void beginArray(int elementCount) override;
    void nextElement() override;
    void endArray() override;
    std::vector<std::uint8_t> toBytes() override;

private:
    std::vector<std::uint8_t> buf;

    void writeByte(std::uint8_t b);
    void writeU16(std::uint16_t v);
    void writeU32(std::uint32_t v);
    void writeU64(std::uint64_t v);
};

void MsgPackWriter::writeByte(std::uint8_t b) { buf.push_back(b); }
void MsgPackWriter::writeU16(std::uint16_t v) { buf.push_back((std::uint8_t)(v >> 8)); buf.push_back((std::uint8_t)v); }
void MsgPackWriter::writeU32(std::uint32_t v) { buf.push_back((std::uint8_t)(v >> 24)); buf.push_back((std::uint8_t)(v >> 16)); buf.push_back((std::uint8_t)(v >> 8)); buf.push_back((std::uint8_t)v); }
void MsgPackWriter::writeU64(std::uint64_t v) { writeU32((std::uint32_t)(v >> 32)); writeU32((std::uint32_t)v); }

void MsgPackWriter::writeString(const std::string& value) {
    std::size_t len = value.size();
    if (len <= 0x1F) writeByte((std::uint8_t)(0xA0 | (int)len));
    else if (len <= 0xFF) { writeByte(0xD9); writeByte((std::uint8_t)len); }
    else if (len <= 0xFFFF) { writeByte(0xDA); writeU16((std::uint16_t)len); }
    else { writeByte(0xDB); writeU32((std::uint32_t)len); }
    buf.insert(buf.end(), value.begin(), value.end());
}

void MsgPackWriter::writeBool(bool value) {
    writeByte(value ? 0xC3 : 0xC2);
}

void MsgPackWriter::writeInt32(std::int32_t value) {
    if (value >= 0 && value <= 0x7F) writeByte((std::uint8_t)value);
    else if (value >= -0x20 && value <= -1) writeByte((std::uint8_t)value);
    else if (value >= 0 && value <= 0xFF) { writeByte(0xCC); writeByte((std::uint8_t)value); }
    else if (value >= 0 && value <= 0xFFFF) { writeByte(0xCD); writeU16((std::uint16_t)value); }
    else if (value >= 0) { writeByte(0xCE); writeU32((std::uint32_t)value); }
    else if (value >= -0x80) { writeByte(0xD0); writeByte((std::uint8_t)value); }
    else if (value >= -0x8000) { writeByte(0xD1); writeU16((std::uint16_t)(value & 0xFFFF)); }
    else { writeByte(0xD2); writeU32((std::uint32_t)value); }
}

void MsgPackWriter::writeInt64(std::int64_t value) {
    if (value >= 0 && value <= 0x7F) writeByte((std::uint8_t)value);
    else if (value >= -0x20LL && value <= -1LL) writeByte((std::uint8_t)(value & 0xFF));
    else if (value >= 0 && value <= 0xFFLL) { writeByte(0xCC); writeByte((std::uint8_t)value); }
    else if (value >= 0 && value <= 0xFFFFLL) { writeByte(0xCD); writeU16((std::uint16_t)value); }
    else if (value >= 0 && value <= 0xFFFFFFFFLL) { writeByte(0xCE); writeU32((std::uint32_t)value); }
    else if (value >= 0) { writeByte(0xCF); writeU64((std::uint64_t)value); }
    else if (value >= -0x80LL) { writeByte(0xD0); writeByte((std::uint8_t)(value & 0xFF)); }
    else if (value >= -0x8000LL) { writeByte(0xD1); writeU16((std::uint16_t)(value & 0xFFFF)); }
    else if (value >= -0x80000000LL) { writeByte(0xD2); writeU32((std::uint32_t)value); }
    else { writeByte(0xD3); writeU64((std::uint64_t)value); }
}

void MsgPackWriter::writeUint32(std::uint32_t value) {
    if (value <= 0x7F) writeByte((std::uint8_t)value);
    else if (value <= 0xFF) { writeByte(0xCC); writeByte((std::uint8_t)value); }
    else if (value <= 0xFFFF) { writeByte(0xCD); writeU16((std::uint16_t)value); }
    else { writeByte(0xCE); writeU32(value); }
}

void MsgPackWriter::writeUint64(std::uint64_t value) {
    if (value <= 0x7FULL) writeByte((std::uint8_t)value);
    else if (value <= 0xFFULL) { writeByte(0xCC); writeByte((std::uint8_t)value); }
    else if (value <= 0xFFFFULL) { writeByte(0xCD); writeU16((std::uint16_t)value); }
    else if (value <= 0xFFFFFFFFULL) { writeByte(0xCE); writeU32((std::uint32_t)value); }
    else { writeByte(0xCF); writeU64(value); }
}

void MsgPackWriter::writeFloat32(float value) {
    writeByte(0xCA);
    std::uint32_t bits;
    std::memcpy(&bits, &value, sizeof(bits));
    writeU32(bits);
}

void MsgPackWriter::writeFloat64(double value) {
    writeByte(0xCB);
    std::uint64_t bits;
    std::memcpy(&bits, &value, sizeof(bits));
    writeU32((std::uint32_t)(bits >> 32));
    writeU32((std::uint32_t)bits);
}

void MsgPackWriter::writeNull() { writeByte(0xC0); }

void MsgPackWriter::writeBytes(const std::vector<std::uint8_t>& value) {
    std::size_t len = value.size();
    if (len <= 0xFF) { writeByte(0xC4); writeByte((std::uint8_t)len); }
    else if (len <= 0xFFFF) { writeByte(0xC5); writeU16((std::uint16_t)len); }
    else { writeByte(0xC6); writeU32((std::uint32_t)len); }
    buf.insert(buf.end(), value.begin(), value.end());
}

void MsgPackWriter::beginObject(int fieldCount) {
    if (fieldCount <= 0x0F) writeByte((std::uint8_t)(0x80 | fieldCount));
    else if (fieldCount <= 0xFFFF) { writeByte(0xDE); writeU16((std::uint16_t)fieldCount); }
    else { writeByte(0xDF); writeU32((std::uint32_t)fieldCount); }
}

void MsgPackWriter::writeField(const std::string& name) { writeString(name); }
void MsgPackWriter::endObject() {}
void MsgPackWriter::beginArray(int elementCount) {
    if (elementCount <= 0x0F) writeByte((std::uint8_t)(0x90 | elementCount));
    else if (elementCount <= 0xFFFF) { writeByte(0xDC); writeU16((std::uint16_t)elementCount); }
    else { writeByte(0xDD); writeU32((std::uint32_t)elementCount); }
}
void MsgPackWriter::nextElement() {}
void MsgPackWriter::endArray() {}
void MsgPackWriter::writeEnum(const std::string& value) { writeString(value); }
std::vector<std::uint8_t> MsgPackWriter::toBytes() { return buf; }

} // namespace specodec
