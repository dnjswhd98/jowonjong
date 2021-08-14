#include "setDefine.h"
#include "SceneMenu.h"

HRESULT SceneMenu::init()
{
	mainStatMenu = IMAGEMANAGER->addImage("���θ޴�", "Images/menu.bmp", 0, WINSIZE_Y / 3, 800, 532, false, RGB(0, 0, 0));
	return S_OK;
}

void SceneMenu::release()
{
}

void SceneMenu::update()
{
}

void SceneMenu::render()
{
	//SetBkColor(DC, RGB) : ���ڿ��� �޹�� ������ ���ϴ� �Լ�
	SetBkColor(getMemDC(), RGB(255, 255, 255));
	//SetBkMode(DC, OPAQUE �Ǵ� TRANSPARENT) : ���ڿ��� ������ ����� ���ϴ� �Լ�
	//OPAQUE : �������ϰ� ����
	//TRANSPARENT : �����ϰ� ����
	SetBkMode(getMemDC(), OPAQUE);

	//���� ǥ��
	char menuType[128];
	wsprintf(menuType, "SOUL SET");
	TextOut(getMemDC(), 3, 320, menuType, strlen(menuType));

	IMAGEMANAGER->render("���θ޴�", getMemDC());
}
