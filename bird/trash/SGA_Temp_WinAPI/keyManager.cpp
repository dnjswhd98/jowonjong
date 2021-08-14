#include "setDefine.h"
#include "keyManager.h"

HRESULT keyManager::init()
{
	//키보드 입력이 없는 상태로 초기화
	for (int i = 0; i < KEYMAX; i++)
	{
		_keyUp[i] = false;
		_keyDown[i] = false;
	}

	return S_OK;
}

bool keyManager::isOnceKeyDown(int key)
{
	if (GetAsyncKeyState(key) & 0x8000)
	{
		if (!_keyDown[key])
		{
			_keyDown[key] = true;
			return true;
		}
	}
	else
	{
		_keyDown[key] = false;
	}

	return false;
}

bool keyManager::isOnceKeyUp(int key)
{
	if (GetAsyncKeyState(key) & 0x8000)
	{
		_keyUp[key] = true;
	}
	else
	{
		if (_keyUp[key])
		{
			_keyUp[key] = false;
			return true;
		}
	}
	return false;
}

bool keyManager::isStayKeyDown(int key)
{
	if (GetAsyncKeyState(key) & 0x8000) return true;
	return false;
}

bool keyManager::isToggleKey(int key)
{
	if (GetKeyState(key) & 0x0001) return true;
	return false;
}

//GetAsyncKeyState(), GetKeyState() 함수에 대하여
/*
	1. 함수 원형
		=> SHORT GetAsyncKeyState(int vKey)

	2. 상세
	  - 입력할 키가 많은 경우에는 GetkeyboardState 를 사용하여 한꺼번에 검사하나, 그렇게 검사할 키가 많지 않은 경우엔 GetKeyState 혹은 GetAsyncKeyState를 사용한다.
	 
	3. GetKeyState 혹은 GetAsyncKeyState의 차이점
	  - GetKeyState 메시지 큐에 저장된 데이터를 기반으로 검사한다. 어떤 작업을 처리하는 도중에 키를 눌러도 GetKeyState는 반응하지 않는다.
	  - GetAsyncKeyState 는 키를 입력할 때 메시지 큐를 거치지 않고 즉시 반응하기 때문에 실시간으로 처리를 필요로 하는 경우 사용한다.

	 4. 속도 차이
	   ※ 약 10만회 반복 입력을 기준으로 결과를 산출
	   1) GetAsyncKeyState : 31ms
	   2) GetKeyState : 47ms
*/

//키 입력 비트 목록
/*
	※ 0x0000 : 이전에 누른 적이 없고, 호출 시점에도 안 눌린 상태
	※ 0x0001 : 이전에 누른 적이 있고, 호출 시점에는 안 눌린 상태

	※ 0x8000 : 이전에 누른 적이 없고, 호출 시점에는 눌린 상태
	※ 0x8001 : 이전에 누른 적이 있고, 호출 시점에도 눌린 상태

	※ '이전'이 가리키는 시간적 의미 : 이전 GetAsyncKeyState()를 호출한 후 ~
														지금 GetAsyncKeyState()를 호출하기 직전
*/