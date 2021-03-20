#include "multi_object.h"
#include "../../core/management/views.h"
#include "../../core/management/observers.h"

MultiObject newMultiObject(View **views, int viewsCount, Observer **observers, int observersCount) {
    for (int i = 0; i < viewsCount; ++i) {
        addView(views[i]);
    }

    for (int i = 0; i < observersCount; ++i) {
        addObserver(observers[i]);
    }

    MultiObject result = { views, viewsCount, observers, observersCount };
    return result;
}

void deleteMultiObject(MultiObject multiObject) {
    for (int i = 0; i < multiObject.viewsCount; ++i) {
        deleteView(multiObject.views[i]->id);
    }

    for (int i = 0; i < multiObject.observersCount; ++i) {
        deleteObserver(multiObject.observers[i]->id);
    }
}
