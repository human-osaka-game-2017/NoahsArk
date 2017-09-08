#include"Sound.h"

LPDIRECTSOUND8      g_lpDS = NULL;            // DirectSound8
LPDIRECTSOUNDBUFFER g_lpSecondary = NULL;     // �Z�J���_���T�E���h�o�b�t�@
LPDIRECTSOUNDBUFFER g_lpSecondary2 = NULL;
LPDIRECTSOUNDBUFFER g_lpSecondary3 = NULL;
LPDIRECTSOUNDBUFFER g_lpSecondary4 = NULL;



int SoundInit(HWND hWnd)
{
	HRESULT ret;

	// DirectSound8���쐬
	ret = DirectSoundCreate8(NULL, &g_lpDS, NULL);
	if (FAILED(ret)) {
		return 0;
	}


	// �������x���̃Z�b�g�i�����ŉ���炷�E�B���h�E���w�肷��K�v������j
	if (FAILED(g_lpDS->SetCooperativeLevel(hWnd, DSSCL_PRIORITY)))
	{
		// ���s
		return 0;
	}

	return -1;
}

// �T�E���h�o�b�t�@�̍쐬

int CreateSoundBuffer(LPDIRECTSOUNDBUFFER *dsb, const char *file)
{
	HRESULT ret;
	MMCKINFO mSrcWaveFile;
	MMCKINFO mSrcWaveFmt;
	MMCKINFO mSrcWaveData;
	LPWAVEFORMATEX wf;

	// WAV�t�@�C�������[�h
	HMMIO hSrc;
	hSrc = mmioOpenA((LPSTR)file, NULL, MMIO_ALLOCBUF | MMIO_READ | MMIO_COMPAT);
	if (!hSrc) {
		return 0;
	}

	// 'WAVE'�`�����N�`�F�b�N
	ZeroMemory(&mSrcWaveFile, sizeof(mSrcWaveFile));
	ret = mmioDescend(hSrc, &mSrcWaveFile, NULL, MMIO_FINDRIFF);
	if (mSrcWaveFile.fccType != mmioFOURCC('W', 'A', 'V', 'E')) {
		mmioClose(hSrc, 0);
		return 0;
	}

	// 'fmt '�`�����N�`�F�b�N
	ZeroMemory(&mSrcWaveFmt, sizeof(mSrcWaveFmt));
	ret = mmioDescend(hSrc, &mSrcWaveFmt, &mSrcWaveFile, MMIO_FINDCHUNK);
	if (mSrcWaveFmt.ckid != mmioFOURCC('f', 'm', 't', ' ')) {
		mmioClose(hSrc, 0);
		return 0;
	}

	// �w�b�_�T�C�Y�̌v�Z
	int iSrcHeaderSize = mSrcWaveFmt.cksize;
	if (iSrcHeaderSize<sizeof(WAVEFORMATEX))
		iSrcHeaderSize = sizeof(WAVEFORMATEX);

	// �w�b�_�������m��
	wf = (LPWAVEFORMATEX)malloc(iSrcHeaderSize);
	if (!wf) {
		mmioClose(hSrc, 0);
		return 0;
	}
	ZeroMemory(wf, iSrcHeaderSize);

	// WAVE�t�H�[�}�b�g�̃��[�h
	ret = mmioRead(hSrc, (char*)wf, mSrcWaveFmt.cksize);
	if (FAILED(ret)) {
		free(wf);
		mmioClose(hSrc, 0);
		return 0;
	}


	// fmt�`�����N�ɖ߂�
	mmioAscend(hSrc, &mSrcWaveFmt, 0);

	// data�`�����N��T��
	while (1) {
		// ����
		ret = mmioDescend(hSrc, &mSrcWaveData, &mSrcWaveFile, 0);
		if (FAILED(ret)) {
			free(wf);
			mmioClose(hSrc, 0);
			return 0;
		}
		if (mSrcWaveData.ckid == mmioStringToFOURCCA("data", 0))
			break;
		// ���̃`�����N��
		ret = mmioAscend(hSrc, &mSrcWaveData, 0);
	}


	// �T�E���h�o�b�t�@�̍쐬
	DSBUFFERDESC dsdesc;
	ZeroMemory(&dsdesc, sizeof(DSBUFFERDESC));
	dsdesc.dwSize = sizeof(DSBUFFERDESC);
	dsdesc.dwFlags = DSBCAPS_GETCURRENTPOSITION2 | DSBCAPS_STATIC | DSBCAPS_LOCDEFER;
	dsdesc.dwBufferBytes = mSrcWaveData.cksize;
	dsdesc.lpwfxFormat = wf;
	dsdesc.guid3DAlgorithm = DS3DALG_DEFAULT;
	ret = g_lpDS->CreateSoundBuffer(&dsdesc, dsb, NULL);
	if (FAILED(ret)) {
		free(wf);
		mmioClose(hSrc, 0);
		return 0;
	}

	// ���b�N�J�n
	LPVOID pMem1, pMem2;
	DWORD dwSize1, dwSize2;
	ret = (*dsb)->Lock(0, mSrcWaveData.cksize, &pMem1, &dwSize1, &pMem2, &dwSize2, 0);
	if (FAILED(ret)) {
		free(wf);
		mmioClose(hSrc, 0);
		return 0;
	}

	// �f�[�^��������
	mmioRead(hSrc, (char*)pMem1, dwSize1);
	mmioRead(hSrc, (char*)pMem2, dwSize2);

	// ���b�N����
	(*dsb)->Unlock(pMem1, dwSize1, pMem2, dwSize2);

	// �w�b�_�p���������J��
	free(wf);

	// WAV�����
	mmioClose(hSrc, 0);

	return -1;
}

//���
int SoundRelease()
{
	if (g_lpSecondary) {
		g_lpSecondary->Release();
		g_lpSecondary = NULL;
	}

	if (g_lpSecondary2)
	{
		g_lpSecondary2->Release();
		g_lpSecondary2 = NULL;
	}

	if (g_lpSecondary3)
	{
		g_lpSecondary3->Release();
		g_lpSecondary3 = NULL;
	}

	if (g_lpDS) {
		g_lpDS->Release();
		g_lpDS = NULL;
	}

	// COM�̏I��
	CoUninitialize();

	return -1;
}
