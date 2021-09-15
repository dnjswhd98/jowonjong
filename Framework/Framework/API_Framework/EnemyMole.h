#pragma once
#include "EnemyBridge.h"
#include "Object.h"


class EnemyMole : public EnemyBridge, Object
{
public:

	virtual void Initialize()override;
	virtual int Update(Transform& _rTransInfo)override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;
public:
	EnemyMole();
	virtual ~EnemyMole();
};

