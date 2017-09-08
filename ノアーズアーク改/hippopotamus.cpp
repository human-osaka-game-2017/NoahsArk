#include "hippopotamus.h"
#include "alligator.h"
#include "lion.h"
#include "char.h"
#include "GameScene.h"
#include "Control.h"
#include "finish.h"
#include "hole.h"
#include "systemCount.h"
#include "gameSceneControl.h"
//�J�o�̏����ʒu

Animal hippopotamus = { 0.f,0.f,false,true,true,false,false,0.f,0.f }; //�X�e�[�W1

CUSTOMVERTEX drawhippopotamus[4];

void hippopotamusdraw()
{
	//�J�o�̒��_���
	CUSTOMVERTEX  hippopotamusvertex[4]
	{
		{ -HIPPOPOTAMUS_W / 2 ,- HIPPOPOTAMUS_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{  HIPPOPOTAMUS_W / 2 ,- HIPPOPOTAMUS_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{  HIPPOPOTAMUS_W / 2 ,  HIPPOPOTAMUS_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -HIPPOPOTAMUS_W / 2 ,  HIPPOPOTAMUS_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	//�ʒu�ƒ��_����������
	for (int i = 0; i < 4; i++)
	{
		drawhippopotamus[i] = hippopotamusvertex[i];
		drawhippopotamus[i].x += hippopotamus.x;
		drawhippopotamus[i].y += hippopotamus.y;
	}

	if (hippopotamus.Skip > 0)
	{
		hippopotamus.Skip--;
		hippopotamus.x += (PLUSMOVESPEED + MOVESPEEDHIPPOPOTAMUS);
		hippopotamus.movement += (PLUSMOVESPEED + MOVESPEEDHIPPOPOTAMUS);
	}
	if (hippopotamus.Move && count > 180 && hippopotamus.Skip == 0)
	{
		hippopotamus.x += MOVESPEEDHIPPOPOTAMUS;
		hippopotamus.movement += MOVESPEEDHIPPOPOTAMUS;
	}
	
	//�����J�o�f�b�g�t���O�������Ă����璆�ɓ���
	if (hippopotamus.Dead)
	{
		static float angle = 15.f;

		hippopotamus.Move = false;

		angle += 15.f;
		if (angle >= 180)
		{
			angle = 180.f;
		}
		//�֐��Ăяo��
		Kaiten(-angle, hippopotamusvertex, drawhippopotamus);

		for (int i = 0; i < 4; i++)
		{
			//lion.x -= DEADMOVESPEED_W;
			//lion.y -= DEADMOVESPEED_H;
			drawhippopotamus[i].x += hippopotamus.x;
			drawhippopotamus[i].y += hippopotamus.y;
		}

	}
	//�����J�o�����j�̍��ɓ������Ă�����
	if (hippopotamus.x >= alligator.x - ALLIGATOR_W)
	{
		//���j������
		alligator.Active = false;
	}
	
	if (stageProgres < hippopotamus.movement)
	{
		hippopotamus.Active = false;
	}
}
void initStage1hippopotamus()
{
	Animal hippopotamus1 = { 263.f,400.f,false,true,true,false,false,0.f,263.f }; //�X�e�[�W1
	hippopotamus = hippopotamus1;
}
void initStage2hippopotamus()
{
	Animal hippopotamus2 = { 265.f,400.f,false,true,true,false,false,0.f,265.f }; //�X�e�[�W2
	hippopotamus = hippopotamus2;
}

void initStage3hippopotamus()
{
	Animal hippopotamus3 = { 224.f,400.f,false,true,true,false,false,0.f,224.f }; //�X�e�[�W3
	hippopotamus = hippopotamus3;
}

void initStage5hippopotamus()
{
	Animal hippopotamus5 = { 350.f,400.f,false,true,true,false,false,0.f,350.f };
	hippopotamus = hippopotamus5;
}