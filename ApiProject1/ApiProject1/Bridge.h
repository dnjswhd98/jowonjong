#pragma once
#include "Headers.h"

class Object;
class Bridge
{
protected:
	string DrawKey;
	int FrameX;
	int FrameY;
	Object* RealObject;
public:
	virtual void Initialize()PURE;
	virtual int Update(Transform& _rTransInfo)PURE;
	virtual void Render(HDC _hdc)PURE;
	virtual void Release()PURE;
public:
	void SetObject(Object* _pObject) { RealObject = _pObject; }
	void SetFrame(float _x, float _y) { FrameX = _x, FrameY = _y; }
public:
	Bridge();
	virtual ~Bridge();
};

