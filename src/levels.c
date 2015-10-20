#include "levels.h"

u8 level = 0;


void drawWorldLevel() {
	u8 str[6];
	sprintf(str, "%u", level);
	cpct_drawStringM0 ("LEVEL", (u8*)0xC069, 0, 7);
	cpct_drawStringM0 (str, (u8*)0xC07F, 0, 7);

}

void initLevel() {
	++level;
}

void nextLevel() {
	initial_cars += 5 + old_initial_cars;//cpct_getRandomUniform_u8_f(5);
	old_initial_cars = initial_cars;
	RunnerCar.speed += 1 + RunnerCar.ospeed;
	RunnerCar.ospeed = RunnerCar.speed;
	drawWorldLevel();
	drawCars(initial_cars);
	gameScene=PLAYGAMESCREEN;
}
