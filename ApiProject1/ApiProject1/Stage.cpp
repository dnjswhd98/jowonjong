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
#include "PlayerBome.h"
#include "Item.h"
#include "ItemNum.h"
#include "GrazeZone.h"

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
	_PlayerBome = new PlayerBome;
	_PlayerBome->Initialize();
	_PowerN = new ItemNum;
	_PowerN->Initialize();
	_PowerN->SetPosition(Vector3(490, 160));
	_ScoreIN = new ItemNum;
	_ScoreIN->Initialize();
	_ScoreIN->SetPosition(Vector3(490, 200));
	_GrazeN = new ItemNum;
	_GrazeN->Initialize();
	_GrazeN->SetPosition(Vector3(490, 180));
	_GrazeZone = new GrazeZone;
	_GrazeZone->Initialize();

	_pPlayer = ObjectManager::GetInstance()->GetPlayer();
	BulletList = ObjectManager::GetInstance()->GetBulletList();
	EnemyList = ObjectManager::GetInstance()->GetEnemyList();
	ItemList = ObjectManager::GetInstance()->GetItemList();
	
	//Vector3 Center = Vector3(WindowsWidth / 3.0f, WindowsHeight / 2.0f);

	for (int i = 0; i < 1; ++i)
	{
		Object* pObj = new Enemy;
		pObj->Initialize();
		Epos = pObj->GetPosition();

		EnemyList->push_back(pObj);
	}
	for (int i = 0; i < 6; ++i)
	{
		Object* IObj = new Item;
		IObj->SetLife(i);
		IObj->Initialize();
		IObj->SetPosition(Epos);
		IObj->SetSpeed(3.0f);
		ItemList->push_back(IObj);
	}
	

	EnemyHp = 100;
	EnemyHpMax = EnemyHp;
	MaxHpBar = _EnemyHpBar->GetScale().x;
	

	S = 0;
	playerLife = 3;
	_pPlayer->SetLife(playerLife);
	_BTime = GetTickCount64();
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
	_PlayerBome->Update();
	_PowerN->Update();
	_PowerN->SetPower(_pPlayer->GetPower());
	_ScoreIN->Update();
	_ScoreIN->SetPower(_pPlayer->GetItem());
	_GrazeN->Update();
	_GrazeN->SetPower(_pPlayer->GetGraze());
	_GrazeZone->Update();

	float MinusHpBar = MaxHpBar / EnemyHpMax;

	_pPlayer->SetLife(playerLife);

	for (vector<Object*>::iterator iter2 = EnemyList->begin();
		iter2 != EnemyList->end(); )
	{
		(*iter2)->Update();
		break;
	}

	for (vector<Object*>::iterator iter = BulletList->begin();
		iter != BulletList->end(); )
	{
		(*iter)->Update();
		break;
	}
	

	for (vector<Object*>::iterator iter = BulletList->begin();
		iter != BulletList->end(); )
	{
		int iResult = (*iter)->Update();

		for (vector<Object*>::iterator iter2 = EnemyList->begin();
			iter2 != EnemyList->end(); )
		{
			
			if ((*iter)->Update() == 3 || (*iter)->Update() == 4)
			{
				if (CollisionManager::EllipseCollision((*iter), _GrazeZone))
				{
					if ((*iter)->GetLife() >= 1)
					{
						_pPlayer->SetGraze(_pPlayer->GetGraze() + 1);
						(*iter)->SetLife(0);
					}
					break;
				}
			}

			if (_BTime + 300 <= GetTickCount64())
			{
				if ((*iter)->Update() == 4)
				{
					Vector3 TargetPos(_pPlayer->GetPosition().x, _pPlayer->GetPosition().y + 500);
					(*iter)->SetDirection(-((*iter)->GetPosition().x - (TargetPos.x)) /500 , -((*iter)->GetPosition().y - TargetPos.y) / 1000);
					break;

				}
				
				_BTime = GetTickCount64();
			}
			

			if (CollisionManager::EllipseCollision((*iter), (*iter2)))
			{
				if ((*iter)->Update() != 3 && (*iter)->Update() != 4)
				{
						EnemyHp--;

						if (EnemyHp <= 0)
						{

							iter2 = EnemyList->erase(iter2);
							_EnemyHpBar->SetScale(_EnemyHpBar->GetScale().x - MinusHpBar, _EnemyHpBar->GetScale().y);
							S += 50010;
							ScoreManager::GetInstance()->SetScore(S);
						}
						//else if (EnemyHp <= 200)
						//{
						//	_EnemyHpBar->SetScale(_EnemyHpBar->GetScale().x - MinusHpBar, _EnemyHpBar->GetScale().y);
						//	S += 10;
						//	ScoreManager::GetInstance()->SetScore(S);
						//}
						else
						{
							_EnemyHpBar->SetScale(_EnemyHpBar->GetScale().x - MinusHpBar, _EnemyHpBar->GetScale().y);
							S += 10;
							ScoreManager::GetInstance()->SetScore(S);
						}


						iResult = 1;

						break;
				}
			}
			else
				++iter2;
		}
		if (iResult == 1)
			iter = BulletList->erase(iter);
		else
			++iter;
	}

	for (vector<Object*>::iterator Iiter = ItemList->begin();
		Iiter != ItemList->end(); )
	{
		(*Iiter)->Update();

		if ((*Iiter)->Update() == 1)
		{
			Iiter = ItemList->erase(Iiter);
			break;
		}

		if (CollisionManager::EllipseCollision((*Iiter), _pPlayer))
		{
			switch ((*Iiter)->GetLife())
			{
			case 0:
				_pPlayer->SetPower(_pPlayer->GetPower() + 1);
				S += 100;
				break;
			case 1:
				_pPlayer->SetItem(_pPlayer->GetItem() + 1);
				S += 200;
				break;
			case 2:
				_pPlayer->SetPower(_pPlayer->GetPower() + 10);
				S += 300;
				break;
			case 3:
				_pPlayer->SetBomb(_pPlayer->GetBomb() + 1);
				S += 400;
				break;
			case 4:
				_pPlayer->SetPower(_pPlayer->GetPower() + 125);
				S += 500;
				break;
			case 5:
				++playerLife;
				S += 600;
				break;
			default:
				break;
			}
			ScoreManager::GetInstance()->SetScore(S);
			Iiter = ItemList->erase(Iiter);
		}
		break;
	}

}

