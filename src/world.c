#include <stdio.h>
#include "world.h"

void drawWorld_Level(u8 nWorld, u8 nLevel) {
  u8 str[6];

  // ESTO LO TIENE K DIBUJAR ENEMYS O EL MAPA
  sprintf(str, "%u", nWorld);
  cpct_drawStringM0 ("WORLD", (u8*)0xC069, 0, 4);
  cpct_drawStringM0 (str, (u8*)0xC07F, 0, 4);
  sprintf(str, "%u", nLevel);
  cpct_drawStringM0 ("LEVEL", (u8*)0xC0B9, 0, 4);
  cpct_drawStringM0 (str, (u8*)0xC0CF, 0, 4);

}

