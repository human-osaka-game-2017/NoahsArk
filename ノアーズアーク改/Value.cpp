#include "GameScene.h"
#include "finish.h"
#include "GameSceneScroll.h"
#include "gameSceneControl.h"


int ClickCount = 0;
int Rank = 0;


void value(int scene)
{
	int valuetable[8][3] = {
		{ 7,6,4 },
		{ 8,7,5 },
		{ 6,5,4 },
		{ 5,4,2 },
		{ 7.6,4 },
		{ 7,6,4 },
		{ 7,6,4 },
		{ 6,5,4 } };

	scene -= STAGEONE;

	Rank = 2;

	for (int i = 0; i < 2;i++)
	{
		if (ClickCount >= valuetable[scene][i])
		{
			Rank = i;
		}
		else if (i == 1 && scene != 3 && ClickCount == valuetable[scene][i] || valuetable[scene][i] - 1)
		{ 
			Rank = i;
		}
	}







}