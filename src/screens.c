#include "screens.h"

u8 gameScene;

void calivGames() {
	u8* memptr;
	cpct_memset(SCR_VMEM, 0x33, 0x4000);

	cpct_etm_setTileset2x4(g_tile_tileset_4);
	cpct_etm_drawTilemap2x4_f(MAP_WIDTH_TILES, MAP_HEIGHT_TILES, SCR_VMEM, g_backgroundLogo);

	memptr = cpct_getScreenPtr(SCR_VMEM, 12, 50);
	cpct_drawSprite(sprite_alce, memptr, 55, 93);

	// waitNVSYNCs(2000);
	gameScene=LANGUAGESCREEN;
}

// void drawFlagH(u8 colour1[], u8 colour2[], u8 colour3[], u8* memory) {
// 	u8 i;
// 	for (i = 0; i < 3; ++i) {
// 		cpct_drawSprite(colour1, memory + (i*4), 4, 8);
// 		cpct_drawSprite(colour2, memory + (i*4) + 0x0050, 4, 8);
// 		cpct_drawSprite(colour3, memory + (i*4) + 0x00A0, 4, 8);
// 	}
// }
//
// void drawFlagV(u8 colour1[], u8 colour2[], u8 colour3[], u8* memory) {
// 	u8 i;
// 	for (i = 0; i < 3; ++i) {
// 		cpct_drawSprite(colour1, memory + (0xc0050*i), 4, 8);
// 		cpct_drawSprite(colour2, memory + (0xc0050*i), 4, 8);
// 		cpct_drawSprite(colour3, memory + (0xc0050*i), 4, 8);
// 	}
// }

void language() {

	// cpct_memset(SCR_VMEM, 0x33, 0x4000);
	// cpct_drawStringM0("SELECT YOUR LANGUAGE", (u8*)0xc000, 0, 4);
	//
	// cpct_drawStringM0("ENGLISH", (u8*)0xc0b0, 0, 4);
	// 	drawFlagH(g_tile_black, g_tile_black, g_tile_black, (u8*)0xc050);
	//
	// cpct_drawStringM0("ESPANYOL", (u8*)0xc1f0, 0, 4);
	// 	drawFlagH(g_tile_bright_red, g_tile_bright_yellow, g_tile_bright_red, (u8*)0xc190);
	//
	// cpct_drawStringM0("FRANCAIS", (u8*)0xc330, 0, 4);
	// 	drawFlagV(g_tile_bright_blue, g_tile_white, g_tile_bright_red, (u8*)0xc2d0);
	//
	// cpct_drawStringM0("ITALIANO", (u8*)0xc470, 0, 4);
	// 	drawFlagH(g_tile_black, g_tile_black, g_tile_black, (u8*)0xc410);
	//
	// cpct_drawStringM0("DEUTSCH", (u8*)0xc5b0, 0, 4);
	// 	drawFlagH(g_tile_black, g_tile_black, g_tile_black, (u8*)0xc550);
	//
	// cpct_drawStringM0("NEDERLANDS", (u8*)0xc6f0, 0, 4);
	// 	drawFlagH(g_tile_black, g_tile_black, g_tile_black, (u8*)0xc690);

	cpct_scanKeyboard_f();
	while(!cpct_isKeyPressed (Key_Return))
	{
		cpct_scanKeyboard_f();
	}
	gameScene=MAINLOOP;
}


void mainMenu() {
//  u8 str[6];
// sprintf(str,"%u",RunnerCar.y);
// cpct_drawStringM0 (str, (u8*)0xc0a4, 0, 4);
}
