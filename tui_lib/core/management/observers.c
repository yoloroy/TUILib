#include "observers.h"
#include "model.h"
#include <stdlib.h>

Observer *getObserverByIndex(int);

void additionObserverFreeing(Observer *view);

ManagerModel ObserverManagerModel;

void initObservers() {
    View tempView;
    initMModel(
            &ObserverManagerModel,
            sizeof(View *),
            ((long)&tempView.id - (long)&tempView),
            (void (*)(void *)) additionObserverFreeing
    );
}

void checkObservers(chtype ch, EventType eventType) {
    for (int i = 0; i < ObserverManagerModel.count; ++i) {
        if (eventType == getObserverByIndex(i)->conditionAndData.eventToObserve &&
                getObserverByIndex(i)->conditionAndData.condition(getObserverByIndex(i)->conditionAndData.args, ch)
        ) {
            getObserverByIndex(i)->action(getObserverByIndex(i)->actionData);
            break;
        }
    }
}

int addObserver(Observer *observer) {
    return addToMModel(&ObserverManagerModel, observer);
}

void deleteObserver(int id) {
    deleteFromMModel(&ObserverManagerModel, id);
}

void clearObservers() {
    clearMModel(&ObserverManagerModel);
}

Observer *getObserverByIndex(int index) {
    return ObserverManagerModel.elements[index];
}

void additionObserverFreeing(Observer *view) {
    free(view->conditionAndData.args);
}
