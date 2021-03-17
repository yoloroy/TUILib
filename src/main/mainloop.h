#ifndef TUILIB_MAINLOOP_H
#define TUILIB_MAINLOOP_H

#include "management/views.h"

void (*_onFinish)();
int (*_onIteration)(double);

void init(int (*)(double), void (*)());

void start();

void finish();

void notify();

#endif //TUILIB_MAINLOOP_H
