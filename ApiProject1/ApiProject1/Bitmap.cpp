#include "Bitmap.h"

Bitmap* Bitmap::LoadBmp(LPCWSTR _FileName)
{
    hdc = GetDC(g_hWnd);
    MemDC = CreateCompatibleDC(hdc);

	hBitmap = (HBITMAP)LoadImage(NULL,
		_FileName, IMAGE_BITMAP, 0, 0,
		LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	OldBitmap = (HBITMAP)SelectObject(MemDC, hBitmap);

	ReleaseDC(g_hWnd, hdc);

	return this;
}

void Bitmap::Release()
{
	SelectObject(MemDC, OldBitmap);
	DeleteObject(hBitmap);
	ReleaseDC(g_hWnd, MemDC);
}

Bitmap::Bitmap()
{
}

Bitmap::~Bitmap()
{
    Release();
}