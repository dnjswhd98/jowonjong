#pragma once
#include "Object.h"
class EnemyHole : public Object
{
private:
	Object* oEnemyMole;
	vector<Object*>* MoleList;
public:

	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;

	virtual Object* Clone()override { return new EnemyHole(*this); }

	template <typename T>
	Object* CreateMole();
public:
	EnemyHole();
	EnemyHole(const Transform& _rTransInfo) : Object(_rTransInfo) { }
	virtual ~EnemyHole();
};
