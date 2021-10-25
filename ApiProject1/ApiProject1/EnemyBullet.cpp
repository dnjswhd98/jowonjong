#include "EnemyBullet.h"
#include "Object.h"
#include "ObjectManager.h"

#include "Player.h"
#include "Enemy.h"

void EnemyBullet::Initialize()
{
    Speed = 1.0f;
    DrawKey = "EnemyBullet";
	BTime = GetTickCount64();
	_pPlayer = ObjectManager::GetInstance()->GetPlayer();
	EnemyList = ObjectManager::GetInstance()->GetEnemyList();
	
}

int EnemyBullet::Update(Transform& _rTransInfo)
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
				Speed = 2.0f;
			}
		}
		else if ((*Eiter)->GetLife() == 1)
		{
			if ((*Eiter)->GetPower() == 2)
			{
				BTime = ABTime;
				if (BTime + 2500 <= GetTickCount64())
				{
					if (!BAc)
					{
						Speed = 0;
						BAc = true;
					}
				}
				if(BAc)
					Speed += 0.01f;
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

	return 3;
}

void EnemyBullet::Render(HDC _hdc)
{
	ImageList = Object::GetImageList();
	TransparentBlt(_hdc,
		int(RealObject->GetPosition().x - 8),
		int(RealObject->GetPosition().y - 8),
		16,
		16,
		ImageList[DrawKey]->GetMemDC(),
		int(16 * FrameX),
		int(16 * FrameY),
		16,
		16,
		RGB(0, 0, 0));
	
}

void EnemyBullet::Release()
{
}

EnemyBullet::EnemyBullet()
{
}

EnemyBullet::~EnemyBullet()
{
}
