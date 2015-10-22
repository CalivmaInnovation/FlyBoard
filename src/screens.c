#include "screens.h"
#include "music.c"

u8 gameScene;

void newLevel() {
	u8 str[6];
	initLevel();
	sprintf(str, "%2u", level);
	cpct_memset(SCR_VMEM, 0, 0x4000);
	cpct_drawStringM0 ("LEVEL", getScreenPosition(7, 11), 15, 0);
	cpct_drawStringM0 (str, getScreenPosition(13, 11), 15, 0);
	cpct_drawStringM0 ("Press Space", getScreenPosition(4, 23), 15, 0);
	cpct_drawStringM0 ("to go next level", getScreenPosition(2, 24), 15, 0);
	cpct_scanKeyboard_f ();
	while (!cpct_isKeyPressed(Key_Space)) {
		cpct_scanKeyboard_f ();
	}
	levelMode();
}

void calivGames() {
	cpct_etm_setTileset2x4(g_tile_tileset_4);
	cpct_etm_drawTilemap2x4_f(MAP_WIDTH_TILES, MAP_HEIGHT_TILES, SCR_VMEM, g_backgroundCalivGames);

	waitNVSYNCs(3000);
	gameScene=MENUSCREEN;
}

void gameOver() {
	cpct_etm_setTileset2x4(g_tile_tileset_4);
	cpct_etm_drawTilemap2x4_f(MAP_WIDTH_TILES, MAP_HEIGHT_TILES, SCR_VMEM, g_backgroundGameOver);

	waitNVSYNCs(3000);
	gameScene=MENUSCREEN;
}

void playMenu() {
		u8 option=0;

		cpct_etm_setTileset2x4(g_tile_tileset_bg);
		cpct_etm_drawTilemap2x4_f(MAP_WIDTH_TILES, MAP_HEIGHT_TILES, SCR_VMEM, g_background);

		cpct_drawStringM0 ("PLAY GAME", getScreenPosition(5, 3), 15, 7);
		cpct_drawStringM0 ("INFINITY MODE", getScreenPosition(6, 5), 15, 7);
		cpct_drawStringM0 ("LEVELS MODE", getScreenPosition(6, 7), 15, 7);

		initScroll();
		initPlayer();
		cpct_scanKeyboard_f ();
		do {
			waitNVSYNCs(3);
			cpct_akp_musicPlay();
			Road();
			drawPlayer();
			if ( cpct_isKeyPressed (Key_Esc)) {
				gameScene=MENUSCREEN;
				return;
			}
			else if ( cpct_isKeyPressed (Key_CursorUp) && option != 0) {
				--option;
			}
			else if ( cpct_isKeyPressed (Key_CursorDown) && option != 1) {
				++option;
			}

			switch (option) {
				case 0:
					cpct_drawSprite(g_tile_sky_blue, getScreenPosition(4, 7), 4, 8);
					cpct_drawSprite(sprite_skate, getScreenPosition(4, 5), 4, 8);
					break;
				case 1:
					cpct_drawSprite(g_tile_sky_blue, getScreenPosition(4, 5), 4, 8);
					cpct_drawSprite(sprite_skate, getScreenPosition(4, 7), 4, 8);
					break;
			}
			cpct_scanKeyboard_f ();
//			waitNVSYNCs(5);
	} while (!cpct_isKeyPressed(Key_Return));

		switch (option) {
			case 0:
				cpct_akp_stop();
				gameScene=PLAYGAMESCREEN;
				break;
			case 1:
				cpct_akp_stop();
				gameScene=NEXTLEVELSCREEN;
				break;
		}
}


