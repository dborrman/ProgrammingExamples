cmake_minimum_required(VERSION 3.1.0)
project(DrawingApp)

find_package(Qt5Widgets REQUIRED)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(DrawingApp
    src/main.cpp
    src/canvas.cpp
    src/window.cpp
    src/point.cpp
    src/rectangle.cpp
)

target_include_directories(DrawingApp PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(DrawingApp Qt5::Widgets)
