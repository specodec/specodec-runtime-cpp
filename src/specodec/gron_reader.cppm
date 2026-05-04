export module specodec.gron_reader;
import std;
import specodec.spec_reader;
import specodec.scodec_error;

namespace specodec {

export class GronReader : public SpecReader {
public:
    explicit GronReader(const std::vector<std::uint8_t>& data);
    ~GronReader() override = default;

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
    struct CtxInfo {
        std::string prefix;
        std::string type;
        int index = -1;
    };

    std::vector<std::pair<std::string, std::string>> lines;
    std::size_t cursor;
    std::vector<CtxInfo> ctx;

    std::string unescape(const std::string& s);
    std::vector<std::uint8_t> b64(const std::string& s);
};

GronReader::GronReader(const std::vector<std::uint8_t>& data)
    : cursor(0) {
    std::string text(data.begin(), data.end());
    std::istringstream iss(text);
    std::string raw;
    while (std::getline(iss, raw)) {
        if (raw.empty()) continue;
        std::size_t start = 0;
        while (start < raw.length() && (raw[start] == ' ' || raw[start] == '\t' || raw[start] == '\r')) start++;
        if (start >= raw.length()) continue;
        std::string line = raw.substr(start);
        while (!line.empty() && line.back() == '\r') line.pop_back();
        if (line.empty()) continue;

        std::size_t eq = line.find(" = ");
        if (eq == std::string::npos) continue;
        std::string path = line.substr(0, eq);
        std::string value = line.substr(eq + 3);
        if (!value.empty() && value.back() == ';') value.pop_back();
        lines.push_back({path, value});
    }
}

std::string GronReader::unescape(const std::string& s) {
    if (s.length() < 2 || s[0] != '"' || s.back() != '"')
        throw SCodecError("internal", "gron: expected quoted string");
    std::string sb;
    std::size_t i = 1;
    while (i < s.length() - 1) {
        if (s[i] == '\\') {
            i++;
            switch (s[i]) {
                case '"': sb += '"'; break;
                case '\\': sb += '\\'; break;
                case '/': sb += '/'; break;
                case 'b': sb += '\b'; break;
                case 'f': sb += '\f'; break;
                case 'n': sb += '\n'; break;
                case 'r': sb += '\r'; break;
                case 't': sb += '\t'; break;
                case 'u': {
                    int cp = (int)std::strtol(s.substr(i + 1, 4).c_str(), nullptr, 16);
                    if (cp >= 0xD800 && cp <= 0xDBFF) {
                        if (i + 7 < s.length() && s[i + 5] == '\\' && s[i + 6] == 'u') {
                            int low = (int)std::strtol(s.substr(i + 7, 4).c_str(), nullptr, 16);
                            if (low >= 0xDC00 && low <= 0xDFFF) {
                                cp = 0x10000 + (cp - 0xD800) * 0x400 + (low - 0xDC00);
                                i += 6;
                            }
                        }
                    }
                    if (cp <= 0x7F) {
                        sb += (char)cp;
                    } else if (cp <= 0x7FF) {
                        sb += (char)(0xC0 | (cp >> 6));
                        sb += (char)(0x80 | (cp & 0x3F));
                    } else if (cp <= 0xFFFF) {
                        sb += (char)(0xE0 | (cp >> 12));
                        sb += (char)(0x80 | ((cp >> 6) & 0x3F));
                        sb += (char)(0x80 | (cp & 0x3F));
                    } else {
                        sb += (char)(0xF0 | (cp >> 18));
                        sb += (char)(0x80 | ((cp >> 12) & 0x3F));
                        sb += (char)(0x80 | ((cp >> 6) & 0x3F));
                        sb += (char)(0x80 | (cp & 0x3F));
                    }
                    i += 4;
                    break;
                }
            }
        } else {
            sb += s[i];
        }
        i++;
    }
    return sb;
}

std::vector<std::uint8_t> GronReader::b64(const std::string& s) {
    std::string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    std::size_t padCount = 0;
    for (std::size_t i = s.length(); i > 0; i--) {
        if (s[i - 1] == '=') padCount++;
        else break;
    }
    std::vector<std::uint8_t> result;
    std::size_t i = 0;
    while (i < s.length() && s[i] != '=') {
        int b0 = (int)chars.find(s[i]); i++;
        int b1 = (i < s.length() && s[i] != '=') ? (int)chars.find(s[i]) : 0; if (i < s.length() && s[i] != '=') i++;
        int b2 = (i < s.length() && s[i] != '=') ? (int)chars.find(s[i]) : 0; if (i < s.length() && s[i] != '=') i++;
        int b3 = (i < s.length() && s[i] != '=') ? (int)chars.find(s[i]) : 0; if (i < s.length() && s[i] != '=') i++;
        result.push_back((std::uint8_t)((b0 << 2) | (b1 >> 4)));
        result.push_back((std::uint8_t)(((b1 & 0xF) << 4) | (b2 >> 2)));
        result.push_back((std::uint8_t)(((b2 & 3) << 6) | b3));
    }
    for (std::size_t p = 0; p < padCount; p++) result.pop_back();
    return result;
}

std::string GronReader::readString() {
    return unescape(lines[cursor++].second);
}

bool GronReader::readBool() {
    return lines[cursor++].second == "true";
}

std::int32_t GronReader::readInt32() {
    return (std::int32_t)std::stoll(lines[cursor++].second);
}

std::int64_t GronReader::readInt64() {
    return std::stoll(unescape(lines[cursor++].second));
}

std::uint32_t GronReader::readUint32() {
    return (std::uint32_t)std::stoull(lines[cursor++].second);
}

std::uint64_t GronReader::readUint64() {
    return std::stoull(unescape(lines[cursor++].second));
}

float GronReader::readFloat32() {
    std::string v = lines[cursor++].second;
    if (v == "\"NaN\"") return std::numeric_limits<float>::quiet_NaN();
    if (v == "\"Infinity\"") return std::numeric_limits<float>::infinity();
    if (v == "\"-Infinity\"") return -std::numeric_limits<float>::infinity();
    return std::stof(v);
}

double GronReader::readFloat64() {
    std::string v = lines[cursor++].second;
    if (v == "\"NaN\"") return std::numeric_limits<double>::quiet_NaN();
    if (v == "\"Infinity\"") return std::numeric_limits<double>::infinity();
    if (v == "\"-Infinity\"") return -std::numeric_limits<double>::infinity();
    return std::stod(v);
}

void GronReader::readNull() {
    if (lines[cursor++].second != "null") throw SCodecError("internal", "gron: expected null");
}

std::vector<std::uint8_t> GronReader::readBytes() {
    return b64(unescape(lines[cursor++].second));
}

std::string GronReader::readEnum() {
    return unescape(lines[cursor++].second);
}

void GronReader::beginObject() {
    auto& line = lines[cursor++];
    ctx.push_back({line.first, "object"});
}

bool GronReader::hasNextField() {
    if (cursor >= lines.size()) return false;
    std::string pfx = ctx.back().prefix + ".";
    const std::string& p = lines[cursor].first;
    if (p.find(pfx) != 0) return false;
    std::string rem = p.substr(pfx.length());
    return rem.find('.') == std::string::npos && rem.find('[') == std::string::npos;
}

std::string GronReader::readFieldName() {
    std::string pfx = ctx.back().prefix + ".";
    return lines[cursor].first.substr(pfx.length());
}

void GronReader::endObject() { ctx.pop_back(); }

void GronReader::beginArray() {
    auto& line = lines[cursor++];
    ctx.push_back({line.first, "array", -1});
}

bool GronReader::hasNextElement() {
    if (cursor >= lines.size()) return false;
    auto& arr = ctx.back();
    int ni = arr.index + 1;
    std::string exp = arr.prefix + "[" + std::to_string(ni) + "]";
    const std::string& p = lines[cursor].first;
    bool hasNext = p == exp || p.find(exp + ".") == 0 || p.find(exp + "[") == 0;
    if (hasNext) arr.index = ni;
    return hasNext;
}

void GronReader::endArray() { ctx.pop_back(); }

bool GronReader::isNull() {
    return cursor < lines.size() && lines[cursor].second == "null";
}

void GronReader::skip() {
    std::string sp = lines[cursor++].first;
    while (cursor < lines.size()) {
        const std::string& np = lines[cursor].first;
        if (np.length() > sp.length() && (np.find(sp + ".") == 0 || np.find(sp + "[") == 0)) cursor++;
        else break;
    }
}

} // namespace specodec
