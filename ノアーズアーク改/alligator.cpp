#include "alligator.h"
#include "char.h"
#include "GameScene.h"
//���j�̏����ʒu
mob alligator = { 5000.f,0.f,true };   //�X�e�[�W1

CUSTOMVERTEX drawalligator[4];

void alligatordraw()
{
	//	���j�̒��_���
	CUSTOMVERTEX   alligatorvertex[4]
	{
		{ -ALLIGATOR_W / 2 , -ALLIGATOR_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ ALLIGATOR_W / 2 , -ALLIGATOR_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ ALLIGATOR_W / 2 ,  ALLIGATOR_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -ALLIGATOR_W / 2 ,  ALLIGATOR_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	//�ʒu�ƒ��_������
	for (int i = 0; i < 4; i++)
	{
		drawalligator[i] = alligatorvertex[i];
		drawalligator[i].x += alligator.x;
		drawalligator[i].y += alligator.y;
	}
}
void initStage1alligator()
{
	mob alligator1 = { 971.f,410.f,true };   //�X�e�[�W1
	alligator = alligator1;
}
void initStage5alligator()
{
	mob alligator2 = { 1250.f,410.f,true };   //�X�e�[�W1
	alligator = alligator2;
}
void initStage7alligator()
{
	mob alligator4 = {1900.f,410.f,true };   //�X�e�[�W1
	alligator = alligator4;
}