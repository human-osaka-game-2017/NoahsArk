#include "tree.h"
#include "char.h"
#include "GameScene.h"
//�؂̈ʒu
mob tree = { 700.f,400.f,true }; //��

CUSTOMVERTEX drawtree[4];

void treedraw()
{
	//	�؂̒��_���
	CUSTOMVERTEX  treevertex[4]
	{
		{ -TREE_W / 2, -TREE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ TREE_W / 2, -TREE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ TREE_W / 2,  TREE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ -TREE_W / 2,  TREE_H / 2, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	//�ʒu�ƒ��_������
	for (int i = 0; i < 4; i++)
	{
		drawtree[i] = treevertex[i];
		drawtree[i].x += tree.x;
		drawtree[i].y += tree.y;
	}
}