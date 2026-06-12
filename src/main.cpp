#include "CUI.h"

class MyApp : public App {
private:
    int counter = 0;

protected:
    void Content() override {
        Button *myButton = new Button();
        myButton->text = "button";
        myButton->fontFamily = "src/assets/fonts/OpenSans-Regular.ttf";
        myButton->onClick = [this]{ counter++; };

        TextBlock *myTextBlock = new TextBlock();
        myTextBlock->textBinding = [this]{ return "Count: " + std::to_string(counter); };
        myTextBlock->fontFamily = "src/assets/fonts/OpenSans-Regular.ttf";

        myButton->textblock = myTextBlock;

        window->content = myButton;
    }
};

int main(int argc, char* argv[])
{
    MyApp *app = new MyApp();

    app->Run(1);

    delete app;
}
