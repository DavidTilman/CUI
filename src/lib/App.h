#pragma once
#include "Window.h"

#include <SDL3/SDL.h>
#include <SDL3/SDL_video.h>

class App {
public:
    App();
    virtual ~App();

    Window *window;

    void Run();

protected:
    virtual void Content() {}
};
