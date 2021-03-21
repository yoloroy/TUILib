#include "views.h"
#include "model.h"
#include <stdlib.h>

View *getViewByIndex(int);

void additionViewFreeing(View *view);

ManagerModel ViewsManagerModel;

void initViews() {
    View tempView;
    initMModel(
            &ViewsManagerModel,
            sizeof(View *),
            ((long)&tempView.id - (long)&tempView),
            (void (*)(void *)) additionViewFreeing
    );
}

void updateViews() {
    for (int i = 0; i < ViewsManagerModel.count; ++i) {
        if (getViewByIndex(i)->isVisible)
            getViewByIndex(i)->drawFunc(getViewByIndex(i)->object);
    }
}

int addView(View *view) {
    return addToMModel(&ViewsManagerModel, view);
}

void deleteView(int id) {
    deleteFromMModel(&ViewsManagerModel, id);
}

void clearViews() {
    clearMModel(&ViewsManagerModel);
}

View *getViewByIndex(int index) {
    return ViewsManagerModel.elements[index];
}

void additionViewFreeing(View *view) {
    free(view->object);
}
