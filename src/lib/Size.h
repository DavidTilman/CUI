#pragma once
#include <cstdint>
#include <ostream>
struct Size { uint32_t x; uint32_t y; };

inline std::ostream& operator<<(std::ostream& os, const Size& s) {
    return os << "Size(x=" << s.x << ", y=" << s.y << ")";
}
