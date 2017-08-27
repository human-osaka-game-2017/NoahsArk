#include "char.h"
#include "GameScene.h"
#include "mole.h"
#include "Control.h"
#include "hole.h"
#include"systemCount.h"
//���O���̈ʒu
Animal mole = { 314.f,400.f,false,true,true,false,false,false }; //�X�e�[�W4
Animal mole2 = { 300.f,400.f,false,true,true,false,false,false }; //�X�e�[�W8

CUSTOMVERTEX drawmole[4];
CUSTOMVERTEX drawmole2[4];

void moledraw()
{
	//���O���̒��_���
	CUSTOMVERTEX  molevertex[4]
	{
		{ -MOLE_W / 2 , -MOLE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{  MOLE_W / 2 , -MOLE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{  MOLE_W / 2 ,  MOLE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -MOLE_W / 2 ,  MOLE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	for (int i = 0; i < 4; i++)
	{
		drawmole[i] = molevertex[i];
		drawmole[i].x += mole.x;
		drawmole[i].y += mole.y;
	}
	//���O���̒��_���
	CUSTOMVERTEX  molevertex2[4]
	{
		{ -MOLE_W / 2 , -MOLE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ MOLE_W / 2 , -MOLE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ MOLE_W / 2 ,  MOLE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -MOLE_W / 2 ,  MOLE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	for (int i = 0; i < 4; i++)
	{
		drawmole2[i] = molevertex2[i];
		drawmole2[i].x += mole2.x;
		drawmole2[i].y += mole2.y;
	}

	if (mole.Move && count > 180)
	{
		mole.x += MOVESPEEDMOLE;
	}
	//���O�������ɓ������Ă�����ړ�����
	if (hole.Active && mole.Skip == false)
	{
	//�������O������O�̌��ɓ������Ă�����
		if (hole.x == mole.x)
		{
			mole.y += 30.f;
		}
	}
	//�������̌��ɓ������Ă�����
	if (mole.x == hole2.x)
	{
		mole.y -= 30.f;
	}
		

	//�������O���f�b�g�t���O�������Ă����璆�ɓ���
	if (mole.Dead)
	{
		static float angle = 15.f;

		mole.Move = false;

		angle += 15.f;
		if (angle >= 180)
		{
			angle = 180.f;
		}
		//�֐��Ăяo��
		Kaiten(-angle, molevertex, drawmole);

		for (int i = 0; i < 4; i++)
		{
			//lion.x -= DEADMOVESPEED_W;
			//lion.y -= DEADMOVESPEED_H;
			drawmole[i].x += mole.x;
			drawmole[i].y += mole.y;
		}
	}
	if (mole.Dead == false)
	{
		for (int i = 0; i < 4; i++)
		{
			//�S�[������
			//���C�I����x���ӂ˂�x��肨�����������璆�ɓ���
			if (mole.x >= ship[i].x)
			{
				mole.y -= 0.1f;
				mole.Clear = true;
			}
			//�N���A����
			if (mole.Clear)
			{
				//���C�I����x���ӂ˂�x��100�����������傫�������璆�ɓ���
				if (mole.x >= ship[i].x + 100)
				{
					mole.Active = false;
				}
			}
		}
	}


}