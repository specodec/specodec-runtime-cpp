export module specodec.ryu.f32;
import std;
import specodec.ryu.math;
import specodec.ryu.tables_f32;

namespace specodec {
namespace ryu {

export std::string float32ToString(float f);

static const int FLOAT_MANTISSA_BITS = 23;
static const int FLOAT_BIAS = 127;
static const int FLOAT_POW5_INV_BITCOUNT = 59;
static const int FLOAT_POW5_BITCOUNT = 61;

static inline std::uint32_t float_to_bits(float f) {
    std::uint32_t bits;
    std::memcpy(&bits, &f, sizeof(bits));
    return bits;
}

std::string float32ToString(float f) {
    std::uint32_t bits = float_to_bits(f);

    bool sign = (bits >> 31) != 0;
    std::uint32_t ieeeMantissa = bits & 0x7FFFFF;
    int ieeeExponent = (bits >> 23) & 0xFF;

    if (ieeeExponent == 255) {
        if (ieeeMantissa == 0) {
            return sign ? "-Infinity" : "Infinity";
        }
        return "NaN";
    }
    if (ieeeExponent == 0 && ieeeMantissa == 0) {
        return sign ? "-0E0" : "0E0";
    }

    int e2;
    std::uint64_t m2;
    if (ieeeExponent == 0) {
        e2 = 1 - FLOAT_BIAS - FLOAT_MANTISSA_BITS - 2;
        m2 = (std::uint64_t)ieeeMantissa;
    } else {
        e2 = ieeeExponent - FLOAT_BIAS - FLOAT_MANTISSA_BITS - 2;
        m2 = ((1ULL << FLOAT_MANTISSA_BITS) | (std::uint64_t)ieeeMantissa);
    }

    bool even = (m2 & 1ULL) == 0ULL;
    bool acceptBounds = even;

    std::uint64_t mv = m2 * 4ULL;
    std::uint64_t mp = mv + 2ULL;
    int mmShift = 0;
    if (ieeeMantissa != 0 || ieeeExponent <= 1) {
        mmShift = 1;
    }
    std::uint64_t mm = mv - 1ULL - (std::uint64_t)mmShift;

    bool vrIsTrailingZeros = false;
    bool vmIsTrailingZeros = false;
    std::uint64_t lastDigit = 0ULL;
    int e10;
    std::uint64_t vr, vp, vm;

    if (e2 >= 0) {
        int q = log10Pow2(e2);
        e10 = q;
        int k = FLOAT_POW5_INV_BITCOUNT + pow5bits(q) - 1;
        int i = -e2 + q + k;

        vr = mulShift32(mv, FLOAT_POW5_INV_SPLIT[q] + 1ULL, i);
        vp = mulShift32(mp, FLOAT_POW5_INV_SPLIT[q] + 1ULL, i);
        vm = mulShift32(mm, FLOAT_POW5_INV_SPLIT[q] + 1ULL, i);

        if (q != 0 && (vp - 1ULL) / 10ULL <= vm / 10ULL) {
            int l = FLOAT_POW5_INV_BITCOUNT + pow5bits(q - 1) - 1;
            lastDigit = mulShift32(mv, FLOAT_POW5_INV_SPLIT[q - 1] + 1ULL, -e2 + q - 1 + l) % 10ULL;
        }

        if (q <= 9) {
            if (mv % 5ULL == 0ULL) {
                vrIsTrailingZeros = multipleOfPowerOf5_32((std::uint32_t)mv, q);
                vmIsTrailingZeros = multipleOfPowerOf5_32((std::uint32_t)mm, q);
                if (multipleOfPowerOf5_32((std::uint32_t)mp, q)) {
                    vp--;
                }
            }
        }
    } else {
        int q = log10Pow5(-e2);
        e10 = q + e2;
        int i = -e2 - q;
        int k = pow5bits(i) - FLOAT_POW5_BITCOUNT;
        int j = q - k;

        vr = mulShift32(mv, FLOAT_POW5_SPLIT[i], j);
        vp = mulShift32(mp, FLOAT_POW5_SPLIT[i], j);
        vm = mulShift32(mm, FLOAT_POW5_SPLIT[i], j);

        if (q != 0 && (vp - 1ULL) / 10ULL <= vm / 10ULL) {
            int j2 = q - 1 - (pow5bits(i + 1) - FLOAT_POW5_BITCOUNT);
            lastDigit = mulShift32(mv, FLOAT_POW5_SPLIT[i + 1], j2) % 10ULL;
        }

        if (q <= 1) {
            vrIsTrailingZeros = true;
            if (acceptBounds) {
                vmIsTrailingZeros = mmShift == 1;
            } else {
                vp--;
            }
        } else if (q < 31) {
            vrIsTrailingZeros = multipleOfPowerOf2_32((std::uint32_t)mv, q - 1);
            if (acceptBounds) {
                vmIsTrailingZeros = multipleOfPowerOf5_32((std::uint32_t)mm, q);
            } else {
                if (multipleOfPowerOf5_32((std::uint32_t)mp, q)) {
                    vp--;
                }
            }
        }
    }

    int removed = 0;
    std::uint64_t vr2 = vr;
    std::uint64_t vp2 = vp;
    std::uint64_t vm2 = vm;

    if (vmIsTrailingZeros || vrIsTrailingZeros) {
        while (vp2 / 10ULL > vm2 / 10ULL) {
            vmIsTrailingZeros = vmIsTrailingZeros && (vm2 % 10ULL == 0ULL);
            vrIsTrailingZeros = vrIsTrailingZeros && (lastDigit == 0ULL);
            lastDigit = vr2 % 10ULL;
            vr2 /= 10ULL;
            vp2 /= 10ULL;
            vm2 /= 10ULL;
            removed++;
        }

        if (vmIsTrailingZeros) {
            while (vm2 % 10ULL == 0ULL) {
                vrIsTrailingZeros = vrIsTrailingZeros && (lastDigit == 0ULL);
                lastDigit = vr2 % 10ULL;
                vr2 /= 10ULL;
                vp2 /= 10ULL;
                vm2 /= 10ULL;
                removed++;
            }
        }

        if (vrIsTrailingZeros && lastDigit == 5ULL && (vr2 & 1ULL) == 0ULL) {
            lastDigit = 4ULL;
        }

        bool roundUp = (vr2 == vm2 && (!acceptBounds || !vmIsTrailingZeros)) || lastDigit >= 5ULL;
        std::uint64_t output = vr2;
        if (roundUp) {
            output++;
        }
        int exp = e10 + removed;
        int olength = decimalLength9((std::uint32_t)output);

        std::string result;
        if (sign) result = "-";
        std::string digits = std::to_string(output);
        if (olength == 1) {
            result += digits;
        } else {
            result += digits.substr(0, 1) + "." + digits.substr(1);
        }
        result += "E" + std::to_string(exp + olength - 1);
        return result;
    } else {
        while (vp2 / 10ULL > vm2 / 10ULL) {
            lastDigit = vr2 % 10ULL;
            vr2 /= 10ULL;
            vp2 /= 10ULL;
            vm2 /= 10ULL;
            removed++;
        }

        std::uint64_t output = vr2;
        if (vr2 == vm2 || lastDigit >= 5ULL) {
            output++;
        }
        int exp = e10 + removed;
        int olength = decimalLength9((std::uint32_t)output);

        std::string result;
        if (sign) result = "-";
        std::string digits = std::to_string(output);
        if (olength == 1) {
            result += digits;
        } else {
            result += digits.substr(0, 1) + "." + digits.substr(1);
        }
        result += "E" + std::to_string(exp + olength - 1);
        return result;
    }
}

} // namespace ryu
} // namespace specodec
