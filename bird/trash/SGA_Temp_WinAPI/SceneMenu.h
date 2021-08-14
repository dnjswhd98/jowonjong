#pragma once
#include "gameNode.h"
typedef enum
{
	SOUL_SET,
	EQUIP,
	ITEM_USE,
	ABILITY,
}Menu;
class SceneMenu:public gameNode
{
private:
	image* mainStatMenu;
public:
	HRESULT init();
	void release();
	void update();
	void render();

	SceneMenu(){}
	~SceneMenu(){}
};

