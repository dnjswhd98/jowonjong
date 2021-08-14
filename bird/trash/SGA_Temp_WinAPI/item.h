#pragma once
#include "setDefine.h"
#include "image.h"

//������ �κ��丮�� ����� ������ ������Ʈ ���� Ŭ����
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