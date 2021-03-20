#ifndef TUILIB_BUTTON_H
#define TUILIB_BUTTON_H

#include "../core/view/view.h"
#include "../core/observer/observer.h"
#include "../../utils/point.h"

typedef struct {
    View *view;
    Observer *onClick;
} Button;

Button newButton(View *view, Observer *observer);

Button newRectButton(Point position, Point size, chtype fillingSymbol, short colorPair, void (*onClickAction)());

Button newTextButton(Point position, Point size, char *string, short colorPair, void (*onClickAction)());

void deleteButton(Button button);

#endif //TUILIB_BUTTON_H
