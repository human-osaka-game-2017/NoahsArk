#include "Mouse.h"
#include "GameScene.h"
#include "char.h"
#include "Control.h"

bool DeadFlg = false;

Animal elephant = { 300.f,500.f,false };//�]�E

Animal lion = { 200.f,500.f,false };;  //���C�I��

mob alligator = { 1000.f,500.f,false };   //���j(��Q��)

mob tree = { 700.f,500.f,false }; //��

//mob chestnut = { 900.f,500.f,false };//�I


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

		////�]�E(�܂��摜�̒��������Ȃ��Ă��Q�[����ʂ̂ǂ�������������~�܂�j
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

//������E�ɗ����Ƃ��̂��̂����蔻��
void Cllide()
{
	//�������C�I�����������Ă�����
	if (g_MoveLion)
	{
		//�������Ă��邩�̔���
		if (tree.x - TREE_W  < lion.x)
		{
			DeadFlg = true;
		}
			
	}
	//�����]�E���������Ă�����
	if (g_Moveelephant)
	{
		//�������Ă��邩�̔���
		if (alligator.x - ALLIGATOR_W< elephant.x)
		{
			//�������Ă�����A���������ʒu�Ŏ~�܂�
			elephant.x -= MOVESPEEDELEPHANT;
		}
	}
}
void Kaiten(float kakudo, CUSTOMVERTEX src[], CUSTOMVERTEX dest[])
{
	float cx, cy;
	float rad;

	rad = D3DXToRadian(kakudo);

	cx = (src[0].x + src[1].x) / 2.0f;
	cy = (src[0].y + src[3].y) / 2.0f;
	for (int i = 0; i < 4; i++) {
		src[i].x -= cx;
		src[i].y -= cy;
			dest[i] = src[i];
			dest[i].x = src[i].x * cos(rad)
				- src[i].y * sin(rad);
			dest[i].y = src[i].x * sin(rad)
				+ src[i].y * cos(rad);
			src[i].x += cx;
			src[i].y += cy;
			dest[i].x += cx;
			dest[i].y += cy;
	}
}