#include "object/view/rect_view.h"
#include "main/mainloop.h"
#include "main/management/observers.h"
#include "object/observer/rect_click_observer.h"
#include "main/management/colors.h"

int onIteration(double _);

void onFinish();

void someRectOnClick();

RectView *someGlobalRect;
char changingChars[] = { '<', '>' };
bool isContinue = true;

int sample1() {
    init(onIteration, onFinish);

    View someView = newRect(point(2, 2), point(5, 3), changingChars[0], getColorId(COLOR_BLUE, COLOR_WHITE));
    someGlobalRect = someView.object;
    addView(&someView);

    Observer someViewOnClick = newRectClickObserver(point(2, 2), point(2+5, 2+3), someRectOnClick);
    addObserver(&someViewOnClick);

    notify();
    start();

    return 0;
}

int onIteration(double _) {
    someGlobalRect->symbol = someGlobalRect->symbol == changingChars[0] ? changingChars[1] : changingChars[0];
    notify();

    return isContinue;
}

void onFinish() {

}

void someRectOnClick() {
    if (changingChars[0] == '#') {
        changingChars[0] = '^';
        changingChars[1] = 'v';
    } else {
        changingChars[0] = '<';
        changingChars[1] = '>';
    }
}
