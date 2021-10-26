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
	TransInfo.Scale = Vector3(14.0f, 14.0f);

	BulletList = ObjectManager::GetInstance()->GetBulletList();

	strKey = "MarisaSide";
	Frame = 0;
	minusX = 4.0f;
	minusY = 20.0f;

	time = GetTickCount64();
	Ftime = GetTickCount64();

}

int PlayerSide::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (_pPlayer->GetPower() >= 8)
	{
		if (GetAsyncKeyState('Z'))
		{
			if (_pPlayer->GetPower() >= 8 && _pPlayer->GetPower() < 16)
			{
				if (Ftime + 500 < GetTickCount64())
				{
					float cx = sinf(180 * PI / 180);
					float cy = cosf(180 * PI / 180);
					TransInfo.Direction = Vector3(cx, cy);

					BulletList->push_back(CreateBullet<MarisaLazer>());
					Ftime = GetTickCount64();
				}
			}
			else if (_pPlayer->GetPower() >= 16 && _pPlayer->GetPower() < 32)
			{
				if (Ftime + 300 < GetTickCount64())
				{
					float cx = sinf(180 * PI / 180);
					float cy = cosf(180 * PI / 180);
					TransInfo.Direction = Vector3(cx, cy);

					BulletList->push_back(CreateBullet<MarisaLazer>());
					Ftime = GetTickCount64();
				}
			}
			else if (_pPlayer->GetPower() >= 32 && _pPlayer->GetPower() < 64)
			{
				if (Ftime + 200 < GetTickCount64())
				{
					if (!Fire)
					{
						float cx = sinf(177 * PI / 180);
						float cy = cosf(177 * PI / 180);
						TransInfo.Direction = Vector3(cx, cy);
						Fire = true;
					}
					else
					{
						float cx = sinf(177 * PI / -180);
						float cy = cosf(177 * PI / -180);
						TransInfo.Direction = Vector3(cx, cy);
						Fire = false;
					}

					BulletList->push_back(CreateBullet<MarisaLazer>());
					Ftime = GetTickCount64();
				}
			}
			else if (_pPlayer->GetPower() >= 64 && _pPlayer->GetPower() < 128)
			{
				if (Ftime + 150 < GetTickCount64())
				{
					if (!Fire)
					{
						float cx = sinf(177 * PI / 180);
						float cy = cosf(177 * PI / 180);
						TransInfo.Direction = Vector3(cx, cy);
						Fire = true;
					}
					else
					{
						float cx = sinf(177 * PI / -180);
						float cy = cosf(177 * PI / -180);
						TransInfo.Direction = Vector3(cx, cy);
						Fire = false;
					}

					BulletList->push_back(CreateBullet<MarisaLazer>());
					Ftime = GetTickCount64();
				}
			}
			else
			{
				if (Ftime + 100 < GetTickCount64())
				{
					if (!Fire)
					{
						float cx = sinf(177 * PI / 180);
						float cy = cosf(177 * PI / 180);
						TransInfo.Direction = Vector3(cx, cy);
						Fire = true;
					}
					else
					{
						float cx = sinf(177 * PI / -180);
						float cy = cosf(177 * PI / -180);
						TransInfo.Direction = Vector3(cx, cy);
						Fire = false;
					}

					BulletList->push_back(CreateBullet<MarisaLazer>());
					Ftime = GetTickCount64();
				}
			}
		}
	}

	if (GetAsyncKeyState(VK_SHIFT))
	{
		if (time + 50 < GetTickCount64())
		{
			++count;
			time = GetTickCount64();
		}

		if (count < 2)
		{
			TransInfo.Position.x += minusX;
			TransInfo.Position.y -= minusY;
			minusY /= 2;
		}
		else
			TransInfo.Position = Vector3(_pPlayer->GetPosition().x - 9, _pPlayer->GetPosition().y - 37);
	}
	else
	{
		TransInfo.Position = Vector3(_pPlayer->GetPosition().x - 30, _pPlayer->GetPosition().y);
		minusX = 4.0f;
		minusY = 20.0f;
		count = 0;
	}

	return 0;

}

void PlayerSide::Render(HDC _hdc)
{
	if (_pPlayer->GetPower() >= 8)
	{
		TransparentBlt(_hdc,
			int(TransInfo.Position.x - (TransInfo.Scale.x / 2) + Offset.x),
			int(TransInfo.Position.y - (TransInfo.Scale.y / 2) + Offset.y),
			int(TransInfo.Scale.x),
			int(TransInfo.Scale.y),
			ImageList[strKey]->GetMemDC(),
			int(TransInfo.Scale.x * Frame),
			int(TransInfo.Scale.y * 0),
			int(TransInfo.Scale.x),
			int(TransInfo.Scale.y),
			RGB(255, 0, 255));
	}
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

	Object* pBullet = ObjectFactory<Bullet>::CreateObject(TransInfo.Position, TransInfo.Direction.x, TransInfo.Direction.y, 0, 0, pBridge);

	return pBullet;
}