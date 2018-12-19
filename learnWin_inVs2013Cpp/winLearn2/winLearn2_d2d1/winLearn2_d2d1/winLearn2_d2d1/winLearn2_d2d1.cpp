// winLearn2_d2d1.cpp : ����Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "winLearn2_d2d1.h"

#define MAX_LOADSTRING 100

// ȫ�ֱ���: 
HINSTANCE hInst;								// ��ǰʵ��
TCHAR szTitle[MAX_LOADSTRING];					// �������ı�
TCHAR szWindowClass[MAX_LOADSTRING];			// ����������

// �˴���ģ���а����ĺ�����ǰ������: 
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO:  �ڴ˷��ô��롣

	


	MSG msg;
	HACCEL hAccelTable;

	// ��ʼ��ȫ���ַ���
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_WINLEARN2_D2D1, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// ִ��Ӧ�ó����ʼ��: 
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINLEARN2_D2D1));

	// ����Ϣѭ��: 
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}



//
//  ����:  MyRegisterClass()
//
//  Ŀ��:  ע�ᴰ���ࡣ
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINLEARN2_D2D1));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_WINLEARN2_D2D1);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   ����:  InitInstance(HINSTANCE, int)
//
//   Ŀ��:  ����ʵ�����������������
//
//   ע��: 
//
//        �ڴ˺����У�������ȫ�ֱ����б���ʵ�������
//        ��������ʾ�����򴰿ڡ�
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // ��ʵ������洢��ȫ�ֱ�����

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  ����:  WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  Ŀ��:    ���������ڵ���Ϣ��
//
//  WM_COMMAND	- ����Ӧ�ó���˵�
//  WM_PAINT	- ����������
//  WM_DESTROY	- �����˳���Ϣ������
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	


	//�Զ������_��D2D1������ ��ʼ-----------------------------------------------------------2018��12��19��00:39:27

	//�ڶ���
	ID2D1Factory* pD2DFactory = NULL;
	HRESULT hr = D2D1CreateFactory(
		D2D1_FACTORY_TYPE_SINGLE_THREADED,
		&pD2DFactory
		);

	//������
	// Obtain the size of the drawing area.
	RECT rc;//����[��rc��]������-: :����_inThisXSet_-:����Ļ��ͼ����	--2018��12��19��11:17:28
	GetClientRect(hWnd, &rc);

	// Create a Direct2D render target          
	ID2D1HwndRenderTarget* pRT = NULL;//����[��pRT��]������-: :����_inThisXSet_-:��ָ����ȾĿ���ָ�롱	--2018��12��19��11:17:31
	hr = pD2DFactory->CreateHwndRenderTarget(
		D2D1::RenderTargetProperties(),
		D2D1::HwndRenderTargetProperties(
		hWnd,
		D2D1::SizeU(
		rc.right - rc.left,
		rc.bottom - rc.top)
		),
		&pRT
		);

	//��4������������
	ID2D1SolidColorBrush* pBlackBrush = NULL;//����[��pBlackBrush��]������-: :����_inThisXSet_-:��һ����"pBlackBrush"�Ļ��ʡ�	--2018��12��19��11:17:28
	if (SUCCEEDED(hr))
	{

		pRT->CreateSolidColorBrush(
			D2D1::ColorF(D2D1::ColorF::Blue),
			&pBlackBrush
			);
	}

	ID2D1SolidColorBrush* pRedBrush = NULL;//����[��pRedBrush��]������-: :����_inThisXSet_-:��һ����"pRedBrush"�Ļ��ʡ�	--2018��12��19��11:17:28
	if (SUCCEEDED(hr))
	{

		pRT->CreateSolidColorBrush(
			D2D1::ColorF(D2D1::ColorF::Red),
			&pRedBrush
			);
	}

	ID2D1SolidColorBrush* pOrangeBrush = NULL;//����[��pOrangeBrush��]������-: :����_inThisXSet_-:��һ����"pOrangeBrush"�Ļ��ʡ�	--2018��12��19��11:17:28
	if (SUCCEEDED(hr))
	{

		pRT->CreateSolidColorBrush(
			D2D1::ColorF(D2D1::ColorF::Orange),
			&pOrangeBrush
			);
	}

	//��5�������ƾ���
	pRT->BeginDraw();

	pRT->DrawRectangle(//����[�� pRT->DrawRectangle ִ�й��̡�]������-: :����_inThisXSet_-:���ڸ��pRT������һ����"pBlackBrush"�Ļ��ʻ������µ����ӡ���rc.left+100.0f,rc.top+10.0f......����	--2018��12��19��11:28:18
		D2D1::RectF(
		rc.left + 100.0f,
		rc.top + 10.0f,
		rc.right - 50.0f,
		rc.bottom - 50.0f),
		pBlackBrush);

	pRT->DrawRectangle(
		D2D1::RectF(
		rc.left + 200.0f,
		rc.top + 200.0f,
		rc.right - 200.0f,
		rc.bottom - 200.0f),
		pRedBrush);

	pRT->DrawRectangle(
		D2D1::RectF(
		rc.left + 10.0f,
		rc.top + 20.0f,
		rc.right - 40.0f,
		rc.bottom - 400.0f),
		pOrangeBrush);

	hr = pRT->EndDraw();

	//��6�����ͷ���Դ
	pRT->Release();
	pBlackBrush->Release();
	pRedBrush->Release();
	pOrangeBrush->Release();

	pD2DFactory->Release();

	//�Զ������_��D2D1������ ����-----------------------------------------------------------2018��12��19��00:39:27

	switch (message)
	{
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// �����˵�ѡ��: 
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO:  �ڴ���������ͼ����...

		
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// �����ڡ������Ϣ�������
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
