#ifndef TUILIB_BUTTON_H
#define TUILIB_BUTTON_H

#include "../core/view/view.h"
#include "../core/observer/observer.h"
#include "../core/view/rect_view.h"

typedef struct {
    View *view;
    Observer *onClick;
} Button;

Button newRectButton(Point position, Point size, chtype ch, short colorPair, void (*onClickAction)());

void deleteButton(Button button);

#endif //TUILIB_BUTTON_H
