#include "hole.h"
#include "char.h"
#include "GameScene.h"

mob hole = { 670.f,400.f,true }; //ステージ4
mob hole2 = { 890.f,400.f,true }; //ステージ4
mob hole3 = { 1130.f,400.f,true }; //ステージ4
mob hole4 = { 1350.f,400.f,true }; //ステージ4
mob hole5 = { 400.f,400.f,true }; //ステージ8
mob hole6 = { 700.f,400.f,true }; //ステージ8
mob hole7 = { 900.f,400.f,true }; //ステージ8
mob hole8 = { 1150.f,400.f,true }; //ステージ8

CUSTOMVERTEX drawhole[4];
CUSTOMVERTEX drawhole2[4];
CUSTOMVERTEX drawhole3[4];
CUSTOMVERTEX drawhole4[4];
CUSTOMVERTEX drawhole5[4];
CUSTOMVERTEX drawhole6[4];
CUSTOMVERTEX drawhole7[4];
CUSTOMVERTEX drawhole8[4];

void holedraw()
{
	//	木の頂点情報
	CUSTOMVERTEX  holevertex[4]
	{
		{ - HOLE_W / 2, - HOLE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{   HOLE_W / 2, - HOLE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{   HOLE_W / 2,   HOLE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ - HOLE_W / 2,   HOLE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	//一つ目位置と頂点情報を代入
	for (int i = 0; i < 4; i++)
	{
		drawhole[i] = holevertex[i];
		drawhole[i].x += hole.x;
		drawhole[i].y += hole.y;
	}
	//二つ目位置と頂点情報を代入
	for (int i = 0; i < 4; i++)
	{
		drawhole2[i] = holevertex[i];
		drawhole2[i].x += hole2.x;
		drawhole2[i].y += hole2.y;
	}
	CUSTOMVERTEX  holevertex2[4]
	{
		{ -HOLE_W / 2, -HOLE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ HOLE_W / 2, -HOLE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ HOLE_W / 2,   HOLE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -HOLE_W / 2,   HOLE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	for (int i = 0; i < 4; i++)
	{
		drawhole3[i] = holevertex2[i];
		drawhole3[i].x += hole3.x;
		drawhole3[i].y += hole3.y;
	}
	for (int i = 0; i < 4; i++)
	{
		drawhole4[i] = holevertex2[i];
		drawhole4[i].x += hole4.x;
		drawhole4[i].y += hole4.y;
	}
	CUSTOMVERTEX  holevertex3[4]
	{
		{ -HOLE_W / 2, -HOLE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ HOLE_W / 2, -HOLE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ HOLE_W / 2,   HOLE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -HOLE_W / 2,   HOLE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	for (int i = 0; i < 4; i++)
	{
		drawhole5[i] = holevertex3[i];
		drawhole5[i].x += hole5.x;
		drawhole5[i].y += hole5.y;
	}
	for (int i = 0; i < 4; i++)
	{
		drawhole6[i] = holevertex3[i];
		drawhole6[i].x += hole6.x;
		drawhole6[i].y += hole6.y;
	}
	CUSTOMVERTEX  holevertex4[4]
	{
		{ -HOLE_W / 2, -HOLE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ HOLE_W / 2, -HOLE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ HOLE_W / 2,   HOLE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -HOLE_W / 2,   HOLE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	for (int i = 0; i < 4; i++)
	{
		drawhole7[i] = holevertex4[i];
		drawhole7[i].x += hole7.x;
		drawhole7[i].y += hole7.y;
	}
	for (int i = 0; i < 4; i++)
	{
		drawhole8[i] = holevertex4[i];
		drawhole8[i].x += hole8.x;
		drawhole8[i].y += hole8.y;
	}

}
