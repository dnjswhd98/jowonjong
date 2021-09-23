#pragma once
#include "Scene.h"
class Stage : public Scene
{
public:
	virtual void Initialize();
	virtual void Update();
	virtual void Render();
	virtual void Release();

	Stage();
	virtual ~Stage();
};

