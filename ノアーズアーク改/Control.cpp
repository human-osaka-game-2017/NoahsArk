#include "Mouse.h"
#include "GameScene.h"
#include "char.h"
#include "Control.h"
#include "hippopotamus.h"
#include "elephant.h"
#include "tree.h"
#include "alligator.h"
#include "mole.h"


void animalInterlap(Animal animal, Animal animal2);

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
			animalInterlap(hippopotamus, elephant);

			/*if (hippopotamus.Move)
			{
				if(elephant.Move)
				{
					//�ǂ���������Ă���ꍇ���̒�~��D��
					elephant.Move = false;
					elephant.Push = true;
				}
				//����ȊO(���͒�~���Ă���)�ꍇ�̓J�o��~�A���ړ�
				if (elephant.Push = false)
				{
					elephant.Move = true;
					hippopotamus.Move = false;
				}
				elephant.Push - false;
			}
			//�J�o����~���Ă��āA���������Ă���ꍇ
			else if (hippopotamus.Move == false)
			{
				if (elephant.Move)
				{
					elephant.Move = false;
					hippopotamus.Move = true;
				}
			}*/
		}
		
		//���ƃ��O�����d�Ȃ��Ă����ꍇ
		if ((mole.x - MOLE_W / 2 < pt.x && mole.x + MOLE_W / 2 > pt.x && mole.y - MOLE_H / 2 < pt.y && mole.y + MOLE_H / 2 > pt.y) &&
			(elephant.x - ELEPHANT_W / 2 < pt.x && elephant.x + ELEPHANT_W / 2 > pt.x&& elephant.y - ELEPHANT_H / 2 < pt.y && elephant.y + ELEPHANT_H / 2 > pt.y))
		{
			animalInterlap(mole, elephant);
		}
		//�J�o�ƃ��O�����d�Ȃ��Ă����ꍇ
		if ((mole.x - MOLE_W / 2 < pt.x && mole.x + MOLE_W / 2 > pt.x && mole.y - MOLE_H / 2 < pt.y && mole.y + MOLE_H / 2 > pt.y) &&
			(hippopotamus.x - HIPPOPOTAMUS_W / 2 < pt.x && hippopotamus.x + HIPPOPOTAMUS_W / 2 > pt.x&& hippopotamus.y - HIPPOPOTAMUS_H / 2 < pt.y && hippopotamus.y + HIPPOPOTAMUS_H / 2 > pt.y))
		{
			animalInterlap(mole, hippopotamus);
		}
		//�J�o�̍��W���ŃN���b�N���ꂽ�ꍇ��~
		else if (hippopotamus.x - HIPPOPOTAMUS_W / 2 < pt.x && hippopotamus.x + HIPPOPOTAMUS_W / 2 > pt.x && hippopotamus.y - HIPPOPOTAMUS_H / 2 < pt.y && hippopotamus.y + HIPPOPOTAMUS_H / 2 > pt.y)
		{
			if (hippopotamus.Move)
			{
				//����������~���Ă���ꍇ�͑��͓����o��
				if (elephant.Move == false)
				{
					elephant.Move = true;
				}
				if (mole.Move == false)
				{
					mole.Move = true;
				}
				hippopotamus.Move = false;
			}

			else
			{
				hippopotamus.Move = true;
			}
		}
		//���O���̍��W���ŃN���b�N���ꂽ�ꍇ��~
		else if (mole.x - MOLE_W / 2 < pt.x && mole.x + MOLE_W / 2 > pt.x && mole.y - MOLE_H / 2 < pt.y && mole.y + MOLE_H / 2 > pt.y)
		{
			if (mole.Move)
			{
				//����������~���Ă���ꍇ�͑��͓����o��
				if (elephant.Move == false)
				{
					elephant.Move = true;
				}
				if (hippopotamus.Move == false)
				{
					hippopotamus.Move = true;
				}
				mole.Move = false;
			}
			else
			{
				mole.Move = true;
			}
		}
		

		//�]�E�̍��W���ŃN���b�N����ƒ�~
		else if (elephant.x - ELEPHANT_W / 2 < pt.x && elephant.x + ELEPHANT_W / 2 > pt.x&& elephant.y - ELEPHANT_H / 2 < pt.y && elephant.y + ELEPHANT_H / 2 > pt.y)
		{
			//���������ăJ�o���~�܂��Ă���ꍇ
			if (elephant.Move)
			{
				if (hippopotamus.Move == false)
				{
					hippopotamus.Move= true;
				}
				if (mole.Move == false)
				{
					mole.Move = true;
				}
				elephant.Move = false;
			}
			else if (elephant.Move == false)
			{
					elephant.Move = true;
			}
		}
		
	}
}


//������E�ɗ����Ƃ��̂��̂����蔻��
void collision()
{
	//�����J�o���������Ă�����
	if (hippopotamus.Move&&tree.Active)
	{
		//�������Ă��邩�̔���
		if (tree.x - TREE_W  < hippopotamus.x)
		{
			hippopotamus.Dead = true;
		}
			
	}
	//�����J�o���������Ă�����
	if (hippopotamus.Move&&tree2.Active)
	{
		//�������Ă��邩�̔���
		if (tree2.x - TREE_W  < hippopotamus.x)
		{
			hippopotamus.Dead = true;
		}

	}
	//�����]�E���������Ă�����
	if (elephant.Move&&alligator.Active)
	{
		//�������Ă��邩�̔���
		if (alligator.x - ALLIGATOR_W< elephant.x)
		{
			//�������Ă�����A���������ʒu�Ŏ~�܂�
			elephant.Dead = true;;
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
//���������Ȃ������̔���֐�
//����1�ڂ��������ق��̓����A�����Q�ڂ��傫���ق��̓���
void animalInterlap(Animal animal, Animal animal2)
{
	if (animal.Move)
	{
		if (animal2.Move == true)
		{
			//�ǂ���������Ă���ꍇ���̒�~��D��
			animal2.Move = false;
			animal2.Push = true;
		}

		//����ȊO(���͒�~���Ă���)�ꍇ�̓J�o��~�A���ړ�
		if (animal2.Push == false)
		{
			animal2.Move = true;
			animal.Move = false;
		}
		animal2.Push = false;
	}
	//�J�o����~���Ă��āA���������Ă���ꍇ
	else if (animal.Move == false)
	{
		if (animal2.Move == true)
		{
			animal2.Move = false;
			animal.Move = true;
		}
	}
}
//��ڂ̓������N���b�N���ꂽ�����A��ڂ��c��̓����A�O�ڂ����l
void click(Animal animal,Animal animal2,Animal animal3)
{
	if (animal.Move)
	{
		//����������~���Ă���ꍇ�͑��͓����o��
		if (animal2.Move == false)
		{
			animal2.Move = true;
		}
		if (animal3.Move == false)
		{
			animal3.Move = true;
		}
		animal.Move = false;
	}
	else
	{
		animal.Move = true;
	}
}