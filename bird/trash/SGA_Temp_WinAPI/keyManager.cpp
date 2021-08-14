#include "setDefine.h"
#include "keyManager.h"

HRESULT keyManager::init()
{
	//Ű���� �Է��� ���� ���·� �ʱ�ȭ
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

//GetAsyncKeyState(), GetKeyState() �Լ��� ���Ͽ�
/*
	1. �Լ� ����
		=> SHORT GetAsyncKeyState(int vKey)

	2. ��
	  - �Է��� Ű�� ���� ��쿡�� GetkeyboardState �� ����Ͽ� �Ѳ����� �˻��ϳ�, �׷��� �˻��� Ű�� ���� ���� ��쿣 GetKeyState Ȥ�� GetAsyncKeyState�� ����Ѵ�.
	 
	3. GetKeyState Ȥ�� GetAsyncKeyState�� ������
	  - GetKeyState �޽��� ť�� ����� �����͸� ������� �˻��Ѵ�. � �۾��� ó���ϴ� ���߿� Ű�� ������ GetKeyState�� �������� �ʴ´�.
	  - GetAsyncKeyState �� Ű�� �Է��� �� �޽��� ť�� ��ġ�� �ʰ� ��� �����ϱ� ������ �ǽð����� ó���� �ʿ�� �ϴ� ��� ����Ѵ�.

	 4. �ӵ� ����
	   �� �� 10��ȸ �ݺ� �Է��� �������� ����� ����
	   1) GetAsyncKeyState : 31ms
	   2) GetKeyState : 47ms
*/

//Ű �Է� ��Ʈ ���
/*
	�� 0x0000 : ������ ���� ���� ����, ȣ�� �������� �� ���� ����
	�� 0x0001 : ������ ���� ���� �ְ�, ȣ�� �������� �� ���� ����

	�� 0x8000 : ������ ���� ���� ����, ȣ�� �������� ���� ����
	�� 0x8001 : ������ ���� ���� �ְ�, ȣ�� �������� ���� ����

	�� '����'�� ����Ű�� �ð��� �ǹ� : ���� GetAsyncKeyState()�� ȣ���� �� ~
														���� GetAsyncKeyState()�� ȣ���ϱ� ����
*/