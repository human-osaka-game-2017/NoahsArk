#include "lion.h"
#include "alligator.h"
#include "char.h"
#include "GameScene.h"
#include "Control.h"
#include "finish.h"
//ライオンの初期位置
Animal lion = { 200.f,400.f,false,true }; //ライオン

CUSTOMVERTEX drawlion[4];

//ライオンが動いてるときtrue
bool g_MoveLion = true;

//ライオンが生きているか死んでいるか
bool LionDeadFlg = false;

void liondraw(int time)
{
	//ライオンの頂点情報
	CUSTOMVERTEX  lionvertex[4]
	{
		{ -LION_W / 2 , -LION_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ LION_W / 2 , -LION_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ LION_W / 2 ,  LION_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -LION_W / 2 ,  LION_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	//位置と頂点情報を代入する
	for (int i = 0; i < 4; i++)
	{
		drawlion[i] = lionvertex[i];
		drawlion[i].x += lion.x;
		drawlion[i].y += lion.y;
	}

	if (g_MoveLion && time > 3000)
	{
		lion.x += MOVESPEEDLION;
	}

	//もしライオンデットフラグがたっていたら中に入る
	if (LionDeadFlg)
	{
		static float angle = 15.f;

		g_MoveLion = false;

		angle += 15.f;
		if (angle >= 180)
		{
			angle = 180.f;
		}
		//関数呼び出し
		Kaiten(-angle, lionvertex, drawlion);

		for (int i = 0; i < 4; i++)
		{
			//lion.x -= DEADMOVESPEED_W;
		    //lion.y -= DEADMOVESPEED_H;
			drawlion[i].x += lion.x;
			drawlion[i].y += lion.y;
		}
			
	}
	//もしライオンがワニの左に当たっていたら
	if (lion.x >= alligator.x - ALLIGATOR_W)
	{
		//ワニを消す
		alligator.Active = false;
	}

	if (LionDeadFlg == false)
	{
		for (int i = 0; i < 4; i++)
		{
			//ゴール判定
			//ライオンのxがふねのxよりおおきかったら中に入る
			if (lion.x >= ship[i].x)
			{
				lion.y -= 0.1f;
				lion.Clear = true;
			}
			//クリア判定
			if (lion.Clear)
			{
				//ライオンのxがふねのxに100足した数より大きかったら中に入る
				if (lion.x >= ship[i].x + 100)
				{
					lion.Active = false;
				}
			}
		}
	}
}