#include "Prototype.h"

void Prototype::CreatePrototype()
{
	Transform TransInfo;


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
