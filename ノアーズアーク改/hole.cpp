#include "hole.h"
#include "char.h"
#include "GameScene.h"

mob hole = { 500.f,400.f,true };
mob hole2 = { 700.f,400.f,true };

//���
CUSTOMVERTEX drawhole[4];
//���
CUSTOMVERTEX drawhole2[4];

void holedraw()
{
	//	�؂̒��_���
	CUSTOMVERTEX  holevertex[4]
	{
		{ - HOLE_W / 2, - HOLE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{   HOLE_W / 2, - HOLE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{   HOLE_W / 2,   HOLE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ - HOLE_W / 2,   HOLE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	//��ڈʒu�ƒ��_������
	for (int i = 0; i < 4; i++)
	{
		drawhole[i] = holevertex[i];
		drawhole[i].x += hole.x;
		drawhole[i].y += hole.y;
	}
	//��ڈʒu�ƒ��_������
	for (int i = 0; i < 4; i++)
	{
		drawhole2[i] = holevertex[i];
		drawhole2[i].x += hole2.x;
		drawhole2[i].y += hole2.y;
	}
}
