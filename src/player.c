#include "player.h"

// Variables Player
TPlayer Player;
const i8 vNumber[3] = { 22, 2, 2 };
/////////////////////

void initPlayer() {
  Player.x=10;
  Player.y=130;
  Player.maxLifes=4;
  Player.lifes=Player.maxLifes;

  drawLifes();

  drawCars(vNumber);
}

void move() {
  Player.memptr = cpct_getScreenPtr(VMEM, Player.x, Player.y);
  cpct_drawSolidBox (Player.memptr, 0, 5, 10);

  cpct_scanKeyboard_f ();
  if ( cpct_isKeyPressed (Key_W) && Player.y > 130) {
    Player.y -= 2;
  }
  else if ( cpct_isKeyPressed (Key_S) && Player.y < 175) {
    Player.y += 2;
  }
  else if ( cpct_isKeyPressed (Key_A) && Player.x > 2) {
    Player.x -= 1;
  }
  else if ( cpct_isKeyPressed (Key_D) && Player.x < 20) {
    Player.x += 1;
  }
  Player.memptr = cpct_getScreenPtr(VMEM, Player.x, Player.y);
  cpct_drawSpriteMasked(character_character, Player.memptr, 5, 10);
}

void drawLifes() {
  u8 i;
  u8 z=48;
  u8 nDigitNumber[10]= { 48, 49, 50, 51, 52, 53, 54, 55, 56, 57 };

  for (i=0; i < Player.maxLifes; i++) {
    cpct_drawSpriteMasked (g_tile_skate, (u8*)0xc054+(i*4), 4, 8);
    // cpct_drawTileAligned4x8 (g_tile_tiles_4, (u8*)0xc054+(i*4));
  }
}

void lessLife() {
  cpct_drawTileAligned4x8(g_tile_tiles_8, (u8*)0xc054+(Player.lifes*4));
  Player.lifes--;
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
