#include "finish.h"
#include "Control.h"
#include "GameScene.h"
#include "hippopotamus.h"
#include "elephant.h"
#include "tree.h"
#include "alligator.h"
#include "gameSceneControl.h"

CUSTOMVERTEX gameoverGrounddraw[4];

CUSTOMVERTEX gameclearGrounddraw[4];

CUSTOMVERTEX gameclearNextStage[4];

CUSTOMVERTEX gameCleardraw[4];

CUSTOMVERTEX oneMoredraw[4];

CUSTOMVERTEX starDraw[4];


extern int Rank;

bool finishFlg = false;

void sceneDraw()
{
	// ゲームオーバーの頂点情報を作成する
	CUSTOMVERTEX gameClearrvertex[4]
	{
		{ 0.f , 0.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 1440.f, 0.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 1440.f, 650.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 0.f, 650.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//右を左に代入
	for (int i = 0; i < 4; i++)
	{
		gameCleardraw[i] = gameClearrvertex[i];
	}
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
int gameClear()
{
	//始めるの頂点情報を作成する
	CUSTOMVERTEX  nextStagedraw[4]
	{
		{ 420.f , 450.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 1020.f, 450.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 1020.f, 550.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 420.f, 550.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	//右を左に代入
	for (int i = 0; i < 4; i++)
	{
		gameclearNextStage[i] = nextStagedraw[i];
	}
	if (CheckMouseL() == PUSH)
	{
		if (420 < pt.x && 1020 > pt.x && 450 < pt.y && 550 > pt.y)
		{
			scene = nextStage;
			
		}
	}
	return scene;
}
int gameOver()
{
	//始めるの頂点情報を作成する
	CUSTOMVERTEX  onemorevretex[4]
	{
		{ 420.f , 450.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 1020.f, 450.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 1020.f, 550.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 420.f, 550.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	//右を左に代入
	for (int i = 0; i < 4; i++)
	{
		oneMoredraw[i] = onemorevretex[i];
	}
	if (CheckMouseL() == PUSH)
	{
		if (420 < pt.x && 1020 > pt.x && 450 < pt.y && 550 > pt.y)
		{
			scene = currentStage;

		}
	}
	return scene;
}
int overSceneDraw()
{

	// 頂点情報の指定
	g_pDirect3DDevice->SetFVF(D3DFVF_CUSTOMVERTEX);

	// 画面の消去
	g_pDirect3DDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0x00, 0x00, 0x00), 1.0, 0);
	// 描画を開始
	g_pDirect3DDevice->BeginScene();
	sceneDraw();
	gameOver();
	// テクスチャをステージに割り当てる
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[ONEMORE_TEX]);
	// 描画
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, oneMoredraw, sizeof(CUSTOMVERTEX));
	// テクスチャをステージに割り当てる
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[GAMEOVER_TEX]);
	// 描画
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, gameoverGrounddraw, sizeof(CUSTOMVERTEX));
	// 描画を終了
	g_pDirect3DDevice->EndScene();
	// 画面に表示
	g_pDirect3DDevice->Present(NULL, NULL, NULL, NULL);
	return scene;
}
int clearSceneDraw()
{

	// 頂点情報の指定
	g_pDirect3DDevice->SetFVF(D3DFVF_CUSTOMVERTEX);

	// 画面の消去
	g_pDirect3DDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0x00, 0x00, 0x00), 1.0, 0);
	// 描画を開始
	g_pDirect3DDevice->BeginScene();
	sceneDraw();

	gameClear();
	// テクスチャをステージに割り当てる
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[CLEARGROUND_TEX]);
	// 描画
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, gameCleardraw, sizeof(CUSTOMVERTEX));
	// テクスチャをステージに割り当てる
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[GAMECLEAR_TEX]);
	// 描画
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, gameclearGrounddraw, sizeof(CUSTOMVERTEX));
	// テクスチャをステージに割り当てる
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[NEXT_TEX]);
	// 描画
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, gameclearNextStage, sizeof(CUSTOMVERTEX));

	StarDraw();

	// 描画を終了
	g_pDirect3DDevice->EndScene();
	// 画面に表示
	g_pDirect3DDevice->Present(NULL, NULL, NULL, NULL);
	return scene;
}

void StarDraw()
{
	// 星の頂点情報を作成する
	CUSTOMVERTEX starDraw[4]
	{
		{ 450.f , 288.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 860.f, 288.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 860.f, 383.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 450.f, 383.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	if (Rank == 1)
	{
		g_pDirect3DDevice->SetTexture(0, g_pGameTexture[STAR1_TEX]);
	}
	else if (Rank == 2)
	{
		g_pDirect3DDevice->SetTexture(0, g_pGameTexture[STAR2_TEX]);
	}
	else
	{
		g_pDirect3DDevice->SetTexture(0, g_pGameTexture[STAR3_TEX]);
	}


	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, starDraw, sizeof(CUSTOMVERTEX));

}

