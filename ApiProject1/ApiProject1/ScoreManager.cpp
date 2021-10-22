#include "ScoreManager.h"

ScoreManager* ScoreManager::Instance = nullptr;

void ScoreManager::Initialize()
{
	for(int i = 0;i<9;++i)
		Frame[i] = 0;
}

void ScoreManager::MakeScoreNumber()
{
	stack <int> Numbers;

	while (Score > 0)
	{
		int iTemp[10];
		for (int i = 0; i < 9; ++i)
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
	for (int i = 0; i < 9; ++i)
	{
		TransparentBlt(_hdc,
			int(Position.x - (16*i)),
			int(Position.y),
			int(18),
			int(14),
			Image->GetMemDC(),
			int(18 * Frame[i]),
			int(0),
			int(18),
			int(14),
			RGB(0, 0, 0));
	}
	
}

