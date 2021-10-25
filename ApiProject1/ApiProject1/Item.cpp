#include "Item.h"

void Item::Initialize()
{
	switch (Life)
	{
	case 0:
		TransInfo.Scale = Vector3(12, 12);
		Frame = 0;
		strKey = "Item1";
		break;
	case 1:
		TransInfo.Scale = Vector3(12, 12);
		Frame = 1;
		strKey = "Item1";
		break;
	case 2:
		TransInfo.Scale = Vector3(16, 16);
		Frame = 0;
		strKey = "Item2";
		break;
	case 3:
		TransInfo.Scale = Vector3(16, 16);
		Frame = 1;
		strKey = "Item2";
		break;
	case 4:
		TransInfo.Scale = Vector3(16, 16);
		Frame = 2;
		strKey = "Item2";
		break;
	case 5:
		TransInfo.Scale = Vector3(16, 16);
		Frame = 3;
		strKey = "Item2";
		break;
	case6:
		TransInfo.Scale = Vector3(10, 10);
		Frame = 0;
		strKey = "BulletSItem";
		break;
	default:
		break;
	}
	

	Time = GetTickCount64();
	TransInfo.Direction = Vector3(0.0f, -1.0f);
}

int Item::Update()
{
	if (TransInfo.Position.y >= (WindowsHeight + 100)
		|| TransInfo.Position.y <= (-100)
		|| TransInfo.Position.x >= (WindowsWidth + 100)
		|| TransInfo.Position.x <= (-100)
		)
		return 1;

	//TransInfo.Position.x += TransInfo.Direction.x * Speed;
	TransInfo.Position.y += TransInfo.Direction.y * Speed;
	if (Time + 100 < GetTickCount64())
	{
		if (Speed > -2.0f)
			Speed -= 0.5f;
		
		Time = GetTickCount64();
	}
    return 0;
}

void Item::Render(HDC _hdc)
{
	TransparentBlt(_hdc,
		int(TransInfo.Position.x - (TransInfo.Scale.x / 2) + Offset.x),
		int(TransInfo.Position.y - (TransInfo.Scale.y / 2) + Offset.y),
		int(TransInfo.Scale.x),
		int(TransInfo.Scale.y),
		ImageList[strKey]->GetMemDC(),
		int(TransInfo.Scale.x * Frame),
		int(0),
		int(TransInfo.Scale.x),
		int(TransInfo.Scale.y),
		RGB(0, 0, 0));
}

void Item::Release()
{
}

Item::Item()
{
}

Item::~Item()
{
}
