#include "setDefine.h"
#include "image.h"

//AlphaBlend�� ����ϱ� ���� ���̺귯�� �߰�
#pragma comment (lib, "msimg32.lib")

image::image()
	: _imageInfo(NULL), _fileName(NULL), _isTrans(FALSE), _transColor(RGB(0,0,0))
{
}

image::~image()
{
}

HRESULT image::init(int width, int height)
{
	//���ʱ�ȭ ����(���� �̹��� ������ ������ ������ ��� �켱 release())
	if (_imageInfo != NULL) this->release();

	//DC �ҷ�����
	HDC hdc = GetDC(_hWnd);

	//�̹��� ���� �ʱ�ȭ
	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_EMPTY;
	_imageInfo->resID = 0;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);
	_imageInfo->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, width, height);
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->width = width;
	_imageInfo->height = height;

	//���� �̸�
	_fileName = NULL;

	//������ ��� ������ ���� ����
	_isTrans = FALSE;
	_transColor = RGB(0, 0, 0);
	
	//���� ���ҽ��� �о���⿡ �������� ���
	if (_imageInfo->hBit == 0)
	{
		this->release();
		return E_FAIL;
	}

	//�������� ���ҽ� �ҷ����⿡ �������� ���
	ReleaseDC(_hWnd, hdc);
	return S_OK;
}

HRESULT image::init(const DWORD resID, int width, int height, BOOL isTrans, COLORREF transColor)
{
	//���ʱ�ȭ ����(���� �̹��� ������ ������ ������ ��� �켱 release())
	if (_imageInfo != NULL) this->release();

	//DC �ҷ�����
	HDC hdc = GetDC(_hWnd);

	//�̹��� ���� �ʱ�ȭ
	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_EMPTY;
	_imageInfo->resID = resID;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);
	_imageInfo->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, width, height);
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->width = width;
	_imageInfo->height = height;

	//���� �̸�
	_fileName = NULL;

	//������ ��� ������ ���� ����
	_isTrans = FALSE;
	_transColor = RGB(0, 0, 0);

	//���� ���ҽ��� �о���⿡ �������� ���
	if (_imageInfo->hBit == 0)
	{
		this->release();
		return E_FAIL;
	}

	//�������� ���ҽ� �ҷ����⿡ �������� ���
	ReleaseDC(_hWnd, hdc);
	return S_OK;
}

HRESULT image::init(const char * fileName, int width, int height, BOOL isTrans, COLORREF transColor)
{
	//���ʱ�ȭ ����(���� �̹��� ������ ������ ������ ��� �켱 release())
	if (_imageInfo != NULL) this->release();

	//DC �ҷ�����
	HDC hdc = GetDC(_hWnd);

	//�̹��� ���� �ʱ�ȭ
	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_EMPTY;
	_imageInfo->resID = 0;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);
	_imageInfo->hBit = (HBITMAP)LoadImage(_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->width = width;
	_imageInfo->height = height;

	//���� �̸�
	int len = strlen(fileName);
	_fileName = new CHAR[len + 1];
	strcpy_s(_fileName, len + 1, fileName);

	//������ ��� ������ ���� ����
	_isTrans = isTrans;
	_transColor = transColor;

	//���� ���ҽ��� �о���⿡ �������� ���
	if (_imageInfo->hBit == 0)
	{
		this->release();
		return E_FAIL;
	}

	//�������� ���ҽ� �ҷ����⿡ �������� ���
	ReleaseDC(_hWnd, hdc);
	return S_OK;
}

HRESULT image::init(const char * fileName, float x, float y, int width, int height, BOOL isTrans, COLORREF transColor)
{
	//���ʱ�ȭ ����(���� �̹��� ������ ������ ������ ��� �켱 release())
	if (_imageInfo != NULL) this->release();

	//DC �ҷ�����
	HDC hdc = GetDC(_hWnd);

	//�̹��� ���� �ʱ�ȭ
	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_FILE;
	_imageInfo->resID = 0;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);
	_imageInfo->hBit = (HBITMAP)LoadImage(_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->x = x;
	_imageInfo->y = y;
	_imageInfo->width = width;
	_imageInfo->height = height;

	//���� �̸�
	int len = strlen(fileName);
	_fileName = new CHAR[len + 1];
	strcpy_s(_fileName, len + 1, fileName);

	//������ ��� ������ ���� ����
	_isTrans = isTrans;
	_transColor = transColor;

	//���� ���ҽ��� �о���⿡ �������� ���
	if (_imageInfo->hBit == 0)
	{
		this->release();
		return E_FAIL;
	}

	//�������� ���ҽ� �ҷ����⿡ �������� ���
	ReleaseDC(_hWnd, hdc);
	return S_OK;

}

