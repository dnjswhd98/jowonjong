#pragma once
#include "setDefine.h"

RECT _temp;

struct
{
	float gravity = 1.0;
	float fallSpeed;
}Phy;

struct
{
	RECT body;
	RECT weapon;
	//RECT soul;

	image* bodyImg;
	image* weaponImg;
	//image* soulImg;

	int _count = 0, _index = 0;
	int Wcont = 0, Windex = 0;
	float _x, _y;
	int _probeY;

	int lv = 1, hp = 320, mp = 80, str = 10, con = 12,in = 11, lck = 9;
	int atk=str, def = con/2;
	int weaponNum = 1;

	bool stop = true;
	bool directionR = true;
	bool jump = false;
	bool atkReady = true;
	bool hit = false;
	bool death = false;
}Soma;

struct Bat
{
	RECT body;
	RECT atkRange;

	image* batImg;

	int hp = 10, mp = 10, atk = 6, def = 0;
	int _count = 0, _index = 5;
	int MCount;

	bool Attak = false;
	bool directionR = false;
}bat[4];

struct Zombie
{
	RECT body;
	RECT atkRange;

	image* zombieImg;

	int hp = 18, mp = 10, atk = 9, def = 1;
	int _count = 0, _index = 0;

	bool attack = false;
	bool directionR = false;
	bool death = true;
}zombie[3];

struct Merman
{
	RECT body;
	RECT atkRange;
	RECT bullet;

	image* mermanImg;
	image* bulletImg;

	int hp = 20, mp = 10, atk = 9, def = 3;
	int _count = 0, _index = 0;
	int shoot = 0;

	bool attack = false;
	bool directionR = false;
}merman;

struct AxeArmor
{
	RECT body;
	RECT atkRange;
	RECT axe;

	image* axeArmorImg;
	image* axeImg;

	int hp = 60, mp = 80, atk = 15, def = 8;
	int _count = 0, _index = 0;
	int shoot;

	bool attack = false;
	bool directionR = false;
}axearmor;

struct SkullArcher
{
	RECT body;
	RECT atkRange;
	RECT arrow;

	image* skullArcherImg;
	image* arrowImg;

	int hp = 42, mp = 40, atk = 13, def = 5;
	int _count = 0, _index = 0;

	bool attack = false;
	bool directionR = false;
}skullarcher;

void SomaMoveKey(void)
{
	

	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		Soma._x += 3;
		Soma.directionR = true;
		Soma.stop = false;
		Soma.bodyImg->setFrameY(3);
		if (Soma._index >= 9)
		{
			Soma.bodyImg->setFrameY(4);
			if (Soma._index >= 8)
			{
				Soma.bodyImg->setFrameY(3);
				Soma._index = 0;
			}
		}
	}
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		Soma._x -= 3;
		Soma.stop = false;
		Soma.directionR = false;
		Soma.bodyImg->setFrameY(3);
		if (Soma._index >= 9)
		{
			Soma.bodyImg->setFrameY(4);
			if (Soma._index >= 8)
			{
				Soma.bodyImg->setFrameY(3);
				Soma._index = 0;
			}
		}
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		Soma.stop = false;
		Soma.body.top - 40;
		Soma.bodyImg->setFrameY(6);
		if (Soma._index <= 3)
		{
			Soma._index = 0;
			Soma.bodyImg->setFrameY(5);
		}
	}
	if (KEYMANAGER->isOnceKeyUp(VK_DOWN))
	{
		Soma.stop = true;
		Soma.body.top + 40;
		Soma.bodyImg->setFrameY(1);
	}

	
	if (KEYMANAGER->isOnceKeyDown(0x58))
	{
		if (Soma.directionR)
		{
			Soma.atkReady = false;
			Soma.weapon = RectMake(Soma.body.right - 30, Soma.body.top, 60, 70);
			Soma.weaponImg->setFrameX(1);
		}
		else
		{
			Soma.atkReady = false;
			Soma.weapon = RectMake(Soma.body.left - 40, Soma.body.top, 60, 70);
			Soma.weaponImg->setFrameX(1);
		}
	}
	if (KEYMANAGER->isOnceKeyUp(0x58))
	{
		Soma.atkReady = true;
		Soma.weapon = RectMake(-110, -250, 50, 50);
	}
	if (KEYMANAGER->isOnceKeyDown(0x5A) && !Soma.jump)
	{
		Soma.stop = false;
		Soma.jump = true;
		Phy.fallSpeed = 20;

	}
	if (KEYMANAGER->isOnceKeyUp(VK_LEFT) ||
		KEYMANAGER->isOnceKeyUp(VK_RIGHT))
	{
		Soma.stop = true;
		Soma.bodyImg->setFrameX(0);
		Soma.bodyImg->setFrameY(0);
	}
	Soma.body = RectMakeCenter(Soma._x, Soma._y, 50, 80);
	Soma._probeY = Soma._y + Soma.bodyImg->getHeight() / 2;
	if (Soma._count % 6 == 0)
	{
		if (Soma._index < 9) Soma._index = 0;
		Soma.bodyImg->setFrameX(Soma._index);
		Soma._index++;
	}
	if (Soma.Wcont % 3 == 0)
	{
		if (Soma.Windex < 4) Soma.Windex = 0;
		Soma.weaponImg->setFrameX(Soma.Windex);
		Soma.Windex++;
	}
}

