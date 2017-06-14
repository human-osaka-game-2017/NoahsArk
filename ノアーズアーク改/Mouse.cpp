#include "GameScene.h"
#include "Mouse.h"


// DirectInput用定義 

LPDIRECTINPUTDEVICE8 pDIMouse = NULL;
LPDIRECTINPUT8 pDInput = NULL;
DIMOUSESTATE2 dIMouseState;

MOUSEKIND g_Mouse;

// DirectInputの初期化　ここから //////////////////////////////////////////////    

HRESULT InitDInputMouse(HWND hWnd)
{
	//DirectInputオブジェクト作成
	DirectInput8Create(GetModuleHandle(NULL), DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&pDInput, NULL);

	//DirectInputデバイス オブジェクト作成
	pDInput->CreateDevice(GUID_SysMouse, &pDIMouse, NULL);

	// マウス用のデータ・フォーマットを設定
	pDIMouse->SetDataFormat(&c_dfDIMouse);

	// 常時取得
	hWnd = FindWindow(WINDOW_TITLE, NULL);
	//協調レベル
	pDIMouse->SetCooperativeLevel(hWnd, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND);

	// デバイスの設定    
	DIPROPDWORD diprop;
	diprop.diph.dwSize = sizeof(diprop);
	diprop.diph.dwHeaderSize = sizeof(diprop.diph);
	diprop.diph.dwObj = 0;
	diprop.diph.dwHow = DIPH_DEVICE;
	diprop.dwData = DIPROPAXISMODE_REL; // 相対値モードで設定（絶対値はDIPROPAXISMODE_ABS）    
	pDIMouse->SetProperty(DIPROP_AXISMODE, &diprop.diph);

	// 入力制御開始    
	pDIMouse->Acquire();
	// DirectInputの初期化　ここまで //////////////////////////////////////////////////////

	// DirectInputの更新　ここから ////////////////////////////////////////////////////// 

	// 値の初期化    
	dIMouseState.rgbButtons[0] = 0;

	// 値の更新 
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




// DirectInputの更新　ここまで //////////////////////////////////////////////////////



