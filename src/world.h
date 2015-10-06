#ifndef _WORLD_H_
#define _WORLD_H_

#include <cpctelera.h>
#include "constantes.h"
#include "tiles.h"

#define BUILD_WIDTH_BYTES         15
#define BUILD_HEIGHT_BYTES        90

#define BUILD_MAX_X 65
#define BUILD_MIN_X 0

void initBuild();
void drawBuild();
void initWorld();
void world1();

#endif
