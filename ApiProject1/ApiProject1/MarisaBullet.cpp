#include "MarisaBullet.h"
#include "Object.h"

void MarisaBullet::Initialize()
{
	Speed = 7.0f;
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
	//Ellipse(_hdc,
	//	int(RealObject->GetPosition().x - (RealObject->GetScale().x / 2)),
	//	int(RealObject->GetPosition().y - (RealObject->GetScale().y / 2)),
	//	int(RealObject->GetPosition().x + (RealObject->GetScale().x / 2)),
	//	int(RealObject->GetPosition().y + (RealObject->GetScale().y / 2)));

	ImageList = Object::GetImageList();
	TransparentBlt(_hdc,
		int(RealObject->GetPosition().x - 7),
		int(RealObject->GetPosition().y - 9),
		14,
		18,
		ImageList[DrawKey]->GetMemDC(),
		int(14 * 0),
		int(18 * 0),
		14,
		18,
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
