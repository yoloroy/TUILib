#include "rect_click_observer.h"
#include <stdlib.h>

bool isClickedInside(Point *startEnd, chtype _);

bool isClickedOutside(Point *startEnd, chtype _);

Observer *newRectClickObserver(Point start, Point end, void (*onClick)(void *), void *actionData, bool isInside) {
    Point *data = malloc(sizeof(Point) * 2);
    data[0] = start; data[1] = end;

    ConditionAndData conditionAndData = {
            EClick,
            (bool (*)(void *, chtype)) (isInside ? isClickedInside : isClickedOutside),
            data
    };

    Observer *result = malloc(sizeof(Observer));
    result->id = -1;
    result->conditionAndData = conditionAndData;
    result->action = onClick;
    result->actionData = actionData;

    return result;
}

bool isClickedInside(Point *startEnd, chtype _) {
    MEVENT event;
    getmouse(&event);
    return (event.y <= startEnd[1].y) && (event.y >= startEnd[0].y) &&
           (event.x <= startEnd[1].x) && (event.x >= startEnd[0].x);
}

bool isClickedOutside(Point *startEnd, chtype _) {
    return !isClickedInside(startEnd, _);
}
