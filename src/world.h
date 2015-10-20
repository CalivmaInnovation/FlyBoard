#ifndef _WORLD_H_
#define _WORLD_H_

#include "constantes.h"
#include "scroll.h"
#include "runners.h"
#include <stdio.h>

extern u16 initial_cars;
extern u16 old_initial_cars;

void drawBackground();
void initWorld();
void computeWorld();

#endif
