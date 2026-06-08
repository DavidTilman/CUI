#include "Rectangle.h"
#include <SDL3/SDL_render.h>

void Rectangle::Draw(SDL_Renderer* renderer, SDL_FRect* pane) {
    SDL_FRect dst = Measure(pane);
    SDL_SetRenderDrawColor(renderer, fill.R, fill.G, fill.B, fill.A);
    SDL_RenderFillRect(renderer, &dst);
}
