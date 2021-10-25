#include "ShockWave.h"

void ShockWave::Initialize()
{
	TransInfo.Position = Vector3(-200, -200);
	TransInfo.Scale = Vector3(61, 63);
	strKey = "ShockWave";
	SPosition = EPosition / 2;
	EPosition = 0;
	Life = 1;
	Bomb = 1;
	Item = 1;
	Power = 1;
}

int ShockWave::Update()
{
	if (EPosition < 1000)
	{
		if (Life == 1)
		{
			EPosition += 50;
			SPosition = EPosition / 2;
		}
		else
			TransInfo.Position = Vector3(-200, -200);
	}
	else
	{
		TransInfo.Position = Vector3(-200, -200);
		EPosition = SPosition = 0;
		Life = 0;
	}
    return 0;
}

void ShockWave::Render(HDC _hdc)
{
	TransparentBlt(_hdc,
		int(TransInfo.Position.x - (TransInfo.Scale.x / 2) - SPosition),
		int(TransInfo.Position.y - (TransInfo.Scale.y / 2) - SPosition),
		int(TransInfo.Scale.x + EPosition),
		int(TransInfo.Scale.y + EPosition),
		ImageList[strKey]->GetMemDC(),
		int(0),
		int(0),
		int(TransInfo.Scale.x),
		int(TransInfo.Scale.y),
		RGB(0, 0, 0));
}

void ShockWave::Release()
{
}

ShockWave::ShockWave()
{
}

ShockWave::~ShockWave()
{
}
