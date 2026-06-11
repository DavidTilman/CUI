#include "App.h"

#include <SDL3/SDL.h>
#include <SDL3/SDL_events.h>
#include <cstdio>

App::App() {
    window = new Window();
}

void App::Run(int debug_print_visual_tree) {
    Content();
    window->Initialize();

    if (debug_print_visual_tree) debug_print_content();


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
    window->debug_print_content("", true);
}


App::~App() {
    delete window;
}
