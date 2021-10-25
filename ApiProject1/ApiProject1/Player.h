#pragma once
#include "Object.h"

class Player : public Object
{
private:
	bool Slow;
	float Speed;
	float SlowSpeed;
	int Frame;
	ULONGLONG Time;
	ULONGLONG FTime;

	vector<Object*>* BulletList;
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;

	virtual Object* Clone()override { return new Player(*this); }

	template <typename T>
	Object* CreateBullet();

	Player();
	Player(const Transform& _rTransInfo) : Object(_rTransInfo) { }
	virtual~Player();
};