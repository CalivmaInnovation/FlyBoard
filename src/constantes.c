#include "constantes.h"

const u8 g_palette[7] = {0x14, 0x1C, 0x0D, 0x00, 0x1F, 0x07, 0x0B};

void waitNVSYNCs(u8 n) {
   do {
      cpct_waitVSYNC();
      if (--n) {
         __asm__ ("halt");
         __asm__ ("halt");
      }
   } while (n);
}
