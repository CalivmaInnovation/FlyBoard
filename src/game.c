#include "game.h"

u8 gameMode;

void initGame() {
	initWorld();
	initPlayer();
	drawLifes();
	initRunnerCar();
}

void infinityMode() {
	/* Make a mode for throw random speeds */
	gameMode = 0;
	initGame();
	cpct_drawStringM0 ("INFINITY MODE", (u8*)0xC068, 0, 7);
	while(gameScene==PLAYGAMESCREEN) {
		waitNVSYNCs(1);
		computeWorld();
		player();
		throwRunner();
		drawPlayer();
		// Synchronize with VSYNC + 1 HSYNC to slow down the movement
		waitNVSYNCs(2);
	}	
}

void levelMode() {
	gameMode = 1;
	initGame();
	initial_cars = 10;
	drawWorldLevel(1);
	drawCars(initial_cars);
	while(gameScene==PLAYGAMESCREEN) {
		waitNVSYNCs(1);
		computeWorld();
		player();
		throwRunner();
		drawPlayer();
		// Synchronize with VSYNC + 1 HSYNC to slow down the movement
		waitNVSYNCs(2);
	}
}
