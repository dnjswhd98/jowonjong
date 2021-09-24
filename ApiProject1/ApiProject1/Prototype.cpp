#include "Prototype.h"
#include "Player.h"

void Prototype::CreatePrototype()
{
	Transform TransInfo;

	PrototypeList["Player"] = new Player(TransInfo);
}

Object* Prototype::FindPrototypeObject(string _Key)
{
	map<string, Object*>::iterator iter = PrototypeList.find(_Key);

	if (iter == PrototypeList.end())
	{
		Sleep(500);
		return nullptr;
	}

	return iter->second;
}

Prototype::Prototype()
{
}

Prototype::~Prototype()
{
}
