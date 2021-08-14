#pragma once
#include "cocos2d.h"

class Sound
{
public:
	
	int bgmI, bgmL;
	int lEf, eEf, oEf;

	void playRain();
	void playCasthle();

	void linkEf(const std::string& st);
	void linkEfstop();
};