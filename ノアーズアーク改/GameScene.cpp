#include "GameScene.h"
#include <stdio.h>
#include"Control.h"

#define MOVESPEED 5.f

// �Q�[���V�[���̉摜�������Ă����z��
LPDIRECT3DTEXTURE9			g_pGameTexture[GAMESCENE_MAX];

/*float animalspeed;
void Movespeed(void) {
	for (int i = 0; i < 4; i++) {

		g_rion[i].x += MOVESPEED;
		g_elephant[i].x += MOVESPEED;
	}
}*/


// �Q�[���V�[���̕`��֐�
void GameSceneDraw()
{
	
	// �o�b�N�O���E���h�̒��_�����쐬����
	CUSTOMVERTEX backGround[4]
	{
		{ 0.f , 0.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 1280.f, 0.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 1280.f, 720.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 0.f, 720.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	
	//���C�I���̒��_���
	CUSTOMVERTEX  g_rion[4]
	{
		{ 0.f , 400.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 100.f , 400.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 100.f , 600.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 0.f, 600.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	//�]�E�̒��_���
	CUSTOMVERTEX  g_elephant[4]
	{
		{ 200.f, 400.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 300.f, 400.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 300.f, 600.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 200.f, 600.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
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

	CUSTOMVERTEX drawvertex[4];
	for (int i = 0; i < 4; i++) {
		drawvertex[i] = g_rion[i];
		drawvertex[i].x += rion.x;
	}

	// �e�N�X�`�����X�e�[�W�Ɋ��蓖�Ă�
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[LION_TEX]);
	// �`��
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawvertex, sizeof(CUSTOMVERTEX));
	// �e�N�X�`�����X�e�[�W�Ɋ��蓖�Ă�
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[ELEPHANT_TEX]);
	// �`��
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, g_elephant, sizeof(CUSTOMVERTEX));
	
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
		"rion.png",
		&g_pGameTexture[LION_TEX]);

	//�]�E�̓ǂݍ���
	D3DXCreateTextureFromFile(
		g_pDirect3DDevice,
		"zou.png",
		&g_pGameTexture[ELEPHANT_TEX]);


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
