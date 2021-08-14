#include "setDefine.h"
#include "SceneCastleCorrior.h"
#include "CharacterStats.h"

HRESULT SceneCastleCorrior::init()
{
	_mapCount = 1;
	CastleCorrior = IMAGEMANAGER->addImage("황성회랑", "Images/Castle Corridor A.bmp", 23136, 8048, true, RGB(0, 88, 24));
	_map = RectMake(-400, -6050, 23136, 8048);
	camera = RectMake(WINSTART_X, WINSTART_Y, WINSIZE_X, WINSIZE_Y);

#pragma region _block
	_block[0] = RectMake(_map.left + 164, _map.top + 6780, 1056, 62);
	_block[1] = RectMake(_map.left + 1667, _map.top + 6651, 589, 194);
	_block[3] = RectMake(_map.left + 2342, _map.top + 6778, 4606, 64);
	_block[4] = RectMake(_map.left + 7060, _map.top + 6652, 402, 182);
	_block[5] = RectMake(_map.left + 8090, _map.top + 6394, 263, 824);
	_block[6] = RectMake(_map.left + 7956, _map.top + 7036, 540, 180);
	_block[7] = RectMake(_map.left + 7204, _map.top + 6844, 128, 640);
	_block[8] = RectMake(_map.left + 7204, _map.top + 7420, 260, 66);
	_block[9] = RectMake(_map.left + 7570, _map.top + 7548, 146, 320);
	_block[10] = RectMake(_map.left + 7202, _map.top + 7674, 270, 192);
	_block[11] = RectMake(_map.left + 7073, _map.top + 6268, 258, 193);
	_block[12] = RectMake(_map.left + 7330, _map.top + 6395, 130, 65);
	_block[13] = RectMake(_map.left + 7330, _map.top + 6395, 130, 65);
	_block[14] = RectMake(_map.left + 7714, _map.top + 6907, 69, 59);
	_block[15] = RectMake(_map.left + 7953, _map.top + 7037, 62, 182);
	_block[16] = RectMake(_map.left + 7588, _map.top + 7293, 132, 60);
	_block[17] = RectMake(_map.left + 7330, _map.top + 7421, 131, 62);
	_block[18] = RectMake(_map.left + 7973, _map.top + 7548, 511, 16);
	_block[19] = RectMake(_map.left + 8604, _map.top + 6648, 74, 63);
	_block[20] = RectMake(_map.left + 8676, _map.top + 6908, 65, 62);
	_block[21] = RectMake(_map.left + 8355, _map.top + 7036, 140, 182);
	_block[22] = RectMake(_map.left + 8741, _map.top + 7292, 129, 60);
	_block[23] = RectMake(_map.left + 8995, _map.top + 7356, 130, 28); // 내려가는 바닥
	_block[24] = RectMake(_map.left + 8979, _map.top + 6652, 402, 192);
	_block[25] = RectMake(_map.left + 8994, _map.top + 6394, 389, 67);
	_block[26] = RectMake(_map.left + 8915, _map.top + 7547, 81, 127);
	_block[27] = RectMake(_map.left + 8997, _map.top + 7677, 382, 194); // 세이브룸 가는 길
	_block[28] = RectMake(_map.left + 9507, _map.top + 6781, 2561, 62); //보스방
	_block[29] = RectMake(_map.left + 12199, _map.top + 6651, 125, 194); 
	//벽
	_block[2] = RectMake(_map.left + 1955, _map.top + 6206, 258, 211);
	_block[30] = RectMake(_map.left + 7330, _map.top + 6201, 1813, 64);
	_block[31] = RectMake(_map.left + 7203, _map.top + 6843, 129, 639);
	_block[32] = RectMake(_map.left + 9123, _map.top + 6844, 274, 642);
#pragma endregion

	_diagonalRect = RectMake(_block[0].right, _block[1].top, 500, 100);

	water = RectMake(_map.left - 7718, _map.top - 7610, 1149, 194);

	Soma.bodyImg = IMAGEMANAGER->addFrameImage("플레이어", "Images/somacruz.bmp", 700, 1424, 9, 17, true, RGB(255, 255, 255));
	Soma._x = WINSIZE_X / 5;
	Soma._y = _block[0].top - 40;
	Soma.body = RectMakeCenter(Soma._x, Soma._y, 50, 80);

	Soma.weaponImg = IMAGEMANAGER->addFrameImage("발만웨", "Images/Valmanway.bmp", 355, 86, 4, 1, true, RGB(84, 109, 142));
	for (int i = 0; i < 4; i++)
	{
		bat[i].batImg = IMAGEMANAGER->addFrameImage("박쥐", "Images/Valmanway.bmp", 102, 30, 5, 1, true, RGB(84, 109, 142));

		if (i < 2)
			bat[i].body = RectMake(_map.left - (7920 + i * 50), _map.top - 6711, 50, 50);
		else
			bat[i].body = RectMake(_map.left - (7920 + (i * 50 + 200)), _map.top - 6711, 50, 50);
	}

	

	return S_OK;
}

