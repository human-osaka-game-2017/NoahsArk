#ifndef HIPPOPOTAMUS
#define HIPPOPOTAMUS

#include "GameScene.h"
#include "char.h"

#define MOVESPEEDHIPPOPOTAMUS 1.f

#define HIPPOPOTAMUS_W 78.f
#define HIPPOPOTAMUS_H 78.f

extern Animal hippopotamus;
//ä÷êîåƒÇ—èoÇµ
void hippopotamusdraw();
void initStage1hippopotamus();
void initStage2hippopotamus();
void initStage3hippopotamus();
void initStage5hippopotamus();
void initStage7hippopotamus();
extern CUSTOMVERTEX drawhippopotamus[4];
#endif