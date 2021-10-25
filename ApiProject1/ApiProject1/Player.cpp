#include "Player.h"
#include "InputManager.h"
#include "ObjectManager.h"
#include "ObjectFactory.h"

#include "Bullet.h"
#include "MarisaBullet.h"
#include "MarisaLazer.h"
#include "PlayerSide.h"

void Player::Initialize()
{
	TransInfo.Position = Vector3(WindowsWidth / 3, (WindowsHeight / 2) + 150);
	TransInfo.Scale = Vector3(29.0f, 44.0f);

	Slow = false;
	Speed = 3.0f;
	SlowSpeed = 2.0f;
	Frame = 0;

	strKey = "Marisa";
	Life = 2;
	Bomb = 3;
	Power = 0;
	Item = 0;
	Graze = 0;

	BulletList = ObjectManager::GetInstance()->GetBulletList();
	Time = GetTickCount64();
	FTime = GetTickCount64();
}

int Player::Update()
{
	if (Time + 100 < GetTickCount64())
	{
		if (Frame <= 2)
			++Frame;
		else
			Frame = 0;
		Time = GetTickCount64();
	}

	DWORD dwKey = InputManager::GetInstance()->GetKey();		

	if (!GetAsyncKeyState(VK_SHIFT))
	{
		Slow = false;

		if (GetAsyncKeyState(VK_UP))
		{
			TransInfo.Position.y -= Speed;
		}
		if (GetAsyncKeyState(VK_DOWN))
		{
			TransInfo.Position.y += Speed;
		}
		if (GetAsyncKeyState(VK_RIGHT))
		{
			TransInfo.Position.x += Speed;
		}
		if (GetAsyncKeyState(VK_LEFT))
		{
			TransInfo.Position.x -= Speed;
		}
	}
	else
	{
		Slow = true;

		if (GetAsyncKeyState(VK_UP))
		{
			TransInfo.Position.y -= SlowSpeed;
		}
		if (GetAsyncKeyState(VK_DOWN))
		{
			TransInfo.Position.y += SlowSpeed;
		}
		if (GetAsyncKeyState(VK_RIGHT))
		{
			TransInfo.Position.x += SlowSpeed;
		}
		if (GetAsyncKeyState(VK_LEFT))
		{
			TransInfo.Position.x -= SlowSpeed;
		}
	}
	
	if (GetAsyncKeyState('Z') && FTime + 50 < GetTickCount64())
	{
		BulletList->push_back(CreateBullet<MarisaBullet>());
		FTime = GetTickCount64();
	}

	if (Power > 128)
		Power = 128;

	return 0;
}

void Player::Render(HDC _hdc)
{
	TransparentBlt(_hdc,
		int(TransInfo.Position.x - (TransInfo.Scale.x / 2) + 2.5f),
		int(TransInfo.Position.y - (TransInfo.Scale.y / 2) + 2.5f),
		int(TransInfo.Scale.x - 5),
		int(TransInfo.Scale.y - 5),
		ImageList[strKey]->GetMemDC(),
		int(TransInfo.Scale.x * Frame),
		int(TransInfo.Scale.y * 0),
		int(TransInfo.Scale.x),
		int(TransInfo.Scale.y),
		RGB(255, 0, 255));
}

void Player::Release()
{
}

Player::Player()
{
}

Player::~Player()
{
}

template<typename T>
inline Object* Player::CreateBullet()
{
	Bridge* pBridge = new T;

	Object* pBullet = ObjectFactory<Bullet>::CreateObject(TransInfo.Position, pBridge);

	return pBullet;
}