void SceneCastleCorrior::release()
{
}

void SceneCastleCorrior::update()
{
	Soma._count++;
	Soma.Wcont++;
#pragma region _block
	_block[0] = RectMake(_map.left + 164, _map.top + 6780, 1056, 62);
	_block[1] = RectMake(_map.left + 1667, _map.top + 6651, 589, 194);
	_block[3] = RectMake(_map.left + 2342, _map.top + 6778, 4606, 64);
	_block[4] = RectMake(_map.left + 7060, _map.top + 6652, 402, 182);
	_block[5] = RectMake(_map.left + 8090, _map.top + 6394, 263, 824);
	_block[6] = RectMake(_map.left + 7956, _map.top + 7036, 540, 180);
	_block[7] = RectMake(_map.left + 7204, _map.top + 6844, 128, 640);
	_block[8] = RectMake(_map.left + 7204, _map.top + 7420, 260, 66);
	_block[9] = RectMake(_map.left + 7570, _map.top + 7548, 146, 320);
	_block[10] = RectMake(_map.left + 7202, _map.top + 7674, 270, 192);
	_block[11] = RectMake(_map.left + 7073, _map.top + 6268, 258, 193);
	_block[12] = RectMake(_map.left + 7330, _map.top + 6395, 130, 65);
	_block[13] = RectMake(_map.left + 7330, _map.top + 6395, 130, 65);
	_block[14] = RectMake(_map.left + 7714, _map.top + 6907, 69, 59);
	_block[15] = RectMake(_map.left + 7953, _map.top + 7037, 62, 182);
	_block[16] = RectMake(_map.left + 7588, _map.top + 7293, 132, 60);
	_block[17] = RectMake(_map.left + 7330, _map.top + 7421, 131, 62);
	_block[18] = RectMake(_map.left + 7973, _map.top + 7548, 511, 16);
	_block[19] = RectMake(_map.left + 8604, _map.top + 6648, 74, 63);
	_block[20] = RectMake(_map.left + 8676, _map.top + 6908, 65, 62);
	_block[21] = RectMake(_map.left + 8355, _map.top + 7036, 140, 182);
	_block[22] = RectMake(_map.left + 8741, _map.top + 7292, 129, 60);
	_block[23] = RectMake(_map.left + 8995, _map.top + 7356, 130, 28); // 내려가는 바닥
	_block[24] = RectMake(_map.left + 8979, _map.top + 6652, 402, 192);
	_block[25] = RectMake(_map.left + 8994, _map.top + 6394, 389, 67);
	_block[26] = RectMake(_map.left + 8915, _map.top + 7547, 81, 127);
	_block[27] = RectMake(_map.left + 8997, _map.top + 7677, 382, 194); // 세이브룸 가는 길
	_block[28] = RectMake(_map.left + 9507, _map.top + 6781, 2561, 62); //보스방
	_block[29] = RectMake(_map.left + 12199, _map.top + 6651, 125, 194);
	//벽
	_block[2] = RectMake(_map.left + 1955, _map.top + 6206, 258, 211);
	_block[30] = RectMake(_map.left + 7330, _map.top + 6201, 1813, 64);
	_block[31] = RectMake(_map.left + 7203, _map.top + 6843, 129, 639);
	_block[32] = RectMake(_map.left + 9123, _map.top + 6844, 274, 642);
#pragma endregion
	_diagonalRect = RectMake(_block[0].right, _block[1].top,_block[1].left - _block[0].right, _block[0].top - _block[1].top);

	switch (_mapCount)
	{
	case 1:
		startP();
		break;
	case 2:
		Lobby1();
		break;
	case 3:
		Lobby2();
		break;
	}

	

	for (int i = 0; i < 34; i++)
	{
		
		if (Soma.body.bottom > _block[i].top && Soma.body.bottom < _block[i].bottom && Soma.body.right > _block[i].left && Soma.body.left < _block[i].right
			)
		{
			Soma.jump = false;
			Soma._y = Soma._y - (Soma.body.bottom - _block[i].top);
			
		}
		else if (Soma.body.top > _block[i].top && Soma.body.top < _block[i].bottom && Soma.body.right > _block[i].left && Soma.body.left < _block[i].right
			)
		{
			Soma._y += Phy.fallSpeed;
			Soma._y = Soma._y - (Soma.body.top - _block[i].bottom);
		}
		/*else
		{
			Soma.jump = true;
		}*/
		if (IntersectRect(&_temp[1], &_diagonalRect, &Soma.body))
		{
			DMove = atan2(_block[i].top, _block[i].right) / 6.5;
			if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
			{
				Soma._y -= DMove;
			}
			if (KEYMANAGER->isStayKeyDown(VK_LEFT))
			{
				Soma._y += DMove;
			}
		}
	}
	if (IntersectRect(&_temp[1], &water, &Soma.body))
	{
		if (Soma._y != water.top)
		{
			Soma._y++;
		}
	}
	
	SomaMoveKey();
	SomaJump();
}

