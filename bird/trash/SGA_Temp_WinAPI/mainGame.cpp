#include "setDefine.h"
#include "mainGame.h"

//��� ��ȯ�� ���� ����
int SCindex = 1;

//�ʱ�ȭ
HRESULT mainGame::init()
{
	gameNode::init(TRUE);

	SCENEMANAGER->addScene("���θ޴�", new SceneMenu);
	SCENEMANAGER->addScene("ȸ��", new SceneCastleCorrior);

	//�ʱ�ȭ�� ����
	SCENEMANAGER->changeScene("ȸ��");

	return S_OK;
}

//����
void mainGame::release()
{
	gameNode::release();
}

//������Ʈ
void mainGame::update()
{
	gameNode::update();

	//�� Scene�� ������Ʈ�� ����
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
	

	/*//����ư���� Scene Transition Trigger ON
	if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD0))
	{
		index++;
	}

	//index�� ���� Scene�� �������� �� Ŭ ���
	if (index == SCENE_INDEX)
	{
		//index ���� 0���� �ʱ�ȭ
		index = 0;
	}
	*/
	//Scene Transition
	TransitionScene(SCindex);
}

//����
void mainGame::render()
{
	//�׸��� ������� �ʴ� ������ Ư�� �������� ä��� ���� �� ����ϴ� �Լ�
	PatBlt(getMemDC(), 0, 0, WINSIZE_X, WINSIZE_Y, BLACKNESS);
	//===========

	SCENEMANAGER->render();

	//===========
	this->getBackBuffer()->render(getHDC());
}

//��� ��ȯ�� ����� ���� �Լ�

void mainGame::TransitionScene(int nIndex)
{
	//�Ű������� ��� �������� ���� ��� ��ȯ�� �ǽ��Ѵ�.
	switch (nIndex)
	{
	case 0:
		SCENEMANAGER->changeScene("���θ޴�");
		break;
	case 1:
		SCENEMANAGER->changeScene("ȸ��");
		break;

	}
}