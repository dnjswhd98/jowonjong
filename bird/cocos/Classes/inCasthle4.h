#pragma once
#include "cocos2d.h"
#include "Infor.h"

class inCasthle4 : public cocos2d::Scene
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

	void uiNum();

	void linkAttcks(Ref*sender);

	Infor inf;

	int linkDirec;
	bool linkAtk;

	CREATE_FUNC(inCasthle4);
private:

	int luffi[3], bomb[2], arrow[2], key;

	int mapIndex;

	bool move;

	//cocos2d::Size visible;

	cocos2d::TMXTiledMap*map1;
	cocos2d::TMXTiledMap*_ui;
	cocos2d::TMXLayer*_bool1;
	cocos2d::Layer*_layer1;
	cocos2d::Layer*_layer2;
	cocos2d::Vec2 linkPosition;
	cocos2d::Sprite*link;

	cocos2d::EventListenerKeyboard*_listener;
};