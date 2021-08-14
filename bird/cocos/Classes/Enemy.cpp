#include "Enemy.h"

USING_NS_CC;

void Enemy::enemyS(int x,int y,cocos2d::Layer*layer)
{
	shild = Sprite::create("zeldaSprites/knight2/001.png");
	
	shild->setPosition(Vec2(x, y));

	layer->addChild(shild);
}

void Enemy::enemyK1(int x, int y, cocos2d::Layer*layer)
{
	knight1 = Sprite::create("zeldaSprites/knight1/001.png");
	knight1->setPosition(Vec2(x, y));
	layer->addChild(knight1);
}

void Enemy::npcS1(int x, int y, cocos2d::Layer * layer)
{
	npc1 = Sprite::create("zeldaSprites/npc1/npc3.png");
	npc1->setPosition(Vec2(x, y));
	layer->addChild(npc1);
}

