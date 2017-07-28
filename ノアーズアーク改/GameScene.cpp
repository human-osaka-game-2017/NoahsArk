#include "GameScene.h"
#include"Control.h"
#include "char.h"
#include "finish.h"
#include "lion.h"
#include "alligator.h"
#include "tree.h"
#include "elephant.h"
#include "GameSceneScroll.h"
#include "right.h"
#include "left.h"



// �Q�[���V�[���̉摜�������Ă����z��
LPDIRECT3DTEXTURE9			g_pGameTexture[GAMESCENE_MAX];


//�D�̒��_�����쐬����
CUSTOMVERTEX  ship[4]
{
	{ 1170.f , 100.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1440.f, 100.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1440.f, 450.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 1170.f, 450.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
};


// �Q�[���V�[���̕`��֐�
void GameSceneDraw(int time)
{
	//	�C�K�N���̒��_���
/*	CUSTOMVERTEX   chestnutvertex[4]
	{
		{ -CHESTNUT_W/2, -CHESTNUT_H/2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{  CHESTNUT_W/2, -CHESTNUT_H/2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{  CHESTNUT_W/2,  CHESTNUT_H/2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -CHESTNUT_W/2 , CHESTNUST_H/2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};*/
	

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

	elephantdraw(time);

	liondraw(time);

	alligatordraw();

	treedraw();

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
	// �e�N�X�`�����X�e�[�W�Ɋ��蓖�Ă�
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[RIGHT_TEX]);
	// �`��
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawright, sizeof(CUSTOMVERTEX));
	// �e�N�X�`�����X�e�[�W�Ɋ��蓖�Ă�
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[LEFT_TEX]);
	// �`��
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawleft, sizeof(CUSTOMVERTEX));
	//����LionDeadFlg��true�Ȃ�
	if (LionDeadFlg)
	{
		finishFlg = true;
	}
	//����ElephantDeadFlg��true�Ȃ�
	if (ElephantDeadFlg)
	{
		finishFlg = true;
	}

	/*CUSTOMVERTEX drawchestnut[4];
	for (int i = 0; i < 4; i++)
	{
		drawchestnut[i] = chestnutvertex[i];
		drawchestnut[i].x += chestnut.x;
		drawchestnut[i].y += chestnut.y;
	}*/

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

	if (alligator.Active)
	{
		// �e�N�X�`�����X�e�[�W�Ɋ��蓖�Ă�
		g_pDirect3DDevice->SetTexture(0, g_pGameTexture[ALLIGATOR_TEX]);
		// �`��
		g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawalligator, sizeof(CUSTOMVERTEX));
	}
	//�e�N�X�`�����X�e�[�W�Ɋ��蓖�Ă�
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[KUSA_TEX]);
	//�`��
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, kusavertex, sizeof(CUSTOMVERTEX));
	if (elephant.Active == false && lion.Active == false)
	{
		// �e�N�X�`�����X�e�[�W�Ɋ��蓖�Ă�
		g_pDirect3DDevice->SetTexture(0, g_pGameTexture[GAMECLEAR_TEX]);
		// �`��
		g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, gameclearGrounddraw, sizeof(CUSTOMVERTEX));
	}
	/*// �e�N�X�`�����X�e�[�W�Ɋ��蓖�Ă�
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[CHESTNUT]);
	// �`��
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawchestnut, sizeof(CUSTOMVERTEX));*/
	// �`����I��
	g_pDirect3DDevice->EndScene();
	// ��ʂɕ\��
	g_pDirect3DDevice->Present(NULL, NULL, NULL, NULL);
}

