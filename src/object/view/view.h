#ifndef TUILIB_VIEW_H
#define TUILIB_VIEW_H

typedef struct {
    int id;
    void *object;
    void (*(drawFunc))(void *);
} View;

#endif //TUILIB_VIEW_H
