#pragma once
#include <cstdint>

class Thickness {
public:
    Thickness();
    Thickness(uint32_t t);
    Thickness(uint32_t y, uint32_t x);
    Thickness(uint32_t l, uint32_t r, uint32_t t, uint32_t b);
    ~Thickness();
    uint32_t l, r, t, b;
};
