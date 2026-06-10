#include "App.h"
#include "Rectangle.h"
#include "Size.h"
#include "TextBlock.h"
#include "Border.h"

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include "Thickness.h"
#include "UniformGrid.h"

class MyApp : public App {
protected:
    void Content() override {
        UniformGrid *grid = new UniformGrid();
        grid->columns = 2;
        grid->rows = 2;

        Rectangle *red = new Rectangle();
        Rectangle *green = new Rectangle();
        Rectangle *blue = new Rectangle();
        Rectangle *yellow = new Rectangle();

        red->fill = Colors::Red;
        green->fill = Colors::Green;
        blue->fill = Colors::Blue;
        yellow->fill = Colors::Yellow;

        grid->AddChild(red, 0, 0);
        grid->AddChild(yellow, 1, 0);
        grid->AddChild(green, 0, 1);
        grid->AddChild(blue, 1, 1);

        Border *border = new Border();
        border->padding = Thickness(10);

        border->content = grid;
        window->content = border;
    }
};

int main(int argc, char* argv[])
{
    MyApp *app = new MyApp();

    app->Run(1);

    delete app;
}
