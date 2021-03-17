#ifndef TUILIB_LABEL_H
#define TUILIB_LABEL_H

#include <ncurses.h>
#include "../../utils/point.h"
#include "view.h"

typedef struct {
    Point position;
    Point size;
    chtype symbol;
    short colorPair;
} RectView;

View newRect(Point, Point, chtype, short);

void drawRect(RectView *rect);

#endif //TUILIB_LABEL_H
