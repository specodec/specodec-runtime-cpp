export module specodec.json_writer;
import std;
import specodec.spec_writer;
import specodec.float_fmt;

namespace specodec {

export class JsonWriter : public SpecWriter {
public:
    JsonWriter() = default;
    ~JsonWriter() override = default;

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
    std::string sb;
    std::vector<bool> firstItem;

    void escape(const std::string& s);
    std::string b64(const std::vector<std::uint8_t>& buf);
};

void JsonWriter::escape(const std::string& s) {
    for (char c : s) {
        unsigned char code = (unsigned char)c;
        switch (code) {
            case 0x22: sb += "\\\""; break;
            case 0x5C: sb += "\\\\"; break;
            case 0x08: sb += "\\b"; break;
            case 0x0C: sb += "\\f"; break;
            case 0x0A: sb += "\\n"; break;
            case 0x0D: sb += "\\r"; break;
            case 0x09: sb += "\\t"; break;
            default:
                if (code <= 0x1F) {
                    std::ostringstream oss;
                    oss << "\\u" << std::hex << std::uppercase
                        << std::setw(4) << std::setfill('0') << (int)code;
                    sb += oss.str();
                } else {
                    sb += c;
                }
        }
    }
}

std::string JsonWriter::b64(const std::vector<std::uint8_t>& buf) {
    std::string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    std::string s;
    std::size_t i = 0;
    while (i < buf.size()) {
        int b0 = buf[i] & 0xFF;
        int b1 = (i + 1 < buf.size()) ? (buf[i + 1] & 0xFF) : 0;
        int b2 = (i + 2 < buf.size()) ? (buf[i + 2] & 0xFF) : 0;
        s += chars[b0 >> 2];
        s += chars[((b0 & 3) << 4) | (b1 >> 4)];
        s += (i + 1 < buf.size()) ? chars[((b1 & 0xF) << 2) | (b2 >> 6)] : '=';
        s += (i + 2 < buf.size()) ? chars[b2 & 0x3F] : '=';
        i += 3;
    }
    return s;
}

void JsonWriter::writeString(const std::string& value) {
    sb += '"';
    escape(value);
    sb += '"';
}

void JsonWriter::writeBool(bool value) {
    sb += value ? "true" : "false";
}

void JsonWriter::writeInt32(std::int32_t value) {
    sb += std::to_string(value);
}

void JsonWriter::writeInt64(std::int64_t value) {
    sb += '"';
    sb += std::to_string(value);
    sb += '"';
}

void JsonWriter::writeUint32(std::uint32_t value) {
    sb += std::to_string((std::uint64_t)value);
}

void JsonWriter::writeUint64(std::uint64_t value) {
    sb += '"';
    sb += std::to_string(value);
    sb += '"';
}

void JsonWriter::writeFloat32(float value) {
    if (std::isnan(value)) {
        sb += "\"NaN\"";
    } else if (std::isinf(value)) {
        sb += (value > 0) ? "\"Infinity\"" : "\"-Infinity\"";
    } else {
        sb += formatFloat32(value);
    }
}

void JsonWriter::writeFloat64(double value) {
    if (std::isnan(value)) {
        sb += "\"NaN\"";
    } else if (std::isinf(value)) {
        sb += (value > 0) ? "\"Infinity\"" : "\"-Infinity\"";
    } else {
        sb += formatFloat64(value);
    }
}

void JsonWriter::writeNull() {
    sb += "null";
}

void JsonWriter::writeBytes(const std::vector<std::uint8_t>& value) {
    sb += '"';
    sb += b64(value);
    sb += '"';
}

void JsonWriter::writeEnum(const std::string& value) {
    sb += '"';
    escape(value);
    sb += '"';
}

void JsonWriter::beginObject(int /*fieldCount*/) {
    sb += '{';
    firstItem.push_back(true);
}

void JsonWriter::writeField(const std::string& name) {
    std::size_t top = firstItem.size() - 1;
    if (!firstItem[top]) sb += ',';
    firstItem[top] = false;
    sb += '"';
    escape(name);
    sb += '"';
    sb += ':';
}

void JsonWriter::endObject() {
    firstItem.pop_back();
    sb += '}';
}

void JsonWriter::beginArray(int /*elementCount*/) {
    sb += '[';
    firstItem.push_back(true);
}

void JsonWriter::nextElement() {
    std::size_t top = firstItem.size() - 1;
    if (!firstItem[top]) sb += ',';
    firstItem[top] = false;
}

void JsonWriter::endArray() {
    firstItem.pop_back();
    sb += ']';
}

std::vector<std::uint8_t> JsonWriter::toBytes() {
    return std::vector<std::uint8_t>(sb.begin(), sb.end());
}

} // namespace specodec
