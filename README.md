# :beers: TUILib

Fun ui "framework" on C for C

## :rocket: How to start

* :package: Download this project and launch in Clion(I use it)
* :wrench: Create your own init function like in [TUILib/samples/sample1.c->int sample();](https://github.com/yoloroy/TUILib/blob/master/samples/sample1.c)
* :iphone: Work with updaters, observers of your widgets and create own widgets for your beautiful Text User Interface!

## :lipstick: Result
<img src="https://github.com/yoloroy/TUILib/blob/master/readme/sampleterminal1.png" width="500" height="400">

## :hammer: Code
```
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

int onIteration(double deltaTime) {...}

void onFinish() {...}

void buttonOnClick(Button *iAmHasClicked) {...}
```

### Samples
https://github.com/yoloroy/TUILib/tree/master/samples

## :white_check_mark: TODO
* Complete widget for text input
* Add scaling and snapping
