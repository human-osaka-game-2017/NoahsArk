#include"Sound.h"

LPDIRECTSOUND8      g_lpDS = NULL;            // DirectSound8
LPDIRECTSOUNDBUFFER g_lpSecondary = NULL;     // セカンダリサウンドバッファ
LPDIRECTSOUNDBUFFER g_lpSecondary2 = NULL;
LPDIRECTSOUNDBUFFER g_lpSecondary3 = NULL;
LPDIRECTSOUNDBUFFER g_lpSecondary4 = NULL;



int SoundInit(HWND hWnd)
{
	HRESULT ret;

	// DirectSound8を作成
	ret = DirectSoundCreate8(NULL, &g_lpDS, NULL);
	if (FAILED(ret)) {
		return 0;
	}


	// 協調レベルのセット（ここで音を鳴らすウィンドウを指定する必要がある）
	if (FAILED(g_lpDS->SetCooperativeLevel(hWnd, DSSCL_PRIORITY)))
	{
		// 失敗
		return 0;
	}

	return -1;
}

// サウンドバッファの作成

int CreateSoundBuffer(LPDIRECTSOUNDBUFFER *dsb, const char *file)
{
	HRESULT ret;
	MMCKINFO mSrcWaveFile;
	MMCKINFO mSrcWaveFmt;
	MMCKINFO mSrcWaveData;
	LPWAVEFORMATEX wf;

	// WAVファイルをロード
	HMMIO hSrc;
	hSrc = mmioOpenA((LPSTR)file, NULL, MMIO_ALLOCBUF | MMIO_READ | MMIO_COMPAT);
	if (!hSrc) {
		return 0;
	}

	// 'WAVE'チャンクチェック
	ZeroMemory(&mSrcWaveFile, sizeof(mSrcWaveFile));
	ret = mmioDescend(hSrc, &mSrcWaveFile, NULL, MMIO_FINDRIFF);
	if (mSrcWaveFile.fccType != mmioFOURCC('W', 'A', 'V', 'E')) {
		mmioClose(hSrc, 0);
		return 0;
	}

	// 'fmt 'チャンクチェック
	ZeroMemory(&mSrcWaveFmt, sizeof(mSrcWaveFmt));
	ret = mmioDescend(hSrc, &mSrcWaveFmt, &mSrcWaveFile, MMIO_FINDCHUNK);
	if (mSrcWaveFmt.ckid != mmioFOURCC('f', 'm', 't', ' ')) {
		mmioClose(hSrc, 0);
		return 0;
	}

	// ヘッダサイズの計算
	int iSrcHeaderSize = mSrcWaveFmt.cksize;
	if (iSrcHeaderSize<sizeof(WAVEFORMATEX))
		iSrcHeaderSize = sizeof(WAVEFORMATEX);

	// ヘッダメモリ確保
	wf = (LPWAVEFORMATEX)malloc(iSrcHeaderSize);
	if (!wf) {
		mmioClose(hSrc, 0);
		return 0;
	}
	ZeroMemory(wf, iSrcHeaderSize);

	// WAVEフォーマットのロード
	ret = mmioRead(hSrc, (char*)wf, mSrcWaveFmt.cksize);
	if (FAILED(ret)) {
		free(wf);
		mmioClose(hSrc, 0);
		return 0;
	}


	// fmtチャンクに戻る
	mmioAscend(hSrc, &mSrcWaveFmt, 0);

	// dataチャンクを探す
	while (1) {
		// 検索
		ret = mmioDescend(hSrc, &mSrcWaveData, &mSrcWaveFile, 0);
		if (FAILED(ret)) {
			free(wf);
			mmioClose(hSrc, 0);
			return 0;
		}
		if (mSrcWaveData.ckid == mmioStringToFOURCCA("data", 0))
			break;
		// 次のチャンクへ
		ret = mmioAscend(hSrc, &mSrcWaveData, 0);
	}


	// サウンドバッファの作成
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

	// ロック開始
	LPVOID pMem1, pMem2;
	DWORD dwSize1, dwSize2;
	ret = (*dsb)->Lock(0, mSrcWaveData.cksize, &pMem1, &dwSize1, &pMem2, &dwSize2, 0);
	if (FAILED(ret)) {
		free(wf);
		mmioClose(hSrc, 0);
		return 0;
	}

	// データ書き込み
	mmioRead(hSrc, (char*)pMem1, dwSize1);
	mmioRead(hSrc, (char*)pMem2, dwSize2);

	// ロック解除
	(*dsb)->Unlock(pMem1, dwSize1, pMem2, dwSize2);

	// ヘッダ用メモリを開放
	free(wf);

	// WAVを閉じる
	mmioClose(hSrc, 0);

	return -1;
}

//解放
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

	// COMの終了
	CoUninitialize();

	return -1;
}
