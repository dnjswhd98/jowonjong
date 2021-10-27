#include "PlayerCore.h"
#include "ObjectManager.h"
#include "Player.h"

void PlayerCore::Initialize()
{
	_pPlayer = ObjectManager::GetInstance()->GetPlayer();
	TransInfo.Position = _pPlayer->GetPosition();
	TransInfo.Scale = Vector3(3, 3);
}

int PlayerCore::Update()
{
	TransInfo.Position = _pPlayer->GetPosition();
    return 0;
}

void PlayerCore::Render(HDC _hdc)
{
	Ellipse(_hdc,
		int(TransInfo.Position.x - (TransInfo.Scale.x / 2)),
		int(TransInfo.Position.y - (TransInfo.Scale.y / 2)),
		int(TransInfo.Position.x + (TransInfo.Scale.x / 2)),
		int(TransInfo.Position.y + (TransInfo.Scale.y / 2)));
}

void PlayerCore::Release()
{
}

PlayerCore::PlayerCore()
{
}

PlayerCore::~PlayerCore()
{
}
