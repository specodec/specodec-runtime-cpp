export module specodec.ryu.f64;
import std;
import specodec.ryu.math;
import specodec.ryu.tables_f64;

namespace specodec {
namespace ryu {

export std::string float64ToString(double d);

static const int DOUBLE_MANTISSA_BITS = 52;
static const int DOUBLE_BIAS = 1023;
static const int DOUBLE_POW5_INV_BITCOUNT = 125;
static const int DOUBLE_POW5_BITCOUNT = 125;

static inline std::uint64_t double_to_bits(double d) {
    std::uint64_t bits;
    std::memcpy(&bits, &d, sizeof(bits));
    return bits;
}

std::string float64ToString(double d) {
    std::uint64_t bits = double_to_bits(d);

    bool sign = (bits >> 63) != 0;
    std::uint64_t ieeeMantissa = bits & 0xFFFFFFFFFFFFFULL;
    int ieeeExponent = (int)((bits >> 52) & 0x7FFULL);

    if (ieeeExponent == 2047) {
        if (ieeeMantissa == 0ULL) {
            return sign ? "-Infinity" : "Infinity";
        }
        return "NaN";
    }
    if (ieeeExponent == 0 && ieeeMantissa == 0ULL) {
        return sign ? "-0E0" : "0E0";
    }

    int e2;
    std::uint64_t m2;
    if (ieeeExponent == 0) {
        e2 = 1 - DOUBLE_BIAS - DOUBLE_MANTISSA_BITS - 2;
        m2 = ieeeMantissa;
    } else {
        e2 = ieeeExponent - DOUBLE_BIAS - DOUBLE_MANTISSA_BITS - 2;
        m2 = ((1ULL << DOUBLE_MANTISSA_BITS) | ieeeMantissa);
    }

    bool even = (m2 & 1ULL) == 0ULL;
    bool acceptBounds = even;

    std::uint64_t mv = m2 * 4ULL;
    std::uint64_t mp = mv + 2ULL;
    std::uint64_t mmShift = 0ULL;
    if (ieeeMantissa != 0ULL || ieeeExponent <= 1) {
        mmShift = 1ULL;
    }
    std::uint64_t mm = mv - 1ULL - mmShift;

    bool vrIsTrailingZeros = false;
    bool vmIsTrailingZeros = false;
    std::uint64_t lastDigit = 0ULL;
    int e10;
    std::uint64_t vr, vp, vm;

    if (e2 >= 0) {
        int q = log10Pow2(e2);
        e10 = q;
        int k = DOUBLE_POW5_INV_BITCOUNT + pow5bits(q) - 1;
        int i = -e2 + q + k;

        vr = mulShift64(mv, DOUBLE_POW5_INV_SPLIT[q], i);
        vp = mulShift64(mp, DOUBLE_POW5_INV_SPLIT[q], i);
        vm = mulShift64(mm, DOUBLE_POW5_INV_SPLIT[q], i);

        if (q != 0 && (vp - 1ULL) / 10ULL <= vm / 10ULL) {
            int l = DOUBLE_POW5_INV_BITCOUNT + pow5bits(q - 1) - 1;
            lastDigit = mulShift64(mv, DOUBLE_POW5_INV_SPLIT[q - 1], -e2 + q - 1 + l) % 10ULL;
        }

        if (q <= 21) {
            if (mv % 5ULL == 0ULL) {
                vrIsTrailingZeros = multipleOfPowerOf5_64(mv, q);
            } else if (acceptBounds) {
                vmIsTrailingZeros = multipleOfPowerOf5_64(mm, q);
            } else {
                if (multipleOfPowerOf5_64(mp, q)) {
                    vp--;
                }
            }
        }
    } else {
        int q = log10Pow5(-e2);
        e10 = q + e2;
        int i = -e2 - q;
        int k = pow5bits(i) - DOUBLE_POW5_BITCOUNT;
        int j = q - k;

        vr = mulShift64(mv, DOUBLE_POW5_SPLIT[i], j);
        vp = mulShift64(mp, DOUBLE_POW5_SPLIT[i], j);
        vm = mulShift64(mm, DOUBLE_POW5_SPLIT[i], j);

        if (q != 0 && (vp - 1ULL) / 10ULL <= vm / 10ULL) {
            int j2 = q - 1 - (pow5bits(i + 1) - DOUBLE_POW5_BITCOUNT);
            lastDigit = mulShift64(mv, DOUBLE_POW5_SPLIT[i + 1], j2) % 10ULL;
        }

        if (q <= 1) {
            vrIsTrailingZeros = true;
            if (acceptBounds) {
                vmIsTrailingZeros = mmShift == 1ULL;
            } else {
                vp--;
            }
        } else if (q < 63) {
            vrIsTrailingZeros = multipleOfPowerOf2_64(mv, q - 1);
            if (acceptBounds) {
                vmIsTrailingZeros = multipleOfPowerOf5_64(mm, q);
            } else {
                if (multipleOfPowerOf5_64(mp, q)) {
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
        int olength = decimalLength17(output);

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
        int olength = decimalLength17(output);

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
