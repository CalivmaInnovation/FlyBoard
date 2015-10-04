#include <types.h>
#include "background.h"

//
// Background
//
const u8 g_background[40*50] = {
	#include "mapa2.csv"
};


//
// RoadLine
//

//
// Variables
#define maxLines 4                // Maximum number of road lines at the same time
u8 last_Line;                     // Last road line value
TRoadLine roadlines[maxLines];    // Vector with road lines

//
// Private methods declaration
TRoadLine* newRoadLine(u8 x, u8 y);
        u8 moveRoadLine(u8 rl_idxidx);
      void destroyRoadLine(u8 rl_idx);

//
// Methods implementation
TRoadLine* newRoadLine(u8 x, u8 y) {
	TRoadLine *new_road_line = 0;
	if (last_Line < maxLines) {
		new_road_line = &roadlines[last_Line];
		new_road_line->tx = x;
		new_road_line->ty = y;

		last_Line += 1;
	}

	return new_road_line;
}

void initRoad() {

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

/* void drawRoad() { */
/* 	u8* memptr; */
/* 	u8 i; */
/* 	for (i = 0; i < 4; i++) { */
/* 		// Redraw a tilebox over the player to erase it (redrawing background over it) */
/* //		cpct_etm_drawTileBox2x4(road[i]->x, road[i]->y, ROAD_WIDTH_TILES, ROAD_HEIGHT_TILES, MAP_WIDTH_TILES, SCR_VMEM, g_background); */
/* //		road[i]->x -= 1; */
/* //		if (road[i]->x <= 0){ road[i]->x = 35; }  */
		
/* 		// Move the player in tiles */
/* 		memptr = cpct_getScreenPtr(SCR_VMEM, TILEWIDTH_BYTES*roadlines[i].tx, TILEHEIGHT_BYTES*roadlines[i].ty); */
/* 		cpct_drawSprite(road_road_line, memptr, ROAD_WIDTH_BYTES, ROAD_HEIGHT_BYTES); */
/* //		waitNVSYNCs(2); */
/* 	} */
/* } */
