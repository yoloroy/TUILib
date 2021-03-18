#include "../src/object/view/rect_view.h"
#include "../src/main/mainloop.h"
#include "../src/main/management/observers.h"
#include "../src/object/observer/rect_click_observer.h"
#include "../src/utils/colors.h"

int onIteration(double _);

void onFinish();

void someRectOnClick();

RectView *someGlobalRect;
int someGlobalRectId;
int someGlobalViewOnClickId;
char changingChars[] = { '<', '>' };
bool isContinue = true;

int sample1() {
    init(onIteration, onFinish);

    View someView = newRect(point(2, 2), point(5, 3), changingChars[0], getColorId(COLOR_BLUE, COLOR_WHITE));
    someGlobalRect = someView.object;
    someGlobalRectId = someView.id;
    addView(&someView);

    Observer someViewOnClick = newRectClickObserver(point(2, 2), point(2+5, 2+3), someRectOnClick);
    someGlobalViewOnClickId = someViewOnClick.id;
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
    if (changingChars[0] == '<') {
        changingChars[0] = '^';
        changingChars[1] = 'v';
    } else {
        deleteObserver(someGlobalViewOnClickId);
        deleteView(someGlobalRectId);
    }
}
