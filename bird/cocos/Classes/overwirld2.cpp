#include "Overwirld2.h"
#include "AudioEngine.h"

USING_NS_CC;

cocos2d::Scene * Overworld2::createScene()
{
	return Overworld2::create();
}

bool Overworld2::init()
{
	Infor inf;
	inf.reset();
	if (!Scene::init())return false;

	next = false;

	mapIndex = 0;

	auto visible = _director->getVisibleSize();

	_layer1 = Layer::create();
	_layer2 = Layer::create();
	auto _layer3 = Layer::create();

#pragma region rainEF
	auto rainEF = Sprite::create("zeldaSprites/ef/rain/rain1.png");
	rainEF->setPosition(Vec2(128, 112));
	rainEF->setOpacity(160);
	//rainEF->setScale(2.0);

	_layer3->addChild(rainEF);

	auto animation = Animation::create();

	animation->setDelayPerUnit(0.08f);

	animation->addSpriteFrameWithFile("zeldaSprites/ef/rain/rain1.png");
	animation->addSpriteFrameWithFile("zeldaSprites/ef/rain/rain2.png");
	animation->addSpriteFrameWithFile("zeldaSprites/ef/rain/rain3.png");
	animation->addSpriteFrameWithFile("zeldaSprites/ef/rain/rain4.png");

	auto animate = Animate::create(animation);

	auto rep = RepeatForever::create(animate);
	rainEF->runAction(rep);
	rainEF->setColor(Color3B(150, 150, 200));
#pragma endregion

	map1 = TMXTiledMap::create("zeldaSprites/map/overworld.tmx");
	auto object1 = map1->getObjectGroup("Object1");
	ValueMap spwanPoint = object1->getObject("LS1");
	ValueMap spwanPoint2 = object1->getObject("LS2");
	_bool1 = map1->getLayer("metaset1");
	_bool2 = map1->getLayer("metaset2");
	_bool1->setVisible(false);
	_bool2->setVisible(false);
	_layer1->addChild(map1, 0);

	int x = spwanPoint2["x"].asInt();
	int y = spwanPoint2["y"].asInt();
	linkPosition = Vec2(x, y);

	this->createLink();

	_ui = TMXTiledMap::create("zeldaSprites/map/ui.tmx");
	_ui->setPosition(Vec2(0, 140));
	_layer2->addChild(_ui, 50);

	schedule(schedule_selector(Overworld2::camera));
	schedule(schedule_selector(Overworld2::nextMap));
	schedule(schedule_selector(Overworld2::changeScene), 1.0f);

	this->addChild(_layer1, 0);
	this->addChild(_layer3, 1);
	this->addChild(_layer2, 2);



	this->uiNum();
	this->enemy();

	return true;
}

