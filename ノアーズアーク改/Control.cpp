#include "Mouse.h"
#include "GameScene.h"
#include "char.h"
#include "Control.h"
#include "lion.h"
#include "elephant.h"
#include "tree.h"
#include "alligator.h"
#include "mole.h"

//�����������Ă��邩�~�܂��Ă��邩�̔���@�����Ă���Ƃ�true,�~�܂��Ă���Ƃ�false
//mob chestnut = { 900.f,500.f,false };//�I

	BTN_STATE g_OldMouse = OFF;
	BTN_STATE g_CurrentMouse = OFF;

	short oldMouse = 0;
	short currentMouse = 0;

	//�}�E�X�̃`�F�b�N�֐�
	BTN_STATE CheckMouseL()
	{
		if (GetAsyncKeyState(VK_LBUTTON))
		{
			if (g_OldMouse == OFF)
			{
				g_CurrentMouse = PUSH;
			}
			else
			{
				g_CurrentMouse = ON;
			}

			g_OldMouse = ON;
		}
		else
		{
			if (g_OldMouse == ON)
			{
				g_CurrentMouse = RELEASE;
			}
			else
			{
				g_CurrentMouse = OFF;
			}
			g_OldMouse = OFF;
		}

		return g_CurrentMouse;
	}
	
	//�}�E�X�������ꂽ���̓���
void Control() 
{
	if (CheckMouseL() == PUSH)
	{
		//���ƃ��C�I�����d�Ȃ��Ă����ꍇ
		if ((lion.x - LION_W / 2 < pt.x && lion.x + LION_W / 2 > pt.x && lion.y - LION_H / 2 < pt.y && lion.y + LION_H / 2 > pt.y) &&
			(elephant.x - ELEPHANT_W / 2 < pt.x && elephant.x + ELEPHANT_W / 2 > pt.x&& elephant.y - ELEPHANT_H / 2 < pt.y && elephant.y + ELEPHANT_H / 2 > pt.y))
		{
			if (g_MoveLion)
			{
				if (g_Moveelephant == true)
				{
					//�ǂ���������Ă���ꍇ���̒�~��D��
					g_Moveelephant = false;
				}

				//����ȊO(���͒�~���Ă���)�ꍇ�̓��C�I����~�A���ړ�
				g_Moveelephant = true;
				g_MoveLion = false;
			}

			else if (g_MoveLion == false)
			{
				//���C�I������~���Ă��āA���������Ă���ꍇ
				if (g_Moveelephant == true)
				{
					g_Moveelephant = false;
					g_MoveLion = true;
				}
			}
		}
		//���C�I���̍��W���ŃN���b�N���ꂽ�ꍇ��~
		else if (lion.x - LION_W / 2 < pt.x && lion.x + LION_W / 2 > pt.x && lion.y - LION_H / 2 < pt.y && lion.y + LION_H / 2 > pt.y)
		{
			if (g_MoveLion)
			{
				//����������~���Ă���ꍇ�͑��͓����o��
				if (g_Moveelephant == false)
				{
					g_Moveelephant = true;
				}
				g_MoveLion = false;
			}

			else
			{

				g_MoveLion = true;
			}
		}
		//���ƃ��O�����d�Ȃ��Ă����ꍇ
		if ((mole.x - MOLE_W / 2 < pt.x && mole.x + MOLE_W / 2 > pt.x && mole.y - MOLE_H / 2 < pt.y && mole.y + MOLE_H / 2 > pt.y) &&
			(elephant.x - ELEPHANT_W / 2 < pt.x && elephant.x + ELEPHANT_W / 2 > pt.x&& elephant.y - ELEPHANT_H / 2 < pt.y && elephant.y + ELEPHANT_H / 2 > pt.y))
		{
			if (g_MoveMole)
			{
				if (g_Moveelephant == true)
				{
					//�ǂ���������Ă���ꍇ���̒�~��D��
					g_Moveelephant = false;
				}

				//����ȊO(���͒�~���Ă���)�ꍇ�̓��O����~�A���ړ�
				g_Moveelephant = true;
				g_MoveMole = false;
			}
		}
		//���C�I���ƃ��O�����d�Ȃ��Ă����ꍇ
		if ((mole.x - MOLE_W / 2 < pt.x && mole.x + MOLE_W / 2 > pt.x && mole.y - MOLE_H / 2 < pt.y && mole.y + MOLE_H / 2 > pt.y) &&
			(lion.x - LION_W / 2 < pt.x && lion.x + LION_W / 2 > pt.x&& lion.y - LION_H / 2 < pt.y && lion.y + LION_H / 2 > pt.y))
		{
			if (g_MoveMole)
			{
				if (g_MoveLion == true)
				{
					//�ǂ���������Ă���ꍇ���C�I���̒�~��D��
					g_MoveLion = false;
				}

				//����ȊO(���C�I���͒�~���Ă���)�ꍇ�̓��O����~�A���C�I���ړ�
				g_MoveLion = true;
				g_MoveMole = false;
			}
		}
		//���O���̍��W���ŃN���b�N���ꂽ�ꍇ��~
		else if (mole.x - MOLE_W / 2 < pt.x && mole.x + MOLE_W / 2 > pt.x && mole.y - MOLE_H / 2 < pt.y && mole.y + MOLE_H / 2 > pt.y)
		{
			if (g_MoveMole)
			{
				g_MoveMole = false;
			}
			else
			{
				g_MoveMole = true;
			}
		}
		

		//�]�E�̍��W���ŃN���b�N����ƒ�~
		else if (elephant.x - ELEPHANT_W / 2 < pt.x && elephant.x + ELEPHANT_W / 2 > pt.x&& elephant.y - ELEPHANT_H / 2 < pt.y && elephant.y + ELEPHANT_H / 2 > pt.y)
		{
			//���������ă��C�I�����~�܂��Ă���ꍇ
			if (g_Moveelephant)
			{
				if (g_MoveLion == false)
				{
					g_Moveelephant = false;
					g_MoveLion = true;

				}
				g_Moveelephant = false;
			}
			else if (g_Moveelephant == false)
			{
				if (g_MoveLion)
				{
					g_Moveelephant = true;
				}
			}
		}
		
	}
}

