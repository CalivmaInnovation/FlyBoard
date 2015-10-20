#ifndef _RUNNERS_H_
#define _RUNNERS_H_

#include <stdio.h>

#include "constantes.h"
#include "world.h"

#define RUNNERCAR_WIDTH 20
#define RUNNERCAR_HEIHGT 40

typedef struct {
  u8 x;
  u8 y;
  u8* memptr;
  i8 ospeed;
  i8 speed;
}TRunner;

extern TRunner RunnerCar;
extern i8 position;

void initRunnerCar();
void throwRunner();
void createRunnerCar(u8 pos);
void drawCars(u16 vNumber);

#endif /* end of include guard: _RUNNERS_H_ */
