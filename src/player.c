#include "player.h"

// Variables Player
TPlayer Player;
const u8 vNumber = 100;
/////////////////////

void initPlayer() {
	Player.x=5;
	Player.y=31;
	Player.maxLifes=4;
	Player.lifes=Player.maxLifes;

	drawLifes();
}

void move() {
	u8* memptr;
	// Redraw a tilebox over the player to erase it (redrawing background over it)
	cpct_etm_drawTileBox2x4(Player.x, Player.y, PLAYER_WIDTH_TILES, PLAYER_HEIGHT_TILES, MAP_WIDTH_TILES, SCR_VMEM, g_background);

	cpct_scanKeyboard_f ();
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
	cpct_drawSpriteMasked(sprite_character, Player.memptr, PLAYER_WIDTH_BYTES, PLAYER_HEIGHT_BYTES);
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
  // Sonido de perder vida
}

void player() {
	move();
}
