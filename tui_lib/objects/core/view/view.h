#ifndef TUILIB_VIEW_H
#define TUILIB_VIEW_H

#include <stdbool.h>

typedef struct {
    int id;
    bool isVisible;
    void *object;
    void (*(drawFunc))(void *);
} View;

#endif //TUILIB_VIEW_H
