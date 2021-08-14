#include "setDefine.h"
#include "mainGame.h"

#pragma region Global Declarations
//�ڵ�(HANDLE)�� ���Ͽ�
/*
	- ��κ��� ��� 32��Ʈ�� �������� ������ �ִ�.
	- ��� ������ ������ ������ �ϱ� �����̸�, �ߺ��Ǵ� ���� ������ �Ѵ�.
	- �ڵ��� OS�� �߱����ֹǷ� ����ڴ� �״�� �޾ƾ��⸸ �ϸ� �ȴ�.
	- �����츦 ���� �ų� ������ �� �� OS�� �ش� ������ �Ǵ� ���Ͽ� �ڵ��� ���δ�.
	- �ڵ��� ���� ���� ���� ���� ����� ����.
	- ���������� ǥ���� ������ ���� ���Ǳ� ����.
*/
HINSTANCE _hInstance;

//OS���� �ش� ���α׷��� �� �����츦 �����ϰ� �����ϱ� ���� ��ü
HWND _hWnd;

//�������� Ÿ��Ʋ �ٿ� �� �̸�
LPTSTR _lpszClass = (LPTSTR)TEXT("Windows API");

//���콺 �������� ��ǥ���� ��´�
POINT _ptMouse = { 0,0 };

//mainGame Ŭ���� ���� �Ҵ�
mainGame* _mg;

//�������� ���� �۾� ������ �缳��
void setWindowSize(int x, int y, int width, int height);

//�Լ� ���� ����
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
#pragma endregion

