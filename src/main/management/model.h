#ifndef TUILIB_MODEL_H
#define TUILIB_MODEL_H

#include <stdlib.h>

typedef struct {
    void **elements;
    int count,
        size,
        lastId;
    size_t elementSize;
    long relativePositionOfId;
    void (*additionFreeing)(void *);
} ManagerModel;

void initMModel(ManagerModel *model, size_t elementSize, long relativePositionOfId, void (*additionFreeing)(void *));

int addToMModel(ManagerModel *model, void *);

void deleteFromMModel(ManagerModel *model, int id);

void clearMModel(ManagerModel *model);

#endif //TUILIB_MODEL_H
