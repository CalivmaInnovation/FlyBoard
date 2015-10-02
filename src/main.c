//-----------------------------LICENSE NOTICE------------------------------------
//  This file is part of CPCtelera: An Amstrad CPC Game Engine
//  Copyright (C) 2015 ronaldo / Fremos / Cheesetea / ByteRealms (@FranGallegoBR)
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.
//------------------------------------------------------------------------------

#include <cpctelera.h>

#include "tiles.h"
#include "character.h"
#include "player.h"

#define VMEM (u8*)0xC000
#define MODE0_HEIGHT 190
#define MODE0_WIDTH 75

// 0,3,8,13,14,16,26
const u8 g_palette[7] = {0x14, 0x1C, 0x0D, 0x00, 0x1F, 0x07, 0x0B};

void drawMap() {
	// Set the internal tileset for drawing Tilemaps
	cpct_etm_setTileset2x4(g_tile_tileset);

	// Draw the background tilemap
	cpct_etm_drawTilemap2x4_f(40, 50, VMEM, g_background);
}

void init() {
	cpct_disableFirmware();
	// cpct_fw2hw(g_palette,8);
	cpct_setPalette(g_palette,7);
	cpct_setBorder (g_palette[1]);
	cpct_setVideoMode(0);

	drawMap();
	initPlayer();
}

// Esto lo dejo en el main temporalmente
const u8 sinus_offsets[256]={
	 0, 0, 0, 0, 0, 0, 0,
	 1, 1, 1, 1, 1, 1,
	 2, 2, 2, 2, 2, 2,
	 3, 3, 3, 3, 3, 3,
	 4, 4, 4, 4, 4, 4,
	 5, 5, 5, 5, 5, 5, 5,
	 6, 6, 6, 6, 6, 6,
	 7, 7, 7, 7, 7, 7,
	 8, 8, 8, 8, 8, 8,
	 9, 9, 9, 9, 9, 9,
	10,10,10,10,10,10,10,
	11,11,11,11,11,11,
	12,12,12,12,12,12,
	13,13,13,13,13,13,
	14,14,14,14,14,14,
	15,15,15,15,15,15,15,
	16,16,16,16,16,16,
	17,17,17,17,17,17,
	18,18,18,18,18,18,
	19,19,19,19,19,19,
	20,20,20,20,20,20,20,
	21,21,21,21,21,21,
	22,22,22,22,22,22,
	23,23,23,23,23,23,
	24,24,24,24,24,24,
	25,25,25,25,25,25,25,
	26,26,26,26,26,26,
	27,27,27,27,27,27,
	28,28,28,28,28,28,
	29,29,29,29,29,29,
	30,30,30,30,30,30,30,
	31,31,31,31,31,31,
	32,32,32,32,32,32,
	33,33,33,33,33,33,
	34,34,34,34,34,34,
	35,35,35,35,35,35,35,
	36,36,36,36,36,36,
	37,37,37,37,37,37,
	38,38,38,38,38,38,
	39,39,39,39,39,39,
	40,40,40,40,40,40,40,40
};

void main(void) {
	 u8 i=0;

	// Clear Screen
	cpct_memset(VMEM, 0, 0x4000);
	init();

	// Loop forever
	while (1) {
		// cpct_setVideoMemoryOffset(sinus_offsets[i++]);
		player();

		// Synchronize with VSYNC + 1 HSYNC to slow down the movement
		cpct_waitVSYNC();   // Wait for VSYNC signal
		__asm__("halt");    // H
	};
}
