#pragma once
#include "Color.h"
#include "Size.h"
#include "Thickness.h"
#include "IDrawable.h"

#include <SDL3/SDL.h>

class Window{
public:
    Window();
    void Initialize();
    ~Window();

    Size size = Size{ 1200, 700 };
    Color background = Colors::Black;
    Thickness padding = Thickness();
    IDrawable* content = nullptr;

    void Present();
    SDL_Window* GetSDLWindow() { return window; }
private:
    SDL_Window*   window;
    SDL_Renderer* renderer;
    SDL_FRect pane;
};
