#include "Border.h"
#include <SDL3/SDL_render.h>
#include <cstdio>
#include <string>

void Border::Draw(SDL_Renderer* renderer, SDL_FRect* pane) {
    SDL_FRect dst = Measure(pane);
    float sw = (float)strokeWeight;

    // Background
    SDL_SetRenderDrawColor(renderer, background.R, background.G, background.B, background.A);
    SDL_RenderFillRect(renderer, &dst);
    // Stroke
    SDL_SetRenderDrawColor(renderer, stroke.R, stroke.G, stroke.B, stroke.A);

    SDL_FRect edges[4] = {
        { dst.x,              dst.y,              dst.w,         sw            },
        { dst.x,              dst.y + dst.h - sw, dst.w,         sw            },
        { dst.x,              dst.y + sw,         sw,            dst.h - sw*2  },
        { dst.x + dst.w - sw, dst.y + sw,         sw,            dst.h - sw*2  },
    };
    SDL_RenderFillRects(renderer, edges, 4);

    if (content) {
        SDL_FRect contentPane = {
            dst.x + sw + padding.l,
            dst.y + sw + padding.t,
            dst.w - sw*2 - padding.l - padding.r,
            dst.h - sw*2 - padding.t - padding.b
        };
        content->Draw(renderer, &contentPane);
    }
}

void Border::debug_print_content(const std::string& prefix, bool is_last) {
    const char* conn = is_last ? "└── " : "├── ";
    std::string cpfx = prefix + (is_last ? "    " : "│   ");
    std::string ppfx = cpfx + "│  ";
    printf("%s%sBorder @ %p\n", prefix.c_str(), conn, this);
    printf("%s%-14s = #%02X%02X%02X%02X\n",  ppfx.c_str(), "background",   background.R, background.G, background.B, background.A);
    printf("%s%-14s = #%02X%02X%02X%02X\n",  ppfx.c_str(), "stroke",       stroke.R, stroke.G, stroke.B, stroke.A);
    printf("%s%-14s = %u\n",                  ppfx.c_str(), "strokeWeight", strokeWeight);
    printf("%s%-14s = l=%u r=%u t=%u b=%u\n", ppfx.c_str(), "padding",     padding.l, padding.r, padding.t, padding.b);
    printf("%s%-14s = %.0f x %.0f\n",         ppfx.c_str(), "size",        width, height);
    if (content) content->debug_print_content(cpfx, true);
}
