#include "Player.h"
#include "InputManager.h"
#include "ObjectManager.h"
#include "ObjectFactory.h"

#include "Bullet.h"
#include "MarisaBullet.h"
#include "MarisaLazer.h"
#include "Bomb.h"
#include "PlayerSide.h"

void Player::Initialize()
{
	TransInfo.Position = Vector3(WindowsWidth / 3, (WindowsHeight / 2) + 150);
	TransInfo.Scale = Vector3(29.0f, 44.0f);

	Slow = false;
	bBomb = false;
	Active = false;
	Dead = false;
	Speed = 3.0f;
	SlowSpeed = 2.0f;
	Frame = 0;
	BFrame = 0;

	strKey = "Marisa";
	Life = 2;
	Bomb = 3;
	Power = 127;
	Item = 0;
	Graze = 0;

	BulletList = ObjectManager::GetInstance()->GetBulletList();
	Time = GetTickCount64();
	FTime = GetTickCount64();
	BTime = GetTickCount64();
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

		if (GetAsyncKeyState(VK_UP) && TransInfo.Position.y > MinHeight)
		{
			TransInfo.Position.y -= Speed;
		}
		if (GetAsyncKeyState(VK_DOWN) && TransInfo.Position.y < MaxHeight)
		{
			TransInfo.Position.y += Speed;
		}
		if (GetAsyncKeyState(VK_RIGHT) && TransInfo.Position.x < MaxWidth)
		{
			TransInfo.Position.x += Speed;
		}
		if (GetAsyncKeyState(VK_LEFT) && TransInfo.Position.x > MinWidth)
		{
			TransInfo.Position.x -= Speed;
		}
	}
	else
	{
		Slow = true;

		if (GetAsyncKeyState(VK_UP) && TransInfo.Position.y > MinHeight)
		{
			TransInfo.Position.y -= SlowSpeed;
		}
		if (GetAsyncKeyState(VK_DOWN) && TransInfo.Position.y < MaxHeight)
		{
			TransInfo.Position.y += SlowSpeed;
		}
		if (GetAsyncKeyState(VK_RIGHT) && TransInfo.Position.x < MaxWidth)
		{
			TransInfo.Position.x += SlowSpeed;
		}
		if (GetAsyncKeyState(VK_LEFT) && TransInfo.Position.x > MinWidth)
		{
			TransInfo.Position.x -= SlowSpeed;
		}
	}
	
	if (GetAsyncKeyState('Z') && FTime + 50 < GetTickCount64())
	{
		if (Power < 32)
		{
			BFrame = 0;
			TransInfo.Direction = Vector3(0, -2);
			BulletList->push_back(CreateBullet<MarisaBullet>());
		}
		else if (Power >= 32 && Power < 64)
		{
			for (int i = 0; i < 2; ++i)
			{
				float cx = sinf((178 + (4 * i)) * PI / 180);
				float cy = cosf((178 + (4 * i)) * PI / 180);
				TransInfo.Direction = Vector3(cx, cy);
				BFrame = 0;
				BulletList->push_back(CreateBullet<MarisaBullet>());
			}
		}
		else
		{
			for (int i = 0; i < 3; ++i)
			{
				float cx = sinf((176 + (4 * i)) * PI / 180);
				float cy = cosf((176 + (4 * i)) * PI / 180);
				TransInfo.Direction = Vector3(cx, cy);
				BFrame = 0;
				BulletList->push_back(CreateBullet<MarisaBullet>());
			}
		}
		FTime = GetTickCount64();
	}
	if (!bBomb)
	{
		if (GetAsyncKeyState('X') && Bomb > 0)
		{
			--Bomb;
			bBomb = true;
			Active = true;
			for (int i = 0; i < 8; ++i)
			{
				float cx = sinf((45 * i) * PI / 180);
				float cy = cosf((45 * i) * PI / 180);
				TransInfo.Direction = Vector3(cx, cy);
				if (i < 4)
					BFrame = i;
				else
					BFrame = i - 4;
				BulletList->push_back(CreateBullet<PBomb>());
			}
		}
	}
	if (BTime + 3000 < GetTickCount64() && bBomb)
	{
		if (bBomb)
		{
			bBomb = false;
			Active = false;
		}
		BTime = GetTickCount64();
	}
	if (Power > 128)
		Power = 128;

	if (Dead)
	{
		if (TransInfo.Scale.x <= 1)
		{
			TransInfo.Position = Vector3(WindowsWidth / 3, (WindowsHeight / 2) + 150);
			TransInfo.Scale.x = 0;
			Dead = false;
		}
		else
		{
			--TransInfo.Scale.x;
			++TransInfo.Scale.y;
		}
	}
	else
	{
		if (TransInfo.Scale.x != 29)
			++TransInfo.Scale.x;
		if (TransInfo.Scale.y != 44)
			--TransInfo.Scale.y;
	}
	

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
		int(44),
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

	Object* pBullet = ObjectFactory<Bullet>::CreateObject(TransInfo.Position, TransInfo.Direction.x, TransInfo.Direction.y, BFrame, 0, pBridge);

	return pBullet;
}
