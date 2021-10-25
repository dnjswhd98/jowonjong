#pragma once
#include "Object.h"

class ShockWave : public Object
{
private:
	float SPosition;
	float EPosition;
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;

	virtual Object* Clone() { return new ShockWave(*this); }

	ShockWave();
	~ShockWave();
};

