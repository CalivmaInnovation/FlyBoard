#include "constantes.h"

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
