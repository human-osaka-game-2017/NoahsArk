#include "risu.h"
#include "chestnut.h"
#include "char.h"
#include "GameScene.h"
#include "Control.h"
#include "finish.h"
#include "hole.h"
#include "systemCount.h"
//���X�̏����ʒu
Animal risu = { 425.f,400.f,false,true }; //�X�e�[�W2
Animal risu2 = { 362.f,400.f,false,true }; //�X�e�[�W3
Animal risu3 = { 195.f,400.f,false,true }; //�X�e�[�W4
Animal risu4 = { 270.f,400.f,false,true }; //�X�e�[�W6
Animal risu5 = { 90.f,400.f,false,true }; //�X�e�[�W8

CUSTOMVERTEX drawrisu[4];
CUSTOMVERTEX drawrisu2[4];
CUSTOMVERTEX drawrisu3[4];
CUSTOMVERTEX drawrisu4[4];
CUSTOMVERTEX drawrisu5[4];

//���X�������Ă�Ƃ�true
bool g_MoveRisu = true;

//���X�������Ă��邩����ł��邩
bool RisuDeadFlg = false;

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
	//���X�̒��_���
	CUSTOMVERTEX  risuvertex2[4]
	{
		{ -RISU_W / 2 , -RISU_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ RISU_W / 2 , -RISU_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ RISU_W / 2 ,  RISU_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -RISU_W / 2 ,  RISU_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	//�ʒu�ƒ��_����������
	for (int i = 0; i < 4; i++)
	{
		drawrisu2[i] = risuvertex2[i];
		drawrisu2[i].x += risu2.x;
		drawrisu2[i].y += risu2.y;
	}
	//���X�̒��_���
	CUSTOMVERTEX  risuvertex3[4]
	{
		{ -RISU_W / 2 , -RISU_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ RISU_W / 2 , -RISU_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ RISU_W / 2 ,  RISU_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -RISU_W / 2 ,  RISU_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	//�ʒu�ƒ��_����������
	for (int i = 0; i < 4; i++)
	{
		drawrisu3[i] = risuvertex3[i];
		drawrisu3[i].x += risu3.x;
		drawrisu3[i].y += risu3.y;
	}
	//���X�̒��_���
	CUSTOMVERTEX  risuvertex4[4]
	{
		{ -RISU_W / 2 , -RISU_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ RISU_W / 2 , -RISU_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ RISU_W / 2 ,  RISU_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -RISU_W / 2 ,  RISU_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	//�ʒu�ƒ��_����������
	for (int i = 0; i < 4; i++)
	{
		drawrisu4[i] = risuvertex4[i];
		drawrisu4[i].x += risu4.x;
		drawrisu4[i].y += risu4.y;
	}
	//���X�̒��_���
	CUSTOMVERTEX  risuvertex5[4]
	{
		{ -RISU_W / 2 , -RISU_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ RISU_W / 2 , -RISU_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ RISU_W / 2 ,  RISU_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -RISU_W / 2 ,  RISU_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	//�ʒu�ƒ��_����������
	for (int i = 0; i < 4; i++)
	{
		drawrisu5[i] = risuvertex5[i];
		drawrisu5[i].x += risu5.x;
		drawrisu5[i].y += risu5.y;
	}

	if (g_MoveRisu && count > 180)
	{
		risu.x += MOVESPEEDRISU;
	}

	if (hole.Active)
	{
		if (hole.x == risu.x)
		{
			//��O�̌����牜�̌��̋������o���Ă����tmp�ɓ����
			int tmp = hole2.x - hole.x;
			//���̃��X�̈ʒu��tmp�𑫂�
			risu.x = risu.x + tmp;
		}
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