#pragma once
#include"Object.h"

class Bridge;
class Enemy : public Object
{
private:
	Bridge* BridgeObject;
	int Frame;
	ULONGLONG Time;
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;

	virtual Object* Clone()override { return new Enemy(*this); }
	void SetBridge(Bridge* _pBridge) { BridgeObject = _pBridge; }

	Enemy();
	Enemy(const Transform& _rTransInfo) : Object(_rTransInfo) { }
	~Enemy();
};

