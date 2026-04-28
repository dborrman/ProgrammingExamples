cmake_minimum_required(VERSION 3.1.0)
project(DrawingApp)

find_package(Qt5Widgets REQUIRED)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(DrawingApp main.cpp canvas.cpp window.cpp point.cpp rectangle.cpp)

target_link_libraries(DrawingApp Qt5::Widgets)
