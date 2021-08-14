#include "LinkHome.h"
#include "AudioEngine.h"
#include "Infor.h"
#include "Sound.h"
#include "overworld.h"


USING_NS_CC;

cocos2d::Scene * LinkHome::createScene()
{
	return LinkHome::create();
}

bool LinkHome::init()
{
	if(!Scene::init())return false;
	Sound sou;

	sou.playRain();

	Infor inf;
	inf.luffis;
	inf.overWI = 0;

	_layer1 = Layer::create();
	_layer2 = Layer::create();
	_layer3 = Layer::create();

	inBad = true;

	auto visible = _director->getVisibleSize();

	map1 = TMXTiledMap::create("zeldaSprites/map/Home.tmx");
	//map1->setPosition(visible*0.5);
	auto object1 = map1->getObjectGroup("Object1");
	ValueMap spwanPoint = object1->getObject("linkS");
	ValueMap door = object1->getObject("door");
	_bool1 = map1->getLayer("metaset");
	_bool1->setVisible(false);

	_ui = TMXTiledMap::create("zeldaSprites/map/ui.tmx");
	_ui->setPosition(Vec2(0, 140));
	_layer2->addChild(_ui, 50);

	int drx = door["x"].asInt();
	int dry = door["y"].asInt();

	auto doorS = Sprite::create("zeldaSprites/map/map/door2.png");
	doorS->setPosition(Vec2(drx, dry));
	_layer1->addChild(doorS, 50);

	this->addChild(map1,0);

	int x = spwanPoint["x"].asInt();
	int y = spwanPoint["y"].asInt() + 8;
	linkPosition = Vec2(x, y);
	
	this->createLink();

	Lc = LayerColor::create(Color4B(0, 0, 60, 160));
	_layer3->addChild(Lc);
	
	this->addChild(_layer1,0);
	this->addChild(_layer3,1);
	this->addChild(_layer2,2);

	auto Act1 = FadeOut::create(5.0f);
	Lc->runAction(Act1);


	ValueMap NpcSpwanPoint = object1->getObject("npc1");

	int sx = NpcSpwanPoint["x"].asInt();
	int sy = NpcSpwanPoint["y"].asInt();

	for (int i = 0; i < 3; i++)
	{
		npc[i] = Sprite::create("zeldaSprites/npc1/npc1.png");
		npc[i]->setPosition(Vec2(sx, sy));
		_layer1->addChild(npc[i]);
	}
	cocos2d::RepeatForever*rep;
	cocos2d::RepeatForever*rep2;
	auto animation = Animation::create();

	animation->setDelayPerUnit(0.1f);

	animation->addSpriteFrameWithFile("zeldaSprites/npc1/Lmove/001.png");
	animation->addSpriteFrameWithFile("zeldaSprites/npc1/Lmove/002.png");

	auto animate = Animate::create(animation);

	rep = RepeatForever::create(animate);

	npc[1]->runAction(rep);

	auto animation2 = Animation::create();

	animation2->setDelayPerUnit(0.1f);

	animation2->addSpriteFrameWithFile("zeldaSprites/npc1/Dmove/001.png");
	animation2->addSpriteFrameWithFile("zeldaSprites/npc1/Dmove/002.png");

	auto animate2 = Animate::create(animation2);

	rep2 = RepeatForever::create(animate2);

	npc[2]->runAction(rep2);

	npc[1]->setOpacity(0);
	npc[2]->setOpacity(0);

	//if (Lc->getOpacity() <= 10)
		//this->EventS1(0);
	scheduleOnce(schedule_selector(LinkHome::EventS1), 6.0);
	schedule(schedule_selector(LinkHome::camera));
	schedule(schedule_selector(LinkHome::nextScene));
		
	//this->STtext();


	return true;
}

void LinkHome::onEnter()
{
	Scene::onEnter();


	_listener = EventListenerKeyboard::create();

	_listener->onKeyPressed = CC_CALLBACK_2(LinkHome::onKeyPressed, this);
	_listener->onKeyReleased = CC_CALLBACK_2(LinkHome::onKeyReleased, this);

	//schedule(schedule_selector(LinkHome::EventS1),5.0);
	

	_eventDispatcher->addEventListenerWithSceneGraphPriority(_listener, this);
}

