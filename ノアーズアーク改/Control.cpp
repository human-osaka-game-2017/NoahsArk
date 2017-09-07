#include "Mouse.h"
#include "GameScene.h"
#include "char.h"
#include "Control.h"
#include "hippopotamus.h"
#include "elephant.h"
#include "tree.h"
#include "alligator.h"
#include "mole.h"
#include "lion.h"
#include "risu.h"
#include "chestnut.h"
void animalInterlap(Animal *animal, Animal *animal2);
void click2(Animal *animal, Animal *animal2);
void click5(Animal *animal, Animal *animal2, Animal *animal3, Animal *animal4, Animal *animal5);

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
			animalInterlap(&hippopotamus, &elephant);
		}
		
		//像とモグラが重なっていた場合
		if ((mole.x - MOLE_W / 2 < pt.x && mole.x + MOLE_W / 2 > pt.x && mole.y - MOLE_H / 2 < pt.y && mole.y + MOLE_H / 2 > pt.y) &&
			(elephant.x - ELEPHANT_W / 2 < pt.x && elephant.x + ELEPHANT_W / 2 > pt.x&& elephant.y - ELEPHANT_H / 2 < pt.y && elephant.y + ELEPHANT_H / 2 > pt.y))
		{
			animalInterlap(&mole, &elephant);
		}
		//カバとモグラが重なっていた場合
		if ((mole.x - MOLE_W / 2 < pt.x && mole.x + MOLE_W / 2 > pt.x && mole.y - MOLE_H / 2 < pt.y && mole.y + MOLE_H / 2 > pt.y) &&
			(hippopotamus.x - HIPPOPOTAMUS_W / 2 < pt.x && hippopotamus.x + HIPPOPOTAMUS_W / 2 > pt.x&& hippopotamus.y - HIPPOPOTAMUS_H / 2 < pt.y && hippopotamus.y + HIPPOPOTAMUS_H / 2 > pt.y))
		{
			animalInterlap(&mole, &hippopotamus);
		}
		//ライオンとカバが重なっていた場合
		if ((lion.x - LION_W / 2 < pt.x && lion.x + LION_W / 2 > pt.x && lion.y - LION_H / 2 < pt.y && lion.y + LION_H / 2 > pt.y) &&
			(hippopotamus.x - HIPPOPOTAMUS_W / 2 < pt.x && hippopotamus.x + HIPPOPOTAMUS_W / 2 > pt.x&& hippopotamus.y - HIPPOPOTAMUS_H / 2 < pt.y && hippopotamus.y + HIPPOPOTAMUS_H / 2 > pt.y))
		{
			animalInterlap(&lion, &hippopotamus);
		}
		//ライオンとモグラが重なっていた場合
		if ((mole.x - MOLE_W / 2 < pt.x && mole.x + MOLE_W / 2 > pt.x && mole.y - MOLE_H / 2 < pt.y && mole.y + MOLE_H / 2 > pt.y) &&
			(lion.x - LION_W / 2 < pt.x && lion.x + LION_W / 2 > pt.x && lion.y - LION_H / 2 < pt.y && lion.y + LION_H / 2 > pt.y))
		{
			animalInterlap(&mole, &lion);
		}
		//リスとゾウが重なっていた場合
		if ((risu.x - RISU_W / 2 < pt.x && risu.x + RISU_W / 2 > pt.x && risu.y - RISU_H / 2 < pt.y && risu.y + RISU_H / 2 > pt.y) &&
			(elephant.x - ELEPHANT_W / 2 < pt.x && elephant.x + ELEPHANT_W / 2 > pt.x&& elephant.y - ELEPHANT_H / 2 < pt.y && elephant.y + ELEPHANT_H / 2 > pt.y))
		{
			animalInterlap(&risu, &elephant);
		}
		//リスとカバが重なっていた場合
		if ((risu.x - RISU_W / 2 < pt.x && risu.x + RISU_W / 2 > pt.x && risu.y - RISU_H / 2 < pt.y && risu.y + RISU_H / 2 > pt.y) &&
			(hippopotamus.x - HIPPOPOTAMUS_W / 2 < pt.x && hippopotamus.x + HIPPOPOTAMUS_W / 2 > pt.x&& hippopotamus.y - HIPPOPOTAMUS_H / 2 < pt.y && hippopotamus.y + HIPPOPOTAMUS_H / 2 > pt.y))
		{
			animalInterlap(&risu, &hippopotamus);
		}//リスとライオンが重なっていた場合
		if ((risu.x - RISU_W / 2 < pt.x && risu.x + RISU_W / 2 > pt.x && risu.y - RISU_H / 2 < pt.y && risu.y + RISU_H / 2 > pt.y) &&
			(lion.x - LION_W / 2 < pt.x && lion.x + LION_W / 2 > pt.x && lion.y - LION_H / 2 < pt.y && lion.y + LION_H / 2 > pt.y))
		{
			animalInterlap(&risu, &lion);
		}//リスとモグラが重なっていた場合
		if ((risu.x - RISU_W / 2 < pt.x && risu.x + RISU_W / 2 > pt.x && risu.y - RISU_H / 2 < pt.y && risu.y + RISU_H / 2 > pt.y) &&
			(mole.x - MOLE_W / 2 < pt.x && mole.x + MOLE_W / 2 > pt.x && mole.y - MOLE_H / 2 < pt.y && mole.y + MOLE_H / 2 > pt.y))
		{
			animalInterlap(&risu, &mole);
		}
		//カバの座標内でクリックされた場合停止
		else if (hippopotamus.x - HIPPOPOTAMUS_W / 2 < pt.x && hippopotamus.x + HIPPOPOTAMUS_W / 2 > pt.x && hippopotamus.y - HIPPOPOTAMUS_H / 2 < pt.y && hippopotamus.y + HIPPOPOTAMUS_H / 2 > pt.y && hippopotamus.Skip == 0)
		{
			click5(&hippopotamus,&elephant,&risu,&lion,&mole);
		}
		//ゾウの座標内でクリックされた場合停止
		else if (elephant.x - ELEPHANT_W / 2 < pt.x && elephant.x + ELEPHANT_W / 2 > pt.x && elephant.y - ELEPHANT_H / 2 < pt.y && elephant.y + ELEPHANT_H / 2 > pt.y && elephant.Skip == 0)
		{
			click5(&elephant, &hippopotamus, &risu, &lion, &mole);
		}
		//リスの座標内でクリックされた場合停止
		else if (risu.x - RISU_W / 2 < pt.x && risu.x + RISU_W / 2 > pt.x && risu.y - RISU_H / 2 < pt.y && risu.y + RISU_H / 2 > pt.y && risu.Skip == 0)
		{
			click5(&risu, &elephant, &hippopotamus, &lion, &mole);
		}//ライオンの座標内でクリックされた場合停止
		else if (lion.x - LION_W / 2 < pt.x && lion.x + LION_W / 2 > pt.x && lion.y - LION_H / 2 < pt.y && lion.y + LION_H / 2 > pt.y)
		{
			click5(&lion, &elephant, &risu, &hippopotamus, &mole);
		}//モグラの座標内でクリックされた場合停止
		else if (mole.x - MOLE_W / 2 < pt.x && mole.x + MOLE_W / 2 > pt.x && mole.y - MOLE_H / 2 < pt.y && mole.y + MOLE_H / 2 > pt.y && mole.Skip == 0)
		{
			click5(&mole, &elephant, &risu, &lion, &hippopotamus);
		}
	}
}


