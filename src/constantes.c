#include "constantes.h"
#include "game.h"
const u8 g_palette[16] = { 0, 2, 3, 5, 6, 8, 9, 11, 13, 14, 15, 16, 20, 22, 24, 26 };
const u8 g_palette2[16] = { 0, 2, 3, 5, 9, 8, 9, 11, 13, 14, 15, 16, 20, 22, 24, 26 };
const u8 g_palette3[16] = { 0, 2, 3, 5, 5, 8, 9, 11, 13, 14, 15, 16, 20, 22, 24, 26 };

void waitNVSYNCs(u8 n) {
   do {
      cpct_waitVSYNC();
      if (--n) {
         __asm__ ("halt");
         __asm__ ("halt");
      }
   } while (n);
}

void stopGame() {
	u8 *memptr;
	cpct_scanKeyboard_f();
	while(!cpct_isKeyPressed(Key_Esc)) {
		cpct_memset(SCR_VMEM, 0x33, 0x4000);
		memptr = cpct_getScreenPtr(SCR_VMEM, 40, 50);
		cpct_drawStringM0 ("PAUSE", memptr, 0, 7);
		waitNVSYNCs(3000);
		cpct_drawStringM0 ("     ", memptr, 0, 7);
		cpct_scanKeyboard_f();
	}
	initGame();
}
