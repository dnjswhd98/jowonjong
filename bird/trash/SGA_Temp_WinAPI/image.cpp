#include "setDefine.h"
#include "image.h"

//AlphaBlend를 사용하기 위한 라이브러리 추가
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
	//재초기화 방지(만약 이미지 정보에 값들이 존재할 경우 우선 release())
	if (_imageInfo != NULL) this->release();

	//DC 불러오기
	HDC hdc = GetDC(_hWnd);

	//이미지 정보 초기화
	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_EMPTY;
	_imageInfo->resID = 0;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);
	_imageInfo->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, width, height);
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->width = width;
	_imageInfo->height = height;

	//파일 이름
	_fileName = NULL;

	//삭제할 배경 색상의 선택 여부
	_isTrans = FALSE;
	_transColor = RGB(0, 0, 0);
	
	//만약 리소스를 읽어오기에 실패했을 경우
	if (_imageInfo->hBit == 0)
	{
		this->release();
		return E_FAIL;
	}

	//문제없이 리소스 불러오기에 성공했을 경우
	ReleaseDC(_hWnd, hdc);
	return S_OK;
}

HRESULT image::init(const DWORD resID, int width, int height, BOOL isTrans, COLORREF transColor)
{
	//재초기화 방지(만약 이미지 정보에 값들이 존재할 경우 우선 release())
	if (_imageInfo != NULL) this->release();

	//DC 불러오기
	HDC hdc = GetDC(_hWnd);

	//이미지 정보 초기화
	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_EMPTY;
	_imageInfo->resID = resID;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);
	_imageInfo->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, width, height);
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->width = width;
	_imageInfo->height = height;

	//파일 이름
	_fileName = NULL;

	//삭제할 배경 색상의 선택 여부
	_isTrans = FALSE;
	_transColor = RGB(0, 0, 0);

	//만약 리소스를 읽어오기에 실패했을 경우
	if (_imageInfo->hBit == 0)
	{
		this->release();
		return E_FAIL;
	}

	//문제없이 리소스 불러오기에 성공했을 경우
	ReleaseDC(_hWnd, hdc);
	return S_OK;
}

HRESULT image::init(const char * fileName, int width, int height, BOOL isTrans, COLORREF transColor)
{
	//재초기화 방지(만약 이미지 정보에 값들이 존재할 경우 우선 release())
	if (_imageInfo != NULL) this->release();

	//DC 불러오기
	HDC hdc = GetDC(_hWnd);

	//이미지 정보 초기화
	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_EMPTY;
	_imageInfo->resID = 0;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);
	_imageInfo->hBit = (HBITMAP)LoadImage(_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->width = width;
	_imageInfo->height = height;

	//파일 이름
	int len = strlen(fileName);
	_fileName = new CHAR[len + 1];
	strcpy_s(_fileName, len + 1, fileName);

	//삭제할 배경 색상의 선택 여부
	_isTrans = isTrans;
	_transColor = transColor;

	//만약 리소스를 읽어오기에 실패했을 경우
	if (_imageInfo->hBit == 0)
	{
		this->release();
		return E_FAIL;
	}

	//문제없이 리소스 불러오기에 성공했을 경우
	ReleaseDC(_hWnd, hdc);
	return S_OK;
}

HRESULT image::init(const char * fileName, float x, float y, int width, int height, BOOL isTrans, COLORREF transColor)
{
	//재초기화 방지(만약 이미지 정보에 값들이 존재할 경우 우선 release())
	if (_imageInfo != NULL) this->release();

	//DC 불러오기
	HDC hdc = GetDC(_hWnd);

	//이미지 정보 초기화
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

	//파일 이름
	int len = strlen(fileName);
	_fileName = new CHAR[len + 1];
	strcpy_s(_fileName, len + 1, fileName);

	//삭제할 배경 색상의 선택 여부
	_isTrans = isTrans;
	_transColor = transColor;

	//만약 리소스를 읽어오기에 실패했을 경우
	if (_imageInfo->hBit == 0)
	{
		this->release();
		return E_FAIL;
	}

	//문제없이 리소스 불러오기에 성공했을 경우
	ReleaseDC(_hWnd, hdc);
	return S_OK;

}

