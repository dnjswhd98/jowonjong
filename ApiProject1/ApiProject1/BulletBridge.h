#pragma once
#include "Bridge.h"

class BulletBridge : public Bridge
{
protected:
public:
	virtual void Initialize()PURE;
	virtual int Update(Transform& _rTransInfo)PURE;
	virtual void Render(HDC _hdc)PURE;
	virtual void Release()PURE;

	BulletBridge();
	~BulletBridge();
};

