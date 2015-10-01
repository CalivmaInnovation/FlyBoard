#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <cpctelera.h>
#include "character.h"
#include "tiles.h"

#define VMEM (u8*)0xC000

typedef struct {
  u8 x;
  u8 y;
  u8* memptr; // no se seguro si esto debe ser propio del player
  u8 maxLifes;
  u8 lifes;
}TPlayer;

void initPlayer();
void player();
void move();
void drawLifes();
void lessLife();

#endif
