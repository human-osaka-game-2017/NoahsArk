#ifndef CONTROL
#define CONTROL

#include"char.h"
#include "GameScene.h"

//Šp‰Á‘¬“x
#define ZNGULAR_ACCELERATION 5.f

extern bool DeadFlg;
extern Animal lion;
extern POINT pt;
extern mob tree;
extern mob alligator;
extern Animal elephant;
extern mob chestnut;

void Kaiten(float kakudo, CUSTOMVERTEX src[], CUSTOMVERTEX dest[]);
void Control();
void Cllide();
//void CircleCllide();
#endif
