#include "screens.h"

u8 gameScene;

void calivGames() {
	cpct_memset(SCR_VMEM, 0x33, 0x4000);

	cpct_etm_setTileset2x4(g_tile_tileset_4);
	cpct_etm_drawTilemap2x4_f(MAP_WIDTH_TILES, MAP_HEIGHT_TILES, SCR_VMEM, g_backgroundCalivGames);

	waitNVSYNCs(3000);
	gameScene=MAINLOOP;
}

void gameOver() {
	cpct_memset(SCR_VMEM, 0x33, 0x4000);

	cpct_etm_setTileset2x4(g_tile_tileset_4);
	cpct_etm_drawTilemap2x4_f(MAP_WIDTH_TILES, MAP_HEIGHT_TILES, SCR_VMEM, g_backgroundGameOver);

	waitNVSYNCs(3000);
	gameScene=MAINLOOP;
}

void mainMenu() {
//  u8 str[6];
// sprintf(str,"%u",RunnerCar.y);
// cpct_drawStringM0 (str, (u8*)0xc0a4, 0, 4);
}
