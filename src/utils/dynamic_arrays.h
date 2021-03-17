#ifndef TUILIB_DYNAMIC_ARRAYS_H
#define TUILIB_DYNAMIC_ARRAYS_H

#include <stdlib.h>

void checkDynamicArrayFullness(void *array, int *pcapacity, int count, size_t size);

void deleteDynamicArrayItem(void *array, int *pcount, size_t size, int id);

#endif //TUILIB_DYNAMIC_ARRAYS_H
