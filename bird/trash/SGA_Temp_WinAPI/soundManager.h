#pragma once
#include "singletonBase.h"
#include "inc/fmod.hpp"

#pragma comment(lib,"lib/fmodex64_vc.lib")

using namespace FMOD;

#define EXTRA_CHANNEL_BUFFER 5
#define SOUND_BUFFER 20

#define TOTAL_SOUND_BUFFER (EXTRA_CHANNEL_BUFFER + SOUND_BUFFER)

class soundManager:public singletonBase<soundManager>
{
private:
	typedef map<string, Sound**>arrSounds;
	typedef map<string, Sound**>::iterator arrSounds_itr;

	System* _system;
	Sound** _sound;
	Channel** _channel;
	arrSounds _mTotalSound;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	void addSound(string keyName, string soundName, bool bgm = false, bool loop = false);
	void play(string keyName, float volume = 1.0);
	void stop(string keyName);
	void pause(string keyName);
	void resume(string keyName);

	bool isPlaySound(string keyName);
	bool isPauseSound(string keyName);

	soundManager():_system(NULL),_sound(NULL),_channel(NULL){}
	~soundManager(){}
};

