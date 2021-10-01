#include "PlayerSide.h"
#include "InputManager.h"
#include "ObjectManager.h"
#include "ObjectFactory.h"

#include "Bullet.h"
#include "Player.h"
#include "MarisaLazer.h"

void PlayerSide::Initialize()
{
	Fire = false;
	_pPlayer = ObjectManager::GetInstance()->GetPlayer();
	TransInfo.Position = Vector3(_pPlayer->GetPosition().x - 30, _pPlayer->GetPosition().y);
	TransInfo.Scale = Vector3(20.0f, 20.0f);

	BulletList = ObjectManager::GetInstance()->GetBulletList();
}

int PlayerSide::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (GetAsyncKeyState('Z') && !Fire)
	{
		BulletList->push_back(CreateBullet<MarisaLazer>());
		Fire = true;
	}
	else
		Fire = false;

	TransInfo.Position = Vector3(_pPlayer->GetPosition().x - 30, _pPlayer->GetPosition().y);

	return 0;
}

void PlayerSide::Render(HDC _hdc)
{
	Ellipse(_hdc,
		int(TransInfo.Position.x - (TransInfo.Scale.x / 2)),
		int(TransInfo.Position.y - (TransInfo.Scale.y / 2)),
		int(TransInfo.Position.x + (TransInfo.Scale.x / 2)),
		int(TransInfo.Position.y + (TransInfo.Scale.y / 2)));
}

void PlayerSide::Release()
{
}

PlayerSide::PlayerSide()
{
}

PlayerSide::~PlayerSide()
{
}

template<typename T>
inline Object * PlayerSide::CreateBullet()
{
	Bridge* pBridge = new T;

	Object* pBullet = ObjectFactory<Bullet>::CreateObject(TransInfo.Position, pBridge);

	return pBullet;
}