#include "Headers.h"
#include "MainUpdate.h"

using namespace std;

int main()
{
	MainUpdate Main;
	Main.Initialize();

	ULONGLONG Time = GetTickCount64();	// 1/1000초를 반환하는 함수

	while (true)
	{

		if (Time + 1000 < GetTickCount64())
		{
			Time = GetTickCount64();

			//루프
			Main.Update();
			Main.Render();
		}
	}


	return 0;
}