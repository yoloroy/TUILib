#include <string.h>
#include "dynamic_arrays.h"

void checkDynamicArrayFullness(void *array, int *pcapacity, int count, size_t size) {
    if (*pcapacity > count) return;

    *pcapacity = *pcapacity * 2 + 1;
    void *newArray = calloc(*pcapacity, size);

    memcpy(newArray, array, *pcapacity * size);
}

void deleteDynamicArrayItem(void *array, int *pcount, size_t size, int index) {
    memcpy(array + index * size, array + (index + 1) * size, (--(*pcount) - index) * size);
}
