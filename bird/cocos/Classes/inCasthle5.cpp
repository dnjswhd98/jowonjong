#include "inCasthle5.h"

USING_NS_CC;

cocos2d::Scene * inCasthle5::createScene()
{
	return inCasthle5::create();
}

bool inCasthle5::init()
{
	if (!Scene::init())return false;

	Infor inf;
	inf.luffis;

	mapIndex = 0;

	auto visible = _director->getVisibleSize();

	_layer1 = Layer::create();
	_layer2 = Layer::create();

	map1 = TMXTiledMap::create("zeldaSprites/map/casthle5.tmx");
	auto object1 = map1->getObjectGroup("object");
	auto spwanPoint = object1->getObject("st1");

	_bool1 = map1->getLayer("metaset");
	_layer1->addChild(map1, 0);

	int x = spwanPoint["x"].asInt();
	int y = spwanPoint["y"].asInt();

	linkPosition = Vec2(x, y);

	this->createLink();

	auto zelda = Sprite::create("zeldaSprites/zelda/001.png");

	_ui = TMXTiledMap::create("zeldaSprites/map/ui.tmx");
	_ui->setPosition(Vec2(0, 140));
	_layer2->addChild(_ui, 50);

	schedule(schedule_selector(inCasthle5::camera));

	this->addChild(_layer1);
	this->addChild(_layer2);



	this->uiNum();

	return true;
}

