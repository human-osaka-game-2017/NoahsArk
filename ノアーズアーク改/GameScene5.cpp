#include "GameScene.h"
#include "Control.h"
#include "char.h"
#include "finish.h"
#include "lion.h"
#include "tree.h"
#include "elephant.h"
#include "risu.h"
#include "mole.h"
#include "chestnut.h"
#include "alligator.h"
#include "hole.h"
#include "GameSceneScroll.h"
#include "right.h"
#include "left.h"
#include "gameSceneControl.h"
#include "Value.h"


int deadCount5 = 0;
//�D�̒��_�����쐬����
CUSTOMVERTEX  ship2[4]
{
	{ 2690.f , 100.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 2880.f, 100.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 2880.f, 450.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 2690.f, 450.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
};
// �Q�[���V�[���̕`��֐�
int GameSceneDraw5()
{


	//���ނ�̒��_�����쐬����
	CUSTOMVERTEX kusavertex[4]
	{
		{ 0.f,0.f,1.f,1.f,0xFFFFFFFF,0.f,0.f },
		{ 2880.f,0.f,1.f,1.f,0xFFFFFFFF,1.f,0.f },
		{ 2880.f,620.f,1.f,1.f,0xFFFFFFFF,1.f,1.f },
		{ 0.f,620.f,1.f,1.f,0xFFFFFFFF,0.f,1.f }
	};

	// ���_���̎w��
	g_pDirect3DDevice->SetFVF(D3DFVF_CUSTOMVERTEX);

	// ��ʂ̏���
	g_pDirect3DDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0x00, 0x00, 0x00), 1.0, 0);
	// �`����J�n
	g_pDirect3DDevice->BeginScene();


	//�֐��Ăяo��

	scroll();

	elephantdraw();

	liondraw();

	moledraw();

	risudraw();

	holedraw();

	treedraw();

	alligatordraw();

	chestnutdraw();

	rightdraw();

	leftdraw();

	// �e�N�X�`�����X�e�[�W�Ɋ��蓖�Ă�
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[BACKGROUND_TEX]);
	// �`��
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, backGround, sizeof(CUSTOMVERTEX));

	// �e�N�X�`�����X�e�[�W�Ɋ��蓖�Ă�
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[BACKGROUND_TEX]);
	// �`��
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, backGround2, sizeof(CUSTOMVERTEX));

	// �e�N�X�`�����X�e�[�W�Ɋ��蓖�Ă�
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[SHIP_TEX]);
	// �`��
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, ship2, sizeof(CUSTOMVERTEX));
	// �e�N�X�`�����X�e�[�W�Ɋ��蓖�Ă�
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[RIGHT_TEX]);
	// �`��
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawright, sizeof(CUSTOMVERTEX));
	// �e�N�X�`�����X�e�[�W�Ɋ��蓖�Ă�
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[LEFT_TEX]);
	// �`��
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawleft, sizeof(CUSTOMVERTEX));
	if (elephant.Dead)
	{ 
		deadCount5++;
		if (deadCount5 > 60)
		{
			currentStage = STAGEFIVE;
			scene = GAMEOVER;
		}
	}
	//����ElephantDeadFlg��true�Ȃ�
	else if (risu.Dead)
	{
		deadCount5++;
		if (deadCount5 > 60)
		{
			currentStage = STAGEFIVE;
			scene = GAMEOVER;
		}
	}
	else if (lion.Dead)
	{
		deadCount5++;
		if (deadCount5 > 60)
		{
			currentStage = STAGEFIVE;
			scene = GAMEOVER;
		}
	}
	else if (mole.Dead)
		deadCount5++;
	if (deadCount5 > 60)
	{
		currentStage = STAGEFIVE;
		scene = GAMEOVER;
	}

	if (elephant.Active)
	{
		// �e�N�X�`�����X�e�[�W�Ɋ��蓖�Ă�
		g_pDirect3DDevice->SetTexture(0, g_pGameTexture[ELEPHANT_TEX]);
		// �`��
		g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawelephant, sizeof(CUSTOMVERTEX));
	}
	if (lion.Active)
	{
		// �e�N�X�`�����X�e�[�W�Ɋ��蓖�Ă�
		g_pDirect3DDevice->SetTexture(0, g_pGameTexture[LION_TEX]);
		// �`��
		g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawlion, sizeof(CUSTOMVERTEX));
	}
	if (mole.Active)
	{
		// �e�N�X�`�����X�e�[�W�Ɋ��蓖�Ă�
		g_pDirect3DDevice->SetTexture(0, g_pGameTexture[MOLE_TEX]);
		// �`��
		g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawmole, sizeof(CUSTOMVERTEX));
	}
	if (risu.Active)
	{
		// �e�N�X�`�����X�e�[�W�Ɋ��蓖�Ă�
		g_pDirect3DDevice->SetTexture(0, g_pGameTexture[RISU_TEX]);
		// �`��
		g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawrisu, sizeof(CUSTOMVERTEX));
	}
	if (tree.Active)
	{
		// �e�N�X�`�����X�e�[�W�Ɋ��蓖�Ă�
		g_pDirect3DDevice->SetTexture(0, g_pGameTexture[TREE_TEX]);
		// �`��
		g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawtree, sizeof(CUSTOMVERTEX));
	}
	if (alligator.Active)
	{
		// �e�N�X�`�����X�e�[�W�Ɋ��蓖�Ă�
		g_pDirect3DDevice->SetTexture(0, g_pGameTexture[ALLIGATOR_TEX]);
		// �`��
		g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawalligator, sizeof(CUSTOMVERTEX));
	}
	if (hole.Active)
	{
		// �e�N�X�`�����X�e�[�W�Ɋ��蓖�Ă�
		g_pDirect3DDevice->SetTexture(0, g_pGameTexture[HOLE_TEX]);
		// �`��
		g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawhole, sizeof(CUSTOMVERTEX));
	}
	if (hole2.Active)
	{
		// �e�N�X�`�����X�e�[�W�Ɋ��蓖�Ă�
		g_pDirect3DDevice->SetTexture(0, g_pGameTexture[HOLE_TEX]);
		// �`��
		g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawhole2, sizeof(CUSTOMVERTEX));
	}
	if (chestnut.Active)
	{
		// �e�N�X�`�����X�e�[�W�Ɋ��蓖�Ă�
		g_pDirect3DDevice->SetTexture(0, g_pGameTexture[CHESTNUT_TEX]);
		// �`��
		g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawchestnut, sizeof(CUSTOMVERTEX));
	}

	//�e�N�X�`�����X�e�[�W�Ɋ��蓖�Ă�
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[KUSA_TEX]);
	//�`��
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, kusavertex, sizeof(CUSTOMVERTEX));
	if (elephant.Active == false && risu.Active == false && lion.Active == false && mole.Active == false)
	{
		value(scene);
		scene = GAMECLEAR;
	}
	// �`����I��
	g_pDirect3DDevice->EndScene();
	// ��ʂɕ\��
	g_pDirect3DDevice->Present(NULL, NULL, NULL, NULL);
	return scene;
}

