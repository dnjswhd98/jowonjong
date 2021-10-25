#pragma once
#include "Headers.h"

class Object;
class Bridge
{
protected:
	string DrawKey;
	int FrameX;
	int FrameY;
	float Speed;
	ULONGLONG ABTime;
	Object* RealObject;
public:
	virtual void Initialize()PURE;
	virtual int Update(Transform& _rTransInfo)PURE;
	virtual void Render(HDC _hdc)PURE;
	virtual void Release()PURE;
public:
	void SetObject(Object* _pObject) { RealObject = _pObject; }
	void SetFrame(int _x, int _y) { FrameX = _x, FrameY = _y; }
	void SetSpeed(float _Speed) { Speed = _Speed; }
	void SetTime(ULONGLONG _time) { ABTime = _time; }
public:
	Bridge();
	virtual ~Bridge();
};

