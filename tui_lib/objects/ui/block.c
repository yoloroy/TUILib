#include <string.h>
#include <stdlib.h>
#include "../../core/management/views.h"
#include "../core/view/rect_view.h"
#include "../core/view/text_view.h"
#include "block.h"

Block newBlock(View *view) {
    addView(view);

    Block result = { view };
    return result;
}

Block newTextBlock(Point position, Point size, char *string, short colorPair) {
    char *temp = calloc(strlen(string)+1, sizeof(char));
    strcpy(temp, string);

    View *view = newText(position, size, temp, colorPair);

    return newBlock(view);
}

Block newRectBlock(Point position, Point size, chtype fillingSymbol, short colorPair) {
    View *view = newRect(position, size, fillingSymbol, colorPair);

    return newBlock(view);
}

void deleteBlock(Block block) {
    deleteView(block.view->id);
}
