#ifndef CONTROL
#define CONTROL

#include"char.h"
#include "GameScene.h"

//角加速度
#define ZNGULAR_ACCELERATION 5.f

 enum BTN_STATE
{
	ON,			// 　押しっぱなし
	OFF,		//　　離れっぱなし
	PUSH,		//　　瞬間押された
	RELEASE,	//　　瞬間離された
};

extern POINT pt;
extern mob tree;
extern mob chestnut;

void Kaiten(float kakudo, CUSTOMVERTEX src[], CUSTOMVERTEX dest[]);
void Control();
void collision();
BTN_STATE CheckMouseL();
#endif
