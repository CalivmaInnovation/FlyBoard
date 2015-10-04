#include <types.h>
#include "background.h"

const u8 g_background[40*50] = {
	#include "mapa2.csv"
};

void drawRoad() {
	u8* memptr;
	u8 x,y;
	x=30;
	y=35;
	// Redraw a tilebox over the player to erase it (redrawing background over it)
	cpct_etm_drawTileBox2x4(x, y, ROAD_WIDTH_TILES, ROAD_HEIGHT_TILES, MAP_WIDTH_TILES, SCR_VMEM, g_background);
	// Move the player in tiles
	memptr = cpct_getScreenPtr(SCR_VMEM, TILEWIDTH_BYTES*x, TILEHEIGHT_BYTES*y);
	cpct_drawSpriteMasked(road_road_line, memptr, ROAD_WIDTH_BYTES, ROAD_HEIGHT_BYTES);
}
