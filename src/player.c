#include "player.h"

// Variables Player
TPlayer Player;
const i8 vNumber[3] = { 22, 2, 2 };
/////////////////////

void initPlayer() {
	//x in [1,127] and y in [1,63] (However, y >= 50 will be outside normal screen, because 50*4 = 200 pixels, which is the height of a normal screen).
	Player.x=5;
	Player.y=35;
	Player.maxLifes=4;
	Player.lifes=Player.maxLifes;

	drawLifes();

	drawCars(vNumber);
}

void move() {
	u8* memptr;
	// Redraw a tilebox over the player to erase it (redrawing background over it)
	cpct_etm_drawTileBox2x4(Player.x, Player.y, PLAYER_WIDTH_TILES, PLAYER_HEIGHT_TILES, MAP_WIDTH_TILES, SCR_VMEM, g_background);

	cpct_scanKeyboard_f ();
	if ( cpct_isKeyPressed (Key_W) && Player.y > PLAYER_MIN_Y) {
		Player.y -= 2;
	}
	else if ( cpct_isKeyPressed (Key_S) && Player.y < PLAYER_MAX_Y) {
		Player.y += 2;
	}
	else if ( cpct_isKeyPressed (Key_A) && Player.x > PLAYER_MIN_X) {
		Player.x -= 1;
	}
	else if ( cpct_isKeyPressed (Key_D) && Player.x < PLAYER_MAX_X) {
		Player.x += 1;
	}
	// Move the player in tiles
	memptr = cpct_getScreenPtr(SCR_VMEM, TILEWIDTH_BYTES*Player.x, TILEHEIGHT_BYTES*Player.y);
	cpct_drawSpriteMasked(player_character, memptr, PLAYER_WIDTH_BYTES, PLAYER_HEIGHT_BYTES);
}

void drawLifes() {
  u8 i;
  u8 z=48;
  u8 nDigitNumber[10]= { 48, 49, 50, 51, 52, 53, 54, 55, 56, 57 };

  for (i=0; i < Player.maxLifes; i++) {
    cpct_drawSprite(lifes_skate, (u8*)0xc054+(i*4), 4, 8);
    // cpct_drawTileAligned4x8 (g_tile_tiles_4, (u8*)0xc054+(i*4));
  }
}

void lessLife() {
//  cpct_drawTileAligned4x8(g_tile_tiles_8, (u8*)0xc054+(Player.lifes*4));
//  Player.lifes--;
  // Cambiar el cuadrado verde por el negro
  // Sonido de perder vida
}

void player() {
  move();
}

// /////////////////////////////
// Estos metodos no son de esta clase
// i8 vNumber[3] = { numReal,firstDigit,secondDigit };
void drawCars(i8 vNumber[]) {
  u8 nDigitNumber[10]= { 48, 49, 50, 51, 52, 53, 54, 55, 56, 57 };
  u8 i=10;
  numberToASCII (vNumber);

  // ESTO LO TIENE K DIBUJAR ENEMYS O EL MAPA
  cpct_drawStringM0 ("CARS:", (u8*)0xc054+(i*4), 0, 2);
  i+= 5;

  if (vNumber[1]==0) {
    cpct_drawCharM0 ((u8*)0xc054+(i*4), 0, 2, nDigitNumber[vNumber[2]]);
  }
  else {
    cpct_drawCharM0 ((u8*)0xc054+(i*4), 0, 2, nDigitNumber[vNumber[1]]);
    i++;
    cpct_drawCharM0 ((u8*)0xc054+(i*4), 0, 2, nDigitNumber[vNumber[2]]);
  }
}

void numberToASCII (i8 vNumber[]) {
  if (vNumber[2]<0) {
    vNumber[2]=9;
    vNumber[1]-=1;
  }
  vNumber[0]-=1;
  vNumber[2]-=1;
}
