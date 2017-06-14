#ifndef GAMESCENE
#define GAMESCENE

#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1)
#define WINDOW_TITLE TEXT("ノアーズ・アーク")	// ウィンドウ名

#include <windows.h>
#include <d3d9.h>
#include <d3dx9.h>

struct CUSTOMVERTEX
{
	FLOAT	x, y, z, rhw;
	DWORD	color;
	FLOAT	tu, tv;
};

enum GAME_TEXTURE
{
	BACKGROUND_TEX,
	LION_TEX,
	ELEPHANT_TEX,
	GAMESCENE_MAX
};
// ゲームシーンの描画関数
void GameSceneDraw();

// ゲームシーンの初期化関数
void GameSceneInit();

// ゲームシーンの解放関数
void GameSceneFree();

void Movespeed();
extern CUSTOMVERTEX  g_rion[4];

extern LPDIRECT3D9			g_pDirect3D;		// DirectXオブジェクトのポインタ
extern LPDIRECT3DDEVICE9	g_pDirect3DDevice;	// DirectXデバイスのポインタ


#endif 

