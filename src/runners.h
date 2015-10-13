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
}TRunner;

extern TRunner RunnerCar;
extern i8 position;

void initRunnerCar();
void throwRunner();
void createRunnerCar(u8 pos);
void drawCars(u8 vNumber);

#endif /* end of include guard: _RUNNERS_H_ */