void inCasthle5::onEnter()
{
	Scene::onEnter();

	_listener = EventListenerKeyboard::create();

	_listener->onKeyPressed = CC_CALLBACK_2(inCasthle5::onKeyPressed, this);
	_listener->onKeyReleased = CC_CALLBACK_2(inCasthle5::onKeyReleased, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(_listener, this);
}

void inCasthle5::onExit()
{
	_eventDispatcher->removeAllEventListeners();
	Scene::onExit();
}

void inCasthle5::onKeyPressed(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event * event)
{
	switch (keycode)
	{
	case cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW:
	{
		link->stopAllActions();

		schedule(schedule_selector(inCasthle5::linkMoveUp));
		auto animation = Animation::create();

		animation->setDelayPerUnit(0.05f);

		animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/Umove/027.png");
		animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/Umove/028.png");
		animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/Umove/029.png");
		animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/Umove/030.png");
		animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/Umove/031.png");
		animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/Umove/032.png");
		animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/Umove/033.png");
		animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/Umove/034.png");

		auto animate = Animate::create(animation);

		auto rep = RepeatForever::create(animate);
		link->runAction(rep);

		linkDirec = 0;
	}
	break;
	case cocos2d::EventKeyboard::KeyCode::KEY_DOWN_ARROW:
	{
		link->stopAllActions();

		schedule(schedule_selector(inCasthle5::linkMoveDown));
		auto animation = Animation::create();

		animation->setDelayPerUnit(0.05f);

		animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/Dmove/007.png");
		animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/Dmove/008.png");
		animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/Dmove/009.png");
		animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/Dmove/010.png");
		animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/Dmove/011.png");
		animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/Dmove/012.png");
		animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/Dmove/013.png");
		animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/Dmove/014.png");

		auto animate = Animate::create(animation);

		auto rep = RepeatForever::create(animate);
		link->runAction(rep);

		linkDirec = 1;
	}
	break;
	case cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW:
	{
		link->stopAllActions();

		schedule(schedule_selector(inCasthle5::linkMoveLeft));
		auto animation = Animation::create();

		animation->setDelayPerUnit(0.05f);

		animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/Lmove/004.png");
		animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/Lmove/015.png");
		animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/Lmove/016.png");
		animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/Lmove/017.png");
		animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/Lmove/018.png");
		animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/Lmove/019.png");

		auto animate = Animate::create(animation);

		auto rep = RepeatForever::create(animate);
		link->runAction(rep);

		linkDirec = 2;
	}
	break;
	case cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
	{
		link->stopAllActions();

		schedule(schedule_selector(inCasthle5::linkMoveRight));
		auto animation = Animation::create();

		animation->setDelayPerUnit(0.05f);

		animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/Rmove/020.png");
		animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/Rmove/021.png");
		animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/Rmove/023.png");
		animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/Rmove/024.png");
		animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/Rmove/025.png");
		animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/Rmove/026.png");

		auto animate = Animate::create(animation);

		auto rep = RepeatForever::create(animate);
		link->runAction(rep);

		linkDirec = 3;
	}
	break;

	case cocos2d::EventKeyboard::KeyCode::KEY_Z:
	{

		linkAtk = true;

		switch (linkDirec)
		{
		case 0:
		{
			auto animation = Animation::create();

			animation->setDelayPerUnit(0.04f);

			animation->addSpriteFrameWithFile("zeldaSprites/link/attck/U/001.png");
			animation->addSpriteFrameWithFile("zeldaSprites/link/attck/U/002.png");
			animation->addSpriteFrameWithFile("zeldaSprites/link/attck/U/003.png");
			animation->addSpriteFrameWithFile("zeldaSprites/link/attck/U/004.png");
			animation->addSpriteFrameWithFile("zeldaSprites/link/attck/U/005.png");
			animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/Umove/027.png");

			auto animate = Animate::create(animation);

			link->runAction(animate);

		}
		break;
		case 1:
		{
			auto animation = Animation::create();

			animation->setDelayPerUnit(0.04f);

			animation->addSpriteFrameWithFile("zeldaSprites/link/attck/D/001.png");
			animation->addSpriteFrameWithFile("zeldaSprites/link/attck/D/002.png");
			animation->addSpriteFrameWithFile("zeldaSprites/link/attck/D/003.png");
			animation->addSpriteFrameWithFile("zeldaSprites/link/attck/D/004.png");
			animation->addSpriteFrameWithFile("zeldaSprites/link/attck/D/005.png");
			animation->addSpriteFrameWithFile("zeldaSprites/link/attck/D/006.png");
			animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/Dmove/007.png");

			auto animate = Animate::create(animation);

			link->runAction(animate);

		}
		break;
		case 2:
		{
			auto animation = Animation::create();

			animation->setDelayPerUnit(0.04f);

			animation->addSpriteFrameWithFile("zeldaSprites/link/attck/L/001.png");
			animation->addSpriteFrameWithFile("zeldaSprites/link/attck/L/002.png");
			animation->addSpriteFrameWithFile("zeldaSprites/link/attck/L/003.png");
			animation->addSpriteFrameWithFile("zeldaSprites/link/attck/L/004.png");
			animation->addSpriteFrameWithFile("zeldaSprites/link/attck/L/005.png");
			animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/Lmove/004.png");

			auto animate = Animate::create(animation);

			link->runAction(animate);

		}
		break;
		case 3:
		{
			auto animation = Animation::create();

			animation->setDelayPerUnit(0.04f);

			animation->addSpriteFrameWithFile("zeldaSprites/link/attck/R/001.png");
			animation->addSpriteFrameWithFile("zeldaSprites/link/attck/R/002.png");
			animation->addSpriteFrameWithFile("zeldaSprites/link/attck/R/003.png");
			animation->addSpriteFrameWithFile("zeldaSprites/link/attck/R/004.png");
			animation->addSpriteFrameWithFile("zeldaSprites/link/attck/R/005.png");
			animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/Rmove/020.png");

			auto animate = Animate::create(animation);

			link->runAction(animate);

		}
		break;
		default:
			break;
		}
	}
	break;
	default:
		break;
	}
}

void inCasthle5::onKeyReleased(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event * event)
{
	switch (keycode)
	{
	case cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW:
	{
		unschedule(schedule_selector(inCasthle5::linkMoveUp));
	}
	break;
	case cocos2d::EventKeyboard::KeyCode::KEY_DOWN_ARROW:
	{
		unschedule(schedule_selector(inCasthle5::linkMoveDown));
	}
	break;
	case cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW:
	{
		unschedule(schedule_selector(inCasthle5::linkMoveLeft));
	}
	break;
	case cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
	{
		unschedule(schedule_selector(inCasthle5::linkMoveRight));
	}
	break;
	case cocos2d::EventKeyboard::KeyCode::KEY_Z:
	{
		linkAtk = false;
	}
	default:
		break;
	}
	link->stopAllActions();

}

void inCasthle5::createLink()
{
	//auto object1 = map1->getObjectGroup("object");
	link = Sprite::create("zeldaSprites/link/002.png");
	link->setPosition(linkPosition);
	_layer1->addChild(link, 7);


}

void inCasthle5::linkMoveUp(float dt)
{
	auto x = link->getPositionX();
	auto y = link->getPositionY();
	bool WB = Pbool(Vec2(x, y + 1));

	if (linkAtk)
		WB = true;

	if (!WB)
	{
		int x = link->getPositionX();
		int y = link->getPositionY();
		link->setPosition(Vec2(x, y + 1));
	}
}

void inCasthle5::linkMoveDown(float dt)
{
	auto x = link->getPositionX();
	auto y = link->getPositionY();
	bool WB = Pbool(Vec2(x, y - 1));

	if (linkAtk)
		WB = true;

	if (!WB)
	{
		int x = link->getPositionX();
		int y = link->getPositionY();
		link->setPosition(Vec2(x, y - 1));
	}
}

void inCasthle5::linkMoveLeft(float dt)
{
	auto x = link->getPositionX();
	auto y = link->getPositionY();
	bool WB = Pbool(Vec2(x - 1, y));

	if (linkAtk)
		WB = true;

	if (!WB)
	{
		int x = link->getPositionX();
		int y = link->getPositionY();
		link->setPosition(Vec2(x - 1, y));
	}
}

void inCasthle5::linkMoveRight(float dt)
{
	auto x = link->getPositionX();
	auto y = link->getPositionY();
	bool WB = Pbool(Vec2(x + 1, y));

	if (linkAtk)
		WB = true;

	if (!WB)
	{
		int x = link->getPositionX();
		int y = link->getPositionY();
		link->setPosition(Vec2(x + 1, y));
	}
}

cocos2d::Vec2 inCasthle5::tileCoordForPosition(cocos2d::Vec2 position)
{
	int x = position.x / map1->getTileSize().width;
	int y = ((map1->getMapSize().height * map1->getTileSize().height)
		- position.y) / map1->getTileSize().height;

	return Vec2(x, y);
}

bool inCasthle5::Pbool(cocos2d::Vec2 position)
{
	//현재 터치한 곳의 타일이 타일맵에서 어디에 있는가?
	Vec2 tileCoord = this->tileCoordForPosition(position);

	//위에서 구한 타일 정보에서 GID를 추출한다
	int tileGid = _bool1->getTileGIDAt(tileCoord);

	if (tileGid)
	{
		// 타일에서 GID에 해당하는 속성을 받아온다
		Value properties = map1->getPropertiesForGID(tileGid);

		if (!properties.isNull())
		{
			std::string wall = properties.asValueMap()["wall"].asString();
			//std::string inout = properties.asValueMap()["inout"].asString();
			if (wall == "YES")
			{
				// 터치한 타일의 정보가 벽일 경우 캐릭터 이동을 금지한다
				return true;
			}
		}
	}
}

void inCasthle5::Wbool(cocos2d::Vec2 position)
{

}

void inCasthle5::camera(float dt)
{
	auto follow1 = Follow::create(link, Rect(0, 0, 456, 240));
	_layer1->runAction(follow1);
}

void inCasthle5::uiNum()
{
#pragma region Luffi
	luffi[2] = inf.luffis / 100;
	luffi[1] = (inf.luffis - luffi[2] * 100) / 10;
	luffi[0] = inf.luffis % 10;

	auto NumPos = _ui->getObjectGroup("object");
	ValueMap luffi1 = NumPos->getObject("luffi1");
	ValueMap luffi10 = NumPos->getObject("luffi10");
	ValueMap luffi100 = NumPos->getObject("luffi100");

	int lx[3], ly[3];

	lx[0] = luffi1["x"].asInt() + 5;
	ly[0] = luffi1["y"].asInt();

	lx[1] = luffi10["x"].asInt() + 5;
	ly[1] = luffi10["y"].asInt();

	lx[2] = luffi100["x"].asInt() + 5;
	ly[2] = luffi100["y"].asInt();

	Vec2 luffiPos1(lx[0], ly[0]);
	Vec2 luffiPos2(lx[1], ly[1]);
	Vec2 luffiPos3(lx[2], ly[2]);

#pragma region liffi1
	switch (luffi[0])
	{
	case 0:
	{
		auto Nsp = Sprite::create("ui/0.png");
		Nsp->setPosition(Vec2(luffiPos1));
		_ui->addChild(Nsp);
	}
	break;
	case 1:
	{
		auto Nsp = Sprite::create("ui/1.png");
		Nsp->setPosition(Vec2(luffiPos1));
		_ui->addChild(Nsp);
	}
	break;
	case 2:
	{
		auto Nsp = Sprite::create("ui/2.png");
		Nsp->setPosition(Vec2(luffiPos1));
		_ui->addChild(Nsp);
	}
	break;
	case 3:
	{
		auto Nsp = Sprite::create("ui/3.png");
		Nsp->setPosition(Vec2(luffiPos1));
		_ui->addChild(Nsp);
	}
	break;
	case 4:
	{
		auto Nsp = Sprite::create("ui/4.png");
		Nsp->setPosition(Vec2(luffiPos1));
		_ui->addChild(Nsp);
	}
	break;
	case 5:
	{
		auto Nsp = Sprite::create("ui/5.png");
		Nsp->setPosition(Vec2(luffiPos1));
		_ui->addChild(Nsp);
	}
	break;
	case 6:
	{
		auto Nsp = Sprite::create("ui/6.png");
		Nsp->setPosition(Vec2(luffiPos1));
		_ui->addChild(Nsp);
	}
	break;
	case 7:
	{
		auto Nsp = Sprite::create("ui/7.png");
		Nsp->setPosition(Vec2(luffiPos1));
		_ui->addChild(Nsp);
	}
	break;
	case 8:
	{
		auto Nsp = Sprite::create("ui/8.png");
		Nsp->setPosition(Vec2(luffiPos1));
		_ui->addChild(Nsp);
	}
	break;
	case 9:
	{
		auto Nsp = Sprite::create("ui/9.png");
		Nsp->setPosition(Vec2(luffiPos1));
		_ui->addChild(Nsp);
	}
	break;
	default:
		break;
	}
#pragma endregion

#pragma region liffi10
	switch (luffi[1])
	{
	case 0:
	{
		auto Nsp = Sprite::create("ui/0.png");
		Nsp->setPosition(Vec2(luffiPos2));
		_ui->addChild(Nsp);
	}
	break;
	case 1:
	{
		auto Nsp = Sprite::create("ui/1.png");
		Nsp->setPosition(Vec2(luffiPos2));
		_ui->addChild(Nsp);
	}
	break;
	case 2:
	{
		auto Nsp = Sprite::create("ui/2.png");
		Nsp->setPosition(Vec2(luffiPos2));
		_ui->addChild(Nsp);
	}
	break;
	case 3:
	{
		auto Nsp = Sprite::create("ui/3.png");
		Nsp->setPosition(Vec2(luffiPos2));
		_ui->addChild(Nsp);
	}
	break;
	case 4:
	{
		auto Nsp = Sprite::create("ui/4.png");
		Nsp->setPosition(Vec2(luffiPos2));
		_ui->addChild(Nsp);
	}
	break;
	case 5:
	{
		auto Nsp = Sprite::create("ui/5.png");
		Nsp->setPosition(Vec2(luffiPos2));
		_ui->addChild(Nsp);
	}
	break;
	case 6:
	{
		auto Nsp = Sprite::create("ui/6.png");
		Nsp->setPosition(Vec2(luffiPos2));
		_ui->addChild(Nsp);
	}
	break;
	case 7:
	{
		auto Nsp = Sprite::create("ui/7.png");
		Nsp->setPosition(Vec2(luffiPos2));
		_ui->addChild(Nsp);
	}
	break;
	case 8:
	{
		auto Nsp = Sprite::create("ui/8.png");
		Nsp->setPosition(Vec2(luffiPos2));
		_ui->addChild(Nsp);
	}
	break;
	case 9:
	{
		auto Nsp = Sprite::create("ui/9.png");
		Nsp->setPosition(Vec2(luffiPos2));
		_ui->addChild(Nsp);
	}
	break;
	default:
		break;
	}
#pragma endregion

#pragma region liffi100
	switch (luffi[2])
	{
	case 0:
	{
		auto Nsp = Sprite::create("ui/0.png");
		Nsp->setPosition(Vec2(luffiPos3));
		_ui->addChild(Nsp);
	}
	break;
	case 1:
	{
		auto Nsp = Sprite::create("ui/1.png");
		Nsp->setPosition(Vec2(luffiPos3));
		_ui->addChild(Nsp);
	}
	break;
	case 2:
	{
		auto Nsp = Sprite::create("ui/2.png");
		Nsp->setPosition(Vec2(luffiPos3));
		_ui->addChild(Nsp);
	}
	break;
	case 3:
	{
		auto Nsp = Sprite::create("ui/3.png");
		Nsp->setPosition(Vec2(luffiPos3));
		_ui->addChild(Nsp);
	}
	break;
	case 4:
	{
		auto Nsp = Sprite::create("ui/4.png");
		Nsp->setPosition(Vec2(luffiPos3));
		_ui->addChild(Nsp);
	}
	break;
	case 5:
	{
		auto Nsp = Sprite::create("ui/5.png");
		Nsp->setPosition(Vec2(luffiPos3));
		_ui->addChild(Nsp);
	}
	break;
	case 6:
	{
		auto Nsp = Sprite::create("ui/6.png");
		Nsp->setPosition(Vec2(luffiPos3));
		_ui->addChild(Nsp);
	}
	break;
	case 7:
	{
		auto Nsp = Sprite::create("ui/7.png");
		Nsp->setPosition(Vec2(luffiPos3));
		_ui->addChild(Nsp);
	}
	break;
	case 8:
	{
		auto Nsp = Sprite::create("ui/8.png");
		Nsp->setPosition(Vec2(luffiPos3));
		_ui->addChild(Nsp);
	}
	break;
	case 9:
	{
		auto Nsp = Sprite::create("ui/9.png");
		Nsp->setPosition(Vec2(luffiPos3));
		_ui->addChild(Nsp);
	}
	break;
	default:
		break;
	}
#pragma endregion
#pragma endregion

#pragma region Bomb
	int bomb[2]{ 0,0 };

	ValueMap bomb1 = NumPos->getObject("bomb1");
	ValueMap bomb10 = NumPos->getObject("bomb10");

	int bx[2], by[2];

	bx[0] = bomb1["x"].asInt() + 3;
	by[0] = bomb1["y"].asInt();

	bx[1] = bomb10["x"].asInt() + 3;
	by[1] = bomb10["y"].asInt();

	Vec2 bombPos1(bx[0], by[0]);
	Vec2 bombPos2(bx[1], by[1]);

#pragma region bomb1
	switch (bomb[0])
	{
	case 0:
	{
		auto Nsp = Sprite::create("ui/0.png");
		Nsp->setPosition(Vec2(bombPos1));
		_ui->addChild(Nsp);
	}
	break;
	case 1:
	{
		auto Nsp = Sprite::create("ui/1.png");
		Nsp->setPosition(Vec2(bombPos1));
		_ui->addChild(Nsp);
	}
	break;
	case 2:
	{
		auto Nsp = Sprite::create("ui/2.png");
		Nsp->setPosition(Vec2(bombPos1));
		_ui->addChild(Nsp);
	}
	break;
	case 3:
	{
		auto Nsp = Sprite::create("ui/3.png");
		Nsp->setPosition(Vec2(bombPos1));
		_ui->addChild(Nsp);
	}
	break;
	case 4:
	{
		auto Nsp = Sprite::create("ui/4.png");
		Nsp->setPosition(Vec2(bombPos1));
		_ui->addChild(Nsp);
	}
	break;
	case 5:
	{
		auto Nsp = Sprite::create("ui/5.png");
		Nsp->setPosition(Vec2(bombPos1));
		_ui->addChild(Nsp);
	}
	break;
	case 6:
	{
		auto Nsp = Sprite::create("ui/6.png");
		Nsp->setPosition(Vec2(bombPos1));
		_ui->addChild(Nsp);
	}
	break;
	case 7:
	{
		auto Nsp = Sprite::create("ui/7.png");
		Nsp->setPosition(Vec2(bombPos1));
		_ui->addChild(Nsp);
	}
	break;
	case 8:
	{
		auto Nsp = Sprite::create("ui/8.png");
		Nsp->setPosition(Vec2(bombPos1));
		_ui->addChild(Nsp);
	}
	break;
	case 9:
	{
		auto Nsp = Sprite::create("ui/9.png");
		Nsp->setPosition(Vec2(bombPos1));
		_ui->addChild(Nsp);
	}
	break;
	default:
		break;
	}
#pragma endregion

#pragma region bomb10
	switch (bomb[1])
	{
	case 0:
	{
		auto Nsp = Sprite::create("ui/0.png");
		Nsp->setPosition(Vec2(bombPos2));
		_ui->addChild(Nsp);
	}
	break;
	case 1:
	{
		auto Nsp = Sprite::create("ui/1.png");
		Nsp->setPosition(Vec2(bombPos2));
		_ui->addChild(Nsp);
	}
	break;
	case 2:
	{
		auto Nsp = Sprite::create("ui/2.png");
		Nsp->setPosition(Vec2(bombPos2));
		_ui->addChild(Nsp);
	}
	break;
	case 3:
	{
		auto Nsp = Sprite::create("ui/3.png");
		Nsp->setPosition(Vec2(bombPos2));
		_ui->addChild(Nsp);
	}
	break;
	case 4:
	{
		auto Nsp = Sprite::create("ui/4.png");
		Nsp->setPosition(Vec2(bombPos2));
		_ui->addChild(Nsp);
	}
	break;
	case 5:
	{
		auto Nsp = Sprite::create("ui/5.png");
		Nsp->setPosition(Vec2(bombPos2));
		_ui->addChild(Nsp);
	}
	break;
	case 6:
	{
		auto Nsp = Sprite::create("ui/6.png");
		Nsp->setPosition(Vec2(bombPos2));
		_ui->addChild(Nsp);
	}
	break;
	case 7:
	{
		auto Nsp = Sprite::create("ui/7.png");
		Nsp->setPosition(Vec2(bombPos2));
		_ui->addChild(Nsp);
	}
	break;
	case 8:
	{
		auto Nsp = Sprite::create("ui/8.png");
		Nsp->setPosition(Vec2(bombPos2));
		_ui->addChild(Nsp);
	}
	break;
	case 9:
	{
		auto Nsp = Sprite::create("ui/9.png");
		Nsp->setPosition(Vec2(bombPos2));
		_ui->addChild(Nsp);
	}
	break;
	default:
		break;
	}
#pragma endregion
#pragma endregion

#pragma region Arrow
	int arrow[2]{ 0,0 };

	ValueMap arrow1 = NumPos->getObject("arrow1");
	ValueMap arrow10 = NumPos->getObject("arrow10");

	int ax[2], ay[2];

	ax[0] = arrow1["x"].asInt() + 3;
	ay[0] = arrow1["y"].asInt();

	ax[1] = arrow10["x"].asInt() + 3;
	ay[1] = arrow10["y"].asInt();

	Vec2 arrowPos1(ax[0], ay[0]);
	Vec2 arrowPos2(ax[1], ay[1]);

#pragma region arrow1
	switch (arrow[0])
	{
	case 0:
	{
		auto Nsp = Sprite::create("ui/0.png");
		Nsp->setPosition(Vec2(arrowPos1));
		_ui->addChild(Nsp);
	}
	break;
	case 1:
	{
		auto Nsp = Sprite::create("ui/1.png");
		Nsp->setPosition(Vec2(arrowPos1));
		_ui->addChild(Nsp);
	}
	break;
	case 2:
	{
		auto Nsp = Sprite::create("ui/2.png");
		Nsp->setPosition(Vec2(arrowPos1));
		_ui->addChild(Nsp);
	}
	break;
	case 3:
	{
		auto Nsp = Sprite::create("ui/3.png");
		Nsp->setPosition(Vec2(arrowPos1));
		_ui->addChild(Nsp);
	}
	break;
	case 4:
	{
		auto Nsp = Sprite::create("ui/4.png");
		Nsp->setPosition(Vec2(arrowPos1));
		_ui->addChild(Nsp);
	}
	break;
	case 5:
	{
		auto Nsp = Sprite::create("ui/5.png");
		Nsp->setPosition(Vec2(arrowPos1));
		_ui->addChild(Nsp);
	}
	break;
	case 6:
	{
		auto Nsp = Sprite::create("ui/6.png");
		Nsp->setPosition(Vec2(arrowPos1));
		_ui->addChild(Nsp);
	}
	break;
	case 7:
	{
		auto Nsp = Sprite::create("ui/7.png");
		Nsp->setPosition(Vec2(arrowPos1));
		_ui->addChild(Nsp);
	}
	break;
	case 8:
	{
		auto Nsp = Sprite::create("ui/8.png");
		Nsp->setPosition(Vec2(arrowPos1));
		_ui->addChild(Nsp);
	}
	break;
	case 9:
	{
		auto Nsp = Sprite::create("ui/9.png");
		Nsp->setPosition(Vec2(arrowPos1));
		_ui->addChild(Nsp);
	}
	break;
	default:
		break;
	}
#pragma endregion

#pragma region arrow10
	switch (arrow[1])
	{
	case 0:
	{
		auto Nsp = Sprite::create("ui/0.png");
		Nsp->setPosition(Vec2(arrowPos2));
		_ui->addChild(Nsp);
	}
	break;
	case 1:
	{
		auto Nsp = Sprite::create("ui/1.png");
		Nsp->setPosition(Vec2(arrowPos2));
		_ui->addChild(Nsp);
	}
	break;
	case 2:
	{
		auto Nsp = Sprite::create("ui/2.png");
		Nsp->setPosition(Vec2(arrowPos2));
		_ui->addChild(Nsp);
	}
	break;
	case 3:
	{
		auto Nsp = Sprite::create("ui/3.png");
		Nsp->setPosition(Vec2(arrowPos2));
		_ui->addChild(Nsp);
	}
	break;
	case 4:
	{
		auto Nsp = Sprite::create("ui/4.png");
		Nsp->setPosition(Vec2(arrowPos2));
		_ui->addChild(Nsp);
	}
	break;
	case 5:
	{
		auto Nsp = Sprite::create("ui/5.png");
		Nsp->setPosition(Vec2(arrowPos2));
		_ui->addChild(Nsp);
	}
	break;
	case 6:
	{
		auto Nsp = Sprite::create("ui/6.png");
		Nsp->setPosition(Vec2(arrowPos2));
		_ui->addChild(Nsp);
	}
	break;
	case 7:
	{
		auto Nsp = Sprite::create("ui/7.png");
		Nsp->setPosition(Vec2(arrowPos2));
		_ui->addChild(Nsp);
	}
	break;
	case 8:
	{
		auto Nsp = Sprite::create("ui/8.png");
		Nsp->setPosition(Vec2(arrowPos2));
		_ui->addChild(Nsp);
	}
	break;
	case 9:
	{
		auto Nsp = Sprite::create("ui/9.png");
		Nsp->setPosition(Vec2(arrowPos2));
		_ui->addChild(Nsp);
	}
	break;
	default:
		break;
	}
#pragma endregion
#pragma endregion

#pragma region Key
	int key = 0;

	ValueMap keyNum = NumPos->getObject("key");

	int kx, ky;

	kx = keyNum["x"].asInt() + 3;
	ky = keyNum["y"].asInt();

	Vec2 keyPos(kx, ky);

#pragma region arrow1
	switch (key)
	{
	case 0:
	{
		auto Nsp = Sprite::create("ui/0.png");
		Nsp->setPosition(Vec2(keyPos));
		_ui->addChild(Nsp);
	}
	break;
	case 1:
	{
		auto Nsp = Sprite::create("ui/1.png");
		Nsp->setPosition(Vec2(keyPos));
		_ui->addChild(Nsp);
	}
	break;
	case 2:
	{
		auto Nsp = Sprite::create("ui/2.png");
		Nsp->setPosition(Vec2(keyPos));
		_ui->addChild(Nsp);
	}
	break;
	case 3:
	{
		auto Nsp = Sprite::create("ui/3.png");
		Nsp->setPosition(Vec2(keyPos));
		_ui->addChild(Nsp);
	}
	break;
	case 4:
	{
		auto Nsp = Sprite::create("ui/4.png");
		Nsp->setPosition(Vec2(keyPos));
		_ui->addChild(Nsp);
	}
	break;
	case 5:
	{
		auto Nsp = Sprite::create("ui/5.png");
		Nsp->setPosition(Vec2(keyPos));
		_ui->addChild(Nsp);
	}
	break;
	case 6:
	{
		auto Nsp = Sprite::create("ui/6.png");
		Nsp->setPosition(Vec2(keyPos));
		_ui->addChild(Nsp);
	}
	break;
	case 7:
	{
		auto Nsp = Sprite::create("ui/7.png");
		Nsp->setPosition(Vec2(keyPos));
		_ui->addChild(Nsp);
	}
	break;
	case 8:
	{
		auto Nsp = Sprite::create("ui/8.png");
		Nsp->setPosition(Vec2(keyPos));
		_ui->addChild(Nsp);
	}
	break;
	case 9:
	{
		auto Nsp = Sprite::create("ui/9.png");
		Nsp->setPosition(Vec2(keyPos));
		_ui->addChild(Nsp);
	}
	break;
	default:
		break;
	}
#pragma endregion
#pragma endregion
	ValueMap heart1 = NumPos->getObject("heart1");
	ValueMap heart2 = NumPos->getObject("heart2");
	ValueMap heart3 = NumPos->getObject("heart3");

	int hx1 = heart1["x"].asInt() + 5;
	int hx2 = heart2["x"].asInt() + 5;
	int hx3 = heart3["x"].asInt() + 5;
	int hy1 = heart1["y"].asInt();
	int hy2 = heart2["y"].asInt();
	int hy3 = heart3["y"].asInt();

	inf.heartM(Vec2(hx1, hy1), Vec2(hx2, hy2), Vec2(hx3, hy3), _ui);
}

void inCasthle5::linkAttcks(Ref*sender)
{

}
