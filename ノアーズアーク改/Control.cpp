#include "Mouse.h"
#include "GameScene.h"
#include "char.h"
#include "Control.h"


Animal elephant = { 300.f,500.f,true,false };//ゾウ

Animal lion = { 200.f,500.f,true,false };;  //ライオン

mob alligator = { 1000.f,500.f,false,false };   //ワニ(障害物)

mob tree = { 700.f,500.f,false,false }; //木

//mob chestnut = { 900.f,500.f,false,false };//栗



	enum BTN_STATE 
	{
		ON,			// 　押しっぱなし
		OFF,		//　　離れっぱなし
		PUSH,		//　　瞬間押された
		RELEASE,	//　　瞬間離された
	};

	BTN_STATE g_OldMouse = OFF;
	BTN_STATE g_CurrentMouse = OFF;

	//動物が動いているか止まっているかの判定　動いているときtrue,止まっているときfalse
	bool g_MoveLion = true;
	bool g_Moveelephant = true;

	
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
		////ライオン（まだ画像の中を押さなくてもゲーム画面のどこかを押したら止まる）
		if (g_MoveLion)
			{
				g_MoveLion = false;

			}
			else
			{

				g_MoveLion = true;
			}

		////ゾウまだ画像の中を押さなくてもゲーム画面のどこかを押したら止まる）
			if (g_Moveelephant)
			{
				g_Moveelephant = false;

			}
			else
			{

				g_Moveelephant = true;
			}
		
	}
	
	if (g_MoveLion)
	{
		lion.x += MOVESPEEDLION;

	}

	if (g_Moveelephant)
	{
		elephant.x += MOVESPEEDELEPHANT;
	}


}
//あたり判定

void Hit()
{
	//もしライオンがうごいていたら
	if (g_MoveLion)
	{
		//当たっているかの判定
		if (tree.x -52 < lion.x)
		{
			//当たっていたら、当たった位置で止まる
			lion.x -= MOVESPEEDLION;
		}
	}
	if (g_Moveelephant)
	{
		if (alligator.x -78 < elephant.x)
		{
			elephant.x -= MOVESPEEDELEPHANT;
		}
	}
}
