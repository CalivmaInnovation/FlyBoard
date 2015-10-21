#include "player.h"

// Variables Player
TPlayer Player;
//const u8 vNumber = 100;
/////////////////////

void initPlayer() {
	Player.x=5;
	Player.y=31;
	Player.maxLifes=4;
	Player.lifes=Player.maxLifes;
	Player.animation = 0;

	Player.memptr=cpct_getScreenPtr(SCR_VMEM, TILEWIDTH_BYTES*Player.x, TILEHEIGHT_BYTES*Player.y);
	Player.ox = Player.x;
	Player.oy = Player.y;
}

void move() {
	u8* memptr;
	// Redraw a tilebox over the player to erase it (redrawing background over it)
	Player.ox = Player.x;
	Player.oy = Player.y;
	cpct_scanKeyboard_f ();

	if ( cpct_isKeyPressed (Key_Esc)) {
		gameScene = MENUSCREEN;
	}
	if ( cpct_isKeyPressed (Key_W) && Player.y > PLAYER_MIN_Y) {
		Player.y = 31;
	}
	else if ( cpct_isKeyPressed (Key_S) && Player.y < PLAYER_MAX_Y) {
		Player.y = 41;
	}
	else if ( cpct_isKeyPressed (Key_A) && Player.x > PLAYER_MIN_X) {
		Player.x -= 1;
	}
	else if ( cpct_isKeyPressed (Key_D) && Player.x < PLAYER_MAX_X) {
		Player.x += 1;
	}

	memptr = cpct_getScreenPtr(SCR_VMEM, TILEWIDTH_BYTES*Player.x, TILEHEIGHT_BYTES*Player.y);
	Player.memptr = memptr;
}

void drawPlayer() {
	cpct_etm_drawTileBox2x4(Player.ox, Player.oy, PLAYER_WIDTH_TILES, PLAYER_HEIGHT_TILES, MAP_WIDTH_TILES, SCR_VMEM, g_background);
	if (Player.animation == 0) {
		cpct_drawSpriteMasked(sprite_player0, Player.memptr, PLAYER_WIDTH_BYTES, PLAYER_HEIGHT_BYTES);
		Player.animation = 1;
	}
	else if (Player.animation == 1) {
		cpct_drawSpriteMasked(sprite_player1, Player.memptr, PLAYER_WIDTH_BYTES, PLAYER_HEIGHT_BYTES);
		Player.animation = 2;
	}
	else {
		cpct_drawSpriteMasked(sprite_player2, Player.memptr, PLAYER_WIDTH_BYTES, PLAYER_HEIGHT_BYTES);
		Player.animation = 0;
	}


}

void drawLifes() {
  u8 i;
	for (i=0; i < Player.maxLifes; i++) {
		if (Player.lifes>i) {
			cpct_drawSprite(sprite_skate, (u8*)0xc054+(i*4), 4, 8);
		} else {
			cpct_drawSprite(g_tile_sky_blue, (u8*)0xc054+(i*4), 4, 8);
		}
	}
}

void lessLife() {
	--Player.lifes;
	drawLifes();
	if (Player.lifes == 0) {
		gameOverLevel();
		gameScene = GAMEOVERSCREEN;
	}
  // Sonido de perder vida
}

void collision() {
	if (RunnerCar.canColision && (Player.y == RunnerCar.y) && checkColision(Player.x)) {
		lessLife();
		RunnerCar.canColision=0;
	}
}

void player() {
	move();
	collision();
}
