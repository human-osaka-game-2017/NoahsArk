#include "Mouse.h"
#include "GameScene.h"
#include "animal.h"
#include "Control.h"

bool HitFlg = false;

//������x�͉E,��Q����x�͍�
Animal lion={56.f,500.f,true,false};   //���C�I��

Animal alligator = { 1000.f,500.f,true,false };   //���j(��Q��)

mob tree = { 756.f,500.f,false,false }; //��

mob tree2 = { 850.f,500.f,false,false };//��2


	enum BTN_STATE 
	{
		ON,			// �@�������ςȂ�
		OFF,		//�@�@������ςȂ�
		PUSH,		//�@�@�u�ԉ����ꂽ
		RELEASE,	//�@�@�u�ԗ����ꂽ
	};

	BTN_STATE g_OldMouse = OFF;
	BTN_STATE g_CurrentMouse = OFF;

	bool g_MoveLion = true;
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
			if (g_MoveLion)
				{
					g_MoveLion = false;

				}
				else
				{

					g_MoveLion = true;
				}
		
	}
	
	if (g_MoveLion)
	{
		lion.x += MOVESPEED;

	}
}
//�����蔻��

void Hit()
{
	if (g_MoveLion)
	{
		if (tree.x<lion.x)
		{
			lion.x -= MOVESPEED;
		}
	}
}
