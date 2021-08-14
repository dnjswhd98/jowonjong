#include "Sound.h"
#include "AudioEngine.h"

USING_NS_CC;
using namespace experimental;

void Sound::playRain()
{
	

	bgmI = AudioEngine::play2d("sound/bgm/rainIntro.mp3", false, 1.0);

	//특정 사운드가 재생중인지 검사한다
	if (AudioEngine::getState(bgmI) != AudioEngine::AudioState::PLAYING)
	{
		//만약 재생중이 아니라면 사운드 재생
		bgmI = AudioEngine::play2d("sound/bgm/rainIntro.mp3", false, 1.0);

		//audioId2 에 할당된 사운드의 재생이 끝났다?
		if (bgmI != AudioEngine::INVALID_AUDIO_ID)
		{
			bgmL = AudioEngine::play2d("sound/bgm/rainLoop.mp3", true, 1.0);
		
		}
	}
}

void Sound::playCasthle()
{

	//bgmI = AudioEngine::play2d("sound/bgm/hyruleCastleIntro.mp3", false, 1.0);

	//특정 사운드가 재생중인지 검사한다
	if (AudioEngine::getState(bgmI) != AudioEngine::AudioState::PLAYING)
	{
		//만약 재생중이 아니라면 사운드 재생
		bgmI = AudioEngine::play2d("sound/bgm/hyruleCastleIntro.mp3", false, 1.0);

		//audioId2 에 할당된 사운드의 재생이 끝났다?
		if (bgmI != AudioEngine::INVALID_AUDIO_ID)
		{
			bgmL = AudioEngine::play2d("sound/bgm/hyruleCastleLoop.mp3", true, 1.0);

		}
	}
}

void Sound::linkEf(const std::string & st)
{
	if (AudioEngine::getState(lEf) != AudioEngine::AudioState::PLAYING)
	{
		lEf = AudioEngine::play2d(st, false, 1.0);
	}
}

void Sound::linkEfstop()
{
	AudioEngine::stopAll();
}


