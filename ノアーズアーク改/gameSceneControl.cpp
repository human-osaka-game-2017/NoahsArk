#include "Control.h"
#include "GameScene.h"
#include "finish.h"
#include "Mouse.h"
#include "GameSceneScroll.h"
#include "gameSceneControl.h"
#include "title.h"
#include "sceneSelect.h"
#include "systemCount.h"
#include "hippopotamus.h"
#include "elephant.h"
#include "mole.h"
#include "lion.h"
#include "risu.h"
#include "tree.h"
#include "chestnut.h"
#include "hole.h"
#include "alligator.h"
#include"Sound.h"

extern LPDIRECTSOUND8      g_lpDS;
extern LPDIRECTSOUNDBUFFER g_lpSecondary;
extern LPDIRECTSOUNDBUFFER g_lpSecondary2;
extern LPDIRECTSOUNDBUFFER g_lpSecondary3;
extern LPDIRECTSOUNDBUFFER g_lpSecondary4;



int prevscene = NONE;
int scene = TITLESCENE;
int nextStage = 0;
int currentStage = 0;
float stageProgres = 0;
void sceneControl()
{
		switch (scene)
		{
		case TITLESCENE:
			scene = title();
			g_lpSecondary2->Play(0, 0, 0);
			break;
		case GEMESELECTION:
			scene = select();
			g_lpSecondary2->Stop();
			g_lpSecondary2->SetCurrentPosition(0);
			g_lpSecondary3->Play(0, 0, 0);
			if (scene == STAGEONE)
			{
				stageProgres = 1440.f;
				initsystemCount();
				initStage1alligator();
				initStage1elephant();
				initStage1hippopotamus();
				initStage1tree();
				g_lpSecondary3->Stop();
				g_lpSecondary3->SetCurrentPosition(0);
			}
			if (scene == STAGETWO)
			{
				stageProgres = 1440.f;
				initsystemCount();
				initStage26elephant();
				initStage2hippopotamus();
				initStage2risu();
				initStage2tree();
				initStage2chestnut();
				g_lpSecondary3->Stop();
				g_lpSecondary3->SetCurrentPosition(0);
			}
			if (scene == STAGETHREE)
			{
				stageProgres = 1440.f;
				initsystemCount();
				initStage3elephant();
				initStage3risu();
				initStage3hippopotamus();
				initStage3chestnut();
				initStage3tree();
				g_lpSecondary3->Stop();
				g_lpSecondary3->SetCurrentPosition(0);
			}
			if (scene == STAGEFOUR)
			{
				stageProgres = 1440.f;
				initsystemCount();
				initStage4elephant();
				initStage4risu();
				initStage4mole();
				initStage4chestnut();
				initStage4tree();
				initStage4hole();
				g_lpSecondary3->Stop();
				g_lpSecondary3->SetCurrentPosition(0);
			}
			if (scene == STAGEFIVE)
			{
				stageProgres = 2880.f;
				initStage5Ship();
				initBackground();
				initsystemCount();
				initStage5elephant();
				initStage5risu();
				initStage5hippopotamus();
				initStage5mole();
				initStage5tree();
				initStage5hole();
				initStage5alligator();
				initStage5chestnut();
				
				g_lpSecondary3->Stop();
				g_lpSecondary3->SetCurrentPosition(0);
			}
			break;
		case STAGEONE:
			systemCountF();
			scene = GameSceneDraw();
			g_lpSecondary->Play(0, 0, 0);
			Control();
			collision();
			break;
		case STAGETWO:
			systemCountF();
			scene = GameSceneDraw2();
			g_lpSecondary->Play(0, 0, 0);
			Control();
			collision();
			break;
		case STAGETHREE:
			systemCountF();
			scene = GameSceneDraw3();
			g_lpSecondary->Play(0, 0, 0);
			Control();
			collision();
			break;
		case STAGEFOUR:
			systemCountF();
			scene = GameSceneDraw4();
			g_lpSecondary->Play(0, 0, 0);
			Control();
			collision();
			break;
		case STAGEFIVE:
			systemCountF();
			scene = GameSceneDraw5();
			g_lpSecondary->Play(0, 0, 0);
			Control();
			collision();
			break;
		case STAGESIX:
			
		case STAGESEVEN:
			
		case STAGEEIGHT:

		case GAMEOVER:
			scene = overSceneDraw();

			g_lpSecondary->Stop();
			g_lpSecondary->SetCurrentPosition(0);
			if (scene == STAGEONE)
			{
				stageProgres = 1440.f;
				initsystemCount();
				initStage1alligator();
				initStage1elephant();
				initStage1hippopotamus();
				initStage1tree();
			}
			if (scene == STAGETWO)
			{
				stageProgres = 1440.f;
				initsystemCount();
				initStage26elephant();
				initStage2hippopotamus();
				initStage2risu();
				initStage2tree();
				initStage2chestnut();
			}
			if (scene == STAGETHREE)
			{
				stageProgres = 1440.f;
				initsystemCount();
				initStage3elephant();
				initStage3risu();
				initStage3hippopotamus();
				initStage3chestnut();
				initStage3tree();
			}
			if (scene == STAGEFOUR)
			{
				stageProgres = 1440.f;
				initsystemCount();
				initStage4elephant();
				initStage4risu();
				initStage4mole();
				initStage4chestnut();
				initStage4tree();
				initStage4hole();
			}
			if (scene == STAGEFIVE)
			{
				stageProgres = 2880.f;
				initStage5Ship();
				initBackground();
				initsystemCount();
				initStage5elephant();
				initStage5risu();
				initStage5hippopotamus();
				initStage5mole();
				initStage5tree();
				initStage5hole();
				initStage5alligator();
				initStage5chestnut();
			}
			break;
		case GAMECLEAR:
			scene = clearSceneDraw();

			g_lpSecondary->Stop();
			g_lpSecondary->SetCurrentPosition(0);
			if (scene == STAGEONE)
			{
				stageProgres = 1440.f;
				initsystemCount();
				initStage1alligator();
				initStage1elephant();
				initStage1hippopotamus();
				initStage1tree();
			}
			if (scene == STAGETWO)
			{
				stageProgres = 1440.f;
				initsystemCount();
				initStage26elephant();
				initStage2hippopotamus();
				initStage2risu();
				initStage2tree();
				initStage2chestnut();
			}
			if (scene == STAGETHREE)
			{
				stageProgres = 1440.f;
				initsystemCount();
				initStage3elephant();
				initStage3risu();
				initStage3hippopotamus();
				initStage3chestnut();
				initStage3tree();
			}
			if (scene == STAGEFOUR)
			{
				stageProgres = 1440.f;
				initsystemCount();
				initStage4elephant();
				initStage4risu();
				initStage4mole();
				initStage4chestnut();
				initStage4tree();
				initStage4hole();
			}
			
			if (scene == STAGEFIVE)
			{
				stageProgres = 2880.f;
				initStage5Ship();
				initBackground();
				initsystemCount();
				initStage5elephant();
				initStage5risu();
				initStage5hippopotamus();
				initStage5mole();
				initStage5tree();
				initStage5hole();
				initStage5alligator();
				initStage5chestnut();
			}
			break;
	}
}
void  pictureDraw()
{
	if (prevscene != scene)
	{

		if (g_pGameTexture[GAMETITLE_TEX] == NULL)
		{
			//�Q�[���^�C�g���̓ǂݍ���
			D3DXCreateTextureFromFile(
				g_pDirect3DDevice,
				"picture/noa!.png",
				&g_pGameTexture[GAMETITLE_TEX]
			);
		}
		if (g_pGameTexture[GAMESTART_TEX] == NULL)
		{
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
		}

		if (g_pGameTexture[SERECT_TEX] == NULL)
		{
			//�Z���N�g��ʂ̓ǂݍ���
			D3DXCreateTextureFromFile(
				g_pDirect3DDevice,
				"picture/serect.png",
				&g_pGameTexture[SERECT_TEX]);
		}
		if (g_pGameTexture[SERECTSTAGE_TEX] == NULL)
		{
			//�Z���N�g��ʂ̓ǂݍ���
			D3DXCreateTextureFromFile(
				g_pDirect3DDevice,
				"picture/stage.png",
				&g_pGameTexture[SERECTSTAGE_TEX]);
		}

		if (g_pGameTexture[SERECT1_TEX] == NULL)
		{
			//�Z���N�g��ʂ̓ǂݍ���
			D3DXCreateTextureFromFile(
				g_pDirect3DDevice,
				"picture/1.png",
				&g_pGameTexture[SERECT1_TEX]);
		}
		if (g_pGameTexture[SERECT2_TEX] == NULL)
		{
			//�Z���N�g��ʂ̓ǂݍ���
			D3DXCreateTextureFromFile(
				g_pDirect3DDevice,
				"picture/2.png",
				&g_pGameTexture[SERECT2_TEX]);
		}
		if (g_pGameTexture[SERECT3_TEX] == NULL)
		{
			//�Z���N�g��ʂ̓ǂݍ���
			D3DXCreateTextureFromFile(
				g_pDirect3DDevice,
				"picture/3.png",
				&g_pGameTexture[SERECT3_TEX]);
		}
		if (g_pGameTexture[SERECT4_TEX] == NULL)
		{
			//�Z���N�g��ʂ̓ǂݍ���
			D3DXCreateTextureFromFile(
				g_pDirect3DDevice,
				"picture/4.png",
				&g_pGameTexture[SERECT4_TEX]);
		}
		if (g_pGameTexture[SERECT5_TEX] == NULL)
		{
			//�Z���N�g��ʂ̓ǂݍ���
			D3DXCreateTextureFromFile(
				g_pDirect3DDevice,
				"picture/5.png",
				&g_pGameTexture[SERECT5_TEX]);
		}
		if (g_pGameTexture[SERECT6_TEX] == NULL)
		{
			//�Z���N�g��ʂ̓ǂݍ���
			D3DXCreateTextureFromFile(
				g_pDirect3DDevice,
				"picture/6.png",
				&g_pGameTexture[SERECT6_TEX]);
		}
		if (g_pGameTexture[SERECT7_TEX] == NULL)
		{
			//�Z���N�g��ʂ̓ǂݍ���
			D3DXCreateTextureFromFile(
				g_pDirect3DDevice,
				"picture/7.png",
				&g_pGameTexture[SERECT7_TEX]);
		}
		if (g_pGameTexture[SERECTBUTTON_TEX] == NULL)
		{
			//�Z���N�g��ʂ̓ǂݍ���
			D3DXCreateTextureFromFile(
				g_pDirect3DDevice,
				"picture/maru.png",
				&g_pGameTexture[SERECTBUTTON_TEX]);
		}
		if (g_pGameTexture[BACKGROUND_TEX] == NULL)
		{
			// �Q�[���V�[���̔w�i�̓ǂݍ���
			D3DXCreateTextureFromFile(
				g_pDirect3DDevice,
				"picture/background.png",
				&g_pGameTexture[BACKGROUND_TEX]);
		}
		if (g_pGameTexture[SHIP_TEX] == NULL)
		{
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
		}
		if (g_pGameTexture[HIPPOPOTAMUS_TEX] == NULL)
		{
			// �J�o�̓ǂݍ���
			D3DXCreateTextureFromFileEx(
				g_pDirect3DDevice,
				"picture/hippopotamus.png",              // �t�@�C����
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
				&g_pGameTexture[HIPPOPOTAMUS_TEX]           // �e�N�X�`����
			);
		}
		if (g_pGameTexture[ELEPHANT_TEX] == NULL)
		{
			//�]�E�̓ǂݍ���
			D3DXCreateTextureFromFile(
				g_pDirect3DDevice,
				"picture/elephant.png",
				&g_pGameTexture[ELEPHANT_TEX]);
		}
		if (g_pGameTexture[TREE_TEX] == NULL)
		{
			//�؂̓ǂݍ���
			D3DXCreateTextureFromFile(
				g_pDirect3DDevice,
				"picture/tree.png",
				&g_pGameTexture[TREE_TEX]);
		}
		if (g_pGameTexture[ALLIGATOR_TEX] == NULL)
		{
			//���j�̓ǂݍ���
			D3DXCreateTextureFromFile(
				g_pDirect3DDevice,
				"picture/alligator.png",
				&g_pGameTexture[ALLIGATOR_TEX]);
		}
		if (g_pGameTexture[KUSA_TEX] == NULL)
		{
			//���ނ�̓ǂݍ���
			D3DXCreateTextureFromFile(
				g_pDirect3DDevice,
				"picture/kusa.png",
				&g_pGameTexture[KUSA_TEX]);
		}

		if (g_pGameTexture[RISU_TEX] == NULL)
		{
			//���X�̓ǂݍ���
			D3DXCreateTextureFromFileEx(
				g_pDirect3DDevice,
				"picture/risu(2).png",
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
				&g_pGameTexture[RISU_TEX]
			);
		}
		if (g_pGameTexture[CHESTNUT_TEX] == NULL)
		{
			//�I�̓ǂݍ���
			D3DXCreateTextureFromFileEx(
				g_pDirect3DDevice,
				"picture/kuri.png",
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
				&g_pGameTexture[CHESTNUT_TEX]
			);
		}
		if (g_pGameTexture[LION_TEX] == NULL)
		{
			//���C�I���̓ǂݍ���
			D3DXCreateTextureFromFile(
				g_pDirect3DDevice,
				"picture/lion.png",
				&g_pGameTexture[LION_TEX]);
		}
		if (g_pGameTexture[MOLE_TEX] == NULL)
		{
			// �J�o�̓ǂݍ���
			D3DXCreateTextureFromFileEx(
				g_pDirect3DDevice,
				"picture/mole.png",              // �t�@�C����
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
				&g_pGameTexture[MOLE_TEX]           // �e�N�X�`����
			);
		}
	
		if (g_pGameTexture[BARRICADE_TEX] == NULL)
		{
			//��Q���̓ǂݍ���
			D3DXCreateTextureFromFile(
				g_pDirect3DDevice,
				"picture/barricade.png",
				&g_pGameTexture[BARRICADE_TEX]);
		}
		if (g_pGameTexture[HOLE_TEX] == NULL)
		{
			//���̓ǂݍ���
			D3DXCreateTextureFromFile(
				g_pDirect3DDevice,
				"picture/hole.png",
				&g_pGameTexture[HOLE_TEX]);
		}
		if (g_pGameTexture[RIGHT_TEX] == NULL)
		{
			D3DXCreateTextureFromFile(
				g_pDirect3DDevice,
				"picture/right.png",
				&g_pGameTexture[RIGHT_TEX]);
		}
		if (g_pGameTexture[LEFT_TEX] == NULL)
		{
			D3DXCreateTextureFromFile(
				g_pDirect3DDevice,
				"picture/left.png",
				&g_pGameTexture[LEFT_TEX]);
		}
		if (g_pGameTexture[GAMEOVER_TEX] == NULL)
		{
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
			if (g_pGameTexture[ONEMORE_TEX] == NULL)
			{
				// �Q�[���I�[�o�[�̓ǂݍ���
				D3DXCreateTextureFromFileEx(
					g_pDirect3DDevice,
					"picture/onemore.png",              // �t�@�C����
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
					&g_pGameTexture[ONEMORE_TEX]           // �e�N�X�`����
				);
			}
			if (g_pGameTexture[CLEARGROUND_TEX] == NULL)
			{
				//��Q���̓ǂݍ���
				D3DXCreateTextureFromFile(
					g_pDirect3DDevice,
					"picture/clearground.png",
					&g_pGameTexture[CLEARGROUND_TEX]);
			}
			if (g_pGameTexture[GAMECLEAR_TEX] == NULL)
			{
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
				); if (g_pGameTexture[NEXT_TEX] == NULL)
				{
					// ���̃X�e�[�W�̓ǂݍ���
					D3DXCreateTextureFromFileEx(
						g_pDirect3DDevice,
						"picture/next.png",              // �t�@�C����
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
						&g_pGameTexture[NEXT_TEX]           // �e�N�X�`����
					);
				}



				if (g_pGameTexture[STAR1_TEX] == NULL)
				{
					// ���̃X�e�[�W�̓ǂݍ���
					D3DXCreateTextureFromFileEx(
						g_pDirect3DDevice,
						"picture/hyouka01.png",              // �t�@�C����
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
						&g_pGameTexture[STAR1_TEX]           // �e�N�X�`����
					);
				}

				if (g_pGameTexture[STAR2_TEX] == NULL)
				{
					// ���̃X�e�[�W�̓ǂݍ���
					D3DXCreateTextureFromFileEx(
						g_pDirect3DDevice,
						"picture/hyouka02.png",              // �t�@�C����
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
						&g_pGameTexture[STAR2_TEX]           // �e�N�X�`����
					);
				}

				if (g_pGameTexture[STAR3_TEX] == NULL)
				{
					// ���̃X�e�[�W�̓ǂݍ���
					D3DXCreateTextureFromFileEx(
						g_pDirect3DDevice,
						"picture/hyouka03.png",              // �t�@�C����
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
						&g_pGameTexture[STAR3_TEX]           // �e�N�X�`����
					);
				}




				prevscene = scene;
			}
		}
	}
}