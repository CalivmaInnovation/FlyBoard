#include "screens.h"

u8 gameScene;

void calivGames() {
	u8* memptr;
	cpct_memset(SCR_VMEM, 0x33, 0x4000);
	
	cpct_etm_setTileset2x4(g_tile_tileset_4);
	cpct_etm_drawTilemap2x4_f(MAP_WIDTH_TILES, MAP_HEIGHT_TILES, SCR_VMEM, g_backgroundLogo);

	memptr = cpct_getScreenPtr(SCR_VMEM, 12, 50);
	cpct_drawSprite(sprite_alce, memptr, 55, 93);

	waitNVSYNCs(2000);
	gameScene=MAINLOOP;
}

void mainMenu() {

}
