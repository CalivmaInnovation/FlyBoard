#include "runners.h"

// Variables de Runners
TRunner RunnerCar;
i8 position=0;

void initRunnerCar() {
  RunnerCar.x=10;
  RunnerCar.y=31;
}

void drawCars(u8 vNumber) {
  u8 str[6];

  // ESTO LO TIENE K DIBUJAR ENEMYS O EL MAPA
  cpct_drawSprite(sprite_car, (u8*)0xC08A, 4, 8);

  sprintf(str,"%u",vNumber);
  cpct_drawStringM0 (str, (u8*)0xC090, 0, 7);
}

void createRunnerCar(u8 posRoad) {
  u8 str[6];
  u8* memptr=(posRoad==0) ? (u8*)0xc54c : (u8*)0xc6dc; // 0xc68c;
  if (position==0) {
    cpct_drawSprite(sprite_carRunnerSet[0], (u8*) memptr, 4, 24);
    ++position;

  } else if (position==1) {
    cpct_drawSprite(sprite_carRunnerSet[0], (u8*) memptr-4, 4, 24);
    cpct_drawSprite(sprite_carRunnerSet[1], (u8*) memptr, 4, 24);
    ++position;
  }
  else if (position==2) {
    cpct_drawSprite(sprite_carRunnerSet[0], (u8*) memptr-8, 4, 24);
    cpct_drawSprite(sprite_carRunnerSet[1], (u8*) memptr-4, 4, 24);
    cpct_drawSprite(sprite_carRunnerSet[2], (u8*) memptr, 4, 24);
    ++position;
  }
  else if (position==3) {
    cpct_drawSprite(sprite_carRunnerSet[0], (u8*) memptr-12, 4, 24);
    cpct_drawSprite(sprite_carRunnerSet[1], (u8*) memptr-8, 4, 24);
    cpct_drawSprite(sprite_carRunnerSet[2], (u8*) memptr-4, 4, 24);
    cpct_drawSprite(sprite_carRunnerSet[3], (u8*) memptr, 4, 24);
    ++position;
  }
  else if (position==4) {
    cpct_drawSprite(sprite_carRunnerSet[0], (u8*) memptr-16, 4, 24);
    cpct_drawSprite(sprite_carRunnerSet[1], (u8*) memptr-12, 4, 24);
    cpct_drawSprite(sprite_carRunnerSet[2], (u8*) memptr-8, 4, 24);
    cpct_drawSprite(sprite_carRunnerSet[3], (u8*) memptr-4, 4, 24);
    cpct_drawSprite(sprite_carRunnerSet[4], (u8*) memptr, 4, 24);
    ++position;
  } else if (position==5){
    cpct_drawSprite(sprite_carRunnerSet[0], (u8*) memptr-20, 4, 24);
    cpct_drawSprite(sprite_carRunnerSet[1], (u8*) memptr-16, 4, 24);
    cpct_drawSprite(sprite_carRunnerSet[2], (u8*) memptr-12, 4, 24);
    cpct_drawSprite(sprite_carRunnerSet[3], (u8*) memptr-8, 4, 24);
    cpct_drawSprite(sprite_carRunnerSet[4], (u8*) memptr-4, 4, 24);
    cpct_drawSprite(sprite_carRunnerShadow, (u8*) memptr, 4, 24);
    ++position;
  } else if  (position<19) {
    cpct_drawSprite(sprite_carRunnerSet[0], (u8*) memptr-(4*position), 4, 24);
    cpct_drawSprite(sprite_carRunnerSet[1], (u8*) memptr-(4*position)+4, 4, 24);
    cpct_drawSprite(sprite_carRunnerSet[2], (u8*) memptr-(4*position)+8, 4, 24);
    cpct_drawSprite(sprite_carRunnerSet[3], (u8*) memptr-(4*position)+12, 4, 24);
    cpct_drawSprite(sprite_carRunnerSet[4], (u8*) memptr-(4*position)+16, 4, 24);
    cpct_drawSprite(sprite_carRunnerShadow, (u8*) memptr-(4*position)+20, 4, 24);
    ++position;
  } else if (position==19) {
    memptr=(posRoad==0) ? (u8*)0xc500 : (u8*)0xc690; // 0xc640;
    cpct_drawSprite(sprite_carRunnerSet[0], (u8*) memptr, 4, 24);
    cpct_drawSprite(sprite_carRunnerSet[1], (u8*) memptr+4, 4, 24);
    cpct_drawSprite(sprite_carRunnerSet[2], (u8*) memptr+8, 4, 24);
    cpct_drawSprite(sprite_carRunnerSet[3], (u8*) memptr+12, 4, 24);
    cpct_drawSprite(sprite_carRunnerSet[4], (u8*) memptr+16, 4, 24);
    cpct_drawSprite(sprite_carRunnerShadow, (u8*) memptr+20, 4, 24);
    ++position;
  } else if (position==20) {
    memptr=(posRoad==0) ? (u8*)0xc500 : (u8*)0xc690; // 0xc640;
    cpct_drawSprite(sprite_carRunnerSet[1], (u8*) memptr, 4, 24);
    cpct_drawSprite(sprite_carRunnerSet[2], (u8*) memptr+4, 4, 24);
    cpct_drawSprite(sprite_carRunnerSet[3], (u8*) memptr+8, 4, 24);
    cpct_drawSprite(sprite_carRunnerSet[4], (u8*) memptr+12, 4, 24);
    cpct_drawSprite(sprite_carRunnerShadow, (u8*) memptr+16, 4, 24);
    ++position;
  }
  else if (position==21) {
    memptr=(posRoad==0) ? (u8*)0xc500 : (u8*)0xc690; // 0xc640;
    cpct_drawSprite(sprite_carRunnerSet[2], (u8*) memptr, 4, 24);
    cpct_drawSprite(sprite_carRunnerSet[3], (u8*) memptr+4, 4, 24);
    cpct_drawSprite(sprite_carRunnerSet[4], (u8*) memptr+8, 4, 24);
    cpct_drawSprite(sprite_carRunnerShadow, (u8*) memptr+12, 4, 24);
    ++position;
  }
  else if (position==22) {
    memptr=(posRoad==0) ? (u8*)0xc500 : (u8*)0xc690; // 0xc640;
    cpct_drawSprite(sprite_carRunnerSet[3], (u8*) memptr, 4, 24);
    cpct_drawSprite(sprite_carRunnerSet[4], (u8*) memptr+4, 4, 24);
    cpct_drawSprite(sprite_carRunnerShadow, (u8*) memptr+8, 4, 24);
    ++position;
  }
  else if (position==23) {
    memptr=(posRoad==0) ? (u8*)0xc500 : (u8*)0xc690; // 0xc640;
    cpct_drawSprite(sprite_carRunnerSet[4], (u8*) memptr, 4, 24);
    cpct_drawSprite(sprite_carRunnerShadow, (u8*) memptr+4, 4, 24);
    ++position;
  }
  else if (position==24) {
    memptr=(posRoad==0) ? (u8*)0xc500 : (u8*)0xc690; // 0xc640;
    cpct_drawSprite(sprite_carRunnerShadow, (u8*) memptr, 4, 24);
    position=0;
  }
  RunnerCar.y=(posRoad==0) ? 31 : 41;
  RunnerCar.x=25-position;
  // 
  // sprintf(str,"%u",RunnerCar.y);
  // cpct_drawStringM0 (str, (u8*)0xc0a4, 0, 4);
  // sprintf(str,"%u",RunnerCar.x);
  // cpct_drawStringM0 (str, (u8*)0xc0a4+12, 0, 4);
  //
  // sprintf(str,"%u",Player.y);
  // cpct_drawStringM0 (str, (u8*)0xc0f4, 0, 4);
  // sprintf(str,"%u",Player.x);
  // cpct_drawStringM0 (str, (u8*)0xc0f4+12, 0, 4);

  // cpct_drawSprite(sprite_carRunnerSet[0], (u8*) memptr-(4*position), 4, 24);
  // ++position;
}
