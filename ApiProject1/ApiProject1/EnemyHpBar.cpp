#include "EnemyHpBar.h"

void EnemyHpBar::Initialize()
{
	TransInfo.Position = Vector3(200, 150);
	TransInfo.Scale = Vector3(1, 15);

	Active = false;
	strKey = "HpBar";
}

int EnemyHpBar::Update()
{
	return 0;
}

void EnemyHpBar::Render(HDC _hdc)
{
	TransparentBlt(_hdc,
		int(TransInfo.Position.x - (TransInfo.Scale.x / 2) + Offset.x),
		int(TransInfo.Position.y - (TransInfo.Scale.y / 2) + Offset.y),
		int(TransInfo.Scale.x),
		int(TransInfo.Scale.y),
		ImageList[strKey]->GetMemDC(),
		int(TransInfo.Scale.x * 0),
		int(TransInfo.Scale.y * 0),
		int(TransInfo.Scale.x),
		int(TransInfo.Scale.y),
		RGB(255, 0, 255));
}

void EnemyHpBar::Release()
{
}

EnemyHpBar::EnemyHpBar()
{
}

EnemyHpBar::~EnemyHpBar()
{
}
