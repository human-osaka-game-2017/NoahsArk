#include "GameScene.h"
#include "Control.h"
#include "char.h"
#include "finish.h"
#include "hippopotamus.h"
#include "tree.h"
#include "elephant.h"
#include "risu.h"
#include "chestnut.h"
#include "GameSceneScroll.h"
#include "right.h"
#include "left.h"
#include "gameSceneControl.h"
#include "Value.h"


int deadCount2 = 0;


// �Q�[���V�[���̕`��֐�
int GameSceneDraw2()
{


	//���ނ�̒��_�����쐬����
	CUSTOMVERTEX kusavertex[4]
	{
		{ 0.f,0.f,1.f,1.f,0xFFFFFFFF,0.f,0.f },
		{ 1440.f,0.f,1.f,1.f,0xFFFFFFFF,1.f,0.f },
		{ 1440.f,650.f,1.f,1.f,0xFFFFFFFF,1.f,1.f },
		{ 0.f,650.f,1.f,1.f,0xFFFFFFFF,0.f,1.f }
	};

	// ���_���̎w��
	g_pDirect3DDevice->SetFVF(D3DFVF_CUSTOMVERTEX);

	// ��ʂ̏���
	g_pDirect3DDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0x00, 0x00, 0x00), 1.0, 0);
	// �`����J�n
	g_pDirect3DDevice->BeginScene();


	//�֐��Ăяo��

	

	elephantdraw();

	hippopotamusdraw();

	risudraw();

	treedraw();

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
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, ship, sizeof(CUSTOMVERTEX));
	
	//����LionDeadFlg��true�Ȃ�
	if (hippopotamus.Dead)
	{
		deadCount2++;
		if (deadCount2 > 60)
		{
			currentStage = STAGETWO;
			scene = GAMEOVER;
		}
	}
	//����ElephantDeadFlg��true�Ȃ�
	else if (elephant.Dead)
	{
		deadCount2++;
		if(deadCount2 >60)
		{
			currentStage = STAGETWO;
			scene = GAMEOVER;
		}
	}
	//����ElephantDeadFlg��true�Ȃ�
	else if (risu.Dead)
	{   
		deadCount2++;
		if (deadCount2 > 60)
		{
			currentStage = STAGETWO;
			value(scene);
			scene = GAMEOVER;
		}
	}
	if (elephant.Active)
	{
		// �e�N�X�`�����X�e�[�W�Ɋ��蓖�Ă�
		g_pDirect3DDevice->SetTexture(0, g_pGameTexture[ELEPHANT_TEX]);
		// �`��
		g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawelephant, sizeof(CUSTOMVERTEX));
	}
	if (hippopotamus.Active)
	{
		// �e�N�X�`�����X�e�[�W�Ɋ��蓖�Ă�
		g_pDirect3DDevice->SetTexture(0, g_pGameTexture[HIPPOPOTAMUS_TEX]);
		// �`��
		g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawhippopotamus, sizeof(CUSTOMVERTEX));
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
	if (tree2.Active)
	{
		// �e�N�X�`�����X�e�[�W�Ɋ��蓖�Ă�
		g_pDirect3DDevice->SetTexture(0, g_pGameTexture[TREE_TEX]);
		// �`��
		g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawtree2, sizeof(CUSTOMVERTEX));
	}
	if (chestnut.Active)
	{
		// �e�N�X�`�����X�e�[�W�Ɋ��蓖�Ă�
		g_pDirect3DDevice->SetTexture(0, g_pGameTexture[CHESTNUT_TEX]);
		// �`��
		g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawchestnut, sizeof(CUSTOMVERTEX));
	}
	if (chestnut2.Active)
	{
		// �e�N�X�`�����X�e�[�W�Ɋ��蓖�Ă�
		g_pDirect3DDevice->SetTexture(0, g_pGameTexture[CHESTNUT_TEX]);
		// �`��
		g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawchestnut2, sizeof(CUSTOMVERTEX));
	}
	//�e�N�X�`�����X�e�[�W�Ɋ��蓖�Ă�
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[KUSA_TEX]);
	//�`��
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, kusavertex, sizeof(CUSTOMVERTEX));
	if (elephant.Active == false && hippopotamus.Active == false && risu.Active == false)
	{
		nextStage = STAGETHREE;
		currentStage = STAGETWO;
		scene = GAMECLEAR;
	}
	// �`����I��
	g_pDirect3DDevice->EndScene();
	// ��ʂɕ\��
	g_pDirect3DDevice->Present(NULL, NULL, NULL, NULL);
	return scene;
}
