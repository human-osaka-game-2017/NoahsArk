#ifndef RISU
#define RISU
#include "GameScene.h"
#include "char.h"

#define MOVESPEEDRISU 2.f

#define RISU_W 52.f
#define RISU_H 52.f

extern bool RisuDeadFlg;

extern bool g_MoveRisu;

extern Animal risu;
extern Animal risu2;
extern Animal risu3;
extern Animal risu4;
extern Animal risu5;
//ä÷êîåƒÇ—èoÇµ
void risudraw(int time);

extern CUSTOMVERTEX drawrisu[4];
extern CUSTOMVERTEX drawrisu2[4];
extern CUSTOMVERTEX drawrisu3[4];
extern CUSTOMVERTEX drawrisu4[4];
extern CUSTOMVERTEX drawrisu5[4];


#endif
