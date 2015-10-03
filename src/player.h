#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <cpctelera.h>
#include "character.h"
#include "skate.h"
#include "background.h"
#include "constantes.h"



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
