#pragma once
#include "cocos2d.h"

class Link
{
public:
	cocos2d::Sprite*link;
	void linkUAni(float dt);
	void linkDAni(float dt);
	void linkLAni(float dt);
	void linkRAni(float dt);
};