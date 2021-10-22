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
	Life = 3;
	Time = GetTickCount64();
	FTime = GetTickCount64();
	BulletList = ObjectManager::GetInstance()->GetBulletList();
	_pPlayer = ObjectManager::GetInstance()->GetPlayer();
}

int Enemy::Update()
{

	if (FTime + 500 < GetTickCount64())
	{
		if (Count < 3)
		{
			for (int i = 0; i < 25; ++i)
			{

				float _pi = PI;
				float cx = sinf(((14.4 * i) * _pi / 180));
				float cy = cosf(((14.4 * i) * _pi / 180));
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

	


	return 0;
}

void Enemy::Render(HDC _hdc)
{
	TransparentBlt(_hdc,
		int(TransInfo.Position.x - (TransInfo.Scale.x / 2) + Offset.x),
		int(TransInfo.Position.y - (TransInfo.Scale.y / 2) + Offset.y),
		int(TransInfo.Scale.x),
		int(TransInfo.Scale.y),
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