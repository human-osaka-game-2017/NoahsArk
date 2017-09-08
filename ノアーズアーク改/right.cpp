#include "right.h"
#include "GameScene.h"
#include "Control.h"
#include "Mouse.h"
#include "GameSceneScroll.h"

//右マークの位置
mark right{ 1300.f,310.f };

CUSTOMVERTEX drawright[4];

void rightdraw()
{
	CUSTOMVERTEX rightvertex[4]
	{
		{ -RIGHT_W / 2.f,-RIGHT_H / 2.f,1.f,1.f,0xFFFFFFFF,0.f,0.f },
		{ RIGHT_W / 2.f,-RIGHT_H / 2.f,1.f,1.f,0xFFFFFFFF,1.f,0.f },
		{ RIGHT_W / 2.f,RIGHT_H / 2.f,1.f,1.f,0xFFFFFFFF,1.f,1.f },
		{ -RIGHT_W / 2.f,RIGHT_H / 2.f,1.f,1.f,0xFFFFFFFF,0.f,1.f }
	};
	for (int i = 0; i < 4; i++)
	{
		drawright[i] = rightvertex[i];
		drawright[i].x += right.x;
		drawright[i].y += right.y;
	}
}