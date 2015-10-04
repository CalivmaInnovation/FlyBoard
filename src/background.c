#include <types.h>
#include "background.h"

TRoadLine road;

const u8 g_background[40*50] = {
	#include "mapa2.csv"
};

void initRoad() {
	road.x = 35;
	road.y = 37;
}

void drawRoad() {
	u8* memptr;
	// Redraw a tilebox over the player to erase it (redrawing background over it)
	cpct_etm_drawTileBox2x4(road.x, road.y, ROAD_WIDTH_TILES, ROAD_HEIGHT_TILES, MAP_WIDTH_TILES, SCR_VMEM, g_background);
	road.x -= 1;
	if (road.x <= 0){ road.x = 35; } 

	// Move the player in tiles
	memptr = cpct_getScreenPtr(SCR_VMEM, TILEWIDTH_BYTES*road.x, TILEHEIGHT_BYTES*road.y);
	cpct_drawSprite(road_road_line, memptr, ROAD_WIDTH_BYTES, ROAD_HEIGHT_BYTES);
}
