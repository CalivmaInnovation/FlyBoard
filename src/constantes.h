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
#define MENUSCREEN       1
#define PLAYGAMESCREEN   2
#define CONTROLSSCREEN   3
#define GAMEOVERSCREEN   4
#define CREDITSSCEENE    5
#define NEXTLEVELSCREEN  6

extern u8 gameScene;
extern u8 gameMode; // 0 for infinity and 1 for level mode
// 0,3,8,13,14,16,26
extern const u8 g_palette[16];
extern const u8 g_palette2[16];
extern const u8 g_palette3[16];

// If we need a global method put here
void waitNVSYNCs(u8 n);
u8* getScreenPosition(u8 x, u8 y);
#endif // _CONSTANTES_
