export module specodec.json_reader;
import std;
import specodec.spec_reader;
import specodec.scodec_error;

namespace specodec {

export class JsonReader : public SpecReader {
public:
    explicit JsonReader(const std::vector<std::uint8_t>& data);
    ~JsonReader() override = default;

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
    std::string src;
    std::size_t pos;
    std::vector<bool> _firstField;
    std::vector<bool> _firstElem;

    void ws();
    char peek();
    char read();
    void expect(char ch);
    std::string parseString();
    std::string parseNumberRaw();
};

JsonReader::JsonReader(const std::vector<std::uint8_t>& data)
    : src(data.begin(), data.end()), pos(0) {}

void JsonReader::ws() {
    while (pos < src.length()) {
        unsigned char c = (unsigned char)src[pos];
        if (c == 0x20 || c == 0x09 || c == 0x0A || c == 0x0D) pos++;
        else break;
    }
}

char JsonReader::peek() {
    ws();
    if (pos >= src.length()) throw SCodecError("internal", "json: unexpected end of input");
    return src[pos];
}

char JsonReader::read() {
    ws();
    if (pos >= src.length()) throw SCodecError("internal", "json: unexpected end of input");
    return src[pos++];
}

void JsonReader::expect(char ch) {
    char got = read();
    if (got != ch) {
        std::string msg = "json: expected '";
        msg += ch;
        msg += "', got '";
        msg += got;
        msg += "' at " + std::to_string(pos - 1);
        throw SCodecError("internal", msg);
    }
}

std::string JsonReader::parseString() {
    expect('"');
    std::string parts;
    while (pos < src.length()) {
        char c = src[pos];
        unsigned char code = (unsigned char)c;
        if (code == 0x22) { pos++; return parts; }
        if (code == 0x5C) {
            pos++;
            if (pos >= src.length()) throw SCodecError("internal", "json: unexpected end of string escape");
            char esc = src[pos];
            switch ((unsigned char)esc) {
                case 0x22: parts += '"'; pos++; break;
                case 0x5C: parts += '\\'; pos++; break;
                case 0x2F: parts += '/'; pos++; break;
                case 0x62: parts += '\b'; pos++; break;
                case 0x66: parts += '\f'; pos++; break;
                case 0x6E: parts += '\n'; pos++; break;
                case 0x72: parts += '\r'; pos++; break;
                case 0x74: parts += '\t'; pos++; break;
                case 0x75: {
                    pos++;
                    if (pos + 4 > src.length()) throw SCodecError("internal", "json: incomplete unicode escape");
                    std::string hex = src.substr(pos, 4);
                    int cp = (int)std::strtol(hex.c_str(), nullptr, 16);
                    pos += 4;
                    if (cp >= 0xD800 && cp <= 0xDBFF) {
                        if (pos + 6 <= src.length() && src[pos] == '\\' && src[pos + 1] == 'u') {
                            pos += 2;
                            std::string hex2 = src.substr(pos, 4);
                            int low = (int)std::strtol(hex2.c_str(), nullptr, 16);
                            pos += 4;
                            if (low >= 0xDC00 && low <= 0xDFFF) {
                                cp = 0x10000 + (cp - 0xD800) * 0x400 + (low - 0xDC00);
                            } else {
                                throw SCodecError("internal", "json: expected low surrogate");
                            }
                        } else {
                            throw SCodecError("internal", "json: expected low surrogate");
                        }
                    }
                    if (cp <= 0x7F) {
                        parts += (char)cp;
                    } else if (cp <= 0x7FF) {
                        parts += (char)(0xC0 | (cp >> 6));
                        parts += (char)(0x80 | (cp & 0x3F));
                    } else if (cp <= 0xFFFF) {
                        parts += (char)(0xE0 | (cp >> 12));
                        parts += (char)(0x80 | ((cp >> 6) & 0x3F));
                        parts += (char)(0x80 | (cp & 0x3F));
                    } else {
                        parts += (char)(0xF0 | (cp >> 18));
                        parts += (char)(0x80 | ((cp >> 12) & 0x3F));
                        parts += (char)(0x80 | ((cp >> 6) & 0x3F));
                        parts += (char)(0x80 | (cp & 0x3F));
                    }
                    break;
                }
                default: {
                    std::string msg = "json: invalid escape '\\";
                    msg += esc;
                    msg += "'";
                    throw SCodecError("internal", msg);
                }
            }
        } else if (code < 0x20) {
            throw SCodecError("internal", "json: unescaped control char");
        } else {
            parts += c; pos++;
        }
    }
    throw SCodecError("internal", "json: unterminated string");
}

std::string JsonReader::parseNumberRaw() {
    ws();
    std::size_t start = pos;
    if (pos < src.length() && src[pos] == '-') pos++;
    if (pos >= src.length()) throw SCodecError("internal", "json: unexpected end of number");
    if (src[pos] == '0') { pos++; }
    else if (src[pos] >= '1' && src[pos] <= '9') {
        pos++;
        while (pos < src.length() && src[pos] >= '0' && src[pos] <= '9') pos++;
    } else throw SCodecError("internal", "json: invalid number");
    if (pos < src.length() && src[pos] == '.') {
        pos++;
        if (pos >= src.length() || src[pos] < '0' || src[pos] > '9')
            throw SCodecError("internal", "json: invalid fraction");
        while (pos < src.length() && src[pos] >= '0' && src[pos] <= '9') pos++;
    }
    if (pos < src.length() && (src[pos] == 'e' || src[pos] == 'E')) {
        pos++;
        if (pos < src.length() && (src[pos] == '+' || src[pos] == '-')) pos++;
        if (pos >= src.length() || src[pos] < '0' || src[pos] > '9')
            throw SCodecError("internal", "json: invalid exponent");
        while (pos < src.length() && src[pos] >= '0' && src[pos] <= '9') pos++;
    }
    return src.substr(start, pos - start);
}

std::string JsonReader::readString() { return parseString(); }

bool JsonReader::readBool() {
    char ch = peek();
    if (ch == 't') {
        if (read() != 't' || read() != 'r' || read() != 'u' || read() != 'e')
            throw SCodecError("internal", "json: expected true");
        return true;
    }
    if (ch == 'f') {
        if (read() != 'f' || read() != 'a' || read() != 'l' || read() != 's' || read() != 'e')
            throw SCodecError("internal", "json: expected false");
        return false;
    }
    throw SCodecError("internal", std::string("json: expected bool, got '") + ch + "'");
}

std::int32_t JsonReader::readInt32() {
    std::string raw = parseNumberRaw();
    try { return (std::int32_t)std::stoll(raw); }
    catch (...) { throw SCodecError("internal", "json: invalid int32: " + raw); }
}

std::int64_t JsonReader::readInt64() {
    if (peek() == '"') {
        std::string s = parseString();
        try { return std::stoll(s); }
        catch (...) { throw SCodecError("internal", "json: invalid int64: " + s); }
    }
    std::string raw = parseNumberRaw();
    try { return std::stoll(raw); }
    catch (...) { throw SCodecError("internal", "json: invalid int64: " + raw); }
}

std::uint32_t JsonReader::readUint32() {
    std::string raw = parseNumberRaw();
    try { return (std::uint32_t)std::stoull(raw); }
    catch (...) { throw SCodecError("internal", "json: invalid uint32: " + raw); }
}

std::uint64_t JsonReader::readUint64() {
    if (peek() == '"') {
        std::string s = parseString();
        try { return std::stoull(s); }
        catch (...) { throw SCodecError("internal", "json: invalid uint64: " + s); }
    }
    std::string raw = parseNumberRaw();
    try { return std::stoull(raw); }
    catch (...) { throw SCodecError("internal", "json: invalid uint64: " + raw); }
}

float JsonReader::readFloat32() {
    if (peek() == '"') {
        std::string s = parseString();
        if (s == "NaN") return std::numeric_limits<float>::quiet_NaN();
        if (s == "Infinity") return std::numeric_limits<float>::infinity();
        if (s == "-Infinity") return -std::numeric_limits<float>::infinity();
        try { return std::stof(s); }
        catch (...) { throw SCodecError("internal", "json: invalid float32: " + s); }
    }
    std::string raw = parseNumberRaw();
    try { return std::stof(raw); }
    catch (...) { throw SCodecError("internal", "json: invalid float32: " + raw); }
}

double JsonReader::readFloat64() {
    if (peek() == '"') {
        std::string s = parseString();
        if (s == "NaN") return std::numeric_limits<double>::quiet_NaN();
        if (s == "Infinity") return std::numeric_limits<double>::infinity();
        if (s == "-Infinity") return -std::numeric_limits<double>::infinity();
        try { return std::stod(s); }
        catch (...) { throw SCodecError("internal", "json: invalid float64: " + s); }
    }
    std::string raw = parseNumberRaw();
    try { return std::stod(raw); }
    catch (...) { throw SCodecError("internal", "json: invalid float64: " + raw); }
}

void JsonReader::readNull() {
    if (read() != 'n' || read() != 'u' || read() != 'l' || read() != 'l')
        throw SCodecError("internal", "json: expected null");
}

std::vector<std::uint8_t> JsonReader::readBytes() {
    std::string s = parseString();
    int lookup[128];
    for (int i = 0; i < 128; i++) lookup[i] = -1;
    std::string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    for (std::size_t i = 0; i < chars.size(); i++) lookup[(unsigned char)chars[i]] = (int)i;

    std::vector<std::uint8_t> out;
    std::size_t i = 0;
    while (i < s.length()) {
        int a = lookup[(unsigned char)s[i]];
        int b = lookup[(unsigned char)s[i + 1]];
        int c = s[i + 2] == '=' ? -1 : lookup[(unsigned char)s[i + 2]];
        int d = s[i + 3] == '=' ? -1 : lookup[(unsigned char)s[i + 3]];
        if (a < 0 || b < 0) throw SCodecError("internal", "json: invalid base64");
        out.push_back((std::uint8_t)((a << 2) | (b >> 4)));
        if (c >= 0) {
            out.push_back((std::uint8_t)(((b & 0xF) << 4) | (c >> 2)));
            if (d >= 0) out.push_back((std::uint8_t)(((c & 0x3) << 6) | d));
        }
        i += 4;
    }
    return out;
}

std::string JsonReader::readEnum() { return parseString(); }

void JsonReader::beginObject() {
    expect('{');
    _firstField.push_back(true);
}

bool JsonReader::hasNextField() {
    char ch = peek();
    if (ch == '}') {
        _firstField.pop_back();
        return false;
    }
    std::size_t top = _firstField.size() - 1;
    if (!_firstField[top]) {
        if (ch != ',') {
            std::string msg = "json: expected ',' or '}', got '";
            msg += ch;
            msg += "'";
            throw SCodecError("internal", msg);
        }
        pos++;
    } else {
        _firstField[top] = false;
    }
    return true;
}

std::string JsonReader::readFieldName() {
    std::string key = parseString();
    ws();
    if (pos < src.length() && src[pos] == ':') {
        pos++;
    } else {
        throw SCodecError("internal", "json: expected ':' after field name '" + key + "'");
    }
    return key;
}

void JsonReader::endObject() { expect('}'); }

void JsonReader::beginArray() {
    expect('[');
    _firstElem.push_back(true);
}

bool JsonReader::hasNextElement() {
    char ch = peek();
    if (ch == ']') {
        _firstElem.pop_back();
        return false;
    }
    std::size_t top = _firstElem.size() - 1;
    if (!_firstElem[top]) {
        if (ch != ',') {
            std::string msg = "json: expected ',' or ']', got '";
            msg += ch;
            msg += "'";
            throw SCodecError("internal", msg);
        }
        pos++;
    } else {
        _firstElem[top] = false;
    }
    return true;
}

void JsonReader::endArray() { expect(']'); }

bool JsonReader::isNull() { return peek() == 'n'; }

void JsonReader::skip() {
    ws();
    if (pos >= src.length()) throw SCodecError("internal", "json: unexpected end of input");
    char ch = src[pos];
    switch (ch) {
        case '"': {
            pos++;
            while (pos < src.length()) {
                if (src[pos] == '\\') pos += 2;
                else if (src[pos] == '"') { pos++; return; }
                else pos++;
            }
            throw SCodecError("internal", "json: unterminated string in skip");
        }
        case '{': {
            beginObject();
            while (hasNextField()) {
                readFieldName();
                skip();
            }
            endObject();
            break;
        }
        case '[': {
            beginArray();
            while (hasNextElement()) {
                skip();
            }
            endArray();
            break;
        }
        case 't': if (read() != 't' || read() != 'r' || read() != 'u' || read() != 'e') throw SCodecError("internal", "json: skip expected true"); break;
        case 'f': if (read() != 'f' || read() != 'a' || read() != 'l' || read() != 's' || read() != 'e') throw SCodecError("internal", "json: skip expected false"); break;
        case 'n': if (read() != 'n' || read() != 'u' || read() != 'l' || read() != 'l') throw SCodecError("internal", "json: skip expected null"); break;
        default:
            if ((ch >= '0' && ch <= '9') || ch == '-') parseNumberRaw();
            else throw SCodecError("internal", std::string("json: unexpected '") + ch + "' in skip");
    }
}

} // namespace specodec
