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
	TransInfo.Position = Vector3(MaxWidth / 2, 150);
	TransInfo.Scale = Vector3(41.5f, 41.0f);

	Active = false;
	strKey = "Enemy";

	EnemyFrame = 0;
	Count = 0;
	Life = 2;
	Power = 2;
	Bomb = 0;
	Speed = 0.5;
	Time = GetTickCount64();
	FTime = GetTickCount64();
	BulletList = ObjectManager::GetInstance()->GetBulletList();
	_pPlayer = ObjectManager::GetInstance()->GetPlayer();
}

int Enemy::Update()
{
	
	TransInfo.Position.x += direc.x * Speed;
	TransInfo.Position.y += direc.y * Speed;

	if (Active)
	{
		Speed = 1.0f;
		Vector3 TargetPos(MaxWidth / 2, 150);
		direc.x = (TargetPos.x - TransInfo.Position.x) / 50;
		direc.y = (TargetPos.y - TransInfo.Position.y) / 50;
		if (TransInfo.Position.x == MaxWidth / 2)
		{
			Speed = 0;
			
		}
		if (Bomb == 0)
		{
			direc.x = 0;
			direc.y = 0;
			Active = false;
		}
	}
	

	TCount = Count;
	if (Life == 2)
	{
		if (Power == 2)
		{
			if (FTime + 500 < GetTickCount64())
			{
				if (Count == 0)
				{
					Speed = 0.5f;
					if (TransInfo.Position.x < (MaxWidth - MinWidth) / 2)
					{
						direc.x = 1 + rand() % 8;
						if(TransInfo.Position.y < MinHeight + 5)
							direc.y = 2.0;
						else if (TransInfo.Position.y < (MinHeight / 2) + 5)
							direc.y = -2.0;
						else
							direc.y = -2.0 + rand() % 5;
					}
					else
					{
						direc.x = -(1 + rand() % 8);
						if (TransInfo.Position.y < MinHeight + 5)
							direc.y = 2.0;
						else
							direc.y = -2.0 + rand() % 5;
					}
				}
				if (Count < 3)
				{
					Speed -= 0.15f;
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
				else if (Count >= 3 && Count < 5)
				{
					Speed = 0.0f;
					
				}
				else
					Count = -1;

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
					if (Count < 12)
					{
						if (Count == 5 || Count == 10 || Count == 15)
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

						for (int i = 1; i < 4; ++i)
						{
							float cx = sinf((100 - (5 * Count)) * PI / 180);
							float cy = cosf((100 - (5 * Count)) * PI / 180);

							FrameX = 6;
							FrameY = 0;

							TransInfo.Direction = Vector3(cx / (0.5 * i), cy / (0.5 * i));
							BulletList->push_back(CreateBullet<EnemyBullet2>());

							cx = sinf((100 - (5 * Count)) * PI / -180);
							cy = cosf((100 - (5 * Count)) * PI / -180);

							TransInfo.Direction = Vector3(cx / (0.5 * i), cy / (0.5 * i));
							BulletList->push_back(CreateBullet<EnemyBullet2>());
						}
						FTime = GetTickCount64();
						++Count;
					}
					else if (Count >= 12 && Count < 24)
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
						
						Speed = 0.0f;
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

					else if (Count >= 30 && Count < 34);
					else if(Count >= 34 && Count<35)
					{
						if (TransInfo.Position.x < (MaxWidth - MinWidth) / 2)
						{
							direc.x = 1 + rand() % 8;
							if (TransInfo.Position.y < MinHeight + 5)
								direc.y = 2.0;
							else if (TransInfo.Position.y < (MinHeight / 2) + 5)
								direc.y = -2.0;
							else
								direc.y = -2.0 + rand() % 5;
						}
						else
						{
							direc.x = -(1 + rand() % 8);
							if (TransInfo.Position.y < MinHeight + 5)
								direc.y = 2.0;
							else
								direc.y = -2.0 + rand() % 5;
						}
						Speed = 1.0f;
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
					else if (Count >= 43 && Count < 100);

					else
						Count = 0;

					++Count;
					FTime = GetTickCount64();
				}
			}
		}
		else if(Power == 1)
		{
			if (FTime + 500 < GetTickCount64())
			{
				Vector3 BulletPos;
				BulletPos = Vector3(TransInfo.Position.x - (-5.0f + (rand() % 10)), TransInfo.Position.y - (-5.0f + (rand() % 10)));
				for (int i = 1; i < 10; ++i)
				{
					float cx = sinf((((rand() % 180) * i) * PI / 180));
					float cy = cosf((((rand() % 180) * i) * PI / 180));

					FrameX = 6;
					FrameY = 2;
					TransInfo.Direction = Vector3(cx / 2, cy / 2);
					BulletList->push_back(CreateBullet<EnemyBullet>(BulletPos));

				}
				FTime = GetTickCount64();
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

template<typename T>
inline Object* Enemy::CreateBullet(Vector3 _pos)
{
	Bridge* pBridge = new T;

	Object* pBullet = ObjectFactory<Bullet>::CreateObject(_pos, TransInfo.Direction.x, TransInfo.Direction.y, FrameX, FrameY, pBridge);

	return pBullet;
}