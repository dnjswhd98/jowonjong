#include "zelda_P.h"
#include "Infor.h"
#include "Sound.h"

USING_NS_CC;

cocos2d::Scene * zeldaP::createScene()
{
	return zeldaP::create();
}

bool zeldaP::init()
{
	if(!Scene::init())return false;

	Infor inf;
	inf.reset();
	Sound son;
	son.linkEf("sound/bgm/01. title.mp3");

	auto _size = _director->getVisibleSize();

	auto titleS = Sprite::create("hqdefault.jpg");
	titleS->setPosition(Vec2(_size*0.5));
	titleS->setScale(0.55);
	this->addChild(titleS);

	text = Sprite::create("zeldaSprites/press.png");
	text->setPosition(Vec2(125,30));
	this->addChild(text);

	auto Ac1 = FadeOut::create(1.0f);
	auto Ac2 = FadeIn::create(1.0f);
	auto Aca = Sequence::create(Ac1, Ac2, nullptr);
	auto Rep = RepeatForever::create(Aca);

	text->runAction(Rep);



	return true;
}

void zeldaP::onEnter()
{
	Scene::onEnter();
	_listener = EventListenerKeyboard::create();
	
	_listener->onKeyPressed = CC_CALLBACK_2(zeldaP::onKeyPressed, this);
	_listener->onKeyReleased = CC_CALLBACK_2(zeldaP::onKeyReleased, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(_listener, this);
}

void zeldaP::onExit()
{
	_eventDispatcher->removeAllEventListeners();

	Scene::onExit();
}

void zeldaP::onKeyPressed(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event * event)
{
	switch (keycode)
	{
	case cocos2d::EventKeyboard::KeyCode::KEY_ENTER:
		scheduleOnce(schedule_selector(zeldaP::nextScene), 1.0);

		text->stopAllActions();

		auto Ac1 = FadeOut::create(0.5f);
		auto Ac2 = FadeIn::create(0.5f);
		auto Aca = Sequence::create(Ac1, Ac2, nullptr);
		auto Rep = RepeatForever::create(Aca);

		text->runAction(Rep);
		break;
	//default:
	//	break;
	}
}

void zeldaP::onKeyReleased(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event * event)
{
}

void zeldaP::nextScene(float dt)
{
	//Director::getInstance()->replaceScene(LinkHome::createScene());
	Sound son;
	son.linkEfstop();
	//Scene*trance = TransitionFade::create(4.0, LinkHome::createScene());
	Director::getInstance()->replaceScene(LinkHome::createScene());

}
