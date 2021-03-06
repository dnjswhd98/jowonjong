#pragma once
#include "Headers.h"
class MathManager
{
private:
	static MathManager* Instance;
public:
	static MathManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new MathManager;

		return Instance;
	}

	static float GetDistance(Vector3 _Current, Vector3 _Target)
	{
		float fX = _Target.x - _Current.x;
		float fY = _Target.y - _Current.y;

		return sqrt((fX * fX) + (fY * fY));
	}

	static Vector3 GetDirection(Vector3 _Current, Vector3 _Target)
	{
		float fX = _Target.x - _Current.x;
		float fY = _Target.y - _Current.y;

		float Distance = sqrt((fX * fX) + (fY * fY));

		return Vector3(fX / Distance, fY / Distance);
	}
};

