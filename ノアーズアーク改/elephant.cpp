#include "elephant.h"
#include "tree.h"
#include "char.h"
#include "GameScene.h"
#include "Control.h"
#include "hole.h"
#include "systemCount.h"
#include "gameSceneControl.h"
#include "lion.h"
//�]�E�̏����ʒu�̐ݒ�
Animal elephant = { 0.f,0.f,false,true,true,false,false,0.f,0.f };//�X�e�[�W1

CUSTOMVERTEX drawelephant[4];
void elephantdraw()
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
	
	if (elephant.Skip > 0 && elephant.Dead == false)
	{
		elephant.Skip--;
		elephant.x +=( PLUSMOVESPEED + MOVESPEEDELEPHANT);
		elephant.movement += (PLUSMOVESPEED + MOVESPEEDELEPHANT);
	}
	if (elephant.Move && count > 180 && elephant.Skip == 0)
	{
		elephant.x += MOVESPEEDELEPHANT;
		elephant.movement += MOVESPEEDELEPHANT;
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
	if (elephant.x >= hole.x - HOLE_W && elephant.Skip == 0)
	{
		//��������
		hole.Active = false;
	}
	if (elephant.x >= hole2.x - HOLE_W && elephant.Skip == 0)
	{
		//��������
		hole2.Active = false;
	}

	//�����]�E�����̍��ɓ������Ă�����
	if (elephant.x >= hole3.x - HOLE_W && elephant.Skip == 0)
	{
		//��������
		hole3.Active = false;
	}
	if (elephant.x >= hole4.x - HOLE_W && elephant.Skip == 0)
	{
		//��������
		hole4.Active = false;
	}

	//�������C�I���f�b�g�t���O�������Ă����璆�ɓ���
	if (elephant.Dead)
	{
		static float angle = 15.f;
		elephant.Move = false;

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
    //�S�[������
	//�]�E�̂����ӂ˂�x���傫�������璆�ɓ���
		
	//�]�E�̂����ӂ˂�x��100����������肨�����������璆�ɓ���
	if (stageProgres < elephant.movement)
	{
		elephant.Active = false;
	}
		
}
void initStage1elephant()
{
	Animal elephant1 = { 112.f,395.f,false,true,true,false,false,0.f,112.f };//�X�e�[�W1
	elephant = elephant1;
}
void initStage26elephant()
{
	Animal elephant2 = { 90.f,395.f,false,true,true,false,false,0.f,90.f };//�X�e�[�W2�A�X�e�[�W6
	elephant = elephant2;
}
void initStage3elephant()
{
	Animal elephant3 = { 60.f,395.f,false,true,true,false,false,0.f,60.f };//�X�e�[�W3
	elephant = elephant3;
}
void initStage4elephant()
{
	Animal elephant4 = { 65.f,395.f,false,true,true,false,false,0.f,65.f };//�X�e�[�W4
	elephant = elephant4;
}
void initStage5elephant()
{
	Animal elephant5 = { 50.f,395.f,false,true,true,false,false,0.f,50.f };//�X�e�[�W7
	elephant = elephant5;
}
void initStage7elephant()
{
	Animal elephant7 = { 400.f,395.f,false,true,true,false,false,0.f,300.f };//�X�e�[�W7
	elephant = elephant7;
}