void Overworld2::onEnter()
{
	Scene::onEnter();

	_listener = EventListenerKeyboard::create();

	_listener->onKeyPressed = CC_CALLBACK_2(Overworld2::onKeyPressed, this);
	_listener->onKeyReleased = CC_CALLBACK_2(Overworld2::onKeyReleased, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(_listener, this);
}

void Overworld2::onExit()
{
	_eventDispatcher->removeAllEventListeners();
	Scene::onExit();
}

void Overworld2::onKeyPressed(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event * event)
{
	if (!next)
	{
		switch (keycode)
		{
		case cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW:
		{
			link->stopAllActions();

			schedule(schedule_selector(Overworld2::linkMoveUp));
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

			schedule(schedule_selector(Overworld2::linkMoveDown));
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

			schedule(schedule_selector(Overworld2::linkMoveLeft));
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

			schedule(schedule_selector(Overworld2::linkMoveRight));
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
}

void Overworld2::onKeyReleased(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event * event)
{
	if (!next)
	{
		switch (keycode)
		{
		case cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW:
		{
			unschedule(schedule_selector(Overworld2::linkMoveUp));
		}
		break;
		case cocos2d::EventKeyboard::KeyCode::KEY_DOWN_ARROW:
		{
			unschedule(schedule_selector(Overworld2::linkMoveDown));
		}
		break;
		case cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		{
			unschedule(schedule_selector(Overworld2::linkMoveLeft));
		}
		break;
		case cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		{
			unschedule(schedule_selector(Overworld2::linkMoveRight));
		}
		break;
		default:
			break;
		}
		//link->stopAllActions();
	}
}

void Overworld2::createLink()
{
	link = Sprite::create("zeldaSprites/link/002.png");
	link->setPosition(linkPosition);
	_layer1->addChild(link);
}

void Overworld2::linkMoveUp(float dt)
{
	auto x = link->getPositionX();
	auto y = link->getPositionY();
	bool WB = Pbool(Vec2(x, y + 1));

	if (!WB || !!next)
	{
		int x = link->getPositionX();
		int y = link->getPositionY();
		link->setPosition(Vec2(x, y + 1));
	}
}

void Overworld2::linkMoveDown(float dt)
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

void Overworld2::linkMoveLeft(float dt)
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

void Overworld2::linkMoveRight(float dt)
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

cocos2d::Vec2 Overworld2::tileCoordForPosition(cocos2d::Vec2 position)
{
	int x = position.x / map1->getTileSize().width;
	int y = ((map1->getMapSize().height * map1->getTileSize().height)
		- position.y) / map1->getTileSize().height;

	return Vec2(x, y);
}

bool Overworld2::Pbool(cocos2d::Vec2 position)
{
	//���� ��ġ�� ���� Ÿ���� Ÿ�ϸʿ��� ��� �ִ°�?
	Vec2 tileCoord = this->tileCoordForPosition(position);

	//������ ���� Ÿ�� �������� GID�� �����Ѵ�
	int tileGid = _bool1->getTileGIDAt(tileCoord);

	if (tileGid)
	{
		// Ÿ�Ͽ��� GID�� �ش��ϴ� �Ӽ��� �޾ƿ´�
		Value properties = map1->getPropertiesForGID(tileGid);

		if (!properties.isNull())
		{
			std::string wall = properties.asValueMap()["wall"].asString();
			//std::string inout = properties.asValueMap()["inout"].asString();
			if (wall == "YES")
			{
				// ��ġ�� Ÿ���� ������ ���� ��� ĳ���� �̵��� �����Ѵ�
				return true;
			}
		}
	}
}

void Overworld2::sound()
{
}

void Overworld2::camera(float dt)
{
	auto object1 = map1->getObjectGroup("Object1");

	ValueMap nextMap = object1->getObject("next");

	auto follow2 = Follow::create(link, Rect(96, 512, 1024, 1024));
	_layer1->runAction(follow2);

}

//void inCasthle1::Enemymove()
//{
//	auto Emove1 = MoveBy::create(2.0, Vec2(70, 0));
//	auto Emove2 = MoveBy::create(2.0, Vec2(-70, 0));
//	auto Emove3 = MoveBy::create(1.0, Vec2(0, 0));
//	auto Emove4 = MoveBy::create(1.0, Vec2(0, 0));
//	auto act1 = Sequence::create(Emove1, Emove3, Emove2, Emove4, nullptr);
//	auto rep = RepeatForever::create(act1);
//	enemy[1].knight1->runAction(rep);
//	enemy[2].knight1->runAction(rep->clone());
//
//	schedule(schedule_selector(inCasthle1::_flip), 3.0);
//}
//
//void inCasthle1::_flip(float dt)
//{
//	if (!enemy[1].knight1->isFlipX())
//	{
//		enemy[1].knight1->setFlipX(true);
//		enemy[2].knight1->setFlipX(true);
//	}
//	else
//	{
//
//		enemy[1].knight1->setFlipX(false);
//		enemy[2].knight1->setFlipX(false);
//	}
//
//
//}
//
//void inCasthle1::dameged(float dt)
//{
//	for (int i = 1; i < 3; i++)
//	{
//		if (linkAtk && enemy[i].knight1->getBoundingBox().intersectsRect(link->getBoundingBox()))
//		{
//			enemy[i].hp--;
//			auto blink = Blink::create(0.4, 2);
//			auto move = MoveBy::create(0.3, Vec2(+10, 0));
//			auto sp = Spawn::create(blink, move, nullptr);
//			enemy[i].knight1->runAction(sp);
//			if (enemy[i].hp <= 0)
//			{
//				enemy[i].knight1->stopAllActions();
//				enemy[i].dead = true;
//				auto DEF = Sprite::create("zeldaSprites/deathEf/001.png");
//
//				auto animation = Animation::create();
//
//				animation->setDelayPerUnit(0.04f);
//
//				animation->addSpriteFrameWithFile("zeldaSprites/deathEf/001.png");
//				animation->addSpriteFrameWithFile("zeldaSprites/deathEf/002.png");
//				animation->addSpriteFrameWithFile("zeldaSprites/deathEf/003.png");
//				animation->addSpriteFrameWithFile("zeldaSprites/deathEf/004.png");
//				animation->addSpriteFrameWithFile("zeldaSprites/deathEf/005.png");
//				animation->addSpriteFrameWithFile("zeldaSprites/deathEf/006.png");
//				animation->addSpriteFrameWithFile("zeldaSprites/deathEf/008.png");
//
//				auto animate = Animate::create(animation);
//
//				enemy[i].knight1->runAction(animate);
//
//				enemy[i].knight1->setVisible(false);
//			}
//		}
//		else if (!linkAtk && enemy[i].knight1->getBoundingBox().intersectsRect(link->getBoundingBox()) && !enemy[i].dead)
//		{
//			Infor inf;
//			inf.heart--;
//			link->stopAllActions();
//			auto blink = Blink::create(0.4, 2);
//			auto move = MoveBy::create(0.3, Vec2(+10, 0));
//			auto sp = Spawn::create(blink, move, nullptr);
//			link->runAction(sp);
//
//		}
//	}
//}



void Overworld2::uiNum()
{
	Infor inf;
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

void Overworld2::enemy()
{
	auto object1 = map1->getObjectGroup("Object1");

	ValueMap ESknight = object1->getObject("shildKnight");
	ValueMap knight1 = object1->getObject("Knight1");
	ValueMap knight2 = object1->getObject("Knight2");
	ValueMap knight3 = object1->getObject("Knight3");
	int sx = ESknight["x"].asInt();
	int kx1 = knight1["x"].asInt();
	int kx2 = knight2["x"].asInt();
	int kx3 = knight3["x"].asInt();
	int sy = ESknight["y"].asInt();
	int ky1 = knight1["y"].asInt();
	int ky2 = knight2["y"].asInt();
	int ky3 = knight3["y"].asInt();

	_enemy[0].enemyS(sx, sy, _layer1);
	_enemy[1].enemyK1(kx1, ky1, _layer1);
	_enemy[2].enemyK1(kx2, ky2, _layer1);
	_enemy[3].enemyK1(kx3, ky3, _layer1);



}

void Overworld2::bush()
{
}

void Overworld2::nextMap(float dt)
{
	auto object1 = map1->getObjectGroup("Object1");

	ValueMap holePos = object1->getObject("hole");
	ValueMap enterPos = object1->getObject("enter");
	int hx = holePos["x"].asInt();
	int hy = holePos["y"].asInt();
	int hw = holePos["width"].asInt();
	int hh = holePos["height"].asInt();
	int ex = enterPos["x"].asInt();
	int ey = enterPos["y"].asInt();
	int ew = enterPos["width"].asInt();
	int eh = enterPos["height"].asInt();

	auto holeR = Rect(hx, hy, hw, hh);
	auto enterR = Rect(ex, ey, ew, eh);

	if (holeR.intersectsRect(link->getBoundingBox()))
	{
		//unschedule(schedule_selector(Overworld2::linkMoveUp));
		link->setPosition(Vec2(hx + 8, hy + 8));

		if (holeR.intersectsRect(link->getBoundingBox()))
		{

			auto animation = Animation::create();

			animation->setDelayPerUnit(0.2f);

			animation->addSpriteFrameWithFile("zeldaSprites/link/linkfall/001.png");
			animation->addSpriteFrameWithFile("zeldaSprites/link/linkfall/002.png");
			animation->addSpriteFrameWithFile("zeldaSprites/link/linkfall/003.png");
			animation->addSpriteFrameWithFile("zeldaSprites/link/linkfall/004.png");
			animation->addSpriteFrameWithFile("zeldaSprites/link/linkfall/005.png");
			animation->addSpriteFrameWithFile("zeldaSprites/link/linkfall/006.png");

			auto animate = Animate::create(animation);
			//auto rep = RepeatForever::create(animate);

			link->runAction(animate);
		}
		next = true;
	}

}

void Overworld2::enterAnimetion(float dt)
{

	auto object1 = map1->getObjectGroup("Object1");

	ValueMap holePos = object1->getObject("hole");
	ValueMap enterPos = object1->getObject("enter");
	int hx = holePos["x"].asInt();
	int hy = holePos["y"].asInt();
	int hw = holePos["width"].asInt();
	int hh = holePos["height"].asInt();
	int ex = enterPos["x"].asInt();
	int ey = enterPos["y"].asInt();
	int ew = enterPos["width"].asInt();
	int eh = enterPos["height"].asInt();

	auto holeR = Rect(hx, hy, hw, hh);


}

void Overworld2::changeScene(float dt)
{
	auto object1 = map1->getObjectGroup("Object1");

	ValueMap spwanPoint2 = object1->getObject("LS2");

	ValueMap holePos = object1->getObject("hole");
	ValueMap enterPos = object1->getObject("enter");
	int hx = holePos["x"].asInt();
	int hy = holePos["y"].asInt();
	int hw = holePos["width"].asInt();
	int hh = holePos["height"].asInt();
	int ex = enterPos["x"].asInt();
	int ey = enterPos["y"].asInt();
	int ew = enterPos["width"].asInt();
	int eh = enterPos["height"].asInt();

	auto holeR = Rect(hx, hy, hw, hh);
	auto enterR = Rect(ex, ey, ew, eh);

	if (enterR.intersectsRect(link->getBoundingBox()))
	{
		Director::getInstance()->replaceScene(inCasthle2::createScene());
	}
}
