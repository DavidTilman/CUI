#include "Window.h"
#include <SDL3/SDL_rect.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <cstdio>
#include <string>

Window::Window() {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("SDL_Init failed: %s", SDL_GetError());
        SDL_Quit();
    }

    if (!TTF_Init()) {

    }

    width = 1200;
    height = 800;
}

void Window::Initialize() {
    window = SDL_CreateWindow("CUI", width, height, 0);
    if (!window) {
        SDL_Log("SDL_CreateWindow failed: %s", SDL_GetError());
        SDL_Quit();
    }

    renderer = SDL_CreateRenderer(window, nullptr);
    if (!renderer) {
        SDL_Log("SDL_CreateRenderer failed: %s", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    pane = { (float)padding.l, (float)padding.t,
             width - (float)(padding.l + padding.r),
             height - (float)(padding.t + padding.b) };
}

void Window::Present() {
    SDL_SetRenderDrawColor(renderer, background.R, background.G, background.B, background.A);
    SDL_RenderClear(renderer);

    if (content) content->Draw(renderer, &pane);

    SDL_RenderPresent(renderer);
}

void Window::debug_print_content(const std::string& prefix, bool is_last) {
    const char* conn = is_last ? "└── " : "├── ";
    std::string cpfx = prefix + (is_last ? "    " : "│   ");
    std::string ppfx = cpfx + "│  ";
    printf("%s%sWindow @ %p\n", prefix.c_str(), conn, this);
    printf("%s%-12s = %f\n",            ppfx.c_str(), "width", width);
    printf("%s%-12s = %f\n",            ppfx.c_str(), "height", height);
    printf("%s%-12s = #%02X%02X%02X%02X\n",  ppfx.c_str(), "background", background.R, background.G, background.B, background.A);
    printf("%s%-12s = l=%u r=%u t=%u b=%u\n", ppfx.c_str(), "padding",   padding.l, padding.r, padding.t, padding.b);
    if (content) content->debug_print_content(cpfx, true);
}

Window::~Window() {
    delete content;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();
    TTF_Quit();
}
