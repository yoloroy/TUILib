#include <ncurses.h>
#include "colors.h"

short registeredColorsCount = 0;

short getColorId(short foreground, short background) {
    init_pair(++registeredColorsCount, foreground, background);
    return registeredColorsCount;
}
