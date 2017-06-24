#include "GameScene.h"
#include"Control.h"
#include "char.h"



// �Q�[���V�[���̉摜�������Ă����z��
LPDIRECT3DTEXTURE9			g_pGameTexture[GAMESCENE_MAX];





// �Q�[���V�[���̕`��֐�
void GameSceneDraw()
{
	
	//���C�I���̒��_���

	CUSTOMVERTEX  lionvertex[4]
	{
		{ -LION_W /2 , -LION_H /2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{  LION_W /2 , -LION_H /2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{  LION_W /2 ,  LION_H /2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -LION_W /2 ,  LION_H /2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	//�]�E�̒��_���
	CUSTOMVERTEX  elephantvertex[4]
	{
		{ -ELEPHANT_W /2, -ELEPHANT_H /2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{  ELEPHANT_W /2, -ELEPHANT_H /2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{  ELEPHANT_W /2,  ELEPHANT_H /2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -ELEPHANT_W /2,  ELEPHANT_H /2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	//	�؂̒��_���
	CUSTOMVERTEX  treevertex[4]
	{
		{ -TREE_W /2, -TREE_H /2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{  TREE_W /2, -TREE_H /2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{  TREE_W /2,  TREE_H /2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -TREE_W /2,  TREE_H /2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	
	//	���j�̒��_���
	CUSTOMVERTEX   alligatorvertex[4]
	{
		{ -ALLIGATOR_W/2 , -ALLIGATOR_H/2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{  ALLIGATOR_W/2 , -ALLIGATOR_H/2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{  ALLIGATOR_W/2 ,  ALLIGATOR_H/2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -ALLIGATOR_W/2 ,  ALLIGATOR_H/2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//	���j�̒��_���
/*	CUSTOMVERTEX   chestnutvertex[4]
	{
		{ -CHESTNUT_W/2, -CHESTNUT_H/2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{  CHESTNUT_W/2, -CHESTNUT_H/2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{  CHESTNUT_W/2,  CHESTNUT_H/2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -CHESTNUT_W/2 , CHESTNUT_H/2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};*/
	// �o�b�N�O���E���h�̒��_�����쐬����
	CUSTOMVERTEX backGround[4]
	{
		{ 0.f , 0.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 1280.f, 0.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 1280.f, 720.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 0.f, 720.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	
	
	// ���_���̎w��
	g_pDirect3DDevice->SetFVF(D3DFVF_CUSTOMVERTEX);

	// ��ʂ̏���
	g_pDirect3DDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0x00, 0x00, 0x00), 1.0, 0);
	// �`����J�n
	g_pDirect3DDevice->BeginScene();


	// �e�N�X�`�����X�e�[�W�Ɋ��蓖�Ă�
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[BACKGROUND_TEX]);

	// �`��
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, backGround, sizeof(CUSTOMVERTEX));

	CUSTOMVERTEX drawlion[4];
	for (int i = 0; i < 4; i++) 
	{
		drawlion[i] = lionvertex[i];
		drawlion[i].x += lion.x;
		drawlion[i].y += lion.y;
	}
	CUSTOMVERTEX drawtree[4];
	for (int i = 0; i < 4; i++)
	{
		drawtree[i] = treevertex[i];
		drawtree[i].x += tree.x;
		drawtree[i].y += tree.y;
	}
	CUSTOMVERTEX drawalligator[4];
	for (int i = 0; i < 4; i++)
	{
		drawalligator[i] = alligatorvertex[i];
		drawalligator[i].x += alligator.x;
		drawalligator[i].y += alligator.y;
	}
	CUSTOMVERTEX drawelephant[4];
	for (int i = 0; i < 4; i++)
	{
		drawelephant[i] = elephantvertex[i];
		drawelephant[i].x += elephant.x;
		drawelephant[i].y += elephant.y;
	}
	/*CUSTOMVERTEX drawchestnut[4];
	for (int i = 0; i < 4; i++)
	{
		drawchestnut[i] = chestnutvertex[i];
		drawchestnut[i].x += chestnut.x;
		drawchestnut[i].y += chestnut.y;
	}*/


	// �e�N�X�`�����X�e�[�W�Ɋ��蓖�Ă�
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[LION_TEX]);
	// �`��
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawlion, sizeof(CUSTOMVERTEX));
	// �e�N�X�`�����X�e�[�W�Ɋ��蓖�Ă�
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[ELEPHANT_TEX]);
	// �`��
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawelephant, sizeof(CUSTOMVERTEX));
	// �e�N�X�`�����X�e�[�W�Ɋ��蓖�Ă�
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[TREE_TEX]);
	// �`��
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawtree, sizeof(CUSTOMVERTEX));
	
	// �e�N�X�`�����X�e�[�W�Ɋ��蓖�Ă�
	//g_pDirect3DDevice->SetTexture(0, g_pGameTexture[TREE_TEX]);
	// �`��
	//g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawtree, sizeof(CUSTOMVERTEX));

	// �e�N�X�`�����X�e�[�W�Ɋ��蓖�Ă�
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[ALLIGATOR]);
	// �`��
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawalligator, sizeof(CUSTOMVERTEX));

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

	// �Q�[���V�[���̔w�i�̓ǂݍ���
	D3DXCreateTextureFromFile(
		g_pDirect3DDevice,
		"test1.JPG",
		&g_pGameTexture[BACKGROUND_TEX]);

	//���C�I���̓ǂݍ���
	D3DXCreateTextureFromFile(
		g_pDirect3DDevice,
		"raionn2.png",
		&g_pGameTexture[LION_TEX]);

	//�]�E�̓ǂݍ���
	D3DXCreateTextureFromFile(
		g_pDirect3DDevice,
		"�]�E.png",
		&g_pGameTexture[ELEPHANT_TEX]);

	//�؂̓ǂݍ���
	D3DXCreateTextureFromFile(
		g_pDirect3DDevice,
		"tree.png",
		&g_pGameTexture[TREE_TEX]);

	//���j�̓ǂݍ���
	D3DXCreateTextureFromFile(
		g_pDirect3DDevice,
		"���j2.png",
		&g_pGameTexture[ALLIGATOR]);

	//�I�̓ǂݍ���
	/*D3DXCreateTextureFromFile(
		g_pDirect3DDevice,
		"kuri.png",
		&g_pGameTexture[CHESTNUT]);*/
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
