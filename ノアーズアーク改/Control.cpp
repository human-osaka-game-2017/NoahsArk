#include "Mouse.h"
#include "GameScene.h"
#include "char.h"
#include "Control.h"
#include "hippopotamus.h"
#include "elephant.h"
#include "tree.h"
#include "alligator.h"
#include "mole.h"
#include "lion.h"
#include "risu.h"
#include "chestnut.h"
void animalInterlap(Animal *animal, Animal *animal2);
void click2(Animal *animal, Animal *animal2);
void click5(Animal *animal, Animal *animal2, Animal *animal3, Animal *animal4, Animal *animal5);

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
			animalInterlap(&hippopotamus, &elephant);
		}
		
		//���ƃ��O�����d�Ȃ��Ă����ꍇ
		if ((mole.x - MOLE_W / 2 < pt.x && mole.x + MOLE_W / 2 > pt.x && mole.y - MOLE_H / 2 < pt.y && mole.y + MOLE_H / 2 > pt.y) &&
			(elephant.x - ELEPHANT_W / 2 < pt.x && elephant.x + ELEPHANT_W / 2 > pt.x&& elephant.y - ELEPHANT_H / 2 < pt.y && elephant.y + ELEPHANT_H / 2 > pt.y))
		{
			animalInterlap(&mole, &elephant);
		}
		//�J�o�ƃ��O�����d�Ȃ��Ă����ꍇ
		if ((mole.x - MOLE_W / 2 < pt.x && mole.x + MOLE_W / 2 > pt.x && mole.y - MOLE_H / 2 < pt.y && mole.y + MOLE_H / 2 > pt.y) &&
			(hippopotamus.x - HIPPOPOTAMUS_W / 2 < pt.x && hippopotamus.x + HIPPOPOTAMUS_W / 2 > pt.x&& hippopotamus.y - HIPPOPOTAMUS_H / 2 < pt.y && hippopotamus.y + HIPPOPOTAMUS_H / 2 > pt.y))
		{
			animalInterlap(&mole, &hippopotamus);
		}
		//���C�I���ƃJ�o���d�Ȃ��Ă����ꍇ
		if ((lion.x - LION_W / 2 < pt.x && lion.x + LION_W / 2 > pt.x && lion.y - LION_H / 2 < pt.y && lion.y + LION_H / 2 > pt.y) &&
			(hippopotamus.x - HIPPOPOTAMUS_W / 2 < pt.x && hippopotamus.x + HIPPOPOTAMUS_W / 2 > pt.x&& hippopotamus.y - HIPPOPOTAMUS_H / 2 < pt.y && hippopotamus.y + HIPPOPOTAMUS_H / 2 > pt.y))
		{
			animalInterlap(&lion, &hippopotamus);
		}
		//���C�I���ƃ��O�����d�Ȃ��Ă����ꍇ
		if ((mole.x - MOLE_W / 2 < pt.x && mole.x + MOLE_W / 2 > pt.x && mole.y - MOLE_H / 2 < pt.y && mole.y + MOLE_H / 2 > pt.y) &&
			(lion.x - LION_W / 2 < pt.x && lion.x + LION_W / 2 > pt.x && lion.y - LION_H / 2 < pt.y && lion.y + LION_H / 2 > pt.y))
		{
			animalInterlap(&mole, &lion);
		}
		//���X�ƃ]�E���d�Ȃ��Ă����ꍇ
		if ((risu.x - RISU_W / 2 < pt.x && risu.x + RISU_W / 2 > pt.x && risu.y - RISU_H / 2 < pt.y && risu.y + RISU_H / 2 > pt.y) &&
			(elephant.x - ELEPHANT_W / 2 < pt.x && elephant.x + ELEPHANT_W / 2 > pt.x&& elephant.y - ELEPHANT_H / 2 < pt.y && elephant.y + ELEPHANT_H / 2 > pt.y))
		{
			animalInterlap(&risu, &elephant);
		}
		//���X�ƃJ�o���d�Ȃ��Ă����ꍇ
		if ((risu.x - RISU_W / 2 < pt.x && risu.x + RISU_W / 2 > pt.x && risu.y - RISU_H / 2 < pt.y && risu.y + RISU_H / 2 > pt.y) &&
			(hippopotamus.x - HIPPOPOTAMUS_W / 2 < pt.x && hippopotamus.x + HIPPOPOTAMUS_W / 2 > pt.x&& hippopotamus.y - HIPPOPOTAMUS_H / 2 < pt.y && hippopotamus.y + HIPPOPOTAMUS_H / 2 > pt.y))
		{
			animalInterlap(&risu, &hippopotamus);
		}//���X�ƃ��C�I�����d�Ȃ��Ă����ꍇ
		if ((risu.x - RISU_W / 2 < pt.x && risu.x + RISU_W / 2 > pt.x && risu.y - RISU_H / 2 < pt.y && risu.y + RISU_H / 2 > pt.y) &&
			(lion.x - LION_W / 2 < pt.x && lion.x + LION_W / 2 > pt.x && lion.y - LION_H / 2 < pt.y && lion.y + LION_H / 2 > pt.y))
		{
			animalInterlap(&risu, &lion);
		}//���X�ƃ��O�����d�Ȃ��Ă����ꍇ
		if ((risu.x - RISU_W / 2 < pt.x && risu.x + RISU_W / 2 > pt.x && risu.y - RISU_H / 2 < pt.y && risu.y + RISU_H / 2 > pt.y) &&
			(mole.x - MOLE_W / 2 < pt.x && mole.x + MOLE_W / 2 > pt.x && mole.y - MOLE_H / 2 < pt.y && mole.y + MOLE_H / 2 > pt.y))
		{
			animalInterlap(&risu, &mole);
		}
		//�J�o�̍��W���ŃN���b�N���ꂽ�ꍇ��~
		else if (hippopotamus.x - HIPPOPOTAMUS_W / 2 < pt.x && hippopotamus.x + HIPPOPOTAMUS_W / 2 > pt.x && hippopotamus.y - HIPPOPOTAMUS_H / 2 < pt.y && hippopotamus.y + HIPPOPOTAMUS_H / 2 > pt.y && hippopotamus.Skip == 0)
		{
			click5(&hippopotamus,&elephant,&risu,&lion,&mole);
		}
		//�]�E�̍��W���ŃN���b�N���ꂽ�ꍇ��~
		else if (elephant.x - ELEPHANT_W / 2 < pt.x && elephant.x + ELEPHANT_W / 2 > pt.x && elephant.y - ELEPHANT_H / 2 < pt.y && elephant.y + ELEPHANT_H / 2 > pt.y && elephant.Skip == 0)
		{
			click5(&elephant, &hippopotamus, &risu, &lion, &mole);
		}
		//���X�̍��W���ŃN���b�N���ꂽ�ꍇ��~
		else if (risu.x - RISU_W / 2 < pt.x && risu.x + RISU_W / 2 > pt.x && risu.y - RISU_H / 2 < pt.y && risu.y + RISU_H / 2 > pt.y && risu.Skip == 0)
		{
			click5(&risu, &elephant, &hippopotamus, &lion, &mole);
		}//���C�I���̍��W���ŃN���b�N���ꂽ�ꍇ��~
		else if (lion.x - LION_W / 2 < pt.x && lion.x + LION_W / 2 > pt.x && lion.y - LION_H / 2 < pt.y && lion.y + LION_H / 2 > pt.y)
		{
			click5(&lion, &elephant, &risu, &hippopotamus, &mole);
		}//���O���̍��W���ŃN���b�N���ꂽ�ꍇ��~
		else if (mole.x - MOLE_W / 2 < pt.x && mole.x + MOLE_W / 2 > pt.x && mole.y - MOLE_H / 2 < pt.y && mole.y + MOLE_H / 2 > pt.y && mole.Skip == 0)
		{
			click5(&mole, &elephant, &risu, &lion, &hippopotamus);
		}
	}
}


