#include "Bomb.h"
#include "Object.h"
#include "ObjectManager.h"
#include "CollisionManager.h"

void PBomb::Initialize()
{
	Speed = 0.8;
	DrawKey = "SubBomb";
	BulletList = ObjectManager::GetInstance()->GetBulletList();
}

int PBomb::Update(Transform& _rTransInfo)
{
	_rTransInfo.Position.x += _rTransInfo.Direction.x * Speed;
	_rTransInfo.Position.y += _rTransInfo.Direction.y * Speed;

	if (_rTransInfo.Position.y >= (WindowsHeight + 100)
		|| _rTransInfo.Position.y <= (-100)
		|| _rTransInfo.Position.x >= (WindowsWidth + 100)
		|| _rTransInfo.Position.x <= (-100)
		)
		return 1;

	return 5;
}

void PBomb::Render(HDC _hdc)
{
	ImageList = Object::GetImageList();
	TransparentBlt(_hdc,
		int(RealObject->GetPosition().x - 75),
		int(RealObject->GetPosition().y - 75),
		150,
		150,
		ImageList[DrawKey]->GetMemDC(),
		int(64 * FrameX),
		0,
		64,
		64,
		RGB(0, 0, 0));

	
}

void PBomb::Release()
{
}

PBomb::PBomb()
{
}

PBomb::~PBomb()
{
}
