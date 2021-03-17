cmake_minimum_required(VERSION 3.17)
project(TUILib C)

set(CMAKE_C_STANDARD 99)

SET(GCC_COVERAGE_LINK_FLAGS    "-lpanel -lncurses")

SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")

add_executable(TUILib main.c src/object/view/rect_view.c src/object/view/rect_view.h src/utils/point.c src/utils/point.h src/object/view/view.h src/main/mainloop.c src/main/mainloop.h src/main/management/views.c src/main/management/views.h src/utils/dynamic_arrays.c src/utils/dynamic_arrays.h src/main/management/colors.c src/main/management/colors.h src/object/observer/observer.h src/object/observer/rect_click_observer.c src/object/observer/rect_click_observer.h src/main/management/observers.c src/main/management/observers.h src/object/observer/event_type.h src/object/observer/event_type.c src/sample1.c src/sample1.h)
