#include <types.h>
#include "background.h"

TRoadLine *road[4];

const u8 g_background[40*50] = {
	#include "mapa2.csv"
};

void initRoad() {
	road[0]->x = 35;
	road[0]->y = 37;
	road[1]->x = 30;
	road[1]->y = 37;
	road[2]->x = 25;
	road[2]->y = 37;
	road[3]->x = 20;
	road[3]->y = 37;
}

void waitNVSYNCs(u8 n) {
   do {
      cpct_waitVSYNC();
      if (--n) {
         __asm__ ("halt");
         __asm__ ("halt");
      }
   } while (n);
}

void drawRoad() {
	u8* memptr;
	u8 i;
	for (i = 0; i < 4; i++) {
		// Redraw a tilebox over the player to erase it (redrawing background over it)
//		cpct_etm_drawTileBox2x4(road[i]->x, road[i]->y, ROAD_WIDTH_TILES, ROAD_HEIGHT_TILES, MAP_WIDTH_TILES, SCR_VMEM, g_background);
//		road[i]->x -= 1;
//		if (road[i]->x <= 0){ road[i]->x = 35; } 
		
		// Move the player in tiles
		memptr = cpct_getScreenPtr(SCR_VMEM, TILEWIDTH_BYTES*road[i]->x, TILEHEIGHT_BYTES*road[i]->y);
		cpct_drawSprite(road_road_line, memptr, ROAD_WIDTH_BYTES, ROAD_HEIGHT_BYTES);
//		waitNVSYNCs(2);
	}
}
