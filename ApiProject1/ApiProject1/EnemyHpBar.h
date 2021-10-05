#pragma once
#include "Object.h"

class EnemyHpBar : public Object
{
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;

	virtual Object* Clone() { return new EnemyHpBar(*this); }

	EnemyHpBar();
	~EnemyHpBar();
};

