#ifndef TUILIB_BLOCK_H
#define TUILIB_BLOCK_H

#include <ncurses.h>
#include "../core/view/view.h"
#include "../../utils/point.h"

typedef struct {
    View *view;
} Block;

Block newBlock(View *view);

Block newTextBlock(Point position, Point size, char *string, short colorPair);

Block newRectBlock(Point position, Point size, chtype fillingSymbol, short colorPair);

void deleteBlock(Block block);

#endif//TUILIB_TEXT_VIEW_H
