#pragma once

//템플릿(Template)
/*
	1. 개요
	  - 인수(매개변수)의 타입에 따라 함수나 클래스를 자동 추론으로 생성하는 문법
	  - 템플릿을 사용하면 여러 타입에서 작동할 수 있는 하나의 함수나 클래스를 만들 수 있다.


	 2. 함수 템플릿
	  - 데이터 타입을 자동 추론하여 함수를 정의한다.
	  - 임의의 데이터 타입을 인수로 전달하였을 때, 컴파일러가 해당 타입에 부합하는 함수를 구체적으로 정의하고 호출한다.

				[문법]
				template <typename 타입>
				함수 원형
				{
					실행문
				}
			
			※ C++98에서 추가된 typename 키워드를 사용하기 전까지는 typename 대신에 class 키워드를 사용했다.
			※ 따라서 템플릿 한정으로 typename과 class는 같은 의미이다.


	 3. 클래스 템플릿
	  - 대상이 클래스로 바뀐 것 말고는 기본적인 작성 방법은 함수 템플릿과 동일하다.
	  - 데이터 타입에 따라 동작하는 클래스를 만들 수 있다.

				[문법]
				template <typename 타입>
				class 클래스명
				{
					멤버 이것저것
				};

			※ 여기서도 typename 대신에 class 가 들어갈 수 있다.
*/

//템플릿 예제
/*
#include <iostream>
using namespace std;

//함수 템플릿 예시1 (동일한 타입을 가진 두 개의 변수를 더하는 함수)
template <typename T>
T Add(T a, T b)
{
	return a + b;
}

//함수 템플릿 예시2 (서로 다른 타입을 가진 두 개의 변수를 더하는 함수)
template <typename T1, typename T2>
void Add_D(T1 a, T2 b)
{
	cout << a + b;
}

//클래스 템플릿 예시 - 다양한 타입의 데이터를 저장하는 클래스
template <typename T>
class Temp
{
private:
	T data;

public:
	Temp(T _data);	//생성자에서 템플릿 변수를 초기화
	
	//get&set 함수
	void setData(T _data);
	T getData();
};


template<typename T>
Temp<T>::Temp(T _data)
{
	//데이터를 저장할 템플릿 내부 변수 초기화
	data = _data;
}

template<typename T>
void Temp<T>::setData(T _data)
{
	//값을 저장하는 set 함수
	data = _data;
}

template<typename T>
T Temp<T>::getData()
{
	//값을 반환하는 get 함수
	return data;
}

int main()
{
	//함수 템플릿 사용 예 (1)
	int a = 10, b = 20;
	float c = 1.0f, d = 3.0f;
	cout << "a + b의 값 : " << Add(a, b) << endl;
	cout << "c + d의 값 : " << Add(c, d) << endl;

	//함수 템플릿 사용 예 (2)
	float e = 3.10f;
	int f = 10;
	cout << "e + f의 값 : ";
	Add_D(e, f);

	//==========================================

	//클래스 템플릿 예제
	//인스턴스 생성
	Temp<int> temp1(0);
	Temp<char> temp2('A');

	//값을 대입하여 인스턴스 내부 변수에 저장
	temp1.setData(100);

	//저장된 값을 출력
	cout << temp1.getData() << endl;
	cout << temp2.getData() << endl;
	


	return 0;
}
*/

//싱글톤 (singleton pattern)
/*
	1. 개요
	  - 특정 클래스가 메모리를 한 번만 할당받고,
	     할당된 메모리에 인스턴스를 생성하여 사용하는 디자인 패턴.

	2. 특징
	  - 빈번한 사용으로 클래스 생성자가 여러 번 호출되더라도 실제로 생성된 객체는 하나 뿐. 이유로써 해당 디자인 패턴 기반으로 생성된 클래스는 static로 선언되기 때문이다.
	  - 메모리 영역이 안전하게 확보된 상황에서 사실상 new를 한 번만 사용한 것과 다름없기 때문에, 불필요한 메모리 사용을 줄일 수 있다.
	  - 전역 선언한 것과 마찬가지로 취급되므로 다른 인스턴스들이 공유하기 쉽다.  
*/

template <typename T>
class singletonBase
{
protected:
	static T* singleton;		//싱글톤 인스턴스 선언

	singletonBase() {}
	~singletonBase() {}

public:
	static T* getSingleton();	//싱글톤 가져오기
	void releaseSingleton();		//싱글톤 삭제
};

//싱글톤 객체 초기화
template<typename T>
T* singletonBase<T>::singleton = 0;

template<typename T>
T * singletonBase<T>::getSingleton()
{
	//만약 싱글톤이 없을 경우 새로 생성한다.
	if (!singleton) singleton = new T;

	return singleton;
}

template<typename T>
void singletonBase<T>::releaseSingleton()
{
	//싱글톤 삭제하기
	if (singleton)
	{
		delete singleton;
		singleton = 0;
	}
}