cmake_minimum_required(VERSION 3.17)
project(TUILib C)

set(CMAKE_C_STANDARD 99)

SET(GCC_COVERAGE_LINK_FLAGS    "-lpanel -lncurses")

SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")

add_library(TUILib STATIC object/view/rect_view.c object/view/rect_view.h utils/point.c utils/point.h object/view/view.h core/mainloop.c core/mainloop.h core/management/views.c core/management/views.h utils/dynamic_arrays.c utils/dynamic_arrays.h utils/colors.c utils/colors.h object/observer/observer.h object/observer/rect_click_observer.c object/observer/rect_click_observer.h core/management/observers.c core/management/observers.h object/observer/event_type.h object/observer/event_type.c core/management/model.c core/management/model.h)
