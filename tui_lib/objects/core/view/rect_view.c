#include <stdlib.h>
#include "rect_view.h"

void drawRect(RectModel *rect);

View *newRect(Point position, Point size, chtype fillingSymbol, short colorPair) {
    RectModel *rectView = malloc(sizeof(RectModel));
    rectView->position = position;
    rectView->size = size;
    rectView->symbol = fillingSymbol;
    rectView->colorPair = colorPair;

    View *view = malloc(sizeof(View));
    view->isVisible = true;
    view->id = -1;
    view->object = rectView;
    view->drawFunc = (void (*)(void *)) drawRect;

    return view;
}

void drawRect(RectModel *rect) {
    int x1 = rect->position.x,
        y1 = rect->position.y,
        x2 = rect->position.x + rect->size.x,
        y2 = rect->position.y + rect->size.y;

    attron(COLOR_PAIR(rect->colorPair));

    for (int y = y1; y < y2; ++y) {
        mvhline(y, x1, rect->symbol, x2 - x1);
    }
}
