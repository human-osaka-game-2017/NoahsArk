#include "lion.h"
#include "hippopotamus.h"
#include "elephant.h"
#include "mole.h"
#include "risu.h"
#include "GameScene.h"
#include "char.h"
#include "systemCount.h"
#include "gameSceneControl.h"

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
		if (elephant.Move)
		{
			//もし止まっているライオンにゾウがに当たっていたら
			if (elephant.x >= lion.x - LION_W)
			{
				elephant.Skip = 180;
			}
		}
		if (hippopotamus.Move)
		{
			//もし止まっているライオンにカバがに当たっていたら
			if (hippopotamus.x >= lion.x - LION_W)
			{
				hippopotamus.Skip = 180;
			}
		}
		if (mole.Move)
		{
			//もし止まっているライオンにモグラがに当たっていたら
			if (mole.x >= lion.x - LION_W)
			{
				mole.Skip = 180;
			}
		}
		if (risu.Move)
		{
			//もし止まっているライオンにリスがに当たっていたら
			if (risu.x >= lion.x - LION_W)
			{
				risu.Skip = 180;
			}
		}

		if (stageProgres < risu.movement)
		{
			risu.Active = false;
		}
	}

}
void initStage5lion()
{
	Animal lion1 = { 435.f,400.f,false,true,true,false,false,0.f,435.f };
	lion = lion1;
}