#include "Stage.h"
#include "SceneManager.h"
#include "ObjectManager.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "ObjectFactory.h"
#include "CollisionManager.h"
#include "InputManager.h"


Stage::Stage() : m_pPlayer(nullptr)
{

}

Stage::~Stage()
{
	Release();
}

void Stage::Initialize()
{
	m_pPlayer = ObjectManager::GetInstance()->GetPlayer();

	for (int i = 0; i < 8; ++i)
	{
		Object* pObj = new Enemy;
		pObj->Initialize();

		pObj->SetPosition(
			float(rand() % (WindowsWidth - 120) + 60), 
			float(rand() % (WindowsHeight - 120) + 60));

		EnemyList.push_back(pObj);
	}
	/*
	EnableList = ObjectManager::GetInstance()->GetEnableList();
	DisableList = ObjectManager::GetInstance()->GetDisableList();

	SetTime = ULONGLONG(rand() % 5000 + 3000);
	*/
	Time = GetTickCount64();
}

void Stage::Update()
{
	m_pPlayer->Update();
	//DWORD dwKey = InputManager::GetInstance()->GetKey();
	//if (dwKey & KEY_SPACE)
	//{
	//	Object* bullObj = new Bullet;
	//	bullObj->Initialize();
	//	bullObj->SetPosition(m_pPlayer->GetPosition());
	//	bullObj->SetActive(false);
	//	BulletList.push_back(bullObj);
	//
	//	//for (vector<Object*>::iterator viter = BulletList.begin();
	//	//	viter != BulletList.end();)
	//	for (int i = 0; i < BulletList.size(); ++i)
	//		BulletList[i]->Update();
	//	
	//}

	if (Time + 300 < GetTickCount64())
	{
		Object* bullObj = new Bullet;

		bullObj->Initialize();
		bullObj->SetPosition(m_pPlayer->GetPosition());
		bullObj->SetActive(false);
		BulletList.push_back(bullObj);

		Time = GetTickCount64();
	}

	for (int i = 0; i < BulletList.size(); ++i)
	{
		BulletList[i]->Update();

	//for (vector<Object*>::iterator biter = BulletList.begin();
	//	biter != BulletList.end(); )
	//{
		for (vector<Object*>::iterator iter = EnemyList.begin();
			iter != EnemyList.end(); )
		{
			if (CollisionManager::EllipseCollision(BulletList[i], (*iter)))
			{
				iter = EnemyList.erase(iter);			}
			else
				++iter;
		}
	}
	/*
	for (list<Object*>::iterator iter = EnableList->begin();
		iter != EnableList->end(); )
	{
		int Result = (*iter)->Update();

		if (Result == 1)
		{
			ObjectManager::GetInstance()->RecallObject(*iter);
			iter = EnableList->erase(iter);
		}
		else
			++iter;
	}

	if (Time + SetTime < GetTickCount64())
	{
		for (int i = 0; i < 6; ++i)
		{
			Vector3 vPos = Vector3(float(WindowsWidth - 100), float(i * 110 + 60));
			ObjectManager::GetInstance()->FindObject("Enemy", vPos);
		}
	}
	*/
}

void Stage::Render(HDC _hdc)
{
	m_pPlayer->Render(_hdc);

	for (int i = 0; i < EnemyList.size(); ++i)
		EnemyList[i]->Render(_hdc);
	
	for (int i = 0; i < BulletList.size(); ++i)
		BulletList[i]->Render(_hdc);

	/*
	for (list<Object*>::iterator iter = EnableList->begin();
		iter != EnableList->end(); ++iter)
	{
		(*iter)->Render(_hdc);
	}
	*/
}

void Stage::Release()
{

}
