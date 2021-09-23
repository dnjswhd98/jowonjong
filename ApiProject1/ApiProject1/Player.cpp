#include "Player.h"
#include "InputManager.h"
#include "ObjectManager.h"
#include "ObjectFactory.h"

void Player::Initialize()
{
	TransInfo.Position = Vector3(WindowsWidth / 2, WindowsHeight / 2);
}

void Player::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	

	if (GetAsyncKeyState(VK_UP))
	{
		TransInfo.Position.y -= 2.0f;
	}

	if (GetAsyncKeyState(VK_DOWN))
	{
		TransInfo.Position.y += 2.0f;
	}
}

void Player::Render(HDC _hdc)
{
	Ellipse(_hdc, TransInfo.Position.x, TransInfo.Position.y, 100, 100);
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
