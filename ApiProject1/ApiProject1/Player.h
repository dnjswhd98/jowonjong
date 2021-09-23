#pragma once
#include "Object.h"

class Player : public Object
{
public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;

	virtual Object* Clone()override { return new Player(*this); }

	Player();
	virtual~Player();
};

