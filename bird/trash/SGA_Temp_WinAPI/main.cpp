#include "setDefine.h"
#include "mainGame.h"

#pragma region Global Declarations
//핸들(HANDLE)에 대하여
/*
	- 대부분의 경우 32비트의 정수값을 가지고 있다.
	- 사용 목적은 오로지 구분을 하기 위함이며, 중복되는 값이 없도록 한다.
	- 핸들은 OS가 발급해주므로 사용자는 그대로 받아쓰기만 하면 된다.
	- 윈도우를 만들 거나 파일을 열 때 OS는 해당 윈도우 또는 파일에 핸들을 붙인다.
	- 핸들의 실제 값을 몰라도 전혀 상관이 없다.
	- 내부적으로 표식의 일종과 같이 사용되기 때문.
*/
HINSTANCE _hInstance;

//OS에서 해당 프로그램의 각 윈도우를 구별하고 관리하기 위한 객체
HWND _hWnd;

//윈도우의 타이틀 바에 들어갈 이름
LPTSTR _lpszClass = (LPTSTR)TEXT("Windows API");

//마우스 포인터의 좌표값을 담는다
POINT _ptMouse = { 0,0 };

//mainGame 클래스 동적 할당
mainGame* _mg;

//윈도우의 실제 작업 영역을 재설정
void setWindowSize(int x, int y, int width, int height);

//함수 전방 선언
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
#pragma endregion

#pragma region WinMain
//WinMain
/*
	hInstance : 프로그램 핸들 인스턴스
	hPrevInstance : 바로 앞(이전)에 실행되었던 인스턴스의 핸들.
								  WIN32에서는 기본 NULL.
    lpszCmdParam : 명령행으로 입력된 프로그램의 인수
	nCmdShow : 프로그램이 실행될 형태 (최대/최소화, 프레임 등)
*/
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	_hInstance = hInstance;

	//사용자가 입출력을 할 수 있도록 도와주는 윈도우 클래스
	//프로그램의 모든 윈도우는 이것을 기반으로 만들어진다.
	WNDCLASS wndClass;

	//Windows가 내부적으로 사용하는 일종의 예약 영역
	//사용자가 쓸 일이 거의 없다고 봐도 될 정도라 보통 0으로 초기화
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;

	//윈도우의 배경색을 지정
	//윈도우의 배경을 채색할 브러쉬를 지정하는 멤버
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);

	//윈도우가 사용할 마우스 커서와 최소화될 때 표시할 아이콘 지정
	//사용자가 직접 아이콘과 커서를 변경할 수 있다.
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	
	//윈도우 클래스를 사용하기 위한 프로그램 번호
	//WinMain의 매개변수로 전달된 hInstance의 값을 사용
	wndClass.hInstance = hInstance;

	//윈도우의 메시지 처리 함수를 지정
	//메시지가 발생할 때마다 지정된 함수를 호출
	wndClass.lpfnWndProc = (WNDPROC)WndProc;

	wndClass.lpszClassName = WIN_NAME;
	wndClass.lpszMenuName = NULL;

	//윈도우의 스타일을 정의한다.
	//윈도우의 수직(또는 수평)의 크기가 변할 경우 윈도우를 다시 그린다.
	wndClass.style = WIN_STYLE;

	//어떠한 특성을 가진 윈도우를 사용하겠다고 등록하는 함수
	RegisterClass(&wndClass);

	_hWnd = CreateWindow(
		//lpszClassName : 생성하고자 하는 윈도우의 클래스를 지정하는 문자열
		WIN_NAME,
		
		//lpszWindowName : 윈도우의 타이틀 바에 나타낼 문자열
		WIN_NAME,
		
		//dwStyle : 시스템 메뉴, 최대/최소화 버튼, 타이틀 바, 외곽선(경계선)을 가진 윈도우
		WS_OVERLAPPEDWINDOW,
		
		//x, y, nWidth, nHeight	: 윈도우의 크기와 위치를 지정
		//CW_USEDEFAULT 를 입력하면 OS가 일아서 적당한 크기와 위치를 설정한다.
		WINSTART_X, WINSTART_Y, WINSIZE_X, WINSIZE_Y,
		
		//hWndParent : 부모 윈도우가 있을 경우 부모 윈도우의 핸들을 지정
		NULL,
		
		//hmenu = 윈도우에서 사용할 메뉴의 핸들
		(HMENU)NULL,

		//hinst : 윈도우를 만드는 주체, 주로 프로그램 핸들을 지칭
		//WinMain의 매개변수로 전달된 hInstance 값을 그대로 사용
		hInstance,

		//pvParam : CREATSTRUCT 라는 구조체의 번지(주소)를 가리킨다. 보통 NULL을 입력.
		NULL
	);

	setWindowSize(WINSTART_X, WINSTART_Y, WINSIZE_X, WINSIZE_Y);

	//윈도우를 화면에 출력하기 위한 방법을 넘겨준다.
	ShowWindow(_hWnd, nCmdShow);
	
	//만약 초기화에 실패했을 경우, 그대로 프로세스를 종료한다.
	_mg = new mainGame();
	if (FAILED(_mg->init()))
	{
		return 0;
	}

	//메시지 구조체
	MSG message;
	//GetMessage : 시스템이 유지하고 있는 메시지 큐(Queue)에서 메시지를 읽어들인다.
	while (GetMessage(&message, 0, 0, 0))
	{
		//TranslateMessage
		/*
			입력 또는 입력 해제 이벤트가 발생했을 때, 입력됐다는 메시지를 만듦.
			예를 들어서 A키를 누른 후에 다시 A키에서 손을 떼면 A라는 문자가 입력됐다는 메시지를 내부에서 만든다.
		*/
		TranslateMessage(&message);
		
		//DispatchMessage : 메시지를 처리 함수인 WndProc에 전달
		//해당 메시지를 점검한 후에 다음 동작을 결정할 수 있도록 도와준다.
		DispatchMessage(&message);
	}


	return message.wParam;
}
#pragma endregion

void setWindowSize(int x, int y, int width, int height)
{
	RECT rc = { 0,0,width, height };

	AdjustWindowRect(&rc, WIN_STYLE, false);

	//위에서 설정한 RECT 정보로 윈도우의 크기를 재조정한다.
	SetWindowPos(_hWnd, NULL, x, y, (rc.right - rc.left), (rc.bottom - rc.top), SWP_NOZORDER | SWP_NOMOVE);
}

//WndProc : 발생한 메시지를 OS에 전달하고 본격적인 처리도 겸하는 함수
/*
	hWnd : 어느 윈도우에서 발생한 메시지인지를 구분한다.
	iMessage : 메시지 구분 번호.
	wParam : 마우스 버튼의 상태 또는 키보드의 입력 상태를 전달한다.
	lParam : 마우스 클릭 혹은 커서가 이동할 때의 좌표를 (x, y) 형식으로 전달한다.
*/
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	//DC(Device Context)에 대하여
	/*
		화면에 출력할 여러 정보를 담고 있는 데이터 구조체이다.
		선의 색상과 굵기, 채움(Fill) 무늬의 종류나 색상, 출력 방법 등을 포함하고 있다.
	*/
	return _mg->MainProc(hWnd, iMessage, wParam, lParam);
}