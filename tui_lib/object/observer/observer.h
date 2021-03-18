#ifndef TUILIB_OBSERVER_H
#define TUILIB_OBSERVER_H

#include <stdbool.h>
#include "event_type.h"

typedef struct {
    EventType eventToObserve;
    bool (*condition)(void *, chtype);
    void *args;
} ConditionAndData;

typedef struct {
    int id;
    ConditionAndData conditionAndData;
    void (*action)();
} Observer;

#endif //TUILIB_OBSERVER_H
