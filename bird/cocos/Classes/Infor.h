#pragma once
#include "cocos2d.h"

class Infor : public cocos2d::Scene
{
public: 
	static cocos2d::Scene*createScene();
	virtual bool init();
	
	int luffis;
	int heart = 6;
	int overWI;

	bool Weapon = false;

	void reset();
	void heartM(cocos2d::Vec2 pos1, cocos2d::Vec2 pos2, cocos2d::Vec2 pos3, cocos2d::TMXTiledMap*map);
	void changeScene(cocos2d::Scene*scene);

	CREATE_FUNC(Infor);
private:
};