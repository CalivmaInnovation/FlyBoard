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

#define VMEM (u8*)0xC000

const u8 g_palette[6] = { 0, 26, 11, 22, 13, 6 };

void drawMap() {
	// Set the internal tileset for drawing Tilemaps
	cpct_etm_setTileset2x4(g_tile_tileset);

	// Draw the background tilemap
	cpct_etm_drawTilemap2x4_f(40, 50, VMEM, g_background);
}

void init() {
	cpct_disableFirmware();
	cpct_fw2hw(g_palette,6);
	cpct_setPalette(g_palette,6);
	cpct_setBorder (g_palette[5]);
	cpct_setVideoMode(0);
}


void main(void) {

	// Clear Screen
   cpct_memset(VMEM, 0, 0x4000);

   init();
   drawMap();
   // Loop forever
   while (1);
}
