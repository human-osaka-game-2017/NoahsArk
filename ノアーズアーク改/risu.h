#ifndef RISU
#define RISU
#include "GameScene.h"
#include "char.h"

#define MOVESPEEDRISU 1.f

#define RISU_W 52.f
#define RISU_H 52.f

extern Animal risu;
//関数呼び出し
void risudraw();

extern CUSTOMVERTEX drawrisu[4];

void initStage2risu();
void initStage3risu();
void initStage4risu();
void initStage5risu();

#endif
