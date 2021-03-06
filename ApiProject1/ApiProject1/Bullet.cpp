#include "Bullet.h"
#include "ObjectManager.h"
#include "MathManager.h"
#include "MarisaBullet.h"
#include "MarisaLazer.h"
#include "EnemyBullet.h"

void Bullet::Initialize()
{
	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Direction = Vector3(0.0f, (-2.0f));
	TransInfo.Scale = Vector3(15.0f, 15.0f);

	BridgeObject = NULL;

	Speed = 1.0;
	strKey = "Bullet";
	Active = false;
	Life = 1;
	BAc = false;
	BTime = GetTickCount64();
	EnemyList = ObjectManager::GetInstance()->GetEnemyList();
	
}

int Bullet::Update()
{
	int re;
	if (BridgeObject)
	{
		re = BridgeObject->Update(TransInfo);
		BridgeObject->SetTime(ATime);
	}

	return re;
}

void Bullet::Render(HDC _hdc)
{
	if (BridgeObject)
		BridgeObject->Render(_hdc);
}

void Bullet::Release()
{
	delete BridgeObject;
	BridgeObject = nullptr;
}

Bullet::Bullet()
{
}

Bullet::~Bullet()
{
	Release();
}
