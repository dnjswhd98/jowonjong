#include "Stage.h"
#include "SceneManager.h"
#include "ObjectManager.h"
#include "ObjectFactory.h"
#include "CollisionManager.h"
#include "ScoreManager.h"

#include "StageBack.h"
#include "StageFront.h"
#include "Player.h"
#include "PlayerSide.h"
#include "PlayerSide2.h"
#include "Enemy.h"
#include "EnemyHpBar.h"

void Stage::Initialize()
{
	_StageBack = new StageBack;
	_StageBack->Initialize();
	_StageFront = new StageFront;
	_StageFront->Initialize();
	_pPSide[0] = new PlayerSide;
	_pPSide[0]->Initialize();
	_pPSide[1] = new PlayerSide2;
	_pPSide[1]->Initialize();
	_EnemyHpBar = new EnemyHpBar;
	_EnemyHpBar->Initialize();

	_pPlayer = ObjectManager::GetInstance()->GetPlayer();
	BulletList = ObjectManager::GetInstance()->GetBulletList();
	EnemyList = ObjectManager::GetInstance()->GetEnemyList();
	
	//Vector3 Center = Vector3(WindowsWidth / 3.0f, WindowsHeight / 2.0f);

	for (int i = 0; i < 1; ++i)
	{
		Object* pObj = new Enemy;
		pObj->Initialize();

		EnemyList->push_back(pObj);
	}

	EnemyHp = 1000;
	EnemyHpMax = EnemyHp;
	MaxHpBar = _EnemyHpBar->GetScale().x;
	S = 0;
	ScoreManager::GetInstance()->SetScore(S);

	ImageList = Object::GetImageList();
}

void Stage::Update()
{
	
	_StageBack->Update();
	_StageFront->Update();
	_pPlayer->Update();
	_pPSide[0]->Update();
	_pPSide[1]->Update();

	float MinusHpBar = MaxHpBar / EnemyHpMax;

	for (vector<Object*>::iterator iter2 = EnemyList->begin();
		iter2 != EnemyList->end(); )
	{
		(*iter2)->Update();
		break;
	}

	for (vector<Object*>::iterator iter = BulletList->begin();
		iter != BulletList->end(); )
	{
		int iResult = (*iter)->Update();


		for (vector<Object*>::iterator iter2 = EnemyList->begin();
			iter2 != EnemyList->end(); )
		{
			if ((*iter)->Update() == 3)
			{
				break;
			}

			if (CollisionManager::EllipseCollision((*iter), (*iter2)))
			{
				EnemyHp--;
				if (EnemyHp <= 0)
				{
					iter2 = EnemyList->erase(iter2);
					_EnemyHpBar->SetScale(_EnemyHpBar->GetScale().x - MinusHpBar, _EnemyHpBar->GetScale().y);
					S += 50010;
					ScoreManager::GetInstance()->SetScore(S);
				}
				else
				{
					_EnemyHpBar->SetScale(_EnemyHpBar->GetScale().x - MinusHpBar, _EnemyHpBar->GetScale().y);
					S += 10;
					ScoreManager::GetInstance()->SetScore(S);
				}
					

				iResult = 1;

				break;
			}
			else
				++iter2;
		}
		if (iResult == 1)
			iter = BulletList->erase(iter);
		else
			++iter;
	}
}

void Stage::Render(HDC _hdc)
{
	_StageBack->Render(ImageList["Buffer"]->GetMemDC());

	for (vector<Object*>::iterator iter = EnemyList->begin();
		iter != EnemyList->end(); ++iter)
		(*iter)->Render(ImageList["Buffer"]->GetMemDC());
	
	for (vector<Object*>::iterator iter = BulletList->begin();
		iter != BulletList->end(); ++iter)
		(*iter)->Render(ImageList["Buffer"]->GetMemDC());
	
	_pPlayer->Render(ImageList["Buffer"]->GetMemDC());
	_pPSide[0]->Render(ImageList["Buffer"]->GetMemDC());
	_pPSide[1]->Render(ImageList["Buffer"]->GetMemDC());
	
	_StageFront->Render(ImageList["Buffer"]->GetMemDC());
	
	_EnemyHpBar->Render(ImageList["Buffer"]->GetMemDC());
	
	BitBlt(_hdc,
		0, 0,
		WindowsWidth,
		WindowsHeight,
		ImageList["Buffer"]->GetMemDC(),
		0, 0,
		SRCCOPY);
}

void Stage::Release()
{
}

Stage::Stage() : _pPlayer(nullptr)
{
}

Stage::~Stage()
{
	Release();
}
