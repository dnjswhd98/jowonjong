#pragma once
#include "Object.h"

class ScoreManager;
class StageFront : public Object
{
public:
	vector<ScoreManager*> ScoreList;
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;

	virtual Object* Clone() { return new StageFront(*this); }

	StageFront();
	~StageFront();
};

