#pragma once
#include "Headers.h"

class InputManager
{
private:
	static InputManager* Instance;
public:
	static InputManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new InputManager;

		return Instance;
	}
private:
	DWORD Key;
public:
	DWORD GetKey() const { return Key; }

	Vector3 GetMousePosition()
	{
		POINT ptMouse;

		GetCursorPos(&ptMouse);

		ScreenToClient(g_hWnd, &ptMouse);

		return Vector3((float)ptMouse.x, (float)ptMouse.y);
	}

	void CheckKey();
private:
	InputManager() : Key(0) {}
public:
	~InputManager() {}
};

