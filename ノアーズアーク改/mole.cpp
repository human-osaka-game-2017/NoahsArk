#include "char.h"
#include "GameScene.h"
#include "mole.h"
#include "Control.h"
#include "hole.h"
#include"systemCount.h"
//モグラの位置
Animal mole = { 314.f,400.f,false,true,true,false,false,false }; //ステージ4
Animal mole2 = { 300.f,400.f,false,true,true,false,false,false }; //ステージ8

CUSTOMVERTEX drawmole[4];
CUSTOMVERTEX drawmole2[4];

void moledraw()
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
	//モグラの頂点情報
	CUSTOMVERTEX  molevertex2[4]
	{
		{ -MOLE_W / 2 , -MOLE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ MOLE_W / 2 , -MOLE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ MOLE_W / 2 ,  MOLE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -MOLE_W / 2 ,  MOLE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	for (int i = 0; i < 4; i++)
	{
		drawmole2[i] = molevertex2[i];
		drawmole2[i].x += mole2.x;
		drawmole2[i].y += mole2.y;
	}

	if (mole.Move && count > 180)
	{
		mole.x += MOVESPEEDMOLE;
	}
	//モグラが穴に当たっていたら移動する
	if (hole.Active && mole.Skip == false)
	{
	//もしモグラが手前の穴に当たっていたら
		if (hole.x == mole.x)
		{
			mole.y += 30.f;
		}
	}
	//もし奥の穴に当たっていたら
	if (mole.x == hole2.x)
	{
		mole.y -= 30.f;
	}
		

	//もしモグラデットフラグがたっていたら中に入る
	if (mole.Dead)
	{
		static float angle = 15.f;

		mole.Move = false;

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
	if (mole.Dead == false)
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