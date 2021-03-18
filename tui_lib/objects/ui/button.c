#include "button.h"
#include "../../core/management/views.h"
#include "../core/observer/rect_click_observer.h"
#include "../../core/management/observers.h"

Button newRectButton(Point position, Point size, chtype ch, short colorPair, void (*onClickAction)()) {
    View *view = newRect(position, size, ch, colorPair);
    addView(view);

    Observer *onClickObserver = newRectClickObserver(
            position,
            point(position.x + size.x, position.y + size.y),
            onClickAction
    );
    addObserver(onClickObserver);

    Button result = { view, onClickObserver };
    return result;
}

void deleteButton(Button button) {
    deleteView(button.view->id);
    deleteObserver(button.onClick->id);
}
