#pragma once
#include "Headers.h"

class Object;
class Prototype;
class ObjectManager
{
private:
	static ObjectManager* Instance;
public:
	static ObjectManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new ObjectManager;

		return Instance;
	}
private:
	Prototype* PrototypeObject;

	Object* pPlayer;

	list<Object*> EnableList;
	vector<Object*> EnemyList;
	vector<Object*> BulletList;
	map<string, list<Object*>> DisableList;
public:
	void Initialize();

	Object* CreateObject(string _Key);

	void FindObject(string _Key);

	Object* CreateObject(string _Key, Vector3 _Position);

	void FindObject(string _Key, Vector3 _Position);

	void AddObject(string _strKey);

	void RecallObject(Object* _Object);

	Object* GetTarget(Vector3 _Pos);


	void Release();
public:
	Object* GetPlayer() { return pPlayer; }
	void SetPlayer(Object* _pPlayer) { pPlayer = _pPlayer; }


	list<Object*>* GetEnableList() { return &EnableList; }
	map<string, list<Object*>>* GetDisableList() { return &DisableList; }


	vector<Object*>* GetBulletList() { return &BulletList; }
	vector<Object*>* GetEnemyList() { return &EnemyList; }

	void AddBullet(Vector3 _vPos);



	list<Object*>* FindList(string _Key)
	{
		map<string, list<Object*>>::iterator iter = DisableList.find(_Key);

		if (iter == DisableList.end())
			return nullptr;

		return &iter->second;
	}
private:
	ObjectManager() : pPlayer(nullptr) { }
public:
	~ObjectManager() { Release(); }
};

