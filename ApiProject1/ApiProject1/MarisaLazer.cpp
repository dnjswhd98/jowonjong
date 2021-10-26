#include "MarisaLazer.h"
#include "Object.h"
#include "ObjectManager.h"
#include "Player.h"

void MarisaLazer::Initialize()
{
	Speed = 0.0;
	DrawKey = "MarisaMissile";
	_pPlayer = ObjectManager::GetInstance()->GetPlayer();
	BTime = GetTickCount64();
}

int MarisaLazer::Update(Transform & _rTransInfo)
{
	if (Speed < 3.0f)
		Speed += 0.1f;
	_rTransInfo.Position.x += _rTransInfo.Direction.x * Speed;
	_rTransInfo.Position.y += _rTransInfo.Direction.y * Speed;

	if (_rTransInfo.Position.y <= (-100))
		return 1;

	return 0;
}

void MarisaLazer::Render(HDC _hdc)
{
	ImageList = Object::GetImageList();
	TransparentBlt(_hdc,
		float(RealObject->GetPosition().x - 5.5f),
		float(RealObject->GetPosition().y - 9.0f),
		11,
		18,
		ImageList[DrawKey]->GetMemDC(),
		0,
		0,
		9,
		16,
		RGB(0, 0, 0));
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
