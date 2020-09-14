// Park and Miller (CACM 31:10 p1195)
#include <cstdint>

class ParkMiller2
{
public:
    ParkMiller2(int seed = 0) : seed{seed} {}
    ~ParkMiller2() = default;

    double operator()() {
        int32_t hi = seed / q;
        int32_t lo = seed % q;
        int32_t test = (a * lo) - (r * hi);
        seed = test > 0 ? test : test + m;
        return static_cast<double>(seed) / static_cast<double>(m);
    }

private:
    int seed {};

    static const int32_t a = 16807;
    static const int32_t m = 0x7fffffff;
    static constexpr int32_t q = m / a;
    static constexpr int32_t r = q % a;
};
