cmake_minimum_required(VERSION 3.17)
project(TUILib C)

set(CMAKE_C_STANDARD 99)

SET(GCC_COVERAGE_LINK_FLAGS    "-lpanel -lncurses")

SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")

add_library(TUILib STATIC objects/core/view/rect_view.c objects/core/view/rect_view.h utils/point.c utils/point.h objects/core/view/view.h core/mainloop.c core/mainloop.h core/management/views.c core/management/views.h utils/dynamic_arrays.c utils/dynamic_arrays.h utils/colors.c utils/colors.h objects/core/observer/observer.h objects/core/observer/rect_click_observer.c objects/core/observer/rect_click_observer.h core/management/observers.c core/management/observers.h objects/core/observer/event_type.h objects/core/observer/event_type.c core/management/model.c core/management/model.h objects/ui/button.c objects/ui/button.h objects/core/view/text_view.c objects/core/view/text_view.h objects/ui/block.c objects/ui/block.h objects/ui/multi_object.c objects/ui/multi_object.h objects/ui/text_field.c objects/ui/text_field.h objects/core/observer/key_click_observer.c objects/core/observer/key_click_observer.h)
