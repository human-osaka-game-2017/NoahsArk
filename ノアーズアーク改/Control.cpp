#include "Mouse.h"
#include "GameScene.h"
#include "char.h"
#include "Control.h"

bool DeadFlg = false;

Animal elephant = { 300.f,500.f,false };//ゾウ

Animal lion = { 200.f,500.f,false };;  //ライオン

mob alligator = { 1000.f,500.f,false };   //ワニ(障害物)

mob tree = { 700.f,500.f,false }; //木

//mob chestnut = { 900.f,500.f,false };//栗


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

		////ゾウ(まだ画像の中を押さなくてもゲーム画面のどこかを押したら止まる）
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

//左から右に流れるときのｘのあたり判定
void Cllide()
{
	//もしライオンがうごいていたら
	if (g_MoveLion)
	{
		//当たっているかの判定
		if (tree.x - TREE_W  < lion.x)
		{
			DeadFlg = true;
		}
			
	}
	//もしゾウがうごいていたら
	if (g_Moveelephant)
	{
		//当たっているかの判定
		if (alligator.x - ALLIGATOR_W< elephant.x)
		{
			//当たっていたら、当たった位置で止まる
			elephant.x -= MOVESPEEDELEPHANT;
		}
	}
}
void Kaiten(float kakudo, CUSTOMVERTEX src[], CUSTOMVERTEX dest[])
{
	float cx, cy;
	float rad;

	rad = D3DXToRadian(kakudo);

	cx = (src[0].x + src[1].x) / 2.0f;
	cy = (src[0].y + src[3].y) / 2.0f;
	for (int i = 0; i < 4; i++) {
		src[i].x -= cx;
		src[i].y -= cy;
			dest[i] = src[i];
			dest[i].x = src[i].x * cos(rad)
				- src[i].y * sin(rad);
			dest[i].y = src[i].x * sin(rad)
				+ src[i].y * cos(rad);
			src[i].x += cx;
			src[i].y += cy;
			dest[i].x += cx;
			dest[i].y += cy;
	}
}