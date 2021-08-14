#pragma once
#include "singletonBase.h"
#include "image.h"

class imageManager : public singletonBase<imageManager>
{
private:
	//map���� ���� �̹��� ���� ���
	typedef map<string, image*> mapImageList;
	typedef map<string, image*>::iterator mapImageIter;

	mapImageList _mImageList;

public:
	HRESULT init(void);
	void release();

	//�̹��� �߰� (Ư�� ������ �������� ����)
	image* addImage(string strKey, int width, int height);

	//�̹��� �߰� (Ư�� ������ ������)
	image* addImage(string strKey, const char* fileName, int width, int height, BOOL isTrans = FALSE, COLORREF transColor = RGB(0, 0, 0));
	image* addImage(string strKey, const char* fileName, float x, float y, int width, int height, BOOL isTrans = FALSE, COLORREF transColor = RGB(0, 0, 0));

	//�̹��� �߰� (��������Ʈ ��Ʈ)
	image* addFrameImage(string strKey, const char* fileName, int width, int height, int maxFrameX, int maxFrameY, BOOL isTrans = FALSE, COLORREF transColor = RGB(0, 0, 0));
	image* addFrameImage(string strKey, const char* fileName, float x, float y, int width, int height, int maxFrameX, int maxFrameY, BOOL isTrans = FALSE, COLORREF transColor = RGB(0, 0, 0));


	//�̹����� key�� ã��
	image* findImage(string strKey);
	//�̹����� key�� ã�� �����ϱ�
	BOOL deleteImage(string strKey);
	//�̹��� ��ü ����
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

