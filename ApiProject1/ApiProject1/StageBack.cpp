#include "StageBack.h"

void StageBack::Initialize()
{
	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Direction = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(0.0f, 0.0f);

	strKey = "BackGround";
	Active = false;

	//nY = 0;
	//MapSize = 512;
}

int StageBack::Update()
{
	

	return 0;
}

void StageBack::Render(HDC _hdc)
{
	//BitBlt(_hdc,
	//	0, 0,
	//	WindowsWidth,
	//	WindowsHeight,
	//	ImageList["BackGround"]->GetMemDC(),
	//	0, 0,
	//	SRCCOPY);

	static int nY = 0;
	int MapSize = 1024;

	if (nY < 0)
	{
		BitBlt(_hdc, 0, 0, WindowsWidth, -nY,
			ImageList[strKey]->GetMemDC(),0, MapSize + nY, SRCCOPY);
		BitBlt(_hdc, 0, -nY, WindowsWidth, WindowsHeight + nY,
			ImageList[strKey]->GetMemDC(), 0, 0, SRCCOPY);
	}
	else
		BitBlt(_hdc, 0, 0, WindowsWidth, WindowsHeight,
			ImageList[strKey]->GetMemDC(), 0, nY, SRCCOPY);
	
	nY -= 4;
	if (nY + WindowsHeight <= 0)
		nY += MapSize;
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
