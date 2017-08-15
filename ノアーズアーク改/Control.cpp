#include "Mouse.h"
#include "GameScene.h"
#include "char.h"
#include "Control.h"
#include "hippopotamus.h"
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
		//���ƃJ�o���d�Ȃ��Ă����ꍇ
		if ((hippopotamus.x - HIPPOPOTAMUS_W / 2 < pt.x && hippopotamus.x + HIPPOPOTAMUS_W / 2 > pt.x && hippopotamus.y - HIPPOPOTAMUS_H / 2 < pt.y && hippopotamus.y + HIPPOPOTAMUS_H / 2 > pt.y) &&
			(elephant.x - ELEPHANT_W / 2 < pt.x && elephant.x + ELEPHANT_W / 2 > pt.x&& elephant.y - ELEPHANT_H / 2 < pt.y && elephant.y + ELEPHANT_H / 2 > pt.y))
		{
			if (g_MoveHippopotamus)
			{
				if (g_Moveelephant == true)
				{
					//�ǂ���������Ă���ꍇ���̒�~��D��
					g_Moveelephant = false;
				}

				//����ȊO(���͒�~���Ă���)�ꍇ�̓J�o��~�A���ړ�
				g_Moveelephant = true;
				g_MoveHippopotamus = false;
			}
			//�J�o����~���Ă��āA���������Ă���ꍇ
			else if (g_MoveHippopotamus == false)
			{
				if (g_Moveelephant == true)
				{
					g_Moveelephant = false;
					g_MoveHippopotamus = true;
				}
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
			//���O������~���Ă��āA���������Ă���ꍇ
			else if (g_MoveMole == false)
			{
				if (g_Moveelephant == true)
				{
					g_Moveelephant = false;
					g_MoveMole = true;
				}
			}
		}
		//�J�o�ƃ��O�����d�Ȃ��Ă����ꍇ
		if ((mole.x - MOLE_W / 2 < pt.x && mole.x + MOLE_W / 2 > pt.x && mole.y - MOLE_H / 2 < pt.y && mole.y + MOLE_H / 2 > pt.y) &&
			(hippopotamus.x - HIPPOPOTAMUS_W / 2 < pt.x && hippopotamus.x + HIPPOPOTAMUS_W / 2 > pt.x&& hippopotamus.y - HIPPOPOTAMUS_H / 2 < pt.y && hippopotamus.y + HIPPOPOTAMUS_H / 2 > pt.y))
		{
			if (g_MoveMole)
			{
				if (g_MoveHippopotamus == true)
				{
					//�ǂ���������Ă���ꍇ�J�o�̒�~��D��
					g_MoveHippopotamus = false;
				}

				//����ȊO(�J�o�͒�~���Ă���)�ꍇ�̓��O����~�A�J�o�ړ�
				g_MoveHippopotamus = true;
				g_MoveMole = false;
			}
			//���O������~���Ă��āA�J�o�������Ă���ꍇ
			else if (g_MoveHippopotamus == false)
			{
				if (g_MoveMole == true)
				{
					g_MoveMole = false;
					g_MoveHippopotamus = true;
				}
			}
		}
		//�J�o�̍��W���ŃN���b�N���ꂽ�ꍇ��~
		else if (hippopotamus.x - HIPPOPOTAMUS_W / 2 < pt.x && hippopotamus.x + HIPPOPOTAMUS_W / 2 > pt.x && hippopotamus.y - HIPPOPOTAMUS_H / 2 < pt.y && hippopotamus.y + HIPPOPOTAMUS_H / 2 > pt.y)
		{
			if (g_MoveHippopotamus)
			{
				//����������~���Ă���ꍇ�͑��͓����o��
				if (g_Moveelephant == false)
				{
					g_Moveelephant = true;
				}
				if (g_MoveMole == false)
				{
					g_MoveMole = true;
				}
				g_MoveHippopotamus = false;
			}

			else
			{
				g_MoveHippopotamus = true;
			}
		}
		//���O���̍��W���ŃN���b�N���ꂽ�ꍇ��~
		else if (mole.x - MOLE_W / 2 < pt.x && mole.x + MOLE_W / 2 > pt.x && mole.y - MOLE_H / 2 < pt.y && mole.y + MOLE_H / 2 > pt.y)
		{
			if (g_MoveMole)
			{
				//����������~���Ă���ꍇ�͑��͓����o��
				if (g_Moveelephant == false)
				{
					g_Moveelephant = true;
				}
				if (g_MoveHippopotamus == false)
				{
					g_MoveHippopotamus = true;
				}
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
			//���������ăJ�o���~�܂��Ă���ꍇ
			if (g_Moveelephant)
			{
				if (g_MoveHippopotamus == false)
				{
					g_MoveHippopotamus = true;
				}
				if (g_MoveMole == false)
				{
					g_MoveMole = true;
				}
				g_Moveelephant = false;
			}
			else if (g_Moveelephant == false)
			{
					g_Moveelephant = true;
			}
		}
		
	}
}

//������E�ɗ����Ƃ��̂��̂����蔻��
void collision()
{
	//�����J�o���������Ă�����
	if (g_MoveHippopotamus&&tree.Active)
	{
		//�������Ă��邩�̔���
		if (tree.x - TREE_W  < hippopotamus.x)
		{
			hippopotamusDeadFlg = true;
		}
			
	}
	//�����J�o���������Ă�����
	if (g_MoveHippopotamus&&tree2.Active)
	{
		//�������Ă��邩�̔���
		if (tree2.x - TREE_W  < hippopotamus.x)
		{
			hippopotamusDeadFlg = true;
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