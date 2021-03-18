#include "model.h"
#include "../../utils/dynamic_arrays.h"

int *getIdPointer(ManagerModel *model, void *element);

void initMModel(ManagerModel *model, size_t elementSize, long relativePositionOfId, void (*additionFreeing)(void *)) {
    model->elements = calloc(10, elementSize);
    model->count = 0;
    model->size = 0;
    model->lastId = 0;
    model->elementSize = elementSize;
    model->relativePositionOfId = relativePositionOfId;
    model->additionFreeing = additionFreeing;
}

int addToMModel(ManagerModel *model, void *element) {
    *getIdPointer(model, element) = model->lastId++;
    checkDynamicArrayFullness(model->elements, &model->size, model->count, model->elementSize);

    model->elements[model->count] = element;

    return model->count++;
}

void deleteFromMModel(ManagerModel *model, int id) {
    for (int index = 0; index < model->count; ++index) {
        if (*getIdPointer(model, model->elements[index]) == id) {
            model->additionFreeing(model->elements[index]);
            deleteDynamicArrayItem(model->elements, &model->count, model->elementSize, index);
        }
    }
}

void clearMModel(ManagerModel *model) {
    for (int i = 0; i < model->count; ++i) {
        deleteFromMModel(model, *getIdPointer(model, model->elements[--(model->count)]));
    }
    free(model->elements);
    model->size = 0;
}

int *getIdPointer(ManagerModel *model, void *element) {
    return (int *)(element + model->relativePositionOfId);
}
