#include "Enemy.h"
#include "ObjectManager.h"
#include "ObjectFactory.h"
#include "Bridge.h"

#include "Bullet.h"
#include "EnemyBullet.h"

void Enemy::Initialize()
{
	TransInfo.Position = Vector3(WindowsWidth / 3, 150);
	TransInfo.Scale = Vector3(41.5f, 41.0f);

	Active = false;
	strKey = "Enemy";

	Frame = 0;
	Count = 0;
	Time = GetTickCount64();
	FTime = GetTickCount64();
	BulletList = ObjectManager::GetInstance()->GetBulletList();
}

int Enemy::Update()
{
	if (FTime + 1000 < GetTickCount64())
	{
		for (int i = 0; i < 25; ++i)
		{
			float _pi = PI;
			float cx = sinf(((14.4 * i) * _pi / 180));
			float cy = cosf(((14.4 * i) * _pi / 180));
			TransInfo.Direction = Vector3(cx * 2, cy * 2);
			BulletList->push_back(CreateBullet<EnemyBullet>());
		}

		FTime = GetTickCount64();

	}

	//if(Time + 1 < GetTickCount64())
	//for(int i = 0; i < 15; ++i)
	//{
	//	float _pi = PI;
	//	float cx = sinf((i * _pi / 180));
	//	float cy = cosf((i * _pi / 180));
	//	TransInfo.Direction = Vector3(cx * 2, cy * 2);
	//	Time = GetTickCount64();
	//	
	//}


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
		int(TransInfo.Scale.x * Frame),
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

	Object* pBullet = ObjectFactory<Bullet>::CreateObject(TransInfo.Position, TransInfo.Direction.x, TransInfo.Direction.y, pBridge);

	return pBullet;
}