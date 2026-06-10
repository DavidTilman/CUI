cmake_minimum_required(VERSION 3.20)
project(CUI VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(SDL3 REQUIRED CONFIG)
find_package(SDL3_ttf REQUIRED CONFIG)

add_executable(CUI
    src/main.cpp
    src/lib/App.cpp
    src/lib/Window.cpp
    src/lib/Thickness.cpp
    src/lib/Rectangle.cpp
    src/lib/Border.cpp
    src/lib/TextBlock.cpp
    src/lib/UniformGrid.cpp
)

target_include_directories(CUI PRIVATE src/lib)

target_link_libraries(CUI PRIVATE SDL3::SDL3 SDL3_ttf::SDL3_ttf)
