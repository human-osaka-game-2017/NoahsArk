#include "risu.h"
#include "chestnut.h"
#include "char.h"
#include "GameScene.h"
#include "Control.h"
#include "finish.h"
#include "hole.h"
#include "systemCount.h"
#include "lion.h"
#include "chestnut.h"
#include "gameSceneControl.h"
//���X�̏����ʒu
Animal risu = { 0.f,0.f,false,true,true,false,false,0.f,0.f }; //�X�e�[�W2
//Animal risu5 = { 90.f,400.f,false,true }; //�X�e�[�W8

CUSTOMVERTEX drawrisu[4];
void risudraw()
{
	//���X�̒��_���
	CUSTOMVERTEX  risuvertex[4]
	{
		{ -RISU_W / 2 , -RISU_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ RISU_W / 2 , -RISU_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ RISU_W / 2 ,  RISU_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -RISU_W / 2 ,  RISU_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	//�ʒu�ƒ��_����������
	for (int i = 0; i < 4; i++)
	{
		drawrisu[i] = risuvertex[i];
		drawrisu[i].x += risu.x;
		drawrisu[i].y += risu.y;
	}
	
	if (risu.Skip > 0)
	{
		risu.Skip--;
		risu.x += (PLUSMOVESPEED+MOVESPEEDRISU);
		risu.movement += (PLUSMOVESPEED + MOVESPEEDRISU);
	}
	if (risu.Move && count > 180 && risu.Skip == 0)
	{
		risu.x += MOVESPEEDRISU;
		risu.movement += MOVESPEEDRISU;
	}
	//�������X���I�̍��ɓ������Ă�����
	if (risu.x >= chestnut.x - CHESTNUT_W && risu.y >= chestnut.y)
	{
		//�؂�����
		chestnut.Active = false;
	}//�������X���I�Q�̍��ɓ������Ă�����
	if (risu.x >= chestnut2.x - CHESTNUT_W && risu.y >= chestnut.y)
	{
		//�؂�����
		chestnut2.Active = false;
	}
	//���X�����ɓ������Ă�����ړ�����
	if (hole.Active && risu.Skip == false)
	{
		//�������O������O�̌��ɓ������Ă�����
		if (hole.x == risu.x)
		{
			risu.Active = false;
			risu.y += 50.f;
		}
	}
	//�������̌��ɓ������Ă�����
	if (risu.x == hole2.x)
	{
		risu.Active = true;
		risu.y += 50.f;
	}
	//���X�����ɓ������Ă�����ړ�����
	if (hole3.Active && risu.Skip == false)
	{
		//�������O������O�̌��ɓ������Ă�����
		if (hole3.x == risu.x)
		{
			risu.Active = false;
			risu.y += 50.f;
		}
	}
	//�������̌��ɓ������Ă�����
	if (risu.x == hole4.x)
	{
		risu.Active = true;
		risu.y += 50.f;
	}
	//�������X�f�b�g�t���O�������Ă����璆�ɓ���
	if (risu.Dead)
	{
		static float angle = 15.f;

		risu.Move = false;

		angle += 15.f;
		if (angle >= 180)
		{
			angle = 180.f;
		}
		//�֐��Ăяo��
		Kaiten(-angle, risuvertex, drawrisu);

		for (int i = 0; i < 4; i++)
		{
			//risu.x -= DEADMOVESPEED_W;
			//risu.y -= DEADMOVESPEED_H;
			drawrisu[i].x += risu.x;
			drawrisu[i].y += risu.y;
		}

	}
	
	if (stageProgres < risu.movement)
	{
		risu.Active = false;
	}
}
void initStage2risu()
{
	Animal risu1 = { 425.f,400.f,false,true,true,false,false,0.f,425.f }; //�X�e�[�W2
	risu = risu1;
}
void initStage3risu()
{
	Animal risu2 = { 362.f,400.f,false,true,true,false,false,0.f,362.f };
	risu = risu2;
}
void initStage4risu()
{
	Animal risu3 = { 195.f,400.f,false,true,true,false,false,0.f,195.f }; //�X�e�[�W4
	risu = risu3;
}
void initStage5risu()
{
	Animal risu4 = { 550.f,400.f,false,true,true,false,false,0.f,550.f }; //�X�e�[�W6
	risu = risu4;
}
