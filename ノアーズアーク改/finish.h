#ifndef FINISH
#define FINISH

#include "Control.h"
#include "GameScene.h"

#define DEADMOVESPEED_W 7.f
#define DEADMOVESPEED_H 3.f
extern bool finishFlg;

extern CUSTOMVERTEX gameoverGrounddraw[4];

extern CUSTOMVERTEX gameclearGrounddraw[4];

void finishSceneDraw(int time);

#endif 

