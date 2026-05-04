export module specodec.float_fmt;
import std;
import specodec.ryu.f32;
import specodec.ryu.f64;

namespace specodec {

export std::string formatFloat32(float value);
export std::string formatFloat64(double value);

std::string formatFloat32(float value) {
    return ryu::float32ToString(value);
}

std::string formatFloat64(double value) {
    return ryu::float64ToString(value);
}

} // namespace specodec
