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
#define maxLines 7                // Maximum number of road lines at the same time
u8 last_Line;                     // Last road line value
TRoadLine roadlines[maxLines];    // Vector with road lines

//
// Private methods declaration
TRoadLine* new_RoadLine(u8 x, u8 y);
        u8 move_RoadLine(u8 rl_idx);
      void destroy_RoadLine(u8 i);
      void draw_RoadLine(TRoadLine* r);

//
// Methods implementation
TRoadLine* new_RoadLine(u8 x, u8 y) {
	TRoadLine *new_road_line = 0;
	if (last_Line < maxLines) {
		new_road_line = &roadlines[last_Line];
		new_road_line->tx = x;
		new_road_line->ty = y;

		last_Line += 1;
	}

	return new_road_line;
}

void destroy_RoadLine(u8 i) {
	i8 nEnts = last_Line - 1; // Entities to the right of the block
	TRoadLine *rl = &roadlines[i];
	
	cpct_drawSolidBox(rl->memptr_old, 0x00, 6, 6);

	if (nEnts)
		cpct_memcpy(&roadlines[i], &roadlines[i+1], nEnts*sizeof(TRoadLine));

	// 1 less block   
	--last_Line;

}

u8 move_RoadLine(u8 rl_idx) {
	TRoadLine *rl = &roadlines[rl_idx];

	if (rl->tx <= 1) {
		destroy_RoadLine(rl_idx);
		return 1;
	}
	
	rl->tx -= 1;
	return 0;
}

void drawRoads() {
   u8  i = last_Line;

   // Draw Blocks (from last to first)
   while(i--) 
      draw_RoadLine(&roadlines[i]);
}

//
// Method for draw line
// 0x3C -> white (see cpct_px2byteM0 for conversions)
void draw_RoadLine(TRoadLine* r) {
	u8* memptr;
	cpct_drawSolidBox(r->memptr_old, 0x00, 6, 6);
	memptr = cpct_getScreenPtr(SCR_VMEM, r->tx, r->ty);
	r->memptr_old = memptr;
	cpct_drawSolidBox(memptr, 0x3C, 6, 6);
	
}

void initRoad() {
	last_Line = 0;
	new_RoadLine(02, 150);
	new_RoadLine(14, 150);
	new_RoadLine(26, 150);
	new_RoadLine(38, 150);
	new_RoadLine(50, 150);
	new_RoadLine(62, 150);
	new_RoadLine(74, 150);
}

void scrollRoads() {
	u8 i;

	for(i=0; i < last_Line; ++i) {
		if ( move_RoadLine(i) ) {
			i--;
			new_RoadLine(74, 150);
		}
	}	
}
