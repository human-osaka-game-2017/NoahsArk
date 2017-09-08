#include "chestnut.h"
#include "char.h"
#include "GameScene.h"
//栗の初期位置
mob chestnut = { 5000.f,0.f,true }; 

mob chestnut2 = { 5000.f,0.f,true }; 

CUSTOMVERTEX drawchestnut[4];
CUSTOMVERTEX drawchestnut2[4];
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
	for (int i = 0; i < 4; i++)
	{
		drawchestnut2[i] = chestnutvertex[i];
		drawchestnut2[i].x += chestnut2.x;
		drawchestnut2[i].y += chestnut2.y;
	}
	
}
	
void initStage2chestnut()
{
	mob chestnut1 = { 875.f,400.f,true };
	chestnut = chestnut1;
	mob chestnut1t = { 1125.f,400.f,true };
	chestnut2 = chestnut1t;
}
void initStage3chestnut()
{
	mob chestnut3 = { 550.f,400.f,true }; //ステージ3
	chestnut = chestnut3;

	mob chestnut4 = { 754.f,400.f,true }; //ステージ3
	chestnut2 = chestnut4;
}

void initStage4chestnut()
{
	mob chestnut5 = { 1240.f,400.f,true }; //ステージ4
	chestnut = chestnut5;
}
void initStage5chestnut()
{
	mob chestnut6 = { 1550.f,400.f,true }; //ステージ6
	chestnut = chestnut6;
}
void initStage6chestnut()
{
	mob chestnut7 = { 250.f,400.f,true }; //ステージ7
	chestnut = chestnut7;
}
void initStage7chestnut()
{
	mob chestnut8 = { 500.f,400.f,true }; //ステージ8
	chestnut = chestnut8;
}
