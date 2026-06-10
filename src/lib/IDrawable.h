#pragma once
#include <SDL3/SDL.h>
#include <string>

class IDrawable {
public:
    virtual void Draw(SDL_Renderer* renderer, SDL_FRect *pane) = 0;
    virtual ~IDrawable() = default;
    virtual void debug_print_content(const std::string& prefix, bool is_last) {}
};
