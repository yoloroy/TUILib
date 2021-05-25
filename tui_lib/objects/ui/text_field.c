#include <stdlib.h>
#include <string.h>
#include "text_field.h"
#include "../core/view/text_view.h"
#include "../core/observer/rect_click_observer.h"

void onFocusTextField(TextField *textField);

void onTypingTextField(TextField *textField);

TextField newTextField(Point position, Point size, int inputSize, char *hint, short inputColorPair, short hintColorPair) {
    TextField result;
    result.hint = hint;
    result.inputString = calloc(inputSize, sizeof(char));
    result.textView = newText(position, size, result.hint, hintColorPair);
    result.inputColorPair = inputColorPair;
    result.onClick = newRectClickObserver(
            position,
            point(position.x + size.x, position.y + size.y),
            (void (*)(void *)) onFocusTextField,
            NULL,
            true
    );

    return result;
}

void onFocusTextField(TextField *textField) {
    textField->isFocused = !textField->isFocused;

    TextModel *textModel = (TextModel *) textField->textView->object;
    if (textField->isFocused && strlen(textField->inputString) > 0) {
        textModel->string = textField->inputString;
        textModel->colorPair = textField->inputColorPair;
        echo();
        curs_set(true);
    } else {
        textModel->string = textField->hint;
        textModel->colorPair = textField->hintColorPair;
        noecho();
        curs_set(false);
    }
}

void onTypingTextField(TextField *textField) {
    if (textField->isFocused) {
//        textField->inputString[strlen(textField->inputString)] =
    }
}
