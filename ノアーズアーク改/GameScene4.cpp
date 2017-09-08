#include "GameScene.h"
#include "Control.h"
#include "char.h"
#include "finish.h"
#include "tree.h"
#include "elephant.h"
#include "risu.h"
#include "chestnut.h"
#include "mole.h"
#include "hole.h"
#include "GameSceneScroll.h"
#include "right.h"
#include "left.h"
#include "gameSceneControl.h"
#include "Value.h"


int deadCount4 = 0;
// ゲームシーンの描画関数
int GameSceneDraw4()
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

	risudraw();

	moledraw();

	treedraw();

	chestnutdraw();

	holedraw();

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
	
	if (elephant.Dead)
	{
		deadCount4++;
		if (deadCount4 > 60)
		{
			currentStage = STAGEFOUR;
			scene = GAMEOVER;
		}
	}
	//もしElephantDeadFlgがtrueなら
	else if (risu.Dead)
	{
		deadCount4++;
		if (deadCount4 > 60)
		{
			currentStage = STAGEFOUR;
			scene = GAMEOVER;
		}
	}
	else if (mole.Dead)
	{
		deadCount4++;
		if (deadCount4 > 60)
		{
			currentStage = STAGEFOUR;
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
	if (risu.Active)
	{
		// テクスチャをステージに割り当てる
		g_pDirect3DDevice->SetTexture(0, g_pGameTexture[RISU_TEX]);
		// 描画
		g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawrisu, sizeof(CUSTOMVERTEX));
	}
	if (mole.Active)
	{
		// テクスチャをステージに割り当てる
		g_pDirect3DDevice->SetTexture(0, g_pGameTexture[MOLE_TEX]);
		// 描画
		g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawmole, sizeof(CUSTOMVERTEX));
	}
	if (tree.Active)
	{
		// テクスチャをステージに割り当てる
		g_pDirect3DDevice->SetTexture(0, g_pGameTexture[TREE_TEX]);
		// 描画
		g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawtree, sizeof(CUSTOMVERTEX));
	}
	if (hole.Active)
	{
		// テクスチャをステージに割り当てる
		g_pDirect3DDevice->SetTexture(0, g_pGameTexture[HOLE_TEX]);
		// 描画
		g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawhole, sizeof(CUSTOMVERTEX));
	}
	if (hole2.Active)
	{
		// テクスチャをステージに割り当てる
		g_pDirect3DDevice->SetTexture(0, g_pGameTexture[HOLE_TEX]);
		// 描画
		g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawhole2, sizeof(CUSTOMVERTEX));
	}
	if (chestnut.Active)
	{
		// テクスチャをステージに割り当てる
		g_pDirect3DDevice->SetTexture(0, g_pGameTexture[CHESTNUT_TEX]);
		// 描画
		g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawchestnut, sizeof(CUSTOMVERTEX));
	}
	if (hole3.Active)
	{
		// テクスチャをステージに割り当てる
		g_pDirect3DDevice->SetTexture(0, g_pGameTexture[HOLE_TEX]);
		// 描画
		g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawhole3, sizeof(CUSTOMVERTEX));
	}
	if (hole4.Active)
	{
		// テクスチャをステージに割り当てる
		g_pDirect3DDevice->SetTexture(0, g_pGameTexture[HOLE_TEX]);
		// 描画
		g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawhole4, sizeof(CUSTOMVERTEX));
	}
	//テクスチャをステージに割り当てる
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[KUSA_TEX]);
	//描画
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, kusavertex, sizeof(CUSTOMVERTEX));
	if (elephant.Active == false && risu.Active == false && mole.Active == false)
	{
		nextStage = STAGEFIVE;
		value(scene);
		scene = GAMECLEAR;
	}
	// 描画を終了
	g_pDirect3DDevice->EndScene();
	// 画面に表示
	g_pDirect3DDevice->Present(NULL, NULL, NULL, NULL);
	return scene;
}


