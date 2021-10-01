#include "Enemy.h"
#include "ObjectManager.h"
#include "ObjectFactory.h"
#include "Bridge.h"

void Enemy::Initialize()
{
	TransInfo.Position = Vector3(WindowsWidth / 2, 150);
	TransInfo.Scale = Vector3(10.0f, 10.0f);
}

int Enemy::Update()
{
	return 0;
}

void Enemy::Render(HDC _hdc)
{
	Ellipse(_hdc,
		int(TransInfo.Position.x - (TransInfo.Scale.x / 2)),
		int(TransInfo.Position.y - (TransInfo.Scale.y / 2)),
		int(TransInfo.Position.x + (TransInfo.Scale.x / 2)),
		int(TransInfo.Position.y + (TransInfo.Scale.y / 2)));
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
