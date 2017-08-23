#include "elephant.h"
#include "tree.h"
#include "char.h"
#include "GameScene.h"
#include "Control.h"
#include "hole.h"
//�]�E�̏����ʒu�̐ݒ�
Animal elephant = { 112.f,395.f,false,true };//�X�e�[�W1
Animal elephant2 = { 90.f,395.f,false,true };//�X�e�[�W2�A�X�e�[�W6
Animal elephant3 = { 60.f,395.f,false,true };//�X�e�[�W3
Animal elephant4 = { 65.f,395.f,false,true };//�X�e�[�W4
Animal elephant5 = { 900.f,395.f,false,true };//�X�e�[�W7

CUSTOMVERTEX drawelephant[4];
CUSTOMVERTEX drawelephant2[4];
CUSTOMVERTEX drawelephant3[4];
CUSTOMVERTEX drawelephant4[4];
CUSTOMVERTEX drawelephant5[4];

//�]�E�������Ă��Ă�����true
bool g_Moveelephant = true;
//�]�E�������Ă��邩����ł��邩
bool ElephantDeadFlg = false;

void elephantdraw(int time)
{
	//�]�E�̒��_���
	CUSTOMVERTEX  elephantvertex[4]
	{
		{ -ELEPHANT_W / 2, -ELEPHANT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{  ELEPHANT_W / 2, -ELEPHANT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{  ELEPHANT_W / 2,  ELEPHANT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -ELEPHANT_W / 2,  ELEPHANT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	//�ʒu�ƒ��_������
	for (int i = 0; i < 4; i++)
	{
		drawelephant[i] = elephantvertex[i];
		drawelephant[i].x += elephant.x;
		drawelephant[i].y += elephant.y;
	}
	//�]�E�̒��_���
	CUSTOMVERTEX  elephantvertex2[4]
	{
		{ -ELEPHANT_W / 2, -ELEPHANT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ ELEPHANT_W / 2, -ELEPHANT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ ELEPHANT_W / 2,  ELEPHANT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -ELEPHANT_W / 2,  ELEPHANT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	//�ʒu�ƒ��_������
	for (int i = 0; i < 4; i++)
	{
		drawelephant2[i] = elephantvertex2[i];
		drawelephant2[i].x += elephant2.x;
		drawelephant2[i].y += elephant2.y;
	}
	//�]�E�̒��_���
	CUSTOMVERTEX  elephantvertex3[4]
	{
		{ -ELEPHANT_W / 2, -ELEPHANT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ ELEPHANT_W / 2, -ELEPHANT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ ELEPHANT_W / 2,  ELEPHANT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -ELEPHANT_W / 2,  ELEPHANT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	//�ʒu�ƒ��_������
	for (int i = 0; i < 4; i++)
	{
		drawelephant3[i] = elephantvertex3[i];
		drawelephant3[i].x += elephant3.x;
		drawelephant3[i].y += elephant3.y;
	}
	//�]�E�̒��_���
	CUSTOMVERTEX  elephantvertex4[4]
	{
		{ -ELEPHANT_W / 2, -ELEPHANT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ ELEPHANT_W / 2, -ELEPHANT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ ELEPHANT_W / 2,  ELEPHANT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -ELEPHANT_W / 2,  ELEPHANT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	//�ʒu�ƒ��_������
	for (int i = 0; i < 4; i++)
	{
		drawelephant4[i] = elephantvertex4[i];
		drawelephant4[i].x += elephant4.x;
		drawelephant4[i].y += elephant4.y;
	}
	//�]�E�̒��_���
	CUSTOMVERTEX  elephantvertex5[4]
	{
		{ -ELEPHANT_W / 2, -ELEPHANT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ ELEPHANT_W / 2, -ELEPHANT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ ELEPHANT_W / 2,  ELEPHANT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -ELEPHANT_W / 2,  ELEPHANT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	//�ʒu�ƒ��_������
	for (int i = 0; i < 4; i++)
	{
		drawelephant5[i] = elephantvertex5[i];
		drawelephant5[i].x += elephant5.x;
		drawelephant5[i].y += elephant5.y;
	}
	if (g_Moveelephant && time > 3000)
	{
		elephant.x += MOVESPEEDELEPHANT;
	}
	//�����]�E���؂̍��ɓ������Ă�����
	if (elephant.x >= tree.x - TREE_W)
	{
		//�؂�����
		tree.Active = false;
	}

	//�����]�E���؂̍��ɓ������Ă�����
	if (elephant.x >= tree2.x - TREE_W)
	{
		//�؂�����
		tree2.Active = false;
	}
	//�����]�E�����̍��ɓ������Ă�����
	if (elephant.x >= hole.x - HOLE_W)
	{
		//��������
		hole.Active = false;
	}

	//�������C�I���f�b�g�t���O�������Ă����璆�ɓ���
	if (ElephantDeadFlg)
	{
		static float angle = 15.f;
		g_Moveelephant = false;

		angle += 15.f;
		if (angle >= 180)
		{
			angle = 180.f;
		}
		//�֐��Ăяo��
		Kaiten(-angle, elephantvertex, drawelephant);

		for (int i = 0; i < 4; i++)
		{
			//elephant.x -= DEADMOVESPEED_W;
			//elephant.y -= DEADMOVESPEED_H;
			drawelephant[i].x += elephant.x;
			drawelephant[i].y += elephant.y;
		}
	}


	for (int i = 0; i < 4; i++)
	{
		//�S�[������
		//�]�E�̂����ӂ˂�x���傫�������璆�ɓ���
		if (elephant.x >= ship[i].x)
		{
			elephant.y -= 0.1f;
			elephant.Clear = true;
		}
		//�N���A����
 		if (elephant.Clear)
		{
			//�]�E�̂����ӂ˂�x��100����������肨�����������璆�ɓ���
			if (elephant.x >= ship[i].x + 100)
			{
				elephant.Active = false;
			}
		}
	}
}