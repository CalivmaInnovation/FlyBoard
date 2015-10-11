#include <stdio.h>
#include "world.h"

void drawWorld_Level(u8 nWorld, u8 nLevel) {
  u8 str[6];
  sprintf(str, "%u", nWorld);
  cpct_drawStringM0 ("WORLD", (u8*)0xC069, 0, 4);
  cpct_drawStringM0 (str, (u8*)0xC07F, 0, 4);
  sprintf(str, "%u", nLevel);
  cpct_drawStringM0 ("LEVEL", (u8*)0xC0B9, 0, 4);
  cpct_drawStringM0 (str, (u8*)0xC0CF, 0, 4);

}

void drawBackground() {
	// Set the internal tileset for drawing Tilemaps
	cpct_etm_setTileset2x4(g_tile_tileset_bg);

	// Draw the background tilemap
	cpct_etm_drawTilemap2x4_f(MAP_WIDTH_TILES, MAP_HEIGHT_TILES, SCR_VMEM, g_background);
}

void initWorld() {
	drawBackground();
	initScroll();
	drawWorld_Level(3, 2);
	drawCars(100);
}

void computeWorld() {
	Road();
	Building();
}
