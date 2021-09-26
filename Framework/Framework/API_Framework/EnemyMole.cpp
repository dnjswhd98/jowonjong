#include "EnemyMole.h"
#include "Enemy.h"

void EnemyMole::Initialize()
{
	//SetObject(enemy);
	RealObject->GetPosition();
	RealObject->GetCollider();
	//TransInfo.Position = Vector3(0.0f, 0.0f);
	//TransInfo.Scale = Vector3(149.0f, 124.0f);
	//
	//Collider.Position = Vector3(0.0f, 0.0f);
	//Collider.Scale = Vector3(100.0f, 100.0f);
	//
	//Offset = Vector3(149.0f, 0.0f);

    DrawKey = "EnemyMole";

	
}

int EnemyMole::Update(Transform& _rTransInfo)
{

	if (!(Offset.y >= 94))
		Offset.y += 2.5f;

	return 0;
}

void EnemyMole::Render(HDC _hdc)
{
	TransparentBlt(_hdc, // ** 최종 출력 위치
		int(TransInfo.Position.x - (TransInfo.Scale.x / 2)),
		int(TransInfo.Position.y + (TransInfo.Scale.x / 2) - Offset.y - 50),
		int(TransInfo.Scale.x),
		int(Offset.y),
		ImageList["Mole"]->GetMemDC(),
		0, 0,
		int(TransInfo.Scale.x),
		int(Offset.y),
		RGB(255, 0, 255));
	//Ellipse(_hdc, 100, 100, 100, 100);
		
		
		
		
}

void EnemyMole::Release()
{
}

EnemyMole::EnemyMole()
{
}

EnemyMole::~EnemyMole()
{
}
