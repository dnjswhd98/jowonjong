#include "StageBack.h"

void StageBack::Initialize()
{
}

int StageBack::Update()
{
	return 0;
}

void StageBack::Render(HDC _hdc)
{
	Rectangle(_hdc, 0, 0, WindowsWidth, WindowsHeight);
}

void StageBack::Release()
{
}

StageBack::StageBack()
{
}

StageBack::~StageBack()
{
}
