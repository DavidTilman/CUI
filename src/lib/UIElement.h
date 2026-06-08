#pragma once
#include "IDrawable.h"
#include <SDL3/SDL.h>

class UIElement : public IDrawable {
public:
    float width  = -1;
    float height = -1;

protected:
    SDL_FRect Measure(SDL_FRect* pane) const {
        return {
            pane->x,
            pane->y,
            width  < 0 ? pane->w : width,
            height < 0 ? pane->h : height
        };
    }
};
