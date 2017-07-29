#include "risu.h"
#include "chestnut.h"
#include "char.h"
#include "GameScene.h"
#include "Control.h"
#include "finish.h"
//���X�̏����ʒu
Animal risu = { 362.f,381.f,false,true }; //���X

CUSTOMVERTEX drawrisu[4];

//���X�������Ă�Ƃ�true
bool g_MoveRisu = true;

//���X�������Ă��邩����ł��邩
bool RisuDeadFlg = false;

void risudraw(int time)
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

	if (g_MoveRisu && time > 3000)
	{
		risu.x += MOVESPEEDRISU;
	}

	//�������X�f�b�g�t���O�������Ă����璆�ɓ���
	if (RisuDeadFlg)
	{
		static float angle = 15.f;

		g_MoveRisu = false;

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
	//�������X���I�̍��ɓ������Ă�����
	if (risu.x >= chestnut.x - CHESTNUT_W)
	{
		//�I������
		chestnut.Active = false;
	}

	if (RisuDeadFlg == false)
	{
		for (int i = 0; i < 4; i++)
		{
			//�S�[������
			//���X��x���ӂ˂�x��肨�����������璆�ɓ���
			if (risu.x >= ship[i].x)
			{
				risu.y -= 0.1f;
				risu.Clear = true;
			}
			//�N���A����
			if (risu.Clear)
			{
				//���X��x���ӂ˂�x��100�����������傫�������璆�ɓ���
				if (risu.x >= ship[i].x + 100)
				{
					risu.Active = false;
				}
			}
		}
	}
}