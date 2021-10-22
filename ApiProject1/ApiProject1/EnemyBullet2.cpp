#include "EnemyBullet2.h"
#include "Object.h"

void EnemyBullet2::Initialize()
{
    Speed = 1.0f;
    DrawKey = "EnemyBullet2";
}

int EnemyBullet2::Update(Transform& _rTransInfo)
{
	_rTransInfo.Position.x += _rTransInfo.Direction.x * Speed;
	_rTransInfo.Position.y -= -_rTransInfo.Direction.y * Speed;

	if (_rTransInfo.Position.y >= (WindowsHeight + 100)
		|| _rTransInfo.Position.y <= (-100)
		|| _rTransInfo.Position.x >= (WindowsWidth + 100)
		|| _rTransInfo.Position.x <= (-100)
		)
		return 1;

	return 4;
}

void EnemyBullet2::Render(HDC _hdc)
{
	ImageList = Object::GetImageList();
	TransparentBlt(_hdc,
		int(RealObject->GetPosition().x - 4),
		int(RealObject->GetPosition().y - 4),
		8,
		8,
		ImageList[DrawKey]->GetMemDC(),
		int(8 * FrameX),
		int(8 * FrameY),
		8,
		8,
		RGB(0, 0, 0));
}

void EnemyBullet2::Release()
{
}

EnemyBullet2::EnemyBullet2()
{
}

EnemyBullet2::~EnemyBullet2()
{
}
