#ifndef GAMESCENE
#define GAMESCENE

#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1)
#define WINDOW_TITLE TEXT("ノアーズ・アーク")	// ウィンドウ名

#include <windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <stdio.h>

struct CUSTOMVERTEX
{
	FLOAT	x, y, z, rhw;
	DWORD	color;
	FLOAT	tu, tv;
};

enum GAME_TEXTURE
{
	BACKGROUND_TEX,
	SHIP_TEX,
	GAMEOVER_TEX,
	GAMECLEAR_TEX,
	GAMETITLE_TEX,
	GAMESTART_TEX,
	SERECT_TEX,
	SERECTSTAGE_TEX,
	SERECT1_TEX,
	SERECT2_TEX,
	SERECT3_TEX,
	SERECT4_TEX,
	SERECT5_TEX,
	SERECT6_TEX,
	SERECT7_TEX,
	SERECT8_TEX,
	SERECTBUTTON_TEX,
	LION_TEX,
	HIPPOPOTAMUS_TEX,
	ELEPHANT_TEX,
	RISU_TEX,
	MOLE_TEX,
	TREE_TEX,
	ALLIGATOR_TEX,
	CHESTNUT_TEX,
	HOLE_TEX,
	BARRICADE_TEX,
	KUSA_TEX,
	RIGHT_TEX,
	LEFT_TEX,
	ONEMORE_TEX,
	CLEARGROUND_TEX,
	NEXT_TEX,
	STAR1_TEX,
	STAR2_TEX,
	STAR3_TEX,
	GAMESCENE_MAX
};
// ゲームシーンの描画関数
int GameSceneDraw();
int GameSceneDraw2();
int GameSceneDraw3();
int GameSceneDraw4();
int GameSceneDraw5();
// ゲームシーンの初期化関数
void GameSceneInit();

// ゲームシーンの解放関数
void GameSceneFree();
extern CUSTOMVERTEX  ship[4];
extern LPDIRECT3DTEXTURE9			g_pGameTexture[GAMESCENE_MAX];
extern LPDIRECT3D9			g_pDirect3D;		// DirectXオブジェクトのポインタ
extern LPDIRECT3DDEVICE9	g_pDirect3DDevice;	// DirectXデバイスのポインタ
#endif 

