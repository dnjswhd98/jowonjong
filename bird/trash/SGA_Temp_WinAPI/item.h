#pragma once
#include "setDefine.h"
#include "image.h"

//상점과 인벤토리에 사용할 아이템 오브젝트 생성 클래스
class item
{
private:
	image* _img;
	string _itemName;
	int _cost;

public:
	void setImage(image* img) { _img = img; }
	void setItemName(string name) { _itemName = name; }
	void setCost(int cost) { _cost = cost; }

	image* getImage() { return _img; }
	string getItemImage() { return _itemName; }
	int getCost() { return _cost; }
};