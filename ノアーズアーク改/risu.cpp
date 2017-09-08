#include "risu.h"
#include "chestnut.h"
#include "char.h"
#include "GameScene.h"
#include "Control.h"
#include "finish.h"
#include "hole.h"
#include "systemCount.h"
#include "lion.h"
#include "chestnut.h"
#include "gameSceneControl.h"
//リスの初期位置
Animal risu = { 0.f,0.f,false,true,true,false,false,0.f,0.f }; //ステージ2
//Animal risu5 = { 90.f,400.f,false,true }; //ステージ8

CUSTOMVERTEX drawrisu[4];
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
	
	if (risu.Skip > 0)
	{
		risu.Skip--;
		risu.x += (PLUSMOVESPEED+MOVESPEEDRISU);
		risu.movement += (PLUSMOVESPEED + MOVESPEEDRISU);
	}
	if (risu.Move && count > 180 && risu.Skip == 0)
	{
		risu.x += MOVESPEEDRISU;
		risu.movement += MOVESPEEDRISU;
	}
	//もしリスが栗の左に当たっていたら
	if (risu.x >= chestnut.x - CHESTNUT_W && risu.y >= chestnut.y)
	{
		//木を消す
		chestnut.Active = false;
	}//もしリスが栗２の左に当たっていたら
	if (risu.x >= chestnut2.x - CHESTNUT_W && risu.y >= chestnut.y)
	{
		//木を消す
		chestnut2.Active = false;
	}
	//リスが穴に当たっていたら移動する
	if (hole.Active && risu.Skip == false)
	{
		//もしモグラが手前の穴に当たっていたら
		if (hole.x == risu.x)
		{
			risu.Active = false;
			risu.y += 50.f;
		}
	}
	//もし奥の穴に当たっていたら
	if (risu.x == hole2.x)
	{
		risu.Active = true;
		risu.y += 50.f;
	}
	//リスが穴に当たっていたら移動する
	if (hole3.Active && risu.Skip == false)
	{
		//もしモグラが手前の穴に当たっていたら
		if (hole3.x == risu.x)
		{
			risu.Active = false;
			risu.y += 50.f;
		}
	}
	//もし奥の穴に当たっていたら
	if (risu.x == hole4.x)
	{
		risu.Active = true;
		risu.y += 50.f;
	}
	//もしリスデットフラグがたっていたら中に入る
	if (risu.Dead)
	{
		static float angle = 15.f;

		risu.Move = false;

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
	
	if (stageProgres < risu.movement)
	{
		risu.Active = false;
	}
}
void initStage2risu()
{
	Animal risu1 = { 425.f,400.f,false,true,true,false,false,0.f,425.f }; //ステージ2
	risu = risu1;
}
void initStage3risu()
{
	Animal risu2 = { 362.f,400.f,false,true,true,false,false,0.f,362.f };
	risu = risu2;
}
void initStage4risu()
{
	Animal risu3 = { 195.f,400.f,false,true,true,false,false,0.f,195.f }; //ステージ4
	risu = risu3;
}
void initStage5risu()
{
	Animal risu4 = { 550.f,400.f,false,true,true,false,false,0.f,550.f }; //ステージ6
	risu = risu4;
}
