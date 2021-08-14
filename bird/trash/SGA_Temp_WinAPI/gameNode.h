#pragma once
#include "image.h"

//백버퍼 이미지
static image* _backBuffer = IMAGEMANAGER->addImage("backBuffer", WINSIZE_X, WINSIZE_Y);

class gameNode
{
private:
	HDC _hdc;
	bool _managerInit;

public:

	virtual HRESULT init();
	virtual HRESULT init(bool managerInit);

	virtual void release();
	virtual void update();
	virtual void render();

	//백버퍼 이미지 받아오기
	image* getBackBuffer(void) { return _backBuffer; }
	//메모리 DC 받아오기
	HDC getMemDC() { return _backBuffer->getMemDC(); }
	//HDC 받아오기
	HDC getHDC() { return _hdc; }

	LRESULT MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);

	gameNode() {}
	~gameNode() {}
};

