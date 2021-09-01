#include "Enemy.h"


Enemy::Enemy()
{

}

Enemy::~Enemy()
{

}

void Enemy::Initialize()
{
	TransInfo.Position = Vector3(900.0f, 200.0f);
	TransInfo.Scale = Vector3(120.0f, 120.0f);

	Active = false;
}

int Enemy::Update()
{
	return 0;
}

void Enemy::Render(HDC _hdc)
{
	Rectangle(_hdc,
		int(TransInfo.Position.x - (TransInfo.Scale.x / 2)),
		int(TransInfo.Position.y - (TransInfo.Scale.x / 2)),
		int(TransInfo.Position.x + (TransInfo.Scale.x / 2)),
		int(TransInfo.Position.y + (TransInfo.Scale.x / 2)));
}

void Enemy::Release()
{

}
