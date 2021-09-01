#include "Bullet.h"


Bullet::Bullet() : Count(0)
{

}

Bullet::~Bullet()
{

}


void Bullet::Initialize()
{
	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(30.0f, 30.0f);

	strKey = "Bullet";
	Count = 0;
	Active = false;

	Speed = 5.0f;
}

int Bullet::Update()
{
	TransInfo.Position.x += Speed;
	return 0;
}

void Bullet::Render(HDC _hdc)
{
	Ellipse(_hdc,
		int(TransInfo.Position.x - (TransInfo.Scale.x / 2)),
		int(TransInfo.Position.y - (TransInfo.Scale.x / 2)),
		int(TransInfo.Position.x + (TransInfo.Scale.x / 2)),
		int(TransInfo.Position.y + (TransInfo.Scale.x / 2)));
}

void Bullet::Release()
{

}
