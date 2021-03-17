#include "views.h"
#include "../../utils/dynamic_arrays.h"
#include <stdlib.h>
// TODO: add parent "class" for observers manager and views manager
// Views Manager Model
struct {
    View **views;
    int viewsCount;
    int viewsSize;
    int lastId;
} VMModel = {0, 0, 0, 0 };

void initViews() {
    VMModel.views = calloc(10, sizeof(View *));
    VMModel.viewsCount = 0;
    VMModel.viewsSize = 10;
}

void updateViews() {
    for (int i = 0; i < VMModel.viewsCount; ++i) {
        VMModel.views[i]->drawFunc(VMModel.views[i]->object);
    }
}

int addView(View *view) {
    view->id = VMModel.lastId++;
    checkDynamicArrayFullness(VMModel.views, &VMModel.viewsSize, VMModel.viewsCount, sizeof(View *));

    VMModel.views[VMModel.viewsCount] = view;

    return VMModel.viewsCount++;
}

void deleteView(int id) {
    for (int index = 0; index < VMModel.viewsCount; ++index) {
        if (VMModel.views[index]->id == id) {
            free(VMModel.views[index]->object);
            deleteDynamicArrayItem(VMModel.views, &VMModel.viewsCount, sizeof(View *), index);
        }
    }
}

void clearViews() {
    for (int i = 0; i < VMModel.viewsCount; ++i) {
        deleteView(VMModel.views[--VMModel.viewsCount]->id);
    }
    free(VMModel.views);
    VMModel.viewsSize = 0;
}
