#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "constantes.h"
#include "runners.h"

// Player constants
#define PLAYER_WIDTH_BYTES         8
#define PLAYER_HEIGHT_BYTES        24
#define PLAYER_WIDTH_TILES         4
#define PLAYER_HEIGHT_TILES        6
#define PLAYER_MAX_X     10
#define PLAYER_MIN_X      1
#define PLAYER_MAX_Y     40
#define PLAYER_MIN_Y     32

// Player struct
typedef struct {
  u8 x;
  u8 y;
  u8 ox;
  u8 oy;
  u8 maxLifes;
  u8 lifes;
  u8* memptr;
}TPlayer;

extern TPlayer Player;

void initPlayer();
void player();
void move();
void drawPlayer(); /* provisional para comprobar pintado parpadeante */
void drawLifes();
void lessLife();
void collision();

#endif
