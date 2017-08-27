#include "risu.h"
#include "chestnut.h"
#include "char.h"
#include "GameScene.h"
#include "Control.h"
#include "finish.h"
#include "hole.h"
#include "systemCount.h"
//リスの初期位置
Animal risu = { 425.f,400.f,false,true }; //ステージ2
Animal risu2 = { 362.f,400.f,false,true }; //ステージ3
Animal risu3 = { 195.f,400.f,false,true }; //ステージ4
Animal risu4 = { 270.f,400.f,false,true }; //ステージ6
Animal risu5 = { 90.f,400.f,false,true }; //ステージ8

CUSTOMVERTEX drawrisu[4];
CUSTOMVERTEX drawrisu2[4];
CUSTOMVERTEX drawrisu3[4];
CUSTOMVERTEX drawrisu4[4];
CUSTOMVERTEX drawrisu5[4];

//リスが動いてるときtrue
bool g_MoveRisu = true;

//リスが生きているか死んでいるか
bool RisuDeadFlg = false;

void risudraw()
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
	//リスの頂点情報
	CUSTOMVERTEX  risuvertex2[4]
	{
		{ -RISU_W / 2 , -RISU_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ RISU_W / 2 , -RISU_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ RISU_W / 2 ,  RISU_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -RISU_W / 2 ,  RISU_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	//位置と頂点情報を代入する
	for (int i = 0; i < 4; i++)
	{
		drawrisu2[i] = risuvertex2[i];
		drawrisu2[i].x += risu2.x;
		drawrisu2[i].y += risu2.y;
	}
	//リスの頂点情報
	CUSTOMVERTEX  risuvertex3[4]
	{
		{ -RISU_W / 2 , -RISU_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ RISU_W / 2 , -RISU_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ RISU_W / 2 ,  RISU_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -RISU_W / 2 ,  RISU_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	//位置と頂点情報を代入する
	for (int i = 0; i < 4; i++)
	{
		drawrisu3[i] = risuvertex3[i];
		drawrisu3[i].x += risu3.x;
		drawrisu3[i].y += risu3.y;
	}
	//リスの頂点情報
	CUSTOMVERTEX  risuvertex4[4]
	{
		{ -RISU_W / 2 , -RISU_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ RISU_W / 2 , -RISU_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ RISU_W / 2 ,  RISU_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -RISU_W / 2 ,  RISU_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	//位置と頂点情報を代入する
	for (int i = 0; i < 4; i++)
	{
		drawrisu4[i] = risuvertex4[i];
		drawrisu4[i].x += risu4.x;
		drawrisu4[i].y += risu4.y;
	}
	//リスの頂点情報
	CUSTOMVERTEX  risuvertex5[4]
	{
		{ -RISU_W / 2 , -RISU_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ RISU_W / 2 , -RISU_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ RISU_W / 2 ,  RISU_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -RISU_W / 2 ,  RISU_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	//位置と頂点情報を代入する
	for (int i = 0; i < 4; i++)
	{
		drawrisu5[i] = risuvertex5[i];
		drawrisu5[i].x += risu5.x;
		drawrisu5[i].y += risu5.y;
	}

	if (g_MoveRisu && count > 180)
	{
		risu.x += MOVESPEEDRISU;
	}

	if (hole.Active)
	{
		if (hole.x == risu.x)
		{
			//手前の穴から奥の穴の距離を出してそれをtmpに入れる
			int tmp = hole2.x - hole.x;
			//今のリスの位置にtmpを足す
			risu.x = risu.x + tmp;
		}
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