#pragma once
#include <stdint.h>
#include <ostream>

typedef struct {
    uint8_t R;
    uint8_t G;
    uint8_t B;
    uint8_t A;
} Color;

inline std::ostream& operator<<(std::ostream& os, const Color& c) {
    return os << "Color(r=" << +c.R << ", g=" << +c.G << ", b=" << +c.B << ", a=" << +c.A << ")";
}

class Colors {
public:
    // Basics
    static constexpr Color Red          = Color{255,   0,   0, 255};
    static constexpr Color Green        = Color{  0, 255,   0, 255};
    static constexpr Color Blue         = Color{  0,   0, 255, 255};
    static constexpr Color White        = Color{255, 255, 255, 255};
    static constexpr Color Black        = Color{  0,   0,   0, 255};
    static constexpr Color Transparent  = Color{  0,   0,   0,   0};

    // Grays
    static constexpr Color Gray         = Color{128, 128, 128, 255};
    static constexpr Color LightGray    = Color{211, 211, 211, 255};
    static constexpr Color DarkGray     = Color{ 64,  64,  64, 255};
    static constexpr Color Silver       = Color{192, 192, 192, 255};

    // Reds / Pinks
    static constexpr Color DarkRed      = Color{139,   0,   0, 255};
    static constexpr Color Crimson      = Color{220,  20,  60, 255};
    static constexpr Color Salmon       = Color{250, 128, 114, 255};
    static constexpr Color Pink         = Color{255, 192, 203, 255};
    static constexpr Color HotPink      = Color{255, 105, 180, 255};
    static constexpr Color DeepPink     = Color{255,  20, 147, 255};

    // Oranges / Yellows
    static constexpr Color Orange       = Color{255, 165,   0, 255};
    static constexpr Color DarkOrange   = Color{255, 140,   0, 255};
    static constexpr Color Gold         = Color{255, 215,   0, 255};
    static constexpr Color Yellow       = Color{255, 255,   0, 255};
    static constexpr Color Khaki        = Color{240, 230, 140, 255};

    // Greens
    static constexpr Color Lime         = Color{  0, 255,   0, 255};
    static constexpr Color LimeGreen    = Color{ 50, 205,  50, 255};
    static constexpr Color DarkGreen    = Color{  0, 100,   0, 255};
    static constexpr Color ForestGreen  = Color{ 34, 139,  34, 255};
    static constexpr Color SeaGreen     = Color{ 46, 139,  87, 255};
    static constexpr Color Olive        = Color{128, 128,   0, 255};
    static constexpr Color Teal         = Color{  0, 128, 128, 255};
    static constexpr Color Mint         = Color{170, 255, 195, 255};

    // Blues / Cyans
    static constexpr Color Cyan         = Color{  0, 255, 255, 255};
    static constexpr Color SkyBlue      = Color{135, 206, 235, 255};
    static constexpr Color DeepSkyBlue  = Color{  0, 191, 255, 255};
    static constexpr Color DodgerBlue   = Color{ 30, 144, 255, 255};
    static constexpr Color RoyalBlue    = Color{ 65, 105, 225, 255};
    static constexpr Color Navy         = Color{  0,   0, 128, 255};
    static constexpr Color MidnightBlue = Color{ 25,  25, 112, 255};
    static constexpr Color SteelBlue    = Color{ 70, 130, 180, 255};

    // Purples / Magentas
    static constexpr Color Magenta      = Color{255,   0, 255, 255};
    static constexpr Color Purple       = Color{128,   0, 128, 255};
    static constexpr Color Violet       = Color{238, 130, 238, 255};
    static constexpr Color Indigo       = Color{ 75,   0, 130, 255};
    static constexpr Color Lavender     = Color{230, 230, 250, 255};
    static constexpr Color Plum         = Color{221, 160, 221, 255};
    static constexpr Color Orchid       = Color{218, 112, 214, 255};

    // Browns
    static constexpr Color Brown        = Color{165,  42,  42, 255};
    static constexpr Color SaddleBrown  = Color{139,  69,  19, 255};
    static constexpr Color Sienna       = Color{160,  82,  45, 255};
    static constexpr Color Tan          = Color{210, 180, 140, 255};
    static constexpr Color Beige        = Color{245, 245, 220, 255};
    static constexpr Color Wheat        = Color{245, 222, 179, 255};
};