HRESULT image::init(const char * fileName, int width, int height, int maxFrameX, int maxFrameY, BOOL isTrans, COLORREF transColor)
{
	//���ʱ�ȭ ����(���� �̹��� ������ ������ ������ ��� �켱 release())
	if (_imageInfo != NULL) this->release();

	//DC �ҷ�����
	HDC hdc = GetDC(_hWnd);

	//�̹��� ���� �ʱ�ȭ
	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_FILE;
	_imageInfo->resID = 0;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);
	_imageInfo->hBit = (HBITMAP)LoadImage(_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->width = width;
	_imageInfo->height = height;
	_imageInfo->currentFrameX = 0;
	_imageInfo->currentFrameY = 0;
	_imageInfo->maxFrameX = maxFrameX - 1;
	_imageInfo->maxFrameY = maxFrameY - 1;
	_imageInfo->frameWidth = width / maxFrameX;
	_imageInfo->frameHeight = height / maxFrameY;

	//���� �̸�
	int len = strlen(fileName);
	_fileName = new CHAR[len + 1];
	strcpy_s(_fileName, len + 1, fileName);

	//������ ��� ������ ���� ����
	_isTrans = isTrans;
	_transColor = transColor;

	//���� ���ҽ��� �о���⿡ �������� ���
	if (_imageInfo->hBit == 0)
	{
		this->release();
		return E_FAIL;
	}

	//�������� ���ҽ� �ҷ����⿡ �������� ���
	ReleaseDC(_hWnd, hdc);
	return S_OK;

}

HRESULT image::init(const char * fileName, float x, float y, int width, int height, int maxFrameX, int maxFrameY, BOOL isTrans, COLORREF transColor)
{
	//���ʱ�ȭ ����(���� �̹��� ������ ������ ������ ��� �켱 release())
	if (_imageInfo != NULL) this->release();

	//DC �ҷ�����
	HDC hdc = GetDC(_hWnd);

	//�̹��� ���� �ʱ�ȭ
	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_FILE;
	_imageInfo->resID = 0;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);
	_imageInfo->hBit = (HBITMAP)LoadImage(_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->x = x;
	_imageInfo->y = y;
	_imageInfo->width = width;
	_imageInfo->height = height;
	_imageInfo->currentFrameX = 0;
	_imageInfo->currentFrameY = 0;
	_imageInfo->maxFrameX = maxFrameX - 1;
	_imageInfo->maxFrameY = maxFrameY - 1;
	_imageInfo->frameWidth = width / maxFrameX;
	_imageInfo->frameHeight = height / maxFrameY;

	//���� �̸�
	int len = strlen(fileName);
	_fileName = new CHAR[len + 1];
	strcpy_s(_fileName, len + 1, fileName);

	//������ ��� ������ ���� ����
	_isTrans = isTrans;
	_transColor = transColor;

	//���� ���ҽ��� �о���⿡ �������� ���
	if (_imageInfo->hBit == 0)
	{
		this->release();
		return E_FAIL;
	}

	//�������� ���ҽ� �ҷ����⿡ �������� ���
	ReleaseDC(_hWnd, hdc);
	return S_OK;


}

HRESULT image::initAlphaBlend(void)
{
	HDC hdc = GetDC(_hWnd);

	//���ĺ��� �ɼ� ����
	_blendFunc.BlendFlags = 0;
	_blendFunc.AlphaFormat = 0;
	_blendFunc.BlendOp = AC_SRC_OVER;

	//���İ��� ����� �̹����� ���� ����
	_blendImage = new IMAGE_INFO;
	_blendImage->loadType = LOAD_FILE;
	_blendImage->resID = 0;
	_blendImage->hMemDC = CreateCompatibleDC(hdc);
	_blendImage->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, _imageInfo->width, _imageInfo->height);
	_blendImage->hOBit = (HBITMAP)SelectObject(_blendImage->hMemDC, _blendImage->hBit);
	_blendImage->width = WINSIZE_X;
	_blendImage->height = WINSIZE_Y;

	//DC ����
	ReleaseDC(_hWnd, hdc);

	return S_OK;
}

