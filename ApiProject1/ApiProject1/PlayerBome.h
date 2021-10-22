#pragma once
#include "Object.h"

class PlayerBome : public Object
{
private:
	int PLife;
	int PBomb;
	Object* _pPlayer;
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;

	virtual Object* Clone() { return new PlayerBome(*this); }

	PlayerBome();
	~PlayerBome();
};

