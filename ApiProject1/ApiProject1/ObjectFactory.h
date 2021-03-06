#pragma once
#include "Object.h"
#include "Bridge.h"

template<typename T>
class ObjectFactory
{
public:
	static Object* CreateObject()
	{
		Object* pObj = new T;
		pObj->Initialize();

		return pObj;
	}

	static Object* CreateObject(Vector3 _vPos)
	{
		Object* pObj = new T;
		pObj->Initialize();
		pObj->SetPosition(_vPos);

		return pObj;
	}

	static Object* CreateObject(float _x, float _y)
	{
		Object* pObj = new T;
		pObj->Initialize();
		pObj->SetPosition(_x, _y);

		return pObj;
	}

	static Object* CreateObject(Vector3 _vPos, Bridge* pBridge)
	{
		Object* pObj = new T;

		pObj->Initialize();
		pObj->SetPosition(_vPos);

		pBridge->SetObject(pObj);
		pBridge->Initialize();

		((T*)pObj)->SetBridge(pBridge);

		return pObj;
	}

	static Object* c(float _x, float _y, Bridge* pBridge)
	{
		Object* pObj = new T;

		pObj->Initialize();
		pObj->SetPosition(_x, _y);

		pBridge->SetObject(pObj);
		pBridge->Initialize();

		((T*)pObj)->SetBridge(pBridge);

		return pObj;
	}

	static Object* CreateObject(Vector3 _vPos, float _Dx, float _Dy, int _frameX, int _frameY, Bridge* pBridge)
	{
		Object* pObj = new T;

		pObj->Initialize();
		pObj->SetPosition(_vPos);
		pObj->SetDirection(_Dx, _Dy);

		pBridge->SetObject(pObj);
		pBridge->SetFrame(_frameX, _frameY);
		pBridge->Initialize();

		((T*)pObj)->SetBridge(pBridge);

		return pObj;
	}
};