void image::setTransColor(BOOL isTrans, COLORREF transColor)
{
	_isTrans = isTrans;
	_transColor = transColor;
}

void image::release()
{
	//�̹��� ������ �������� ��� �޸𸮿��� ����
	if (_imageInfo)
	{
		//DC ����
		SelectObject(_imageInfo->hMemDC, _imageInfo->hOBit);
		DeleteObject(_imageInfo->hBit);
		DeleteDC(_imageInfo->hMemDC);

		//��ü ����
		SAFE_DELETE(_imageInfo);
		SAFE_DELETE_ARRAY(_fileName);

		//��Ÿ ���� �ʱ�ȭ
		_isTrans = FALSE;
		_transColor = RGB(0, 0, 0);
	}
}

void image::render(HDC hdc)
{
	if (_isTrans)
	{
		//GdiTransparentBlt : ��Ʈ�� �̹����� �ҷ��� �� Ư�� ������ �����ϰ� �������ִ� �Լ�
		GdiTransparentBlt
		(
			hdc,											//������ ����� DC (ȭ�鿡 ��µǴ� DC)
			0,												//����� ����� ���� X��ǥ
			0,												//����� ����� ���� Y��ǥ
			_imageInfo->width,				//����� �̹����� ���� ũ��
			_imageInfo->height,			//����� �̹����� ���� ũ��
			_imageInfo->hMemDC,		//����� �̹����� DC
			0,												//���� ���� (X)
			0,												//���� ���� (Y)
			_imageInfo->width,				//���� ������ ���� ũ��
			_imageInfo->height,			//���� ������ ���� ũ��
			_transColor							//������ �� ������ ���� ����
		);
	}
	else
	{
		//BitBlt : DC ���� �������� ���� ��Ӻ��縦 ���ִ� �Լ�
		BitBlt(hdc, 0, 0, _imageInfo->width, _imageInfo->height, _imageInfo->hMemDC, 0, 0, SRCCOPY);
	}
}

void image::render(HDC hdc, int destX, int destY)
{
	if (_isTrans)
	{
		//GdiTransparentBlt : ��Ʈ�� �̹����� �ҷ��� �� Ư�� ������ �����ϰ� �������ִ� �Լ�
		GdiTransparentBlt
		(
			hdc,											//������ ����� DC (ȭ�鿡 ��µǴ� DC)
			destX,										//����� ����� ���� X��ǥ
			destY,										//����� ����� ���� Y��ǥ
			_imageInfo->width,				//����� �̹����� ���� ũ��
			_imageInfo->height,			//����� �̹����� ���� ũ��
			_imageInfo->hMemDC,		//����� �̹����� DC
			0,												//���� ���� (X)
			0,												//���� ���� (Y)
			_imageInfo->width,				//���� ������ ���� ũ��
			_imageInfo->height,			//���� ������ ���� ũ��
			_transColor							//������ �� ������ ���� ����
		);
	}
	else
	{
		//BitBlt : DC ���� �������� ���� ��Ӻ��縦 ���ִ� �Լ�
		BitBlt(hdc, destX, destY, _imageInfo->width, _imageInfo->height, _imageInfo->hMemDC, 0, 0, SRCCOPY);
	}
}

void image::render(HDC hdc, int destX, int destY, int sourceX, int sourceY, int sourceWidth, int sourceHeight)
{
	if (_isTrans)
	{
		//GdiTransparentBlt : ��Ʈ�� �̹����� �ҷ��� �� Ư�� ������ �����ϰ� �������ִ� �Լ�
		GdiTransparentBlt
		(
			hdc,											//������ ����� DC (ȭ�鿡 ��µǴ� DC)
			destX,										//����� ����� ���� X��ǥ
			destY,										//����� ����� ���� Y��ǥ
			sourceWidth,						//����� �̹����� ���� ũ��
			sourceHeight,						//����� �̹����� ���� ũ��
			_imageInfo->hMemDC,		//����� �̹����� DC
			sourceX,									//���� ���� (X)
			sourceY,									//���� ���� (Y)
			sourceWidth,						//���� ������ ���� ũ��
			sourceHeight,						//���� ������ ���� ũ��
			_transColor							//������ �� ������ ���� ����
		);
	}
	else
	{
		//BitBlt : DC ���� �������� ���� ��Ӻ��縦 ���ִ� �Լ�
		BitBlt(hdc, destX, destY, sourceWidth, sourceHeight, _imageInfo->hMemDC, sourceX, sourceY, SRCCOPY);
	}
}

