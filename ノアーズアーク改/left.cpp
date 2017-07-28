#include "left.h"
#include "GameScene.h"
#include "Control.h"
#include "Mouse.h"
#include "GameSceneScroll.h"


mark left{ 80.f,310.f };

CUSTOMVERTEX drawleft[4];

void leftdraw()
{

	CUSTOMVERTEX leftvertex[4]
	{
		{ -LEFT_W / 2.f,-LEFT_H / 2.f,1.f,1.f,0xFFFFFFFF,0.f,0.f },
		{ LEFT_W / 2.f,-LEFT_H / 2.f,1.f,1.f,0xFFFFFFFF,1.f,0.f },
		{ LEFT_W / 2.f,LEFT_H / 2.f,1.f,1.f,0xFFFFFFFF,1.f,1.f },
		{ -LEFT_W / 2.f,LEFT_H / 2.f,1.f,1.f,0xFFFFFFFF,0.f,1.f }
	};

	for (int i = 0; i < 4; i++)
	{

		drawleft[i] = leftvertex[i];
		drawleft[i].x += left.x;
		drawleft[i].y += left.y;
	}
}

