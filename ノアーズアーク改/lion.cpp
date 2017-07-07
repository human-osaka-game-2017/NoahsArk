#include "lion.h"
#include "alligator.h"
#include "char.h"
#include "GameScene.h"
#include "Control.h"
#include "finish.h"
//���C�I���̏����ʒu
Animal lion = { 200.f,400.f,false,true }; //���C�I��

CUSTOMVERTEX drawlion[4];

//���C�I���������Ă�Ƃ�true
bool g_MoveLion = true;

//���C�I���������Ă��邩����ł��邩
bool LionDeadFlg = false;

void liondraw(int time)
{
	//���C�I���̒��_���
	CUSTOMVERTEX  lionvertex[4]
	{
		{ -LION_W / 2 , -LION_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ LION_W / 2 , -LION_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ LION_W / 2 ,  LION_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -LION_W / 2 ,  LION_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	//�ʒu�ƒ��_����������
	for (int i = 0; i < 4; i++)
	{
		drawlion[i] = lionvertex[i];
		drawlion[i].x += lion.x;
		drawlion[i].y += lion.y;
	}

	if (g_MoveLion && time > 3000)
	{
		lion.x += MOVESPEEDLION;
	}

	//�������C�I���f�b�g�t���O�������Ă����璆�ɓ���
	if (LionDeadFlg)
	{
		static float angle = 15.f;

		g_MoveLion = false;

		angle += 15.f;
		if (angle >= 180)
		{
			angle = 180.f;
		}
		//�֐��Ăяo��
		Kaiten(-angle, lionvertex, drawlion);

		for (int i = 0; i < 4; i++)
		{
			//lion.x -= DEADMOVESPEED_W;
		    //lion.y -= DEADMOVESPEED_H;
			drawlion[i].x += lion.x;
			drawlion[i].y += lion.y;
		}
			
	}
	//�������C�I�������j�̍��ɓ������Ă�����
	if (lion.x >= alligator.x - ALLIGATOR_W)
	{
		//���j������
		alligator.Active = false;
	}

	if (LionDeadFlg == false)
	{
		for (int i = 0; i < 4; i++)
		{
			//�S�[������
			//���C�I����x���ӂ˂�x��肨�����������璆�ɓ���
			if (lion.x >= ship[i].x)
			{
				lion.y -= 0.1f;
				lion.Clear = true;
			}
			//�N���A����
			if (lion.Clear)
			{
				//���C�I����x���ӂ˂�x��100�����������傫�������璆�ɓ���
				if (lion.x >= ship[i].x + 100)
				{
					lion.Active = false;
				}
			}
		}
	}
}