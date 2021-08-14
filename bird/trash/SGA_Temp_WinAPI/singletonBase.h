#pragma once

//���ø�(Template)
/*
	1. ����
	  - �μ�(�Ű�����)�� Ÿ�Կ� ���� �Լ��� Ŭ������ �ڵ� �߷����� �����ϴ� ����
	  - ���ø��� ����ϸ� ���� Ÿ�Կ��� �۵��� �� �ִ� �ϳ��� �Լ��� Ŭ������ ���� �� �ִ�.


	 2. �Լ� ���ø�
	  - ������ Ÿ���� �ڵ� �߷��Ͽ� �Լ��� �����Ѵ�.
	  - ������ ������ Ÿ���� �μ��� �����Ͽ��� ��, �����Ϸ��� �ش� Ÿ�Կ� �����ϴ� �Լ��� ��ü������ �����ϰ� ȣ���Ѵ�.

				[����]
				template <typename Ÿ��>
				�Լ� ����
				{
					���๮
				}
			
			�� C++98���� �߰��� typename Ű���带 ����ϱ� �������� typename ��ſ� class Ű���带 ����ߴ�.
			�� ���� ���ø� �������� typename�� class�� ���� �ǹ��̴�.


	 3. Ŭ���� ���ø�
	  - ����� Ŭ������ �ٲ� �� ����� �⺻���� �ۼ� ����� �Լ� ���ø��� �����ϴ�.
	  - ������ Ÿ�Կ� ���� �����ϴ� Ŭ������ ���� �� �ִ�.

				[����]
				template <typename Ÿ��>
				class Ŭ������
				{
					��� �̰�����
				};

			�� ���⼭�� typename ��ſ� class �� �� �� �ִ�.
*/

//���ø� ����
/*
#include <iostream>
using namespace std;

//�Լ� ���ø� ����1 (������ Ÿ���� ���� �� ���� ������ ���ϴ� �Լ�)
template <typename T>
T Add(T a, T b)
{
	return a + b;
}

//�Լ� ���ø� ����2 (���� �ٸ� Ÿ���� ���� �� ���� ������ ���ϴ� �Լ�)
template <typename T1, typename T2>
void Add_D(T1 a, T2 b)
{
	cout << a + b;
}

//Ŭ���� ���ø� ���� - �پ��� Ÿ���� �����͸� �����ϴ� Ŭ����
template <typename T>
class Temp
{
private:
	T data;

public:
	Temp(T _data);	//�����ڿ��� ���ø� ������ �ʱ�ȭ
	
	//get&set �Լ�
	void setData(T _data);
	T getData();
};


template<typename T>
Temp<T>::Temp(T _data)
{
	//�����͸� ������ ���ø� ���� ���� �ʱ�ȭ
	data = _data;
}

template<typename T>
void Temp<T>::setData(T _data)
{
	//���� �����ϴ� set �Լ�
	data = _data;
}

template<typename T>
T Temp<T>::getData()
{
	//���� ��ȯ�ϴ� get �Լ�
	return data;
}

int main()
{
	//�Լ� ���ø� ��� �� (1)
	int a = 10, b = 20;
	float c = 1.0f, d = 3.0f;
	cout << "a + b�� �� : " << Add(a, b) << endl;
	cout << "c + d�� �� : " << Add(c, d) << endl;

	//�Լ� ���ø� ��� �� (2)
	float e = 3.10f;
	int f = 10;
	cout << "e + f�� �� : ";
	Add_D(e, f);

	//==========================================

	//Ŭ���� ���ø� ����
	//�ν��Ͻ� ����
	Temp<int> temp1(0);
	Temp<char> temp2('A');

	//���� �����Ͽ� �ν��Ͻ� ���� ������ ����
	temp1.setData(100);

	//����� ���� ���
	cout << temp1.getData() << endl;
	cout << temp2.getData() << endl;
	


	return 0;
}
*/

//�̱��� (singleton pattern)
/*
	1. ����
	  - Ư�� Ŭ������ �޸𸮸� �� ���� �Ҵ�ް�,
	     �Ҵ�� �޸𸮿� �ν��Ͻ��� �����Ͽ� ����ϴ� ������ ����.

	2. Ư¡
	  - ����� ������� Ŭ���� �����ڰ� ���� �� ȣ��Ǵ��� ������ ������ ��ü�� �ϳ� ��. �����ν� �ش� ������ ���� ������� ������ Ŭ������ static�� ����Ǳ� �����̴�.
	  - �޸� ������ �����ϰ� Ȯ���� ��Ȳ���� ��ǻ� new�� �� ���� ����� �Ͱ� �ٸ����� ������, ���ʿ��� �޸� ����� ���� �� �ִ�.
	  - ���� ������ �Ͱ� ���������� ��޵ǹǷ� �ٸ� �ν��Ͻ����� �����ϱ� ����.  
*/

template <typename T>
class singletonBase
{
protected:
	static T* singleton;		//�̱��� �ν��Ͻ� ����

	singletonBase() {}
	~singletonBase() {}

public:
	static T* getSingleton();	//�̱��� ��������
	void releaseSingleton();		//�̱��� ����
};

//�̱��� ��ü �ʱ�ȭ
template<typename T>
T* singletonBase<T>::singleton = 0;

template<typename T>
T * singletonBase<T>::getSingleton()
{
	//���� �̱����� ���� ��� ���� �����Ѵ�.
	if (!singleton) singleton = new T;

	return singleton;
}

template<typename T>
void singletonBase<T>::releaseSingleton()
{
	//�̱��� �����ϱ�
	if (singleton)
	{
		delete singleton;
		singleton = 0;
	}
}