#include "GameScene.h"
#include"Control.h"
#include "char.h"
#include "finish.h"
#include "lion.h"
#include "alligator.h"
#include "tree.h"
#include "elephant.h"


// ゲームシーンの画像情報を入れておく配列
LPDIRECT3DTEXTURE9			g_pGameTexture[GAMESCENE_MAX];

//船の頂点情報を作成する
CUSTOMVERTEX  ship[4]
{
	{ 1240.f , 100.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1440.f, 100.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1440.f, 500.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 1240.f, 500.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
};

// ゲームシーンの描画関数
void GameSceneDraw()
{

	//	イガクリの頂点情報
/*	CUSTOMVERTEX   chestnutvertex[4]
	{
		{ -CHESTNUT_W/2, -CHESTNUT_H/2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{  CHESTNUT_W/2, -CHESTNUT_H/2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{  CHESTNUT_W/2,  CHESTNUT_H/2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -CHESTNUT_W/2 , CHESTNUST_H/2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};*/
	// バックグラウンドの頂点情報を作成する
	CUSTOMVERTEX backGround[4]
	{
		{ 0.f , 0.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 1440.f, 0.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 1440.f, 720.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 0.f, 720.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	// 頂点情報の指定
	g_pDirect3DDevice->SetFVF(D3DFVF_CUSTOMVERTEX);

	// 画面の消去
	g_pDirect3DDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0x00, 0x00, 0x00), 1.0, 0);
	// 描画を開始
	g_pDirect3DDevice->BeginScene();

	//関数呼び出し
	elephantdraw();

	liondraw();

	alligatordraw();

	treedraw();

	finishdraw();

	// テクスチャをステージに割り当てる
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[BACKGROUND_TEX]);
	// 描画
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, backGround, sizeof(CUSTOMVERTEX));

	// テクスチャをステージに割り当てる
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[SHIP_TEX]);
	// 描画
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, ship, sizeof(CUSTOMVERTEX));
	//もしLionDeadFlgがtrueなら
	if (LionDeadFlg)
	{
		// テクスチャをステージに割り当てる
		g_pDirect3DDevice->SetTexture(0, g_pGameTexture[GAMEOVER_TEX]);
		// 描画
		g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, gameoverGrounddraw, sizeof(CUSTOMVERTEX));
	}
	//もしElephantDeadFlgがtrueなら
	if (ElephantDeadFlg)
	{
		// テクスチャをステージに割り当てる
		g_pDirect3DDevice->SetTexture(0, g_pGameTexture[GAMEOVER_TEX]);
		// 描画
		g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, gameoverGrounddraw, sizeof(CUSTOMVERTEX));
	}


	/*CUSTOMVERTEX drawchestnut[4];
	for (int i = 0; i < 4; i++)
	{
		drawchestnut[i] = chestnutvertex[i];
		drawchestnut[i].x += chestnut.x;
		drawchestnut[i].y += chestnut.y;
	}*/

	if (elephant.Active)
	{
		// テクスチャをステージに割り当てる
		g_pDirect3DDevice->SetTexture(0, g_pGameTexture[ELEPHANT_TEX]);
		// 描画
		g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawelephant, sizeof(CUSTOMVERTEX));
	}

	if (lion.Active)
	{
		// テクスチャをステージに割り当てる
		g_pDirect3DDevice->SetTexture(0, g_pGameTexture[LION_TEX]);
		// 描画
		g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawlion, sizeof(CUSTOMVERTEX));
	}
	if (tree.Active)
	{
		// テクスチャをステージに割り当てる
		g_pDirect3DDevice->SetTexture(0, g_pGameTexture[TREE_TEX]);
		// 描画
		g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawtree, sizeof(CUSTOMVERTEX));
	}
	
	if (alligator.Active)
	{
		// テクスチャをステージに割り当てる
		g_pDirect3DDevice->SetTexture(0, g_pGameTexture[ALLIGATOR_TEX]);
		// 描画
		g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawalligator, sizeof(CUSTOMVERTEX));
	}
	if (elephant.Active == false && lion.Active == false)
	{
		// テクスチャをステージに割り当てる
		g_pDirect3DDevice->SetTexture(0, g_pGameTexture[GAMECLEAR_TEX]);
		// 描画
		g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, gameclearGrounddraw, sizeof(CUSTOMVERTEX));
	}
	/*// テクスチャをステージに割り当てる
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[CHESTNUT]);
	// 描画
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawchestnut, sizeof(CUSTOMVERTEX));*/
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
		"haikei.png",
		&g_pGameTexture[BACKGROUND_TEX]);

	// 船の背景の読み込み
	D3DXCreateTextureFromFile(
		g_pDirect3DDevice,
		"ふね.png",
		&g_pGameTexture[SHIP_TEX]);
	//-------------------------------------
    //透過のやり方
	//-------------------------------------
	// ゲームクリアの読み込み
	D3DXCreateTextureFromFileEx(
		g_pDirect3DDevice,
		"Clear.png",              // ファイル名
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

	// ゲームオーバーの読み込み
	D3DXCreateTextureFromFileEx(
		g_pDirect3DDevice,
		"gameover.png",              // ファイル名
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
		&g_pGameTexture[ALLIGATOR_TEX]);

	//栗の読み込み
	/*D3DXCreateTextureFromFile(
		g_pDirect3DDevice,
		"kuri.png",
		&g_pGameTexture[CHESTNUT]);*/
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
