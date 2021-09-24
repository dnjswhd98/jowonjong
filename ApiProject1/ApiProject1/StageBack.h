#pragma once
#include "Object.h"

class StageBack : public Object
{
public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;

	virtual Object* Clone()
	{
		return new StageBack(*this);
	};

	StageBack();
	~StageBack();
};

