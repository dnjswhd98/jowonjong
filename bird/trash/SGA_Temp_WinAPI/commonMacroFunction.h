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

//인라인 함수 (Inline Function)
/*
	1. 개요
	  - 매크로 함수의 장점과 일반 함수의 특징을 결합한 함수이다.
	  - 본질적으로는 함수의 성질을 갖고 있어, 매개변수에 데이터 타입을 지정할 수 있다.

	2. 구조
	inline 리턴타입 함수명 (매개변수 목록)
	{
		코드 블록 (실행문)
	}

	3. 주의사항
	  - 코드의 반복적인 사용이 필연적인 프로그래밍에서 길이가 일정 수준 이상 길어지면 사용을 지양해야 한다.
	  - 프로그램의 안정성을 위해 컴파일러가 자체적으로 코드 길이를 제한하고 있다.
*/