#include "hippopotamus.h"
#include "alligator.h"
#include "lion.h"
#include "char.h"
#include "GameScene.h"
#include "Control.h"
#include "finish.h"
#include "hole.h"
//カバの初期位置
Animal hippopotamus = { 263.f,400.f,true }; //ステージ1
Animal hippopotamus2 = { 265.f,400.f,true }; //ステージ2

CUSTOMVERTEX drawhippopotamus[4];
CUSTOMVERTEX drawhippopotamus2[4];

//カバが動いてるときtrue
bool g_MoveHippopotamus = true;

//カバが生きているか死んでいるか
bool hippopotamusDeadFlg = false;

void hippopotamusdraw(int time)
{
	//カバの頂点情報
	CUSTOMVERTEX  hippopotamusvertex[4]
	{
		{ -HIPPOPOTAMUS_W / 2 ,- HIPPOPOTAMUS_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{  HIPPOPOTAMUS_W / 2 ,- HIPPOPOTAMUS_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{  HIPPOPOTAMUS_W / 2 ,  HIPPOPOTAMUS_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -HIPPOPOTAMUS_W / 2 ,  HIPPOPOTAMUS_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	//位置と頂点情報を代入する
	for (int i = 0; i < 4; i++)
	{
		drawhippopotamus[i] = hippopotamusvertex[i];
		drawhippopotamus[i].x += hippopotamus.x;
		drawhippopotamus[i].y += hippopotamus.y;
	}
	//カバの頂点情報
	CUSTOMVERTEX   hippopotamusvertex2[4]
	{
		{ -HIPPOPOTAMUS_W / 2 , -HIPPOPOTAMUS_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ HIPPOPOTAMUS_W / 2 , -HIPPOPOTAMUS_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ HIPPOPOTAMUS_W / 2 ,  HIPPOPOTAMUS_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -HIPPOPOTAMUS_W / 2 ,  HIPPOPOTAMUS_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	//位置と頂点情報を代入
	for (int i = 0; i < 4; i++)
	{
		drawhippopotamus2[i] = hippopotamusvertex2[i];
		drawhippopotamus2[i].x += hippopotamus2.x;
		drawhippopotamus2[i].y += hippopotamus2.y;
	}

	//もしカバが穴の左に当たっていたら
	if (hippopotamus.x >= hole.x - HOLE_W)
	{
		//穴を消す
		hole.Active = false;
	}

	if (g_MoveHippopotamus && time > 3000)
	{
		hippopotamus.x += MOVESPEEDHIPPOPOTAMUS;
	}

	//もしカバデットフラグがたっていたら中に入る
	if (hippopotamusDeadFlg)
	{
		static float angle = 15.f;

		g_MoveHippopotamus = false;

		angle += 15.f;
		if (angle >= 180)
		{
			angle = 180.f;
		}
		//関数呼び出し
		Kaiten(-angle, hippopotamusvertex, drawHippopotamus);

		for (int i = 0; i < 4; i++)
		{
			//lion.x -= DEADMOVESPEED_W;
			//lion.y -= DEADMOVESPEED_H;
			drawHippopotamus[i].x += hippopotamus.x;
			drawHippopotamus[i].y += hippopotamus.y;
		}

	}
	//もしカバがワニの左に当たっていたら
	if (hippopotamus.x >= alligator.x - ALLIGATOR_W)
	{
		//ワニを消す
		alligator.Active = false;
	}

	if (hole.Active)
	{
		if (hippopotamus.x == hole.x)
		{
			hippopotamus.x -= MOVESPEEDHIPPOPOTAMUS;
		}
	}

	if (hippopotamusDeadFlg == false)
	{
		for (int i = 0; i < 4; i++)
		{
			//ゴール判定
			//カバのxがふねのxよりおおきかったら中に入る
			if (hippopotamus.x >= ship[i].x)
			{
				hippopotamus.y -= 0.1f;
				hippopotamus.Clear = true;
			}
			//クリア判定
			if (hippopotamus.Clear)
			{
				//カバのxがふねのxに100足した数より大きかったら中に入る
				if (hippopotamus.x >= ship[i].x + 100)
				{
					hippopotamus.Active = false;
				}
			}
		}
	}
}