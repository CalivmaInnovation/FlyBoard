#include <types.h>
#include "background.h"

//
// Background
const u8 g_background[40*50] = {
	#include "mapa.csv"
};


//
// RoadLine
//----------
//
// Variables
#define maxLines 7                // Maximum number of road lines at the same time
u8 last_Line;                     // Last road line value
TRoadLine roadlines[maxLines];    // Vector with road lines

//
// Private methods declaration
TRoadLine* new_RoadLine(u8 x, u8 y, u8 tiles, u8 new, u8 ttiles);
        u8 move_RoadLine(u8 rl_idx);
      void destroy_RoadLine(u8 i);
      void draw_RoadLine(TRoadLine* r);

//
// Methods implementation
//
// Create a new road line an (x,y) position
TRoadLine* new_RoadLine(u8 x, u8 y, u8 tiles, u8 new, u8 ttiles) {
	TRoadLine *new_road_line = 0;
	if (last_Line < maxLines) {
		new_road_line = &roadlines[last_Line];
		new_road_line->tx = x;
		new_road_line->ty = y;
		new_road_line->dtiles = tiles;
		new_road_line->ttiles = ttiles;
		new_road_line->new = new;
		last_Line += 1;
	}

	return new_road_line;
}

//
// Destroy a road line
void destroy_RoadLine(u8 i) {
	i8 nEnts = last_Line - 1;

	// Copy 0 roadline to 1
	if (nEnts)
		cpct_memcpy(&roadlines[i], &roadlines[i+1], nEnts*sizeof(TRoadLine));

	// 1 less block
	--last_Line;

}

//
// Move a road line and check if it is at screen border
u8 move_RoadLine(u8 rl_idx) {
	TRoadLine *rl = &roadlines[rl_idx];

	// If we are new and don't have all tiles, plus one
	if (rl->new && rl->dtiles < rl->ttiles) {
		rl->dtiles += 1;
		rl->tx -= 1;
	}
	
	// If we are out screen, draw one less tile
	if (rl->tx <= -1)
		rl->dtiles -= 1;

	// If don't have more tiles, destroy it
	if (rl->dtiles <= -rl->ttiles) {
		destroy_RoadLine(rl_idx);
		return 1;
	}

	// If have all dtiles, isn't new
	if(rl->dtiles == rl->ttiles) 
		rl->new = 0;
	
	// Minus one position to the left
	rl->tx -= 1;
	return 0;
}

//
// Draw all roads
void drawRoads() {
   u8 i = last_Line;

   while(i--) 
      draw_RoadLine(&roadlines[i]);
}

//
// Method for draw 
void draw_RoadLine(TRoadLine* r) {
	u8* memptr;
	i8 i;

	// If it are outside screen, start to draw in screen. So obvious men!! :)
	if (r->tx <= -1) {
		memptr = cpct_getScreenPtr(SCR_VMEM, 0, r->ty);
	}
	else {
		// Else, draw where we have to draw xD!
		memptr = cpct_getScreenPtr(SCR_VMEM, r->tx, r->ty);		
	}

	// Draw n white tiles
	for(i = 0; i < r->dtiles; ++i)
		cpct_drawSprite(g_tile_white, memptr+(i * 2), TILEWIDTH_BYTES, TILEHEIGHT_BYTES);
	// Draw a black tile in end of line
	if (!r->new)
		cpct_drawSprite(g_tile_black, memptr+(r->dtiles * 2), TILEWIDTH_BYTES, TILEHEIGHT_BYTES);
	
}

//
// Init road lines
void initRoad() {
	last_Line = 0;
	new_RoadLine(02, 150, 3, 0, 3);
	new_RoadLine(14, 150, 3, 0, 3);
	new_RoadLine(26, 150, 3, 0, 3);
	new_RoadLine(38, 150, 3, 0, 3);
	new_RoadLine(50, 150, 3, 0, 3);
	new_RoadLine(62, 150, 3, 0, 3);
	new_RoadLine(74, 150, 3, 0, 3);
}

//
// Scroll roadlines
void scrollRoads() {
	u8 i;

	// Move all road lines to left
	for(i=0; i < last_Line; ++i) {
		if ( move_RoadLine(i) ) {
			i--;
		}
	}
	// Create new road line at end
	new_RoadLine(78, 150, 1, 1, 3);
}
