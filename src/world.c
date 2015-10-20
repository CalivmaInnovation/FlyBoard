#include "world.h"

u16 initial_cars;
u16 old_initial_cars;

void drawBackground() {
	// Set the internal tileset for drawing Tilemaps
	cpct_etm_setTileset2x4(g_tile_tileset_bg);

	// Draw the background tilemap
	cpct_etm_drawTilemap2x4_f(MAP_WIDTH_TILES, MAP_HEIGHT_TILES, SCR_VMEM, g_background);
}

void initWorld() {
	drawBackground();
	initScroll();
}

void computeWorld() {
	Road();
	Building();
}