HRESULT image::init(const char * fileName, int width, int height, int maxFrameX, int maxFrameY, BOOL isTrans, COLORREF transColor)
{
	//재초기화 방지(만약 이미지 정보에 값들이 존재할 경우 우선 release())
	if (_imageInfo != NULL) this->release();

	//DC 불러오기
	HDC hdc = GetDC(_hWnd);

	//이미지 정보 초기화
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

	//파일 이름
	int len = strlen(fileName);
	_fileName = new CHAR[len + 1];
	strcpy_s(_fileName, len + 1, fileName);

	//삭제할 배경 색상의 선택 여부
	_isTrans = isTrans;
	_transColor = transColor;

	//만약 리소스를 읽어오기에 실패했을 경우
	if (_imageInfo->hBit == 0)
	{
		this->release();
		return E_FAIL;
	}

	//문제없이 리소스 불러오기에 성공했을 경우
	ReleaseDC(_hWnd, hdc);
	return S_OK;

}

HRESULT image::init(const char * fileName, float x, float y, int width, int height, int maxFrameX, int maxFrameY, BOOL isTrans, COLORREF transColor)
{
	//재초기화 방지(만약 이미지 정보에 값들이 존재할 경우 우선 release())
	if (_imageInfo != NULL) this->release();

	//DC 불러오기
	HDC hdc = GetDC(_hWnd);

	//이미지 정보 초기화
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

	//파일 이름
	int len = strlen(fileName);
	_fileName = new CHAR[len + 1];
	strcpy_s(_fileName, len + 1, fileName);

	//삭제할 배경 색상의 선택 여부
	_isTrans = isTrans;
	_transColor = transColor;

	//만약 리소스를 읽어오기에 실패했을 경우
	if (_imageInfo->hBit == 0)
	{
		this->release();
		return E_FAIL;
	}

	//문제없이 리소스 불러오기에 성공했을 경우
	ReleaseDC(_hWnd, hdc);
	return S_OK;


}

HRESULT image::initAlphaBlend(void)
{
	HDC hdc = GetDC(_hWnd);

	//알파블렌드 옵션 설정
	_blendFunc.BlendFlags = 0;
	_blendFunc.AlphaFormat = 0;
	_blendFunc.BlendOp = AC_SRC_OVER;

	//알파값이 적용된 이미지의 정보 설정
	_blendImage = new IMAGE_INFO;
	_blendImage->loadType = LOAD_FILE;
	_blendImage->resID = 0;
	_blendImage->hMemDC = CreateCompatibleDC(hdc);
	_blendImage->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, _imageInfo->width, _imageInfo->height);
	_blendImage->hOBit = (HBITMAP)SelectObject(_blendImage->hMemDC, _blendImage->hBit);
	_blendImage->width = WINSIZE_X;
	_blendImage->height = WINSIZE_Y;

	//DC 해제
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
	//이미지 정보가 남아있을 경우 메모리에서 해제
	if (_imageInfo)
	{
		//DC 삭제
		SelectObject(_imageInfo->hMemDC, _imageInfo->hOBit);
		DeleteObject(_imageInfo->hBit);
		DeleteDC(_imageInfo->hMemDC);

		//객체 삭제
		SAFE_DELETE(_imageInfo);
		SAFE_DELETE_ARRAY(_fileName);

		//기타 변수 초기화
		_isTrans = FALSE;
		_transColor = RGB(0, 0, 0);
	}
}

void image::render(HDC hdc)
{
	if (_isTrans)
	{
		//GdiTransparentBlt : 비트맵 이미지를 불러올 때 특정 색상을 제외하고 복사해주는 함수
		GdiTransparentBlt
		(
			hdc,											//복사할 장소의 DC (화면에 출력되는 DC)
			0,												//복사될 장소의 시작 X좌표
			0,												//복사될 장소의 시작 Y좌표
			_imageInfo->width,				//복사될 이미지의 가로 크기
			_imageInfo->height,			//복사될 이미지의 세로 크기
			_imageInfo->hMemDC,		//복사될 이미지의 DC
			0,												//복사 지점 (X)
			0,												//복사 지점 (Y)
			_imageInfo->width,				//복사 영역의 가로 크기
			_imageInfo->height,			//복사 영역의 세로 크기
			_transColor							//복사할 때 제외할 색상 정보
		);
	}
	else
	{
		//BitBlt : DC 간의 영역끼리 서로 고속복사를 해주는 함수
		BitBlt(hdc, 0, 0, _imageInfo->width, _imageInfo->height, _imageInfo->hMemDC, 0, 0, SRCCOPY);
	}
}

