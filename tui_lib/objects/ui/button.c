#include <string.h>
#include <stdlib.h>
#include "button.h"
#include "../../core/management/views.h"
#include "../core/observer/rect_click_observer.h"
#include "../../core/management/observers.h"
#include "../core/view/rect_view.h"
#include "../core/view/text_view.h"

Button newButton(View *view, Observer *observer) {
    addView(view);
    addObserver(observer);

    Button result = { view, observer };
    return result;
}

Button newRectButton(Point position, Point size, chtype fillingSymbol, short colorPair, void (*onClickAction)(void *), void *actionData) {
    View *view = newRect(position, size, fillingSymbol, colorPair);
    Observer *onClickObserver = newRectClickObserver(
            position,
            point(position.x + size.x, position.y + size.y),
            onClickAction,
            actionData,
            true
    );

    return newButton(view, onClickObserver);
}

Button newTextButton(Point position, Point size, char *string, short colorPair, void (*onClickAction)(void *), void *actionData) {
    char *temp = calloc(strlen(string)+1, sizeof(char));
    strcpy(temp, string);

    View *view = newText(position, size, temp, colorPair);
    Observer *onClickObserver = newRectClickObserver(
            position,
            point(position.x + size.x, position.y + size.y),
            onClickAction,
            actionData,
            true
    );

    return newButton(view, onClickObserver);
}

void deleteButton(Button button) {
    deleteView(button.view->id);
    deleteObserver(button.onClick->id);
}
