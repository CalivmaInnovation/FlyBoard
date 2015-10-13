#ifndef _WORLD_H_
#define _WORLD_H_

#include "constantes.h"
#include "scroll.h"
#include "runners.h"
#include <stdio.h>

extern u16 initial_cars;

void drawWorldLevel(u8 nWorld, u8 nLevel);
void drawBackground();
void initWorld();
void computeWorld();

#endif