#pragma region WinMain
//WinMain
/*
	hInstance : ���α׷� �ڵ� �ν��Ͻ�
	hPrevInstance : �ٷ� ��(����)�� ����Ǿ��� �ν��Ͻ��� �ڵ�.
								  WIN32������ �⺻ NULL.
    lpszCmdParam : ��������� �Էµ� ���α׷��� �μ�
	nCmdShow : ���α׷��� ����� ���� (�ִ�/�ּ�ȭ, ������ ��)
*/
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	_hInstance = hInstance;

	//����ڰ� ������� �� �� �ֵ��� �����ִ� ������ Ŭ����
	//���α׷��� ��� ������� �̰��� ������� ���������.
	WNDCLASS wndClass;

	//Windows�� ���������� ����ϴ� ������ ���� ����
	//����ڰ� �� ���� ���� ���ٰ� ���� �� ������ ���� 0���� �ʱ�ȭ
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;

	//�������� ������ ����
	//�������� ����� ä���� �귯���� �����ϴ� ���
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);

	//�����찡 ����� ���콺 Ŀ���� �ּ�ȭ�� �� ǥ���� ������ ����
	//����ڰ� ���� �����ܰ� Ŀ���� ������ �� �ִ�.
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	
	//������ Ŭ������ ����ϱ� ���� ���α׷� ��ȣ
	//WinMain�� �Ű������� ���޵� hInstance�� ���� ���
	wndClass.hInstance = hInstance;

	//�������� �޽��� ó�� �Լ��� ����
	//�޽����� �߻��� ������ ������ �Լ��� ȣ��
	wndClass.lpfnWndProc = (WNDPROC)WndProc;

	wndClass.lpszClassName = WIN_NAME;
	wndClass.lpszMenuName = NULL;

	//�������� ��Ÿ���� �����Ѵ�.
	//�������� ����(�Ǵ� ����)�� ũ�Ⱑ ���� ��� �����츦 �ٽ� �׸���.
	wndClass.style = WIN_STYLE;

	//��� Ư���� ���� �����츦 ����ϰڴٰ� ����ϴ� �Լ�
	RegisterClass(&wndClass);

	_hWnd = CreateWindow(
		//lpszClassName : �����ϰ��� �ϴ� �������� Ŭ������ �����ϴ� ���ڿ�
		WIN_NAME,
		
		//lpszWindowName : �������� Ÿ��Ʋ �ٿ� ��Ÿ�� ���ڿ�
		WIN_NAME,
		
		//dwStyle : �ý��� �޴�, �ִ�/�ּ�ȭ ��ư, Ÿ��Ʋ ��, �ܰ���(��輱)�� ���� ������
		WS_OVERLAPPEDWINDOW,
		
		//x, y, nWidth, nHeight	: �������� ũ��� ��ġ�� ����
		//CW_USEDEFAULT �� �Է��ϸ� OS�� �ϾƼ� ������ ũ��� ��ġ�� �����Ѵ�.
		WINSTART_X, WINSTART_Y, WINSIZE_X, WINSIZE_Y,
		
		//hWndParent : �θ� �����찡 ���� ��� �θ� �������� �ڵ��� ����
		NULL,
		
		//hmenu = �����쿡�� ����� �޴��� �ڵ�
		(HMENU)NULL,

		//hinst : �����츦 ����� ��ü, �ַ� ���α׷� �ڵ��� ��Ī
		//WinMain�� �Ű������� ���޵� hInstance ���� �״�� ���
		hInstance,

		//pvParam : CREATSTRUCT ��� ����ü�� ����(�ּ�)�� ����Ų��. ���� NULL�� �Է�.
		NULL
	);

	setWindowSize(WINSTART_X, WINSTART_Y, WINSIZE_X, WINSIZE_Y);

	//�����츦 ȭ�鿡 ����ϱ� ���� ����� �Ѱ��ش�.
	ShowWindow(_hWnd, nCmdShow);
	
	//���� �ʱ�ȭ�� �������� ���, �״�� ���μ����� �����Ѵ�.
	_mg = new mainGame();
	if (FAILED(_mg->init()))
	{
		return 0;
	}

	//�޽��� ����ü
	MSG message;
	//GetMessage : �ý����� �����ϰ� �ִ� �޽��� ť(Queue)���� �޽����� �о���δ�.
	while (GetMessage(&message, 0, 0, 0))
	{
		//TranslateMessage
		/*
			�Է� �Ǵ� �Է� ���� �̺�Ʈ�� �߻����� ��, �Էµƴٴ� �޽����� ����.
			���� �� AŰ�� ���� �Ŀ� �ٽ� AŰ���� ���� ���� A��� ���ڰ� �Էµƴٴ� �޽����� ���ο��� �����.
		*/
		TranslateMessage(&message);
		
		//DispatchMessage : �޽����� ó�� �Լ��� WndProc�� ����
		//�ش� �޽����� ������ �Ŀ� ���� ������ ������ �� �ֵ��� �����ش�.
		DispatchMessage(&message);
	}


	return message.wParam;
}
#pragma endregion

void setWindowSize(int x, int y, int width, int height)
{
	RECT rc = { 0,0,width, height };

	AdjustWindowRect(&rc, WIN_STYLE, false);

	//������ ������ RECT ������ �������� ũ�⸦ �������Ѵ�.
	SetWindowPos(_hWnd, NULL, x, y, (rc.right - rc.left), (rc.bottom - rc.top), SWP_NOZORDER | SWP_NOMOVE);
}

//WndProc : �߻��� �޽����� OS�� �����ϰ� �������� ó���� ���ϴ� �Լ�
/*
	hWnd : ��� �����쿡�� �߻��� �޽��������� �����Ѵ�.
	iMessage : �޽��� ���� ��ȣ.
	wParam : ���콺 ��ư�� ���� �Ǵ� Ű������ �Է� ���¸� �����Ѵ�.
	lParam : ���콺 Ŭ�� Ȥ�� Ŀ���� �̵��� ���� ��ǥ�� (x, y) �������� �����Ѵ�.
*/
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	//DC(Device Context)�� ���Ͽ�
	/*
		ȭ�鿡 ����� ���� ������ ��� �ִ� ������ ����ü�̴�.
		���� ����� ����, ä��(Fill) ������ ������ ����, ��� ��� ���� �����ϰ� �ִ�.
	*/
	return _mg->MainProc(hWnd, iMessage, wParam, lParam);
}