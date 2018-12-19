// winLearn2_d2d1.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "winLearn2_d2d1.h"

#define MAX_LOADSTRING 100

// 全局变量: 
HINSTANCE hInst;								// 当前实例
TCHAR szTitle[MAX_LOADSTRING];					// 标题栏文本
TCHAR szWindowClass[MAX_LOADSTRING];			// 主窗口类名

// 此代码模块中包含的函数的前向声明: 
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

 	// TODO:  在此放置代码。

	


	MSG msg;
	HACCEL hAccelTable;

	// 初始化全局字符串
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_WINLEARN2_D2D1, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// 执行应用程序初始化: 
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINLEARN2_D2D1));

	// 主消息循环: 
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
//  函数:  MyRegisterClass()
//
//  目的:  注册窗口类。
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
//   函数:  InitInstance(HINSTANCE, int)
//
//   目的:  保存实例句柄并创建主窗口
//
//   注释: 
//
//        在此函数中，我们在全局变量中保存实例句柄并
//        创建和显示主程序窗口。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // 将实例句柄存储在全局变量中

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
//  函数:  WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目的:    处理主窗口的消息。
//
//  WM_COMMAND	- 处理应用程序菜单
//  WM_PAINT	- 绘制主窗口
//  WM_DESTROY	- 发送退出消息并返回
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	


	//自定义代码_用D2D1画矩形 开始-----------------------------------------------------------2018年12月19日00:39:27

	//第二步
	ID2D1Factory* pD2DFactory = NULL;
	HRESULT hr = D2D1CreateFactory(
		D2D1_FACTORY_TYPE_SINGLE_THREADED,
		&pD2DFactory
		);

	//第三步
	// Obtain the size of the drawing area.
	RECT rc;//关于[“rc”]的描述-: :概念_inThisXSet_-:“屏幕画图区域”	--2018年12月19日11:17:28
	GetClientRect(hWnd, &rc);

	// Create a Direct2D render target          
	ID2D1HwndRenderTarget* pRT = NULL;//关于[“pRT”]的描述-: :概念_inThisXSet_-:“指向渲染目标的指针”	--2018年12月19日11:17:31
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

	//第4步：创建画笔
	ID2D1SolidColorBrush* pBlackBrush = NULL;//关于[“pBlackBrush”]的描述-: :概念_inThisXSet_-:“一个叫"pBlackBrush"的画笔”	--2018年12月19日11:17:28
	if (SUCCEEDED(hr))
	{

		pRT->CreateSolidColorBrush(
			D2D1::ColorF(D2D1::ColorF::Blue),
			&pBlackBrush
			);
	}

	ID2D1SolidColorBrush* pRedBrush = NULL;//关于[“pRedBrush”]的描述-: :概念_inThisXSet_-:“一个叫"pRedBrush"的画笔”	--2018年12月19日11:17:28
	if (SUCCEEDED(hr))
	{

		pRT->CreateSolidColorBrush(
			D2D1::ColorF(D2D1::ColorF::Red),
			&pRedBrush
			);
	}

	ID2D1SolidColorBrush* pOrangeBrush = NULL;//关于[“pOrangeBrush”]的描述-: :概念_inThisXSet_-:“一个叫"pOrangeBrush"的画笔”	--2018年12月19日11:17:28
	if (SUCCEEDED(hr))
	{

		pRT->CreateSolidColorBrush(
			D2D1::ColorF(D2D1::ColorF::Orange),
			&pOrangeBrush
			);
	}

	//第5步：绘制矩形
	pRT->BeginDraw();

	pRT->DrawRectangle(//关于[“ pRT->DrawRectangle 执行过程”]的描述-: :概念_inThisXSet_-:“在概念“pRT”上用一个叫"pBlackBrush"的画笔画“如下的样子”（rc.left+100.0f,rc.top+10.0f......）”	--2018年12月19日11:28:18
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

	//第6步：释放资源
	pRT->Release();
	pBlackBrush->Release();
	pRedBrush->Release();
	pOrangeBrush->Release();

	pD2DFactory->Release();

	//自定义代码_用D2D1画矩形 结束-----------------------------------------------------------2018年12月19日00:39:27

	switch (message)
	{
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// 分析菜单选择: 
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
		// TODO:  在此添加任意绘图代码...

		
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

// “关于”框的消息处理程序。
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
