#include "GameScene.h"
#include <stdio.h>
#include"Control.h"



// ゲームシーンの画像情報を入れておく配列
LPDIRECT3DTEXTURE9			g_pGameTexture[GAMESCENE_MAX];

//ライオンの頂点情報
CUSTOMVERTEX  g_lion[4]
{
	{ 0.f , 544.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 56.f , 544.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 56.f , 600.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 600.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
};
//ゾウの頂点情報
CUSTOMVERTEX  g_elephant[4]
{
	{ 200.f, 400.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 300.f, 400.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 300.f, 600.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 200.f, 600.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
};
//	木の頂点情報
CUSTOMVERTEX  g_tree[4]
{
	{ 800.f , 544.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 856.f , 544.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 856.f , 600.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 800.f, 600.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
};
//	木２の頂点情報
CUSTOMVERTEX  g_tree2[4]
{
	{ 1200.f , 400.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1300.f , 400.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1300.f , 600.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 1200.f, 600.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
};
//	ワニの頂点情報
CUSTOMVERTEX   g_alligator[4]
{
	{ 1000.f , 544.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1056.f , 544.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1056.f , 600.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 1000.f, 600.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
};


void Movespeed(void) {
	for (int i = 0; i < 4; i++) {

		g_lion[i].x += MOVESPEED;
		g_elephant[i].x += MOVESPEED;
	}
}


// ゲームシーンの描画関数
void GameSceneDraw()
{
	
	// バックグラウンドの頂点情報を作成する
	CUSTOMVERTEX backGround[4]
	{
		{ 0.f , 0.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 1280.f, 0.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 1280.f, 720.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 0.f, 720.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	
	// 頂点情報の指定
	g_pDirect3DDevice->SetFVF(D3DFVF_CUSTOMVERTEX);

	// 画面の消去
	g_pDirect3DDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0x00, 0x00, 0x00), 1.0, 0);
	// 描画を開始
	g_pDirect3DDevice->BeginScene();
	// テクスチャをステージに割り当てる
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[BACKGROUND_TEX]);

	// 描画
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, backGround, sizeof(CUSTOMVERTEX));

	CUSTOMVERTEX drawlion[4];
	for (int i = 0; i < 4; i++) {
		drawlion[i] = g_lion[i];
		drawlion[i].x += lion.x;
	}



	// テクスチャをステージに割り当てる
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[LION_TEX]);
	// 描画
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawlion, sizeof(CUSTOMVERTEX));
	// テクスチャをステージに割り当てる
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[ELEPHANT_TEX]);
	// 描画
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, g_elephant, sizeof(CUSTOMVERTEX));
	// テクスチャをステージに割り当てる
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[TREE_TEX]);
	// 描画
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, g_tree, sizeof(CUSTOMVERTEX));
	
	// テクスチャをステージに割り当てる
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[TREE_TEX]);
	// 描画
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, g_tree2, sizeof(CUSTOMVERTEX));

	// テクスチャをステージに割り当てる
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[ALLIGATOR]);
	// 描画
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, g_alligator, sizeof(CUSTOMVERTEX));

	// 描画を終了
	g_pDirect3DDevice->EndScene();
	// 画面に表示
	g_pDirect3DDevice->Present(NULL, NULL, NULL, NULL);
}

// ゲームシーンの初期化関数
void GameSceneInit()
{
	// 描画の設定
	g_pDirect3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
	g_pDirect3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);  //SRCの設定
	g_pDirect3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	g_pDirect3DDevice->SetRenderState(D3DRS_DIFFUSEMATERIALSOURCE, D3DMCS_COLOR1);

	g_pDirect3DDevice->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	g_pDirect3DDevice->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);

	g_pDirect3DDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);

	g_pDirect3DDevice->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	g_pDirect3DDevice->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE);

	g_pDirect3DDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);

	// ゲームシーンの背景の読み込み
	D3DXCreateTextureFromFile(
		g_pDirect3DDevice,
		"test1.JPG",
		&g_pGameTexture[BACKGROUND_TEX]);

	//ライオンの読み込み
	D3DXCreateTextureFromFile(
		g_pDirect3DDevice,
		"raionn2.png",
		&g_pGameTexture[LION_TEX]);

	//ゾウの読み込み
	D3DXCreateTextureFromFile(
		g_pDirect3DDevice,
		"ゾウ.png",
		&g_pGameTexture[ELEPHANT_TEX]);

	//木の読み込み
	D3DXCreateTextureFromFile(
		g_pDirect3DDevice,
		"tree.png",
		&g_pGameTexture[TREE_TEX]);

	//ワニの読み込み
	D3DXCreateTextureFromFile(
		g_pDirect3DDevice,
		"ワニ2.png",
		&g_pGameTexture[ALLIGATOR]);

}
// ゲームシーンの解放関数
void GameSceneFree()
{
	// テクスチャを解放
	for (int i = 0; i < GAMESCENE_MAX; i++)
	{
		g_pGameTexture[i]->Release();
	}
}
