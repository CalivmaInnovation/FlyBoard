#include "scroll.h"

// VARIABLES SCROLL
i8 cx, cy;
///////////////////////

void initScroll() {
  cx=0;
  cy=0;
}


void scroll(u8 tile[], /*u8 shadowTile[],*/ u8 tallTille, i8 posX, i8 posY, i8 nextLine) {
	i8 position;
	position = (posX+cx) % 20;
	cpct_drawSprite(tile, (u8*)0xc04c-(4*position) + 0x0050*posY, 4, tallTille);

	// if (position==0) {
	// 	cpct_drawSprite(shadowTile, (u8*)0xc000 + 0x50*posY, 4, 8);
	// } else {
	// 	cpct_drawSprite(shadowTile, (u8*)0xc04c-(4*position)+4 + 0x50*posY, 4, 8);
	// }

	if (nextLine>0) { ++cx; }
	if (cx>20) { cx=0; }
}

void Road() {
	u8 i=19;
	u8 posY=19;

  scroll(g_tile_black, 8, i, posY,-1);
  --i;
	scroll(g_tile_roadLine, 8, i, posY,-1);
	--i;
	scroll(g_tile_roadLine, 8, i, posY,-1);
	--i;
	scroll(g_tile_roadLine, 8, i, posY,-1);
	--i;
  scroll(g_tile_black, 8, i, posY,-1);
	--i;
	scroll(g_tile_roadLine, 8, i, posY,-1);
	--i;
	scroll(g_tile_roadLine, 8, i, posY,-1);
	--i;
	scroll(g_tile_roadLine, 8, i, posY,-1);
	--i;
  scroll(g_tile_black, 8, i, posY,-1);
	--i;
	scroll(g_tile_roadLine, 8, i, posY,-1);
	--i;
	scroll(g_tile_roadLine, 8, i, posY,-1);
	--i;
	scroll(g_tile_roadLine, 8, i, posY,-1);
	--i;
  scroll(g_tile_black, 8, i, posY,-1);
	--i;
	scroll(g_tile_roadLine, 8, i, posY,-1);
	--i;
	scroll(g_tile_roadLine, 8, i, posY,-1);
	--i;
	scroll(g_tile_roadLine, 8, i, posY,-1);
	--i;
  scroll(g_tile_black, 8, i, posY,-1);
	--i;
	scroll(g_tile_roadLine, 8, i, posY,-1);
	--i;
	scroll(g_tile_roadLine, 8, i, posY,-1);
	--i;
	scroll(g_tile_roadLine, 8, i, posY,1);
}

void Building() {
  u8 i=10;
  makeWall(i);
  // --i;
  // makeWall(i);
  // --i;
  // makeWall(i);
  // --i;
  // makeWall(i);
  // --i;
  // makeWall(i);
  // --i;
  // makeWall(i);
  // --i;
  // makeWall(i);
  // --i;
  // makeWall(i);
  // --i;
  // makeWall(i);
}

void makeWall(u8 positionY) {
  u8 i=19;
  scroll(g_tile_wall32, 32, i, positionY,-1);
  --i;
  scroll(g_tile_wallwindow32, 32, i, positionY,-1);
  --i;
  scroll(g_tile_wall32, 32, i, positionY,-1);
  --i;
  scroll(g_tile_wallShadow, 32, i, positionY,-1);

  i=10;
  scroll(g_tile_wall32, 32, i, positionY,-1);
  --i;
  scroll(g_tile_wall32, 32, i, positionY,-1);
  // --i;
  // scroll(g_tile_wallShadow, 32, i, positionY,-1);

  --i;
  scroll(g_tile_wall64, 64, i, positionY-4,-1);
  --i;
  scroll(g_tile_wallwindow64, 64, i, positionY-4,-1);
  --i;
  scroll(g_tile_wall64, 64, i, positionY-4,-1);
  --i;
  scroll(g_tile_wallwindow64, 64, i, positionY-4,-1);
  --i;
  scroll(g_tile_wall64, 64, i, positionY-4,-1);
  --i;
  scroll(g_tile_wallShadow2, 64, i, positionY-4,-1);
}
