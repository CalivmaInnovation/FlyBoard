#include "runners.h"

// Variables de Runners
TRunner RunnerCar;
i8 position=0;
u8 car = 0;

void initRunnerCar() {
  RunnerCar.x=19;
  RunnerCar.y=0;
  RunnerCar.speed=0;
  RunnerCar.canColision=0;
}

void drawCars(u16 numCars) {
  u8 str[50];
  cpct_drawSprite(sprite_car, (u8*)0xC08A, 4, 8);
  sprintf(str,"%2d",numCars);
  cpct_drawStringM0 (str, (u8*)0xC090, 0, 7);
}

void throwRunner() {
	u8 rnd, rnd2;

	if (initial_cars == -1) {
		// If no more cars, change status and no throw car
		gameScene = NEXTLEVELSCREEN;
		return;
	} else {
		rnd = cpct_getRandomUniform_u8_f(0);
		rnd2 = cpct_getRandomUniform_u8_f(0);
		if(position==0) {
			cpct_setPalette(g_palette,16);
			if(rnd2 < 50)
				cpct_setPalette(g_palette2,16);
			else if (rnd2 > 150)
				cpct_setPalette(g_palette3,16);

			if (rnd < 100) {
				car = 0;
			} else if (rnd > 100) {
				car = 1;
			}
      if (gameMode) {
        --initial_cars;
        drawCars(initial_cars);
      }
    RunnerCar.canColision=1;
		}
		createRunnerCar(car);
	}
}

void createRunnerCar(u8 posRoad) {
  i8 i;
  u8* z=0;
  // u8 y=(posRoad==0) ? 16 : 21; // 0xc68c;
  u8* memptr=(posRoad==0) ? (u8*)0xc54c : (u8*)0xc6dc; // 0xc68c;
  i8 point=(position<6) ? position : 5;
  i=(position<20) ? 0 : position-19;

  for (i; i<=point; ++i) {
    z=(position<20) ? (u8*) memptr-(4*(position-i)) : (u8*) memptr-(4*position)+(20-(4*(5-i)));
    cpct_drawSprite(sprite_carRunnerSet[i], z, 4, 24);
  }
  // RunnerCar.memptr=z;
  //
  // for (i=0; i<RunnerCar.speed && RunnerCar.x<14; ++i) {
  //   cpct_drawSprite(sprite_carRunnerSet[0], getScreenPosition(RunnerCar.x+5+i, y), 4, 24);
  //   // waitNVSYNCs(5);
  // }
  RunnerCar.y=(posRoad==0) ? 31 : 41;
  RunnerCar.x=(position<20) ? 19-position : 19; // la colision es el morro del coche

  position+=RunnerCar.speed;
  position %= 25;
  if (position==25) {
    position=0;
  }
}

u8 checkColision(u8 pos) {
  if ((pos == RunnerCar.x)
      || (pos == RunnerCar.x+1)
      || (pos == RunnerCar.x+2)
      || (pos == RunnerCar.x+3)
      || (pos == RunnerCar.x+4))
      return 1;
  return 0;
}
