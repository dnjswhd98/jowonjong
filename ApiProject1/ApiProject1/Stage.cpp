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
#include "ShockWave.h"

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
	_ShockWave = new ShockWave;
	_ShockWave->Initialize();

	_pPlayer = ObjectManager::GetInstance()->GetPlayer();
	BulletList = ObjectManager::GetInstance()->GetBulletList();
	EnemyList = ObjectManager::GetInstance()->GetEnemyList();
	ItemList = ObjectManager::GetInstance()->GetItemList();
	

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
		IObj->SetSpeed(2.0f);
		ItemList->push_back(IObj);
	}
	

	EnemyHp = 100;
	EnemyHpMax = EnemyHp;
	MaxHpBar = _EnemyHpBar->GetScale().x;
	HitCount = 0;
	Tcount = 0;

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

	

	for (vector<Object*>::iterator iter = EnemyList->begin();
		iter != EnemyList->end(); )
	{
		(*iter)->Update();
		if ((*iter)->GetPower() < 2 || (*iter)->GetLife() < 2)
			_ShockWave->Update();
		
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

		if (iResult == 4)
		{
			(*iter)->SetSpeed((*iter)->GetSpeed() - 0.5f);
		}
		
		for (vector<Object*>::iterator iter2 = EnemyList->begin();
			iter2 != EnemyList->end(); )
		{
			if ((*iter2)->GetPower() == 1 && (*iter2)->GetLife() == 2)
			{
				if (_ShockWave->GetPower() == 1)
				{
					(*iter2)->SetActive(true);
					_ShockWave->SetPower(0);
					_ShockWave->SetPosition((*iter2)->GetPosition());
					Tcount = 0;
				}
				else
				{
					if (_BTime + 1000 < GetTickCount64())
					{
						++Tcount;
						_BTime = GetTickCount64();
					}
					if (Tcount < 3)
					{
						if ((*iter)->Update() == 3 || (*iter)->Update() == 4)
							iResult = 1;
					}

				}
			}
			if ((*iter2)->GetLife() == 1)
			{
				if (_ShockWave->GetBomb() == 1)
				{
					_ShockWave->SetLife(1);
					_ShockWave->SetPosition((*iter2)->GetPosition());
					Tcount = 0;
					(*iter2)->SetBomb(100);
					_ShockWave->SetBomb(0);
				}
				else
				{
					if (_BTime + 1000 < GetTickCount64())
					{
						++Tcount;
						_BTime = GetTickCount64();
					}
					if (Tcount < 3)
					{
						if ((*iter)->Update() == 3 || (*iter)->Update() == 4)
							iResult = 1;
					}
				}
			}
			if ((*iter2)->GetPower() == 1 && (*iter2)->GetLife() == 1)
			{
				if (_ShockWave->GetItem() == 1)
				{
					_ShockWave->SetLife(1);
					_ShockWave->SetPosition((*iter2)->GetPosition());
					Tcount = 0;
					(*iter2)->SetBomb(100);
					_ShockWave->SetItem(0);
				}
				else
				{
					if (_BTime + 1000 < GetTickCount64())
					{
						++Tcount;
						_BTime = GetTickCount64();
					}
					if (Tcount < 3)
					{
						if ((*iter)->Update() == 3 || (*iter)->Update() == 4)
							iResult = 1;
					}
				}
			}
			if ((*iter2)->GetTimeCount() == 30)
			{

				_ShockWave->SetPosition((*iter2)->GetPosition());
				_ShockWave->SetLife(1);
			}
			if ((*iter2)->GetTimeCount() == 50)
			{

				_ShockWave->SetPosition((*iter2)->GetPosition());
				_ShockWave->SetLife(1);
			}

			
			
			if ((*iter)->Update() == 3 || (*iter)->Update() == 4)
			{
				if (CollisionManager::EllipseCollision((*iter), _GrazeZone))
				{
					if ((*iter)->GetLife() >= 1)
					{
						_pPlayer->SetGraze(_pPlayer->GetGraze() + 1);
						(*iter)->SetLife(0);
					}
				}
				
				//if (CollisionManager::EllipseCollision(_ShockWave, (*iter)))
				//{
				//	iResult = 1;
				//}
			}
			
			if (CollisionManager::EllipseCollision((*iter), (*iter2)))
			{
				if ((*iter2)->GetBomb() <= 0)
				{
					if ((*iter)->Update() != 3 && (*iter)->Update() != 4)
					{
						if (EnemyHp <= 0)
						{
							EnemyHp--;
							S += 50010;
							if ((*iter2)->GetLife() > 1)
							{
								(*iter2)->SetLife((*iter2)->GetLife() - 1);
								(*iter2)->SetPower(2);
								_EnemyHpBar->SetScale(280, 5);
								EnemyHp = EnemyHpMax;
							}
							else
							{
								iter2 = EnemyList->erase(iter2);
								_EnemyHpBar->SetScale(_EnemyHpBar->GetScale().x - MinusHpBar, _EnemyHpBar->GetScale().y);
							}
						}
						else if (EnemyHp <= (EnemyHpMax / 4) && EnemyHp > 0)
						{
							++HitCount;
							S += 10;
							(*iter2)->SetPower(1);
							if (HitCount == 5)
							{
								EnemyHp--;
								_EnemyHpBar->SetScale(_EnemyHpBar->GetScale().x - MinusHpBar, _EnemyHpBar->GetScale().y);
								HitCount = 0;
							}
						}
						else
						{
							EnemyHp--;
							_EnemyHpBar->SetScale(_EnemyHpBar->GetScale().x - MinusHpBar, _EnemyHpBar->GetScale().y);
							S += 10;
						}


						iResult = 1;

					}
				}
			}
			else
				++iter2;
			break;
		}
		if (iResult == 1)
			iter = BulletList->erase(iter);
		else
			++iter;
	}

	for (vector<Object*>::iterator Iiter = ItemList->begin();
		Iiter != ItemList->end();)
	{
		int Re = (*Iiter)->Update();

	

		if (CollisionManager::EllipseCollision((*Iiter), _pPlayer))
		{
			switch ((*Iiter)->GetLife())
			{
			case 0:
				_pPlayer->SetPower(_pPlayer->GetPower() + 1);
				S += 10;
				break;
			case 1:
				_pPlayer->SetItem(_pPlayer->GetItem() + 1);
				S += (10 * (2 * (MaxHeight - _pPlayer->GetPosition().y)));
				break;
			case 2:
				_pPlayer->SetPower(_pPlayer->GetPower() + 10);
				S += 10;
				break;
			case 3:
				_pPlayer->SetBomb(_pPlayer->GetBomb() + 1);
				break;
			case 4:
				if (_pPlayer->GetPower() < 128)
					_pPlayer->SetPower(_pPlayer->GetPower() + 128);
				if (_pPlayer->GetPower() >= 128)
					S += 1000;
				break;
			case 5:
				++playerLife;
				break;
			default:
				break;
			}
			Re = 1;
		}
		if (Re == 1)
		{
			Iiter = ItemList->erase(Iiter);
			break;
		}
		else
			++Iiter;
		
	}

	

	ScoreManager::GetInstance()->SetScore(S);
}

void Stage::Render(HDC _hdc)
{
	_StageBack->Render(ImageList["Buffer"]->GetMemDC());

	_ShockWave->Render(ImageList["Buffer"]->GetMemDC());

	for (vector<Object*>::iterator iter = EnemyList->begin();
		iter != EnemyList->end(); ++iter)
		(*iter)->Render(ImageList["Buffer"]->GetMemDC());
	
	//_GrazeZone->Render(ImageList["Buffer"]->GetMemDC());
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
