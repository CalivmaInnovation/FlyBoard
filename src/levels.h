#ifndef LEVELS_H
#define LEVELS_H

#include "constantes.h"
#include "runners.h"
#include "world.h"

extern u8 level;

void initLevel();
void drawWorldLevel();
void nextLevel();
void gameOverLevel();

#endif /* LEVELS_H */
