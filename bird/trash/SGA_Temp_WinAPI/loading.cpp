#include "setDefine.h"
#include "loading.h"

HRESULT loadItem::init(string keyName, int width, int height)
{
	//�ε� ���� �ʱ�ȭ
	_itemCategory = LOAD_IMAGE_0;

	//�̹��� ����ü �ʱ�ȭ
	_imageResource.keyName = keyName;
	_imageResource.width = width; 
	_imageResource.height = height;

	return S_OK;
}

HRESULT loadItem::init(string keyName, const char * fileName, int width, int height, BOOL isTrans, COLORREF transColor)
{
	//�ε� ���� �ʱ�ȭ
	_itemCategory = LOAD_IMAGE_1;

	//�̹��� ����ü �ʱ�ȭ
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
	//�ε�ȭ�� ��׶��� �̹���
	_background = IMAGEMANAGER->addImage("�ε�ȭ��", "Images/soulworker_logo.bmp", WINSIZE_X, WINSIZE_Y);
	
	//�ε��� �ʱ�ȭ
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
	//������ ��ü�� �����
	loadItem* item = new loadItem;
	//�ʱ�ȭ�� ������ �ڿ�
	item->init(strKey, width, height);
	//���Ϳ� �ش� �����͸� �����Ѵ�
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
	//����� �ϴ� �����ϰ� �Ѿ��
}

void loading::loadFrameImage(string strKey, const char * fileName, float x, float y, int width, int height, int maxFrameX, int maxFrameY, BOOL isTrans, COLORREF transColor)
{
	loadItem* item = new loadItem;
	item->init(strKey, fileName, x, y, width, height, maxFrameX, maxFrameY, isTrans, transColor);
	_vLoadItem.push_back(item);
}

BOOL loading::loadingDone()
{
	//�ε��� ����� ������� ���
	if (_currentGauge >= _vLoadItem.size())
	{
		return TRUE;
	}

	//loadItem ��ü
	loadItem* item = _vLoadItem[_currentGauge];

	//������ ��ü�� ī�װ��� � �������� ���� IMAGEMANAGER�� �ٸ��� �߰�
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
	
	//�ε������� ���
	_currentGauge++;

	//�ε������� ����
	_loadingBar->setGauge(_currentGauge, _vLoadItem.size());

	return FALSE;
}
