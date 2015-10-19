#include "game.h"

void initGame() {
	initWorld();
	initPlayer();
	drawLifes();
}

void mainLoop() {
	initGame();
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
