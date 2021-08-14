#include "Infor.h"
#include "zelda_P.h"
#include "LinkHome.h"
#include "overworld.h"

USING_NS_CC;

cocos2d::Scene * Infor::createScene()
{
	return Infor::create();
}

bool Infor::init()
{
	if (!Scene::init())return true;


	return false;
}

void Infor::reset()
{
	luffis = 0;
	heart = 6;
}

void Infor::heartM(cocos2d::Vec2 pos1, cocos2d::Vec2 pos2, cocos2d::Vec2 pos3, cocos2d::TMXTiledMap*map)
{
	switch (heart)
	{
	case 6:
	{
		auto HS1 = Sprite::create("zeldaSprites/heart/heart1.png");
		auto HS2 = Sprite::create("zeldaSprites/heart/heart1.png");
		auto HS3 = Sprite::create("zeldaSprites/heart/heart1.png");

		HS1->setPosition(pos1);
		HS2->setPosition(pos2);
		HS3->setPosition(pos3);

		map->addChild(HS1);
		map->addChild(HS2);
		map->addChild(HS3);
	}
	break;
	case 5:
	{
		auto HS1 = Sprite::create("zeldaSprites/heart/heart1.png");
		auto HS2 = Sprite::create("zeldaSprites/heart/heart1.png");
		auto HS3 = Sprite::create("zeldaSprites/heart/heart3.png");

		HS1->setPosition(pos1);
		HS2->setPosition(pos2);
		HS3->setPosition(pos3);

		map->addChild(HS1);
		map->addChild(HS2);
		map->addChild(HS3);
	}
	break;
	case 4:
	{
		auto HS1 = Sprite::create("zeldaSprites/heart/heart1.png");
		auto HS2 = Sprite::create("zeldaSprites/heart/heart1.png");
		auto HS3 = Sprite::create("zeldaSprites/heart/heart5.png");

		HS1->setPosition(pos1);
		HS2->setPosition(pos2);
		HS3->setPosition(pos3);

		map->addChild(HS1);
		map->addChild(HS2);
		map->addChild(HS3);
	}
	break;
	case 3:
	{
		auto HS1 = Sprite::create("zeldaSprites/heart/heart1.png");
		auto HS2 = Sprite::create("zeldaSprites/heart/heart3.png");
		auto HS3 = Sprite::create("zeldaSprites/heart/heart5.png");

		HS1->setPosition(pos1);
		HS2->setPosition(pos2);
		HS3->setPosition(pos3);

		map->addChild(HS1);
		map->addChild(HS2);
		map->addChild(HS3);
	}
	break;
	case 2:
	{
		auto HS1 = Sprite::create("zeldaSprites/heart/heart1");
		auto HS2 = Sprite::create("zeldaSprites/heart/heart5");
		auto HS3 = Sprite::create("zeldaSprites/heart/heart5");

		HS1->setPosition(pos1);
		HS2->setPosition(pos2);
		HS3->setPosition(pos3);

		map->addChild(HS1);
		map->addChild(HS2);
		map->addChild(HS3);
	}
	break;
	case 1:
	{
		auto HS1 = Sprite::create("zeldaSprites/heart/heart3.png");
		auto HS2 = Sprite::create("zeldaSprites/heart/heart5.png");
		auto HS3 = Sprite::create("zeldaSprites/heart/heart5.png");

		HS1->setPosition(pos1);
		HS2->setPosition(pos2);
		HS3->setPosition(pos3);

		map->addChild(HS1);
		map->addChild(HS2);
		map->addChild(HS3);
	}
	break;
	default:
		break;
	}
}

void Infor::changeScene(cocos2d::Scene * scene)
{
	Scene*trance = TransitionFade::create(2.0, scene);
	Director::getInstance()->replaceScene(scene);
}


