#include "setDefine.h"
#include "soundManager.h"

HRESULT soundManager::init()
{
	System_Create(&_system);

	_system->init(TOTAL_SOUND_BUFFER, FMOD_INIT_NORMAL, 0);

	_sound = new Sound*[TOTAL_SOUND_BUFFER];
	_channel = new Channel*[TOTAL_SOUND_BUFFER];

	memset(_sound, 0, sizeof(Sound*)*TOTAL_SOUND_BUFFER);
	memset(_channel, 0, sizeof(Channel*)*TOTAL_SOUND_BUFFER);

	return S_OK;
}

void soundManager::release()
{
	//사운드 채널 릴리즈
	if (_channel != NULL || _sound != NULL)
	{
		for (int i = 0; i < TOTAL_SOUND_BUFFER; i++)
		{
			if (_channel != NULL) _channel[i]->stop();
			if (_sound != NULL)_sound[i]->release();
		}
	}
	SAFE_DELETE_ARRAY(_sound);
	SAFE_DELETE_ARRAY(_channel);

	if (_system != NULL)
	{
		_system->release();
		_system->close();
	}
}

void soundManager::update()
{
	_system->update();
}

void soundManager::render()
{
}

void soundManager::addSound(string keyName, string soundName, bool bgm, bool loop)
{
	//BGM재생하기
	if (loop)
	{
		//진짜 bgm 재생
		if (bgm)
		{
			_system->createStream(soundName.c_str(), FMOD_LOOP_NORMAL, 0, &_sound[_mTotalSound.size()]);
		}
		//반복재생이 필요한 효과음
		else
		{
			_system->createStream(soundName.c_str(), FMOD_LOOP_NORMAL, 0, &_sound[_mTotalSound.size()]);
		}
	}
	else
	{
		_system->createStream(soundName.c_str(), FMOD_DEFAULT, 0, &_sound[_mTotalSound.size()]);
	}

	_mTotalSound.insert(make_pair(keyName, &_sound[_mTotalSound.size()]));
}

void soundManager::play(string keyName, float volume)
{
	int count = 0;
	arrSounds_itr itr = _mTotalSound.begin();

	for (itr; itr != _mTotalSound.end(); ++itr, count++)
	{
		if (keyName == itr->first)
		{
			_system->playSound(FMOD_CHANNEL_FREE, *itr->second, false, &_channel[count]);

			_channel[count]->setVolume(volume);
		}
	}
}

void soundManager::stop(string keyName)
{
	int count = 0;
	arrSounds_itr itr = _mTotalSound.begin();

	for (itr; itr != _mTotalSound.end(); ++itr, count++)
	{
		if (keyName == itr->first)
		{
			_channel[count]->stop();
			break;
		}
	}
}

void soundManager::pause(string keyName)
{
	int count = 0;
	arrSounds_itr itr = _mTotalSound.begin();

	for (itr; itr != _mTotalSound.end(); ++itr, count++)
	{
		if (keyName == itr->first)
		{
			_channel[count]->setPaused(true);
			break;
		}
	}
}

void soundManager::resume(string keyName)
{
	int count = 0;
	arrSounds_itr itr = _mTotalSound.begin();

	for (itr; itr != _mTotalSound.end(); ++itr, count++)
	{
		if (keyName == itr->first)
		{
			_channel[count]->setPaused(false);
			break;
		}
	}
}

bool soundManager::isPlaySound(string keyName)
{
	bool play;
	int count = 0;
	arrSounds_itr itr = _mTotalSound.begin();

	for (itr; itr != _mTotalSound.end(); ++itr, count++)
	{
		if (keyName == itr->first)
		{
			//사운드가 현재 재생중인지 확인하고 그 값을 play에 담아 반환한다
			_channel[count]->setPaused(&play);
			break;
		}
	}
	return play;
}

bool soundManager::isPauseSound(string keyName)
{
	bool pause;
	int count = 0;
	arrSounds_itr itr = _mTotalSound.begin();

	for (itr; itr != _mTotalSound.end(); ++itr, count++)
	{
		if (keyName == itr->first)
		{
			//사운드가 현재 재생중인지 확인하고 그 값을 play에 담아 반환한다
			_channel[count]->setPaused(&pause);
			break;
		}
	}
	return pause;
}
