#include <stdlib.h>
#include "key_click_observer.h"

bool isAnyTextChar(void *_, chtype ch);

Observer *newAnyTextCharTypeObserver(void (*onKey)(void *), void *actionData) {
    ConditionAndData conditionAndData = {
            EKey,
            (bool (*)(void *, chtype)) isAnyTextChar,
            NULL
    };

    Observer *result = malloc(sizeof(Observer));
    result->id = -1;
    result->conditionAndData = conditionAndData;
    result->action = onKey;
    result->actionData = actionData;

    return result;
}

bool isAnyTextChar(void *_, chtype ch) {
    return true; // TODO: clicks and other non-chars ignoring
}
