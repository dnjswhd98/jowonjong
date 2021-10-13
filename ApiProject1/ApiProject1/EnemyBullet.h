#pragma once
#include "BulletBridge.h"
class EnemyBullet : public BulletBridge
{
protected:
	int Frame;
	float Speed;
	map<string, Bitmap*> ImageList;

public:
	virtual void Initialize()override;
	virtual int Update(Transform& _rTransInfo)override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;
	EnemyBullet();
	~EnemyBullet();
};

