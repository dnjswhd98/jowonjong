#pragma once
#include "cocos2d.h"
#include "LinkHome.h"
#include "overworld.h"

class zeldaP :public cocos2d::Scene
{
public:
	static cocos2d::Scene*createScene();
	virtual bool init();

	void onEnter();
	void onExit();

	void onKeyPressed(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event*event);
	void onKeyReleased(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event*event);

	void nextScene(float dt);

	CREATE_FUNC(zeldaP);
private:
	cocos2d::EventListenerKeyboard*_listener;
	cocos2d::Label*_label;
	cocos2d::Sprite*text;
};