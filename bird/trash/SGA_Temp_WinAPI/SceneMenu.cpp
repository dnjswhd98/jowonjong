#include "setDefine.h"
#include "SceneMenu.h"

HRESULT SceneMenu::init()
{
	mainStatMenu = IMAGEMANAGER->addImage("메인메뉴", "Images/menu.bmp", 0, WINSIZE_Y / 3, 800, 532, false, RGB(0, 0, 0));
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
	//SetBkColor(DC, RGB) : 문자열의 뒷배경 색상을 정하는 함수
	SetBkColor(getMemDC(), RGB(255, 255, 255));
	//SetBkMode(DC, OPAQUE 또는 TRANSPARENT) : 문자열의 렌더링 방식을 정하는 함수
	//OPAQUE : 불투명하게 설정
	//TRANSPARENT : 투명하게 설정
	SetBkMode(getMemDC(), OPAQUE);

	//점수 표시
	char menuType[128];
	wsprintf(menuType, "SOUL SET");
	TextOut(getMemDC(), 3, 320, menuType, strlen(menuType));

	IMAGEMANAGER->render("메인메뉴", getMemDC());
}
