#include "levels.h"

u8 level = 5;

void drawWorldLevel() {
	u8 str[6];
	sprintf(str, "%u", level);
	cpct_drawStringM0 ("LEVEL", (u8*)0xC069, 0, 7);
	cpct_drawStringM0 (str, (u8*)0xC07F, 0, 7);

}

void initLevel() {
//	level = 5;
	++level;
}

void nextLevel() {
	initial_cars = 5 * level;
	RunnerCar.speed = level;
	drawWorldLevel();
	drawCars(initial_cars);
	gameScene=PLAYGAMESCREEN;
}

void gameOverLevel() {
	level = 0;
}