// �Q�[���V�[���̏������֐�
void GameSceneInit()
{
	// �`��̐ݒ�
	g_pDirect3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
	g_pDirect3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);  //SRC�̐ݒ�
	g_pDirect3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	g_pDirect3DDevice->SetRenderState(D3DRS_DIFFUSEMATERIALSOURCE, D3DMCS_COLOR1);

	g_pDirect3DDevice->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	g_pDirect3DDevice->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);

	g_pDirect3DDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);

	g_pDirect3DDevice->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	g_pDirect3DDevice->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE);

	g_pDirect3DDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);

	//     picture/haikei��/�͂��̃t�@�C���̒��ɓ����

	// �Q�[���V�[���̔w�i�̓ǂݍ���
	D3DXCreateTextureFromFile(
		g_pDirect3DDevice,
		"picture/haikei.png",
		&g_pGameTexture[BACKGROUND_TEX]);
	
	D3DXCreateTextureFromFile(
		g_pDirect3DDevice,
		"picture/right.png",
		&g_pGameTexture[RIGHT_TEX]);

	D3DXCreateTextureFromFile(
		g_pDirect3DDevice,
		"picture/left.png",
		&g_pGameTexture[LEFT_TEX]);

	//-------------------------------------
	//���߂̂���
	//-------------------------------------
	// �D�̓ǂݍ���
	D3DXCreateTextureFromFileEx(
		g_pDirect3DDevice,
		"picture/ship.png",              // �t�@�C����
		0,
		0,
		0,
		0,
		D3DFMT_A1R5G5B5,                // �F�������\��
		D3DPOOL_MANAGED,
		D3DX_FILTER_LINEAR,
		D3DX_FILTER_LINEAR,
		D3DCOLOR_ARGB(255, 0, 255, 0),  //�΂𓧉�
		NULL,
		NULL,
		&g_pGameTexture[SHIP_TEX]           // �e�N�X�`����
	);
	
	// �Q�[���N���A�̓ǂݍ���
	D3DXCreateTextureFromFileEx(
		g_pDirect3DDevice,
		"picture/clear.png",              // �t�@�C����
		0,
		0,
		0,
		0,
		D3DFMT_A1R5G5B5,                // �F�������\��
		D3DPOOL_MANAGED,
		D3DX_FILTER_LINEAR,
		D3DX_FILTER_LINEAR,
		D3DCOLOR_ARGB(255, 0, 255, 0),  //�΂𓧉�
		NULL,
		NULL,
		&g_pGameTexture[GAMECLEAR_TEX]           // �e�N�X�`����
	);

	// �Q�[���I�[�o�[�̓ǂݍ���
	D3DXCreateTextureFromFileEx(
		g_pDirect3DDevice,
		"picture/gameover.png",              // �t�@�C����
		0,
		0,
		0,
		0,
		D3DFMT_A1R5G5B5,                // �F�������\��
		D3DPOOL_MANAGED,
		D3DX_FILTER_LINEAR,
		D3DX_FILTER_LINEAR,
		D3DCOLOR_ARGB(255, 0, 255, 0),  //�΂𓧉�
		NULL,
		NULL,
		&g_pGameTexture[GAMEOVER_TEX]           // �e�N�X�`����
	);
	//���C�I���̓ǂݍ���
	D3DXCreateTextureFromFile(
		g_pDirect3DDevice,
		"picture/lion.png",
		&g_pGameTexture[LION_TEX]);

	//�]�E�̓ǂݍ���
	D3DXCreateTextureFromFile(
		g_pDirect3DDevice,
		"picture/elephant.png",
		&g_pGameTexture[ELEPHANT_TEX]);

	//�؂̓ǂݍ���
	D3DXCreateTextureFromFile(
		g_pDirect3DDevice,
		"picture/tree.png",
		&g_pGameTexture[TREE_TEX]);

	//���j�̓ǂݍ���
	D3DXCreateTextureFromFile(
		g_pDirect3DDevice,
		"picture/alligator.png",
		&g_pGameTexture[ALLIGATOR_TEX]);

	//�I�̓ǂݍ���
	/*D3DXCreateTextureFromFile(
	g_pDirect3DDevice,
	"picture/kuri.png",
	&g_pGameTexture[CHESTNUT]);*/

	//���ނ�̓ǂݍ���
	D3DXCreateTextureFromFile(
		g_pDirect3DDevice,
		"picture/kusa.png",
		&g_pGameTexture[KUSA_TEX]);
}

	// �Q�[���V�[���̉���֐�
void GameSceneFree()
{
	// �e�N�X�`�������
	for (int i = 0; i < GAMESCENE_MAX; i++)
	{
		g_pGameTexture[i]->Release();
	}
}
