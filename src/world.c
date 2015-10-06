#include "world.h"

// Variables World
u8 buildX;
u8 buildY;
// ////////////////

void initBuild() {
  buildX = 65;
  buildY = 20;
}

void drawBuild() {
  u8* memptr;

  buildX-=1;
  if (buildX==BUILD_MIN_X) {
    buildX=BUILD_MAX_X;
  }
  // memptr = cpct_getScreenPtr(SCR_VMEM, buildX, buildY);
  // cpct_drawSprite (build_build, memptr, BUILD_WIDTH_BYTES, BUILD_HEIGHT_BYTES);
  // memptr = cpct_getScreenPtr(SCR_VMEM, buildX+15, buildY);
  // cpct_drawSprite (buildShadow_buildShadow, memptr, 0, BUILD_HEIGHT_BYTES);
  //
	// cpct_waitVSYNC();
}

void initWorld() {
  initBuild();
}

void world1() {
  drawBuild();
}
