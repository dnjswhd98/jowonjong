#pragma once
#include "cocos2d.h"
#include "Enemy.h"
#include "Infor.h"
#include "inCasthle1.h"
#include "inCasthle2.h"

class Overworld :public cocos2d::Scene
{
public:
	Enemy _enemy[4];
	Infor inf;
	static cocos2d::Scene*createScene();
	virtual bool init();

	void onEnter();
	void onExit();

	void onKeyPressed(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event*event);
	void onKeyReleased(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event*event);

	void createLink();

	void linkMoveUp(float dt);
	void linkMoveDown(float dt);
	void linkMoveLeft(float dt);
	void linkMoveRight(float dt);

	cocos2d::Vec2 tileCoordForPosition(cocos2d::Vec2 position);

	bool Pbool(cocos2d::Vec2 position);
	void sound();

	void camera(float dt);

	void uiNum();

	void enemy();

	void bush();

	void nextMap(float dt);
	void enterAnimetion(float dt);
	void changeScene(float dt);

	int item, HP, MP;

	CREATE_FUNC(Overworld);
private:
	
	int luffi[3], bomb[2], arrow[2], key;

	int mapIndex;

	bool move;
	bool next;
	//cocos2d::Size visible;

	cocos2d::TMXTiledMap*map1;
	cocos2d::TMXTiledMap*_ui;
	cocos2d::TMXLayer*_bool1;
	cocos2d::TMXLayer*_bool2;
	cocos2d::Layer*_layer1;
	cocos2d::Layer*_layer2;
	cocos2d::Vec2 linkPosition;
	cocos2d::Sprite*link;
	cocos2d::Sprite*stickbush;
	//cocos2d::Sprite*npc1;
	cocos2d::RepeatForever*Lrep;

	cocos2d::EventListenerKeyboard*_listener;
};