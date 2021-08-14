#pragma once
#include "cocos2d.h"
#include "Enemy.h"

class inCasthle1 : public cocos2d::Scene
{
public:
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
	void Wbool(cocos2d::Vec2 position);

	void camera(float dt);

	void npcEvent(float dt);
	void Enemymove(float dt);

	void uiNum(float dt);

	void nextMap(float dt);

	void Enemymove();
	void _flip(float dt);
	void dameged(float dt);

	Enemy enemy[4];
	int luffis, item, HP, MP;
	int nextindex = 0;

	int linkDirec;
	bool linkAtk;
	bool linkW;

	CREATE_FUNC(inCasthle1);
private:

	int luffi[3], bomb[2], arrow[2], key;

	int mapIndex;


	bool move;

	//cocos2d::Size visible;

	cocos2d::TMXTiledMap*map1;
	cocos2d::TMXTiledMap*map2;
	cocos2d::TMXTiledMap*_ui;
	cocos2d::TMXLayer*_bool1;
	cocos2d::TMXLayer*_bool2;
	cocos2d::Layer*_layer1;
	cocos2d::Layer*_layer2;
	cocos2d::Vec2 linkPosition;
	cocos2d::Sprite*link;
	//cocos2d::Sprite*npc1;

	cocos2d::EventListenerKeyboard*_listener;
};