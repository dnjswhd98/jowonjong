#include "inCasthle1.h"
#include "Infor.h"
#include "Sound.h"
#include "overwirld2.h"

USING_NS_CC;

cocos2d::Scene * inCasthle1::createScene()
{
	return inCasthle1::create();
}

bool inCasthle1::init()
{
	if (!Scene::init())return false;

	Infor inf;

	inf.luffis;

	mapIndex = 0;

	auto visible = _director->getVisibleSize();

	_layer1 = Layer::create();
	_layer2 = Layer::create();

	map1 = TMXTiledMap::create("zeldaSprites/map/casthle1.tmx");
	map2 = TMXTiledMap::create("zeldaSprites/map/casthle1_1.tmx");
	auto object1 = map1->getObjectGroup("object");
	ValueMap spwanPoint = object1->getObject("fallstart");
	ValueMap spwanEnd = object1->getObject("fallend");

	_bool1 = map1->getLayer("metaset1");
	_bool1->setVisible(false);
	TMXLayer*bg2 = map1->getLayer("bg2");
	bg2->setZOrder(10);
	_layer1->addChild(map1, 0);
	_layer1->addChild(map2, 15);

	int x = spwanPoint["x"].asInt();
	int y = spwanPoint["y"].asInt();
	int ex = spwanEnd["x"].asInt();
	int ey = spwanEnd["y"].asInt();
	linkPosition = Vec2(x, y);	

	this->createLink();


	ValueMap Npc1M = object1->getObject("npc1");
	ValueMap Enemy1M = object1->getObject("enemy1");
	ValueMap Enemy2M = object1->getObject("enemy2");
	int nx = Npc1M["x"].asInt();
	int enx1 = Enemy1M["x"].asInt();
	int enx2 = Enemy2M["x"].asInt();
	int ny = Npc1M["y"].asInt();
	int eny1 = Enemy1M["y"].asInt();
	int eny2 = Enemy2M["y"].asInt();

	enemy[0].npcS1(nx, ny, _layer1);
	enemy[1].enemyK1(enx1, eny1, _layer1);
	enemy[2].enemyK1(enx2, eny2, _layer1);
	enemy[3].npc1 = Sprite::create("zeldaSprites/npc1/npc4.png");
	enemy[3].npc1->setPosition(Vec2(nx,ny));
	enemy[3].npc1->setVisible(false);
	_layer1->addChild(enemy[3].npc1);

	auto animation = Animation::create();

	animation->setDelayPerUnit(0.8f);

	animation->addSpriteFrameWithFile("zeldaSprites/knight1/005.png");
	animation->addSpriteFrameWithFile("zeldaSprites/knight1/006.png");
	animation->addSpriteFrameWithFile("zeldaSprites/knight1/005.png");
	animation->addSpriteFrameWithFile("zeldaSprites/knight1/005.png");
	
	auto animate = Animate::create(animation);
	auto _krep = RepeatForever::create(animate);

	enemy[1].knight1->runAction(_krep);
	enemy[2].knight1->runAction(_krep->clone());
	
	auto lfAc = MoveBy::create(0.5, Vec2(0,-100));
	link->runAction(lfAc);

	_ui = TMXTiledMap::create("zeldaSprites/map/ui.tmx");
	_ui->setPosition(Vec2(0, 140));
	_layer2->addChild(_ui, 10);

	schedule(schedule_selector(inCasthle1::dameged));
	schedule(schedule_selector(inCasthle1::camera));

	this->addChild(_layer1);
	this->addChild(_layer2);

	schedule(schedule_selector(inCasthle1::npcEvent));

	this->uiNum(0);
	this->Enemymove();

	schedule(schedule_selector(inCasthle1::nextMap));

	linkW = false;

	return true;
}

