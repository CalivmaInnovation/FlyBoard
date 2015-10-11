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

// Player sprites
extern const u8 bloque [32];
// Player struct
typedef struct {
  u8 x;
  u8 y;
  u8 maxLifes;
  u8 lifes;
}TPlayer;

void initPlayer();
void player();
void move();
void drawLifes();
void lessLife();

#endif
