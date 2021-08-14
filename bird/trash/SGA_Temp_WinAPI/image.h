#pragma once

class image
{
public:
	image();
	~image();

	enum IMAGE_LOAD_CATEGORY
	{
		LOAD_RESOURCE,
		LOAD_FILE,
		LOAD_EMPTY,
		LOAD_END
	};

	typedef struct tagImage
	{
		DWORD resID;											//리소스 ID
		HDC hMemDC;											//DC 정보
		HBITMAP hBit;											//비트맵
		HBITMAP hOBit;										//올드 비트맵
		float x, y;													//이미지 X, Y좌표
		int width, height;										//이미지 가로&세로 길이
		int currentFrameX, currentFrameY;	//현재 프레임의 X,Y 값
		int maxFrameX, maxFrameY;					//현재 프레임의 최대 X, Y 값
		int frameWidth, frameHeight;				//1프레임의 가로&세로 길이
		BYTE loadType;											//이미지 로드 타입

		tagImage()
		{
			resID = 0;
			hMemDC = NULL;
			hBit = NULL;
			hOBit = NULL;
			x = y = width = height = 0;
			currentFrameX = currentFrameY = 0;
			maxFrameX = maxFrameY = 0;
			loadType = LOAD_RESOURCE;
		}
	}IMAGE_INFO, *LPIMAGE_INFO;


	//초기화
	HRESULT init(int width, int height);
	HRESULT init(const DWORD resID, int width, int height, BOOL isTrans = FALSE, COLORREF transColor = RGB(0,0,0));
	HRESULT init(const char* fileName, int width, int height, BOOL isTrans = FALSE, COLORREF transColor = RGB(0,0,0));
	HRESULT init(const char* fileName, float x, float y, int width, int height, BOOL isTrans = FALSE, COLORREF transColor = RGB(0,0,0));
	
	//FrameImage 초기화 (1)
	HRESULT init(const char* fileName, int width, int height, int maxFrameX, int maxFrameY, BOOL isTrans = FALSE, COLORREF transColor = RGB(0,0,0));
	//FrameImage 초기화 (2)
	HRESULT init(const char* fileName, float x, float y, int width, int height, int maxFrameX, int maxFrameY, BOOL isTrans = FALSE, COLORREF transColor = RGB(0, 0, 0));

	//AlphaBlend 초기화
	HRESULT initAlphaBlend(void);

	//bmp 파일을 png처럼 배경을 투명하게 만들기 위한 특정 컬러 삭제용 함수
	void setTransColor(BOOL isTrans, COLORREF transColor);

	//메모리에서 해제
	void release();

	//화면에 그리기 (내가 지정한 좌표에 이미지 출력)
	void render(HDC hdc);
	void render(HDC hdc, int destX, int destY);
	
	//화면에 그리기 (내가 지정한 좌표에 내가 원하는 만큼만 출력)
	void render(HDC hdc, int destX, int destY, int sourceX, int sourceY, int sourceWidth, int sourceHeight);

	//알파 렌더 (알파값과 함께 이미지를 출력)
	void alphaRender(HDC hdc, BYTE alpha);
	//알파 렌더 (내가 지정한 좌표에 이미지를 출력)
	void alphaRender(HDC hdc, int destX, int destY, BYTE alpha);

	//루프 렌더
	void loopRender(HDC hdc, const LPRECT drawArea, int offsetX, int offsetY);

	//프레임 렌더
	void frameRender(HDC hdc, int destX, int destY);
	void frameRender(HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY);

	//DC 받아오기
	inline HDC getMemDC(void) { return _imageInfo->hMemDC; }

	//이미지 좌표 (X축)
	inline float getX(void) { return _imageInfo->x; }
	inline void setX(float x) { _imageInfo->x = x; }

	//이미지 좌표 (Y축)
	inline float getY(void) { return _imageInfo->y; }
	inline void setY(float y) { _imageInfo->y = y; }

	//이미지의 센터 좌표 설정
	inline void setCenter(float x, float y)
	{
		_imageInfo->x = x - (_imageInfo->width / 2);
		_imageInfo->y = y - (_imageInfo->height / 2);
	}

	//이미지의 가로세로 길이 구하기
	inline int getWidth(void) { return _imageInfo->width; }
	inline int getHeight(void) { return _imageInfo->height; }

	//바운딩박스 구하기 (충돌용 RECT)
	inline RECT boundingBox(void)
	{
		RECT rc = { (int)_imageInfo->x, (int)_imageInfo->y,
							(int)_imageInfo->x + _imageInfo->width,
							(int)_imageInfo->y + _imageInfo->height };
	}

	//X축의 프레임 위치 설정 (get&set)
	inline int getFrameX(void) { return _imageInfo->currentFrameX; }
	inline void setFrameX(int frameX)
	{
		_imageInfo->currentFrameX = frameX;
		if (frameX > _imageInfo->maxFrameX)
		{
			_imageInfo->currentFrameX = _imageInfo->maxFrameX;
		}
	}

	//Y축의 프레임 위치 설정 (get&set)
	inline int getFrameY(void) { return _imageInfo->currentFrameY; }
	inline void setFrameY(int frameY)
	{
		_imageInfo->currentFrameY = frameY;
		if (frameY > _imageInfo->maxFrameY)
		{
			_imageInfo->currentFrameY = _imageInfo->maxFrameY;
		}
	}

	//이미지 1프레임의 가로세로 길이 구하기
	inline int getFrameWidth(void) { return _imageInfo->frameWidth; }
	inline int getFrameHeight(void) { return _imageInfo->frameHeight; }

	//x, y의 최대 프레임 개수 구하기
	inline int getMaxFrameX(void) { return _imageInfo->maxFrameX; }
	inline int getMaxFrameY(void) { return _imageInfo->maxFrameY; }

private:
	LPIMAGE_INFO _imageInfo;			//이미지 정보
	CHAR* _fileName;								//이미지 이름
	BOOL _isTrans;									//특정 색상을 없앨 건지?
	COLORREF _transColor;					//삭제할 특정 색상의 RGB값

	BLENDFUNCTION _blendFunc;		//알파 렌더에 쓰일 정보
	LPIMAGE_INFO _blendImage;		//알파 렌더용 이미지 정보
};

