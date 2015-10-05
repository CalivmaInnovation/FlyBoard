#ifndef _BACKGROUND_H_
#define _BACKGROUND_H_

#include <cpctelera.h>
#include <types.h>
#include "constantes.h"

typedef struct {
	u8 tx, ty;
	u8* memptr_old;
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
