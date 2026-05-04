export module specodec.ryu.math;
import std;

namespace specodec {
namespace ryu {

export int pow5bits(int e);
export int log10Pow2(int e);
export int log10Pow5(int e);
export int decimalLength17(std::uint64_t v);
export int decimalLength9(std::uint32_t v);
export std::uint64_t mulShift32(std::uint64_t m, std::uint64_t factor, int shift);
export std::uint64_t mulShift64(std::uint64_t m, const std::uint64_t* mul, int shift);
export std::pair<std::uint64_t, std::uint64_t> umul128(std::uint64_t a, std::uint64_t b);
export bool multipleOfPowerOf5_64(std::uint64_t value, int q);
export bool multipleOfPowerOf2_64(std::uint64_t value, int q);
export bool multipleOfPowerOf5_32(std::uint32_t value, int q);
export bool multipleOfPowerOf2_32(std::uint32_t value, int q);

int pow5bits(int e) {
    return e * 1217359 / 524288 + 1;
}

int log10Pow2(int e) {
    return e * 78913 / 262144;
}

int log10Pow5(int e) {
    return e * 732923 / 1048576;
}

int decimalLength17(std::uint64_t v) {
    if (v >= 10000000000000000ULL) return 17;
    if (v >= 1000000000000000ULL) return 16;
    if (v >= 100000000000000ULL) return 15;
    if (v >= 10000000000000ULL) return 14;
    if (v >= 1000000000000ULL) return 13;
    if (v >= 100000000000ULL) return 12;
    if (v >= 10000000000ULL) return 11;
    if (v >= 1000000000ULL) return 10;
    if (v >= 100000000ULL) return 9;
    if (v >= 10000000ULL) return 8;
    if (v >= 1000000ULL) return 7;
    if (v >= 100000ULL) return 6;
    if (v >= 10000ULL) return 5;
    if (v >= 1000ULL) return 4;
    if (v >= 100ULL) return 3;
    if (v >= 10ULL) return 2;
    return 1;
}

int decimalLength9(std::uint32_t v) {
    if (v >= 100000000U) return 9;
    if (v >= 10000000U) return 8;
    if (v >= 1000000U) return 7;
    if (v >= 100000U) return 6;
    if (v >= 10000U) return 5;
    if (v >= 1000U) return 4;
    if (v >= 100U) return 3;
    if (v >= 10U) return 2;
    return 1;
}

std::pair<std::uint64_t, std::uint64_t> umul128(std::uint64_t a, std::uint64_t b) {
    std::uint64_t aLo = a & 0xFFFFFFFFULL;
    std::uint64_t aHi = a >> 32;
    std::uint64_t bLo = b & 0xFFFFFFFFULL;
    std::uint64_t bHi = b >> 32;

    std::uint64_t ll = aLo * bLo;
    std::uint64_t lh = aLo * bHi;
    std::uint64_t hl = aHi * bLo;
    std::uint64_t hh = aHi * bHi;

    std::uint64_t mid = lh + hl;
    std::uint64_t overflow = (mid < lh) ? 1ULL : 0ULL;

    std::uint64_t hi = hh + (mid >> 32) + overflow;
    std::uint64_t lo = ll + ((mid & 0xFFFFFFFFULL) << 32);
    if (lo < ll) hi++;

    return {hi, lo};
}

std::uint64_t mulShift32(std::uint64_t m, std::uint64_t factor, int shift) {
    std::uint64_t factorLo = factor & 0xFFFFFFFFULL;
    std::uint64_t factorHi = factor >> 32;
    std::uint64_t bits0 = m * factorLo;
    std::uint64_t bits1 = m * factorHi;
    std::uint64_t sumVal = (bits0 >> 32) + bits1;
    return (sumVal >> (shift - 32)) & 0xFFFFFFFFULL;
}

std::uint64_t mulShift64(std::uint64_t m, const std::uint64_t* mul, int shift) {
    auto [hi0, lo0] = umul128(m, mul[0]);
    auto [hi2, lo2] = umul128(m, mul[1]);

    std::uint64_t sumLo = lo2 + hi0;
    std::uint64_t carry = (sumLo < lo2) ? 1ULL : 0ULL;
    std::uint64_t sumHi = hi2 + carry;

    int shiftAmount = shift - 64;
    if (shiftAmount >= 128) return 0ULL;
    if (shiftAmount >= 64) return sumHi >> (shiftAmount - 64);
    if (shiftAmount == 0) return sumLo;
    return (sumHi << (64 - shiftAmount)) | (sumLo >> shiftAmount);
}

bool multipleOfPowerOf5_64(std::uint64_t value, int q) {
    if (q == 0) return true;
    if (q >= 64) return value == 0ULL;
    std::uint64_t pow5 = 5ULL;
    for (int i = 1; i < q; i++) pow5 *= 5ULL;
    return (value % pow5) == 0ULL;
}

bool multipleOfPowerOf2_64(std::uint64_t value, int q) {
    if (q == 0) return true;
    if (q >= 64) return value == 0ULL;
    return (value & ((1ULL << q) - 1ULL)) == 0ULL;
}

bool multipleOfPowerOf5_32(std::uint32_t value, int q) {
    if (q == 0) return true;
    if (q >= 32) return value == 0U;
    std::uint32_t pow5 = 5U;
    for (int i = 1; i < q; i++) pow5 *= 5U;
    return (value % pow5) == 0U;
}

bool multipleOfPowerOf2_32(std::uint32_t value, int q) {
    if (q == 0) return true;
    if (q >= 32) return value == 0U;
    return (value & ((1U << q) - 1U)) == 0U;
}

} // namespace ryu
} // namespace specodec
