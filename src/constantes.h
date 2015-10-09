#ifndef _CONSTANTES_
#define _CONSTANTES_

#include <cpctelera.h>
#include "tiles.h"

#define SCR_VMEM (u8*)0xC000

#define MAP_WIDTH_TILES          40
#define MAP_HEIGHT_TILES         50

#define TILEWIDTH_BYTES           2
#define TILEHEIGHT_BYTES          4

// 0,3,8,13,14,16,26
extern const u8 g_palette[7];

// If we need a global method put here
void waitNVSYNCs(u8 n);


#endif // _CONSTANTES_
