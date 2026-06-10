#pragma once
#include <cstdint>
#include <ostream>

class Thickness {
public:
    Thickness();
    Thickness(uint32_t t);
    Thickness(uint32_t y, uint32_t x);
    Thickness(uint32_t l, uint32_t r, uint32_t t, uint32_t b);
    ~Thickness();
    uint32_t l, r, t, b;
};

inline std::ostream& operator<<(std::ostream& os, const Thickness& t) {
    return os << "Thickness(l=" << t.l << ", r=" << t.r << ", t=" << t.t << ", b=" << t.b << ")";
}
