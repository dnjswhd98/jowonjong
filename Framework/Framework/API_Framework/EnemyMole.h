#pragma once
#include "EnemyBridge.h"
#include "Object.h"

class Enemy;
class EnemyMole : public EnemyBridge, Object
{
public:
	Enemy* enemy;
	virtual void Initialize()override;
	virtual int Update(Transform& _rTransInfo)override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;
public:
	EnemyMole();
	virtual ~EnemyMole();
};

