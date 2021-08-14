#include "setDefine.h"
#include "iniManager.h"

HRESULT iniManager::init()
{
	return S_OK;
}

void iniManager::release()
{
}

//������ �߰��ϱ�
void iniManager::addData(char * section, char * key, char * value)
{
	// ini ������ ����ü ���� �� �ʱ�ȭ
	tagIniData data;
	data.section = section;
	data.key = key;
	data.value = value;

	//�� ������ ������� ini ����� ���� ������ ���Ϳ� ���
	_vIniData.push_back(data);
}

//������ �����ϱ�
void iniManager::saveINI(char * fileName)
{
	// ���� ���忡 �ռ� ���� ��θ� ���� char �迭
	char str[256], dir[256];
	ZeroMemory(str, sizeof(str));
	ZeroMemory(dir, sizeof(dir));
	wsprintf(str, "\\%s.ini", fileName);

	//���� �۾����� ������Ʈ�� ��θ� �޾ƿ´�
	GetCurrentDirectory(256, dir);
	
	//���ڿ��� �����ϴ� �Լ� (string concatenate)
	strcat_s(dir, str);
	
	for (int i = 0; i < _vIniData.size(); i++)
	{
		// �� ������ ���� ini ������ �ۼ��Ͽ� �����͸� �����Ѵ�
		WritePrivateProfileString(_vIniData[i].section, _vIniData[i].key, _vIniData[i].value, dir);
	}
}

char * iniManager::loadDataString(char * fileName, char * section, char * key)
{
	// ���� ���忡 �ռ� ���� ��θ� ���� char �迭
	char str[256], dir[256];
	ZeroMemory(str, sizeof(str));
	ZeroMemory(dir, sizeof(dir));
	wsprintf(str, "\\%s.ini", fileName);

	//���� �۾����� ������Ʈ�� ��θ� �޾ƿ´�
	GetCurrentDirectory(256, dir);

	//���ڿ��� �����ϴ� �Լ� (string concatenate)
	strcat_s(dir, str);

	char data[64] = { NULL };
	//GetPrivateProfileString(����, Ű, �⺻��, ���� ������ ����, �о�� ���ڿ��� ũ��, ini ���� ��ġ)
	GetPrivateProfileString(section, key, "", data, 64, dir);

	return data;
}

int iniManager::loadDataInt(char * fileName, char * section, char * key)
{
	// ���� ���忡 �ռ� ���� ��θ� ���� char �迭
	char str[256], dir[256];
	ZeroMemory(str, sizeof(str));
	ZeroMemory(dir, sizeof(dir));
	wsprintf(str, "\\%s.ini", fileName);

	//���� �۾����� ������Ʈ�� ��θ� �޾ƿ´�
	GetCurrentDirectory(256, dir);

	//���ڿ��� �����ϴ� �Լ� (string concatenate)
	strcat_s(dir, str);

	//GetPrivateProfileInt(����, Ű, �⺻��, ini ���� ��ġ)
	return GetPrivateProfileInt(section, key, 0, dir);
}
