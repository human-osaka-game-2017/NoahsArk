#include "chestnut.h"
#include "char.h"
#include "GameScene.h"
//�I�̏����ʒu
mob chestnut = { 550.f,381.f,true };   //�I(��Q��)

CUSTOMVERTEX drawchestnut[4];

void chestnutdraw()
{
	//	�I�̒��_���
	CUSTOMVERTEX   chestnutvertex[4]
	{
		{ -CHESTNUT_W / 2 , -CHESTNUT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ CHESTNUT_W / 2 , -CHESTNUT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ CHESTNUT_W / 2 ,  CHESTNUT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -CHESTNUT_W / 2 ,  CHESTNUT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	//�ʒu�ƒ��_������
	for (int i = 0; i < 4; i++)
	{
		drawchestnut[i] = chestnutvertex[i];
		drawchestnut[i].x += chestnut.x;
		drawchestnut[i].y += chestnut.y;
	}
}