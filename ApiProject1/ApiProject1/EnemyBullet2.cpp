#include "EnemyBullet2.h"
#include "Object.h"
#include "ObjectManager.h"

#include "Player.h"
#include "Enemy.h"

void EnemyBullet2::Initialize()
{
    Speed = 1.0f;
    DrawKey = "EnemyBullet2";
	BAc = false;
	BTime = GetTickCount64();
	CCount = 1;
	_pPlayer = ObjectManager::GetInstance()->GetPlayer();
	EnemyList = ObjectManager::GetInstance()->GetEnemyList();
}

int EnemyBullet2::Update(Transform& _rTransInfo)
{
	_rTransInfo.Position.x += _rTransInfo.Direction.x * Speed;
	_rTransInfo.Position.y -= -_rTransInfo.Direction.y * Speed;

	for (vector<Object*>::iterator Eiter = EnemyList->begin();
		Eiter != EnemyList->end(); )
	{
		if ((*Eiter)->GetLife() == 2)
		{
			if ((*Eiter)->GetPower() == 2)
			{
				if (BTime + 1000 <= GetTickCount64() && BAc == false)
				{
					{
						BAc = true;
						Vector3 TargetPos(_pPlayer->GetPosition().x, _pPlayer->GetPosition().y + 500);
						_rTransInfo.Direction.x = -(_rTransInfo.Position.x - TargetPos.x) / 500;
						_rTransInfo.Direction.y = -(_rTransInfo.Position.y - TargetPos.y) / 1000;
					}
					BTime = GetTickCount64();
				}
			}
			else if ((*Eiter)->GetPower() == 1)
			{
				if (BTime + 500 <= GetTickCount64() && BAc == false)
				{
					Speed -= 0.5f;
					BTime = GetTickCount64();

				}
				if (Speed < 0)
					Speed = 0;
				else if (Speed == 0)
				{
					if ((*Eiter)->GetTimeCount() < 24)
					{
						if (_rTransInfo.Position.x < (*Eiter)->GetPosition().x)
						{
							float cx = sinf((10 - (5 * ((*Eiter)->GetTimeCount() - 3))) * PI / -180);
							float cy = cosf((10 - (5 * ((*Eiter)->GetTimeCount() - 3))) * PI / -180);
							_rTransInfo.Direction.x = cx / 2;
							_rTransInfo.Direction.y = cy / 2;
						}
						else if (_rTransInfo.Position.x > (*Eiter)->GetPosition().x)
						{
							float cx = sinf((10 - (5 * ((*Eiter)->GetTimeCount() - 3))) * PI / 180);
							float cy = cosf((10 - (5 * ((*Eiter)->GetTimeCount() - 3))) * PI / 180);
							_rTransInfo.Direction.x = cx / 2;
							_rTransInfo.Direction.y = cy / 2;
						}
					}

					Speed = 1.0f;
					BAc = true;
					++CCount;
				}
			}
		}
		
		break;
	}

	if (_rTransInfo.Position.y >= (WindowsHeight + 100)
		|| _rTransInfo.Position.y <= (-100)
		|| _rTransInfo.Position.x >= (WindowsWidth + 100)
		|| _rTransInfo.Position.x <= (-100)
		)
		return 1;

	return 4;
}

void EnemyBullet2::Render(HDC _hdc)
{
	ImageList = Object::GetImageList();
	TransparentBlt(_hdc,
		int(RealObject->GetPosition().x - 4),
		int(RealObject->GetPosition().y - 4),
		8,
		8,
		ImageList[DrawKey]->GetMemDC(),
		int(8 * FrameX),
		int(8 * FrameY),
		8,
		8,
		RGB(0, 0, 0));
}

void EnemyBullet2::Release()
{
}

EnemyBullet2::EnemyBullet2()
{
}

EnemyBullet2::~EnemyBullet2()
{
}
