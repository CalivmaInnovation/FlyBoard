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

#include "constantes.h"

#include "player.h"
#include "world.h"
#include "scroll.h"

void drawMap() {
	// Set the internal tileset for drawing Tilemaps
	cpct_etm_setTileset2x4(g_tile_tileset);

	// Draw the background tilemap
	cpct_etm_drawTilemap2x4_f(40, 50, SCR_VMEM, g_background);
}

void init() {
	cpct_disableFirmware();
	cpct_setPalette(g_palette,7);
	cpct_setBorder (g_palette[1]);
	cpct_setVideoMode(0);

	drawMap();
	initPlayer();
	initScroll();
}

void main(void) {
	 u8 i=0;

	// Clear Screen
	cpct_memset(SCR_VMEM, 0, 0x4000);
	init();
	// Loop forever
	while (1) {
		player();
		Road();
		// Synchronize with VSYNC + 1 HSYNC to slow down the movement
		cpct_waitVSYNC();   // Wait for VSYNC signal
		__asm__("halt");    // H
	};
}
