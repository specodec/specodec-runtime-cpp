export module specodec.spec_writer;
import std;

namespace specodec {

export class SpecWriter {
public:
    virtual ~SpecWriter() = default;
    virtual void writeString(const std::string& value) = 0;
    virtual void writeBool(bool value) = 0;
    virtual void writeInt32(std::int32_t value) = 0;
    virtual void writeInt64(std::int64_t value) = 0;
    virtual void writeUint32(std::uint32_t value) = 0;
    virtual void writeUint64(std::uint64_t value) = 0;
    virtual void writeFloat32(float value) = 0;
    virtual void writeFloat64(double value) = 0;
    virtual void writeNull() = 0;
    virtual void writeBytes(const std::vector<std::uint8_t>& value) = 0;
    virtual void writeEnum(const std::string& value) = 0;
    virtual void beginObject(int fieldCount) = 0;
    virtual void writeField(const std::string& name) = 0;
    virtual void endObject() = 0;
    virtual void beginArray(int elementCount) = 0;
    virtual void nextElement() = 0;
    virtual void endArray() = 0;
    virtual std::vector<std::uint8_t> toBytes() = 0;
};

} // namespace specodec