void SomaJump(void)
{
	if (Soma.jump)
	{
		
		Phy.fallSpeed -= Phy.gravity;
		Soma.bodyImg->setFrameY(10);
		if (Soma._index >= 7)
			Soma._index = 0;
	}
	else
	{
		Phy.fallSpeed = 0;
	}
		Soma._y -= Phy.fallSpeed;
	
}

void BatMove(int i)
{

	bat[i].batImg->setFrameX(bat[i]._index);
	bat[i].atkRange = RectMake(bat[i].body.left - 100, bat[i].body.top - 100, 240, 240);
	if (IntersectRect(&_temp, &bat[i].atkRange, &Soma.body))
		bat[i].Attak = true;
	if (bat[i].Attak)
	{
		bat[i]._count++;

		if (bat[i].MCount < 5)
		{
			bat[i].body.top += 1;
			bat[i].body.bottom += 1;
			bat[i].body.left += 1;
			bat[i].body.right += 1;
		}
		else
		{
			bat[i].body.left -= 2;
			bat[i].body.right -= 2;
		}
		
		if (bat[i]._count % 6 == 0)
		{
			bat[i].MCount++;
			if (bat[i]._index < 1) bat[i]._index = 3;
			bat[i].batImg->setFrameX(bat[i]._index);
			bat[i]._index--;
		}
	}
}

void ZombieMove(int i)
{

	zombie[i]._count++;

	zombie[i].atkRange = RectMakeCenter(zombie[i].body.left + 40, zombie[i].body.bottom, 200, 100);

	if (IntersectRect(&_temp, &zombie[i].atkRange, &Soma.body))
	{
		zombie[i].body.top -= 5;
		if (zombie[i].body.top == zombie[i].body.bottom - 80)
		{
			zombie[i].body.top += 5;
			zombie[i].attack = true;
		}
	}
	if (zombie[i].attack)
	{
		zombie[i].death = false;
		zombie[i].body.left -= 1;
		zombie[i].body.right -= 1;
	}

}

