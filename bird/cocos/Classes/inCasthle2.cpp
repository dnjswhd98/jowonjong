#include "inCasthle2.h"
#include "inCasthle3.h"

USING_NS_CC;

cocos2d::Scene * inCasthle2::createScene()
{
	return inCasthle2::create();
}

bool inCasthle2::init()
{
	if (!Scene::init())return false;

	Infor inf;
	inf.luffis;

	mapIndex = 0;

	Sound son;
	son.linkEfstop();
	son.playCasthle();

	Enemy ene;

	auto visible = _director->getVisibleSize();

	_layer1 = Layer::create();
	_layer2 = Layer::create();

	map1 = TMXTiledMap::create("zeldaSprites/map/casthle2.tmx");
	map2 = TMXTiledMap::create("zeldaSprites/map/casthle5_1.tmx");
	auto object1 = map1->getObjectGroup("object");
	auto spwanPoint = object1->getObject("start");

	_bool1 = map1->getLayer("metaset");
	_bool1->setVisible(false);
	_layer1->addChild(map1, 0);
	_layer1->addChild(map2, 15);

	int x = spwanPoint["x"].asInt();
	int y = spwanPoint["y"].asInt();
	
	linkPosition = Vec2(x, y);

	this->createLink();

	//
	//auto lfAc = MoveBy::create(1, Vec2(x-ex,y-ey));
	//link->runAction(lfAc);

	_ui = TMXTiledMap::create("zeldaSprites/map/ui.tmx");
	_ui->setPosition(Vec2(0, 140));
	_layer2->addChild(_ui, 50);

	schedule(schedule_selector(inCasthle2::camera));

	this->addChild(_layer1);
	this->addChild(_layer2);

	auto En1 = object1->getObject("enemy1");
	auto En2 = object1->getObject("enemy2");
	auto En3 = object1->getObject("enemy3");
	auto En4 = object1->getObject("enemy4");
	auto En5 = object1->getObject("enemy5");
	auto En6 = object1->getObject("enemy6");
	auto En7 = object1->getObject("enemy7");


	int Ex1 = En1["x"].asInt();
	int Ex2 = En2["x"].asInt();
	int Ex3 = En3["x"].asInt();
	int Ex4 = En4["x"].asInt();
	int Ex5 = En5["x"].asInt();
	int Ex6 = En6["x"].asInt();
	int Ex7 = En7["x"].asInt();
	int Ey1 = En1["y"].asInt();
	int Ey2 = En2["y"].asInt();
	int Ey3 = En3["y"].asInt();
	int Ey4 = En4["y"].asInt();
	int Ey5 = En5["y"].asInt();
	int Ey6 = En6["y"].asInt();
	int Ey7 = En7["y"].asInt();

	ene.enemyK1(Ex1, Ey1, _layer1);
	ene.enemyK1(Ex2, Ey2, _layer1);
	ene.enemyK1(Ex3, Ey3, _layer1);
	ene.enemyK1(Ex4, Ey4, _layer1);
	ene.enemyK1(Ex5, Ey5, _layer1);
	ene.enemyK1(Ex6, Ey6, _layer1);
	ene.enemyK1(Ex7, Ey7, _layer1);

	this->uiNum();

	return true;
}

