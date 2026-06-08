#include "Thickness.h"

Thickness::Thickness() { t = 0; b = 0; l = 0; r = 0; };
Thickness::Thickness(uint32_t t) { this->t = t; b = t; l = t; r = t; };
Thickness::Thickness(uint32_t x, uint32_t y) { t = y; b = y; l = x; r = x; };
Thickness::Thickness(uint32_t l, uint32_t r, uint32_t t, uint32_t b) { this->l = l; this->r = r; this->t = t; this->b = b; };

Thickness::~Thickness() { };
