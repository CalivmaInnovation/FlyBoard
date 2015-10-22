#include "game.h"
#include "music.c"

u8 gameMode;

void initGame() {
	initWorld();
	initPlayer();
	drawLifes();
	initRunnerCar();
}

void infinityMode() {
	/* TODO:  Make a mode for throw random speeds */
	gameMode = 0;
	initGame();
	RunnerCar.speed = 1;
	cpct_drawStringM0 ("INFINITY MODE", (u8*)0xC068, 0, 7);
	while(gameScene==PLAYGAMESCREEN) {
		waitNVSYNCs(1);
		cpct_akp_musicPlay();
		computeWorld();
		player();
		throwRunner();
		drawPlayer();
		// Synchronize with VSYNC + 1 HSYNC to slow down the movement
		waitNVSYNCs(2);
	}
	cpct_akp_stop();
}

void levelMode() {
	gameMode = 1;
	initGame();
	nextLevel();
	while(gameScene==PLAYGAMESCREEN) {
		waitNVSYNCs(1);
		cpct_akp_musicPlay();
		computeWorld();
		player();
		throwRunner();
		drawPlayer();
		// Synchronize with VSYNC + 1 HSYNC to slow down the movement
		waitNVSYNCs(2);
	}
	cpct_akp_stop();
}
