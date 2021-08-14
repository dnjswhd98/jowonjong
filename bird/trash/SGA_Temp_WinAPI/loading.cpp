#include "setDefine.h"
#include "loading.h"

HRESULT loadItem::init(string keyName, int width, int height)
{
	//로딩 종류 초기화
	_itemCategory = LOAD_IMAGE_0;

	//이미지 구조체 초기화
	_imageResource.keyName = keyName;
	_imageResource.width = width; 
	_imageResource.height = height;

	return S_OK;
}

HRESULT loadItem::init(string keyName, const char * fileName, int width, int height, BOOL isTrans, COLORREF transColor)
{
	//로딩 종류 초기화
	_itemCategory = LOAD_IMAGE_1;

	//이미지 구조체 초기화
	_imageResource.keyName = keyName;
	_imageResource.fileName = fileName;
	_imageResource.width = width;
	_imageResource.height = height;
	_imageResource.trans = isTrans;
	_imageResource.transColor = transColor;

	return S_OK;
}

HRESULT loadItem::init(string keyName, const char * fileName, float x, float y, int width, int height, BOOL isTrans, COLORREF transColor)
{
	_itemCategory = LOAD_IMAGE_2;

	_imageResource.keyName = keyName;
	_imageResource.fileName = fileName;
	_imageResource.x = x;
	_imageResource.y = y;
	_imageResource.width = width;
	_imageResource.height = height;
	_imageResource.trans = isTrans;
	_imageResource.transColor = transColor;

	return S_OK;

}

HRESULT loadItem::init(string keyName, const char * fileName, int width, int height, int maxFrameX, int maxFrameY, BOOL isTrans, COLORREF transColor)
{
	_itemCategory = LOAD_FRAMEIMAGE_0;

	_imageResource.keyName = keyName;
	_imageResource.fileName = fileName;
	_imageResource.frameX = maxFrameX;
	_imageResource.frameY = maxFrameY;
	_imageResource.width = width;
	_imageResource.height = height;
	_imageResource.trans = isTrans;
	_imageResource.transColor = transColor;

	return S_OK;
}

HRESULT loadItem::init(string keyName, const char * fileName, int x, int y, int width, int height, int maxFrameX, int maxFrameY, BOOL isTrans, COLORREF transColor)
{
	_itemCategory = LOAD_FRAMEIMAGE_1;

	_imageResource.keyName = keyName;
	_imageResource.fileName = fileName;
	_imageResource.x = x;
	_imageResource.y = y;
	_imageResource.frameX = maxFrameX;
	_imageResource.frameY = maxFrameY;
	_imageResource.width = width;
	_imageResource.height = height;
	_imageResource.trans = isTrans;
	_imageResource.transColor = transColor;

	return S_OK;

}






HRESULT loading::init()
{
	//로딩화면 백그라운드 이미지
	_background = IMAGEMANAGER->addImage("로딩화면", "Images/soulworker_logo.bmp", WINSIZE_X, WINSIZE_Y);
	
	//로딩바 초기화
	_loadingBar = new progressBar;
	_loadingBar->init((char*)"Images/loadingBarFront", (char*)"Images/loadingBarBack", WINSIZE_X / 4, 600, 640, 48);
	_loadingBar->setGauge(0, 0);
	_currentGauge = 0;

	return S_OK;
}

void loading::release()
{
	SAFE_DELETE(_loadingBar);
}

void loading::update()
{
	_loadingBar->update();
}

void loading::render()
{
	_background->render(getMemDC());
	_loadingBar->render();
}

void loading::loadImage(string strKey, int width, int height)
{
	//아이템 객체를 만들고
	loadItem* item = new loadItem;
	//초기화를 진행한 뒤에
	item->init(strKey, width, height);
	//벡터에 해당 데이터를 삽입한다
	_vLoadItem.push_back(item);
}

void loading::loadImage(string strKey, const char * fileName, int width, int height, BOOL isTrans, COLORREF transColor)
{
	loadItem* item = new loadItem;
	item->init(strKey, fileName, width, height, isTrans, transColor);
	_vLoadItem.push_back(item);
}

void loading::loadImage(string strKey, const char * fileName, float x, float y, int width, int height, BOOL isTrans, COLORREF transColor)
{
	loadItem* item = new loadItem;
	item->init(strKey, fileName, x, y, width, height, isTrans, transColor);
	_vLoadItem.push_back(item);
}

void loading::loadFrameImage(string strKey, const char * fileName, int width, int height, int maxFrameX, int maxFrameY, BOOL isTrans, COLORREF transColor)
{
	//여기는 일단 생략하고 넘어간다
}

void loading::loadFrameImage(string strKey, const char * fileName, float x, float y, int width, int height, int maxFrameX, int maxFrameY, BOOL isTrans, COLORREF transColor)
{
	loadItem* item = new loadItem;
	item->init(strKey, fileName, x, y, width, height, maxFrameX, maxFrameY, isTrans, transColor);
	_vLoadItem.push_back(item);
}

BOOL loading::loadingDone()
{
	//로딩이 충분히 진행됐을 경우
	if (_currentGauge >= _vLoadItem.size())
	{
		return TRUE;
	}

	//loadItem 객체
	loadItem* item = _vLoadItem[_currentGauge];

	//아이템 객체의 카테고리가 어떤 것인지에 따라 IMAGEMANAGER에 다르게 추가
	switch (item->getLoadingItemCategory())
	{
	case LOAD_IMAGE_0:
	{
		tagImageResource img = item->getItemResource();
		IMAGEMANAGER->addImage(img.keyName, img.width, img.height);
	}
	break;
	
	case LOAD_IMAGE_1:
	{
		tagImageResource img = item->getItemResource();
		IMAGEMANAGER->addImage(img.keyName, img.fileName, img.width, img.height, img.trans, img.transColor);
	}
	break;	
	
	case LOAD_IMAGE_2:
	{
		tagImageResource img = item->getItemResource();
		IMAGEMANAGER->addImage(img.keyName, img.fileName, img.x, img.y, img.width, img.height, img.trans, img.transColor);
	}
	break;

	case LOAD_SOUND:
		break;	
	case LOAD_END:
		break;
	}
	
	//로딩게이지 상승
	_currentGauge++;

	//로딩게이지 갱신
	_loadingBar->setGauge(_currentGauge, _vLoadItem.size());

	return FALSE;
}
