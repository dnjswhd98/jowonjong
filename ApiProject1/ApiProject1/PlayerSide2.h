#pragma once
#include "Object.h"

class PlayerSide2 : public Object
{
private:
	bool Fire;
	int Frame;
	int count;
	float minusX;
	float minusY;
	ULONGLONG time;
	ULONGLONG Ftime;

	vector<Object*>* BulletList;

	Object* _pPlayer;
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;

	virtual Object* Clone()override { return new PlayerSide2(*this); }

	template <typename T>
	Object* CreateBullet();

	PlayerSide2();
	PlayerSide2(const Transform& _rTransInfo) : Object(_rTransInfo) { }
	~PlayerSide2();
};

