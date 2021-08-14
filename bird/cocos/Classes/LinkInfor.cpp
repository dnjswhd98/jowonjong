#include "LinkInfor.h"

USING_NS_CC;

void Link::linkUAni(float dt)
{
	auto animation = Animation::create();

	animation->setDelayPerUnit(0.05f);

	animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/linkUnwapone/Umove/017.png");
	animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/linkUnwapone/Umove/018.png");
	animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/linkUnwapone/Umove/019.png");
	animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/linkUnwapone/Umove/020.png");
	animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/linkUnwapone/Umove/021.png");
	animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/linkUnwapone/Umove/022.png");
	animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/linkUnwapone/Umove/023.png");
	animation->addSpriteFrameWithFile("zeldaSprites/link/linkMove/linkUnwapone/Umove/024.png");

	auto animate = Animate::create(animation);

	auto rep = RepeatForever::create(animate);
	link->runAction(rep);
}

void Link::linkDAni(float dt)
{
}

void Link::linkLAni(float dt)
{
}

void Link::linkRAni(float dt)
{
}
