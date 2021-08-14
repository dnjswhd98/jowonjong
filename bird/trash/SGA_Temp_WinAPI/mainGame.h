#pragma once
#include "gameNode.h"

#include "SceneMenu.h"
#include "SceneCastleCorrior.h"

#define SCENE_INDEX 2

class mainGame : public gameNode
{
private:
	void TransitionScene(int nIndex);
	int PreviousScene = 0;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	mainGame() {}
	~mainGame() {}
};

