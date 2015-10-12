#ifndef _WORLD_H_
#define _WORLD_H_

#include "constantes.h"
#include "scroll.h"
#include "runners.h"

extern u8 initial_cars;

void drawWorld_Level(u8 nWorld, u8 nLevel);
void drawBackground();
void initWorld();
void computeWorld();

#endif