void image::render(HDC hdc, int destX, int destY)
{
	if (_isTrans)
	{
		//GdiTransparentBlt : 비트맵 이미지를 불러올 때 특정 색상을 제외하고 복사해주는 함수
		GdiTransparentBlt
		(
			hdc,											//복사할 장소의 DC (화면에 출력되는 DC)
			destX,										//복사될 장소의 시작 X좌표
			destY,										//복사될 장소의 시작 Y좌표
			_imageInfo->width,				//복사될 이미지의 가로 크기
			_imageInfo->height,			//복사될 이미지의 세로 크기
			_imageInfo->hMemDC,		//복사될 이미지의 DC
			0,												//복사 지점 (X)
			0,												//복사 지점 (Y)
			_imageInfo->width,				//복사 영역의 가로 크기
			_imageInfo->height,			//복사 영역의 세로 크기
			_transColor							//복사할 때 제외할 색상 정보
		);
	}
	else
	{
		//BitBlt : DC 간의 영역끼리 서로 고속복사를 해주는 함수
		BitBlt(hdc, destX, destY, _imageInfo->width, _imageInfo->height, _imageInfo->hMemDC, 0, 0, SRCCOPY);
	}
}

void image::render(HDC hdc, int destX, int destY, int sourceX, int sourceY, int sourceWidth, int sourceHeight)
{
	if (_isTrans)
	{
		//GdiTransparentBlt : 비트맵 이미지를 불러올 때 특정 색상을 제외하고 복사해주는 함수
		GdiTransparentBlt
		(
			hdc,											//복사할 장소의 DC (화면에 출력되는 DC)
			destX,										//복사될 장소의 시작 X좌표
			destY,										//복사될 장소의 시작 Y좌표
			sourceWidth,						//복사될 이미지의 가로 크기
			sourceHeight,						//복사될 이미지의 세로 크기
			_imageInfo->hMemDC,		//복사될 이미지의 DC
			sourceX,									//복사 지점 (X)
			sourceY,									//복사 지점 (Y)
			sourceWidth,						//복사 영역의 가로 크기
			sourceHeight,						//복사 영역의 세로 크기
			_transColor							//복사할 때 제외할 색상 정보
		);
	}
	else
	{
		//BitBlt : DC 간의 영역끼리 서로 고속복사를 해주는 함수
		BitBlt(hdc, destX, destY, sourceWidth, sourceHeight, _imageInfo->hMemDC, sourceX, sourceY, SRCCOPY);
	}
}

void image::alphaRender(HDC hdc, BYTE alpha)
{
	//알파블렌드를 처음 사용하는 경우 초기화를 진행
	if (!_blendImage)	initAlphaBlend();

	//알파값을 초기화
	_blendFunc.SourceConstantAlpha = alpha;

	//특정 색상을 없앤 후에 알파블렌드를 실시할 경우
	if (_isTrans)
	{
		// 1. 출력해야될 DC에 그려져 있는 내용을 _blendImage에 담아둔다.
		BitBlt(_blendImage->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, hdc, 0, 0, SRCCOPY);
		// 2. 특정 색상을 없앤 상태의 _blendImage에 새롭게 그려준다.
		GdiTransparentBlt(_blendImage->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _imageInfo->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _transColor);
		// 3. _blendImage를 화면에 출력한다.
		AlphaBlend(hdc, 0, 0, _imageInfo->width, _imageInfo->height, _imageInfo->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _blendFunc);
	}
	else
	{
		AlphaBlend(hdc, 0, 0, _imageInfo->width, _imageInfo->height, _imageInfo->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _blendFunc);
	}
}