void image::alphaRender(HDC hdc, BYTE alpha)
{
	//���ĺ��带 ó�� ����ϴ� ��� �ʱ�ȭ�� ����
	if (!_blendImage)	initAlphaBlend();

	//���İ��� �ʱ�ȭ
	_blendFunc.SourceConstantAlpha = alpha;

	//Ư�� ������ ���� �Ŀ� ���ĺ��带 �ǽ��� ���
	if (_isTrans)
	{
		// 1. ����ؾߵ� DC�� �׷��� �ִ� ������ _blendImage�� ��Ƶд�.
		BitBlt(_blendImage->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, hdc, 0, 0, SRCCOPY);
		// 2. Ư�� ������ ���� ������ _blendImage�� ���Ӱ� �׷��ش�.
		GdiTransparentBlt(_blendImage->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _imageInfo->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _transColor);
		// 3. _blendImage�� ȭ�鿡 ����Ѵ�.
		AlphaBlend(hdc, 0, 0, _imageInfo->width, _imageInfo->height, _imageInfo->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _blendFunc);
	}
	else
	{
		AlphaBlend(hdc, 0, 0, _imageInfo->width, _imageInfo->height, _imageInfo->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _blendFunc);
	}
}

void image::alphaRender(HDC hdc, int destX, int destY, BYTE alpha)
{
	//���ĺ��带 ó�� ����ϴ� ��� �ʱ�ȭ�� ����
	if (!_blendImage)	initAlphaBlend();

	//���İ��� �ʱ�ȭ
	_blendFunc.SourceConstantAlpha = alpha;

	//Ư�� ������ ���� �Ŀ� ���ĺ��带 �ǽ��� ���
	if (_isTrans)
	{
		// 1. ����ؾߵ� DC�� �׷��� �ִ� ������ _blendImage�� ��Ƶд�.
		BitBlt(_blendImage->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, hdc, destX, destY, SRCCOPY);
		// 2. Ư�� ������ ���� ������ _blendImage�� ���Ӱ� �׷��ش�.
		GdiTransparentBlt(_blendImage->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _imageInfo->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _transColor);
		// 3. _blendImage�� ȭ�鿡 ����Ѵ�.
		AlphaBlend(hdc, destX, destY, _imageInfo->width, _imageInfo->height, _blendImage->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _blendFunc);
	}
	else
	{
		AlphaBlend(hdc, destX, destY, _imageInfo->width, _imageInfo->height, _imageInfo->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _blendFunc);
	}
}

