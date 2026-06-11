#include "CUI.h"

class MyApp : public App {
protected:
    void Content() override {
        Button *myButton = new Button();
        myButton->text = "button";
        myButton->fontFamily = "src/assets/fonts/OpenSans-Regular.ttf";

        myButton->onClick = []{ printf("holy click batman!\n"); };

        window->padding = Thickness(100);
        window->content = myButton;
    }
};

int main(int argc, char* argv[])
{
    MyApp *app = new MyApp();

    app->Run(1);

    delete app;
}
