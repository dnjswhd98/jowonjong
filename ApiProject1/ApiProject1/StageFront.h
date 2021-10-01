#pragma once
#include "Object.h"
class StageFront : public Object
{
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;

	StageFront();
	~StageFront();
};

