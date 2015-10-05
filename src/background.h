#ifndef _BACKGROUND_H_
#define _BACKGROUND_H_

#include <cpctelera.h>
#include <types.h>
#include "constantes.h"
#include "tiles.h"

typedef struct {
	i8 tx, ty;
	i8 dtiles;
	u8 new;
	// tile = g_tile_tiles_1
}TRoadLine;

//typedef struct {
//}Building;

// Background
extern const u8 g_background[40*50];

// RoadLines methods
void initRoad();
void scrollRoads();
void drawRoads();


#endif
