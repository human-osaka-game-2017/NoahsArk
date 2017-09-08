#include "GameScene.h"
#include "finish.h"
#include "GameSceneScroll.h"
#include "gameSceneControl.h"


int ClickCount = 0;
int Rank = 0;


void value(int scene)
{
	int valuetable[8][3] = {
		{ 6,5,4 },
		{ 6,5,4 },
		{ 6,5,4 },
		{ 6,5,4 },
		{ 6.5,4 },
		{ 6,5,4 },
		{ 6,5,4 },
		{ 6,5,4 } };

	scene -= STAGEONE;

	Rank = 3;

	for (int i = 0; i < 2;i++)
	{
		if (ClickCount > valuetable[scene][i])
		{
			Rank = i;
		}
	}







}