void mainMenu() {
		u8 option=0;
		cpct_etm_setTileset2x4(g_tile_tileset_bg);
		cpct_etm_drawTilemap2x4_f(MAP_WIDTH_TILES, MAP_HEIGHT_TILES, SCR_VMEM, g_background);

		cpct_drawStringM0 ("PLAY GAME", getScreenPosition(5, 3), 15, 7);
		cpct_drawStringM0 ("CONTROLS", getScreenPosition(5, 5), 15, 7);
		cpct_drawStringM0 ("CREDITS", getScreenPosition(5, 7), 15, 7);

		initScroll();
		initPlayer();
		cpct_scanKeyboard_f ();
		do {
		    waitNVSYNCs(3);
			cpct_akp_musicPlay();

			Road();
			drawPlayer();
			if ( cpct_isKeyPressed (Key_CursorUp) && option != 0) {
				--option;
			}
			else if ( cpct_isKeyPressed (Key_CursorDown) && option != 2) {
				++option;
			}

			switch (option) {
				case 0:
					cpct_drawSprite(g_tile_sky_blue, getScreenPosition(3, 5), 4, 8);
					cpct_drawSprite(sprite_skate, getScreenPosition(3, 3), 4, 8);
					break;
				case 1:
					cpct_drawSprite(g_tile_sky_blue, getScreenPosition(3, 3), 4, 8);
					cpct_drawSprite(g_tile_sky_blue, getScreenPosition(3, 7), 4, 8);
					cpct_drawSprite(sprite_skate, getScreenPosition(3, 5), 4, 8);
					break;
				case 2:
					cpct_drawSprite(g_tile_sky_blue, getScreenPosition(3, 5), 4, 8);
					cpct_drawSprite(sprite_skate, getScreenPosition(3, 7), 4, 8);
					break;
			}
			cpct_scanKeyboard_f ();
//			waitNVSYNCs(5);
	} while (!cpct_isKeyPressed(Key_Return));

		switch (option) {
    		case 0:	playMenu();
				break;
    		case 1: 
				gameScene=CONTROLSSCREEN;
				break;
		    case 2: 
				gameScene=CREDITSSCEENE;
				break;
		}
}

void controls() {
	cpct_memset(SCR_VMEM, 0, 0x4000);
	cpct_drawStringM0 ("CONTROLS", getScreenPosition(5, 3), 15, 0);

	cpct_drawStringM0 ("W: Move Up", getScreenPosition(4, 7), 15, 0);
	cpct_drawStringM0 ("S: Move Down", getScreenPosition(4, 9), 15, 0);
	cpct_drawStringM0 ("A: Move Left", getScreenPosition(4, 11), 15, 0);
	cpct_drawStringM0 ("D: Move Right", getScreenPosition(4, 13), 15, 0);

	cpct_drawStringM0 ("Press Space", getScreenPosition(4, 23), 15, 0);
	cpct_drawStringM0 ("to go main menu", getScreenPosition(2, 24), 15, 0);

	cpct_scanKeyboard_f ();
	while (!cpct_isKeyPressed(Key_Space)) {
		cpct_waitVSYNC();
		cpct_akp_musicPlay();
		cpct_scanKeyboard_f ();
	}
	// gameScene=MENUSCREEN;
	gameScene=MENUSCREEN;
}

void credits() {
	cpct_memset(SCR_VMEM, 0, 0x4000);
	cpct_drawStringM0 ("CREDITS", getScreenPosition(6, 0), 15, 0);

	cpct_drawStringM0 ("DEVELOPERS", getScreenPosition(5, 3), 15, 0);
	cpct_drawStringM0 ("Cesar Ivorra Oliver", getScreenPosition(1, 5), 15, 0);
	cpct_drawStringM0 ("Alex Almira Molla", getScreenPosition(1, 7), 15, 0);

	cpct_drawStringM0 ("GAME POWERED BY", getScreenPosition(2, 11), 15, 0);
	cpct_drawStringM0 ("CPCtelera", getScreenPosition(5, 13), 15, 0);

	cpct_drawStringM0 ("SPECIAL THANKS", getScreenPosition(3, 18), 15, 0);
	cpct_drawStringM0 ("Francisco Gallego", getScreenPosition(1, 20), 15, 0);

	cpct_drawStringM0 ("Press Space", getScreenPosition(4, 23), 15, 0);
	cpct_drawStringM0 ("to go main menu", getScreenPosition(2, 24), 15, 0);
	cpct_scanKeyboard_f ();
	while (!cpct_isKeyPressed(Key_Space)) {
		cpct_waitVSYNC();
		cpct_akp_musicPlay();

		cpct_scanKeyboard_f ();
	}
	gameScene=MENUSCREEN;
}
