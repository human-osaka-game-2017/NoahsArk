#include "chestnut.h"
#include "char.h"
#include "GameScene.h"
//栗の初期位置
mob chestnut = { 875.f,400.f,true }; //ステージ2
mob chestnut2 = { 1125.f,400.f,true }; //ステージ2
mob chestnut3 = { 550.f,400.f,true }; //ステージ3
mob chestnut4 = { 754.f,400.f,true }; //ステージ3
mob chestnut5 = { 1240.f,400.f,true }; //ステージ4
mob chestnut6 = { 1250.f,400.f,true }; //ステージ6
mob chestnut7 = { 250.f,400.f,true }; //ステージ8
mob chestnut8 = { 500.f,400.f,true }; //ステージ8

CUSTOMVERTEX drawchestnut[4];
CUSTOMVERTEX drawchestnut2[4];
CUSTOMVERTEX drawchestnut3[4];
CUSTOMVERTEX drawchestnut4[4];
CUSTOMVERTEX drawchestnut5[4];
CUSTOMVERTEX drawchestnut6[4];
CUSTOMVERTEX drawchestnut7[4];
CUSTOMVERTEX drawchestnut8[4];

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
	//	栗の頂点情報
	CUSTOMVERTEX   chestnutvertex2[4]
	{
		{ -CHESTNUT_W / 2 , -CHESTNUT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ CHESTNUT_W / 2 , -CHESTNUT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ CHESTNUT_W / 2 ,  CHESTNUT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -CHESTNUT_W / 2 ,  CHESTNUT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	//位置と頂点情報を代入
	for (int i = 0; i < 4; i++)
	{
		drawchestnut2[i] = chestnutvertex2[i];
		drawchestnut2[i].x += chestnut2.x;
		drawchestnut2[i].y += chestnut2.y;
	}
	CUSTOMVERTEX   chestnutvertex3[4]
	{
		{ -CHESTNUT_W / 2 , -CHESTNUT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ CHESTNUT_W / 2 , -CHESTNUT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ CHESTNUT_W / 2 ,  CHESTNUT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -CHESTNUT_W / 2 ,  CHESTNUT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	//位置と頂点情報を代入
	for (int i = 0; i < 4; i++)
	{
		drawchestnut3[i] = chestnutvertex3[i];
		drawchestnut3[i].x += chestnut3.x;
		drawchestnut3[i].y += chestnut3.y;
	}
	CUSTOMVERTEX   chestnutvertex4[4]
	{
		{ -CHESTNUT_W / 2 , -CHESTNUT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ CHESTNUT_W / 2 , -CHESTNUT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ CHESTNUT_W / 2 ,  CHESTNUT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -CHESTNUT_W / 2 ,  CHESTNUT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	//位置と頂点情報を代入
	for (int i = 0; i < 4; i++)
	{
		drawchestnut4[i] = chestnutvertex4[i];
		drawchestnut4[i].x += chestnut4.x;
		drawchestnut4[i].y += chestnut4.y;
	}
	CUSTOMVERTEX   chestnutvertex5[4]
	{
		{ -CHESTNUT_W / 2 , -CHESTNUT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ CHESTNUT_W / 2 , -CHESTNUT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ CHESTNUT_W / 2 ,  CHESTNUT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -CHESTNUT_W / 2 ,  CHESTNUT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	//位置と頂点情報を代入
	for (int i = 0; i < 4; i++)
	{
		drawchestnut5[i] = chestnutvertex5[i];
		drawchestnut5[i].x += chestnut5.x;
		drawchestnut5[i].y += chestnut5.y;
	}
	CUSTOMVERTEX   chestnutvertex6[4]
	{
		{ -CHESTNUT_W / 2 , -CHESTNUT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ CHESTNUT_W / 2 , -CHESTNUT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ CHESTNUT_W / 2 ,  CHESTNUT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -CHESTNUT_W / 2 ,  CHESTNUT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	//位置と頂点情報を代入
	for (int i = 0; i < 4; i++)
	{
		drawchestnut6[i] = chestnutvertex6[i];
		drawchestnut6[i].x += chestnut6.x;
		drawchestnut6[i].y += chestnut6.y;
	}
	CUSTOMVERTEX   chestnutvertex7[4]
	{
		{ -CHESTNUT_W / 2 , -CHESTNUT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ CHESTNUT_W / 2 , -CHESTNUT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ CHESTNUT_W / 2 ,  CHESTNUT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -CHESTNUT_W / 2 ,  CHESTNUT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	//位置と頂点情報を代入
	for (int i = 0; i < 4; i++)
	{
		drawchestnut7[i] = chestnutvertex7[i];
		drawchestnut7[i].x += chestnut7.x;
		drawchestnut7[i].y += chestnut7.y;
	}
	CUSTOMVERTEX   chestnutvertex8[4]
	{
		{ -CHESTNUT_W / 2 , -CHESTNUT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ CHESTNUT_W / 2 , -CHESTNUT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ CHESTNUT_W / 2 ,  CHESTNUT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -CHESTNUT_W / 2 ,  CHESTNUT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	//位置と頂点情報を代入
	for (int i = 0; i < 4; i++)
	{
		drawchestnut8[i] = chestnutvertex8[i];
		drawchestnut8[i].x += chestnut8.x;
		drawchestnut8[i].y += chestnut8.y;
	}
}