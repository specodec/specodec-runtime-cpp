export module specodec.gron_writer;
import std;
import specodec.spec_writer;
import specodec.float_fmt;

namespace specodec {

export class GronWriter : public SpecWriter {
public:
    GronWriter() = default;
    ~GronWriter() override = default;

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
    struct NestInfo {
        int depth;
        int arrayIndex = -1;
    };

    std::vector<std::string> _lines;
    std::vector<std::string> segments = {"json"};
    std::vector<NestInfo> nesting;

    std::string buildPath();
    std::string escape(const std::string& s);
    std::string b64(const std::vector<std::uint8_t>& buf);
    void emit(const std::string& raw);
};

std::string GronWriter::buildPath() {
    std::string r = segments[0];
    for (std::size_t i = 1; i < segments.size(); i++) {
        if (segments[i].find('[') == 0) r += segments[i];
        else r += "." + segments[i];
    }
    return r;
}

std::string GronWriter::escape(const std::string& s) {
    std::string sb;
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
    return sb;
}

std::string GronWriter::b64(const std::vector<std::uint8_t>& buf) {
    std::string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    std::string sb;
    std::size_t i = 0;
    while (i < buf.size()) {
        int b0 = buf[i] & 0xFF;
        int b1 = (i + 1 < buf.size()) ? (buf[i + 1] & 0xFF) : 0;
        int b2 = (i + 2 < buf.size()) ? (buf[i + 2] & 0xFF) : 0;
        sb += chars[b0 >> 2];
        sb += chars[((b0 & 3) << 4) | (b1 >> 4)];
        sb += (i + 1 < buf.size()) ? chars[((b1 & 0xF) << 2) | (b2 >> 6)] : '=';
        sb += (i + 2 < buf.size()) ? chars[b2 & 0x3F] : '=';
        i += 3;
    }
    return sb;
}

void GronWriter::emit(const std::string& raw) {
    _lines.push_back(buildPath() + " = " + raw + ";");
}

void GronWriter::writeString(const std::string& value) { emit("\"" + escape(value) + "\""); }
void GronWriter::writeBool(bool value) { emit(value ? "true" : "false"); }
void GronWriter::writeInt32(std::int32_t value) { emit(std::to_string(value)); }
void GronWriter::writeInt64(std::int64_t value) { emit("\"" + std::to_string(value) + "\""); }
void GronWriter::writeUint32(std::uint32_t value) { emit(std::to_string(value)); }
void GronWriter::writeUint64(std::uint64_t value) { emit("\"" + std::to_string(value) + "\""); }

void GronWriter::writeFloat32(float value) {
    if (std::isnan(value)) {
        emit("\"NaN\"");
    } else if (std::isinf(value)) {
        emit((value > 0) ? "\"Infinity\"" : "\"-Infinity\"");
    } else {
        emit(formatFloat32(value));
    }
}

void GronWriter::writeFloat64(double value) {
    if (std::isnan(value)) {
        emit("\"NaN\"");
    } else if (std::isinf(value)) {
        emit((value > 0) ? "\"Infinity\"" : "\"-Infinity\"");
    } else {
        emit(formatFloat64(value));
    }
}

void GronWriter::writeNull() { emit("null"); }
void GronWriter::writeBytes(const std::vector<std::uint8_t>& value) { emit("\"" + b64(value) + "\""); }
void GronWriter::writeEnum(const std::string& value) { emit("\"" + escape(value) + "\""); }

void GronWriter::beginObject(int /*fieldCount*/) {
    _lines.push_back(buildPath() + " = {};");
    nesting.push_back({(int)segments.size()});
}

void GronWriter::writeField(const std::string& name) {
    auto& top = nesting.back();
    if ((int)segments.size() > top.depth) segments[segments.size() - 1] = name;
    else segments.push_back(name);
}

void GronWriter::endObject() {
    auto info = nesting.back();
    nesting.pop_back();
    while ((int)segments.size() > info.depth) segments.pop_back();
}

void GronWriter::beginArray(int /*elementCount*/) {
    _lines.push_back(buildPath() + " = [];");
    nesting.push_back({(int)segments.size(), -1});
}

void GronWriter::nextElement() {
    auto& info = nesting.back();
    info.arrayIndex++;
    std::string seg = "[" + std::to_string(info.arrayIndex) + "]";
    if ((int)segments.size() > info.depth) segments[segments.size() - 1] = seg;
    else segments.push_back(seg);
}

void GronWriter::endArray() {
    auto info = nesting.back();
    nesting.pop_back();
    while ((int)segments.size() > info.depth) segments.pop_back();
}

std::vector<std::uint8_t> GronWriter::toBytes() {
    std::string result;
    for (const auto& l : _lines) result += l + "\n";
    return std::vector<std::uint8_t>(result.begin(), result.end());
}

} // namespace specodec
