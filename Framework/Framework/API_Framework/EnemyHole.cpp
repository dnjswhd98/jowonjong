#include "EnemyHole.h"
#include "ObjectManager.h"
#include "ObjectFactory.h"
#include "Enemy.h"
#include "EnemyMole.h"

EnemyHole::EnemyHole()
{

}

EnemyHole::~EnemyHole()
{

}


void EnemyHole::Initialize()
{
	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(149.0f, 124.0f);

	Collider.Position = Vector3(0.0f, 0.0f);
	Collider.Scale = Vector3(100.0f, 100.0f);

	Offset = Vector3(149.0f, 0.0f);

	Active = false;
	strKey = "Hole";

	Speed = 0.0f;

	oEnemyMole = new Enemy;
	oEnemyMole->Initialize();

	
	MoleList->push_back(CreateMole<EnemyMole>());
}

//Transform& _TrnasPos
int EnemyHole::Update()
{
	oEnemyMole->SetPosition(TransInfo.Position.x, TransInfo.Position.y);
	oEnemyMole->Update();

	return 0;
}

void EnemyHole::Render(HDC _hdc)
{
	TransparentBlt(_hdc, // ** 최종 출력 위치
		int(TransInfo.Position.x - (TransInfo.Scale.x / 2)),
		int(TransInfo.Position.y - (TransInfo.Scale.y / 2)),
		int(TransInfo.Scale.x),
		int(TransInfo.Scale.y),
		ImageList[strKey]->GetMemDC(),
		0, 0,
		int(TransInfo.Scale.x),
		int(TransInfo.Scale.y),
		RGB(255, 0, 255));

	
}

void EnemyHole::Release()
{

}

template <typename T>
Object* EnemyHole::CreateMole()
{
	Bridge* pBridge = new T;

	Object* pBullet = ObjectFactory<Enemy>::CreateObject(TransInfo.Position, pBridge);

	return pBullet;
}