void inCasthle1::onEnter()
{
	Scene::onEnter();

	_listener = EventListenerKeyboard::create();

	_listener->onKeyPressed = CC_CALLBACK_2(inCasthle1::onKeyPressed, this);
	_listener->onKeyReleased = CC_CALLBACK_2(inCasthle1::onKeyReleased, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(_listener, this);
}

void inCasthle1::onExit()
{
	_eventDispatcher->removeAllEventListeners();
	Scene::onExit();
}

void inCasthle1::onKeyPressed(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event * event)
{
	if (link->getPositionY() < 376)
	{
		switch (keycode)
		{
		case cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW:
		{
			link->stopAllActions();
			schedule(schedule_selector(inCasthle1::linkMoveUp));
			if (linkW)
			{
				linkDirec = 0;
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

			}
			else
			{

			auto animation = Animation::create();

			animation->setDelayPerUnit(0.05f);

			animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/linkUnwapone/Umove/017.png");
			animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/linkUnwapone/Umove/018.png");
			animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/linkUnwapone/Umove/019.png");
			animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/linkUnwapone/Umove/020.png");
			animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/linkUnwapone/Umove/021.png");
			animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/linkUnwapone/Umove/022.png");
			animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/linkUnwapone/Umove/023.png");
			animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/linkUnwapone/Umove/024.png");

			auto animate = Animate::create(animation);

			auto rep = RepeatForever::create(animate);
			link->runAction(rep);
			}
		}
		break;
		case cocos2d::EventKeyboard::KeyCode::KEY_DOWN_ARROW:
		{
			link->stopAllActions();

			schedule(schedule_selector(inCasthle1::linkMoveDown));
			if (linkW)
			{
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
			else
			{

			auto animation = Animation::create();

			animation->setDelayPerUnit(0.05f);

			animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/linkUnwapone/Dmove/025.png");
			animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/linkUnwapone/Dmove/026.png");
			animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/linkUnwapone/Dmove/027.png");
			animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/linkUnwapone/Dmove/028.png");
			animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/linkUnwapone/Dmove/029.png");
			animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/linkUnwapone/Dmove/030.png");
			animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/linkUnwapone/Dmove/031.png");
			animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/linkUnwapone/Dmove/032.png");

			auto animate = Animate::create(animation);

			auto rep = RepeatForever::create(animate);
			link->runAction(rep);
			}
		}
		break;
		case cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		{
			link->stopAllActions();

			schedule(schedule_selector(inCasthle1::linkMoveLeft));
			if (linkW)
			{
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
			else
			{

			auto animation = Animation::create();

			animation->setDelayPerUnit(0.05f);

			animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/linkUnwapone/Lmove/001.png");
			animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/linkUnwapone/Lmove/002.png");
			animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/linkUnwapone/Lmove/003.png");
			animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/linkUnwapone/Lmove/004.png");
			animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/linkUnwapone/Lmove/005.png");
			animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/linkUnwapone/Lmove/006.png");
			animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/linkUnwapone/Lmove/007.png");
			animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/linkUnwapone/Lmove/008.png");

			auto animate = Animate::create(animation);

			auto rep = RepeatForever::create(animate);
			link->runAction(rep);
			}
		}
		break;
		case cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		{
			link->stopAllActions();

			schedule(schedule_selector(inCasthle1::linkMoveRight));
			if (linkW)
			{
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
			else
			{
				auto animation = Animation::create();

				animation->setDelayPerUnit(0.05f);

				animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/linkUnwapone/Rmove/009.png");
				animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/linkUnwapone/Rmove/010.png");
				animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/linkUnwapone/Rmove/011.png");
				animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/linkUnwapone/Rmove/012.png");
				animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/linkUnwapone/Rmove/013.png");
				animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/linkUnwapone/Rmove/014.png");
				animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/linkUnwapone/Rmove/015.png");
				animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/linkUnwapone/Rmove/016.png");

				auto animate = Animate::create(animation);

				auto rep = RepeatForever::create(animate);
				link->runAction(rep);
			}
		}
		break;
		case cocos2d::EventKeyboard::KeyCode::KEY_Z:
		{
			if (link->getBoundingBox().intersectsRect(enemy[0].npc1->getBoundingBox()))
			{
				link->stopAllActions();
				enemy[0].npc1->setVisible(false);
				enemy[3].npc1->setVisible(true);

				auto Lanimation = Animation::create();
				Lanimation->setDelayPerUnit(0.05f);

				Lanimation->addSpriteFrameWithFile("zeldaSprites/link/getweapon.png");
				auto Lanimate = Animate::create(Lanimation);
				link->runAction(Lanimate);


				Sound sun;
				sun.linkEf("sound/SoundEffects/itemget1.wav");
				linkW = true;

			}
			if (linkW && !link->getBoundingBox().intersectsRect(enemy[0].npc1->getBoundingBox()))
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
			break;
			}
		default:
			break;
		}
		}
	
	}
}

void inCasthle1::onKeyReleased(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event * event)
{
	switch (keycode)
	{
	case cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW:
	{
		unschedule(schedule_selector(inCasthle1::linkMoveUp));
	}
	break;
	case cocos2d::EventKeyboard::KeyCode::KEY_DOWN_ARROW:
	{
		unschedule(schedule_selector(inCasthle1::linkMoveDown));
	}
	break;
	case cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW:
	{
		unschedule(schedule_selector(inCasthle1::linkMoveLeft));
	}
	break;
	case cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
	{
		unschedule(schedule_selector(inCasthle1::linkMoveRight));
	}
	break;
	case cocos2d::EventKeyboard::KeyCode::KEY_Z:
	{
		linkAtk = false;
	}
	default:
		break;
	}
	//link->stopAllActions();

}

void inCasthle1::createLink()
{
	//auto object1 = map1->getObjectGroup("object");
	link = Sprite::create("zeldaSprites/link/001.png");
	link->setPosition(linkPosition);
	_layer1->addChild(link,7);

	
}

void inCasthle1::linkMoveUp(float dt)
{
	auto x = link->getPositionX();
	auto y = link->getPositionY();
	bool WB = Pbool(Vec2(x, y + 1));

	if (!WB)
	{
		int x = link->getPositionX();
		int y = link->getPositionY();
		link->setPosition(Vec2(x, y + 1));
	}
}

void inCasthle1::linkMoveDown(float dt)
{
	auto x = link->getPositionX();
	auto y = link->getPositionY();
	bool WB = Pbool(Vec2(x, y - 1));

	if (!WB)
	{
		int x = link->getPositionX();
		int y = link->getPositionY();
		link->setPosition(Vec2(x, y - 1));
	}
}

void inCasthle1::linkMoveLeft(float dt)
{
	auto x = link->getPositionX();
	auto y = link->getPositionY();
	bool WB = Pbool(Vec2(x - 1, y));

	if (!WB)
	{
		int x = link->getPositionX();
		int y = link->getPositionY();
		link->setPosition(Vec2(x - 1, y));
	}
}

void inCasthle1::linkMoveRight(float dt)
{
	auto x = link->getPositionX();
	auto y = link->getPositionY();
	bool WB = Pbool(Vec2(x + 1, y));

	if (!WB)
	{
		int x = link->getPositionX();
		int y = link->getPositionY();
		link->setPosition(Vec2(x + 1, y));
	}
}

cocos2d::Vec2 inCasthle1::tileCoordForPosition(cocos2d::Vec2 position)
{
	int x = position.x / map1->getTileSize().width;
	int y = ((map1->getMapSize().height * map1->getTileSize().height)
		- position.y) / map1->getTileSize().height;

	return Vec2(x, y);
}

bool inCasthle1::Pbool(cocos2d::Vec2 position)
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

void inCasthle1::Wbool(cocos2d::Vec2 position)
{

}

void inCasthle1::camera(float dt)
{
	auto object1 = map1->getObjectGroup("object");

	ValueMap nextMap = object1->getObject("nextmap");

	float Nx1 = nextMap["x"].asInt();
	float Ny1 = nextMap["y"].asInt();
	float Nw1 = nextMap["width"].asInt();
	float Nh1 = nextMap["height"].asInt();

	Rect _nextW(Nx1, Ny1, Nw1, Nh1);

	int y1 = link->getBoundingBox().getMaxY();
	int y2 = _nextW.getMidY();

	if (y1 < y2)
		mapIndex++;

	auto follow1 = Follow::create(link, Rect(0, 208, 472, 224));
	auto follow2 = Follow::create(link, Rect(0, 0, 472, 208));
	//auto Mac1 = MoveBy::create(1.0, Vec2(0, _director->getVisibleSize().height));
	if (link->getPositionY() < map1->getBoundingBox().getMaxY())
	{
		if (mapIndex == 0)
		{
			_layer1->runAction(follow1);
		}
		else
		{
			_layer1->stopAction(follow1);
			//_layer1->runAction(Mac1);
			_layer1->runAction(follow2);
		}
		//Vec2 y = link->getPosition() - (_director->getVisibleSize() / 2);
		//int x = 
	}
	else
	{
		ValueMap spwanEnd = object1->getObject("fallend");
		int x = spwanEnd["x"].asInt();
		int y = spwanEnd["y"].asInt();

		_layer1->setPosition(Vec2(-x + 175, -y + 110));
	}
}

void inCasthle1::npcEvent(float dt)
{
	
}

void inCasthle1::Enemymove()
{
	auto Emove1 = MoveBy::create(2.0,Vec2(70, 0));
	auto Emove2 = MoveBy::create(2.0,Vec2(-70, 0));
	auto Emove3 = MoveBy::create(1.0,Vec2(0, 0));
	auto Emove4 = MoveBy::create(1.0,Vec2(0, 0));
	auto act1 = Sequence::create(Emove1, Emove3, Emove2, Emove4, nullptr);
	auto rep = RepeatForever::create(act1);
	enemy[1].knight1->runAction(rep);
	enemy[2].knight1->runAction(rep->clone());

	schedule(schedule_selector(inCasthle1::_flip), 3.0);
}

void inCasthle1::_flip(float dt)
{
	if (!enemy[1].knight1->isFlipX())
	{
		enemy[1].knight1->setFlipX(true);
		enemy[2].knight1->setFlipX(true);
	}
	else
	{

		enemy[1].knight1->setFlipX(false);
		enemy[2].knight1->setFlipX(false);
	}
	
		
}

void inCasthle1::dameged(float dt)
{
	for (int i = 1; i < 3; i++)
	{
		if (linkAtk && enemy[i].knight1->getBoundingBox().intersectsRect(link->getBoundingBox()))
		{
			enemy[i].hp--;
			auto blink = Blink::create(0.4, 2);
			auto move = MoveBy::create(0.3, Vec2(+10, 0));
			auto sp = Spawn::create(blink, move, nullptr);
			enemy[i].knight1->runAction(sp);
			if (enemy[i].hp <= 0)
			{
				enemy[i].knight1->stopAllActions();
				enemy[i].dead = true;
				auto DEF = Sprite::create("zeldaSprites/deathEf/001.png");

				auto animation = Animation::create();

				animation->setDelayPerUnit(0.04f);

				animation->addSpriteFrameWithFile("zeldaSprites/deathEf/001.png");
				animation->addSpriteFrameWithFile("zeldaSprites/deathEf/002.png");
				animation->addSpriteFrameWithFile("zeldaSprites/deathEf/003.png");
				animation->addSpriteFrameWithFile("zeldaSprites/deathEf/004.png");
				animation->addSpriteFrameWithFile("zeldaSprites/deathEf/005.png");
				animation->addSpriteFrameWithFile("zeldaSprites/deathEf/006.png");
				animation->addSpriteFrameWithFile("zeldaSprites/deathEf/008.png");

				auto animate = Animate::create(animation);

				enemy[i].knight1->runAction(animate);

				enemy[i].knight1->setVisible(false);
			}
		}
		else if (!linkAtk && enemy[i].knight1->getBoundingBox().intersectsRect(link->getBoundingBox()) && !enemy[i].dead)
		{
			Infor inf;
			inf.heart--;
			link->stopAllActions();
			auto blink = Blink::create(0.4, 2);
			auto move = MoveBy::create(0.3, Vec2(+10, 0));
			auto sp = Spawn::create(blink, move, nullptr);
			link->runAction(sp);

		}
	}
}

void inCasthle1::uiNum(float dt)
{
#pragma region Luffi
	luffi[2] = luffis / 100;
	luffi[1] = (luffis - luffi[2] * 100) / 10;
	luffi[0] = luffis % 10;

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

#pragma region Arrow
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

	Infor inf;

	inf.heartM(Vec2(hx1, hy1), Vec2(hx2, hy2), Vec2(hx3, hy3), _ui);
}

void inCasthle1::nextMap(float dt)
{
	auto object1 = map1->getObjectGroup("object");
	ValueMap nextScene = object1->getObject("nextscene");

	int x = nextScene["x"].asInt();
	int y = nextScene["y"].asInt();
	int w = nextScene["width"].asInt();
	int h = -(nextScene["height"].asInt());

	auto nextR = Rect(x, y, w, h);

	if (link->getPositionY() < y-10)
	{
		_director->replaceScene(Overworld2::createScene());
	}
}
