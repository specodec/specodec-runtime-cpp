import specodec;
#include <cstdio>

int main() {
    // Test SpecCodec dispatch
    auto codec = specodec::SpecCodec<int>{
        .encode = [](specodec::SpecWriter& w, const int& v) { w.writeInt32(v); },
        .decode = [](specodec::SpecReader& r) -> int { return r.readInt32(); }
    };

    // Test JsonWriter
    specodec::JsonWriter w;
    w.writeInt32(42);
    auto bytes = w.toBytes();
    printf("JSON: %s\n", reinterpret_cast<const char*>(bytes.data()));

    // Test Ryu
    auto s = specodec::formatFloat32(1.0f);
    printf("Ryu f32(1.0) = %s\n", s.c_str());

    auto d = specodec::formatFloat64(0.001);
    printf("Ryu f64(0.001) = %s\n", d.c_str());

    return 0;
}
