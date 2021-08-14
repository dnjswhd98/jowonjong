#pragma once

//콘솔창 띄우기
#ifdef UNICODE	//문자집합 : 유니코드
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")
#else	//문자집합 : 멀티바이트 또는 기타
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#endif

#define WIN32_LEAN_AND_MEAN
#include <sdkddkver.h>

//윈도우 헤더 파일
#include <Windows.h>

//C언어 런타임 헤더 파일
#include <cstdlib>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

//C++ 런타임 헤더 파일
#include <iostream>
#include <numeric>
#include <vector>
#include <list>
#include <map>
#include <string>

//네임스페이스
using namespace std;



/*=================================
		사용자 정의 헤더 파일 목록
=================================*/
#include "customMath.h"
#include "commonMacroFunction.h"
#include "keyManager.h"
#include "randomFunction.h"
#include "imageManager.h"
#include "sceneManager.h"
#include "iniManager.h"
#include "soundManager.h"
using namespace Util;


/*=================================
		매니저 목록 (싱글톤)
=================================*/
#define KEYMANAGER keyManager::getSingleton()
#define RND randomFunction::getSingleton()
#define IMAGEMANAGER imageManager::getSingleton()
#define SCENEMANAGER sceneManager::getSingleton()
#define INI_DATA iniManager::getSingleton()
#define SOUNDMANAGER soundManager::getSingleton()


/*=================================
		윈도우 관련 Define 모음
=================================*/
#define WIN_NAME (LPTSTR)(TEXT("Windows API"))
#define WINSTART_X 400
#define WINSTART_Y 100
#define WINSIZE_X 800
#define WINSIZE_Y 800
#define WIN_STYLE CS_HREDRAW | CS_VREDRAW



/*=================================
					extern 변수
=================================*/
extern HINSTANCE _hInstance;
extern HWND _hWnd;
extern POINT _ptMouse;



/*=================================
	동적할당된 객체를 해제하는 매크로 함수
=================================*/
#define SAFE_DELETE(p) {if(p) {delete (p); (p) = NULL;}}
#define SAFE_DELETE_ARRAY(p)  {if(p) {delete[] (p); (p) = NULL;}}