#pragma once
#include "BulletBridge.h"
class EnemyBullet : public BulletBridge
{
protected:
	bool BAc;
	ULONGLONG BTime;
	map<string, Bitmap*> ImageList;
	vector<Object*>* EnemyList;

	Object* _pPlayer;
public:
	virtual void Initialize()override;
	virtual int Update(Transform& _rTransInfo)override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;
	EnemyBullet();
	~EnemyBullet();
};

