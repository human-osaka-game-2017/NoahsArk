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
	//タイトルの頂点情報を作成する
	CUSTOMVERTEX  drawtitle[4]
	{
		{ 320.f , 200.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 1120.f, 200.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 1120.f, 400.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 320.f, 400.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	//始めるの頂点情報を作成する
	CUSTOMVERTEX  drawstrat[4]
	{
		{ 420.f , 450.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 1020.f, 450.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 1020.f, 550.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 420.f, 550.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//タイトル背景の頂点情報を作成する
	CUSTOMVERTEX  drawtitleBack[4]
	{ { 0.f , 0.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1440.f, 0.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1440.f, 650.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f,650.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};


	// 頂点情報の指定
	g_pDirect3DDevice->SetFVF(D3DFVF_CUSTOMVERTEX);

	// 画面の消去
	g_pDirect3DDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0x00, 0x00, 0x00), 1.0, 0);
	// 描画を開始
	g_pDirect3DDevice->BeginScene();

	titleControl();


	// テクスチャをステージに割り当てる
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[BACKGROUND_TEX]);
	// 描画
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawtitleBack, sizeof(CUSTOMVERTEX));

	// テクスチャをステージに割り当てる
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[GAMETITLE_TEX]);

	
	// 描画
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawtitle, sizeof(CUSTOMVERTEX));
	// テクスチャをステージに割り当てる
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[GAMESTART_TEX]);
	// 描画
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawstrat, sizeof(CUSTOMVERTEX));
	// 描画を終了
	g_pDirect3DDevice->EndScene();
	// 画面に表示
	g_pDirect3DDevice->Present(NULL, NULL, NULL, NULL);
	return scene;
}