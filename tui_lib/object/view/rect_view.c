#include <stdlib.h>
#include "rect_view.h"

View newRect(Point position, Point size, chtype symbol, short colorPair) {
    RectView *rectView = malloc(sizeof(RectView));
    rectView->position = position;
    rectView->size = size;
    rectView->symbol = symbol;
    rectView->colorPair = colorPair;

    View view = {0, rectView, (void (*)(void *)) drawRect};

    return view;
}

void drawRect(RectView *rect) {
    int x1 = rect->position.x,
        y1 = rect->position.y,
        x2 = rect->position.x + rect->size.x,
        y2 = rect->position.y + rect->size.y;

    attron(COLOR_PAIR(rect->colorPair));

    for (int y = y1; y < y2; ++y) {
        mvhline(y, x1, rect->symbol, x2 - x1);
    }
}
