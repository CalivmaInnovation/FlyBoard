#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <cpctelera.h>
#include "character.h"
#include "skate.h"
#include "background.h"

// Player constants
#define PLAYER_WIDTH_BYTES         4
#define PLAYER_HEIGHT_BYTES        8
#define PLAYER_WIDTH_TILES         2
#define PLAYER_HEIGHT_TILES        2
#define PLAYER_MAX_X     10
#define PLAYER_MIN_X      1
#define PLAYER_MAX_Y     45
#define PLAYER_MIN_Y     30

// Player sprites
extern const u8 sprite_skate[64];
extern const u8 sprite_character[64];

// Player struct
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

// Estos metodos no son de esta clase
void drawCars(i8 vNumber[]);
void numberToASCII (i8 vNumber[]);

#endif
