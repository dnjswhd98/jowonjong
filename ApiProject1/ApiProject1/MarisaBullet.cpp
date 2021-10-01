#include "MarisaBullet.h"
#include "Object.h"
#include "Bullet.h"

void MarisaBullet::Initialize()
{
	Speed = 10.0f;
	DrawKey = "MarisaBullet";
	
}

int MarisaBullet::Update(Transform& _rTransInfo)
{
	_rTransInfo.Position.x += _rTransInfo.Direction.x * Speed;
	_rTransInfo.Position.y += _rTransInfo.Direction.y * Speed;

	if (_rTransInfo.Position.x >= (WindowsWidth - 100))
		return 1;

	return 0;
}

void MarisaBullet::Render(HDC _hdc)
{
	TransparentBlt(_hdc,
		int(RealObject->GetPosition().x - (RealObject->GetScale().x / 2) + Offset.x),
		int(RealObject->GetPosition().y - (RealObject->GetScale().y / 2) + Offset.y),
		int(RealObject->GetScale().x),
		int(RealObject->GetScale().y),
		ImageList[strKey]->GetMemDC(),
		int(RealObject->GetScale().x * RealObject->Frame),
		int(RealObject->GetScale().y * 0),
		int(RealObject->GetScale().x),
		int(RealObject->GetScale().y),
		RGB(255, 0, 255));
}

void MarisaBullet::Release()
{
}

MarisaBullet::MarisaBullet()
{
}

MarisaBullet::~MarisaBullet()
{
}
