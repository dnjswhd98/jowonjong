#pragma once
#include "EnemyBridge.h"

class EnemyBullet2 : public EnemyBridge
{
protected:
	bool BAc;
	int CCount;
	float Speed;
	ULONGLONG BTime;

	map<string, Bitmap*> ImageList;
	vector<Object*>* EnemyList;

	Object* _pPlayer;
public:
	virtual void Initialize()override;
	virtual int Update(Transform& _rTransInfo)override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;
	EnemyBullet2();
	~EnemyBullet2();

};

