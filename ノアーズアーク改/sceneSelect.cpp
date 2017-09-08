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
	//タイトルの頂点情報を作成する
	CUSTOMVERTEX  drawSelect[4]
	{
		{ 0.f , 0.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 1440.f, 0.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 1440.f, 650.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 0.f, 650.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	// 頂点情報の指定
	g_pDirect3DDevice->SetFVF(D3DFVF_CUSTOMVERTEX);

	// 画面の消去
	g_pDirect3DDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0x00, 0x00, 0x00), 1.0, 0);
	// 描画を開始
	g_pDirect3DDevice->BeginScene();

	selectStageControl();

	// テクスチャをステージに割り当てる
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[SERECT_TEX]);
	// 描画
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawSelect, sizeof(CUSTOMVERTEX));
	
	// 描画を終了
	g_pDirect3DDevice->EndScene();
	// 画面に表示
	g_pDirect3DDevice->Present(NULL, NULL, NULL, NULL);
	return scene;
}