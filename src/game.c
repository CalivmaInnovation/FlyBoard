#include "game.h"

void init_game() {
	initWorld();
	initPlayer();
}

void main_loop() {
	waitNVSYNCs(1);
	computeWorld();
	player();
	throwRunner();
	drawPlayer();
	// Synchronize with VSYNC + 1 HSYNC to slow down the movement
	waitNVSYNCs(2);
}

void story_board(u16 n) {
	u8* memptr;
	cpct_memset(SCR_VMEM, 0x33, 0x4000);
	cpct_etm_setTileset2x4(g_tile_tileset_4);

	// Draw the background tilemap
	cpct_etm_drawTilemap2x4_f(MAP_WIDTH_TILES, MAP_HEIGHT_TILES, SCR_VMEM, g_backgroundLogo);
//	memptr = cpct_getScreenPtr(SCR_VMEM, 0, 0);
//	cpct_drawSprite(g_tile_caliv, (u8*)0xC318, 70, 40);
	memptr = cpct_getScreenPtr(SCR_VMEM, 12, 50);
	cpct_drawSprite(g_tile_alce, memptr, 55, 93);
//	memptr = cpct_getScreenPtr(SCR_VMEM, 15, 180);
//	cpct_drawStringM0("CALIV GAMES", memptr, 0, 12);
//	memptr = cpct_getScreenPtr(SCR_VMEM, 12, 80);
//	cpct_drawSprite(g_tile_games, SCR_VMEM, 68, 36);
	while(--n){
		__asm__ ("halt");
		__asm__ ("halt");
	}

}
