#ifndef TUILIB_MULTYOBJECT_H
#define TUILIB_MULTYOBJECT_H

#include "../core/view/view.h"
#include "../core/observer/observer.h"

typedef struct {
    View **views;
    int viewsCount;
    Observer **observers;
    int observersCount;
} MultiObject;

MultiObject newMultiObject(View **views, int viewsCount, Observer **observers, int observersCount);

void deleteMultiObject(MultiObject multiObject);

#endif//TUILIB_MULTYOBJECT_H
