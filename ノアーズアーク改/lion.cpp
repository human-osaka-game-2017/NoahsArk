#include "lion.h"
#include "hippopotamus.h"
#include "elephant.h"
#include "mole.h"
#include "risu.h"
#include "GameScene.h"
#include "char.h"

//���C�I���̏����ʒu
Animal lion = { 224.f,400.f,false,true }; //�X�e�[�W3
Animal lion2 = { 435.f,400.f,false,true }; //�X�e�[�W6
Animal lion3 = { 90.f,400.f,false,true }; //�X�e�[�W7
Animal lion4 = { 175.f,400.f,false,true }; //�X�e�[�W7
Animal lion5 = { 450.f,400.f,false,true }; //�X�e�[�W7
Animal lion6 = { 700.f,400.f,false,true }; //�X�e�[�W7
Animal lion7 = { 150.f,400.f,false,true }; //�X�e�[�W8

CUSTOMVERTEX drawlion[4];
CUSTOMVERTEX drawlion2[4];
CUSTOMVERTEX drawlion3[4];
CUSTOMVERTEX drawlion4[4];
CUSTOMVERTEX drawlion5[4];
CUSTOMVERTEX drawlion6[4];
CUSTOMVERTEX drawlion7[4];

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
	//���C�I���̒��_���
	CUSTOMVERTEX  lionvertex2[4]
	{
		{ -LION_W / 2 , -LION_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ LION_W / 2 , -LION_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ LION_W / 2 ,  LION_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -LION_W / 2 ,  LION_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	//�ʒu�ƒ��_����������
	for (int i = 0; i < 4; i++)
	{
		drawlion2[i] = lionvertex2[i];
		drawlion2[i].x += lion2.x;
		drawlion2[i].y += lion2.y;
	}

	//���C�I���̒��_���
	CUSTOMVERTEX  lionvertex3[4]
	{
		{ -LION_W / 2 , -LION_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ LION_W / 2 , -LION_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ LION_W / 2 ,  LION_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -LION_W / 2 ,  LION_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	//�ʒu�ƒ��_����������
	for (int i = 0; i < 4; i++)
	{
		drawlion3[i] = lionvertex3[i];
		drawlion3[i].x += lion3.x;
		drawlion3[i].y += lion3.y;
	}

	//���C�I���̒��_���
	CUSTOMVERTEX  lionvertex4[4]
	{
		{ -LION_W / 2 , -LION_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ LION_W / 2 , -LION_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ LION_W / 2 ,  LION_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -LION_W / 2 ,  LION_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	//�ʒu�ƒ��_����������
	for (int i = 0; i < 4; i++)
	{
		drawlion4[i] = lionvertex4[i];
		drawlion4[i].x += lion4.x;
		drawlion4[i].y += lion4.y;
	}
	//���C�I���̒��_���
	CUSTOMVERTEX  lionvertex5[4]
	{
		{ -LION_W / 2 , -LION_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ LION_W / 2 , -LION_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ LION_W / 2 ,  LION_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -LION_W / 2 ,  LION_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	//�ʒu�ƒ��_����������
	for (int i = 0; i < 4; i++)
	{
		drawlion5[i] = lionvertex5[i];
		drawlion5[i].x += lion5.x;
		drawlion5[i].y += lion5.y;
	}
	//���C�I���̒��_���
	CUSTOMVERTEX  lionvertex6[4]
	{
		{ -LION_W / 2 , -LION_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ LION_W / 2 , -LION_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ LION_W / 2 ,  LION_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -LION_W / 2 ,  LION_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	//�ʒu�ƒ��_����������
	for (int i = 0; i < 4; i++)
	{
		drawlion6[i] = lionvertex6[i];
		drawlion6[i].x += lion6.x;
		drawlion6[i].y += lion6.y;
	}
	//���C�I���̒��_���
	CUSTOMVERTEX  lionvertex7[4]
	{
		{ -LION_W / 2 , -LION_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ LION_W / 2 , -LION_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ LION_W / 2 ,  LION_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -LION_W / 2 ,  LION_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	//�ʒu�ƒ��_����������
	for (int i = 0; i < 4; i++)
	{
		drawlion7[i] = lionvertex7[i];
		drawlion7[i].x += lion7.x;
		drawlion7[i].y += lion7.y;
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