//������E�ɗ����Ƃ��̂��̂����蔻��
void collision()
{
	//�J�o///////////////////////////////////////////////////////////
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
	//�����J�o���������Ă�����
	if (hippopotamus.Move&&chestnut.Active)
	{
		//�������Ă��邩�̔���
		if (chestnut.x - CHESTNUT_W < hippopotamus.x)
		{
			hippopotamus.Dead = true;
		}
	}
	//�����J�o���������Ă�����
	if (hippopotamus.Move&&chestnut2.Active)
	{
		//�������Ă��邩�̔���
		if (chestnut2.x - CHESTNUT_W < hippopotamus.x)
		{
			hippopotamus.Dead = true;
		}
	}
	//////////////////////////////////////////////////////////

	//�]�E///////////////////////////////////////////////////////////////////////
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
	//�����J�o���������Ă�����
	if (elephant.Move&&chestnut.Active)
	{
		//�������Ă��邩�̔���
		if (chestnut.x - CHESTNUT_W < elephant.x)
		{
			elephant.Dead = true;
		}
	}//�����J�o���������Ă�����
	if (elephant.Move&&chestnut2.Active)
	{
		//�������Ă��邩�̔���
		if (chestnut2.x - CHESTNUT_W < elephant.x)
		{
			elephant.Dead = true;
		}
	}
	///////////////////////////////////////////////////////////////

	//���X///////////////////////////////////////////////////////////////////
	if (risu.Move&&tree.Active)
	{
		//�������Ă��邩�̔���
		if (tree.x - TREE_W < risu.x)
		{
			risu.Dead = true;
		}
	}
	if (risu.Move&&tree2.Active)
	{
		//�������Ă��邩�̔���
		if (tree2.x - TREE_W < risu.x)
		{
			risu.Dead = true;
		}
	}
	if (risu.Move&&alligator.Active)
	{
		//�������Ă��邩�̔���
		if (alligator.x - ALLIGATOR_W < risu.x)
		{
			risu.Dead = true;
		}
	}
	///////////////////////////////////////////////////////////////////////////////////////////////

	//���O��///////////////////////////////////////////////////////////////////////////////////////
	if (mole.Move&&tree.Active)
	{
		//�������Ă��邩�̔���
		if (tree.x - TREE_W < mole.x)
		{
			mole.Dead = true;
		}
	}
	if (mole.Move&&tree2.Active)
	{
		//�������Ă��邩�̔���
		if (tree2.x - TREE_W < mole.x)
		{
			mole.Dead = true;
		}
	}
	if (mole.Move&&alligator.Active)
	{
		//�������Ă��邩�̔���
		if (alligator.x - ALLIGATOR_W < mole.x)
		{
			mole.Dead = true;
		}
	}
	if (mole.Move&&chestnut.Active)
	{
		//�������Ă��邩�̔���
		if (chestnut.x - CHESTNUT_W < mole.x)
		{
			mole.Dead = true;
		}
	}
	if (mole.Move&&chestnut2.Active)
	{
		//�������Ă��邩�̔���
		if (chestnut2.x - CHESTNUT_W < mole.x)
		{
			mole.Dead = true;
		}
	}
	///////////////////////////////////////////////////////////////
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
void animalInterlap(Animal *animal, Animal *animal2)
{
	if (animal->Move)
	{
		if (animal2->Move == true)
		{
			//�ǂ���������Ă���ꍇ���̒�~��D��
			animal->Move = false;
			animal2->Push = true;
		}

		//����ȊO(���͒�~���Ă���)�ꍇ�̓J�o��~�A���ړ�
		if (animal2->Push == false)
		{
			animal2->Move = true;
			animal->Move = false;
		}
		animal2->Push = false;
	}
	//�J�o����~���Ă��āA���������Ă���ꍇ
	else if (animal->Move == false)
	{
		if (animal2->Move == true)
		{
			animal2->Move = false;
			animal->Move = true;
		}
	}
}
void click2(Animal *animal, Animal *animal2)
{
	if (animal->Move)
	{
		//����������~���Ă���ꍇ�͑��͓����o��
		if (animal2->Move == false)
		{
			animal2->Move = true;
		}
		animal->Move = false;
	}
	else
	{
		animal->Move = true;
	}
}
//��ڂ̓������N���b�N���ꂽ�����A��ڂ��c��̓����A�O�ڂ����l
void click5(Animal *animal,Animal *animal2,Animal *animal3,Animal *animal4,Animal *animal5)
{
	if (animal->Move)
	{
		//����������~���Ă���ꍇ�͑��͓����o��
		if (animal2->Move == false)
		{
			animal2->Move = true;
		}
		if (animal3->Move == false)
		{
			animal3->Move = true;
		}
		if (animal4->Move == false)
		{
			animal4->Move = true;
		}
		if (animal5->Move == false)
		{
			animal5->Move = true;
		}
		animal->Move = false;
	}
	else
	{
		animal->Move = true;
	}
}