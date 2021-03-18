cmake_minimum_required(VERSION 3.17)
project(TUILib C)

set(CMAKE_C_STANDARD 99)

SET(GCC_COVERAGE_LINK_FLAGS    "-lpanel -lncurses")

SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")

add_library(TUILib object/view/rect_view.c object/view/rect_view.h utils/point.c utils/point.h object/view/view.h main/mainloop.c main/mainloop.h main/management/views.c main/management/views.h utils/dynamic_arrays.c utils/dynamic_arrays.h utils/colors.c utils/colors.h object/observer/observer.h object/observer/rect_click_observer.c object/observer/rect_click_observer.h main/management/observers.c main/management/observers.h object/observer/event_type.h object/observer/event_type.c main/management/model.c main/management/model.h)
