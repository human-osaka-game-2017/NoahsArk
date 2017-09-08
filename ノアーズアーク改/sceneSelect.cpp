#include "GameScene.h"
#include "Mouse.h"
#include "Control.h"
#include "gameSceneControl.h"

int selectStageControl()
{
	if (CheckMouseL() == PUSH)
	{
		if (340 < pt.x && 380 > pt.x && 200 < pt.y && 240 > pt.y)
		{
			scene = STAGEONE;
			return scene;
		}
		if (600.f < pt.x && 640.f > pt.x && 180 < pt.y && 220 > pt.y)
		{
			scene = STAGETWO;
			return scene;
		}
		if (480 < pt.x && 520 > pt.x && 440 < pt.y && 480 > pt.y)
		{
			scene = STAGETHREE;
			return scene;
		}
		if (730 < pt.x && 770 > pt.x && 350 < pt.y && 390 > pt.y)
		{
			scene = STAGEFOUR;
			return scene;
		}
		if (830 < pt.x && 870 > pt.x && 170 < pt.y && 210 > pt.y)
		{
			scene = STAGEFIVE;
			return scene;
		}
		if (990 < pt.x && 1030 > pt.x && 310 < pt.y && 350 > pt.y)
		{
			scene = STAGESIX;
			return scene;
		}
		if (1110 < pt.x && 1150 > pt.x && 500 < pt.y && 540 > pt.y)
		{
			scene = STAGESEVEN;
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
	CUSTOMVERTEX  drawSelectstage1[4]
	{
		{ 260.f , 160.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 420.f, 160.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 420.f, 200.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 260.f, 200.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	CUSTOMVERTEX  drawSelect1[4]
	{
		{ 400.f , 160.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 440.f, 160.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 440.f, 200.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 400.f, 200.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	CUSTOMVERTEX  drawSelectbutton1[4]
	{
		{ 340.f , 200.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 380.f, 200.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 380.f, 240.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 340.f, 240.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	CUSTOMVERTEX  drawSelectstage2[4]
	{
		{ 520 , 140.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 680.f, 140.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 680.f, 180.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 520.f, 180.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	CUSTOMVERTEX  drawSelect2[4]
	{
		{ 660.f , 140.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 700.f, 140.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 700.f, 180.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 660.f, 180.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	CUSTOMVERTEX  drawSelectbutton2[4]
	{
		{ 600.f , 180.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 640.f, 180.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 640.f, 220.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 600.f, 220.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	CUSTOMVERTEX  drawSelectstage3[4]
	{
		{ 400.f , 400.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 560.f, 400.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 560.f, 440.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 400.f, 440.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	CUSTOMVERTEX  drawSelect3[4]
	{
		{ 540.f , 400.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 580.f, 400.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 580.f, 440.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 540.f, 440.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	CUSTOMVERTEX  drawSelectbutton3[4]
	{
		{ 480.f , 440.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 520.f, 440.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 520.f, 480.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 480.f, 480.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	CUSTOMVERTEX  drawSelectstage4[4]
	{
		{ 650 , 310.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 810.f, 310.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 810.f, 350.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 650.f, 350.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	CUSTOMVERTEX  drawSelect4[4]
	{
		{ 790.f , 310.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 830.f, 310.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 830.f, 350.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 790.f, 350.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	CUSTOMVERTEX  drawSelectbutton4[4]
	{
		{ 730.f , 350.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 770.f, 350.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 770.f, 390.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 730.f, 390.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	CUSTOMVERTEX  drawSelectstage5[4]
	{
		{ 750.f , 130.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 910.f, 130.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 910.f, 170.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 750.f, 170.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	CUSTOMVERTEX  drawSelect5[4]
	{
		{ 890.f , 130.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 930.f, 130.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 930.f, 170.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 890.f, 170.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	CUSTOMVERTEX  drawSelectbutton5[4]
	{
		{ 830.f , 170.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 870.f, 170.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 870.f, 210.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 830.f, 210.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	CUSTOMVERTEX  drawSelectstage6[4]
	{
		{ 910.f , 270.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 1070.f, 270.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 1070.f, 310.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 910.f, 310.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	CUSTOMVERTEX  drawSelect6[4]
	{
		{ 1050.f , 270.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 1090.f, 270.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 1090.f, 310.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 1050.f, 310.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	CUSTOMVERTEX  drawSelectbutton6[4]
	{
		{ 990.f , 310.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 1030.f, 310.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 1030.f, 350.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 990.f, 350.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	CUSTOMVERTEX  drawSelectstage7[4]
	{
		{ 1030.f, 460.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 1190.f, 460.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 1190.f, 500.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 1030.f, 500.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	CUSTOMVERTEX  drawSelect7[4]
	{
		{ 1170.f , 460.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 1210.f, 460.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 1210.f, 500.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 1170.f, 500.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	CUSTOMVERTEX  drawSelectbutton7[4]
	{
		{ 1110.f , 500.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 1150, 500.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 1150.f, 540.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 1110.f, 540.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
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
	// テクスチャをステージに割り当てる
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[SERECTSTAGE_TEX]);
	// 描画
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawSelectstage1, sizeof(CUSTOMVERTEX));
	// テクスチャをステージに割り当てる
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[SERECT1_TEX]);
	// 描画
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawSelect1, sizeof(CUSTOMVERTEX));
	// テクスチャをステージに割り当てる
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[SERECTBUTTON_TEX]);
	// 描画
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawSelectbutton1, sizeof(CUSTOMVERTEX));
	// テクスチャをステージに割り当てる
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[SERECTSTAGE_TEX]);
	// 描画
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawSelectstage2, sizeof(CUSTOMVERTEX));
	// テクスチャをステージに割り当てる
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[SERECT2_TEX]);
	// 描画
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawSelect2, sizeof(CUSTOMVERTEX));
	// テクスチャをステージに割り当てる
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[SERECTBUTTON_TEX]);
	// 描画
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawSelectbutton2, sizeof(CUSTOMVERTEX));
	// テクスチャをステージに割り当てる
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[SERECTSTAGE_TEX]);
	// 描画
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawSelectstage3, sizeof(CUSTOMVERTEX));
	// テクスチャをステージに割り当てる
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[SERECT3_TEX]);
	// 描画
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawSelect3, sizeof(CUSTOMVERTEX));
	// テクスチャをステージに割り当てる
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[SERECTBUTTON_TEX]);
	// 描画
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawSelectbutton3, sizeof(CUSTOMVERTEX));
	// テクスチャをステージに割り当てる
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[SERECTSTAGE_TEX]);
	// 描画
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawSelectstage4, sizeof(CUSTOMVERTEX));
	// テクスチャをステージに割り当てる
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[SERECT4_TEX]);
	// 描画
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawSelect4, sizeof(CUSTOMVERTEX));
	// テクスチャをステージに割り当てる
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[SERECTBUTTON_TEX]);
	// 描画
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawSelectbutton4, sizeof(CUSTOMVERTEX));
	// テクスチャをステージに割り当てる
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[SERECTSTAGE_TEX]);
	// 描画
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawSelectstage5, sizeof(CUSTOMVERTEX));
	// テクスチャをステージに割り当てる
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[SERECT5_TEX]);
	// 描画
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawSelect5, sizeof(CUSTOMVERTEX));
	// テクスチャをステージに割り当てる
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[SERECTBUTTON_TEX]);
	// 描画
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawSelectbutton5, sizeof(CUSTOMVERTEX));
	// テクスチャをステージに割り当てる
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[SERECTSTAGE_TEX]);
	// 描画
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawSelectstage6, sizeof(CUSTOMVERTEX));
	// テクスチャをステージに割り当てる
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[SERECT6_TEX]);
	// 描画
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawSelect6, sizeof(CUSTOMVERTEX));
	// テクスチャをステージに割り当てる
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[SERECTBUTTON_TEX]);
	// 描画
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawSelectbutton6, sizeof(CUSTOMVERTEX));
	// テクスチャをステージに割り当てる
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[SERECTSTAGE_TEX]);
	// 描画
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawSelectstage7, sizeof(CUSTOMVERTEX));
	// テクスチャをステージに割り当てる
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[SERECT7_TEX]);
	// 描画
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawSelect7, sizeof(CUSTOMVERTEX));
	// テクスチャをステージに割り当てる
	g_pDirect3DDevice->SetTexture(0, g_pGameTexture[SERECTBUTTON_TEX]);
	// 描画
	g_pDirect3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, drawSelectbutton7, sizeof(CUSTOMVERTEX));

	// 描画を終了
	g_pDirect3DDevice->EndScene();
	// 画面に表示
	g_pDirect3DDevice->Present(NULL, NULL, NULL, NULL);
	return scene;
}