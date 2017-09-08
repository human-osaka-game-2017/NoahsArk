#include "GameScene.h"
#include "Control.h"
#include "char.h"
#include "finish.h"
#include "alligator.h"
#include "tree.h"
#include "hole.h"
#include "elephant.h"
#include "hippopotamus.h"
#include "mole.h"
#include "GameSceneScroll.h"
#include "right.h"
#include "left.h"
#include "title.h"
#include "gameSceneControl.h"
#include "systemCount.h"
#include "Sound.h"
#include "Value.h"


// ゲームシーンの画像情報を入れておく配列
LPDIRECT3DTEXTURE9			g_pGameTexture[GAMESCENE_MAX] = {NULL};

//船の頂点情報を作成する
CUSTOMVERTEX  ship[4]
{
	{ 1170.f , 100.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1440.f, 100.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1440.f, 450.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 1170.f, 450.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
};
int deadCount = 0;
// ゲームシーンの描画関数
int GameSceneDraw()
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
	elephantdraw();

	hippopotamusdraw();

	alligatordraw();

	treedraw();
	// テクスチャをステージに割り当てる
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[BACKGROUND_TEX]);
	// 描画
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, backGround, sizeof(CUSTOMVERTEX));


	// テクスチャをステージに割り当てる
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[SHIP_TEX]);
	// 描画
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, ship, sizeof(CUSTOMVERTEX));
	/*// テクスチャをステージに割り当てる
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[RIGHT_TEX]);
	// 描画
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawright, sizeof(CUSTOMVERTEX));
	// テクスチャをステージに割り当てる
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[LEFT_TEX]);
	// 描画
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawleft, sizeof(CUSTOMVERTEX));
	*/
	//もしLionDeadFlgがtrueなら
	if (hippopotamus.Dead)
	{
		deadCount++;
		if (deadCount > 60)
		{
			currentStage = STAGEONE;
			scene = GAMEOVER;
		}
	}
	//もしElephantDeadFlgがtrueなら
	else if (elephant.Dead)
	{
		deadCount++;
		if (deadCount > 60)
		{
			currentStage = STAGEONE;
			scene = GAMEOVER;
		}
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

	if (elephant.Active == false && hippopotamus.Active == false)
	{
		nextStage = STAGETWO;
		value(scene);
		scene = GAMECLEAR;

	}
	// 描画を終了
	g_pDirect3DDevice->EndScene();
	// 画面に表示
	g_pDirect3DDevice->Present(NULL, NULL, NULL, NULL);
	return scene;
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
}

	// ゲームシーンの解放関数
void GameSceneFree()
{
	// テクスチャを解放
	for (int i = 0; i < GAMESCENE_MAX; i++)
	{
		if (g_pGameTexture[i]) g_pGameTexture[i]->Release();
	}
}
