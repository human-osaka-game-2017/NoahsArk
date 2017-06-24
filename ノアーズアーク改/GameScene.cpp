#include "GameScene.h"
#include"Control.h"
#include "char.h"



// ゲームシーンの画像情報を入れておく配列
LPDIRECT3DTEXTURE9			g_pGameTexture[GAMESCENE_MAX];





// ゲームシーンの描画関数
void GameSceneDraw()
{
	
	//ライオンの頂点情報

	CUSTOMVERTEX  lionvertex[4]
	{
		{ -LION_W /2 , -LION_H /2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{  LION_W /2 , -LION_H /2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{  LION_W /2 ,  LION_H /2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -LION_W /2 ,  LION_H /2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	//ゾウの頂点情報
	CUSTOMVERTEX  elephantvertex[4]
	{
		{ -ELEPHANT_W /2, -ELEPHANT_H /2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{  ELEPHANT_W /2, -ELEPHANT_H /2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{  ELEPHANT_W /2,  ELEPHANT_H /2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -ELEPHANT_W /2,  ELEPHANT_H /2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	//	木の頂点情報
	CUSTOMVERTEX  treevertex[4]
	{
		{ -TREE_W /2, -TREE_H /2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{  TREE_W /2, -TREE_H /2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{  TREE_W /2,  TREE_H /2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -TREE_W /2,  TREE_H /2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	
	//	ワニの頂点情報
	CUSTOMVERTEX   alligatorvertex[4]
	{
		{ -ALLIGATOR_W/2 , -ALLIGATOR_H/2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{  ALLIGATOR_W/2 , -ALLIGATOR_H/2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{  ALLIGATOR_W/2 ,  ALLIGATOR_H/2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -ALLIGATOR_W/2 ,  ALLIGATOR_H/2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//	ワニの頂点情報
/*	CUSTOMVERTEX   chestnutvertex[4]
	{
		{ -CHESTNUT_W/2, -CHESTNUT_H/2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{  CHESTNUT_W/2, -CHESTNUT_H/2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{  CHESTNUT_W/2,  CHESTNUT_H/2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -CHESTNUT_W/2 , CHESTNUT_H/2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};*/
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
	for (int i = 0; i < 4; i++) 
	{
		drawlion[i] = lionvertex[i];
		drawlion[i].x += lion.x;
		drawlion[i].y += lion.y;
	}
	CUSTOMVERTEX drawtree[4];
	for (int i = 0; i < 4; i++)
	{
		drawtree[i] = treevertex[i];
		drawtree[i].x += tree.x;
		drawtree[i].y += tree.y;
	}
	CUSTOMVERTEX drawalligator[4];
	for (int i = 0; i < 4; i++)
	{
		drawalligator[i] = alligatorvertex[i];
		drawalligator[i].x += alligator.x;
		drawalligator[i].y += alligator.y;
	}
	CUSTOMVERTEX drawelephant[4];
	for (int i = 0; i < 4; i++)
	{
		drawelephant[i] = elephantvertex[i];
		drawelephant[i].x += elephant.x;
		drawelephant[i].y += elephant.y;
	}
	/*CUSTOMVERTEX drawchestnut[4];
	for (int i = 0; i < 4; i++)
	{
		drawchestnut[i] = chestnutvertex[i];
		drawchestnut[i].x += chestnut.x;
		drawchestnut[i].y += chestnut.y;
	}*/


	// テクスチャをステージに割り当てる
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[LION_TEX]);
	// 描画
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawlion, sizeof(CUSTOMVERTEX));
	// テクスチャをステージに割り当てる
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[ELEPHANT_TEX]);
	// 描画
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawelephant, sizeof(CUSTOMVERTEX));
	// テクスチャをステージに割り当てる
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[TREE_TEX]);
	// 描画
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawtree, sizeof(CUSTOMVERTEX));
	
	// テクスチャをステージに割り当てる
	//g_pDirect3DDevice->SetTexture(0, g_pGameTexture[TREE_TEX]);
	// 描画
	//g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawtree, sizeof(CUSTOMVERTEX));

	// テクスチャをステージに割り当てる
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[ALLIGATOR]);
	// 描画
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawalligator, sizeof(CUSTOMVERTEX));

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
