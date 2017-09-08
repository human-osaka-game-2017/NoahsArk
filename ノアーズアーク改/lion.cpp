#include "lion.h"
#include "hippopotamus.h"
#include "elephant.h"
#include "mole.h"
#include "risu.h"
#include "GameScene.h"
#include "char.h"
#include "systemCount.h"
#include "gameSceneControl.h"
#include "Control.h"

//ライオンの初期位置
Animal lion = { 0.f,0.f,false,true,true,false,false,0.f,0.f }; 

CUSTOMVERTEX drawlion[4];

void liondraw()
{
	//ライオンの頂点情報
	CUSTOMVERTEX  lionvertex[4]
	{
		{ -LION_W / 2 ,-LION_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{  LION_W / 2 ,-LION_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{  LION_W / 2 ,  LION_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -LION_W / 2 ,  LION_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	//位置と頂点情報を代入する
	for (int i = 0; i < 4; i++)
	{
		drawlion[i] = lionvertex[i];
		drawlion[i].x += lion.x;
		drawlion[i].y += lion.y;
	}
	
	if (lion.Move && count > 180)
	{
		lion.x += MOVESPEEDLION;
		lion.movement += MOVESPEEDLION;
	}
	if (lion.Move == false)
	{
		if (elephant.Move && elephant.Skip == 0)
		{
			//もし止まっているライオンにゾウがに当たっていたら
			if (elephant.x == lion.x + LION_W)
			{
				elephant.Skip = 180;
			}
		}
		if (hippopotamus.Move && hippopotamus.Skip == 0)
		{
			//もし止まっているライオンにカバがに当たっていたら
			if (hippopotamus.x == lion.x + LION_W)
			{
				hippopotamus.Skip = 180;
			}
		}
		if (mole.Move && mole.Skip == 0)
		{
			//もし止まっているライオンにモグラがに当たっていたら
			if (mole.x == lion.x + LION_W)
			{
				mole.Skip = 180;
			}
		}
		if (risu.Move && risu.Skip == 0)
		{
			//もし止まっているライオンにリスがに当たっていたら
			if (risu.x == lion.x + LION_W)
			{
				risu.Skip = 180;
			}
		}
	}
	// もしライオンデットフラグがたっていたら中に入る
	if (lion.Dead)
	{
		static float angle = 15.f;
		lion.Move = false;

		angle += 15.f;
		if (angle >= 180)
		{
			angle = 180.f;
		}
		//関数呼び出し
		Kaiten(-angle, lionvertex, drawlion);

		for (int i = 0; i < 4; i++)
		{
			//elephant.x -= DEADMOVESPEED_W;
			//elephant.y -= DEADMOVESPEED_H;
			drawlion[i].x += lion.x;
			drawlion[i].y += lion.y;
		}
	}
		if (stageProgres < lion.movement)
		{
			lion.Active = false;
		}

}
void initStage6lion()
{
	Animal lion1 = { 350.f,400.f,false,true,true,false,false,0.f,350.f };
	lion = lion1;
}
void initStage7lion()
{
	Animal lion3 = { 1000.f,400.f,false,true,true,false,false,0.f,1000.f };
	lion = lion3;
}