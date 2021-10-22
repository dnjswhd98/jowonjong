#pragma once
#include "Object.h"

class GrazeZone : public Object
{
private:
	Object* _pPlayer;
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;

	virtual Object* Clone() { return new GrazeZone(*this); }

	GrazeZone();
	~GrazeZone();
};

