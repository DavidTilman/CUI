#pragma once
#include "IDrawable.h"
#include "Thickness.h"
#include <SDL3/SDL.h>

class UIElement : public IDrawable {
public:
    float width  = -1;
    float height = -1;
    Thickness margin = Thickness();

protected:
    SDL_FRect Measure(SDL_FRect* pane) const {
        return {
            pane->x + (float)margin.l,
            pane->y + (float)margin.t,
            (width  < 0 ? pane->w : width)  - (float)(margin.l + margin.r),
            (height < 0 ? pane->h : height) - (float)(margin.t + margin.b)
        };
    }
};
