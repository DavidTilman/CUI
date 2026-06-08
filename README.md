# CUI

A lightweight C++ UI framework built on top of SDL3, inspired by XAML/WPF-style declarative layouts.

## Overview

CUI provides a simple component model for building windowed applications. Elements are composed in a tree — a `Window` holds a content element, containers like `Border` hold child elements, and leaf elements like `Rectangle` render shapes. Layout is handled via `Thickness` padding and flexible sizing that fills available space by default.

## Components

| Class | Description |
|-------|-------------|
| `App` | Base class for your application. Override `Content()` to build the UI tree. |
| `Window` | Root container. Sets background color, size, and padding. |
| `Border` | Container with background fill, configurable stroke, corner radius, and padding. Holds one child `content`. |
| `Rectangle` | Filled rectangle leaf element. |
| `UIElement` | Base class for all elements. Supports explicit `width`/`height` or auto-fill. |
| `Colors` | Static color constants (Red, Blue, DarkGray, SkyBlue, etc.). |
| `Thickness` | Padding/margin helper (uniform or per-side). |
| `Size` | Width/height value pair. |

## Requirements

- CMake 3.20+
- C++20 compiler
- [SDL3](https://wiki.libsdl.org/SDL3/FrontPage)

## Build & Run

```bash
./run.sh
```

Or manually:

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
./build/CUI
```

## Example

```cpp
#include "App.h"
#include "Rectangle.h"
#include "Border.h"

class MyApp : public App {
protected:
    void Content() override {
        window->background = Colors::DarkGray;
        window->size = Size{1200, 700};
        window->padding = Thickness(10);

        Border* border = new Border();
        border->strokeWeight = 4;
        border->padding = Thickness(10, 5, 10, 30);

        Rectangle* rect = new Rectangle();
        rect->fill = Colors::Blue;

        border->content = rect;
        window->content = border;
    }
};

int main(int argc, char* argv[]) {
    MyApp* app = new MyApp();
    app->Run();
    delete app;
}
```
