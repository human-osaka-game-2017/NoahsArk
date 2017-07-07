#include "elephant.h"
#include "tree.h"
#include "char.h"
#include "GameScene.h"
#include "Control.h"
#include "finish.h"
//ゾウの初期位置の設定
Animal elephant = { 300.f,400.f,false,true };//ゾウ

CUSTOMVERTEX drawelephant[4];

//ゾウが動いていていたらtrue
bool g_Moveelephant = true;
//ゾウが生きているか死んでいるか
bool ElephantDeadFlg = false;

void elephantdraw()
{
	//ゾウの頂点情報
	CUSTOMVERTEX  elephantvertex[4]
	{
		{ -ELEPHANT_W / 2, -ELEPHANT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ ELEPHANT_W / 2, -ELEPHANT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ ELEPHANT_W / 2,  ELEPHANT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -ELEPHANT_W / 2,  ELEPHANT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	//位置と頂点情報を代入
	for (int i = 0; i < 4; i++)
	{
		drawelephant[i] = elephantvertex[i];
		drawelephant[i].x += elephant.x;
		drawelephant[i].y += elephant.y;
	}

	if (g_Moveelephant)
	{
		elephant.x += MOVESPEEDELEPHANT;
	}

	if (elephant.x >= tree.x)
	{
		tree.Active = false;
	}

	//もしライオンデットフラグがたっていたら中に入る
	if (ElephantDeadFlg)
	{
		static float angle = 15.f;
		g_Moveelephant = false;

		angle += 15.f;
		if (angle >= 180)
		{
			angle = 180.f;
		}
		//関数呼び出し
		Kaiten(-angle, elephantvertex, drawelephant);

		for (int i = 0; i < 4; i++)
		{
			//elephant.x -= DEADMOVESPEED_W;
			//elephant.y -= DEADMOVESPEED_H;
			drawelephant[i].x += elephant.x;
			drawelephant[i].y += elephant.y;
		}

	}


	for (int i = 0; i < 4; i++)
	{
		//ゴール判定
		//ゾウのｘがふねのxより大きかったら中に入る
		if (elephant.x >= ship[i].x)
		{
			elephant.y -= 1;
			elephant.Clear = true;
		}
		//クリア判定
		if (elephant.Clear) 
		{ 
			//ゾウのｘがふねのxに100足した数よりおおきかったら中に入る
			if (elephant.x >= ship[i].x + 100)
			{
				elephant.Active = false;
			}
		}
	}
}