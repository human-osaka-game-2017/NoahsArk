#include "tree.h"
#include "char.h"
#include "GameScene.h"
//木の位置
mob tree = { 0.f,0.f,true }; 
mob tree2 = { 0.f,0.f,true };

CUSTOMVERTEX drawtree[4];

CUSTOMVERTEX drawtree2[4];

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
		//位置と頂点情報を代入
		for (int i = 0; i < 4; i++)
		{
			drawtree2[i] = treevertex[i];
			drawtree2[i].x += tree2.x;
			drawtree2[i].y += tree2.y;
		}
	

}
void initStage1tree()
{
	mob tree1_1 = { 806.f,400.f,true };
	mob tree1_2 = { 1136.f,400.f,true };
	tree = tree1_1;
	tree2 = tree1_2;
}
void initStage2tree()
{
	mob tree3 = { 1000.f,400.f,true }; //ステージ
	tree = tree3;
	mob tree4 = { 1250.f,400.f,true }; //ステージ
	tree2 = tree4;
}

void initStage3tree()
{
	mob tree5 = { 702.f,400.f,true }; //ステージ
	tree = tree5;
}
void initStage4tree()
{
	mob tree6 = { 780.f,400.f,true }; //ステージ
	tree = tree6;
}
void initStage5tree()
{
	mob tree7 = { 1750.f,400.f,true }; //ステージ6
	tree = tree7;
}
void initStage6tree()
{
	mob tree8 = { 890.f,400.f,true };
	tree = tree8;
}
void initStage7tree()
{
	mob tree9 = { 1600.f,400.f,true }; //ステージ6
	tree = tree9;
}