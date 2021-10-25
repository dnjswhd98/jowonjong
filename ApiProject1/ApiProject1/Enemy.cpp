#include "Enemy.h"
#include "ObjectManager.h"
#include "ObjectFactory.h"
#include "MathManager.h"
#include "Bridge.h"

#include "Player.h"
#include "Bullet.h"
#include "EnemyBullet.h"
#include "EnemyBullet2.h"

void Enemy::Initialize()
{
	TransInfo.Position = Vector3(WindowsWidth / 3, 150);
	TransInfo.Scale = Vector3(41.5f, 41.0f);

	Active = false;
	strKey = "Enemy";

	EnemyFrame = 0;
	Count = 0;
	Life = 2;
	Power = 2;
	Bomb = 150;
	Time = GetTickCount64();
	FTime = GetTickCount64();
	BulletList = ObjectManager::GetInstance()->GetBulletList();
	_pPlayer = ObjectManager::GetInstance()->GetPlayer();
}

int Enemy::Update()
{
	if (Life == 2)
	{
		if (Power == 2)
		{
			if (FTime + 500 < GetTickCount64())
			{
				if (Count < 3)
				{
					for (int i = 0; i < 25; ++i)
					{
						float cx = sinf(((14.4 * i) * PI / 180));
						float cy = cosf(((14.4 * i) * PI / 180));
						if (Count < 2)
						{
							FrameX = 8;
							FrameY = 2;
							TransInfo.Direction = Vector3(cx / 2, cy / 2);
							BulletList->push_back(CreateBullet<EnemyBullet>());
						}
						else
						{
							FrameX = 0;
							FrameY = 0;
							TransInfo.Direction = Vector3(cx / 2, cy / 2);
							BulletList->push_back(CreateBullet<EnemyBullet2>());
						}
					}
				}
				else if (Count == 4)
					Count = -1;
				else;

				++Count;
				FTime = GetTickCount64();
			}
		}
		else if (Power == 1)
		{
			if (FTime + 500 < GetTickCount64())
			{
				if (Bomb >= 0)
				{
					--Bomb;
					Count = 0;
				}
				else
				{
					if (Count < 13)
					{
						if (Count == 5 || Count == 10)
						{
							for (int i = 1; i < 6; ++i)
							{
								float cx = sinf(((-54 + (18 * i)) * PI / 180));
								float cy = cosf(((-54 + (18 * i)) * PI / 180));
								//13
								FrameX = 13;
								FrameY = 2;
								TransInfo.Direction = Vector3(cx, cy);
								BulletList->push_back(CreateBullet<EnemyBullet>());
							}
						}

						for (int i = 0; i < 3; ++i)
						{
							float cx = sinf((88 - (5 * Count)) * PI / 180);
							float cy = cosf((88 - (5 * Count)) * PI / 180);

							FrameX = 6;
							FrameY = 0;

							TransInfo.Direction = Vector3(cx / (1 + i), cy / (1 + i));
							BulletList->push_back(CreateBullet<EnemyBullet2>());

							cx = sinf((88 - (5 * Count)) * PI / -180);
							cy = cosf((88 - (5 * Count)) * PI / -180);

							TransInfo.Direction = Vector3(cx / (1 + i), cy / (1 + i));
							BulletList->push_back(CreateBullet<EnemyBullet2>());
						}
						FTime = GetTickCount64();
						++Count;
					}
					else if (Count >= 5 && Count < 7)
						++Count;
					else
					{
						Count = 1;
					}
				}
				
			}
		}
	}
	else if (Life == 1)
	{
		if (Power == 2)
		{
			if (Bomb >= 0)
			{
				--Bomb;
				Count = 0;
			}
			else
			{
				if (FTime + 150 < GetTickCount64())
				{
					if (Count < 30)
					{
						for (int i = 1; i < 9; ++i)
						{
							float cx = sinf((((rand() % 180) * i) * PI / 180));
							float cy = cosf((((rand() % 180) * i) * PI / 180));

							FrameX = 4 + rand() % 10;
							FrameY = 1;
							TransInfo.Direction = Vector3(cx, cy);
							BulletList->push_back(CreateBullet<EnemyBullet>());

						}
					}
					else if (Count >= 30 && Count < 35)
					{
						
					}
					else if (Count >= 35 && Count < 43)
					{
						for (int i = 1; i < 8; ++i)
						{
							float cx = sinf(((-55 + (15 * i)) * PI / 180));
							float cy = cosf(((-55 + (15 * i)) * PI / 180));

							FrameX = 6;
							FrameY = 2;

							TransInfo.Direction = Vector3(cx, cy);
							BulletList->push_back(CreateBullet<EnemyBullet>());
						}
					}
					else if (Count >= 43 && Count < 60);

					else
						Count = 0;

					++Count;
					FTime = GetTickCount64();
				}
			}
		}
	}

	return 0;
}

void Enemy::Render(HDC _hdc)
{
	TransparentBlt(_hdc,
		int(TransInfo.Position.x - (TransInfo.Scale.x / 2) + Offset.x),
		int(TransInfo.Position.y - (TransInfo.Scale.y / 2) + Offset.y),
		int(TransInfo.Scale.x - 10),
		int(TransInfo.Scale.y - 10),
		ImageList[strKey]->GetMemDC(),
		int(TransInfo.Scale.x * EnemyFrame),
		int(TransInfo.Scale.y * 0),
		int(TransInfo.Scale.x),
		int(TransInfo.Scale.y),
		RGB(255, 0, 255));

	//if (BridgeObject)
	//	BridgeObject->Render(_hdc);
}

void Enemy::Release()
{
	
}

Enemy::Enemy()
{
}


Enemy::~Enemy()
{
}

template<typename T>
inline Object* Enemy::CreateBullet()
{
	Bridge* pBridge = new T;

	Object* pBullet = ObjectFactory<Bullet>::CreateObject(TransInfo.Position, TransInfo.Direction.x, TransInfo.Direction.y, FrameX, FrameY, pBridge);

	return pBullet;
}