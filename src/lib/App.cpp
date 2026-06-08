#include "App.h"

#include <SDL3/SDL.h>
#include <SDL3/SDL_events.h>

App::App() {
    window = new Window();
}

void App::Run() {
    Content();
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

App::~App() {
    delete window;
    SDL_Quit();
}
