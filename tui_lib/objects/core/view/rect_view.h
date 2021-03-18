#ifndef TUILIB_LABEL_H
#define TUILIB_LABEL_H

#include <ncurses.h>
#include "../../../utils/point.h"
#include "view.h"

typedef struct {
    Point position;
    Point size;
    chtype symbol;
    short colorPair;
} RectModel;

View *newRect(Point, Point, chtype, short);

#endif //TUILIB_LABEL_H
