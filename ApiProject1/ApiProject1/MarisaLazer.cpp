#include "MarisaLazer.h"
#include "Object.h"

void MarisaLazer::Initialize()
{
	Speed = 10.0;
	DrawKey = "MarisaLazer";
	
}

int MarisaLazer::Update(Transform & _rTransInfo)
{
	_rTransInfo.Position.x += _rTransInfo.Direction.x * Speed;
	_rTransInfo.Position.y += _rTransInfo.Direction.y * Speed;

	if (_rTransInfo.Position.y <= (-100))
		return 1;

	ULONGLONG Time = GetTickCount64();
	if (Time + 1000 < GetTickCount64())
	{
		Time = GetTickCount64();
		return 1;
	}

	return 1;
}

void MarisaLazer::Render(HDC _hdc)
{
	//Rectangle(_hdc,
	//	int(RealObject->GetPosition().x - (RealObject->GetScale().x / 2)),
	//	-WindowsHeight,
	//	int(RealObject->GetPosition().x + (RealObject->GetScale().x / 2)),
	//	int(RealObject->GetPosition().y + (RealObject->GetScale().y / 2)));

	ImageList = Object::GetImageList();
	TransparentBlt(_hdc,
		int(RealObject->GetPosition().x - (5/2)),
		int(RealObject->GetPosition().y - 8),
		5,
		16,
		ImageList[DrawKey]->GetMemDC(),
		int(5 * 0),
		int(16 * 0),
		5,
		16,
		RGB(255, 0, 255));
}

void MarisaLazer::Release()
{
}

MarisaLazer::MarisaLazer()
{
}


MarisaLazer::~MarisaLazer()
{
}
