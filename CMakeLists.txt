cmake_minimum_required(VERSION 3.17)
project(TUILib C)

set(CMAKE_C_STANDARD 99)

add_executable(TUILib main.c src/view/label.c src/view/label.h)