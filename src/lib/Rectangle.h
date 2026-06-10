#pragma once
#include "UIElement.h"
#include "Color.h"

#include <SDL3/SDL.h>

class Rectangle : public UIElement {
public:
    void Draw(SDL_Renderer* renderer, SDL_FRect* pane) override;
    void debug_print_content(const std::string& prefix, bool is_last) override;

    Color fill = Colors::Black;
};
