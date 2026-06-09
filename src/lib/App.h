#pragma once
#include "Window.h"

#include <SDL3/SDL.h>
#include <SDL3/SDL_video.h>

class App {
public:
    App();
    virtual ~App();

    Window *window;

    void Run(int debug_print_visual_tree);

protected:
    virtual void Content() {}
private:
    void debug_print_content();
};
