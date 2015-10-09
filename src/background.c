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
T_ScrollEntitie roadlines[maxLines];    // Vector with road lines

//
// Private methods declaration
T_ScrollEntitie* new_ScrollEntitie(u8 x, u8 y, u8 tiles, u8 new, u8 ttiles, u8* sprite, u8 t_width, u8 t_height, u8* e_sprite, u8 e_width, u8 e_height);
        u8 move_ScrollEntitie(u8 rl_idx);
      void destroy_ScrollEntitie(u8 i);
      void draw_ScrollEntitie(T_ScrollEntitie* r);

//
// Methods implementation
//
// Create a new road line an (x,y) position
T_ScrollEntitie* new_ScrollEntitie(u8 x, u8 y, u8 tiles, u8 new, u8 ttiles, u8* sprite, u8 t_width, u8 t_height, u8* e_sprite, u8 e_width, u8 e_height) {
	T_ScrollEntitie *new_scroll_enitite = 0;
	if (last_Line < maxLines) {
		new_scroll_enitite = &roadlines[last_Line];
		new_scroll_enitite->tx = x;
		new_scroll_enitite->ty = y;
		new_scroll_enitite->dtiles = tiles;
		new_scroll_enitite->ttiles = ttiles;
		new_scroll_enitite->new = new;
		new_scroll_enitite->sprite = sprite;
		new_scroll_enitite->t_width_bytes = t_width;
		new_scroll_enitite->t_height_bytes = t_height;
		new_scroll_enitite->e_sprite = e_sprite;
		new_scroll_enitite->e_width_bytes = e_width;
		new_scroll_enitite->e_height_bytes = e_height;
		last_Line += 1;
	}

	return new_scroll_enitite;
}

//
// Destroy a road line
void destroy_ScrollEntitie(u8 i) {
	i8 nEnts = last_Line - 1;

	// Copy 0 roadline to 1
	if (nEnts)
		cpct_memcpy(&roadlines[i], &roadlines[i+1], nEnts*sizeof(T_ScrollEntitie));

	// 1 less block
	--last_Line;

}

//
// Move a road line and check if it is at screen border
u8 move_ScrollEntitie(u8 rl_idx) {
	T_ScrollEntitie *rl = &roadlines[rl_idx];

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
		destroy_ScrollEntitie(rl_idx);
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
      draw_ScrollEntitie(&roadlines[i]);
}

//
// Method for draw
void draw_ScrollEntitie(T_ScrollEntitie* r) {
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
		cpct_drawSprite(r->sprite, memptr+(i * r->t_width_bytes), r->t_width_bytes, r->t_height_bytes);
	// Draw a black tile in end of line
	if (!r->new)
		cpct_drawSprite(r->e_sprite, memptr+(r->dtiles * r->e_width_bytes), r->e_width_bytes, r->e_height_bytes);

}

//
// Init road lines
void initRoad() {
	// g_tile_white
	u8 i;
	last_Line = 0;
	for (i = 2; i < maxLines*12; i+=12) {
		new_ScrollEntitie(i, 150, 3, 0, 3, g_tile_white, 2, 4, g_tile_black, 2, 4);
	}
}

//
// Scroll roadlines
void scrollRoads() {
	u8 i;

	// Move all road lines to left
	for(i=0; i < last_Line; ++i) {
		if ( move_ScrollEntitie(i) ) {
			i--;
		}
	}
	// Create new road line at end
	new_ScrollEntitie(78, 150, 1, 1, 3, g_tile_white, 2, 4, g_tile_black, 2, 4);
}
