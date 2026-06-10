#pragma once
#include "UIElement.h"
#include "Color.h"

#include <SDL3/SDL.h>

class TextBlock : public UIElement {
public:
    void Draw(SDL_Renderer* renderer, SDL_FRect* pane) override;
    void debug_print_content(int depth) override;
    const char* text = nullptr;
    Color background = Colors::Black;
    Color foreground = Colors::White;
    float fontSize = 12;
    const char * fontFamily = nullptr;
};