void image::alphaRender(HDC hdc, int destX, int destY, BYTE alpha)
{
	//알파블렌드를 처음 사용하는 경우 초기화를 진행
	if (!_blendImage)	initAlphaBlend();

	//알파값을 초기화
	_blendFunc.SourceConstantAlpha = alpha;

	//특정 색상을 없앤 후에 알파블렌드를 실시할 경우
	if (_isTrans)
	{
		// 1. 출력해야될 DC에 그려져 있는 내용을 _blendImage에 담아둔다.
		BitBlt(_blendImage->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, hdc, destX, destY, SRCCOPY);
		// 2. 특정 색상을 없앤 상태의 _blendImage에 새롭게 그려준다.
		GdiTransparentBlt(_blendImage->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _imageInfo->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _transColor);
		// 3. _blendImage를 화면에 출력한다.
		AlphaBlend(hdc, destX, destY, _imageInfo->width, _imageInfo->height, _blendImage->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _blendFunc);
	}
	else
	{
		AlphaBlend(hdc, destX, destY, _imageInfo->width, _imageInfo->height, _imageInfo->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _blendFunc);
	}
}

void image::loopRender(HDC hdc, const LPRECT drawArea, int offsetX, int offsetY)
{
	//offset 값이 음수일 경우에 보정하기
	if (offsetX < 0) offsetX = _imageInfo->width + (offsetX % _imageInfo->width);
	if (offsetY < 0) offsetY = _imageInfo->height + (offsetY % _imageInfo->height);

	//화면에 묘사할 영역 설정
	RECT rcSource;
	int sourceWidth;
	int sourceHeight;

	//DC 영역 (스크린 크기)
	RECT rcDest;

	//이미지를 그려야 하는 영역
	int drawAreaX = drawArea->left;
	int drawAreaY = drawArea->top;
	int drawAreaW = drawArea->right - drawArea->left;
	int drawAreaH = drawArea->bottom - drawArea->top;

	//세로 루프 영역
	for (int y = 0; y < drawAreaH; y += sourceHeight)
	{
		//DC 영역의 높이 구하기
		rcSource.top = (y + offsetY) % _imageInfo->height;
		rcSource.bottom = _imageInfo->height;
		sourceHeight = rcSource.bottom - rcSource.top;

		//이미지를 출력하는 영역이 화면 밖으로 벗어났을 때
		if (y + sourceHeight > drawAreaH)
		{
			//넘어간 그림의 픽셀값만큼 bottom 값을 조정한다
			rcSource.bottom -= y + drawAreaY;
			sourceHeight = rcSource.bottom - rcSource.top;
		}

		//화면에 그려지는 세로 DC 영역
		rcDest.top = y + drawAreaY;
		rcDest.bottom = rcDest.top + sourceHeight;

		//==========

		//가로 루프 영역
		for (int x = 0; x < drawAreaW; x += sourceWidth)
		{
			//DC 영역의 가로 길이 구하기
			rcSource.left = (x + offsetX) % _imageInfo->width;
			rcSource.right = _imageInfo->width;
			sourceWidth = rcSource.right - rcSource.left;

			//이미지를 출력하는 영역이 화면 밖으로 벗어났을 때
			if (x + sourceWidth > drawAreaW)
			{
				//넘어간 그림의 픽셀값만큼 right 값을 조정한다
				rcSource.right -= (x + sourceWidth) - drawAreaW;
				sourceWidth = rcSource.right - rcSource.left;
			}

			//화면에 그려지는 가로 DC 영역
			rcDest.left = x + drawAreaX;
			rcDest.right = rcDest.left + sourceWidth;

			//화면에 그리기 (일반 렌더의 이미지 잘라 붙이기)
			render(hdc, rcDest.left, rcDest.top, rcSource.left, rcSource.top, sourceWidth, sourceHeight);
		}
	}
}

void image::frameRender(HDC hdc, int destX, int destY)
{
	//애니메이션을 출력하기 위해 스프라이트 시트를 분할하여 출력하기
	if (_isTrans)
	{
		//특정 색상을 지우는 경우
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
		//그렇지 않은 경우
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

	//애니메이션을 출력하기 위해 스프라이트 시트를 분할하여 출력하기
	if (_isTrans)
	{
		//특정 색상을 지우는 경우
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
		//그렇지 않은 경우
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
