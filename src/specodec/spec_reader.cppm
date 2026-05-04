export module specodec.spec_reader;
import std;

namespace specodec {

export class SpecReader {
public:
    virtual ~SpecReader() = default;
    virtual void beginObject() = 0;
    virtual bool hasNextField() = 0;
    virtual std::string readFieldName() = 0;
    virtual void endObject() = 0;
    virtual void beginArray() = 0;
    virtual bool hasNextElement() = 0;
    virtual void endArray() = 0;
    virtual std::string readString() = 0;
    virtual bool readBool() = 0;
    virtual std::int32_t readInt32() = 0;
    virtual std::int64_t readInt64() = 0;
    virtual std::uint32_t readUint32() = 0;
    virtual std::uint64_t readUint64() = 0;
    virtual float readFloat32() = 0;
    virtual double readFloat64() = 0;
    virtual void readNull() = 0;
    virtual std::vector<std::uint8_t> readBytes() = 0;
    virtual std::string readEnum() = 0;
    virtual bool isNull() = 0;
    virtual void skip() = 0;
};

} // namespace specodec
