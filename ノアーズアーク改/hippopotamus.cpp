#include "hippopotamus.h"
#include "alligator.h"
#include "lion.h"
#include "char.h"
#include "GameScene.h"
#include "Control.h"
#include "finish.h"
#include "hole.h"
//�J�o�̏����ʒu
Animal hippopotamus = { 263.f,400.f,true }; //�X�e�[�W1
Animal hippopotamus2 = { 265.f,400.f,true }; //�X�e�[�W2

CUSTOMVERTEX drawhippopotamus[4];
CUSTOMVERTEX drawhippopotamus2[4];

//�J�o�������Ă�Ƃ�true
bool g_MoveHippopotamus = true;

//�J�o�������Ă��邩����ł��邩
bool hippopotamusDeadFlg = false;

void hippopotamusdraw(int time)
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
	//�J�o�̒��_���
	CUSTOMVERTEX   hippopotamusvertex2[4]
	{
		{ -HIPPOPOTAMUS_W / 2 , -HIPPOPOTAMUS_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ HIPPOPOTAMUS_W / 2 , -HIPPOPOTAMUS_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ HIPPOPOTAMUS_W / 2 ,  HIPPOPOTAMUS_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -HIPPOPOTAMUS_W / 2 ,  HIPPOPOTAMUS_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	//�ʒu�ƒ��_������
	for (int i = 0; i < 4; i++)
	{
		drawhippopotamus2[i] = hippopotamusvertex2[i];
		drawhippopotamus2[i].x += hippopotamus2.x;
		drawhippopotamus2[i].y += hippopotamus2.y;
	}

	//�����J�o�����̍��ɓ������Ă�����
	if (hippopotamus.x >= hole.x - HOLE_W)
	{
		//��������
		hole.Active = false;
	}

	if (g_MoveHippopotamus && time > 3000)
	{
		hippopotamus.x += MOVESPEEDHIPPOPOTAMUS;
	}

	//�����J�o�f�b�g�t���O�������Ă����璆�ɓ���
	if (hippopotamusDeadFlg)
	{
		static float angle = 15.f;

		g_MoveHippopotamus = false;

		angle += 15.f;
		if (angle >= 180)
		{
			angle = 180.f;
		}
		//�֐��Ăяo��
		Kaiten(-angle, hippopotamusvertex, drawHippopotamus);

		for (int i = 0; i < 4; i++)
		{
			//lion.x -= DEADMOVESPEED_W;
			//lion.y -= DEADMOVESPEED_H;
			drawHippopotamus[i].x += hippopotamus.x;
			drawHippopotamus[i].y += hippopotamus.y;
		}

	}
	//�����J�o�����j�̍��ɓ������Ă�����
	if (hippopotamus.x >= alligator.x - ALLIGATOR_W)
	{
		//���j������
		alligator.Active = false;
	}

	if (hole.Active)
	{
		if (hippopotamus.x == hole.x)
		{
			hippopotamus.x -= MOVESPEEDHIPPOPOTAMUS;
		}
	}

	if (hippopotamusDeadFlg == false)
	{
		for (int i = 0; i < 4; i++)
		{
			//�S�[������
			//�J�o��x���ӂ˂�x��肨�����������璆�ɓ���
			if (hippopotamus.x >= ship[i].x)
			{
				hippopotamus.y -= 0.1f;
				hippopotamus.Clear = true;
			}
			//�N���A����
			if (hippopotamus.Clear)
			{
				//�J�o��x���ӂ˂�x��100�����������傫�������璆�ɓ���
				if (hippopotamus.x >= ship[i].x + 100)
				{
					hippopotamus.Active = false;
				}
			}
		}
	}
}