void LinkHome::onExit()
{
	_eventDispatcher->removeAllEventListeners();
	Scene::onExit();
}
void LinkHome::onKeyPressed(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event * event)
{
	switch (keycode)
	{
	case cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW:
	{
		link->stopAllActions();

		schedule(schedule_selector(LinkHome::linkMoveUp));
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
	break;
	case cocos2d::EventKeyboard::KeyCode::KEY_DOWN_ARROW:
	{
		link->stopAllActions();

		schedule(schedule_selector(LinkHome::linkMoveDown));
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
	break;
	case cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW:
	{
		link->stopAllActions();

		schedule(schedule_selector(LinkHome::linkMoveLeft));
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
	break;
	case cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
	{
		link->stopAllActions();
		if (inBad)
		{
			auto act1 = JumpBy::create(0.5f, Vec2(18, 0), 5, 1);
			auto animation = Animation::create();

			animation->setDelayPerUnit(0.05f);

			animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/linkUnwapone/Rmove/012.png");
			
			auto animate = Animate::create(animation);
			link->runAction(animate);
			link->runAction(act1);

			inBad = false;
		}
		else
		{
			schedule(schedule_selector(LinkHome::linkMoveRight));
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

	default:
		break;
	}
}

void LinkHome::onKeyReleased(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event * event)
{
	switch (keycode)
	{
	case cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW:
	{
		unschedule(schedule_selector(LinkHome::linkMoveUp));
	}
	break;
	case cocos2d::EventKeyboard::KeyCode::KEY_DOWN_ARROW:
	{
		unschedule(schedule_selector(LinkHome::linkMoveDown));
	}
	break;
	case cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW:
	{
		unschedule(schedule_selector(LinkHome::linkMoveLeft));
	}
	break;
	case cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
	{
		unschedule(schedule_selector(LinkHome::linkMoveRight));
	}
	break;
	case cocos2d::EventKeyboard::KeyCode::KEY_Z:
	{
		schedule(schedule_selector(LinkHome::TextAction), 0.2);
	}
	break;
	default:
		break;
	}
	link->stopAllActions();

}

void LinkHome::createLink()
{
	link = Sprite::create("zeldaSprites/link/bad1.png");
	link->setPosition(linkPosition);
	_layer1->addChild(link,3);
}

void LinkHome::linkMoveUp(float dt)
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

void LinkHome::linkMoveDown(float dt)
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

void LinkHome::linkMoveLeft(float dt)
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

void LinkHome::linkMoveRight(float dt)
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

cocos2d::Vec2 LinkHome::tileCoordForPosition(cocos2d::Vec2 position)
{
	int x = position.x / map1->getTileSize().width;
	int y = ((map1->getMapSize().height * map1->getTileSize().height)
		- position.y) / map1->getTileSize().height;

	return Vec2(x, y);
}

bool LinkHome::Pbool(cocos2d::Vec2 position)
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

void LinkHome::STtext()
{
	TTFConfig ttfConfig("fonts/arial.ttf", 13);

	ttfConfig.outlineSize = 1;

	pLabel = Label::createWithTTF(ttfConfig, "Help me...\n\nPlease help me...\nI am  prisoner in the dungeon\nof the casthle.\nMy name is Zelda.\nThe wizard, Agahnim, has done...\nsomething to the other missing\ngirls. Now only I remain.\nAgahnim has seized control of\nthe castle and is now trying to\nopen the seven wise men's\nseal. ... ...\nI am in the dungeon of the\ncastle.\nPlease help me...");
	pLabel->setPosition(Vec2(100, 0));
	pLabel->enableOutline(Color4B(0,0,100,255));
	pLabel->setOpacity(0);
	_layer2->addChild(pLabel);

	ttfConfig.outlineSize = 0;

	this->schedule(schedule_selector(LinkHome::TextAction),0.1);

}

void LinkHome::TextAction(float dt)
{
	//auto str = "\n"
	//
	//if (i < pLabel->getStringLength())
	//{
	//	//cocos2d::Sprite* getLetter(int letterIndex)
	//	/*
	//		현재 Label 객체에 삽입된 문자열에서 i(letterIndex)번째에
	//		위치한 문자를 cocos2d::Sprite* 타입으로 반환한다.
	//	*/
	//	letter = pLabel->getLetter(i);
	//
	//	//if (str == letter)
	//	//{
	//	//	i2++;
	//	//}
	//
	//	//getLetter() 함수는 기본적으로 공백(스페이스)를 인식할 수 없어 예외처리 필요
	//	if (!letter)
	//	{
	//		// 빈 칸에 접근했을 때 강제로 제어용 변수 값을 +1, 다음 순서로 건너뛴다
	//		i++;
	//		return;
	//	}
	//
	//	//letter에 값이 무사히 전달되면 색상과 투명도를 재조정
	//	letter->setOpacity(255);
	//
	//	//제어용 변수 i의 값을 +1 하여 다음 순서의 문자를 받아올 수 있도록
	//	i++;
	//}
	//else
	//{
	//	//0으로 초기화
	//	i = 0;
	//
	//	// label 객체에 담아둔 문자열이 완벽하게 출력된 경우
	//	// 더 이상 사용할 일이 없으므로 해제한다.
	//	this->unschedule(schedule_selector(LinkHome::TextAction));
	//}
}

void LinkHome::camera(float dt)
{
	auto follow1 = Follow::create(link, Rect(0, 0, 256, 192));
	
	_layer1->runAction(follow1);	
}

void LinkHome::nextScene(float dt)
{
	auto object1 = map1->getObjectGroup("Object1");

	ValueMap nextS = object1->getObject("enter");

	int ex = nextS["x"].asInt();
	int ey = nextS["y"].asInt();

	if (link->getPositionY() <= ey + 20)
	{
		//auto ef = Sprite::create("zeldaSprites/ef/enterEF8.png");
		//ef->setPosition(Vec2(128, 112));
		//_layer3->addChild(ef);
		//
		//auto animation = Animation::create();
		//
		//animation->setDelayPerUnit(0.03f);
		//
		//animation->addSpriteFrameWithFile("zeldaSprites/ef/enterEF8.png");
		//animation->addSpriteFrameWithFile("zeldaSprites/ef/enterEF7.png");
		//animation->addSpriteFrameWithFile("zeldaSprites/ef/enterEF6.png");
		//animation->addSpriteFrameWithFile("zeldaSprites/ef/enterEF5.png");
		//animation->addSpriteFrameWithFile("zeldaSprites/ef/enterEF4.png");
		//animation->addSpriteFrameWithFile("zeldaSprites/ef/enterEF3.png");
		//animation->addSpriteFrameWithFile("zeldaSprites/ef/enterEF2.png");
		//animation->addSpriteFrameWithFile("zeldaSprites/ef/enterEF1.png");
		//
		//auto animate = Animate::create(animation);
		//ef->runAction(animate);
		Infor inf;
		inf.changeScene(Overworld::createScene());
	}
}

void LinkHome::changeScene(float dt)
{
	//auto ly = LayerColor::create(Color4B::BLACK);
	//_layer3->addChild(ly);
	//unschedule(schedule_selector(LinkHome::nextScene));
}

void LinkHome::EventS1(float dt)
{
	auto object1 = map1->getObjectGroup("Object1");
	
	auto move1 = MoveBy::create(1.0, Vec2(-72, 0));
	auto move2 = MoveBy::create(2.0, Vec2(0, -100));
	auto fo1 = FadeOut::create(0.001f);
	auto fo2 = FadeOut::create(0.001f);
	auto fo3 = FadeOut::create(0.001f);
	auto fi1 = FadeIn::create(0.001f);
	auto fi2 = FadeIn::create(0.001f);

	auto rem = RemoveSelf::create();
	auto npcMove1 = Sequence::create(fi1, move1, fo2, move2, nullptr);
	auto npcMove2 = Sequence::create(move1->clone(),fi2,move2,fo3, nullptr);

	npc[0]->runAction(rem);
	npc[1]->runAction(npcMove1);
	npc[2]->runAction(npcMove2);
	unschedule(schedule_selector(LinkHome::EventS1));
}

void LinkHome::eEvent(float dt)
{
	

}

void LinkHome::uiNum()
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
