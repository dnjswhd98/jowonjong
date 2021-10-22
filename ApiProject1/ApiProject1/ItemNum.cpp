#include "ItemNum.h"

void ItemNum::Initialize()
{
	a = 1;
	strKey = "ItemNum";
	for (int i = 0; i < 2; ++i)
		Frame[i] = 0;
	Score = Power;
	sScore = Power;
}

int ItemNum::Update()
{
	Score = Power;
	sScore = Power;

	if (sScore >= 10 && sScore < 100)
		a = 2;
	else if (sScore >= 100)
		a = 3;

	stack <int> Numbers;

	while (Score > 0)
	{
		int iTemp[3];
		for (int i = 0; i < 3; ++i)
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


    return 0;
}

void ItemNum::Render(HDC _hdc)
{
	for (int i = 0; i < a; ++i)
	{
		TransparentBlt(_hdc,
			int(TransInfo.Position.x - (16 * i)),
			int(TransInfo.Position.y),
			int(18),
			int(14),
			ImageList[strKey]->GetMemDC(),
			int(18 * Frame[i]),
			int(0),
			int(18),
			int(14),
			RGB(0, 0, 0));
	}
}

void ItemNum::Release()
{
}

ItemNum::ItemNum()
{
}

ItemNum::~ItemNum()
{
}
