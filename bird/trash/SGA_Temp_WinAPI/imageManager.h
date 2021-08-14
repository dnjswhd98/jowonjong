#pragma once
#include "singletonBase.h"
#include "image.h"

class imageManager : public singletonBase<imageManager>
{
private:
	//map으로 만든 이미지 정보 목록
	typedef map<string, image*> mapImageList;
	typedef map<string, image*>::iterator mapImageIter;

	mapImageList _mImageList;

public:
	HRESULT init(void);
	void release();

	//이미지 추가 (특정 색상을 삭제하지 않음)
	image* addImage(string strKey, int width, int height);

	//이미지 추가 (특정 색상을 삭제함)
	image* addImage(string strKey, const char* fileName, int width, int height, BOOL isTrans = FALSE, COLORREF transColor = RGB(0, 0, 0));
	image* addImage(string strKey, const char* fileName, float x, float y, int width, int height, BOOL isTrans = FALSE, COLORREF transColor = RGB(0, 0, 0));

	//이미지 추가 (스프라이트 시트)
	image* addFrameImage(string strKey, const char* fileName, int width, int height, int maxFrameX, int maxFrameY, BOOL isTrans = FALSE, COLORREF transColor = RGB(0, 0, 0));
	image* addFrameImage(string strKey, const char* fileName, float x, float y, int width, int height, int maxFrameX, int maxFrameY, BOOL isTrans = FALSE, COLORREF transColor = RGB(0, 0, 0));


	//이미지를 key로 찾기
	image* findImage(string strKey);
	//이미지를 key로 찾고 삭제하기
	BOOL deleteImage(string strKey);
	//이미지 전체 삭제
	BOOL deleteAll();


	//Render
	void render(string strKey, HDC hdc);
	void render(string strKey, HDC hdc, int destX, int destY);
	void render(string strKey, HDC hdc, int destX, int destY,
		int sourceX, int sourceY, int sourceWidth, int sourceHeight);

	//Alpha Render
	void alphaRender(string strKey, HDC hdc, BYTE alpha);
	void alphaRender(string strKey, HDC hdc, int destX, int destY, BYTE alpha);

	//loop Render
	void loopRender(string strKey, HDC hdc, const LPRECT drawArea, int offsetX, int offsetY);

	//frame Render
	void frameRender(string strKey, HDC hdc, int destX, int destY);
	void frameRender(string strKey, HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY);

	imageManager() {}
	~imageManager() {}
};

