#ifndef _SCROLL_H_
#define _SCROLL_H_

#include <cpctelera.h>
#include "tiles.h"

void initScroll();
void widthImageScroll(u8 tile[], u8 shadowTile[], i8 posY, u8 widthImage);
void Road();
void scroll(u8 tile[], u8 shadowTile[], i8 posX, i8 posY, i8 nextLine);


#endif /* end of include guard: _SCROLL_H_ */
