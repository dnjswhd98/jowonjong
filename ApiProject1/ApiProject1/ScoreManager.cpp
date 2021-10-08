#include "ScoreManager.h"

ScoreManager* ScoreManager::Instance = nullptr;

void ScoreManager::Initialize()
{
	for(int i = 0;i<8;++i)
		Frame[i] = 0;
}

void ScoreManager::MakeScoreNumber()
{
	stack <int> Numbers;

	while (Score > 0)
	{
		int iTemp[9];
		for (int i = 0; i < 8; ++i)
		{
			iTemp[i] = int(Score % 10);
			Score /= 10;
			Frame[i] = iTemp[i];
			Numbers.push(iTemp[i]);
		}
	}

	while (!Numbers.empty())
	{
		NumberList.push_back(Numbers.top());
		Numbers.pop();
	}
}

void ScoreManager::Render(HDC _hdc)
{
	for (int i = 0; i < 8; ++i)
	{
		TransparentBlt(_hdc,
			int(Position.x - (20*i)),
			int(Position.y),
			int(20),
			int(18),
			Image->GetMemDC(),
			int(20 * Frame[i]),
			int(0),
			int(20),
			int(18),
			RGB(255, 0, 255));
	}
	
}
