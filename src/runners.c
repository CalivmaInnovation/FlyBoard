#include "runners.h"

// Variables de Runners
TRunner RunnerCar;

void initRunnerCar() {
  RunnerCar.x=10;
  RunnerCar.y=0;
}

void drawCars(u8 vNumber) {
  u8 str[6];

  // ESTO LO TIENE K DIBUJAR ENEMYS O EL MAPA
  cpct_drawSprite(sprite_car, (u8*)0xC08A, 4, 8);

  sprintf(str,"%u",vNumber);
  cpct_drawStringM0 (str, (u8*)0xC090, 0, 4);
}

void createRunnerCar(u8 pos) {
  u8* memptr=(pos==0) ? 0xc580 : 0xc710;

}

void runnerCar() {
  u8* memptr;
  memptr = cpct_getScreenPtr(SCR_VMEM, RUNNERCAR_WIDTH*RunnerCar.x, RUNNERCAR_HEIHGT*RunnerCar.y);
  cpct_drawSprite(sprite_carRunner, memptr, RUNNERCAR_WIDTH, RUNNERCAR_HEIHGT);
}
