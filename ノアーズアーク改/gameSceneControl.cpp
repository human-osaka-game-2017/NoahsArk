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
			//ゲームタイトルの読み込み
			D3DXCreateTextureFromFile(
				g_pDirect3DDevice,
				"picture/noa!.png",
				&g_pGameTexture[GAMETITLE_TEX]
			);
		}
		if (g_pGameTexture[GAMESTART_TEX] == NULL)
		{
			//スタートボタンの読み込み
			D3DXCreateTextureFromFileEx(
				g_pDirect3DDevice,
				"picture/start.png",              // ファイル名
				0,
				0,
				0,
				0,
				D3DFMT_A1R5G5B5,                // 色抜きを可能に
				D3DPOOL_MANAGED,
				D3DX_FILTER_LINEAR,
				D3DX_FILTER_LINEAR,
				D3DCOLOR_ARGB(255, 0, 255, 0),  //緑を透過
				NULL,
				NULL,
				&g_pGameTexture[GAMESTART_TEX]           // テクスチャ名
			);
		}

		if (g_pGameTexture[SERECT_TEX] == NULL)
		{
			//セレクト画面の読み込み
			D3DXCreateTextureFromFile(
				g_pDirect3DDevice,
				"picture/serect.png",
				&g_pGameTexture[SERECT_TEX]);
		}
		if (g_pGameTexture[SERECTSTAGE_TEX] == NULL)
		{
			//セレクト画面の読み込み
			D3DXCreateTextureFromFile(
				g_pDirect3DDevice,
				"picture/stage.png",
				&g_pGameTexture[SERECTSTAGE_TEX]);
		}

		if (g_pGameTexture[SERECT1_TEX] == NULL)
		{
			//セレクト画面の読み込み
			D3DXCreateTextureFromFile(
				g_pDirect3DDevice,
				"picture/1.png",
				&g_pGameTexture[SERECT1_TEX]);
		}
		if (g_pGameTexture[SERECT2_TEX] == NULL)
		{
			//セレクト画面の読み込み
			D3DXCreateTextureFromFile(
				g_pDirect3DDevice,
				"picture/2.png",
				&g_pGameTexture[SERECT2_TEX]);
		}
		if (g_pGameTexture[SERECT3_TEX] == NULL)
		{
			//セレクト画面の読み込み
			D3DXCreateTextureFromFile(
				g_pDirect3DDevice,
				"picture/3.png",
				&g_pGameTexture[SERECT3_TEX]);
		}
		if (g_pGameTexture[SERECT4_TEX] == NULL)
		{
			//セレクト画面の読み込み
			D3DXCreateTextureFromFile(
				g_pDirect3DDevice,
				"picture/4.png",
				&g_pGameTexture[SERECT4_TEX]);
		}
		if (g_pGameTexture[SERECT5_TEX] == NULL)
		{
			//セレクト画面の読み込み
			D3DXCreateTextureFromFile(
				g_pDirect3DDevice,
				"picture/5.png",
				&g_pGameTexture[SERECT5_TEX]);
		}
		if (g_pGameTexture[SERECT6_TEX] == NULL)
		{
			//セレクト画面の読み込み
			D3DXCreateTextureFromFile(
				g_pDirect3DDevice,
				"picture/6.png",
				&g_pGameTexture[SERECT6_TEX]);
		}
		if (g_pGameTexture[SERECT7_TEX] == NULL)
		{
			//セレクト画面の読み込み
			D3DXCreateTextureFromFile(
				g_pDirect3DDevice,
				"picture/7.png",
				&g_pGameTexture[SERECT7_TEX]);
		}
		if (g_pGameTexture[SERECTBUTTON_TEX] == NULL)
		{
			//セレクト画面の読み込み
			D3DXCreateTextureFromFile(
				g_pDirect3DDevice,
				"picture/maru.png",
				&g_pGameTexture[SERECTBUTTON_TEX]);
		}
		if (g_pGameTexture[BACKGROUND_TEX] == NULL)
		{
			// ゲームシーンの背景の読み込み
			D3DXCreateTextureFromFile(
				g_pDirect3DDevice,
				"picture/background.png",
				&g_pGameTexture[BACKGROUND_TEX]);
		}
		if (g_pGameTexture[SHIP_TEX] == NULL)
		{
			// 船の読み込み
			D3DXCreateTextureFromFileEx(
				g_pDirect3DDevice,
				"picture/ship.png",              // ファイル名
				0,
				0,
				0,
				0,
				D3DFMT_A1R5G5B5,                // 色抜きを可能に
				D3DPOOL_MANAGED,
				D3DX_FILTER_LINEAR,
				D3DX_FILTER_LINEAR,
				D3DCOLOR_ARGB(255, 0, 255, 0),  //緑を透過
				NULL,
				NULL,
				&g_pGameTexture[SHIP_TEX]           // テクスチャ名
			);
		}
		if (g_pGameTexture[HIPPOPOTAMUS_TEX] == NULL)
		{
			// カバの読み込み
			D3DXCreateTextureFromFileEx(
				g_pDirect3DDevice,
				"picture/hippopotamus.png",              // ファイル名
				0,
				0,
				0,
				0,
				D3DFMT_A1R5G5B5,                // 色抜きを可能に
				D3DPOOL_MANAGED,
				D3DX_FILTER_LINEAR,
				D3DX_FILTER_LINEAR,
				D3DCOLOR_ARGB(255, 0, 255, 0),  //緑を透過
				NULL,
				NULL,
				&g_pGameTexture[HIPPOPOTAMUS_TEX]           // テクスチャ名
			);
		}
		if (g_pGameTexture[ELEPHANT_TEX] == NULL)
		{
			//ゾウの読み込み
			D3DXCreateTextureFromFile(
				g_pDirect3DDevice,
				"picture/elephant.png",
				&g_pGameTexture[ELEPHANT_TEX]);
		}
		if (g_pGameTexture[TREE_TEX] == NULL)
		{
			//木の読み込み
			D3DXCreateTextureFromFile(
				g_pDirect3DDevice,
				"picture/tree.png",
				&g_pGameTexture[TREE_TEX]);
		}
		if (g_pGameTexture[ALLIGATOR_TEX] == NULL)
		{
			//ワニの読み込み
			D3DXCreateTextureFromFile(
				g_pDirect3DDevice,
				"picture/alligator.png",
				&g_pGameTexture[ALLIGATOR_TEX]);
		}
		if (g_pGameTexture[KUSA_TEX] == NULL)
		{
			//草むらの読み込み
			D3DXCreateTextureFromFile(
				g_pDirect3DDevice,
				"picture/kusa.png",
				&g_pGameTexture[KUSA_TEX]);
		}

		if (g_pGameTexture[RISU_TEX] == NULL)
		{
			//リスの読み込み
			D3DXCreateTextureFromFileEx(
				g_pDirect3DDevice,
				"picture/risu(2).png",
				0,
				0,
				0,
				0,
				D3DFMT_A1R5G5B5,                // 色抜きを可能に
				D3DPOOL_MANAGED,
				D3DX_FILTER_LINEAR,
				D3DX_FILTER_LINEAR,
				D3DCOLOR_ARGB(255, 0, 255, 0),  //緑を透過
				NULL,
				NULL,
				&g_pGameTexture[RISU_TEX]
			);
		}
		if (g_pGameTexture[CHESTNUT_TEX] == NULL)
		{
			//栗の読み込み
			D3DXCreateTextureFromFileEx(
				g_pDirect3DDevice,
				"picture/kuri.png",
				0,
				0,
				0,
				0,
				D3DFMT_A1R5G5B5,                // 色抜きを可能に
				D3DPOOL_MANAGED,
				D3DX_FILTER_LINEAR,
				D3DX_FILTER_LINEAR,
				D3DCOLOR_ARGB(255, 0, 255, 0),  //緑を透過
				NULL,
				NULL,
				&g_pGameTexture[CHESTNUT_TEX]
			);
		}
		if (g_pGameTexture[LION_TEX] == NULL)
		{
			//ライオンの読み込み
			D3DXCreateTextureFromFile(
				g_pDirect3DDevice,
				"picture/lion.png",
				&g_pGameTexture[LION_TEX]);
		}
		if (g_pGameTexture[MOLE_TEX] == NULL)
		{
			// カバの読み込み
			D3DXCreateTextureFromFileEx(
				g_pDirect3DDevice,
				"picture/mole.png",              // ファイル名
				0,
				0,
				0,
				0,
				D3DFMT_A1R5G5B5,                // 色抜きを可能に
				D3DPOOL_MANAGED,
				D3DX_FILTER_LINEAR,
				D3DX_FILTER_LINEAR,
				D3DCOLOR_ARGB(255, 0, 255, 0),  //緑を透過
				NULL,
				NULL,
				&g_pGameTexture[MOLE_TEX]           // テクスチャ名
			);
		}
	
		if (g_pGameTexture[BARRICADE_TEX] == NULL)
		{
			//障害物の読み込み
			D3DXCreateTextureFromFile(
				g_pDirect3DDevice,
				"picture/barricade.png",
				&g_pGameTexture[BARRICADE_TEX]);
		}
		if (g_pGameTexture[HOLE_TEX] == NULL)
		{
			//穴の読み込み
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
			// ゲームオーバーの読み込み
			D3DXCreateTextureFromFileEx(
				g_pDirect3DDevice,
				"picture/gameover.png",              // ファイル名
				0,
				0,
				0,
				0,
				D3DFMT_A1R5G5B5,                // 色抜きを可能に
				D3DPOOL_MANAGED,
				D3DX_FILTER_LINEAR,
				D3DX_FILTER_LINEAR,
				D3DCOLOR_ARGB(255, 0, 255, 0),  //緑を透過
				NULL,
				NULL,
				&g_pGameTexture[GAMEOVER_TEX]           // テクスチャ名
			);
			if (g_pGameTexture[ONEMORE_TEX] == NULL)
			{
				// ゲームオーバーの読み込み
				D3DXCreateTextureFromFileEx(
					g_pDirect3DDevice,
					"picture/onemore.png",              // ファイル名
					0,
					0,
					0,
					0,
					D3DFMT_A1R5G5B5,                // 色抜きを可能に
					D3DPOOL_MANAGED,
					D3DX_FILTER_LINEAR,
					D3DX_FILTER_LINEAR,
					D3DCOLOR_ARGB(255, 0, 255, 0),  //緑を透過
					NULL,
					NULL,
					&g_pGameTexture[ONEMORE_TEX]           // テクスチャ名
				);
			}
			if (g_pGameTexture[CLEARGROUND_TEX] == NULL)
			{
				//障害物の読み込み
				D3DXCreateTextureFromFile(
					g_pDirect3DDevice,
					"picture/clearground.png",
					&g_pGameTexture[CLEARGROUND_TEX]);
			}
			if (g_pGameTexture[GAMECLEAR_TEX] == NULL)
			{
				// ゲームクリアの読み込み
				D3DXCreateTextureFromFileEx(
					g_pDirect3DDevice,
					"picture/clear.png",              // ファイル名
					0,
					0,
					0,
					0,
					D3DFMT_A1R5G5B5,                // 色抜きを可能に
					D3DPOOL_MANAGED,
					D3DX_FILTER_LINEAR,
					D3DX_FILTER_LINEAR,
					D3DCOLOR_ARGB(255, 0, 255, 0),  //緑を透過
					NULL,
					NULL,
					&g_pGameTexture[GAMECLEAR_TEX]           // テクスチャ名
				); if (g_pGameTexture[NEXT_TEX] == NULL)
				{
					// 次のステージの読み込み
					D3DXCreateTextureFromFileEx(
						g_pDirect3DDevice,
						"picture/next.png",              // ファイル名
						0,
						0,
						0,
						0,
						D3DFMT_A1R5G5B5,                // 色抜きを可能に
						D3DPOOL_MANAGED,
						D3DX_FILTER_LINEAR,
						D3DX_FILTER_LINEAR,
						D3DCOLOR_ARGB(255, 0, 255, 0),  //緑を透過
						NULL,
						NULL,
						&g_pGameTexture[NEXT_TEX]           // テクスチャ名
					);
				}



				if (g_pGameTexture[STAR1_TEX] == NULL)
				{
					// 次のステージの読み込み
					D3DXCreateTextureFromFileEx(
						g_pDirect3DDevice,
						"picture/hyouka01.png",              // ファイル名
						0,
						0,
						0,
						0,
						D3DFMT_A1R5G5B5,                // 色抜きを可能に
						D3DPOOL_MANAGED,
						D3DX_FILTER_LINEAR,
						D3DX_FILTER_LINEAR,
						D3DCOLOR_ARGB(255, 0, 255, 0),  //緑を透過
						NULL,
						NULL,
						&g_pGameTexture[STAR1_TEX]           // テクスチャ名
					);
				}

				if (g_pGameTexture[STAR2_TEX] == NULL)
				{
					// 次のステージの読み込み
					D3DXCreateTextureFromFileEx(
						g_pDirect3DDevice,
						"picture/hyouka02.png",              // ファイル名
						0,
						0,
						0,
						0,
						D3DFMT_A1R5G5B5,                // 色抜きを可能に
						D3DPOOL_MANAGED,
						D3DX_FILTER_LINEAR,
						D3DX_FILTER_LINEAR,
						D3DCOLOR_ARGB(255, 0, 255, 0),  //緑を透過
						NULL,
						NULL,
						&g_pGameTexture[STAR2_TEX]           // テクスチャ名
					);
				}

				if (g_pGameTexture[STAR3_TEX] == NULL)
				{
					// 次のステージの読み込み
					D3DXCreateTextureFromFileEx(
						g_pDirect3DDevice,
						"picture/hyouka03.png",              // ファイル名
						0,
						0,
						0,
						0,
						D3DFMT_A1R5G5B5,                // 色抜きを可能に
						D3DPOOL_MANAGED,
						D3DX_FILTER_LINEAR,
						D3DX_FILTER_LINEAR,
						D3DCOLOR_ARGB(255, 0, 255, 0),  //緑を透過
						NULL,
						NULL,
						&g_pGameTexture[STAR3_TEX]           // テクスチャ名
					);
				}




				prevscene = scene;
			}
		}
	}
}