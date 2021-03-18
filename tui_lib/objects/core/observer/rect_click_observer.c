#include "rect_click_observer.h"
#include <stdlib.h>

bool isClickedIn(Point *data, chtype _);

Observer *newRectClickObserver(Point start, Point end, void (*onClick)()) {
    Point *data = malloc(sizeof(Point) * 2);
    data[0] = start; data[1] = end;

    ConditionAndData conditionAndData = {
            EClick,
            (bool (*)(void *, chtype)) isClickedIn,
            data
    };

    Observer *result = malloc(sizeof(Observer));
    result->id = -1;
    result->conditionAndData = conditionAndData;
    result->action = onClick;

    return result;
}

bool isClickedIn(Point *startEnd, chtype _) {
    MEVENT event;
    getmouse(&event);
    return (event.y <= startEnd[1].y) && (event.y >= startEnd[0].y) &&
           (event.x <= startEnd[1].x) && (event.x >= startEnd[0].x);
}
