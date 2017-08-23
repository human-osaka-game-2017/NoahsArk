#include "elephant.h"
#include "tree.h"
#include "char.h"
#include "GameScene.h"
#include "Control.h"
#include "hole.h"
//ゾウの初期位置の設定
Animal elephant = { 112.f,395.f,false,true };//ステージ1
Animal elephant2 = { 90.f,395.f,false,true };//ステージ2、ステージ6
Animal elephant3 = { 60.f,395.f,false,true };//ステージ3
Animal elephant4 = { 65.f,395.f,false,true };//ステージ4
Animal elephant5 = { 900.f,395.f,false,true };//ステージ7

CUSTOMVERTEX drawelephant[4];
CUSTOMVERTEX drawelephant2[4];
CUSTOMVERTEX drawelephant3[4];
CUSTOMVERTEX drawelephant4[4];
CUSTOMVERTEX drawelephant5[4];

//ゾウが動いていていたらtrue
bool g_Moveelephant = true;
//ゾウが生きているか死んでいるか
bool ElephantDeadFlg = false;

void elephantdraw(int time)
{
	//ゾウの頂点情報
	CUSTOMVERTEX  elephantvertex[4]
	{
		{ -ELEPHANT_W / 2, -ELEPHANT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{  ELEPHANT_W / 2, -ELEPHANT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{  ELEPHANT_W / 2,  ELEPHANT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -ELEPHANT_W / 2,  ELEPHANT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	//位置と頂点情報を代入
	for (int i = 0; i < 4; i++)
	{
		drawelephant[i] = elephantvertex[i];
		drawelephant[i].x += elephant.x;
		drawelephant[i].y += elephant.y;
	}
	//ゾウの頂点情報
	CUSTOMVERTEX  elephantvertex2[4]
	{
		{ -ELEPHANT_W / 2, -ELEPHANT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ ELEPHANT_W / 2, -ELEPHANT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ ELEPHANT_W / 2,  ELEPHANT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -ELEPHANT_W / 2,  ELEPHANT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	//位置と頂点情報を代入
	for (int i = 0; i < 4; i++)
	{
		drawelephant2[i] = elephantvertex2[i];
		drawelephant2[i].x += elephant2.x;
		drawelephant2[i].y += elephant2.y;
	}
	//ゾウの頂点情報
	CUSTOMVERTEX  elephantvertex3[4]
	{
		{ -ELEPHANT_W / 2, -ELEPHANT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ ELEPHANT_W / 2, -ELEPHANT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ ELEPHANT_W / 2,  ELEPHANT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -ELEPHANT_W / 2,  ELEPHANT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	//位置と頂点情報を代入
	for (int i = 0; i < 4; i++)
	{
		drawelephant3[i] = elephantvertex3[i];
		drawelephant3[i].x += elephant3.x;
		drawelephant3[i].y += elephant3.y;
	}
	//ゾウの頂点情報
	CUSTOMVERTEX  elephantvertex4[4]
	{
		{ -ELEPHANT_W / 2, -ELEPHANT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ ELEPHANT_W / 2, -ELEPHANT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ ELEPHANT_W / 2,  ELEPHANT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -ELEPHANT_W / 2,  ELEPHANT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	//位置と頂点情報を代入
	for (int i = 0; i < 4; i++)
	{
		drawelephant4[i] = elephantvertex4[i];
		drawelephant4[i].x += elephant4.x;
		drawelephant4[i].y += elephant4.y;
	}
	//ゾウの頂点情報
	CUSTOMVERTEX  elephantvertex5[4]
	{
		{ -ELEPHANT_W / 2, -ELEPHANT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ ELEPHANT_W / 2, -ELEPHANT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ ELEPHANT_W / 2,  ELEPHANT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -ELEPHANT_W / 2,  ELEPHANT_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	//位置と頂点情報を代入
	for (int i = 0; i < 4; i++)
	{
		drawelephant5[i] = elephantvertex5[i];
		drawelephant5[i].x += elephant5.x;
		drawelephant5[i].y += elephant5.y;
	}
	if (g_Moveelephant && time > 3000)
	{
		elephant.x += MOVESPEEDELEPHANT;
	}
	//もしゾウが木の左に当たっていたら
	if (elephant.x >= tree.x - TREE_W)
	{
		//木を消す
		tree.Active = false;
	}

	//もしゾウが木の左に当たっていたら
	if (elephant.x >= tree2.x - TREE_W)
	{
		//木を消す
		tree2.Active = false;
	}
	//もしゾウが穴の左に当たっていたら
	if (elephant.x >= hole.x - HOLE_W)
	{
		//穴を消す
		hole.Active = false;
	}

	//もしライオンデットフラグがたっていたら中に入る
	if (ElephantDeadFlg)
	{
		static float angle = 15.f;
		g_Moveelephant = false;

		angle += 15.f;
		if (angle >= 180)
		{
			angle = 180.f;
		}
		//関数呼び出し
		Kaiten(-angle, elephantvertex, drawelephant);

		for (int i = 0; i < 4; i++)
		{
			//elephant.x -= DEADMOVESPEED_W;
			//elephant.y -= DEADMOVESPEED_H;
			drawelephant[i].x += elephant.x;
			drawelephant[i].y += elephant.y;
		}
	}


	for (int i = 0; i < 4; i++)
	{
		//ゴール判定
		//ゾウのｘがふねのxより大きかったら中に入る
		if (elephant.x >= ship[i].x)
		{
			elephant.y -= 0.1f;
			elephant.Clear = true;
		}
		//クリア判定
 		if (elephant.Clear)
		{
			//ゾウのｘがふねのxに100足した数よりおおきかったら中に入る
			if (elephant.x >= ship[i].x + 100)
			{
				elephant.Active = false;
			}
		}
	}
}