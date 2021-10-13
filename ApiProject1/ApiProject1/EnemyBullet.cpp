#include "EnemyBullet.h"
#include "Object.h"

void EnemyBullet::Initialize()
{
    Speed = 1.0f;
    DrawKey = "EnemyBullet";
}

int EnemyBullet::Update(Transform& _rTransInfo)
{
	_rTransInfo.Position.x += _rTransInfo.Direction.x * Speed;
	_rTransInfo.Position.y -= -_rTransInfo.Direction.y * Speed;

	if (_rTransInfo.Position.y >= (WindowsHeight + 100)
		|| _rTransInfo.Position.y <= (-100)
		|| _rTransInfo.Position.x >= (WindowsWidth + 100)
		|| _rTransInfo.Position.x <= (-100)
		)
		return 1;

	return 3;
}

void EnemyBullet::Render(HDC _hdc)
{
	ImageList = Object::GetImageList();
	TransparentBlt(_hdc,
		int(RealObject->GetPosition().x - 8),
		int(RealObject->GetPosition().y - 8),
		16,
		16,
		ImageList[DrawKey]->GetMemDC(),
		int(16 * 8),
		int(16 * 2),
		16,
		16,
		RGB(0, 0, 0));
}

void EnemyBullet::Release()
{
}

EnemyBullet::EnemyBullet()
{
}

EnemyBullet::~EnemyBullet()
{
}
