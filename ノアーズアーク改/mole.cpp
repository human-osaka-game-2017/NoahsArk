#include "char.h"
#include "GameScene.h"
#include "mole.h"
#include "Control.h"
#include "hole.h"
//���O���̈ʒu
Animal mole{ 100.f,400.f,false,true };

//���O���������Ă�Ƃ�true
bool g_MoveMole = true;

//���O���������Ă��邩����ł��邩
bool MoleDeadFlg = false;

CUSTOMVERTEX drawmole[4];

void moledraw(int time)
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

	if (g_MoveMole && time > 3000)
	{
		mole.x += MOVESPEEDMOLE;
	}

	if (hole.Active)
	{
	//�������O������O�̌��ɓ������Ă�����
		if (hole.x == mole.x)
		{
			//��O�̌����牜�̌��̋������o���Ă����tmp�ɓ����
			int tmp = hole2.x - hole.x;
			//���̃��O���̈ʒu��tmp�𑫂�
			mole.x = mole.x + tmp;
		}
	}

		

	//�������C�I���f�b�g�t���O�������Ă����璆�ɓ���
	if (MoleDeadFlg)
	{
		static float angle = 15.f;

		g_MoveMole = false;

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
	if (MoleDeadFlg == false)
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