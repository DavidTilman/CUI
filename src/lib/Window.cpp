#include "Window.h"
#include <SDL3/SDL_rect.h>
#include <cstdio>

Window::Window() {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("SDL_Init failed: %s", SDL_GetError());
        SDL_Quit();
    }
}

void Window::Initialize() {
    window = SDL_CreateWindow("CUI", size.x, size.y, 0);
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
             size.x - (float)(padding.l + padding.r),
             size.y - (float)(padding.t + padding.b) };
}

void Window::Present() {
    SDL_SetRenderDrawColor(renderer, background.R, background.G, background.B, background.A);
    SDL_RenderClear(renderer);

    if (content) content->Draw(renderer, &pane);

    SDL_RenderPresent(renderer);
}

void Window::debug_print_content(int depth) {
    for (int i = 0; i < depth; i++) {
        printf("|   ");
    }

    printf("Window @ %p (\n", this);

    if (content) content->debug_print_content(depth + 1);

    for (int i = 0; i < depth; i++) {
        printf("|   ");
    }
    printf(")\n");
}

Window::~Window() {
    delete content;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}