void image::loopRender(HDC hdc, const LPRECT drawArea, int offsetX, int offsetY)
{
	//offset ���� ������ ��쿡 �����ϱ�
	if (offsetX < 0) offsetX = _imageInfo->width + (offsetX % _imageInfo->width);
	if (offsetY < 0) offsetY = _imageInfo->height + (offsetY % _imageInfo->height);

	//ȭ�鿡 ������ ���� ����
	RECT rcSource;
	int sourceWidth;
	int sourceHeight;

	//DC ���� (��ũ�� ũ��)
	RECT rcDest;

	//�̹����� �׷��� �ϴ� ����
	int drawAreaX = drawArea->left;
	int drawAreaY = drawArea->top;
	int drawAreaW = drawArea->right - drawArea->left;
	int drawAreaH = drawArea->bottom - drawArea->top;

	//���� ���� ����
	for (int y = 0; y < drawAreaH; y += sourceHeight)
	{
		//DC ������ ���� ���ϱ�
		rcSource.top = (y + offsetY) % _imageInfo->height;
		rcSource.bottom = _imageInfo->height;
		sourceHeight = rcSource.bottom - rcSource.top;

		//�̹����� ����ϴ� ������ ȭ�� ������ ����� ��
		if (y + sourceHeight > drawAreaH)
		{
			//�Ѿ �׸��� �ȼ�����ŭ bottom ���� �����Ѵ�
			rcSource.bottom -= y + drawAreaY;
			sourceHeight = rcSource.bottom - rcSource.top;
		}

		//ȭ�鿡 �׷����� ���� DC ����
		rcDest.top = y + drawAreaY;
		rcDest.bottom = rcDest.top + sourceHeight;

		//==========

		//���� ���� ����
		for (int x = 0; x < drawAreaW; x += sourceWidth)
		{
			//DC ������ ���� ���� ���ϱ�
			rcSource.left = (x + offsetX) % _imageInfo->width;
			rcSource.right = _imageInfo->width;
			sourceWidth = rcSource.right - rcSource.left;

			//�̹����� ����ϴ� ������ ȭ�� ������ ����� ��
			if (x + sourceWidth > drawAreaW)
			{
				//�Ѿ �׸��� �ȼ�����ŭ right ���� �����Ѵ�
				rcSource.right -= (x + sourceWidth) - drawAreaW;
				sourceWidth = rcSource.right - rcSource.left;
			}

			//ȭ�鿡 �׷����� ���� DC ����
			rcDest.left = x + drawAreaX;
			rcDest.right = rcDest.left + sourceWidth;

			//ȭ�鿡 �׸��� (�Ϲ� ������ �̹��� �߶� ���̱�)
			render(hdc, rcDest.left, rcDest.top, rcSource.left, rcSource.top, sourceWidth, sourceHeight);
		}
	}
}

void image::frameRender(HDC hdc, int destX, int destY)
{
	//�ִϸ��̼��� ����ϱ� ���� ��������Ʈ ��Ʈ�� �����Ͽ� ����ϱ�
	if (_isTrans)
	{
		//Ư�� ������ ����� ���
		GdiTransparentBlt(
			hdc, destX, destY,
			_imageInfo->frameWidth,	_imageInfo->frameHeight,
			_imageInfo->hMemDC,
			_imageInfo->currentFrameX * _imageInfo->frameWidth,
			_imageInfo->currentFrameY * _imageInfo->frameHeight,
			_imageInfo->frameWidth,	_imageInfo->frameHeight,
			_transColor
		);
	}
	else
	{
		//�׷��� ���� ���
		BitBlt(
			hdc, destX, destY,
			_imageInfo->frameWidth,	_imageInfo->frameHeight,
			_imageInfo->hMemDC,
			_imageInfo->currentFrameX * _imageInfo->frameWidth,
			_imageInfo->currentFrameY * _imageInfo->frameHeight,
			SRCCOPY
		);
	}
}

void image::frameRender(HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY)
{
	_imageInfo->currentFrameX = currentFrameX;
	_imageInfo->currentFrameY = currentFrameY;

	if (currentFrameX > _imageInfo->maxFrameX)
	{
		_imageInfo->currentFrameX = _imageInfo->maxFrameX;
	}

	if (currentFrameY > _imageInfo->maxFrameY)
	{
		_imageInfo->currentFrameY = _imageInfo->maxFrameY;
	}

	//�ִϸ��̼��� ����ϱ� ���� ��������Ʈ ��Ʈ�� �����Ͽ� ����ϱ�
	if (_isTrans)
	{
		//Ư�� ������ ����� ���
		GdiTransparentBlt(
			hdc, destX, destY,
			_imageInfo->frameWidth, _imageInfo->frameHeight,
			_imageInfo->hMemDC,
			_imageInfo->currentFrameX * _imageInfo->frameWidth,
			_imageInfo->currentFrameY * _imageInfo->frameHeight,
			_imageInfo->frameWidth, _imageInfo->frameHeight,
			_transColor
		);
	}
	else
	{
		//�׷��� ���� ���
		BitBlt(
			hdc, destX, destY,
			_imageInfo->frameWidth, _imageInfo->frameHeight,
			_imageInfo->hMemDC,
			_imageInfo->currentFrameX * _imageInfo->frameWidth,
			_imageInfo->currentFrameY * _imageInfo->frameHeight,
			SRCCOPY
		);
	}
}
