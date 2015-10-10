#include "constantes.h"

const u8 g_palette[16] = { 0, 2, 3, 5, 6, 9, 11, 13, 14, 15, 16, 18, 20, 22, 24, 26 }; // {0x14, 0x1C, 0x0D, 0x00, 0x1F, 0x07, 0x0B};

void waitNVSYNCs(u8 n) {
   do {
      cpct_waitVSYNC();
      if (--n) {
         __asm__ ("halt");
         __asm__ ("halt");
      }
   } while (n);
}
