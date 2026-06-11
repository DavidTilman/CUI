#pragma once
#include "UIElement.h"
#include "Color.h"
#include "Thickness.h"

#include <SDL3/SDL.h>

class TextBlock : public UIElement {
public:
    void Draw(SDL_Renderer* renderer, SDL_FRect* pane) override;
    void debug_print_content(const std::string& prefix, bool is_last) override;
    const char* text = nullptr;
    Color background = Colors::Black;
    Color foreground = Colors::White;
    float fontSize = 12;
    const char * fontFamily = nullptr;
    Thickness padding = Thickness();
};
