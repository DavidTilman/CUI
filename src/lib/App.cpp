#include "App.h"

#include <SDL3/SDL.h>
#include <SDL3/SDL_events.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <cstdio>

App::App() {
    TTF_Init();
    window = new Window();
}

void App::Run(int debug_print_visual_tree) {
    Content();

    if (debug_print_visual_tree) debug_print_content();

    window->Initialize();

    bool running = true;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT)
                running = false;
        }

        window->Present();
    }
}

void App::debug_print_content() {
    printf("App @ %p\n", this);
}

App::~App() {
    delete window;
    TTF_Quit();
    SDL_Quit();
}
