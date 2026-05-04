export module specodec.spec_codec;
import std;
import specodec.spec_reader;
import specodec.spec_writer;
import specodec.json_reader;
import specodec.json_writer;
import specodec.gron_reader;
import specodec.gron_writer;
import specodec.msgpack_reader;
import specodec.msgpack_writer;

namespace specodec {

export template<typename T>
struct SpecCodec {
    std::function<void(SpecWriter&, const T&)> encode;
    std::function<T(SpecReader&)> decode;
};

export struct FormatEntry {
    std::string name;
    std::function<std::unique_ptr<SpecWriter>()> newWriter;
    std::function<std::unique_ptr<SpecReader>(const std::vector<std::uint8_t>&)> newReader;
};

export class FormatRegistry {
    std::vector<FormatEntry> entries;
public:
    FormatRegistry& register_(FormatEntry entry) {
        entries.push_back(std::move(entry));
        return *this;
    }

    const FormatEntry& match(const std::string& format) const {
        for (const auto& e : entries) {
            if (format == e.name) return e;
        }
        if (!entries.empty()) return entries[0];
        throw std::runtime_error("FormatRegistry: no entries registered");
    }
};

export extern const FormatRegistry defaultRegistry;

export struct RespondResult {
    std::vector<std::uint8_t> body;
    std::string name;
};

export template<typename T>
T dispatch(const SpecCodec<T>& codec, const std::vector<std::uint8_t>& body,
           const std::string& format,
           const FormatRegistry& registry = defaultRegistry) {
    const auto& fmt = registry.match(format);
    return codec.decode(*fmt.newReader(body));
}

export template<typename T>
RespondResult respond(const SpecCodec<T>& codec, const T& obj,
                      const std::string& format,
                      const FormatRegistry& registry = defaultRegistry) {
    const auto& fmt = registry.match(format);
    auto w = fmt.newWriter();
    codec.encode(*w, obj);
    return {w->toBytes(), fmt.name};
}

const FormatRegistry defaultRegistry = FormatRegistry()
    .register_(FormatEntry{
        "json",
        []() { return std::make_unique<JsonWriter>(); },
        [](const std::vector<std::uint8_t>& data) { return std::make_unique<JsonReader>(data); }
    })
    .register_(FormatEntry{
        "msgpack",
        []() { return std::make_unique<MsgPackWriter>(); },
        [](const std::vector<std::uint8_t>& data) { return std::make_unique<MsgPackReader>(data); }
    })
    .register_(FormatEntry{
        "gron",
        []() { return std::make_unique<GronWriter>(); },
        [](const std::vector<std::uint8_t>& data) { return std::make_unique<GronReader>(data); }
    });

} // namespace specodec
