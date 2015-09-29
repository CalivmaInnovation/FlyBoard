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

#define VMEM (u8*)0xC000
#define MODE0_HEIGHT 190
#define MODE0_WIDTH 75

const u8 g_palette[7] = { 0, 26, 11, 22, 13, 6, 2 };

void drawMap() {
	// Set the internal tileset for drawing Tilemaps
	cpct_etm_setTileset2x4(g_tile_tileset);

	// Draw the background tilemap
	cpct_etm_drawTilemap2x4_f(40, 50, VMEM, g_background);
}

void init() {
	cpct_disableFirmware();
	cpct_fw2hw(g_palette,7);
	cpct_setPalette(g_palette,7);
	cpct_setBorder (g_palette[1]);
	cpct_setVideoMode(0);
}


void main(void) {

	u8 var;
	u8 x = 10;
	u8 y = 130;
	u8* memptr;
	u8 mu;
	
	// Clear Screen
	cpct_memset(VMEM, 0, 0x4000);

	init();
	drawMap();

	// Loop forever
	while (1) {

		memptr = cpct_getScreenPtr(VMEM, x, y);
		cpct_drawSolidBox (memptr, 0, 5, 10);
		
		cpct_scanKeyboard_f ();
		if ( cpct_isKeyPressed (Key_CursorUp) && y > 130) {
			y -= 2;
		}
		else if ( cpct_isKeyPressed (Key_CursorDown) && y < 175) {
			y += 2;
		}
		else if ( cpct_isKeyPressed (Key_CursorLeft) && x > 2) {
			x -= 1;
		}
		else if ( cpct_isKeyPressed (Key_CursorRight) && x < 20) {
			x += 1;
		}
		memptr = cpct_getScreenPtr(VMEM, x, y);
		cpct_drawSpriteMasked(character_character, memptr, 5, 10);
		cpct_waitVSYNC();
	}
}
