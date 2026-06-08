#include "App.h"
#include "Size.h"
#include "Rectangle.h"
#include "Border.h"

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
class MyApp : public App {
protected:
    void Content() override {
        window->background = Colors::DarkGray;
        window->size = Size {1200,700};
        window->padding = Thickness(10);

        Border *myborder = new Border();
        myborder->strokeWeight = 4;
        myborder->padding = Thickness(10,5,10,30);

        Rectangle *myRectangle = new Rectangle();
        myRectangle->fill = Colors::Blue;

        myborder->content = myRectangle;

        window->content = myborder;
    }
};

int main(int argc, char* argv[])
{
    MyApp *app = new MyApp();

    app->Run();

    delete app;
}
