#pragma once
#include "singletonBase.h"

// ini ������ ����ü
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

	//������ �߰��ϱ�(����, Ű, ���)
	void addData(char* section, char* key, char* value);
	//������ �����ϱ�(���ϸ�)
	void saveINI(char* fileName);

	//���ڷ� ���� �ҷ�����
	char* loadDataString(char* fileName, char* section, char* key);
	//������ ���� �ҷ�����
	int loadDataInt(char* fileName, char* section, char* key);

	iniManager() {}
	~iniManager() {}
};

