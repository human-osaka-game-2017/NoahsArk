#ifndef SOUND_H__
#define SOUND_H__
#include <dsound.h>
#include <windows.h>

#pragma comment(lib, "dsound.lib") 
#pragma comment(lib, "d3dxof.lib")
#pragma comment(lib, "dxguid.lib")


int SoundInit(HWND hWnd);
int CreateSoundBuffer(LPDIRECTSOUNDBUFFER *dsb, const char *file);
int SoundRelease();





#endif