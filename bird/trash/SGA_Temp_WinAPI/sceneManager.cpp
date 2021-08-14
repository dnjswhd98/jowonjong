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
		//만약 gameNode가 존재하는 경우
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
	//Scene이 없다면 NULL 반환
	if (!scene) return NULL;

	//Scene이 있다면 map에 추가
	_mSceneList.insert(make_pair(sceneName, scene));

	return scene;
}

HRESULT sceneManager::changeScene(string sceneName)
{
	mSceneList_itr find = _mSceneList.find(sceneName);

	//Scene을 찾지 못함
	if (find == _mSceneList.end()) return E_FAIL;

	//Scene을 찾았지만 현재 Scene과 동일한 경우
	if (find->second == _currentScene) return E_FAIL;

	//이상이 없으면 확인한 후 초기화하고 Scene 전환
	if (SUCCEEDED(find->second->init()))
	{
		_currentScene = find->second;
		return S_OK;
	}
	return E_FAIL;
}
