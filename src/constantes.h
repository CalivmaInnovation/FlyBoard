#ifndef _CONSTANTES_
#define _CONSTANTES_

#include <cpctelera.h>
#include "tiles.h"

#define SCR_VMEM (u8*)0xC000

#define MAP_WIDTH_TILES          40
#define MAP_HEIGHT_TILES         50

#define TILEWIDTH_BYTES           2
#define TILEHEIGHT_BYTES          4

#define CALIVGAMESSCREEN 0
#define LANGUAGESCREEN   1
#define MENUSCREEN       2
#define PLAYGAMESCREEN   3
#define PASSSCREEN       4
#define CONTROLSSCREEN   5
#define GAMEOVERSCREEN   6
#define CREDITSSCEENE    7
#define NEXTLEVELSCEENE  8
#define MAINLOOP         9

extern u8 gameScene;

// 0,3,8,13,14,16,26
extern const u8 g_palette[16];
extern const u8 g_palette2[16];
extern const u8 g_palette3[16];

// If we need a global method put here
void waitNVSYNCs(u8 n);

#endif // _CONSTANTES_
