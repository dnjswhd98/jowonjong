#pragma once
#include "Headers.h"

class Scene;
class SceneManager
{
private:
	static SceneManager* instance;
public:
	static SceneManager* GetInstance()
	{
		if (instance == nullptr)
			instance = new SceneManager;

		return instance;
	}
private:
	Scene* pSceneState;
public:
	void SetScene(SCENEID _SceneID);
	void Update();
	void Render(HDC _hdc);
	void Release();
private:
	SceneManager() : pSceneState(nullptr) {}
public:
	~SceneManager() { Release(); }
};