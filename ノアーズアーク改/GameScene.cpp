#include "GameScene.h"
#include "Control.h"
#include "char.h"
#include "finish.h"
#include "alligator.h"
#include "tree.h"
#include "elephant.h"
#include "hippopotamus.h"
#include "GameSceneScroll.h"
#include "right.h"
#include "left.h"


// ゲームシーンの画像情報を入れておく配列
LPDIRECT3DTEXTURE9			g_pGameTexture[GAMESCENE_MAX];


//船の頂点情報を作成する
CUSTOMVERTEX  ship[4]
{
	{ 1170.f , 100.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1440.f, 100.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1440.f, 450.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 1170.f, 450.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
};


// ゲームシーンの描画関数
void GameSceneDraw(int time)
{
	

	//草むらの頂点情報を作成する
	CUSTOMVERTEX kusavertex[4]
	{
		{ 0.f,0.f,1.f,1.f,0xFFFFFFFF,0.f,0.f },
		{ 2880.f,0.f,1.f,1.f,0xFFFFFFFF,1.f,0.f },
		{ 2880.f,620.f,1.f,1.f,0xFFFFFFFF,1.f,1.f },
		{ 0.f,620.f,1.f,1.f,0xFFFFFFFF,0.f,1.f }
	};
	
	// 頂点情報の指定
	g_pDirect3DDevice->SetFVF(D3DFVF_CUSTOMVERTEX);

	// 画面の消去
	g_pDirect3DDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0x00, 0x00, 0x00), 1.0, 0);
	// 描画を開始
	g_pDirect3DDevice->BeginScene();


	//関数呼び出し

	scroll();

	elephantdraw(time);

	hippopotamusdraw(time);

	alligatordraw();

	treedraw();

	rightdraw();

	leftdraw();

	// テクスチャをステージに割り当てる
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[BACKGROUND_TEX]);
	// 描画
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, backGround, sizeof(CUSTOMVERTEX));

	// テクスチャをステージに割り当てる
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[BACKGROUND_TEX]);
	// 描画
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, backGround2, sizeof(CUSTOMVERTEX));

	// テクスチャをステージに割り当てる
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[SHIP_TEX]);
	// 描画
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, ship, sizeof(CUSTOMVERTEX));
	// テクスチャをステージに割り当てる
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[RIGHT_TEX]);
	// 描画
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawright, sizeof(CUSTOMVERTEX));
	// テクスチャをステージに割り当てる
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[LEFT_TEX]);
	// 描画
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawleft, sizeof(CUSTOMVERTEX));
	//もしLionDeadFlgがtrueなら
	if (hippopotamusDeadFlg)
	{
		finishFlg = true;
	}
	//もしElephantDeadFlgがtrueなら
	if (ElephantDeadFlg)
	{
		finishFlg = true;
	}

	if (elephant.Active)
	{
		// テクスチャをステージに割り当てる
		g_pDirect3DDevice->SetTexture(0, g_pGameTexture[ELEPHANT_TEX]);
		// 描画
		g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawelephant, sizeof(CUSTOMVERTEX));
	}

	if (hippopotamus.Active)
	{
		// テクスチャをステージに割り当てる
		g_pDirect3DDevice->SetTexture(0, g_pGameTexture[HIPPOPOTAMUS_TEX]);
		// 描画
		g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawhippopotamus, sizeof(CUSTOMVERTEX));
	}
	if (tree.Active)
	{
		// テクスチャをステージに割り当てる
		g_pDirect3DDevice->SetTexture(0, g_pGameTexture[TREE_TEX]);
		// 描画
		g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawtree, sizeof(CUSTOMVERTEX));
	}
	if (tree2.Active)
	{
		// テクスチャをステージに割り当てる
		g_pDirect3DDevice->SetTexture(0, g_pGameTexture[TREE_TEX]);
		// 描画
		g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawtree2, sizeof(CUSTOMVERTEX));
	}
	if (alligator.Active)
	{
		// テクスチャをステージに割り当てる
		g_pDirect3DDevice->SetTexture(0, g_pGameTexture[ALLIGATOR_TEX]);
		// 描画
		g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawalligator, sizeof(CUSTOMVERTEX));
	}
	//テクスチャをステージに割り当てる
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[KUSA_TEX]);
	//描画
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, kusavertex, sizeof(CUSTOMVERTEX));
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

	//     picture/haikeiの/はそのファイルの中に入れる

	// ゲームシーンの背景の読み込み
	D3DXCreateTextureFromFile(
		g_pDirect3DDevice,
		"picture/haikei.png",
		&g_pGameTexture[BACKGROUND_TEX]);
	
	D3DXCreateTextureFromFile(
		g_pDirect3DDevice,
		"picture/right.png",
		&g_pGameTexture[RIGHT_TEX]);

	D3DXCreateTextureFromFile(
		g_pDirect3DDevice,
		"picture/left.png",
		&g_pGameTexture[LEFT_TEX]);

	//-------------------------------------
	//透過のやり方
	//-------------------------------------
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
	//ゲームタイトルの読み込み
	D3DXCreateTextureFromFile(
		g_pDirect3DDevice,
		"picture/noa!.png",
		&g_pGameTexture[GAMETITLE_TEX]
	);
	//スタートボタンの読み込み
	D3DXCreateTextureFromFileEx(
		g_pDirect3DDevice,
		"picture/newgame().png",              // ファイル名
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
	//ライオンの読み込み
	D3DXCreateTextureFromFile(
		g_pDirect3DDevice,
		"picture/lion.png",
		&g_pGameTexture[LION_TEX]);

	//カバの読み込み
	D3DXCreateTextureFromFile(
		g_pDirect3DDevice,
		"picture/hippopotamus.png",
		&g_pGameTexture[HIPPOPOTAMUS_TEX]);

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

	//ゾウの読み込み
	D3DXCreateTextureFromFile(
		g_pDirect3DDevice,
		"picture/elephant.png",
		&g_pGameTexture[ELEPHANT_TEX]);

	//木の読み込み
	D3DXCreateTextureFromFile(
		g_pDirect3DDevice,
		"picture/mole.png",
		&g_pGameTexture[MOLE_TEX]);

	//木の読み込み
	D3DXCreateTextureFromFile(
		g_pDirect3DDevice,
		"picture/tree.png",
		&g_pGameTexture[TREE_TEX]);

	//障害物の読み込み
	D3DXCreateTextureFromFile(
		g_pDirect3DDevice,
		"picture/barricade.png",
		&g_pGameTexture[BARRICADE_TEX]);

	//ワニの読み込み
	D3DXCreateTextureFromFile(
		g_pDirect3DDevice,
		"picture/alligator.png",
		&g_pGameTexture[ALLIGATOR_TEX]);

	//栗の読み込み
	D3DXCreateTextureFromFile(
	g_pDirect3DDevice,
	"picture/kuri.png",
	&g_pGameTexture[CHESTNUT_TEX]);

	//穴の読み込み
	D3DXCreateTextureFromFile(
		g_pDirect3DDevice,
		"picture/hole.png",
		&g_pGameTexture[HOLE_TEX]);

	//草むらの読み込み
	D3DXCreateTextureFromFile(
		g_pDirect3DDevice,
		"picture/kusa.png",
		&g_pGameTexture[KUSA_TEX]);
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
