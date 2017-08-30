#include "Control.h"
#include "GameScene.h"
#include "finish.h"
#include "Mouse.h"
#include "GameSceneScroll.h"
#include "gameSceneControl.h"
#include "title.h"
#include "sceneSelect.h"
#include "systemCount.h"
int prevscene = scene;
int scene = TITLESCENE;
void sceneControl()
{
		switch (scene)
		{
		case TITLESCENE:
			scene = title();
			break;
		case GEMESELECTION:
			scene = select();
			break;
		case STAGEONE:
			scene = GameSceneDraw();
			Control();
			collision();
			break;
		case GAMEOVER:
			scene = overSceneDraw();
			break;
		case GAMECLEAR:
			scene = clearSceneDraw();
			break;
		
		
	}
}
void  pictureDraw()
{
	if (prevscene != scene || scene == TITLESCENE)
	{
		switch (scene)
		{
		case TITLESCENE:
			//�Q�[���^�C�g���̓ǂݍ���
			D3DXCreateTextureFromFile(
				g_pDirect3DDevice,
				"picture/noa!.png",
				&g_pGameTexture[GAMETITLE_TEX]
			);
			//�X�^�[�g�{�^���̓ǂݍ���
			D3DXCreateTextureFromFileEx(
				g_pDirect3DDevice,
				"picture/start.png",              // �t�@�C����
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
				&g_pGameTexture[GAMESTART_TEX]           // �e�N�X�`����
			);
			break;
		case GEMESELECTION:

			//�Z���N�g��ʂ̓ǂݍ���
			D3DXCreateTextureFromFile(
				g_pDirect3DDevice,
				"picture/serect.png",
				&g_pGameTexture[SERECT_TEX]);
			break;
		case STAGEONE:
			// �Q�[���V�[���̔w�i�̓ǂݍ���
			D3DXCreateTextureFromFile(
				g_pDirect3DDevice,
				"picture/haikei.png",
				&g_pGameTexture[BACKGROUND_TEX]);


			// �Q�[���V�[���̔w�i�̓ǂݍ���
			D3DXCreateTextureFromFile(
				g_pDirect3DDevice,
				"picture/haikei.png",
				&g_pGameTexture[BACKGROUND_TEX]);
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

			//���C�I���̓ǂݍ���
			D3DXCreateTextureFromFile(
				g_pDirect3DDevice,
				"picture/hippopotamus.png",
				&g_pGameTexture[HIPPOPOTAMUS_TEX]);

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
			//���ނ�̓ǂݍ���
			D3DXCreateTextureFromFile(
				g_pDirect3DDevice,
				"picture/kusa.png",
				&g_pGameTexture[KUSA_TEX]);
			break;
		case GAMEOVER:
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
			break;
		case GAMECLEAR:

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
			break;

		}
	}
}
