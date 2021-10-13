#pragma once
#include "Object.h"
#include "MathManager.h"

class PlayerSide : public Object
{
private:
	bool Fire;
	int Frame;
	int count;
	float minusX;
	float minusY;
	ULONGLONG time;

	vector<Object*>* BulletList;

	Object* _pPlayer;
public:

	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;

	virtual Object* Clone()override { return new PlayerSide(*this); }

	template <typename T>
	Object* CreateBullet();

	PlayerSide();
	PlayerSide(const Transform& _rTransInfo) : Object(_rTransInfo) { }
	~PlayerSide();
};