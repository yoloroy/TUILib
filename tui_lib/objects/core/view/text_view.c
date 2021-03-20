#include <string.h>
#include <stdlib.h>
#include <ncurses.h>
#include "text_view.h"

void drawText(TextModel *text);

View *newText(Point position, Point size, char *string, short colorPair) {
    TextModel *text = malloc(sizeof(TextModel));
    text->position = position;
    text->size = size;
    text->string = calloc(strlen(string), sizeof(char));
    strcpy(text->string, string);
    text->colorPair = colorPair;

    View *view = malloc(sizeof(View));
    view->id = -1;
    view->object = text;
    view->drawFunc = (void (*)(void *)) drawText;
    return NULL;
}

void drawText(TextModel *text) {
    // TODO: add '\n' checking + add line breaking between words
    int x1 = text->position.x,
            y1 = text->position.y,
            x2 = text->position.x + text->size.x,
            y2 = text->position.y + text->size.y;

    attron(COLOR_PAIR(text->colorPair));

    int length = x2 - x1;
    char string[length + 1]; string[length] = 0;
    char *textPointer = text->string;
    for (int y = y1; y < y2; ++y) {
        strncpy(string, textPointer, length);
        textPointer += length;
        mvaddstr(y, x1, string);
    }
}
