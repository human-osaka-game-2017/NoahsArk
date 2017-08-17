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
//ä÷êîåƒÇ—èoÇµ
void hippopotamusdraw(int time);

extern CUSTOMVERTEX drawHippopotamus[4];

#endif