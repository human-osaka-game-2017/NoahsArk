#include "hole.h"
#include "char.h"
#include "GameScene.h"

mob hole = { 5000.f,0.f,true }; 
mob hole2 = { 5000.f,0.f,true }; 
mob hole3 = { 5000.f,0.f,true }; 
mob hole4 = { 5000.f,0.f,true }; 
/*mob hole5 = { 400.f,400.f,true }; 
mob hole6 = { 700.f,400.f,true }; 
mob hole7 = { 900.f,400.f,true };
mob hole8 = { 1150.f,400.f,true };*/

CUSTOMVERTEX drawhole[4];
CUSTOMVERTEX drawhole2[4];
CUSTOMVERTEX drawhole3[4];
CUSTOMVERTEX drawhole4[4];

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
	
	for (int i = 0; i < 4; i++)
	{
		drawhole3[i] = holevertex[i];
		drawhole3[i].x += hole3.x;
		drawhole3[i].y += hole3.y;
	}
	for (int i = 0; i < 4; i++)
	{
		drawhole4[i] = holevertex[i];
		drawhole4[i].x += hole4.x;
		drawhole4[i].y += hole4.y;
	}
	

}
void initStage4hole()
{
	mob hole4_1 = { 670.f,430.f,true };
	hole = hole4_1;
	mob hole4_2 = { 890.f,430.f,true };
	hole2 = hole4_2;
	mob hole4_3 = { 1130.f,430.f,true };
	hole3 = hole4_3;
	mob hole4_4 = { 1350.f,430.f,true };
	hole4 = hole4_4;
}
void initStage5hole()
{
	mob hole5_1 = { 1450.f,430.f,true };
	hole = hole5_1;
	mob hole5_2 = { 1850.f,430.f,true };
	hole2 = hole5_2;
}
void initStage7hole()
{
	mob hole7_1 = { 1500.f,430.f,true };
	hole = hole7_1;
	mob hole7_2 = { 2000.f,430.f,true };
	hole2 = hole7_2;
}