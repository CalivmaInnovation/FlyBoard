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

void init_CPC() {
	cpct_disableFirmware();
	cpct_fw2hw(g_palette,16);
	cpct_setPalette(g_palette,16);
	cpct_setBorder (g_palette[15]);
	cpct_setVideoMode(0);
}

void init_game() {
	initWorld();
	initPlayer();
}

void main(void) {
	 u8 i=0;

	// Clear Screen
	cpct_memset(SCR_VMEM, 0, 0x4000);
	init_CPC();
	init_game();
	// Loop forever
	while (1) {
		computeWorld();
		player();
		createRunnerCar(0);
		drawPlayer();
		// Synchronize with VSYNC + 1 HSYNC to slow down the movement
		cpct_waitVSYNC();   // Wait for VSYNC signal
		__asm__("halt");    // H
	};
}
