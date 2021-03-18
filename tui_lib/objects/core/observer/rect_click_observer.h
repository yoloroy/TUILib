#ifndef TUILIB_RECT_CLICK_OBSERVER_H
#define TUILIB_RECT_CLICK_OBSERVER_H

#include "observer.h"
#include "../../../utils/point.h"

Observer *newRectClickObserver(Point, Point, void(*)());

#endif //TUILIB_RECT_CLICK_OBSERVER_H
