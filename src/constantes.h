#ifndef _CONSTANTES_
#define _CONSTANTES_

#define SCR_VMEM (u8*)0xC000

#define MODE0_HEIGHT 190
#define MODE0_WIDTH 75

#define MAP_WIDTH_TILES          40
#define MAP_HEIGHT_TILES         50
#define ROAD_WIDTH_BYTES         8
#define ROAD_HEIGHT_BYTES        8
#define ROAD_WIDTH_TILES         ROAD_WIDTH_BYTES/2
#define ROAD_HEIGHT_TILES        ROAD_HEIGHT_BYTES/4

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

#endif // _CONSTANTES_
