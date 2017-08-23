#include "tree.h"
#include "char.h"
#include "GameScene.h"
//木の位置
mob tree = { 806.f,400.f,true }; //ステージ1
mob tree2 = { 1136.f,400.f,true }; //ステージ1
mob tree3 = { 1000.f,400.f,true }; //ステージ2
mob tree4 = { 1250.f,400.f,true }; //ステージ2
mob tree5 = { 702.f,400.f,true }; //ステージ3
mob tree6 = { 780.f,400.f,true }; //ステージ4
mob tree7 = { 890.f,400.f,true }; //ステージ6
								  //一つ目
CUSTOMVERTEX drawtree[4];
CUSTOMVERTEX drawtree2[4];
CUSTOMVERTEX drawtree3[4];
CUSTOMVERTEX drawtree4[4];
CUSTOMVERTEX drawtree5[4];
CUSTOMVERTEX drawtree6[4];
CUSTOMVERTEX drawtree7[4];

void treedraw()
{
		//	木の頂点情報
		CUSTOMVERTEX  treevertex[4]
		{
			{ -TREE_W / 2, -TREE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
			{ TREE_W / 2, -TREE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
			{ TREE_W / 2,  TREE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
			{ -TREE_W / 2,  TREE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
		};
		//位置と頂点情報を代入
		for (int i = 0; i < 4; i++)
		{
			drawtree[i] = treevertex[i];
			drawtree[i].x += tree.x;
			drawtree[i].y += tree.y;
		}
		//	木の頂点情報
	CUSTOMVERTEX  treevertex2[4]
	{
		{ -TREE_W / 2, -TREE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ TREE_W / 2, -TREE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ TREE_W / 2,  TREE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -TREE_W / 2,  TREE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	//位置と頂点情報を代入
	for (int i = 0; i < 4; i++)
	{
		drawtree2[i] = treevertex2[i];
		drawtree2[i].x += tree2.x;
		drawtree2[i].y += tree2.y;
	}
	//	木の頂点情報
	CUSTOMVERTEX  treevertex3[4]
	{
		{ -TREE_W / 2, -TREE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ TREE_W / 2, -TREE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ TREE_W / 2,  TREE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -TREE_W / 2,  TREE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	//位置と頂点情報を代入
	for (int i = 0; i < 4; i++)
	{
		drawtree3[i] = treevertex3[i];
		drawtree3[i].x += tree3.x;
		drawtree3[i].y += tree3.y;
	}
	//	木の頂点情報
	CUSTOMVERTEX  treevertex4[4]
	{
		{ -TREE_W / 2, -TREE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ TREE_W / 2, -TREE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ TREE_W / 2,  TREE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -TREE_W / 2,  TREE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	//位置と頂点情報を代入
	for (int i = 0; i < 4; i++)
	{
		drawtree4[i] = treevertex4[i];
		drawtree4[i].x += tree4.x;
		drawtree4[i].y += tree4.y;
	}
	//	木の頂点情報
	CUSTOMVERTEX  treevertex5[4]
	{
		{ -TREE_W / 2, -TREE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ TREE_W / 2, -TREE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ TREE_W / 2,  TREE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -TREE_W / 2,  TREE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	//位置と頂点情報を代入
	for (int i = 0; i < 4; i++)
	{
		drawtree5[i] = treevertex5[i];
		drawtree5[i].x += tree5.x;
		drawtree5[i].y += tree5.y;
	}
	//	木の頂点情報
	CUSTOMVERTEX  treevertex6[4]
	{
		{ -TREE_W / 2, -TREE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ TREE_W / 2, -TREE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ TREE_W / 2,  TREE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -TREE_W / 2,  TREE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	//位置と頂点情報を代入
	for (int i = 0; i < 4; i++)
	{
		drawtree6[i] = treevertex6[i];
		drawtree6[i].x += tree6.x;
		drawtree6[i].y += tree6.y;
	}
	//	木の頂点情報
	CUSTOMVERTEX  treevertex7[4]
	{
		{ -TREE_W / 2, -TREE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ TREE_W / 2, -TREE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ TREE_W / 2,  TREE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -TREE_W / 2,  TREE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	//位置と頂点情報を代入
	for (int i = 0; i < 4; i++)
	{
		drawtree7[i] = treevertex7[i];
		drawtree7[i].x += tree7.x;
		drawtree7[i].y += tree7.y;
	}

}