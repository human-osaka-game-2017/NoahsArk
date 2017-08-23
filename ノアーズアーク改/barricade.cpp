#include "barricade.h"
#include "char.h"
#include "GameScene.h"
//��Q���̏����ʒu
mob barricade = { 350.f,400.f,true };   //�X�e�[�W7
mob barricade2 = { 1100.f,400.f,true }; //�X�e�[�W7
mob barricade3 = { 1000.f,400.f,true };   //�X�e�[�W8


CUSTOMVERTEX drawbarricade[4];
CUSTOMVERTEX drawbarricade2[4];
CUSTOMVERTEX drawbarricade3[4];

void barricadedraw()
{
	//	��Q���̒��_���
	CUSTOMVERTEX   barricadevertex[4]
	{
		{ -BARRICADE_W / 2 , -BARRICADE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ BARRICADE_W / 2 , -BARRICADE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ BARRICADE_W / 2 ,  BARRICADE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -BARRICADE_W / 2 ,  BARRICADE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	//�ʒu�ƒ��_������
	for (int i = 0; i < 4; i++)
	{
		drawbarricade[i] = barricadevertex[i];
		drawbarricade[i].x += barricade.x;
		drawbarricade[i].y += barricade.y;
	}
	CUSTOMVERTEX   barricadevertex2[4]
	{
		{ -BARRICADE_W / 2 , -BARRICADE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ BARRICADE_W / 2 , -BARRICADE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ BARRICADE_W / 2 ,  BARRICADE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -BARRICADE_W / 2 ,  BARRICADE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	//�ʒu�ƒ��_������
	for (int i = 0; i < 4; i++)
	{
		drawbarricade2[i] = barricadevertex2[i];
		drawbarricade2[i].x += barricade2.x;
		drawbarricade2[i].y += barricade2.y;
	}
	CUSTOMVERTEX   barricadevertex3[4]
	{
		{ -BARRICADE_W / 2 , -BARRICADE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ BARRICADE_W / 2 , -BARRICADE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ BARRICADE_W / 2 ,  BARRICADE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -BARRICADE_W / 2 ,  BARRICADE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	//�ʒu�ƒ��_������
	for (int i = 0; i < 4; i++)
	{
		drawbarricade3[i] = barricadevertex3[i];
		drawbarricade3[i].x += barricade3.x;
		drawbarricade3[i].y += barricade3.y;
	}
}