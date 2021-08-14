#include "setDefine.h"
#include "mainGame.h"

//장면 전환용 전역 변수
int SCindex = 1;

//초기화
HRESULT mainGame::init()
{
	gameNode::init(TRUE);

	SCENEMANAGER->addScene("메인메뉴", new SceneMenu);
	SCENEMANAGER->addScene("회랑", new SceneCastleCorrior);

	//초기화면 설정
	SCENEMANAGER->changeScene("회랑");

	return S_OK;
}

//삭제
void mainGame::release()
{
	gameNode::release();
}

//업데이트
void mainGame::update()
{
	gameNode::update();

	//각 Scene의 업데이트를 실행
	SCENEMANAGER->update();
	
	if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		if (SCindex != 0)
		{
			PreviousScene = SCindex;
			SCindex = 0;
		}
		else
			SCindex = PreviousScene;
	}
	/*
	if (KEYMANAGER->isOnceKeyDown(VK_F6))
	{
		if (SCindex != 0)
		{
			PreviousScene = SCindex;
			SCindex = 0;
		}
		else
			SCindex = PreviousScene;
	}*/
	

	/*//원버튼으로 Scene Transition Trigger ON
	if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD0))
	{
		index++;
	}

	//index가 현재 Scene의 개수보다 더 클 경우
	if (index == SCENE_INDEX)
	{
		//index 값을 0으로 초기화
		index = 0;
	}
	*/
	//Scene Transition
	TransitionScene(SCindex);
}

//렌더
void mainGame::render()
{
	//그림이 묘사되지 않는 영역을 특정 색상으로 채우고 싶을 때 사용하는 함수
	PatBlt(getMemDC(), 0, 0, WINSIZE_X, WINSIZE_Y, BLACKNESS);
	//===========

	SCENEMANAGER->render();

	//===========
	this->getBackBuffer()->render(getHDC());
}

//장면 전환용 사용자 정의 함수

void mainGame::TransitionScene(int nIndex)
{
	//매개변수에 담긴 정수값에 따라 장면 전환을 실시한다.
	switch (nIndex)
	{
	case 0:
		SCENEMANAGER->changeScene("메인메뉴");
		break;
	case 1:
		SCENEMANAGER->changeScene("회랑");
		break;

	}
}