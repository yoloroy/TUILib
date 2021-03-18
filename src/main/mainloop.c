#include <ncurses.h>
#include <time.h>
#include <zconf.h>
#include "mainloop.h"
#include "management/observers.h"
#include "../utils/colors.h"

bool needToRefresh = false;

void init(int (*onIteration)(double), void (*onFinish)()) {
    initscr();
    start_color();
    keypad(stdscr, TRUE);
    mousemask(BUTTON1_PRESSED | BUTTON2_PRESSED | BUTTON3_PRESSED, NULL);
    noecho();
    curs_set(false);
    halfdelay(1);

    initViews();
    initObservers();

    _onIteration = onIteration;
    _onFinish = onFinish;
}

void start() {
    int lastTime = clock(), time;
    double dt;
    chtype ch;

    do {
        time = clock();
        dt = ((double)(time - lastTime)) / CLOCKS_PER_SEC;
        lastTime = time;

        // region TODO: refactor
        attron(COLOR_PAIR(getColorId(COLOR_WHITE, COLOR_BLACK)));
        clear();
        // endregion

        updateViews();
        while ((ch = getch()) != ERR) {
            mvprintw(0, 0, "getch: %d", ch);
            checkObservers(ch, getEventTypeOfCh(ch));
        }
        mvprintw(0, 0, "getch: %d", ch);

        if (needToRefresh) {
            refresh();
            needToRefresh = false;
        }
        sleep(1);
    } while (_onIteration(dt));

    finish();
}

void finish() {
    clearViews();
    clearObservers();
    _onFinish();
    endwin();
}

void notify() {
    needToRefresh = true;
}
