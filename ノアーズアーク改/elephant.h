#ifndef ELEPHANT
#define ELEPHANT

#include "GameScene.h"
#include "char.h"

#define MOVESPEEDELEPHANT 2.f

#define ELEPHANT_W 104.f
#define ELEPHANT_H 104.f
//ä÷êîåƒÇ—èoÇµ
void elephantdraw(int time);

extern bool g_Moveelephant;

extern bool ElephantDeadFlg;

extern Animal elephant;

extern CUSTOMVERTEX drawelephant[4];

#endif 

