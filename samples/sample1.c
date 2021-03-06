#include <stdbool.h>
#include "../tui_lib/utils/colors.h"
#include "../tui_lib/objects/ui/button.h"
#include "../tui_lib/core/mainloop.h"
#include "../tui_lib/objects/core/view/rect_view.h"
#include "../tui_lib/objects/ui/block.h"

int onIteration(double _);

void onFinish();

void buttonOnClick();

Button button;
char changingChars[] = { '<', '>' };
bool isContinue = true;

int sample1() {
    init(onIteration, onFinish);

    button = newRectButton(
            point(2, 2),
            point(5, 3),
            changingChars[0],
            getColorId(COLOR_RED, COLOR_WHITE),
            buttonOnClick,
            &button);

    newTextBlock(
            point(4, 4),
            point(6, 3),
            "123456789101112131415",
            getColorId(COLOR_WHITE, COLOR_CYAN));

    notify();
    start();

    return 0;
}

int onIteration(double _) {
    RectModel *rectModel = ((RectModel *) button.view->object);
    rectModel->symbol = rectModel->symbol == changingChars[0] ? changingChars[1] : changingChars[0];

    notify();

    return isContinue;
}

void onFinish() {

}

void buttonOnClick(Button *iAmHasClicked) {
    if (changingChars[0] == '<') {
        changingChars[0] = '^';
        changingChars[1] = 'v';
    } else {
        deleteButton(*iAmHasClicked);
    }
}