void SceneCastleCorrior::render()
{
	IMAGEMANAGER->render("황성회랑", getMemDC(),_map.left,_map.top);
	IMAGEMANAGER->frameRender("플레이어", getMemDC(), Soma.body.left, Soma.body.top);
	IMAGEMANAGER->frameRender("발만웨", getMemDC(), Soma.weapon.left, Soma.weapon.top);
	for (int i = 0; i < 34; i++)
		RectangleMake(getMemDC(), _block[i]);
		
	RectangleMake(getMemDC(), _diagonalRect);
	RectangleMake(getMemDC(), _temp[1]);
	RectangleMake(getMemDC(), Soma.body);

	for (int i = 0; i < 3; i++)
	{
		RectangleMake(getMemDC(), zombie[i].body);
		RectangleMake(getMemDC(), zombie[i].atkRange);
	}
	for (int i = 0; i < 4; i++)
		IMAGEMANAGER->frameRender("박쥐", getMemDC(), bat[i].body.left, bat[i].body.top);
}

void SceneCastleCorrior::cameraMove(int leftX, int rightX, int topY, int bottomY)
{
	if(Soma.directionR && Soma.body.right > WINSIZE_X / 2 + 25)
	{
		if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
		{
			Soma._x -= 3;
			_map.left -= 3;
			_map.right -= 3;
		}
		if (_map.left < rightX && KEYMANAGER->isStayKeyDown(VK_RIGHT))
		{
			Soma._x += 3;
			_map.left += 3;
			_map.right += 3;
		}
	}
	if ((!Soma.directionR) && Soma.body.left < WINSIZE_X / 2 - 25)
	{
		if (KEYMANAGER->isStayKeyDown(VK_LEFT))
		{
			Soma._x += 3;
			_map.left += 3;
			_map.right += 3;
		}
		if (_map.left > leftX && KEYMANAGER->isStayKeyDown(VK_LEFT))
		{
			Soma._x -= 3;
			_map.left -= 3;
			_map.right -= 3;
		}
	}
	if (Soma._y > WINSIZE_Y/2 || Soma._y <= WINSIZE_Y / 2 && Soma.jump)
	{
		
		if (_map.top > topY || _map.top > bottomY)
		{
			_map.bottom += Phy.fallSpeed;
			_map.top += Phy.fallSpeed;
			
		}
		
		else
		{
			Soma._y += Phy.fallSpeed;
			_map.bottom += Phy.fallSpeed;
			_map.top += Phy.fallSpeed;

		}
	}
	if (camera.bottom > (_map.top - bottomY) + 800)
	{
		_map.top = -bottomY;
		_map.bottom = _map.top + 8048;
	}
	
}

void SceneCastleCorrior::startP()
{
	cameraMove(-260, -1300, 6040, 6842);
	if (Soma.body.left > WINSIZE_X)
	{
		_mapCount++;
		Soma._x = WINSTART_X;
		_map.left = -2100;
		_map.right = _map.right + 23136;
	}
}

void SceneCastleCorrior::Lobby1()
{
	int zomX;

	if (Soma._x >= WINSTART_X)
	{
		if (Soma.body.left > WINSIZE_X)
		{
			_mapCount++;
			Soma._x = WINSTART_X;
			_map.left = -7200;
			_map.right = _map.right + 23136;
		}
	}
	cameraMove(-2100, -6400 ,6271 ,6842);

	for (int i = 0; i < 3; i++)
	{
		if (zombie[i].death)
		{
			zomX = Soma._x + (RND->getFromIntTo(-200, 200));
			zombie[i].body = RectMake(zomX, _block[3].top, 80, 0);
		}

		if (!zombie[i].death)
		{
			if (zombie[i].body.right < _block[3].left || zombie[i].body.left < _block[3].right)
			{
				zombie[i].body = RectMake(zomX, _block[3].top, 80, 0);
			}
		}
		ZombieMove(i);
	}
}

void SceneCastleCorrior::Lobby2()
{
	Merman _merman[3];

	
	if (Soma._x >= WINSTART_X)
	{
		if (Soma.body.left > WINSIZE_X)
		{
			_mapCount++;
			Soma._x = WINSTART_X;
			
		}
	}
	cameraMove(-7200, -8550, 6271, 7065);

	for (int i = 0; i < 4; i++)
	{
		bat[i]._count++;
		
		if (i < 3)
		{
			zombie[i].body = RectMake(-100, -100, 0, 0);
			_merman[i].body = RectMake(_map.left - RND->getFromIntTo(7970, 8480), 7880, 80, 100);
		}

		BatMove(i);
	}
}
