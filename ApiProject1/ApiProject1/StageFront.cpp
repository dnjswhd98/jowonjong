#include "StageFront.h"

void StageFront::Initialize()
{
	TransInfo.Position = Vector3(WindowsWidth / 2, WindowsHeight / 2 - 20);
	TransInfo.Scale = Vector3(640, 480);

	strKey = "StageUI";
}

int StageFront::Update()
{
	return 0;
}

void StageFront::Render(HDC _hdc)
{
	TransparentBlt(_hdc,
		int(TransInfo.Position.x - (TransInfo.Scale.x / 2) + Offset.x),
		int(TransInfo.Position.y - (TransInfo.Scale.y / 2) + Offset.y),
		int(TransInfo.Scale.x),
		int(TransInfo.Scale.y),
		ImageList[strKey]->GetMemDC(),
		int(TransInfo.Scale.x * 0),
		int(TransInfo.Scale.y * 0),
		int(TransInfo.Scale.x),
		int(TransInfo.Scale.y),
		RGB(255, 0, 255));

	TransparentBlt(_hdc,
		int(30),
		int(10),
		int(46),
		int(16),
		ImageList["EnemyFont"]->GetMemDC(),
		int(0),
		int(0),
		int(46),
		int(16),
		RGB(255, 0, 255));
}

void StageFront::Release()
{
}

StageFront::StageFront()
{
}

StageFront::~StageFront()
{
}
