#pragma once
#include "cocos2d.h"

class LinkHome :public cocos2d::Scene
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

	void STtext();

	void TextAction(float dt);

	void camera(float dt);

	void uiNum();

	void npcCreate();

	void nextScene(float dt);
	void changeScene(float dt);

	void EventS1(float dt);
	void eEvent(float dt);
	CREATE_FUNC(LinkHome);
private:
	
	int luffi[3], bomb[2], arrow[2], key;
	int mapIndex;
	int i = 0;
	int i2 = 0;

	bool move;
	bool inBad;

	
	//cocos2d::Size visible;

	cocos2d::TMXTiledMap*map1;
	cocos2d::TMXTiledMap*_ui;
	cocos2d::TMXLayer*_bool1;
	cocos2d::TMXLayer*_bool2;
	cocos2d::LayerColor*Lc;
	cocos2d::Layer*_layer1;
	cocos2d::Layer*_layer2;
	cocos2d::Layer*_layer3;
	cocos2d::Label*pLabel;
	cocos2d::Vec2 linkPosition;
	cocos2d::Sprite*link;
	cocos2d::Sprite*npc[3];
	cocos2d::Sprite*letter;

	cocos2d::EventListenerKeyboard*_listener;
};