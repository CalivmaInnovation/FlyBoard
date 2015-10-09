#ifndef _BACKGROUND_H_
#define _BACKGROUND_H_

#include <cpctelera.h>
#include <types.h>
#include "constantes.h"
#include "tiles.h"
#include "player.h"
#include "car.h"


typedef struct {
	i8 tx, ty;
	i8 dtiles;
	i8 ttiles;
	u8 new;
	// This is a probe, until this all work
	u8* sprite;
	u8 t_width_bytes;
	u8 t_height_bytes;
	u8* e_sprite;
	u8 e_width_bytes;
	u8 e_height_bytes;
	// tile = g_tile_tiles_1
}T_ScrollEntitie;

//typedef struct {
//}Building;

// Background
extern const u8 g_background[40*50];

// RoadLines methods
void initRoad();
void scrollRoads();
void drawRoads();


#endif
