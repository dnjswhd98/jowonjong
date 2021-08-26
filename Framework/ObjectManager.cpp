#include "ObjectManager.h"
#include "ObjectFactory.h"
#include "Enemy.h"

ObjectManager* ObjectManager::Instance = nullptr;


void ObjectManager::FindObject()
{
	//DisableList�� �����Ϸ��� ������Ʈ�� �ִ��� Ȯ��
	//�ִٸ� EnableList�� �̵���Ŵ
	//���ٸ� AddObject �Լ� ����
	//�׸��� �ٽ� EnableList�� �̵���Ŵ
}

void ObjectManager::AddObject(string _strKey)
{
	// Ű������ Ž���� Ž���� �Ϸ�� ������� ��ȯ.
	map<string, list<Object*>>::iterator Disableiter = DisableList.find(_strKey);

	for (int i = 0; i < 5; ++i)
	{
		//object ��ü�� ����
		Object* pObj = ObjectFactory<Enemy>::CreateObject();

		if (Disableiter->second.size())
		{
			// ���� ������� �������� �ʴ´ٸ�....
			if (Disableiter == DisableList.end())
			{
				// ** ���ο� ����Ʈ�� ����.
				list<Object*> TempList;

				TempList.push_back(pObj);

				// ** ������Ʈ�� �߰��� ����Ʈ�� �ʿ� ����.
				DisableList.insert(make_pair(_strKey, TempList));
			}
			// ** ������� ���� �Ѵٸ�...
			else
				// ** �ش� ����Ʈ�� ������Ʈ�� �߰�
				Disableiter->second.push_back(pObj);
		}
	}

}

void ObjectManager::Release()
{
	// ** ������ ����.
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
