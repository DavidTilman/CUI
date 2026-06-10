#pragma once
#include "UIElement.h"
#include "Color.h"
#include "Thickness.h"

#include <SDL3/SDL.h>

class Border : public UIElement {
public:
    void Draw(SDL_Renderer* renderer, SDL_FRect* pane) override;
    void debug_print_content(const std::string& prefix, bool is_last) override;

    Color background = Colors::Black;
    Color stroke = Colors::White;
    uint32_t strokeWeight = 1;
    Thickness padding = Thickness();
    IDrawable* content = nullptr;
};
