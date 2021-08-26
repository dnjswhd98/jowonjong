#pragma once
#include "Headers.h"

class Object
{
protected:
	Transform TransInfo;
	string strKey;
	bool Active;
public:
	virtual void Initialize()PURE;
	virtual int Update()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
public:
	string GetKey() { return strKey; }

	bool GetActive() const { return Active; }
	void SetActive(const bool& _Active) { Active = _Active; }

public:
	Object();
	virtual ~Object();
};