#include "Mouse.h"
#include "GameScene.h"
#include "char.h"
#include "Control.h"


Animal elephant = { 300.f,500.f,true,false };//�]�E

Animal lion = { 200.f,500.f,true,false };;  //���C�I��

mob alligator = { 1000.f,500.f,false,false };   //���j(��Q��)

mob tree = { 700.f,500.f,false,false }; //��

//mob chestnut = { 900.f,500.f,false,false };//�I



	enum BTN_STATE 
	{
		ON,			// �@�������ςȂ�
		OFF,		//�@�@������ςȂ�
		PUSH,		//�@�@�u�ԉ����ꂽ
		RELEASE,	//�@�@�u�ԗ����ꂽ
	};

	BTN_STATE g_OldMouse = OFF;
	BTN_STATE g_CurrentMouse = OFF;

	//�����������Ă��邩�~�܂��Ă��邩�̔���@�����Ă���Ƃ�true,�~�܂��Ă���Ƃ�false
	bool g_MoveLion = true;
	bool g_Moveelephant = true;

	
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
		////���C�I���i�܂��摜�̒��������Ȃ��Ă��Q�[����ʂ̂ǂ�������������~�܂�j
		if (g_MoveLion)
			{
				g_MoveLion = false;

			}
			else
			{

				g_MoveLion = true;
			}

		////�]�E�܂��摜�̒��������Ȃ��Ă��Q�[����ʂ̂ǂ�������������~�܂�j
			if (g_Moveelephant)
			{
				g_Moveelephant = false;

			}
			else
			{

				g_Moveelephant = true;
			}
		
	}
	
	if (g_MoveLion)
	{
		lion.x += MOVESPEEDLION;

	}

	if (g_Moveelephant)
	{
		elephant.x += MOVESPEEDELEPHANT;
	}


}
//�����蔻��

void Hit()
{
	//�������C�I�����������Ă�����
	if (g_MoveLion)
	{
		//�������Ă��邩�̔���
		if (tree.x -52 < lion.x)
		{
			//�������Ă�����A���������ʒu�Ŏ~�܂�
			lion.x -= MOVESPEEDLION;
		}
	}
	if (g_Moveelephant)
	{
		if (alligator.x -78 < elephant.x)
		{
			elephant.x -= MOVESPEEDELEPHANT;
		}
	}
}