//������E�ɗ����Ƃ��̂��̂����蔻��
void collision()
{
	//�������C�I�����������Ă�����
	if (g_MoveLion&&tree.Active)
	{
		//�������Ă��邩�̔���
		if (tree.x - TREE_W  < lion.x)
		{
			LionDeadFlg = true;
		}
			
	}
	//�������C�I�����������Ă�����
	if (g_MoveLion&&tree2.Active)
	{
		//�������Ă��邩�̔���
		if (tree2.x - TREE_W  < lion.x)
		{
			LionDeadFlg = true;
		}

	}
	//�����]�E���������Ă�����
	if (g_Moveelephant&&alligator.Active)
	{
		//�������Ă��邩�̔���
		if (alligator.x - ALLIGATOR_W< elephant.x)
		{
			//�������Ă�����A���������ʒu�Ŏ~�܂�
			ElephantDeadFlg = true;;
		}
	}
}
//��]�֐�
void Kaiten(float kakudo, CUSTOMVERTEX src[], CUSTOMVERTEX dest[])
{
	float cx, cy;
	float rad;

	rad = D3DXToRadian(kakudo);

	cx = (src[0].x + src[1].x) / 2.0f;
	cy = (src[0].y + src[3].y) / 2.0f;
	for (int i = 0; i < 4; i++) {
		//���S�����_��
		src[i].x -= cx;
		src[i].y -= cy;


			dest[i] = src[i];
			dest[i].x = src[i].x * cos(rad)
				- src[i].y * sin(rad);
			dest[i].y = src[i].x * sin(rad)
				+ src[i].y * cos(rad);
			
			// ���_���璆�S
			src[i].x += cx;
			src[i].y += cy;
			dest[i].x += cx;
			dest[i].y += cy;
	}
}