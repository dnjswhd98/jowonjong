#pragma once
#include "Object.h"
class Item : public Object
{
private:
	int ItemNum;
	int Frame;

	ULONGLONG Time;
	Object* _pPlayer;
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;

	virtual Object* Clone()override { return new Item(*this); }

	Item();
	Item(const Transform& _rTransInfo) : Object(_rTransInfo) { }
	~Item();
};

