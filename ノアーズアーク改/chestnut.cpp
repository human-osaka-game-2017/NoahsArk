#include "chestnut.h"
#include "char.h"
#include "GameScene.h"
//栗の初期位置
mob chestnut = { 550.f,381.f,true };   //栗(障害物)

CUSTOMVERTEX drawchestnut[4];

void chestnutdraw()
{
	//	栗の頂点情報
	CUSTOMVERTEX   chestnutvertex[4]
	{
		{ -CHESTNUT_W / 2 , -CHESTNUT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ CHESTNUT_W / 2 , -CHESTNUT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ CHESTNUT_W / 2 ,  CHESTNUT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -CHESTNUT_W / 2 ,  CHESTNUT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	//位置と頂点情報を代入
	for (int i = 0; i < 4; i++)
	{
		drawchestnut[i] = chestnutvertex[i];
		drawchestnut[i].x += chestnut.x;
		drawchestnut[i].y += chestnut.y;
	}
}