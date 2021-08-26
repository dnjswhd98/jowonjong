#include "ObjectManager.h"
#include "ObjectFactory.h"
#include "Enemy.h"

ObjectManager* ObjectManager::Instance = nullptr;


void ObjectManager::FindObject()
{
	//DisableList에 생성하려는 오브젝트가 있는지 확인
	//있다면 EnableList로 이동시킴
	//없다면 AddObject 함수 실행
	//그리고 다시 EnableList로 이동시킴
}

void ObjectManager::AddObject(string _strKey)
{
	// 키값으로 탐색후 탐색이 완료된 결과물을 반환.
	map<string, list<Object*>>::iterator Disableiter = DisableList.find(_strKey);

	for (int i = 0; i < 5; ++i)
	{
		//object 객체를 생성
		Object* pObj = ObjectFactory<Enemy>::CreateObject();

		if (Disableiter->second.size())
		{
			// 만약 결과물이 존재하지 않는다면....
			if (Disableiter == DisableList.end())
			{
				// ** 새로운 리스트를 생성.
				list<Object*> TempList;

				TempList.push_back(pObj);

				// ** 오브젝트가 추가된 리스트를 맵에 삽입.
				DisableList.insert(make_pair(_strKey, TempList));
			}
			// ** 결과물이 존재 한다면...
			else
				// ** 해당 리스트에 오브젝트를 추가
				Disableiter->second.push_back(pObj);
		}
	}

}

void ObjectManager::Release()
{
	// ** 안전한 삭제.
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

	for (map<string, list<Object*>>::iterator iter = EnableList.begin();
		iter != EnableList.end(); ++iter)
	{
		for (list<Object*>::iterator iter2 = iter->second.begin();
			iter2 != iter->second.end(); ++iter2)
		{
			::Safe_Delete((*iter2));
		}
		iter->second.clear();
	}
	EnableList.clear();
}
