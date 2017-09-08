#include "char.h"
#include "GameScene.h"
#include "mole.h"
#include "Control.h"
#include "hole.h"
#include"systemCount.h"
#include "lion.h"
#include "gameSceneControl.h"

bool dive1 = false;
bool dive2 = false;


//モグラの位置
Animal mole = { 0.f,0.f,false,true,true,false,false,0.f,0.f }; //ステージ4
//Animal mole2 = { 300.f,400.f,false,true,true,false,false,false }; //ステージ8

CUSTOMVERTEX drawmole[4];
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
	
	if (mole.Skip > 0 && mole.Dead == false)
	{
		mole.Skip--;
		mole.x += (PLUSMOVESPEED + MOVESPEEDMOLE);
		mole.movement += (PLUSMOVESPEED + MOVESPEEDMOLE);
	}
	if (mole.Move && count > 180 && mole.Skip == 0)
	{
		mole.x += MOVESPEEDMOLE;
		mole.movement += MOVESPEEDMOLE;
	}
	//モグラが穴に当たっていたら移動する
	if (hole.Active && mole.Skip == false)
	{
	//もしモグラが手前の穴に当たっていたら
		if (hole.x == mole.x)
		{
			mole.Active = false;
			dive1 = true;
			mole.y += 50.f;
		}
	}
	//もし奥の穴に当たっていたら
	if (mole.x == hole2.x && mole.Active == false)
	{
		mole.Active = true;
		mole.y -= 50.f;
	}
	//モグラが穴に当たっていたら移動する
	if (hole3.Active && mole.Skip == false)
	{
		//もしモグラが手前の穴に当たっていたら
		if (hole3.x == mole.x)
		{
			mole.Active = false;
			dive2 = true;
			mole.y += 50.f;
		}
	}
	//もし奥の穴に当たっていたら
	if (mole.x == hole4.x)
	{
		mole.Active = true;
		mole.y -= 50.f;
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
	
	if (stageProgres < mole.movement)
	{
		mole.Active = false;
	}
}
void initStage4mole()
{
	Animal mole1 = { 314.f,400.f,false,true,true,false,false,0.f,314.f }; //ステージ4
	mole = mole1;

	dive1 = false;
	dive2 = false;
}
void initStage5mole()
{
	Animal mole2 = { 750.f,400.f,false,true,true,false,false,0.f,750.f }; //ステージ4
	mole = mole2;

	dive1 = false;
}
void initStage7mole()
{
	Animal mole4 = { 600.f,400.f,false,true,true,false,false,0.f,600.f }; //ステージ4
	mole = mole4;

	dive1 = false;
}