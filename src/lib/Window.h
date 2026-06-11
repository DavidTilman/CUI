#pragma once
#include "Color.h"
#include "Thickness.h"
#include "IDrawable.h"
#include "UIElement.h"

#include <SDL3/SDL.h>

class Window : public UIElement {
public:
    Window();
    void Initialize();
    ~Window();

    Color background = Colors::Black;
    Thickness padding = Thickness();
    IDrawable* content = nullptr;

    void Draw(SDL_Renderer* renderer, SDL_FRect* pane) override { Present(); }
    void Present();
    SDL_Window* GetSDLWindow() { return window; }
    void debug_print_content(const std::string& prefix, bool is_last) override;
private:
    SDL_Window*   window;
    SDL_Renderer* renderer;
    SDL_FRect pane;
};
