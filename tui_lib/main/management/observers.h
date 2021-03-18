#ifndef TUILIB_OBSERVERS_H
#define TUILIB_OBSERVERS_H

#include <ncurses.h>
#include "../../object/observer/observer.h"

void initObservers();

void checkObservers(chtype ch, EventType eventType);

int addObserver(Observer *);

void deleteObserver(int id);

void clearObservers();

#endif //TUILIB_OBSERVERS_H
