#pragma once
#include "EnemyBridge.h"

class EnemyBullet2 : public EnemyBridge
{
protected:
	float Speed;
	map<string, Bitmap*> ImageList;

public:
	virtual void Initialize()override;
	virtual int Update(Transform& _rTransInfo)override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;
	EnemyBullet2();
	~EnemyBullet2();

};

