#pragma once
#include "cocos2d.h"

class Enemy:public cocos2d::Scene
{
public:

	int knight1Index = 0;
	int hp;
	bool dead = false;

	cocos2d::Sprite*shild;
	cocos2d::Sprite*knight1;
	cocos2d::Sprite*knight2;

	cocos2d::Sprite*npc1;

	void enemyS(int x, int y, cocos2d::Layer * layer);

	void enemyK1(int x, int y, cocos2d::Layer * layer);

	void npcS1(int x, int y, cocos2d::Layer * layer);

};