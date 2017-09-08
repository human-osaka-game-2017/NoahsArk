#include "GameSceneScroll.h"
#include "GameScene.h"
#include "Mouse.h"
#include "Control.h"
#include "right.h"
#include "left.h"
#include "alligator.h"
#include "elephant.h"
#include "hippopotamus.h"
#include "tree.h"
#include "chestnut.h"
#include "hole.h"
#include "gameSceneControl.h"
//画面の中点
mark backGD{ 720.f,325.f };
// バックグラウンドの頂点情報を作成する
CUSTOMVERTEX backGround[4]
{
	{ backGD.x - RIGHT_AND_LEFT, backGD.y - ABOVE_AND_BELOW, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ backGD.x + RIGHT_AND_LEFT, backGD.y - ABOVE_AND_BELOW, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ backGD.x + RIGHT_AND_LEFT, backGD.y + ABOVE_AND_BELOW, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ backGD.x - RIGHT_AND_LEFT, backGD.y + ABOVE_AND_BELOW, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
};
//上と同じ背景
CUSTOMVERTEX backGround2[4]
{
	{ backGD.x - RIGHT_AND_LEFT + 1440, backGD.y - ABOVE_AND_BELOW, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ backGD.x + RIGHT_AND_LEFT + 1440, backGD.y - ABOVE_AND_BELOW, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ backGD.x + RIGHT_AND_LEFT + 1440, backGD.y + ABOVE_AND_BELOW, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ backGD.x - RIGHT_AND_LEFT + 1440, backGD.y + ABOVE_AND_BELOW, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
};

//スクロールする関数
void scroll()
{
	
	if (backGD.x + RIGHT_AND_LEFT < backGround2[1].x)
	{
		//マウスが押されていたら
		if (CheckMouseL() == ON)
		{
			//右の画像のなかにはいってたら
			if (right.x - RIGHT_W / 2 < pt.x
				&&right.x + RIGHT_W / 2 > pt.x
				&&right.y - RIGHT_H / 2 < pt.y
				&&right.y + RIGHT_H / 2 > pt.y)
			{
				for (int i = 0; i < 4; i++)
				{
					//背景を左にずらす
					backGround[i].x -= SCROLLSPEED;
					backGround2[i].x -= SCROLLSPEED;
				}
				//すべての障害物やどうぶつもずらしてあげる
				hippopotamus.x -= SCROLLSPEED;
				elephant.x -= SCROLLSPEED;
				tree.x -= SCROLLSPEED;
				tree2.x -= SCROLLSPEED;
				alligator.x -= SCROLLSPEED;
				chestnut.x -= SCROLLSPEED;
				hole.x -= SCROLLSPEED;
				hole2.x -= SCROLLSPEED;
				//backGD.x -= SCROLLSPEED;
				stageProgres -= SCROLLSPEED;
			}
		}
	}
	if (backGD.x - RIGHT_AND_LEFT > backGround[0].x)
	{
		if (CheckMouseL() == ON)
		{
			//左の画像の中で押されていたら
			if (left.x - LEFT_W / 2 < pt.x
				&&left.x + LEFT_W / 2 > pt.x
				&&left.y - LEFT_H / 2 < pt.y
				&&left.y + LEFT_H / 2 > pt.y)
			{
				for (int i = 0; i < 4; i++)
				{
					//背景を右にずらす
					backGround[i].x += SCROLLSPEED;
					backGround2[i].x += SCROLLSPEED;
				}
				//すべての障害物やどうぶつもずらしてあげる
				hippopotamus.x += SCROLLSPEED;
				elephant.x += SCROLLSPEED;
				tree.x += SCROLLSPEED;
				tree2.x += SCROLLSPEED;
				hole.x += SCROLLSPEED;
				hole2.x += SCROLLSPEED;
				chestnut.x += SCROLLSPEED;
				alligator.x += SCROLLSPEED;
				stageProgres += SCROLLSPEED;
			}
		}
	}
}