#include "risu.h"
#include "chestnut.h"
#include "char.h"
#include "GameScene.h"
#include "Control.h"
#include "finish.h"
//リスの初期位置
Animal risu = { 362.f,381.f,false,true }; //リス

CUSTOMVERTEX drawrisu[4];

//リスが動いてるときtrue
bool g_MoveRisu = true;

//リスが生きているか死んでいるか
bool RisuDeadFlg = false;

void risudraw(int time)
{
	//リスの頂点情報
	CUSTOMVERTEX  risuvertex[4]
	{
		{ -RISU_W / 2 , -RISU_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ RISU_W / 2 , -RISU_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ RISU_W / 2 ,  RISU_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -RISU_W / 2 ,  RISU_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	//位置と頂点情報を代入する
	for (int i = 0; i < 4; i++)
	{
		drawrisu[i] = risuvertex[i];
		drawrisu[i].x += risu.x;
		drawrisu[i].y += risu.y;
	}

	if (g_MoveRisu && time > 3000)
	{
		risu.x += MOVESPEEDRISU;
	}

	//もしリスデットフラグがたっていたら中に入る
	if (RisuDeadFlg)
	{
		static float angle = 15.f;

		g_MoveRisu = false;

		angle += 15.f;
		if (angle >= 180)
		{
			angle = 180.f;
		}
		//関数呼び出し
		Kaiten(-angle, risuvertex, drawrisu);

		for (int i = 0; i < 4; i++)
		{
			//risu.x -= DEADMOVESPEED_W;
			//risu.y -= DEADMOVESPEED_H;
			drawrisu[i].x += risu.x;
			drawrisu[i].y += risu.y;
		}

	}
	//もしリスが栗の左に当たっていたら
	if (risu.x >= chestnut.x - CHESTNUT_W)
	{
		//栗を消す
		chestnut.Active = false;
	}

	if (RisuDeadFlg == false)
	{
		for (int i = 0; i < 4; i++)
		{
			//ゴール判定
			//リスのxがふねのxよりおおきかったら中に入る
			if (risu.x >= ship[i].x)
			{
				risu.y -= 0.1f;
				risu.Clear = true;
			}
			//クリア判定
			if (risu.Clear)
			{
				//リスのxがふねのxに100足した数より大きかったら中に入る
				if (risu.x >= ship[i].x + 100)
				{
					risu.Active = false;
				}
			}
		}
	}
}