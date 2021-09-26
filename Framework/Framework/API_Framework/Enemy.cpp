#include "Enemy.h"
#include "Bridge.h"
#include "EnemyMole.h"

Enemy::Enemy() : BridgeObject(NULL)
{

}

Enemy::~Enemy()
{

}

void Enemy::Initialize()
{

	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(149.0f, 124.0f);

	Collider.Position = Vector3(0.0f, 0.0f);
	Collider.Scale = Vector3(100.0f, 100.0f);

	Offset = Vector3(149.0f, 0.0f);

	BridgeObject = NULL;

	Active = false;
	strKey = "Mole";
	
	Speed = 1.5f;

	if(BridgeObject)
		BridgeObject->Initialize();
}

int Enemy::Update()
{
	if (BridgeObject)
		BridgeObject->Update(TransInfo);

	return 0;
}

void Enemy::Render(HDC _hdc)
{
	if (BridgeObject)
		BridgeObject->Render(_hdc);

	//TransparentBlt(_hdc, // ** 최종 출력 위치
	//	int(TransInfo.Position.x - (TransInfo.Scale.x / 2)),
	//	int(TransInfo.Position.y + (TransInfo.Scale.x / 2) - Offset.y - 50),
	//	int(TransInfo.Scale.x),
	//	int(Offset.y),
	//	ImageList[strKey]->GetMemDC(),
	//	0, 0,
	//	int(TransInfo.Scale.x),
	//	int(Offset.y),
	//	RGB(255, 0, 255));
}

void Enemy::Release()
{
	delete BridgeObject;
	BridgeObject = nullptr;
}
