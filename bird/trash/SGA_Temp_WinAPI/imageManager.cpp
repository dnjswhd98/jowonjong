#include "setDefine.h"
#include "imageManager.h"

HRESULT imageManager::init(void)
{
	return S_OK;
}

void imageManager::release()
{
	this->deleteAll();
}

//빈 비트맵 초기화 및 이미지 추가
image * imageManager::addImage(string strKey, int width, int height)
{
	//추가하려는 이미지가 이미 존재하는지 검사
	image* img = findImage(strKey);

	//추가하려는 이미지가 이미 존재할 경우, 새로 만들지 않고 그대로 리턴
	if (img) return img;

	//없으면 새로 만들기
	img = new image;

	//불러오는 도중에 뭔가 잘못됐다면 일단 중지
	if (FAILED(img->init(width, height)))
	{
		SAFE_DELETE(img);
		return NULL;
	}

	//map에 데이터 삽입
	_mImageList.insert(make_pair(strKey, img));

	return img;
}

image * imageManager::addImage(string strKey, const char * fileName, int width, int height, BOOL isTrans, COLORREF transColor)
{
	image* img = findImage(strKey);

	if (img) return img;

	img = new image;
	if (FAILED(img->init(fileName, width, height, isTrans, transColor)))
	{
		SAFE_DELETE(img);
		return NULL;
	}

	_mImageList.insert(make_pair(strKey, img));
	return img;
}

image * imageManager::addImage(string strKey, const char * fileName, float x, float y, int width, int height, BOOL isTrans, COLORREF transColor)
{
	image* img = findImage(strKey);

	if (img) return img;

	img = new image;
	if (FAILED(img->init(fileName, x, y, width, height, isTrans, transColor)))
	{
		SAFE_DELETE(img);
		return NULL;
	}

	_mImageList.insert(make_pair(strKey, img));
	return img;
}

image * imageManager::addFrameImage(string strKey, const char * fileName, int width, int height, int maxFrameX, int maxFrameY, BOOL isTrans, COLORREF transColor)
{
	image* img = findImage(strKey);

	if (img) return img;

	img = new image;
	if (FAILED(img->init(fileName, width, height, maxFrameX, maxFrameY, isTrans, transColor)))
	{
		SAFE_DELETE(img);
		return NULL;
	}

	_mImageList.insert(make_pair(strKey, img));
	return img;
}

image * imageManager::addFrameImage(string strKey, const char * fileName, float x, float y, int width, int height, int maxFrameX, int maxFrameY, BOOL isTrans, COLORREF transColor)
{
	image* img = findImage(strKey);

	if (img) return img;

	img = new image;
	if (FAILED(img->init(fileName, x, y, width, height, maxFrameX, maxFrameY, isTrans, transColor)))
	{
		SAFE_DELETE(img);
		return NULL;
	}

	_mImageList.insert(make_pair(strKey, img));
	return img;
}

image * imageManager::findImage(string strKey)
{
	//특정 key를 map에서 검색한다
	mapImageIter key = _mImageList.find(strKey);

	//데이터가 존재하는지 확인
	if (key != _mImageList.end())
	{
		//찾았을 경우 파일 경로 반환
		return key->second;
	}
	//못 찾았을 경우는 NULL 반환
	return NULL;
}

BOOL imageManager::deleteImage(string strKey)
{
	mapImageIter key = _mImageList.find(strKey);
	if (key != _mImageList.end())
	{
		//특정 이미지를 메모리에서 해제하고 맵의 요소도 삭제한다
		key->second->release();
		SAFE_DELETE(key->second);
		_mImageList.erase(key);
		return TRUE;
	}

	return FALSE;
}

BOOL imageManager::deleteAll()
{
	mapImageIter itr = _mImageList.begin();
	for (; itr != _mImageList.end();)
	{
		if (itr->second != NULL)
		{
			itr->second->release();
			SAFE_DELETE(itr->second);
			itr = _mImageList.erase(itr);
		}
		else
		{
			itr++;
		}
	}

	//map 안의 요소를 전부 삭제
	_mImageList.clear();
	return TRUE;
}

void imageManager::render(string strKey, HDC hdc)
{
	image* img = findImage(strKey);
	if (img) img->render(hdc);
}

void imageManager::render(string strKey, HDC hdc, int destX, int destY)
{
	image* img = findImage(strKey);
	if (img) img->render(hdc, destX, destY);
}

void imageManager::render(string strKey, HDC hdc, int destX, int destY, int sourceX, int sourceY, int sourceWidth, int sourceHeight)
{
	image* img = findImage(strKey);
	if (img) img->render(hdc, destX, destY, sourceX, sourceY, sourceWidth, sourceHeight);
}

void imageManager::alphaRender(string strKey, HDC hdc, BYTE alpha)
{
	image* img = findImage(strKey);
	if (img) img->alphaRender(hdc, alpha);
}

void imageManager::alphaRender(string strKey, HDC hdc, int destX, int destY, BYTE alpha)
{
	image* img = findImage(strKey);
	if (img) img->alphaRender(hdc, destX, destY, alpha);
}

void imageManager::loopRender(string strKey, HDC hdc, const LPRECT drawArea, int offsetX, int offsetY)
{
	image* img = findImage(strKey);
	if (img) img->loopRender(hdc, drawArea, offsetX, offsetY);
}

void imageManager::frameRender(string strKey, HDC hdc, int destX, int destY)
{
	image* img = findImage(strKey);
	if (img) img->frameRender(hdc, destX, destY);
}

void imageManager::frameRender(string strKey, HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY)
{
	image* img = findImage(strKey);
	if (img) img->frameRender(hdc, destX, destY, currentFrameX, currentFrameY);
}
