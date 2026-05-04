export module specodec.scodec_error;
import std;

namespace specodec {

export class SCodecError : public std::runtime_error {
public:
    std::string code;
    SCodecError(const std::string& code_, const std::string& message)
        : std::runtime_error(message), code(code_) {}
};

} // namespace specodec