void MermanMove()
{

	merman._count++;

	merman.atkRange = RectMake(merman.body.left - 400, merman.body.top, 850, 80);

	if (IntersectRect(&_temp, &merman.atkRange, &Soma.body))
	{
		if (Soma.body.left <= merman.body.left)
		{
			merman.body.left -= 2;
			merman.body.right -= 2;
		}
		else
		{
			merman.body.left += 2;
			merman.body.right += 2;
		}
		
		if (merman._count % 3 == 0 || !merman.attack)
		{
			merman.shoot = RND->getFloat(3);
			if (merman.shoot == 3)
			{
				merman.attack = true;

				if (Soma.body.left <= merman.body.left)
				{
					merman.body.left += 2;
					merman.body.right += 2;
				}
				else
				{
					merman.body.left -= 2;
					merman.body.right -= 2;
				}

				if (merman.directionR)
					merman.bullet = RectMake(merman.body.right + 30, merman.body.top + 10, 80, 10);
				else
					merman.bullet = RectMake(merman.body.left - 50, merman.body.top + 10, 80, 10);
			}
		}
	}
	if (merman.attack)
	{
		if (merman.directionR)
		{
			merman.bullet.left + 4;
			merman.bullet.right + 4;
		}
		else
		{
			merman.bullet.left - 4;
			merman.bullet.right - 4;
		}

		if (merman.bullet.left < -80 || merman.bullet.right > WINSIZE_X + 80)
			merman.attack = false;
	}
}
void AxeArmorMove()
{

	axearmor._count++;

	axearmor.atkRange = RectMake(axearmor.body.left - 200, axearmor.body.top, 450, 85);

	if (IntersectRect(&_temp, &axearmor.atkRange, &Soma.body))
	{
		if (axearmor._count % 3 == 0)
			axearmor.attack = true;
			//axearmor.shoot = RND->getFloat(3);
		/*if (axearmor.shoot == 3)
		{
			axearmor.attack = true;
			if (axearmor.directionR)
				axearmor.axe = RectMake(axearmor.body.right, axearmor.body.top + 10, 50, 50);
			else
				axearmor.axe = RectMake(axearmor.body.left - 50, axearmor.body.top + 10, 50, 50);
		}*/
		if (axearmor.directionR)
			axearmor.axe = RectMake(axearmor.body.right, axearmor.body.top + 10, 50, 50);
		else
			axearmor.axe = RectMake(axearmor.body.left - 50, axearmor.body.top + 10, 50, 50);

	}
	if (axearmor.attack)
	{
		if (axearmor.directionR)
		{
			if (axearmor.axe.left < axearmor.body.right + 200)
			{
				axearmor.axe.left -= 3;
				axearmor.axe.right -= 3;
			}
			else
			{
				axearmor.axe.left += 3;
				axearmor.axe.right += 3;
			}
		}
		else
		{
			if (axearmor.axe.right > axearmor.body.left - 200)
			{
				axearmor.axe.left += 3;
				axearmor.axe.right += 3;
			}
			else
			{
				axearmor.axe.left -= 3;
				axearmor.axe.right -= 3;
			}
		}
		if (axearmor.axe.left < axearmor.body.left || axearmor.axe.right > axearmor.body.right)
		{
			axearmor.attack = false;
			axearmor.axe = RectMake(WINSIZE_X - 100, WINSIZE_Y - 100, 50, 50);
		}
	}

}

/*
void SkullACMove()
{
	skullarcher._count++;
	
	if (skullarcher._count % 6 == 0)
	{
		if (skullarcher._index > 15)
			skullarcher._index = 0;
		skullarcher.skullArcherImg->setFrameX(skullarcher._index);
		skullarcher._index++;

		if (skullarcher._index == 6)
		{
			skullarcher.arrow = RectMakeCenter(skullarcher.body.left, skullarcher.body.top + 10, 15, 10);
		}
	}

	//skullarcher.arrow.left -= 5;
	//skullarcher.arrow.right -= 5;
}
*/

void Animation()
{
	Soma._count++;
	Soma.Wcont++;

	if (Soma._count % 7 == 0)
	{
		//캐릭터 조작을 실행하지 않을 경우
		if (Soma.stop)
		{
			Soma.bodyImg->setFrameX(0);
			Soma._index = 0;
			return;
		}

		//애니메이션을 반복 출력한다
		if (Soma._index > 9)
			Soma._index = 0;
		Soma.bodyImg->setFrameX(Soma._index);
		Soma._index++;
	}

	if (Soma.Wcont % 1 == 0)
	{
		if (Soma.Windex > 4) Soma.Windex = 0;
		Soma.weaponImg->setFrameX(Soma.Windex);
		Soma.Windex++;
	}
}

void Damaged()
{
	
}
