#pragma once
#include "Scene.h"

class Object;
class Stage : public Scene
{
private:
	Object* _StageBack;
	Object* _pPlayer;

	vector<Object*>* BulletList;
public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;

	Stage();
	virtual ~Stage();
};

