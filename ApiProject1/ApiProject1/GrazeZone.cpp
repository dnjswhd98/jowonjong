#include "GrazeZone.h"
#include "Player.h"
#include "ObjectManager.h"

void GrazeZone::Initialize()
{
	_pPlayer = ObjectManager::GetInstance()->GetPlayer();
	TransInfo.Position = _pPlayer->GetPosition();
	TransInfo.Scale = Vector3(35.0f, 35.0f);

}

int GrazeZone::Update()
{
	TransInfo.Position = _pPlayer->GetPosition();
	return 0;
}

void GrazeZone::Render(HDC _hdc)
{
	Ellipse(_hdc,
		int(TransInfo.Position.x - (TransInfo.Scale.x / 2)),
		int(TransInfo.Position.y - (TransInfo.Scale.y / 2)),
		int(TransInfo.Position.x + (TransInfo.Scale.x / 2)),
		int(TransInfo.Position.y + (TransInfo.Scale.y / 2)));
}

void GrazeZone::Release()
{
}

GrazeZone::GrazeZone()
{
}

GrazeZone::~GrazeZone()
{
}
