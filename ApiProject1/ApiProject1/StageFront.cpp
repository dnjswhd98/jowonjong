#include "StageFront.h"
#include "ScoreManager.h"
#include "ItemNum.h"

void StageFront::Initialize()
{
	TransInfo.Position = Vector3(WindowsWidth / 2, WindowsHeight / 2 - 20);
	TransInfo.Scale = Vector3(640, 480);

	ScoreManager::GetInstance()->SetScorePosition(Vector3(600, 60));
	ScoreManager::GetInstance()->Initialize();

	strKey = "StageUI";
}

int StageFront::Update()
{
	ScoreManager::GetInstance()->MakeScoreNumber();
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

#pragma region Fonts

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

	ScoreManager::GetInstance()->Render(_hdc);

	TransparentBlt(_hdc,
		int(420),
		int(60),
		int(31),
		int(17),
		ImageList["ScoreFont"]->GetMemDC(),
		int(0),
		int(0),
		int(31),
		int(17),
		RGB(255, 0, 255));

	TransparentBlt(_hdc,
		int(420),
		int(100),
		int(45),
		int(14),
		ImageList["PlayerFont"]->GetMemDC(),
		int(0),
		int(0),
		int(45),
		int(14),
		RGB(0, 0, 0));

	TransparentBlt(_hdc,
		int(420),
		int(120),
		int(39),
		int(15),
		ImageList["BombFont"]->GetMemDC(),
		int(0),
		int(0),
		int(39),
		int(15),
		RGB(0, 0, 0));

	TransparentBlt(_hdc,
		int(420),
		int(160),
		int(45),
		int(12),
		ImageList["PowerFont"]->GetMemDC(),
		int(0),
		int(0),
		int(45),
		int(12),
		RGB(0, 0, 0));

	TransparentBlt(_hdc,
		int(420),
		int(180),
		int(42),
		int(12),
		ImageList["GrazeFont"]->GetMemDC(),
		int(0),
		int(0),
		int(42),
		int(12),
		RGB(0, 0, 0));

	TransparentBlt(_hdc,
		int(420),
		int(200),
		int(13),
		int(13),
		ImageList["ScoreItemFont"]->GetMemDC(),
		int(0),
		int(0),
		int(13),
		int(13),
		RGB(0, 0, 0));

	TransparentBlt(_hdc,
		int(430),
		int(260),
		int(161),
		int(182),
		ImageList["inGameLogo"]->GetMemDC(),
		int(0),
		int(0),
		int(161),
		int(182),
		RGB(0, 0, 0));
#pragma endregion
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
