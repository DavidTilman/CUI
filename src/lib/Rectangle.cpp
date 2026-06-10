#include "Rectangle.h"
#include <SDL3/SDL_render.h>
#include <cstdio>

void Rectangle::Draw(SDL_Renderer* renderer, SDL_FRect* pane) {
    SDL_FRect dst = Measure(pane);
    SDL_SetRenderDrawColor(renderer, fill.R, fill.G, fill.B, fill.A);
    SDL_RenderFillRect(renderer, &dst);
}

void Rectangle::debug_print_content(int depth) {
    for (int i = 0; i < depth; i++) {
        printf("|   ");
    }

    printf("Rectangle @ %p (\n", this);

    for (int i = 0; i < depth; i++) {
        printf("|   ");
    }
    printf(")\n");
}
