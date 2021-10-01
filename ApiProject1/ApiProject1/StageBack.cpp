#include "StageBack.h"

void StageBack::Initialize()
{
	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Direction = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(0.0f, 0.0f);

	strKey = "Bullet";
	Active = false;
}

int StageBack::Update()
{
	return 0;
}

void StageBack::Render(HDC _hdc)
{
	BitBlt(_hdc,
		0, 0,
		WindowsWidth,
		WindowsHeight,
		ImageList["BackGround"]->GetMemDC(),
		0, 0,
		SRCCOPY);
}

void StageBack::Release()
{
}

StageBack::StageBack()
{
}

StageBack::~StageBack()
{
}
