#include "Mouse.h"
#include "GameScene.h"
#include "char.h"
#include "Control.h"
#include "lion.h"
#include "elephant.h"
#include "tree.h"
#include "alligator.h"
#include "mole.h"

//動物が動いているか止まっているかの判定　動いているときtrue,止まっているときfalse
//mob chestnut = { 900.f,500.f,false };//栗

	BTN_STATE g_OldMouse = OFF;
	BTN_STATE g_CurrentMouse = OFF;

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
		//像とライオンが重なっていた場合
		if ((lion.x - LION_W / 2 < pt.x && lion.x + LION_W / 2 > pt.x && lion.y - LION_H / 2 < pt.y && lion.y + LION_H / 2 > pt.y) &&
			(elephant.x - ELEPHANT_W / 2 < pt.x && elephant.x + ELEPHANT_W / 2 > pt.x&& elephant.y - ELEPHANT_H / 2 < pt.y && elephant.y + ELEPHANT_H / 2 > pt.y))
		{
			if (g_MoveLion)
			{
				if (g_Moveelephant == true)
				{
					//どちらも動いている場合像の停止を優先
					g_Moveelephant = false;
				}

				//それ以外(像は停止している)場合はライオン停止、像移動
				g_Moveelephant = true;
				g_MoveLion = false;
			}

			else if (g_MoveLion == false)
			{
				//ライオンが停止していて、像が動いている場合
				if (g_Moveelephant == true)
				{
					g_Moveelephant = false;
					g_MoveLion = true;
				}
			}
		}
		//ライオンの座標内でクリックされた場合停止
		else if (lion.x - LION_W / 2 < pt.x && lion.x + LION_W / 2 > pt.x && lion.y - LION_H / 2 < pt.y && lion.y + LION_H / 2 > pt.y)
		{
			if (g_MoveLion)
			{
				//もし像が停止している場合は像は動き出す
				if (g_Moveelephant == false)
				{
					g_Moveelephant = true;
				}
				g_MoveLion = false;
			}

			else
			{

				g_MoveLion = true;
			}
		}
		//像とモグラが重なっていた場合
		if ((mole.x - MOLE_W / 2 < pt.x && mole.x + MOLE_W / 2 > pt.x && mole.y - MOLE_H / 2 < pt.y && mole.y + MOLE_H / 2 > pt.y) &&
			(elephant.x - ELEPHANT_W / 2 < pt.x && elephant.x + ELEPHANT_W / 2 > pt.x&& elephant.y - ELEPHANT_H / 2 < pt.y && elephant.y + ELEPHANT_H / 2 > pt.y))
		{
			if (g_MoveMole)
			{
				if (g_Moveelephant == true)
				{
					//どちらも動いている場合像の停止を優先
					g_Moveelephant = false;
				}

				//それ以外(像は停止している)場合はモグラ停止、像移動
				g_Moveelephant = true;
				g_MoveMole = false;
			}
		}
		//ライオンとモグラが重なっていた場合
		if ((mole.x - MOLE_W / 2 < pt.x && mole.x + MOLE_W / 2 > pt.x && mole.y - MOLE_H / 2 < pt.y && mole.y + MOLE_H / 2 > pt.y) &&
			(lion.x - LION_W / 2 < pt.x && lion.x + LION_W / 2 > pt.x&& lion.y - LION_H / 2 < pt.y && lion.y + LION_H / 2 > pt.y))
		{
			if (g_MoveMole)
			{
				if (g_MoveLion == true)
				{
					//どちらも動いている場合ライオンの停止を優先
					g_MoveLion = false;
				}

				//それ以外(ライオンは停止している)場合はモグラ停止、ライオン移動
				g_MoveLion = true;
				g_MoveMole = false;
			}
		}
		//モグラの座標内でクリックされた場合停止
		else if (mole.x - MOLE_W / 2 < pt.x && mole.x + MOLE_W / 2 > pt.x && mole.y - MOLE_H / 2 < pt.y && mole.y + MOLE_H / 2 > pt.y)
		{
			if (g_MoveMole)
			{
				g_MoveMole = false;
			}
			else
			{
				g_MoveMole = true;
			}
		}
		

		//ゾウの座標内でクリックすると停止
		else if (elephant.x - ELEPHANT_W / 2 < pt.x && elephant.x + ELEPHANT_W / 2 > pt.x&& elephant.y - ELEPHANT_H / 2 < pt.y && elephant.y + ELEPHANT_H / 2 > pt.y)
		{
			//像が動いてライオンが止まっている場合
			if (g_Moveelephant)
			{
				if (g_MoveLion == false)
				{
					g_Moveelephant = false;
					g_MoveLion = true;

				}
				g_Moveelephant = false;
			}
			else if (g_Moveelephant == false)
			{
				if (g_MoveLion)
				{
					g_Moveelephant = true;
				}
			}
		}
		
	}
}

//左から右に流れるときのｘのあたり判定
void collision()
{
	//もしライオンがうごいていたら
	if (g_MoveLion&&tree.Active)
	{
		//当たっているかの判定
		if (tree.x - TREE_W  < lion.x)
		{
			LionDeadFlg = true;
		}
			
	}
	//もしライオンがうごいていたら
	if (g_MoveLion&&tree2.Active)
	{
		//当たっているかの判定
		if (tree2.x - TREE_W  < lion.x)
		{
			LionDeadFlg = true;
		}

	}
	//もしゾウがうごいていたら
	if (g_Moveelephant&&alligator.Active)
	{
		//当たっているかの判定
		if (alligator.x - ALLIGATOR_W< elephant.x)
		{
			//当たっていたら、当たった位置で止まる
			ElephantDeadFlg = true;;
		}
	}
}
//回転関数
void Kaiten(float kakudo, CUSTOMVERTEX src[], CUSTOMVERTEX dest[])
{
	float cx, cy;
	float rad;

	rad = D3DXToRadian(kakudo);

	cx = (src[0].x + src[1].x) / 2.0f;
	cy = (src[0].y + src[3].y) / 2.0f;
	for (int i = 0; i < 4; i++) {
		//中心を原点に
		src[i].x -= cx;
		src[i].y -= cy;


			dest[i] = src[i];
			dest[i].x = src[i].x * cos(rad)
				- src[i].y * sin(rad);
			dest[i].y = src[i].x * sin(rad)
				+ src[i].y * cos(rad);
			
			// 原点から中心
			src[i].x += cx;
			src[i].y += cy;
			dest[i].x += cx;
			dest[i].y += cy;
	}
}