#pragma once
#include <SDL3/SDL.h>

class IDrawable {
public:
    virtual void Draw(SDL_Renderer* renderer, SDL_FRect *pane) = 0;
    virtual ~IDrawable() = default;
};
