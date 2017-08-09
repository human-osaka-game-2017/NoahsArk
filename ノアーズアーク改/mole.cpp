#include "char.h"
#include "GameScene.h"
#include "mole.h"
#include "Control.h"
#include "hole.h"
//モグラの位置
Animal mole{ 100.f,400.f,false,true };

//モグラが動いてるときtrue
bool g_MoveMole = true;

//モグラが生きているか死んでいるか
bool MoleDeadFlg = false;

CUSTOMVERTEX drawmole[4];

void moledraw(int time)
{
	//モグラの頂点情報
	CUSTOMVERTEX  molevertex[4]
	{
		{ -MOLE_W / 2 , -MOLE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{  MOLE_W / 2 , -MOLE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{  MOLE_W / 2 ,  MOLE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -MOLE_W / 2 ,  MOLE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	for (int i = 0; i < 4; i++)
	{
		drawmole[i] = molevertex[i];
		drawmole[i].x += mole.x;
		drawmole[i].y += mole.y;
	}

	if (g_MoveMole && time > 3000)
	{
		mole.x += MOVESPEEDMOLE;
	}

	if (hole.Active)
	{
	//もしモグラが手前の穴に当たっていたら
		if (hole.x == mole.x)
		{
			//手前の穴から奥の穴の距離を出してそれをtmpに入れる
			int tmp = hole2.x - hole.x;
			//今のモグラの位置にtmpを足す
			mole.x = mole.x + tmp;
		}
	}

		

	//もしライオンデットフラグがたっていたら中に入る
	if (MoleDeadFlg)
	{
		static float angle = 15.f;

		g_MoveMole = false;

		angle += 15.f;
		if (angle >= 180)
		{
			angle = 180.f;
		}
		//関数呼び出し
		Kaiten(-angle, molevertex, drawmole);

		for (int i = 0; i < 4; i++)
		{
			//lion.x -= DEADMOVESPEED_W;
			//lion.y -= DEADMOVESPEED_H;
			drawmole[i].x += mole.x;
			drawmole[i].y += mole.y;
		}
	}
	if (MoleDeadFlg == false)
	{
		for (int i = 0; i < 4; i++)
		{
			//ゴール判定
			//ライオンのxがふねのxよりおおきかったら中に入る
			if (mole.x >= ship[i].x)
			{
				mole.y -= 0.1f;
				mole.Clear = true;
			}
			//クリア判定
			if (mole.Clear)
			{
				//ライオンのxがふねのxに100足した数より大きかったら中に入る
				if (mole.x >= ship[i].x + 100)
				{
					mole.Active = false;
				}
			}
		}
	}


}