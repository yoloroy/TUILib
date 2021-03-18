cmake_minimum_required(VERSION 3.17)
project(checkTUILib C)

set(CMAKE_C_STANDARD 99)

SET(GCC_COVERAGE_LINK_FLAGS    "-lpanel -lncurses")

SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")

add_executable(checkTUILib main.c samples/sample1.c samples/sample1.h)

target_link_libraries(checkTUILib TUILib)
