#include "ObjectManager.h"
#include "MathManager.h"
#include "ObjectFactory.h"
#include "Prototype.h"

#include "Bullet.h"

ObjectManager* ObjectManager::Instance = nullptr;

void ObjectManager::Initialize()
{
    PrototypeObject = new Prototype;
    PrototypeObject->CreatePrototype();
}

Object* ObjectManager::CreateObject(string _Key)
{
	Object* pProtoObject = PrototypeObject->FindPrototypeObject(_Key);

	if (pProtoObject == nullptr)
		return nullptr;
	else
	{
		Object* pObject = pProtoObject->Clone();
		pObject->Initialize();

		return pObject;
	}
}

void ObjectManager::FindObject(string _Key)
{
	map<string, list<Object*>>::iterator iter = DisableList.find(_Key);

	if (iter == DisableList.end() || iter->second.empty())
	{
		Object* pObject = CreateObject(_Key);

		if (pObject == nullptr)
			return;

		EnableList.push_back(pObject);
	}
	else
	{
		Object* pObject = iter->second.front();
		pObject->Initialize();

		EnableList.push_back(pObject);
		iter->second.pop_front();
	}
}

Object* ObjectManager::CreateObject(string _Key, Vector3 _Position)
{
	Object* pProtoObject = PrototypeObject->FindPrototypeObject(_Key);

	if (pProtoObject == nullptr)
		return nullptr;
	else
	{
		Object* pObject = pProtoObject->Clone();
		pObject->Initialize();
		pObject->SetPosition(_Position);

		return pObject;
	}
}

void ObjectManager::FindObject(string _Key, Vector3 _Position)
{
	map<string, list<Object*>>::iterator iter = DisableList.find(_Key);

	if (iter == DisableList.end() || iter->second.empty())
	{
		Object* pObject = CreateObject(_Key, _Position);

		if (pObject == nullptr)
			return;

		EnableList.push_back(pObject);
	}
	else
	{
		Object* pObject = iter->second.front();
		pObject->Initialize();
		pObject->SetPosition(_Position);

		EnableList.push_back(pObject);

		iter->second.pop_front();
	}
}

void ObjectManager::AddObject(string _strKey)
{
}

void ObjectManager::RecallObject(Object* _Object)
{
	map<string, list<Object*>>::iterator iter = DisableList.find(_Object->GetKey());

	if (iter == DisableList.end())
	{
		list<Object*> TempList;

		TempList.push_back(_Object);

		DisableList.insert(make_pair(_Object->GetKey(), TempList));
	}
	else
		iter->second.push_back(_Object);
}

Object* ObjectManager::GetTarget(Vector3 _Pos)
{
    return nullptr;
}

void ObjectManager::Release()
{
	::Safe_Delete(pPlayer);

	for (map<string, list<Object*>>::iterator iter = DisableList.begin();
		iter != DisableList.end(); ++iter)
	{
		for (list<Object*>::iterator iter2 = iter->second.begin();
			iter2 != iter->second.end(); ++iter2)
		{
			::Safe_Delete((*iter2));
		}
		iter->second.clear();
	}
	DisableList.clear();

	for (list<Object*>::iterator iter = EnableList.begin();
		iter != EnableList.end(); ++iter)
	{
		::Safe_Delete((*iter));
	}
	EnableList.clear();
}

void ObjectManager::AddBullet(Vector3 _vPos)
{
	BulletList.push_back(
		ObjectFactory<Bullet>::CreateObject(_vPos));
}