void inCasthle2::onEnter()
{
	Scene::onEnter();

	_listener = EventListenerKeyboard::create();

	_listener->onKeyPressed = CC_CALLBACK_2(inCasthle2::onKeyPressed, this);
	_listener->onKeyReleased = CC_CALLBACK_2(inCasthle2::onKeyReleased, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(_listener, this);
}

void inCasthle2::onExit()
{
	_eventDispatcher->removeAllEventListeners();
	Scene::onExit();
}

void inCasthle2::onKeyPressed(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event * event)
{
	switch (keycode)
	{
	case cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW:
	{
		link->stopAllActions();

		schedule(schedule_selector(inCasthle2::linkMoveUp));
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

		schedule(schedule_selector(inCasthle2::linkMoveDown));
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

		schedule(schedule_selector(inCasthle2::linkMoveLeft));
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

		schedule(schedule_selector(inCasthle2::linkMoveRight));
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

		link->stopAllActions();

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

void inCasthle2::onKeyReleased(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event * event)
{
	switch (keycode)
	{
	case cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW:
	{
		unschedule(schedule_selector(inCasthle2::linkMoveUp));
	}
	break;
	case cocos2d::EventKeyboard::KeyCode::KEY_DOWN_ARROW:
	{
		unschedule(schedule_selector(inCasthle2::linkMoveDown));
	}
	break;
	case cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW:
	{
		unschedule(schedule_selector(inCasthle2::linkMoveLeft));
	}
	break;
	case cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
	{
		unschedule(schedule_selector(inCasthle2::linkMoveRight));
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

void inCasthle2::createLink()
{
	//auto object1 = map1->getObjectGroup("object");
	link = Sprite::create("zeldaSprites/link/002.png");
	link->setPosition(linkPosition);
	_layer1->addChild(link, 7);


}

void inCasthle2::linkMoveUp(float dt)
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

void inCasthle2::linkMoveDown(float dt)
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

void inCasthle2::linkMoveLeft(float dt)
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

void inCasthle2::linkMoveRight(float dt)
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

cocos2d::Vec2 inCasthle2::tileCoordForPosition(cocos2d::Vec2 position)
{
	int x = position.x / map1->getTileSize().width;
	int y = ((map1->getMapSize().height * map1->getTileSize().height)
		- position.y) / map1->getTileSize().height;

	return Vec2(x, y);
}

bool inCasthle2::Pbool(cocos2d::Vec2 position)
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

void inCasthle2::Wbool(cocos2d::Vec2 position)
{

}

void inCasthle2::camera(float dt)
{
	auto object1 = map1->getObjectGroup("object");

#pragma region nextPos
	ValueMap next1_2 = object1->getObject("next1-2");
	ValueMap next1_2_1 = object1->getObject("next1-2-1");
	ValueMap next2_1 = object1->getObject("next2-1");
	ValueMap next2_3 = object1->getObject("next2-3");
	ValueMap next3_2 = object1->getObject("next3-2");
	ValueMap next3_4 = object1->getObject("next3-4");
	ValueMap next4_3 = object1->getObject("next4-3");
	ValueMap next4_5 = object1->getObject("next4-5");
	ValueMap next5_4 = object1->getObject("next5-4");
	ValueMap next5_6 = object1->getObject("next5-6");
	ValueMap next5_6_1 = object1->getObject("next5-6(1)");
	ValueMap next6_5 = object1->getObject("next6-5");
	ValueMap next6_5_1 = object1->getObject("next6-5(1)");
	ValueMap next6_1 = object1->getObject("next6-1");
	ValueMap next1_6 = object1->getObject("next1-6");

	int Nx1_2 = next1_2["x"].asInt();
	int Ny1_2 = next1_2["y"].asInt();
	int Nw1_2 = next1_2["width"].asInt();
	int Nh1_2 = next1_2["height"].asInt();

	int Nx2_1 = next2_1["x"].asInt();
	int Ny2_1 = next2_1["y"].asInt();
	int Nw2_1 = next2_1["width"].asInt();
	int Nh2_1 = next2_1["height"].asInt();

	int Nx2_3 = next2_3["x"].asInt();
	int Ny2_3 = next2_3["y"].asInt();
	int Nw2_3 = next2_3["width"].asInt();
	int Nh2_3 = next2_3["height"].asInt();

	int Nx3_2 = next3_2["x"].asInt();
	int Ny3_2 = next3_2["y"].asInt();
	int Nw3_2 = next3_2["width"].asInt();
	int Nh3_2 = next3_2["height"].asInt();

	int Nx3_4 = next3_4["x"].asInt();
	int Ny3_4 = next3_4["y"].asInt();
	int Nw3_4 = next3_4["width"].asInt();
	int Nh3_4 = next3_4["height"].asInt();

	int Nx4_3 = next4_3["x"].asInt();
	int Ny4_3 = next4_3["y"].asInt();
	int Nw4_3 = next4_3["width"].asInt();
	int Nh4_3 = next4_3["height"].asInt();

	int Nx4_5 = next4_5["x"].asInt();
	int Ny4_5 = next4_5["y"].asInt();
	int Nw4_5 = next4_5["width"].asInt();
	int Nh4_5 = next4_5["height"].asInt();

	int Nx5_4 = next5_4["x"].asInt();
	int Ny5_4 = next5_4["y"].asInt();
	int Nw5_4 = next5_4["width"].asInt();
	int Nh5_4 = next5_4["height"].asInt();

	int Nx5_6 = next5_6["x"].asInt();
	int Ny5_6 = next5_6["y"].asInt();
	int Nw5_6 = next5_6["width"].asInt();
	int Nh5_6 = next5_6["height"].asInt();

	int Nx6_5 = next6_5["x"].asInt();
	int Ny6_5 = next6_5["y"].asInt();
	int Nw6_5 = next6_5["width"].asInt();
	int Nh6_5 = next6_5["height"].asInt();

	int Nx6_1 = next6_1["x"].asInt();
	int Ny6_1 = next6_1["y"].asInt();
	int Nw6_1 = next6_1["width"].asInt();
	int Nh6_1 = next6_1["height"].asInt();

	Rect _next1_2(Nx1_2, Ny1_2, Nw1_2, Nh1_2);
	Rect _next2_1(Nx2_1, Ny2_1, Nw2_1, Nh2_1);
	Rect _next2_3(Nx2_3, Ny2_3, Nw2_3, Nh2_3);
	Rect _next3_2(Nx3_2, Ny3_2, Nw3_2, Nh3_2);
	Rect _next3_4(Nx3_4, Ny3_4, Nw3_4, Nh3_4);
	Rect _next4_3(Nx4_3, Ny4_3, Nw4_3, Nh4_3);
	Rect _next4_5(Nx4_5, Ny4_5, Nw4_5, Nh4_5);
	Rect _next5_4(Nx5_4, Ny5_4, Nw5_4, Nh5_4);
	Rect _next5_6(Nx5_6, Ny5_6, Nw5_6, Nh5_6);
	Rect _next6_5(Nx6_5, Ny6_5, Nw6_5, Nh6_5);
	Rect _next6_1(Nx6_1, Ny6_1, Nw6_1, Nh6_1);

#pragma endregion

	int lx = link->getPositionX();
	int ly = link->getPositionY();

	if (_next1_2.intersectsRect(link->getBoundingBox()))
	{
		link->setPosition(Vec2(lx - 50, ly));
		mapIndex++;
	}
	else if (_next2_1.intersectsRect(link->getBoundingBox()))
	{
		link->setPosition(Vec2(lx + 50, ly));
		mapIndex--;
	}
	else if (_next2_3.intersectsRect(link->getBoundingBox()))
	{
		link->setPosition(Vec2(lx, ly+105));
		mapIndex++;
	}
	else if (_next3_2.intersectsRect(link->getBoundingBox()))
	{
		link->setPosition(Vec2(lx , ly-105));
		mapIndex--;
	}
	else if (_next3_4.intersectsRect(link->getBoundingBox()))
	{
		link->setPosition(Vec2(lx+50, ly));
		mapIndex++;
	}
	else if (_next4_3.intersectsRect(link->getBoundingBox()))
	{
		link->setPosition(Vec2(lx-50, ly));
		mapIndex--;
	}
	else if (_next4_5.intersectsRect(link->getBoundingBox()))
	{
		link->setPosition(Vec2(lx+50, ly));
		mapIndex++;
	}
	else if (_next5_4.intersectsRect(link->getBoundingBox()))
	{
		link->setPosition(Vec2(lx-50, ly));
		mapIndex--;
	}
	else if (_next5_6.intersectsRect(link->getBoundingBox()))
	{
		link->setPosition(Vec2(lx, ly - 105));
		mapIndex++;
	}
	else if (_next6_5.intersectsRect(link->getBoundingBox()))
	{
		link->setPosition(Vec2(lx, ly - 105));
		mapIndex--;
	}
	else if (_next6_1.intersectsRect(link->getBoundingBox()))
	{
		link->setPosition(Vec2(lx-50, ly));
		mapIndex = 0;
	}

	auto follow1 = Follow::create(link, Rect(272, 0, 512, 544));
	auto follow2 = Follow::create(link, Rect(0, 0, 256, 528));
	auto follow3 = Follow::create(link, Rect(0, 512, 256, 480));
	auto follow4 = Follow::create(link, Rect(256, 784, 512, 176));
	auto follow5 = Follow::create(link, Rect(768, 496, 320, 480));
	auto follow6 = Follow::create(link, Rect(768, 0, 384, 480));

	//auto Mac1 = MoveBy::create(1.0, Vec2(0, _director->getVisibleSize().height));
	
	switch (mapIndex)
	{
	case 0:
	{
		_layer1->runAction(follow1);
	}
	break;
	case 1:
	{
		_layer1->stopAllActions();
		_layer1->runAction(follow2);
	}
		break;
	case 2:
	{
		_layer1->stopAllActions();
		_layer1->runAction(follow3);
	}
	break;
	case 3:
	{
		_layer1->stopAllActions();
		_layer1->runAction(follow4);
	}
	break;
	case 4:
	{
		_layer1->stopAllActions();
		_layer1->runAction(follow5);
	}
	break;
	case 5:
	{
		_layer1->stopAllActions();
		_layer1->runAction(follow6);
	}
	break;
	default:
		break;
	}
}

void inCasthle2::uiNum()
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

void inCasthle2::linkAttcks(Ref*sender)
{
	
}

void inCasthle2::nextScene()
{
	_director->pushScene(inCasthle3::createScene());
	//_director->Scene(inCasthle3::createScene())
}
