#include "setDefine.h"
#include "sceneManager.h"
#include "gameNode.h"

HRESULT sceneManager::init()
{
	return S_OK;
}

void sceneManager::release()
{
	//iterator
	mSceneList_itr itr = _mSceneList.begin();

	for (; itr != _mSceneList.end();)
	{
		//���� gameNode�� �����ϴ� ���
		if (itr->second != NULL)
		{
			if (itr->second == _currentScene)
			{
				itr->second->release();
				SAFE_DELETE(itr->second);
				itr = _mSceneList.erase(itr);
			}
		}
		else
		{
			itr++;
		}
	}
}

void sceneManager::update()
{
	_currentScene->update();
}

void sceneManager::render()
{
	_currentScene->render();
}

gameNode * sceneManager::addScene(string sceneName, gameNode * scene)
{
	//Scene�� ���ٸ� NULL ��ȯ
	if (!scene) return NULL;

	//Scene�� �ִٸ� map�� �߰�
	_mSceneList.insert(make_pair(sceneName, scene));

	return scene;
}

HRESULT sceneManager::changeScene(string sceneName)
{
	mSceneList_itr find = _mSceneList.find(sceneName);

	//Scene�� ã�� ����
	if (find == _mSceneList.end()) return E_FAIL;

	//Scene�� ã������ ���� Scene�� ������ ���
	if (find->second == _currentScene) return E_FAIL;

	//�̻��� ������ Ȯ���� �� �ʱ�ȭ�ϰ� Scene ��ȯ
	if (SUCCEEDED(find->second->init()))
	{
		_currentScene = find->second;
		return S_OK;
	}
	return E_FAIL;
}
