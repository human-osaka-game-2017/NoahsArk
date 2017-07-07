#ifndef GAMESCENE
#define GAMESCENE

#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1)
#define WINDOW_TITLE TEXT("�m�A�[�Y�E�A�[�N")	// �E�B���h�E��

#include <windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <stdio.h>

struct CUSTOMVERTEX
{
	FLOAT	x, y, z, rhw;
	DWORD	color;
	FLOAT	tu, tv;
};

enum GAME_TEXTURE
{
	BACKGROUND_TEX,
    SHIP_TEX,
	GAMEOVER_TEX,
	GAMECLEAR_TEX,
	LION_TEX,
	ELEPHANT_TEX,
	TREE_TEX,
	ALLIGATOR_TEX,
	//CHESTNUT
	KUSA_TEX,
	GAMESCENE_MAX
};
// �Q�[���V�[���̕`��֐�
void GameSceneDraw(int time);

// �Q�[���V�[���̏������֐�
void GameSceneInit();

// �Q�[���V�[���̉���֐�
void GameSceneFree();

extern CUSTOMVERTEX  ship[4];

extern LPDIRECT3D9			g_pDirect3D;		// DirectX�I�u�W�F�N�g�̃|�C���^
extern LPDIRECT3DDEVICE9	g_pDirect3DDevice;	// DirectX�f�o�C�X�̃|�C���^
#endif 

