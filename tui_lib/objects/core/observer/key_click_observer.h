#ifndef CHECKTUILIB_KEY_CLICK_OBSERVER_H
#define CHECKTUILIB_KEY_CLICK_OBSERVER_H

#include "observer.h"

Observer *newAnyKeyClickObserver(void(*)(void *), void *);

#endif //CHECKTUILIB_KEY_CLICK_OBSERVER_H
