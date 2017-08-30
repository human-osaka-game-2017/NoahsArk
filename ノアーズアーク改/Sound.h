#ifndef SOUND_H__
#define SOUND_H__
#include <dsound.h>
#include <windows.h>

int SoundInit(HWND hWnd);
int CreateSoundBuffer(LPDIRECTSOUNDBUFFER *dsb, const char *file);
int SoundRelease();

#endif