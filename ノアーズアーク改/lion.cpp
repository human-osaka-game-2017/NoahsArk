#include "lion.h"
#include "hippopotamus.h"
#include "elephant.h"
#include "mole.h"
#include "risu.h"
#include "GameScene.h"
#include "char.h"

//���C�I���̏����ʒu
Animal lion = { -100.f,400.f,false,true };

CUSTOMVERTEX drawLion[4];

bool g_MoveLion = true;

void liondraw(int time)
{
	//���C�I���̒��_���
	CUSTOMVERTEX  lionvertex[4]
	{
		{ -LION_W / 2 ,-LION_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{  LION_W / 2 ,-LION_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{  LION_W / 2 ,  LION_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -LION_W / 2 ,  LION_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	//�ʒu�ƒ��_����������
	for (int i = 0; i < 4; i++)
	{
		drawLion[i] = lionvertex[i];
		drawLion[i].x += lion.x;
		drawLion[i].y += lion.y;
	}

	if (g_MoveLion && time > 3000)
	{
		lion.x += MOVESPEEDLION;
	}

	if (lion.x >= hippopotamus.x - HIPPOPOTAMUS_W)
	{
		hippopotamus.x += PLUSMOVESPEED;
	}

	if (lion.x >= elephant.x - ELEPHANT_W)
	{
		elephant.x += PLUSMOVESPEED;
	}

	if (lion.x >= mole.x - MOLE_W)
	{
		mole.x += PLUSMOVESPEED;
		MolePlusSpeed = true;
	}



}
