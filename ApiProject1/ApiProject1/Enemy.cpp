#include "Enemy.h"
#include "ObjectManager.h"
#include "ObjectFactory.h"
#include "Bridge.h"

void Enemy::Initialize()
{
	TransInfo.Position = Vector3(WindowsWidth / 3, 150);
	TransInfo.Scale = Vector3(41.5f, 41.0f);

	Active = false;
	strKey = "Enemy";

	Frame = 0;
	Hp = 3000;
	Time = GetTickCount64();
}

int Enemy::Update()
{
	if(Time + 1000 < GetTickCount64())
	{
	if (Frame <= 4)
		++Frame;
	else
		Frame = 0;
	Time = GetTickCount64();
	}

	return 0;
}

void Enemy::Render(HDC _hdc)
{
	//Ellipse(_hdc,
	//	int(TransInfo.Position.x - (TransInfo.Scale.x / 2)),
	//	int(TransInfo.Position.y - (TransInfo.Scale.y / 2)),
	//	int(TransInfo.Position.x + (TransInfo.Scale.x / 2)),
	//	int(TransInfo.Position.y + (TransInfo.Scale.y / 2)));

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
