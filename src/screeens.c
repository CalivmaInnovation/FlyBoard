#include "screens.h"

u8 gameSceene;

void calivGames() {
  u8* memptr=0xC058;
  u8 i=0;
  cpct_memset(SCR_VMEM, 0x33, 0x4000);
  cpct_drawSprite(g_tile_black, (u8*)memptr+(i*4), 4, 8);
  ++i;
  cpct_drawSprite(g_tile_black, (u8*)memptr+(i*4), 4, 8);
  ++i;
  ++i;
  cpct_drawSprite(g_tile_black, (u8*)memptr+(i*4), 4, 8);
  ++i;
  ++i;
  cpct_drawSprite(g_tile_black, (u8*)memptr+(i*4), 4, 8);
  ++i;
  ++i;
  cpct_drawSprite(g_tile_black, (u8*)memptr+(i*4), 4, 8);
  ++i;
  ++i;
  cpct_drawSprite(g_tile_black, (u8*)memptr+(i*4), 4, 8);
  ++i;
  ++i;
  ++i;
  cpct_drawSprite(g_tile_black, (u8*)memptr+(i*4), 4, 8);
  memptr+=0xc050;

  waitNVSYNCs(2000);
  gameSceene=MAINLOP;
}

void mainMenu() {

}
