#include "CUI.h"

class MyApp : public App {
protected:
    void Content() override {

        UniformGrid *grid = new UniformGrid();
        grid->columns = 2;
        grid->rows = 2;

        Rectangle *red2 = new Rectangle();
        Rectangle *green2 = new Rectangle();
        Rectangle *blue2 = new Rectangle();
        Rectangle *yellow2 = new Rectangle();

        Rectangle *red = new Rectangle();
        Rectangle *green = new Rectangle();
        Rectangle *blue = new Rectangle();

        red->fill = Colors::Red;
        green->fill = Colors::Green;
        blue->fill = Colors::Blue;

        red2->fill = Colors::Red;
        green2->fill = Colors::Green;
        blue2->fill = Colors::Blue;
        yellow2->fill = Colors::Yellow;

        UniformGrid *grid2 = new UniformGrid();
        grid2->columns = 4;
        grid2->rows = 1;

        grid2->AddChild(red2, 0, 0);
        grid2->AddChild(yellow2, 1, 0);
        grid2->AddChild(green2, 2, 0);
        grid2->AddChild(blue2, 3, 0);

        grid->AddChild(red, 0, 0);
        grid->AddChild(grid2, 1, 0);
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
