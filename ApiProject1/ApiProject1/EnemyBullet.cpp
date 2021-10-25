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
				if ((*Eiter)->GetTimeCount() >= 30 && (*Eiter)->GetTimeCount() < 35)
				{
					if (!BAc)
					{
						FrameX = 15;
						float cx = sinf((rand() % 360) * PI / 180);
						float cy = cosf((rand() % 360) * PI / 180);
						_rTransInfo.Direction.x = cx / 2;
						_rTransInfo.Direction.y = cy / 2;
						Speed = 0;
						BAc = true;
					}
				}
				else if ((*Eiter)->GetTimeCount() >= 50 && (*Eiter)->GetTimeCount() < 60)
				{

					if (BAc)
					{
						if (_rTransInfo.Direction.x + _rTransInfo.Direction.y < 0.3f)
							Speed += 0.01f;
						else if (_rTransInfo.Direction.x + _rTransInfo.Direction.y >= 0.3f && _rTransInfo.Direction.x + _rTransInfo.Direction.y < 0.5f)
							Speed += 0.008f;
						else if (_rTransInfo.Direction.x + _rTransInfo.Direction.y >= 1.0f && _rTransInfo.Direction.x + _rTransInfo.Direction.y < 2.5f)
							Speed += 0.00005f;
						else if (_rTransInfo.Direction.x + _rTransInfo.Direction.y >= 2.5f)
							Speed += 0.00001f;
						else
							Speed += 0.004f;
					}
				}
			}
			else if ((*Eiter)->GetPower() == 1)
			{
				if (!BAc)
				{
					Speed = 2.0f;
					BAc = true;
				}
				if (BTime + 150 < GetTickCount64())
				{
					if (BAc)
					{
						if(Speed > 1.0f)
							Speed -= 0.3f;
					}
					BTime = GetTickCount64();
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
