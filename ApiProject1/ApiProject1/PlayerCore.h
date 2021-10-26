#pragma once
#include "Object.h"

class PlayerCore : public Object
{
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;

	virtual Object* Clone()override { return new PlayerCore(*this); }

	PlayerCore();
	PlayerCore(const Transform& _rTransInfo) : Object(_rTransInfo) { }
	~PlayerCore();
};

