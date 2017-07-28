#ifndef GAMESCENESCROLL
#define GAMESCENESCROLL

#include "GameScene.h"

#define SCROLLSPEED 2
#define RIGHT_AND_LEFT 720
#define ABOVE_AND_BELOW 325


extern CUSTOMVERTEX backGround[4];
extern CUSTOMVERTEX backGround2[4];
extern CUSTOMVERTEX drawright[4];
extern CUSTOMVERTEX drawleft[4];

struct mark
{
	float x;
	float y;
};


void scroll();
#endif 

