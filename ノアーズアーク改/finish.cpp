#include "finish.h"
#include "Control.h"
#include "GameScene.h"
#include "hippopotamus.h"
#include "elephant.h"
#include "tree.h"
#include "alligator.h"

CUSTOMVERTEX gameoverGrounddraw[4];

CUSTOMVERTEX gameclearGrounddraw[4];

bool finishFlg = false;

void sceneDraw()
{
	// ゲームオーバーの頂点情報を作成する
	CUSTOMVERTEX gameoverGround[4]
	{
		{ 320.f , 100.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 1120.f, 100.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 1120.f, 300.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 320.f, 300.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//右を左に代入
	for (int i = 0; i < 4; i++)
	{
		gameoverGrounddraw[i] = gameoverGround[i];
	}

	//ゲームクリアの頂点情報
	CUSTOMVERTEX gameclearGround[4]
	{
		{ 320.f , 100.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 1120.f, 100.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 1120.f, 300.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 320.f, 300.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	//右を左に代入
	for (int i = 0; i < 4; i++)
	{
		gameclearGrounddraw[i] = gameclearGround[i];
	}
}
int overSceneDraw()
{
	sceneDraw();

	// 頂点情報の指定
	g_pDirect3DDevice->SetFVF(D3DFVF_CUSTOMVERTEX);

	// 画面の消去
	g_pDirect3DDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0x00, 0x00, 0x00), 1.0, 0);
	// 描画を開始
	g_pDirect3DDevice->BeginScene();
	if (hippopotamus.Dead)
	{
		// テクスチャをステージに割り当てる
		g_pDirect3DDevice->SetTexture(0, g_pGameTexture[GAMEOVER_TEX]);
		// 描画
		g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, gameoverGrounddraw, sizeof(CUSTOMVERTEX));
	}
	//もしElephantDeadFlgがtrueなら
	if (elephant.Dead)
	{
		// テクスチャをステージに割り当てる
		g_pDirect3DDevice->SetTexture(0, g_pGameTexture[GAMEOVER_TEX]);
		// 描画
		g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, gameoverGrounddraw, sizeof(CUSTOMVERTEX));
	}

	return 0;
	// 描画を終了
	g_pDirect3DDevice->EndScene();
	// 画面に表示
	g_pDirect3DDevice->Present(NULL, NULL, NULL, NULL);

}
int clearSceneDraw()
{
	sceneDraw();

	// 頂点情報の指定
	g_pDirect3DDevice->SetFVF(D3DFVF_CUSTOMVERTEX);

	// 画面の消去
	g_pDirect3DDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0x00, 0x00, 0x00), 1.0, 0);
	// 描画を開始
	g_pDirect3DDevice->BeginScene();

	// テクスチャをステージに割り当てる
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[GAMECLEAR_TEX]);
	// 描画
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, gameclearGrounddraw, sizeof(CUSTOMVERTEX));
	return 0;
	// 描画を終了

	g_pDirect3DDevice->EndScene();
	// 画面に表示
	g_pDirect3DDevice->Present(NULL, NULL, NULL, NULL);
}

