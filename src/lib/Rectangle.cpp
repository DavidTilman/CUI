#include "Rectangle.h"
#include <SDL3/SDL_render.h>
#include <cstdio>
#include <string>

void Rectangle::Draw(SDL_Renderer* renderer, SDL_FRect* pane) {
    SDL_FRect dst = Measure(pane);
    SDL_SetRenderDrawColor(renderer, fill.R, fill.G, fill.B, fill.A);
    SDL_RenderFillRect(renderer, &dst);
}

void Rectangle::debug_print_content(const std::string& prefix, bool is_last) {
    const char* conn = is_last ? "└── " : "├── ";
    std::string ppfx = prefix + (is_last ? "    " : "│   ") + "│  ";
    printf("%s%sRectangle @ %p\n", prefix.c_str(), conn, this);
    printf("%s%-6s = #%02X%02X%02X%02X\n", ppfx.c_str(), "fill", fill.R, fill.G, fill.B, fill.A);
    printf("%s%-6s = %.0f x %.0f\n",        ppfx.c_str(), "size", width, height);
}
