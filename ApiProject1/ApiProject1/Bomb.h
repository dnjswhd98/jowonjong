#pragma once
#include "BulletBridge.h"

class PBomb : public BulletBridge
{
protected:
	map<string, Bitmap*> ImageList;
	vector<Object*>* BulletList;
public:
	virtual void Initialize()override;
	virtual int Update(Transform& _rTransInfo)override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;
	PBomb();
	~PBomb();
};

