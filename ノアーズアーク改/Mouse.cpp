#include "GameScene.h"
#include "Mouse.h"


// DirectInput�p��` 

LPDIRECTINPUTDEVICE8 pDIMouse = NULL;
LPDIRECTINPUT8 pDInput = NULL;
DIMOUSESTATE2 dIMouseState;

MOUSEKIND g_Mouse;

// DirectInput�̏������@�������� //////////////////////////////////////////////    

HRESULT InitDInputMouse(HWND hWnd)
{
	//DirectInput�I�u�W�F�N�g�쐬
	DirectInput8Create(GetModuleHandle(NULL), DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&pDInput, NULL);

	//DirectInput�f�o�C�X �I�u�W�F�N�g�쐬
	pDInput->CreateDevice(GUID_SysMouse, &pDIMouse, NULL);

	// �}�E�X�p�̃f�[�^�E�t�H�[�}�b�g��ݒ�
	pDIMouse->SetDataFormat(&c_dfDIMouse);

	// �펞�擾
	hWnd = FindWindow(WINDOW_TITLE, NULL);
	//�������x��
	pDIMouse->SetCooperativeLevel(hWnd, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND);

	// �f�o�C�X�̐ݒ�    
	DIPROPDWORD diprop;
	diprop.diph.dwSize = sizeof(diprop);
	diprop.diph.dwHeaderSize = sizeof(diprop.diph);
	diprop.diph.dwObj = 0;
	diprop.diph.dwHow = DIPH_DEVICE;
	diprop.dwData = DIPROPAXISMODE_REL; // ���Βl���[�h�Őݒ�i��Βl��DIPROPAXISMODE_ABS�j    
	pDIMouse->SetProperty(DIPROP_AXISMODE, &diprop.diph);

	// ���͐���J�n    
	pDIMouse->Acquire();
	// DirectInput�̏������@�����܂� //////////////////////////////////////////////////////

	// DirectInput�̍X�V�@�������� ////////////////////////////////////////////////////// 

	// �l�̏�����    
	dIMouseState.rgbButtons[0] = 0;

	// �l�̍X�V 
	if (FAILED(pDIMouse->GetDeviceState(sizeof(DIMOUSESTATE2), &dIMouseState)))
		pDIMouse->Acquire();
	return S_OK;
	
}
void MouseCheck(MOUSEKIND* Mouse)
{
	DIMOUSESTATE dims;
	pDIMouse->Acquire();
	HRESULT hr = pDIMouse->GetDeviceState(sizeof(DIMOUSESTATE), &dims);
	if (SUCCEEDED(hr))
	{
		if (dims.rgbButtons[0])
		{
			Mouse->LEFT_mouse = true;
		}
		else
		{
			Mouse->LEFT_mouse = false;
		}

		if (dims.rgbButtons[1])
		{
			Mouse->RIGHT_mouse = true;
		}
		else
		{
			Mouse->RIGHT_mouse = false;
		}

		if (dims.lX)
		{
			Mouse->dim_x = dims.lX;
		}

		if (dims.lY)
		{
			Mouse->dim_y = dims.lY;
		}

		if (dims.lZ)
		{
			Mouse->dim_z = dims.lZ;
		}
	}
}


void ReleaseDInput()
{
	if (pDInput != NULL)
	{
		pDInput->Release();
		pDInput = NULL;
	}
}




// DirectInput�̍X�V�@�����܂� //////////////////////////////////////////////////////



