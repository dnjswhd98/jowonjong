#pragma once
#include "Object.h"

class PlayerSide : public Object
{
private:
	bool Fire;

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