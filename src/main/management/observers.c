#include "observers.h"
#include "../../object/view/view.h"
#include "../../utils/dynamic_arrays.h"
#include <stdlib.h>
// TODO: add parent "class" for observers manager and views manager
// Observers Manager Model
struct {
    Observer **observers;
    int observersCount;
    int observersSize;
    int lastId;
} OMModel = { 0, 0, 0, 0 };

void initObservers() {
    OMModel.observers = calloc(10, sizeof(View *));
    OMModel.observersCount = 0;
    OMModel.observersSize = 10;
}

void checkObservers(chtype ch, EventType eventType) {
    for (int i = 0; i < OMModel.observersCount; ++i) {
        if (eventType == OMModel.observers[i]->conditionAndData.eventToObserve &&
                OMModel.observers[i]->conditionAndData.condition(OMModel.observers[i]->conditionAndData.args, ch)
        ) {
            OMModel.observers[i]->action();
        }
    }
}

int addObserver(Observer *observer) {
    observer->id = OMModel.lastId++;
    checkDynamicArrayFullness(OMModel.observers, &OMModel.observersSize, OMModel.observersCount, sizeof(View *));

    OMModel.observers[OMModel.observersCount] = observer;

    return OMModel.observersCount++;
}

void deleteObserver(int id) {
    for (int index = 0; index < OMModel.observersCount; ++index) {
        if (OMModel.observers[index]->id == id) {
            free(OMModel.observers[index]->conditionAndData.args);
            deleteDynamicArrayItem(OMModel.observers, &OMModel.observersCount, sizeof(View *), index);
        }
    }
}

void clearObservers() {
    for (int i = 0; i < OMModel.observersCount; ++i) {
        deleteObserver(OMModel.observers[--OMModel.observersCount]->id);
    }
    free(OMModel.observers);
    OMModel.observersSize = 0;
}
