#include "SceneManager.h"

SceneManager* SceneManager::instance = nullptr;

void SceneManager::SetScene(SCENEID _SceneID)
{
	::Safe_Delete(pSceneState);

	switch (_SceneID)
	{

	}
	
}

void SceneManager::Update()
{
	
}

void SceneManager::Render(HDC _hdc)
{
}

void SceneManager::Release()
{
}
