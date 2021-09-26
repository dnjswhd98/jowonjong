#pragma once
#include "BulletBridge.h"

class MarisaBullet : public BulletBridge
{
protected:
	float Speed;
public:
	virtual void Initialize()override;
	virtual int Update(Transform& _rTransInfo)override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;

	MarisaBullet();
	~MarisaBullet();
};

