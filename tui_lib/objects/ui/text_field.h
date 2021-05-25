#ifndef TUILIB_TEXT_FIELD_H
#define TUILIB_TEXT_FIELD_H

#include <stdbool.h>
#include "../core/view/view.h"
#include "../core/observer/observer.h"
#include "../../utils/point.h"

typedef struct {
    bool isFocused;
    View *textView;
    Observer *onClick, *onKey;
    char *inputString, *hint;
    short inputColorPair, hintColorPair;
} TextField;

TextField newTextField(Point position, Point size, int inputSize, char *hint, short inputColorPair, short hintColorPair);

void deleteTextField(TextField textField);

#endif//TUILIB_TEXT_FIELD_H
