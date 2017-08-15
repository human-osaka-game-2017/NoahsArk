#include "Mouse.h"
#include "GameScene.h"
#include "char.h"
#include "Control.h"
#include "hippopotamus.h"
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
		//像とカバが重なっていた場合
		if ((hippopotamus.x - HIPPOPOTAMUS_W / 2 < pt.x && hippopotamus.x + HIPPOPOTAMUS_W / 2 > pt.x && hippopotamus.y - HIPPOPOTAMUS_H / 2 < pt.y && hippopotamus.y + HIPPOPOTAMUS_H / 2 > pt.y) &&
			(elephant.x - ELEPHANT_W / 2 < pt.x && elephant.x + ELEPHANT_W / 2 > pt.x&& elephant.y - ELEPHANT_H / 2 < pt.y && elephant.y + ELEPHANT_H / 2 > pt.y))
		{
			if (g_MoveHippopotamus)
			{
				if (g_Moveelephant == true)
				{
					//どちらも動いている場合像の停止を優先
					g_Moveelephant = false;
				}

				//それ以外(像は停止している)場合はカバ停止、像移動
				g_Moveelephant = true;
				g_MoveHippopotamus = false;
			}
			//カバが停止していて、像が動いている場合
			else if (g_MoveHippopotamus == false)
			{
				if (g_Moveelephant == true)
				{
					g_Moveelephant = false;
					g_MoveHippopotamus = true;
				}
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
			//モグラが停止していて、像が動いている場合
			else if (g_MoveMole == false)
			{
				if (g_Moveelephant == true)
				{
					g_Moveelephant = false;
					g_MoveMole = true;
				}
			}
		}
		//カバとモグラが重なっていた場合
		if ((mole.x - MOLE_W / 2 < pt.x && mole.x + MOLE_W / 2 > pt.x && mole.y - MOLE_H / 2 < pt.y && mole.y + MOLE_H / 2 > pt.y) &&
			(hippopotamus.x - HIPPOPOTAMUS_W / 2 < pt.x && hippopotamus.x + HIPPOPOTAMUS_W / 2 > pt.x&& hippopotamus.y - HIPPOPOTAMUS_H / 2 < pt.y && hippopotamus.y + HIPPOPOTAMUS_H / 2 > pt.y))
		{
			if (g_MoveMole)
			{
				if (g_MoveHippopotamus == true)
				{
					//どちらも動いている場合カバの停止を優先
					g_MoveHippopotamus = false;
				}

				//それ以外(カバは停止している)場合はモグラ停止、カバ移動
				g_MoveHippopotamus = true;
				g_MoveMole = false;
			}
			//モグラが停止していて、カバが動いている場合
			else if (g_MoveHippopotamus == false)
			{
				if (g_MoveMole == true)
				{
					g_MoveMole = false;
					g_MoveHippopotamus = true;
				}
			}
		}
		//カバの座標内でクリックされた場合停止
		else if (hippopotamus.x - HIPPOPOTAMUS_W / 2 < pt.x && hippopotamus.x + HIPPOPOTAMUS_W / 2 > pt.x && hippopotamus.y - HIPPOPOTAMUS_H / 2 < pt.y && hippopotamus.y + HIPPOPOTAMUS_H / 2 > pt.y)
		{
			if (g_MoveHippopotamus)
			{
				//もし像が停止している場合は像は動き出す
				if (g_Moveelephant == false)
				{
					g_Moveelephant = true;
				}
				if (g_MoveMole == false)
				{
					g_MoveMole = true;
				}
				g_MoveHippopotamus = false;
			}

			else
			{
				g_MoveHippopotamus = true;
			}
		}
		//モグラの座標内でクリックされた場合停止
		else if (mole.x - MOLE_W / 2 < pt.x && mole.x + MOLE_W / 2 > pt.x && mole.y - MOLE_H / 2 < pt.y && mole.y + MOLE_H / 2 > pt.y)
		{
			if (g_MoveMole)
			{
				//もし像が停止している場合は像は動き出す
				if (g_Moveelephant == false)
				{
					g_Moveelephant = true;
				}
				if (g_MoveHippopotamus == false)
				{
					g_MoveHippopotamus = true;
				}
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
			//像が動いてカバが止まっている場合
			if (g_Moveelephant)
			{
				if (g_MoveHippopotamus == false)
				{
					g_MoveHippopotamus = true;
				}
				if (g_MoveMole == false)
				{
					g_MoveMole = true;
				}
				g_Moveelephant = false;
			}
			else if (g_Moveelephant == false)
			{
					g_Moveelephant = true;
			}
		}
		
	}
}

//左から右に流れるときのｘのあたり判定
void collision()
{
	//もしカバがうごいていたら
	if (g_MoveHippopotamus&&tree.Active)
	{
		//当たっているかの判定
		if (tree.x - TREE_W  < hippopotamus.x)
		{
			hippopotamusDeadFlg = true;
		}
			
	}
	//もしカバがうごいていたら
	if (g_MoveHippopotamus&&tree2.Active)
	{
		//当たっているかの判定
		if (tree2.x - TREE_W  < hippopotamus.x)
		{
			hippopotamusDeadFlg = true;
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