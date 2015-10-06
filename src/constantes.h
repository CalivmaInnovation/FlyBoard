#ifndef _CONSTANTES_
#define _CONSTANTES_

#define SCR_VMEM (u8*)0xC000

#define MAP_WIDTH_TILES          40
#define MAP_HEIGHT_TILES         50

#define TILEWIDTH_BYTES           2
#define TILEHEIGHT_BYTES          4

#define PLAYER_WIDTH_BYTES         4
#define PLAYER_HEIGHT_BYTES        8
#define PLAYER_WIDTH_TILES         2
#define PLAYER_HEIGHT_TILES        2
#define PLAYER_MAX_X     10
#define PLAYER_MIN_X      1
#define PLAYER_MAX_Y     43
#define PLAYER_MIN_Y     33

void waitNVSYNCs(u8 n) {
   do {
      cpct_waitVSYNC();
      if (--n) {
         __asm__ ("halt");
         __asm__ ("halt");
      }
   } while (n);
}

#endif // _CONSTANTES_
