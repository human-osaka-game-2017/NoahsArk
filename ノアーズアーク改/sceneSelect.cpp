#include "GameScene.h"
#include "Mouse.h"
#include "Control.h"
#include "gameSceneControl.h"

int selectStageControl()
{
	if (CheckMouseL() == PUSH)
	{
		if (0 < pt.x && 480 > pt.x && 350 < pt.y && 650 > pt.y)
		{
			scene = STAGEONE;
			return scene;
		}
		if (480 < pt.x && 960 > pt.x && 350 < pt.y && 650 > pt.y)
		{
			scene = STAGETWO;
			return scene;
		}
		if (480 < pt.x && 960 > pt.x && 350 < pt.y && 650 > pt.y)
		{
			scene = STAGETHREE;
			return scene;
		}

	}
}

//STAGEFOUR

int select()
{
	//�^�C�g���̒��_�����쐬����
	CUSTOMVERTEX  drawSelect[4]
	{
		{ 0.f , 0.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 1440.f, 0.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 1440.f, 650.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 0.f, 650.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	// ���_���̎w��
	g_pDirect3DDevice->SetFVF(D3DFVF_CUSTOMVERTEX);

	// ��ʂ̏���
	g_pDirect3DDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0x00, 0x00, 0x00), 1.0, 0);
	// �`����J�n
	g_pDirect3DDevice->BeginScene();

	selectStageControl();

	// �e�N�X�`�����X�e�[�W�Ɋ��蓖�Ă�
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[SERECT_TEX]);
	// �`��
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawSelect, sizeof(CUSTOMVERTEX));
	
	// �`����I��
	g_pDirect3DDevice->EndScene();
	// ��ʂɕ\��
	g_pDirect3DDevice->Present(NULL, NULL, NULL, NULL);
	return scene;
}