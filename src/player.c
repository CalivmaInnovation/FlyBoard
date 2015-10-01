#include "player.h"

// Variables Player
TPlayer Player;
/////////////////////

void initPlayer() {
  Player.x=10;
  Player.y=130;
  Player.maxLifes=5;
  Player.lifes=Player.maxLifes;

  drawLifes();
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
  for (i=0; i < Player.maxLifes; i++) {
    cpct_drawSpriteMasked (g_tile_skate, (u8*)0xc054+(i*4), 4, 8);
    // cpct_drawTileAligned4x8 (g_tile_tiles_4, (u8*)0xc054+(i*4));
  }
  // Dibujar X cuadrados de 8bits verdes en el hueco de vida
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
