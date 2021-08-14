#include "setDefine.h"
#include "iniManager.h"

HRESULT iniManager::init()
{
	return S_OK;
}

void iniManager::release()
{
}

//데이터 추가하기
void iniManager::addData(char * section, char * key, char * value)
{
	// ini 데이터 구조체 선언 후 초기화
	tagIniData data;
	data.section = section;
	data.key = key;
	data.value = value;

	//위 정보로 만들어진 ini 사용자 정의 변수를 벡터에 담기
	_vIniData.push_back(data);
}

//데이터 저장하기
void iniManager::saveINI(char * fileName)
{
	// 파일 저장에 앞서 저장 경로를 담을 char 배열
	char str[256], dir[256];
	ZeroMemory(str, sizeof(str));
	ZeroMemory(dir, sizeof(dir));
	wsprintf(str, "\\%s.ini", fileName);

	//현재 작업중인 프로젝트의 경로를 받아온다
	GetCurrentDirectory(256, dir);
	
	//문자열을 접합하는 함수 (string concatenate)
	strcat_s(dir, str);
	
	for (int i = 0; i < _vIniData.size(); i++)
	{
		// 위 정보를 토대로 ini 파일을 작성하여 데이터를 저장한다
		WritePrivateProfileString(_vIniData[i].section, _vIniData[i].key, _vIniData[i].value, dir);
	}
}

char * iniManager::loadDataString(char * fileName, char * section, char * key)
{
	// 파일 저장에 앞서 저장 경로를 담을 char 배열
	char str[256], dir[256];
	ZeroMemory(str, sizeof(str));
	ZeroMemory(dir, sizeof(dir));
	wsprintf(str, "\\%s.ini", fileName);

	//현재 작업중인 프로젝트의 경로를 받아온다
	GetCurrentDirectory(256, dir);

	//문자열을 접합하는 함수 (string concatenate)
	strcat_s(dir, str);

	char data[64] = { NULL };
	//GetPrivateProfileString(섹션, 키, 기본값, 값을 저장할 변수, 읽어올 문자열의 크기, ini 파일 위치)
	GetPrivateProfileString(section, key, "", data, 64, dir);

	return data;
}

int iniManager::loadDataInt(char * fileName, char * section, char * key)
{
	// 파일 저장에 앞서 저장 경로를 담을 char 배열
	char str[256], dir[256];
	ZeroMemory(str, sizeof(str));
	ZeroMemory(dir, sizeof(dir));
	wsprintf(str, "\\%s.ini", fileName);

	//현재 작업중인 프로젝트의 경로를 받아온다
	GetCurrentDirectory(256, dir);

	//문자열을 접합하는 함수 (string concatenate)
	strcat_s(dir, str);

	//GetPrivateProfileInt(섹션, 키, 기본값, ini 파일 위치)
	return GetPrivateProfileInt(section, key, 0, dir);
}
