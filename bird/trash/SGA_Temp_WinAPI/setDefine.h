#pragma once

//�ܼ�â ����
#ifdef UNICODE	//�������� : �����ڵ�
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")
#else	//�������� : ��Ƽ����Ʈ �Ǵ� ��Ÿ
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#endif

#define WIN32_LEAN_AND_MEAN
#include <sdkddkver.h>

//������ ��� ����
#include <Windows.h>

//C��� ��Ÿ�� ��� ����
#include <cstdlib>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

//C++ ��Ÿ�� ��� ����
#include <iostream>
#include <numeric>
#include <vector>
#include <list>
#include <map>
#include <string>

//���ӽ����̽�
using namespace std;



/*=================================
		����� ���� ��� ���� ���
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
		�Ŵ��� ��� (�̱���)
=================================*/
#define KEYMANAGER keyManager::getSingleton()
#define RND randomFunction::getSingleton()
#define IMAGEMANAGER imageManager::getSingleton()
#define SCENEMANAGER sceneManager::getSingleton()
#define INI_DATA iniManager::getSingleton()
#define SOUNDMANAGER soundManager::getSingleton()


/*=================================
		������ ���� Define ����
=================================*/
#define WIN_NAME (LPTSTR)(TEXT("Windows API"))
#define WINSTART_X 400
#define WINSTART_Y 100
#define WINSIZE_X 800
#define WINSIZE_Y 800
#define WIN_STYLE CS_HREDRAW | CS_VREDRAW



/*=================================
					extern ����
=================================*/
extern HINSTANCE _hInstance;
extern HWND _hWnd;
extern POINT _ptMouse;



/*=================================
	�����Ҵ�� ��ü�� �����ϴ� ��ũ�� �Լ�
=================================*/
#define SAFE_DELETE(p) {if(p) {delete (p); (p) = NULL;}}
#define SAFE_DELETE_ARRAY(p)  {if(p) {delete[] (p); (p) = NULL;}}