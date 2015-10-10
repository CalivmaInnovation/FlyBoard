#ifndef _SCROLL_H_
#define _SCROLL_H_

#include "constantes.h"

void initScroll();
void scroll(u8 tile[], /*u8 shadowTile[],*/ u8 tallTille, i8 posX, i8 posY, i8 nextLine);
void Road();
void Building();
void makeWall(u8 positionY);

#endif /* end of include guard: _SCROLL_H_ */
