#ifndef _BACKGROUND_H_
#define _BACKGROUND_H_

#include <cpctelera.h>
#include <types.h>
#include "road_line.h"
#include "constantes.h"

typedef struct {
	u8 x;
	u8 y;
}TRoadLine;

extern const u8 g_background[40*50];

void initRoad();

void drawRoad();


#endif
