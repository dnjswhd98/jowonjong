#include "Headers.h"
#include "MainUpdate.h"

using namespace std;

int main()
{
	MainUpdate Main;
	Main.Initialize();

	ULONGLONG Time = GetTickCount64();	// 1/1000�ʸ� ��ȯ�ϴ� �Լ�

	while (true)
	{

		if (Time + 1000 < GetTickCount64())
		{
			Time = GetTickCount64();

			//����
			Main.Update();
			Main.Render();
		}
	}


	return 0;
}