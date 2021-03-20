#ifndef TUILIB_TEXT_VIEW_H
#define TUILIB_TEXT_VIEW_H

#include "../../../utils/point.h"
#include "view.h"

typedef struct {
    Point position;
    Point size;
    char *string;
    short colorPair;
} TextModel;

View *newText(Point, Point, char *, short);

#endif // TUILIB_TEXT_VIEW_H
