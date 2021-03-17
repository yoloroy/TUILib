#include "event_type.h"

EventType getEventTypeOfCh(chtype ch) {
    switch (ch) {
        case KEY_MOUSE:
            return EClick;
        default:
            return EKey;
    }
}
