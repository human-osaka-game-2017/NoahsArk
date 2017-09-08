#include "GameSceneScroll.h"
#include "GameScene.h"
#include "Mouse.h"
#include "Control.h"
#include "right.h"
#include "left.h"
#include "alligator.h"
#include "elephant.h"
#include "hippopotamus.h"
#include "tree.h"
#include "chestnut.h"
#include "hole.h"
#include"risu.h"
#include"mole.h"
#include "lion.h"
#include "gameSceneControl.h"

extern CUSTOMVERTEX  ship2[4];


//��ʂ̒��_
mark backGD{ 720.f,325.f };
// �o�b�N�O���E���h�̒��_�����쐬����
CUSTOMVERTEX backGround[4]
{
	{ backGD.x - RIGHT_AND_LEFT, backGD.y - ABOVE_AND_BELOW, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ backGD.x + RIGHT_AND_LEFT, backGD.y - ABOVE_AND_BELOW, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ backGD.x + RIGHT_AND_LEFT, backGD.y + ABOVE_AND_BELOW, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ backGD.x - RIGHT_AND_LEFT, backGD.y + ABOVE_AND_BELOW, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
};
//��Ɠ����w�i
CUSTOMVERTEX backGround2[4]
{
	{ backGD.x - RIGHT_AND_LEFT + 1440, backGD.y - ABOVE_AND_BELOW, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ backGD.x + RIGHT_AND_LEFT + 1440, backGD.y - ABOVE_AND_BELOW, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ backGD.x + RIGHT_AND_LEFT + 1440, backGD.y + ABOVE_AND_BELOW, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ backGD.x - RIGHT_AND_LEFT + 1440, backGD.y + ABOVE_AND_BELOW, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
};


CUSTOMVERTEX backupbackGround[4]
{
	{ backGD.x - RIGHT_AND_LEFT, backGD.y - ABOVE_AND_BELOW, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ backGD.x + RIGHT_AND_LEFT, backGD.y - ABOVE_AND_BELOW, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ backGD.x + RIGHT_AND_LEFT, backGD.y + ABOVE_AND_BELOW, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ backGD.x - RIGHT_AND_LEFT, backGD.y + ABOVE_AND_BELOW, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
};
//��Ɠ����w�i
CUSTOMVERTEX backupbackGround2[4]
{
	{ backGD.x - RIGHT_AND_LEFT + 1440, backGD.y - ABOVE_AND_BELOW, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ backGD.x + RIGHT_AND_LEFT + 1440, backGD.y - ABOVE_AND_BELOW, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ backGD.x + RIGHT_AND_LEFT + 1440, backGD.y + ABOVE_AND_BELOW, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ backGD.x - RIGHT_AND_LEFT + 1440, backGD.y + ABOVE_AND_BELOW, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
};


//�X�N���[������֐�
void scroll()
{


	
	if (backGD.x + RIGHT_AND_LEFT + 770 < backGround2[1].x)
	{
		//�}�E�X��������Ă�����
		if (CheckMouseL() == ON)
		{
			//�E�̉摜�̂Ȃ��ɂ͂����Ă���
			if (right.x - RIGHT_W / 2 < pt.x
				&&right.x + RIGHT_W / 2 > pt.x
				&&right.y - RIGHT_H / 2 < pt.y
				&&right.y + RIGHT_H / 2 > pt.y)
			{
				for (int i = 0; i < 4; i++)
				{
					//�w�i�����ɂ��炷
					backGround[i].x -= SCROLLSPEED;
					backGround2[i].x -= SCROLLSPEED;
				}
				//���ׂĂ̏�Q����ǂ��Ԃ����炵�Ă�����
				hippopotamus.x -= SCROLLSPEED;
				elephant.x -= SCROLLSPEED;
				lion.x -= SCROLLSPEED;
				tree.x -= SCROLLSPEED;
				tree2.x -= SCROLLSPEED;
				alligator.x -= SCROLLSPEED;
				chestnut.x -= SCROLLSPEED;
				hole.x -= SCROLLSPEED;
				hole2.x -= SCROLLSPEED;
				//backGD.x -= SCROLLSPEED;
				stageProgres -= SCROLLSPEED;
				risu.x -= SCROLLSPEED;
				mole.x -= SCROLLSPEED;
				for (int i = 0; i < 4; i++)
				{
					ship2[i].x -= SCROLLSPEED;
				}
				
			}
		}
	}
	if (backGD.x - RIGHT_AND_LEFT > backGround[0].x)
	{
		if (CheckMouseL() == ON)
		{
			//���̉摜�̒��ŉ�����Ă�����
			if (left.x - LEFT_W / 2 < pt.x
				&&left.x + LEFT_W / 2 > pt.x
				&&left.y - LEFT_H / 2 < pt.y
				&&left.y + LEFT_H / 2 > pt.y)
			{
				for (int i = 0; i < 4; i++)
				{
					//�w�i���E�ɂ��炷
					backGround[i].x += SCROLLSPEED;
					backGround2[i].x += SCROLLSPEED;
				}
				//���ׂĂ̏�Q����ǂ��Ԃ����炵�Ă�����
				hippopotamus.x += SCROLLSPEED;
				elephant.x += SCROLLSPEED;
				lion.x += SCROLLSPEED;
				tree.x += SCROLLSPEED;
				tree2.x += SCROLLSPEED;
				hole.x += SCROLLSPEED;
				hole2.x += SCROLLSPEED;
				chestnut.x += SCROLLSPEED;
				alligator.x += SCROLLSPEED;
				stageProgres += SCROLLSPEED;
				risu.x += SCROLLSPEED;
				mole.x += SCROLLSPEED;
				for (int i = 0; i < 4; i++)
				{
					ship2[i].x += SCROLLSPEED;
				}
			}
		}
	}
}
void initBackground()
{
	for (int i = 0; i < 4; i++)
	{
		//�w�i���E�ɂ��炷
		backGround[i]= backupbackGround[i];
		backGround2[i]= backupbackGround2[i];
	}

}
