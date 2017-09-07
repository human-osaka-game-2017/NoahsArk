#ifndef HOLE
#define HOLE

#include "GameScene.h"
#include "char.h"

#define HOLE_W 60.f
#define HOLE_H 20.f

extern mob hole;
extern mob hole2;
extern mob hole3;
extern mob hole4;
/*extern mob hole5;
extern mob hole6;
extern mob hole7;
extern mob hole8;*/

extern CUSTOMVERTEX drawhole[4];
extern CUSTOMVERTEX drawhole2[4];
extern CUSTOMVERTEX drawhole3[4];
extern CUSTOMVERTEX drawhole4[4];

void holedraw();
void initStage4hole();

#endif 

