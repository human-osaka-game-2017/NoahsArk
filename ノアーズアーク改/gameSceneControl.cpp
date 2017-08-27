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
			//ゲームタイトルの読み込み
			D3DXCreateTextureFromFile(
				g_pDirect3DDevice,
				"picture/noa!.png",
				&g_pGameTexture[GAMETITLE_TEX]
			);
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
			break;
		case GEMESELECTION:

			//セレクト画面の読み込み
			D3DXCreateTextureFromFile(
				g_pDirect3DDevice,
				"picture/serect.png",
				&g_pGameTexture[SERECT_TEX]);
			break;
		case STAGEONE:
			// ゲームシーンの背景の読み込み
			D3DXCreateTextureFromFile(
				g_pDirect3DDevice,
				"picture/haikei.png",
				&g_pGameTexture[BACKGROUND_TEX]);


			// ゲームシーンの背景の読み込み
			D3DXCreateTextureFromFile(
				g_pDirect3DDevice,
				"picture/haikei.png",
				&g_pGameTexture[BACKGROUND_TEX]);
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

			//ライオンの読み込み
			D3DXCreateTextureFromFile(
				g_pDirect3DDevice,
				"picture/hippopotamus.png",
				&g_pGameTexture[HIPPOPOTAMUS_TEX]);

			//ゾウの読み込み
			D3DXCreateTextureFromFile(
				g_pDirect3DDevice,
				"picture/elephant.png",
				&g_pGameTexture[ELEPHANT_TEX]);
			//木の読み込み
			D3DXCreateTextureFromFile(
				g_pDirect3DDevice,
				"picture/tree.png",
				&g_pGameTexture[TREE_TEX]);
			//ワニの読み込み
			D3DXCreateTextureFromFile(
				g_pDirect3DDevice,
				"picture/alligator.png",
				&g_pGameTexture[ALLIGATOR_TEX]);
			//草むらの読み込み
			D3DXCreateTextureFromFile(
				g_pDirect3DDevice,
				"picture/kusa.png",
				&g_pGameTexture[KUSA_TEX]);
			break;
		case GAMEOVER:
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
			break;
		case GAMECLEAR:

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
			);
			break;

		}
	}
}
