#pragma once
#include "gameNode.h"
#include "progressBar.h"

typedef enum
{
	LOAD_IMAGE_0,				//�� ��Ʈ�� �̹���
	LOAD_IMAGE_1,					//�Ϲ� �̹���
	LOAD_IMAGE_2,				//�Ϲ� �̹��� (��ġ ��ǥ ����)
	LOAD_FRAMEIMAGE_0,	//������ �̹���
	LOAD_FRAMEIMAGE_1,		//������ �̹��� (��ġ ��ǥ ����)
	LOAD_SOUND,					//����
	LOAD_END,							//��
}LOAD_ITEM;

typedef struct
{
	string keyName;
	const char* fileName;
	int x, y, width, height, frameX, frameY;
	bool trans;
	COLORREF transColor;
}tagImageResource;

class loadItem
{
private:
	LOAD_ITEM _itemCategory;
	tagImageResource _imageResource;

public:
	//�Ϲ� �̹��� �ʱ�ȭ
	HRESULT init(string keyName, int width, int height);
	HRESULT init(string keyName, const char* fileName, int width, int height, BOOL isTrans = FALSE, COLORREF transColor = RGB(0,0,0));
	HRESULT init(string keyName, const char* fileName, float x, float y, int width, int height, BOOL isTrans = FALSE, COLORREF transColor = RGB(0, 0, 0));

	//������ �̹��� �ʱ�ȭ
	HRESULT init(string keyName, const char* fileName, int width, int height, int maxFrameX, int maxFrameY, BOOL isTrans = FALSE, COLORREF transColor = RGB(0,0,0));
	HRESULT init(string keyName, const char* fileName,int x, int y, int width, int height, int maxFrameX, int maxFrameY, BOOL isTrans = FALSE, COLORREF transColor = RGB(0, 0, 0));

	//�ε� ������ ���� �޾ƿ���
	LOAD_ITEM getLoadingItemCategory() { return _itemCategory; }
	//�̹��� ���ҽ� �޾ƿ���
	tagImageResource getItemResource() { return _imageResource; }

	loadItem() {}
	~loadItem() {}
};

class loading : public gameNode
{
private:
	typedef vector<loadItem*> arrLoadItem;
	typedef vector<loadItem*>::iterator arrLoadItem_itr;

	arrLoadItem _vLoadItem;

	// �ε�ȭ�鿡�� ����� �̹��� ����
	image* _background;
	progressBar* _loadingBar;
	int _currentGauge;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	void loadImage(string strKey, int width, int height);
	void loadImage(string strKey, const char* fileName, int width, int height, BOOL isTrans = FALSE, COLORREF transColor = RGB(0, 0, 0));
	void loadImage(string strKey, const char* fileName, float x, float y, int width, int height, BOOL isTrans = FALSE, COLORREF transColor = RGB(0, 0, 0));

	void loadFrameImage(string strKey, const char* fileName, int width, int height, int maxFrameX, int maxFrameY, BOOL isTrans = FALSE, COLORREF transColor = RGB(0, 0, 0));
	void loadFrameImage(string strKey, const char* fileName, float x, float y, int width, int height, int maxFrameX, int maxFrameY, BOOL isTrans = FALSE, COLORREF transColor = RGB(0, 0, 0));

	//�ε��� �Ϸ�� ���¸� �˻��ϴ� �Լ�
	BOOL loadingDone();

	//LoadItem Ŭ������ vector�� �����´�
	arrLoadItem getLoadItem() { return _vLoadItem; }

	loading() {}
	~loading() {}
};

