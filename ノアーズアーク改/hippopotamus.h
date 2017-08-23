#ifndef HIPPOPOTAMUS
#define HIPPOPOTAMUS

#include "GameScene.h"
#include "char.h"

#define MOVESPEEDHIPPOPOTAMUS 2.f

#define HIPPOPOTAMUS_W 78.f
#define HIPPOPOTAMUS_H 78.f

extern bool hippopotamusDeadFlg;

extern bool g_MoveHippopotamus;

extern Animal hippopotamus;
extern Animal hippopotamus2;
//ä÷êîåƒÇ—èoÇµ
void hippopotamusdraw(int time);

extern CUSTOMVERTEX drawhippopotamus[4];
extern CUSTOMVERTEX drawhippopotamus2[4];

#endif