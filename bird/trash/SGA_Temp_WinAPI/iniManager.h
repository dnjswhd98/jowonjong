#pragma once
#include "singletonBase.h"

// ini 데이터 구조체
struct tagIniData
{
	char* section;
	char* key;
	char* value;
};

class iniManager : public singletonBase<iniManager>
{
private:
	vector<tagIniData> _vIniData;

public:
	HRESULT init();
	void release();

	//데이터 추가하기(섹션, 키, 밸류)
	void addData(char* section, char* key, char* value);
	//데이터 저장하기(파일명)
	void saveINI(char* fileName);

	//문자로 값을 불러오기
	char* loadDataString(char* fileName, char* section, char* key);
	//정수로 값을 불러오기
	int loadDataInt(char* fileName, char* section, char* key);

	iniManager() {}
	~iniManager() {}
};

