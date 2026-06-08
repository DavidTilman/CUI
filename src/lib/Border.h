#pragma once
#include "UIElement.h"
#include "Color.h"
#include "Thickness.h"

#include <SDL3/SDL.h>

class Border : public UIElement {
public:
    void Draw(SDL_Renderer* renderer, SDL_FRect* pane) override;

    Color background = Colors::Black;
    Color stroke = Colors::White;
    uint32_t strokeWeight = 1;
    uint32_t cornerRadius = 0;
    Thickness padding = Thickness();
    IDrawable* content = nullptr;
};
