#pragma once
#include "Object.h"
class CollisionManager
{
private:
	static CollisionManager* Instance;
public:
	static CollisionManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new CollisionManager;

		return Instance;
	}

	static bool EllipseCollision(Object* _Temp, Object* _Dest)
	{
		float Sum = (_Temp->GetScale().x / 2) + (_Dest->GetScale().x / 2);

		float fX = _Temp->GetPosition().x - _Dest->GetPosition().x;
		float fY = _Temp->GetPosition().y - _Dest->GetPosition().y;

		float Distance = sqrt((fX * fX) + (fY * fY));

		if (Sum > Distance)
			return true;

		return false;
	}

	static bool EllipseCollision(const Transform& _Temp, const Transform& _Dest)
	{
		float Sum = (_Temp.Scale.x / 2) + (_Dest.Scale.x / 2);

		float fX = _Temp.Position.x - _Dest.Position.x;
		float fY = _Temp.Position.y - _Dest.Position.y;

		float Distance = sqrt((fX * fX) + (fY * fY));

		if (Sum > Distance)
			return true;

		return false;
	}
};

