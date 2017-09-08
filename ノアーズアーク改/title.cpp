#include "GameScene.h"
#include "Mouse.h"
#include "Control.h"
#include "gameSceneControl.h"

int titleControl()
{
	

	if (CheckMouseL() == PUSH)
	{
		if (420 < pt.x && 1020 > pt.x && 450 < pt.y && 550 > pt.y)
		{
			scene = GEMESELECTION;
		}
	}
	return scene;
}

int title()
{
	//�^�C�g���̒��_�����쐬����
	CUSTOMVERTEX  drawtitle[4]
	{
		{ 320.f , 200.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 1120.f, 200.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 1120.f, 400.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 320.f, 400.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	//�n�߂�̒��_�����쐬����
	CUSTOMVERTEX  drawstrat[4]
	{
		{ 420.f , 450.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 1020.f, 450.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 1020.f, 550.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 420.f, 550.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//�^�C�g���w�i�̒��_�����쐬����
	CUSTOMVERTEX  drawtitleBack[4]
	{ { 0.f , 0.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1440.f, 0.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1440.f, 650.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f,650.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};


	// ���_���̎w��
	g_pDirect3DDevice->SetFVF(D3DFVF_CUSTOMVERTEX);

	// ��ʂ̏���
	g_pDirect3DDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0x00, 0x00, 0x00), 1.0, 0);
	// �`����J�n
	g_pDirect3DDevice->BeginScene();

	titleControl();


	// �e�N�X�`�����X�e�[�W�Ɋ��蓖�Ă�
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[BACKGROUND_TEX]);
	// �`��
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawtitleBack, sizeof(CUSTOMVERTEX));

	// �e�N�X�`�����X�e�[�W�Ɋ��蓖�Ă�
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[GAMETITLE_TEX]);

	
	// �`��
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawtitle, sizeof(CUSTOMVERTEX));
	// �e�N�X�`�����X�e�[�W�Ɋ��蓖�Ă�
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[GAMESTART_TEX]);
	// �`��
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawstrat, sizeof(CUSTOMVERTEX));
	// �`����I��
	g_pDirect3DDevice->EndScene();
	// ��ʂɕ\��
	g_pDirect3DDevice->Present(NULL, NULL, NULL, NULL);
	return scene;
}