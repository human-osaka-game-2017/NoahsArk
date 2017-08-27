#include "Mouse.h"
#include "GameScene.h"
#include "char.h"
#include "Control.h"
#include "hippopotamus.h"
#include "elephant.h"
#include "tree.h"
#include "alligator.h"
#include "mole.h"


void animalInterlap(Animal animal, Animal animal2);

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
			animalInterlap(hippopotamus, elephant);

			/*if (hippopotamus.Move)
			{
				if(elephant.Move)
				{
					//どちらも動いている場合像の停止を優先
					elephant.Move = false;
					elephant.Push = true;
				}
				//それ以外(像は停止している)場合はカバ停止、像移動
				if (elephant.Push = false)
				{
					elephant.Move = true;
					hippopotamus.Move = false;
				}
				elephant.Push - false;
			}
			//カバが停止していて、像が動いている場合
			else if (hippopotamus.Move == false)
			{
				if (elephant.Move)
				{
					elephant.Move = false;
					hippopotamus.Move = true;
				}
			}*/
		}
		
		//像とモグラが重なっていた場合
		if ((mole.x - MOLE_W / 2 < pt.x && mole.x + MOLE_W / 2 > pt.x && mole.y - MOLE_H / 2 < pt.y && mole.y + MOLE_H / 2 > pt.y) &&
			(elephant.x - ELEPHANT_W / 2 < pt.x && elephant.x + ELEPHANT_W / 2 > pt.x&& elephant.y - ELEPHANT_H / 2 < pt.y && elephant.y + ELEPHANT_H / 2 > pt.y))
		{
			animalInterlap(mole, elephant);
		}
		//カバとモグラが重なっていた場合
		if ((mole.x - MOLE_W / 2 < pt.x && mole.x + MOLE_W / 2 > pt.x && mole.y - MOLE_H / 2 < pt.y && mole.y + MOLE_H / 2 > pt.y) &&
			(hippopotamus.x - HIPPOPOTAMUS_W / 2 < pt.x && hippopotamus.x + HIPPOPOTAMUS_W / 2 > pt.x&& hippopotamus.y - HIPPOPOTAMUS_H / 2 < pt.y && hippopotamus.y + HIPPOPOTAMUS_H / 2 > pt.y))
		{
			animalInterlap(mole, hippopotamus);
		}
		//カバの座標内でクリックされた場合停止
		else if (hippopotamus.x - HIPPOPOTAMUS_W / 2 < pt.x && hippopotamus.x + HIPPOPOTAMUS_W / 2 > pt.x && hippopotamus.y - HIPPOPOTAMUS_H / 2 < pt.y && hippopotamus.y + HIPPOPOTAMUS_H / 2 > pt.y)
		{
			if (hippopotamus.Move)
			{
				//もし像が停止している場合は像は動き出す
				if (elephant.Move == false)
				{
					elephant.Move = true;
				}
				if (mole.Move == false)
				{
					mole.Move = true;
				}
				hippopotamus.Move = false;
			}

			else
			{
				hippopotamus.Move = true;
			}
		}
		//モグラの座標内でクリックされた場合停止
		else if (mole.x - MOLE_W / 2 < pt.x && mole.x + MOLE_W / 2 > pt.x && mole.y - MOLE_H / 2 < pt.y && mole.y + MOLE_H / 2 > pt.y)
		{
			if (mole.Move)
			{
				//もし像が停止している場合は像は動き出す
				if (elephant.Move == false)
				{
					elephant.Move = true;
				}
				if (hippopotamus.Move == false)
				{
					hippopotamus.Move = true;
				}
				mole.Move = false;
			}
			else
			{
				mole.Move = true;
			}
		}
		

		//ゾウの座標内でクリックすると停止
		else if (elephant.x - ELEPHANT_W / 2 < pt.x && elephant.x + ELEPHANT_W / 2 > pt.x&& elephant.y - ELEPHANT_H / 2 < pt.y && elephant.y + ELEPHANT_H / 2 > pt.y)
		{
			//像が動いてカバが止まっている場合
			if (elephant.Move)
			{
				if (hippopotamus.Move == false)
				{
					hippopotamus.Move= true;
				}
				if (mole.Move == false)
				{
					mole.Move = true;
				}
				elephant.Move = false;
			}
			else if (elephant.Move == false)
			{
					elephant.Move = true;
			}
		}
		
	}
}


//左から右に流れるときのｘのあたり判定
void collision()
{
	//もしカバがうごいていたら
	if (hippopotamus.Move&&tree.Active)
	{
		//当たっているかの判定
		if (tree.x - TREE_W  < hippopotamus.x)
		{
			hippopotamus.Dead = true;
		}
			
	}
	//もしカバがうごいていたら
	if (hippopotamus.Move&&tree2.Active)
	{
		//当たっているかの判定
		if (tree2.x - TREE_W  < hippopotamus.x)
		{
			hippopotamus.Dead = true;
		}

	}
	//もしゾウがうごいていたら
	if (elephant.Move&&alligator.Active)
	{
		//当たっているかの判定
		if (alligator.x - ALLIGATOR_W< elephant.x)
		{
			//当たっていたら、当たった位置で止まる
			elephant.Dead = true;;
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
//動物がかなった時の判定関数
//引数1つ目が小さいほうの動物、引数２つ目が大きいほうの動物
void animalInterlap(Animal animal, Animal animal2)
{
	if (animal.Move)
	{
		if (animal2.Move == true)
		{
			//どちらも動いている場合像の停止を優先
			animal2.Move = false;
			animal2.Push = true;
		}

		//それ以外(像は停止している)場合はカバ停止、像移動
		if (animal2.Push == false)
		{
			animal2.Move = true;
			animal.Move = false;
		}
		animal2.Push = false;
	}
	//カバが停止していて、像が動いている場合
	else if (animal.Move == false)
	{
		if (animal2.Move == true)
		{
			animal2.Move = false;
			animal.Move = true;
		}
	}
}
//一つ目の動物がクリックされた動物、二つ目が残りの動物、三つ目も同様
void click(Animal animal,Animal animal2,Animal animal3)
{
	if (animal.Move)
	{
		//もし像が停止している場合は像は動き出す
		if (animal2.Move == false)
		{
			animal2.Move = true;
		}
		if (animal3.Move == false)
		{
			animal3.Move = true;
		}
		animal.Move = false;
	}
	else
	{
		animal.Move = true;
	}
}