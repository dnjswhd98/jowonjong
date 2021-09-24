#include "Player.h"
#include "InputManager.h"
#include "ObjectManager.h"
#include "ObjectFactory.h"

void Player::Initialize()
{
	TransInfo.Position = Vector3(WindowsWidth / 2, WindowsHeight / 2);
	TransInfo.Scale = Vector3(10.0f, 10.0f);

	Slow = false;
	Speed = 1.5f;
	SlowSpeed = 0.5f;
}

void Player::Update()
{
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
}

void Player::Render(HDC _hdc)
{
	Ellipse(_hdc,
		int(TransInfo.Position.x - (TransInfo.Scale.x / 2)),
		int(TransInfo.Position.y - (TransInfo.Scale.y / 2)),
		int(TransInfo.Position.x + (TransInfo.Scale.x / 2)),
		int(TransInfo.Position.y + (TransInfo.Scale.y / 2)));
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
