#pragma once
#include <ctime>
#include "singletonBase.h"

class randomFunction : public singletonBase<randomFunction>
{
public:
	//GetTickCount() : OS가 부팅된 이후부터 현재 시간을 1ms 단위로 카운트하여 반환
	randomFunction() { srand(GetTickCount()); };
	~randomFunction() {};

	HRESULT init() { return S_OK; }


	//========


	//Normal Random Function
	inline int getInt(int num)
	{
		return rand() % num;
	}

	//Range-based Random Function
	inline int getFromIntTo(int fromNum, int toNum)
	{
		return rand() % (toNum - fromNum + 1) + fromNum;
	}

	// RAND_MAX = 32767
	inline float getFloat(float num)
	{
		return ((float)rand() / (float)RAND_MAX) * num;
	}

	inline float getFromFloatTo(float fromNum, float toNum)
	{
		float rnd = (float)rand() / (float)RAND_MAX;
		return (rnd * (toNum - fromNum) + fromNum);
	}
};