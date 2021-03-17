#ifndef TUILIB_EVENT_TYPE_H
#define TUILIB_EVENT_TYPE_H

#include <ncurses.h>

typedef enum {
    EClick,
    EKey // TODO: add press and release
} EventType;

EventType getEventTypeOfCh(chtype ch);

#endif //TUILIB_EVENT_TYPE_H
