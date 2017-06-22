#include "Mouse.h"
#include "GameScene.h"
#include "char.h"
#include "Control.h"

bool HitFlg = false;

Animal elephant = { 300.f,500.f,true,false };//ゾウ

Animal lion={500.f,500.f,true,false};   //ライオン

mob alligator = { 1000.f,500.f,false,false };   //ワニ(障害物)

mob tree = { 756.f,500.f,false,false }; //木



	enum BTN_STATE 
	{
		ON,			// 　押しっぱなし
		OFF,		//　　離れっぱなし
		PUSH,		//　　瞬間押された
		RELEASE,	//　　瞬間離された
	};

	BTN_STATE g_OldMouse = OFF;
	BTN_STATE g_CurrentMouse = OFF;

	bool g_MoveLion = true;
	short oldMouse = 0;
	short currentMouse = 0;

	//マウスのチェック関数
	BTN_STATE CheckMouseL()
	{
		if (GetAsyncKeyState(VK_LBUTTON))
		{
			if (g_OldMouse == OFF)
			{
				g_CurrentMouse = PUSH;
			}
			else
			{
				g_CurrentMouse = ON;
			}

			g_OldMouse = ON;
		}
		else
		{
			if (g_OldMouse == ON)
			{
				g_CurrentMouse = RELEASE;
			}
			else
			{
				g_CurrentMouse = OFF;
			}
			g_OldMouse = OFF;
		}

		return g_CurrentMouse;
	}
	
	//マウスが押された時の動作
void Control() 
{
	
	if (CheckMouseL() == PUSH)
	{
			if (g_MoveLion)
				{
					g_MoveLion = false;

				}
				else
				{

					g_MoveLion = true;
				}
		
	}
	
	if (g_MoveLion)
	{
		lion.x += MOVESPEED;

	}
}
//あたり判定

void Hit()
{
	if (g_MoveLion)
	{
		if (tree.x<lion.x)
		{
			lion.x -= MOVESPEED;
		}
	}
}
