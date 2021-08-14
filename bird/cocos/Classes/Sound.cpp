#include "Sound.h"
#include "AudioEngine.h"

USING_NS_CC;
using namespace experimental;

void Sound::playRain()
{
	

	bgmI = AudioEngine::play2d("sound/bgm/rainIntro.mp3", false, 1.0);

	//Ư�� ���尡 ��������� �˻��Ѵ�
	if (AudioEngine::getState(bgmI) != AudioEngine::AudioState::PLAYING)
	{
		//���� ������� �ƴ϶�� ���� ���
		bgmI = AudioEngine::play2d("sound/bgm/rainIntro.mp3", false, 1.0);

		//audioId2 �� �Ҵ�� ������ ����� ������?
		if (bgmI != AudioEngine::INVALID_AUDIO_ID)
		{
			bgmL = AudioEngine::play2d("sound/bgm/rainLoop.mp3", true, 1.0);
		
		}
	}
}

void Sound::playCasthle()
{

	//bgmI = AudioEngine::play2d("sound/bgm/hyruleCastleIntro.mp3", false, 1.0);

	//Ư�� ���尡 ��������� �˻��Ѵ�
	if (AudioEngine::getState(bgmI) != AudioEngine::AudioState::PLAYING)
	{
		//���� ������� �ƴ϶�� ���� ���
		bgmI = AudioEngine::play2d("sound/bgm/hyruleCastleIntro.mp3", false, 1.0);

		//audioId2 �� �Ҵ�� ������ ����� ������?
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


