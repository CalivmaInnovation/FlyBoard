#ifndef _RUNNERS_H_
#define _RUNNERS_H_

#include "constantes.h"
#include <stdio.h>


#define RUNNERCAR_WIDTH 20
#define RUNNERCAR_HEIHGT 40


typedef struct {
  u8 x;
  u8 y;
}TRunner;


void initRunnerCar();
void createRunnerCar(u8 pos);
void drawCars(u8 vNumber);
void runnerCar();

#endif /* end of include guard: _RUNNERS_H_ */