void Stage::Render(HDC _hdc)
{
	_StageBack->Render(ImageList["Buffer"]->GetMemDC());

	for (vector<Object*>::iterator iter = EnemyList->begin();
		iter != EnemyList->end(); ++iter)
		(*iter)->Render(ImageList["Buffer"]->GetMemDC());
	
	_GrazeZone->Render(ImageList["Buffer"]->GetMemDC());
	_pPlayer->Render(ImageList["Buffer"]->GetMemDC());
	_pPSide[0]->Render(ImageList["Buffer"]->GetMemDC());
	_pPSide[1]->Render(ImageList["Buffer"]->GetMemDC());

	for (vector<Object*>::iterator iter = ItemList->begin();
		iter != ItemList->end(); ++iter)
		(*iter)->Render(ImageList["Buffer"]->GetMemDC());
	
	for (vector<Object*>::iterator iter = BulletList->begin();
		iter != BulletList->end(); ++iter)
		(*iter)->Render(ImageList["Buffer"]->GetMemDC());
	
	_StageFront->Render(ImageList["Buffer"]->GetMemDC());

	_PowerN->Render(ImageList["Buffer"]->GetMemDC());
	_ScoreIN->Render(ImageList["Buffer"]->GetMemDC());
	_GrazeN->Render(ImageList["Buffer"]->GetMemDC());

	_PlayerBome->Render(ImageList["Buffer"]->GetMemDC());
	
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
