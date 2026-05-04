module;
#include <cstdlib>
#include <cmath>
export module test_ryu;
import std;
import specodec;

using namespace specodec::ryu;

static bool startsWith(const std::string& s, const std::string& prefix) {
    return s.rfind(prefix, 0) == 0;
}

static std::string trim(const std::string& s) {
    auto start = s.find_first_not_of(" \t\r\n");
    auto end = s.find_last_not_of(" \t\r\n");
    if (start == std::string::npos) return "";
    return s.substr(start, end - start + 1);
}

static std::vector<std::string> loadTests(const std::string& filename) {
    std::vector<std::string> result;
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        std::string t = trim(line);
        if (t.empty() || startsWith(t, "#")) continue;
        result.push_back(t);
    }
    return result;
}

static std::vector<std::string> loadCoverageTests(const std::string& filename) {
    std::vector<std::string> result;
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        std::string t = trim(line);
        if (t.empty() || !std::isdigit(static_cast<unsigned char>(t[0]))) continue;
        std::size_t hashPos = t.find('#');
        if (hashPos != std::string::npos) {
            t = trim(t.substr(0, hashPos));
            if (t.empty()) continue;
        }
        result.push_back(t);
    }
    return result;
}

static std::vector<std::string> loadExpected(const std::string& filename) {
    std::vector<std::string> result;
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        std::string t = trim(line);
        if (t.empty()) continue;
        result.push_back(t);
    }
    return result;
}

static float parseFloat(const std::string& s) {
    if (s == "NaN") return std::nanf("");
    if (s == "Infinity" || s == "+Infinity") return std::numeric_limits<float>::infinity();
    if (s == "-Infinity") return -std::numeric_limits<float>::infinity();
    char* end = nullptr;
    float val = std::strtof(s.c_str(), &end);
    return val;
}

static double parseDouble(const std::string& s) {
    if (s == "NaN") return std::nan("");
    if (s == "Infinity" || s == "+Infinity") return std::numeric_limits<double>::infinity();
    if (s == "-Infinity") return -std::numeric_limits<double>::infinity();
    char* end = nullptr;
    double val = std::strtod(s.c_str(), &end);
    return val;
}

int main() {
    int passed = 0, failed = 0;

    // === Float32 Original ===
    std::cout << "=== Float32 Original (125 tests) ===" << std::endl;
    {
        auto inputs = loadTests("test_cases_f32.txt");
        auto expected = loadExpected("expected_f32.txt");
        int catPass = 0, catFail = 0;
        int failShown = 0;
        std::size_t n = std::min(inputs.size(), expected.size());
        for (std::size_t i = 0; i < n; i++) {
            float val = parseFloat(inputs[i]);
            std::string result = float32ToString(val);
            if (result == expected[i]) {
                catPass++; passed++;
            } else {
                catFail++; failed++;
                if (failShown < 5) {
                    std::cout << "FAIL: " << inputs[i] << " => " << result
                              << " (expected " << expected[i] << ")" << std::endl;
                    failShown++;
                }
            }
        }
        std::cout << catPass << "/" << n << std::endl << std::endl;
    }

    // === Float64 Original ===
    std::cout << "=== Float64 Original (102 tests) ===" << std::endl;
    {
        auto inputs = loadTests("test_cases_f64.txt");
        auto expected = loadExpected("expected_f64.txt");
        int catPass = 0, catFail = 0;
        int failShown = 0;
        std::size_t n = std::min(inputs.size(), expected.size());
        for (std::size_t i = 0; i < n; i++) {
            double val = parseDouble(inputs[i]);
            std::string result = float64ToString(val);
            if (result == expected[i]) {
                catPass++; passed++;
            } else {
                catFail++; failed++;
                if (failShown < 5) {
                    std::cout << "FAIL: " << inputs[i] << " => " << result
                              << " (expected " << expected[i] << ")" << std::endl;
                    failShown++;
                }
            }
        }
        std::cout << catPass << "/" << n << std::endl << std::endl;
    }

    // === Float32 Coverage ===
    std::cout << "=== Float32 Coverage (78 tests) ===" << std::endl;
    {
        auto inputs = loadCoverageTests("test_cases_table_coverage.txt");
        auto expected = loadExpected("expected_table_coverage.txt");
        int catPass = 0, catFail = 0;
        int failShown = 0;
        std::size_t n = std::min(inputs.size(), expected.size());
        for (std::size_t i = 0; i < n; i++) {
            float val = parseFloat(inputs[i]);
            std::string result = float32ToString(val);
            if (result == expected[i]) {
                catPass++; passed++;
            } else {
                catFail++; failed++;
                if (failShown < 5) {
                    std::cout << "FAIL: " << inputs[i] << " => " << result
                              << " (expected " << expected[i] << ")" << std::endl;
                    failShown++;
                }
            }
        }
        std::cout << catPass << "/" << n << std::endl << std::endl;
    }

    // === Float64 Coverage ===
    std::cout << "=== Float64 Coverage (616 tests) ===" << std::endl;
    {
        auto inputs = loadCoverageTests("test_cases_f64_table_coverage.txt");
        auto expected = loadExpected("expected_f64_table_coverage.txt");
        int catPass = 0, catFail = 0;
        int failShown = 0;
        std::size_t n = std::min(inputs.size(), expected.size());
        for (std::size_t i = 0; i < n; i++) {
            double val = parseDouble(inputs[i]);
            std::string result = float64ToString(val);
            if (result == expected[i]) {
                catPass++; passed++;
            } else {
                catFail++; failed++;
                if (failShown < 5) {
                    std::cout << "FAIL: " << inputs[i] << " => " << result
                              << " (expected " << expected[i] << ")" << std::endl;
                    failShown++;
                }
            }
        }
        std::cout << catPass << "/" << n << std::endl << std::endl;
    }

    int total = passed + failed;
    std::cout << "=== TOTAL: " << passed << "/" << total << " ===" << std::endl;

    return failed > 0 ? 1 : 0;
}
