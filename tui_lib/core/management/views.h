#ifndef TUILIB_VIEWS_H
#define TUILIB_VIEWS_H

#include "../../objects/ui/button.h"

void initViews();

void updateViews();

int addView(View *);

void deleteView(int id);

void clearViews();

#endif //TUILIB_VIEWS_H
