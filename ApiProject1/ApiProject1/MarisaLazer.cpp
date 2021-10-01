#include "MarisaLazer.h"
#include "Object.h"

void MarisaLazer::Initialize()
{
	Speed = 5.0;
	DrawKey = "MarisaLazer";
	
}

int MarisaLazer::Update(Transform & _rTransInfo)
{
	_rTransInfo.Position.x = RealObject->GetPosition().x;

	//if (_rTransInfo.Position.y > 0)
	//	return 1;

	ULONGLONG Time = GetTickCount64();
	if (Time + 1000 < GetTickCount64())
	{
		Time = GetTickCount64();
		return 1;
	}

	return 0;
}

void MarisaLazer::Render(HDC _hdc)
{
	Rectangle(_hdc,
		int(RealObject->GetPosition().x - (RealObject->GetScale().x / 2)),
		-WindowsHeight,
		int(RealObject->GetPosition().x + (RealObject->GetScale().x / 2)),
		int(RealObject->GetPosition().y + (RealObject->GetScale().y / 2)));
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
