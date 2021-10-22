#pragma once
#include "Object.h"

class ItemNum : public Object
{
private:
	int a;
	int Frame[3];
	UINT Score;
	UINT sScore;
	vector<int> NumberList;

	Object* _pPlayer;
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;

	virtual Object* Clone() { return new ItemNum(*this); }

	ItemNum();
	~ItemNum();
};