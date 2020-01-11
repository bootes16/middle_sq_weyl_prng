//
// Middle Square Weyl Sequence PRNG
//
// Simple pseudo random number generator class.
//
// Author: Greg Johnson
// Github: bootes16
//
#ifndef MIDDLE_SQ_WEYL_H
#define MIDDLE_SQ_WEYL_H
#include <iostream>

//
// Implements the Middle Square Weyle Sequence psuedo random number generator.
// The templated type size determines the output size range. Sort of.
// The range doesn't work terribly well for anything by char, doesn't give a good
// spread of values for large types like int.
// PRNG algorithm from: https://en.wikipedia.org/wiki/Middle-square_method.
//
// Template Args:
//   T          Type which dictates PRNG value range. 
// 
template <typename T>
class MiddleSqWeyl {
    const uint64_t s {0xb5ad4eceda1ce2a9};
    uint64_t x {0};
    uint64_t w {0};

    // Bitmask only really matters for char to ensure it serves 7-bit values.
    constexpr static const bool is_char = std::is_signed<T>::value && (sizeof(T) == 1);
    constexpr static const uint32_t bitmask = is_char ? 0x7f : 0xffffffff;

public:
    MiddleSqWeyl() {}
    MiddleSqWeyl(unsigned seed) {
        this->seed(seed);
    }
    
    void seed(unsigned seed) {
        reset();
        if (0 == seed) return;
        x = seed * seed;
        w += s;
        x += w;
        x = (x >> 32) | ( x << 32);
    }

    // Reset the PRNG state so the same data can be generated again.
    void reset() {
        x = w = 0;
    }
    
    T operator()() {
        x *= x;
        w += s;
        x += w;
        x = (x >> 32) | ( x << 32);
        x += is_char;
        return static_cast<T>(x & bitmask);
    }
};
#endif /* MIDDLE_SQ_WEYL */
