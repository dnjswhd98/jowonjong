#pragma once
#include <Windows.h>

inline RECT RectMake(int x, int y, int width, int height)
{
	RECT rc = { x, y, x + width, y + height };
	return rc;
}

inline RECT RectMakeCenter(int x, int y, int width, int height)
{
	RECT rc = { x - width / 2, y - height / 2, x + width / 2, y + height / 2 };
	return rc;
}

inline void RectangleMake(HDC hdc, int x, int y, int width, int height)
{
	Rectangle(hdc, x, y, x + width, y + height);
}

inline void RectangleMake(HDC hdc, RECT rc)
{
	Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);
}

inline void EllipseMake(HDC hdc, int x, int y, int width, int height)
{
	Ellipse(hdc, x, y, x + width, y + height);
}

inline void EllipseMakeCenter(HDC hdc, int x, int y, int width, int height)
{
	Ellipse(hdc, x - width / 2, y - height / 2, x + width / 2, y + height / 2);
}

inline void LineMake(HDC hdc, POINT startPT, POINT endPT)
{
	MoveToEx(hdc, startPT.x, startPT.y, NULL);
	LineTo(hdc, endPT.x, endPT.y);
}

//�ζ��� �Լ� (Inline Function)
/*
	1. ����
	  - ��ũ�� �Լ��� ������ �Ϲ� �Լ��� Ư¡�� ������ �Լ��̴�.
	  - ���������δ� �Լ��� ������ ���� �־�, �Ű������� ������ Ÿ���� ������ �� �ִ�.

	2. ����
	inline ����Ÿ�� �Լ��� (�Ű����� ���)
	{
		�ڵ� ��� (���๮)
	}

	3. ���ǻ���
	  - �ڵ��� �ݺ����� ����� �ʿ����� ���α׷��ֿ��� ���̰� ���� ���� �̻� ������� ����� �����ؾ� �Ѵ�.
	  - ���α׷��� �������� ���� �����Ϸ��� ��ü������ �ڵ� ���̸� �����ϰ� �ִ�.
*/