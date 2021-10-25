#pragma once
#include "Object.h"

class Bridge;
class Bullet : public Object
{
private:
	bool BAc;
	ULONGLONG BTime;
	Bridge* BridgeObject;

	vector<Object*>* EnemyList;
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;

	virtual Object* Clone()override { return new Bullet(*this); }

	void SetBridge(Bridge* _pBridge) { BridgeObject = _pBridge; }
public:
	Bullet();
	Bullet(const Transform& _rTransInfo) : Object(_rTransInfo) { }
	virtual ~Bullet();
};

