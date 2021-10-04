#pragma once
#include "BulletBridge.h"

class MarisaLazer : public BulletBridge
{
protected:
	float Speed;
	map<string, Bitmap*> ImageList;

public:
	virtual void Initialize()override;
	virtual int Update(Transform& _rTransInfo)override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;
	MarisaLazer();
	~MarisaLazer();
};