//左から右に流れるときのｘのあたり判定
void collision()
{
	//カバ///////////////////////////////////////////////////////////
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
	//もしカバがうごいていたら
	if (hippopotamus.Move&&chestnut.Active)
	{
		//当たっているかの判定
		if (chestnut.x - CHESTNUT_W < hippopotamus.x)
		{
			hippopotamus.Dead = true;
		}
	}
	//もしカバがうごいていたら
	if (hippopotamus.Move&&chestnut2.Active)
	{
		//当たっているかの判定
		if (chestnut2.x - CHESTNUT_W < hippopotamus.x)
		{
			hippopotamus.Dead = true;
		}
	}
	//////////////////////////////////////////////////////////

	//ゾウ///////////////////////////////////////////////////////////////////////
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
	//もしカバがうごいていたら
	if (elephant.Move&&chestnut.Active)
	{
		//当たっているかの判定
		if (chestnut.x - CHESTNUT_W < elephant.x)
		{
			elephant.Dead = true;
		}
	}//もしカバがうごいていたら
	if (elephant.Move&&chestnut2.Active)
	{
		//当たっているかの判定
		if (chestnut2.x - CHESTNUT_W < elephant.x)
		{
			elephant.Dead = true;
		}
	}
	///////////////////////////////////////////////////////////////

	//リス///////////////////////////////////////////////////////////////////
	if (risu.Move&&tree.Active)
	{
		//当たっているかの判定
		if (tree.x - TREE_W < risu.x)
		{
			risu.Dead = true;
		}
	}
	if (risu.Move&&tree2.Active)
	{
		//当たっているかの判定
		if (tree2.x - TREE_W < risu.x)
		{
			risu.Dead = true;
		}
	}
	if (risu.Move&&alligator.Active)
	{
		//当たっているかの判定
		if (alligator.x - ALLIGATOR_W < risu.x)
		{
			risu.Dead = true;
		}
	}
	///////////////////////////////////////////////////////////////////////////////////////////////

	//モグラ///////////////////////////////////////////////////////////////////////////////////////
	if (mole.Move&&tree.Active)
	{
		//当たっているかの判定
		if (tree.x - TREE_W < mole.x)
		{
			mole.Dead = true;
		}
	}
	if (mole.Move&&tree2.Active)
	{
		//当たっているかの判定
		if (tree2.x - TREE_W < mole.x)
		{
			mole.Dead = true;
		}
	}
	if (mole.Move&&alligator.Active)
	{
		//当たっているかの判定
		if (alligator.x - ALLIGATOR_W < mole.x)
		{
			mole.Dead = true;
		}
	}
	if (mole.Move&&chestnut.Active)
	{
		//当たっているかの判定
		if (chestnut.x - CHESTNUT_W < mole.x)
		{
			mole.Dead = true;
		}
	}
	if (mole.Move&&chestnut2.Active)
	{
		//当たっているかの判定
		if (chestnut2.x - CHESTNUT_W < mole.x)
		{
			mole.Dead = true;
		}
	}
	///////////////////////////////////////////////////////////////
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
void animalInterlap(Animal *animal, Animal *animal2)
{
	if (animal->Move)
	{
		if (animal2->Move == true)
		{
			//どちらも動いている場合像の停止を優先
			animal->Move = false;
			animal2->Push = true;
		}

		//それ以外(像は停止している)場合はカバ停止、像移動
		if (animal2->Push == false)
		{
			animal2->Move = true;
			animal->Move = false;
		}
		animal2->Push = false;
	}
	//カバが停止していて、像が動いている場合
	else if (animal->Move == false)
	{
		if (animal2->Move == true)
		{
			animal2->Move = false;
			animal->Move = true;
		}
	}
}
void click2(Animal *animal, Animal *animal2)
{
	if (animal->Move)
	{
		//もし像が停止している場合は像は動き出す
		if (animal2->Move == false)
		{
			animal2->Move = true;
		}
		animal->Move = false;
	}
	else
	{
		animal->Move = true;
	}
}
//一つ目の動物がクリックされた動物、二つ目が残りの動物、三つ目も同様
void click5(Animal *animal,Animal *animal2,Animal *animal3,Animal *animal4,Animal *animal5)
{
	if (animal->Move)
	{
		//もし像が停止している場合は像は動き出す
		if (animal2->Move == false)
		{
			animal2->Move = true;
		}
		if (animal3->Move == false)
		{
			animal3->Move = true;
		}
		if (animal4->Move == false)
		{
			animal4->Move = true;
		}
		if (animal5->Move == false)
		{
			animal5->Move = true;
		}
		animal->Move = false;
	}
	else
	{
		animal->Move = true;
	}
}