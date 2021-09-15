#include "EnemyMole.h"


void EnemyMole::Initialize()
{


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
	//TransparentBlt(_hdc, // ** 최종 출력 위치
	//	int(TransInfo.Position.x - (TransInfo.Scale.x / 2)),
	//	int(TransInfo.Position.y + (TransInfo.Scale.x / 2) - Offset.y - 50),
	//	int(TransInfo.Scale.x),
	//	int(Offset.y),
	//	ImageList["Mole"]->GetMemDC(),
	//	0, 0,
	//	int(TransInfo.Scale.x),
	//	int(Offset.y),
	//	RGB(255, 0, 255));
	Ellipse(_hdc, 100, 100, 100, 100);
		
		
		
		
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
