#ifndef CONTROL
#define CONTROL

#include"char.h"
#include "GameScene.h"

//�p�����x
#define ZNGULAR_ACCELERATION 5.f

 enum BTN_STATE
{
	ON,			// �@�������ςȂ�
	OFF,		//�@�@������ςȂ�
	PUSH,		//�@�@�u�ԉ����ꂽ
	RELEASE,	//�@�@�u�ԗ����ꂽ
};

extern POINT pt;
extern mob tree;
extern mob chestnut;

void Kaiten(float kakudo, CUSTOMVERTEX src[], CUSTOMVERTEX dest[]);
void Control();
void collision();
BTN_STATE CheckMouseL();
#endif
