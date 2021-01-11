// WindowsProject1.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "OP_lab4.h"

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);




void light(HDC hdc, int x, int y, int r) {
	HPEN hPen;
	hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	SelectObject(hdc, hPen);
	POINT l[6];
	//l[0].x = x - 15 * r;
	//l[0].y = y + 20 * r;
	//l[1].x = x;
	//l[1].y = y + 10 * r;
	//l[2].x = x - 10 * r;
	//l[2].y = y - 16 * r;
	//l[3].x = x + 15 * r;
	//l[3].y = y - 20 * r;
	//l[4].x = x;
	//l[4].y = y - 10 * r;
	//l[5].x = x + 10 * r;
	//l[5].y = y + 16 * r;
	l[0].x = x - 15 -r ;
	l[0].y = y + 20 +r;
	l[1].x = x;
	l[1].y = y + 10 +r;
	l[2].x = x - 10 - r;
	l[2].y = y - 16 - r;
	l[3].x = x + 15 + r;
	l[3].y = y - 20 - r;
	l[4].x = x;
	l[4].y = y - 10 - r;
	l[5].x = x + 10 + r;
	l[5].y = y + 16 + r;
	Polygon(hdc, l, 6);
	if (r > 10) {
		light(hdc, x - r, y - r, r / 2);
		light(hdc, x + r, y - r, r / 2);
		light(hdc, x - r, y + r, r / 2);
		light(hdc, x + r, y + r, r / 2);
	}

}
void rect(HDC hdc, int x, int y, int r) {
	HPEN hPen;
	hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	SelectObject(hdc, hPen);

	Rectangle(hdc, x, y, x + r, y + r);
	

	if (r > 10)
	{
		rect(hdc, x - r / 2, y - r /2, r / 2);
		rect(hdc, x - r / 2, y + r / 2, r / 2);
		rect(hdc, x + r / 2, y - r / 2, r / 2);
		rect(hdc, x + r / 2, y + r / 2, r / 2);
	}
}
void circle(HDC hdc, int x, int y, int r) {
	HPEN hPen;
	hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	SelectObject(hdc, hPen);

	Ellipse(hdc, x - r, y - r, x + r, y + r);

	MoveToEx(hdc, x - r*2, y, 0);
	LineTo(hdc, x - r, y);

	MoveToEx(hdc, x, y - r*2, 0);
	LineTo(hdc, x, y - r);

	MoveToEx(hdc, x + r, y, 0);
	LineTo(hdc, x + r * 2, y);

	MoveToEx(hdc, x, y + r, 0);
	LineTo(hdc, x, y + r * 2);

	if (r > 10)
	{
		circle(hdc, x + r, y, r / 2);
		circle(hdc, x - r, y, r / 2);
		circle(hdc, x, y + r, r / 2);
		circle(hdc, x, y - r, r / 2);
	}
}


void blu1(HDC hdc, int x, int y, int rad);
void red1(HDC hdc, int x, int y, int rad) {
	HPEN redpen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	SelectObject(hdc, redpen);

	MoveToEx(hdc, x, y, 0);
	LineTo(hdc, x, y - rad);

	MoveToEx(hdc, x, y, 0);
	LineTo(hdc, x + rad / 2, y + rad / 2);

	MoveToEx(hdc, x, y, 0);
	LineTo(hdc, x - rad / 2, y + rad / 2);
	if (rad > 10)
	{
		blu1(hdc, x, y - rad, rad / 2);
		blu1(hdc, x - rad / 2, y + rad / 2, rad / 2);
		blu1(hdc, x + rad / 2, y + rad / 2, rad / 2);
	}


}
void blu1(HDC hdc, int x, int y, int rad) {
	HPEN blupen = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
	SelectObject(hdc, blupen);

	MoveToEx(hdc, x, y, 0);
	LineTo(hdc, x - rad / 2, y - rad / 2);

	MoveToEx(hdc, x, y, 0);
	LineTo(hdc, x + rad / 2, y - rad / 2);

	MoveToEx(hdc, x, y, 0);
	LineTo(hdc, x + rad / 2, y + rad / 2);

	MoveToEx(hdc, x, y, 0);
	LineTo(hdc, x - rad / 2, y + rad / 2);
	if (rad > 10)
	{
		red1(hdc, x - rad / 2, y - rad / 2, rad / 2);
		red1(hdc, x + rad / 2, y - rad / 2, rad / 2);
		red1(hdc, x + rad / 2, y + rad / 2, rad / 2);
		red1(hdc, x - rad / 2, y + rad / 2, rad / 2);
	}

}
void blu2(HDC hdc, int x, int y, int rad);
void red2(HDC hdc, int x, int y, int rad) {
	HPEN redpen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	SelectObject(hdc, redpen);

	MoveToEx(hdc, x - rad, y - rad, 0);
	LineTo(hdc, x + rad, y - rad);
	LineTo(hdc, x + rad / 2, y);
	LineTo(hdc, x + rad, y + rad);
	LineTo(hdc, x - rad, y + rad);
	LineTo(hdc, x - rad / 2, y);
	LineTo(hdc, x - rad, y - rad);

	if (rad > 10)
	{
		blu2(hdc, x - rad, y - rad, rad / 2);
		blu2(hdc, x + rad, y - rad, rad / 2);
		blu2(hdc, x + rad, y + rad, rad / 2);
		blu2(hdc, x - rad, y + rad, rad / 2);
	}

}
void blu2(HDC hdc, int x, int y, int rad) {
	HPEN blupen = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
	SelectObject(hdc, blupen);

	MoveToEx(hdc, x - rad, y - rad, 0);
	LineTo(hdc, x, y - rad / 2);
	LineTo(hdc, x + rad, y - rad);
	LineTo(hdc, x + rad, y + rad);
	LineTo(hdc, x, y + rad / 2);
	LineTo(hdc, x - rad, y + rad);
	LineTo(hdc, x - rad, y - rad);

	if (rad > 10)
	{
		red2(hdc, x - rad, y - rad, rad / 2);
		red2(hdc, x + rad, y - rad, rad / 2);
		red2(hdc, x + rad, y + rad, rad / 2);
		red2(hdc, x - rad, y + rad, rad / 2);
	}
}
void blu3(HDC hdc, int x, int y, int rad);
void red3(HDC hdc, int x, int y, int rad) {
	HPEN redpen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	SelectObject(hdc, redpen);

	MoveToEx(hdc, x - rad, y, 0);
	LineTo(hdc, x - rad / 2, y);
	LineTo(hdc, x, y - rad / 2);
	LineTo(hdc, x + rad / 2, y);
	LineTo(hdc, x, y + rad / 2);
	LineTo(hdc, x - rad / 2, y);
	MoveToEx(hdc, x, y - rad / 2, 0);
	LineTo(hdc, x, y - rad);
	MoveToEx(hdc, x + rad / 2, y, 0);
	LineTo(hdc, x + rad, y);
	MoveToEx(hdc, x, y + rad / 2, 0);
	LineTo(hdc, x, y + rad);

	if (rad > 10)
	{
		blu3(hdc, x - rad, y, rad / 2);
		blu3(hdc, x, y - rad, rad / 2);
		blu3(hdc, x + rad, y, rad / 2);
		blu3(hdc, x, y + rad, rad / 2);
	}
}
void blu3(HDC hdc, int x, int y, int rad) {
	HPEN blupen = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
	SelectObject(hdc, blupen);

	MoveToEx(hdc, x - rad, y, 0);
	LineTo(hdc, x - rad / 4, y - rad / 4);
	LineTo(hdc, x, y - rad);
	LineTo(hdc, x + rad / 4, y - rad / 4);
	LineTo(hdc, x + rad, y);
	LineTo(hdc, x + rad / 4, y + rad / 4);
	LineTo(hdc, x, y + rad);
	LineTo(hdc, x - rad / 4, y + rad / 4);
	LineTo(hdc, x - rad, y);

	if (rad > 10)
	{
		red3(hdc, x - rad, y, rad / 2);
		red3(hdc, x, y - rad, rad / 2);
		red3(hdc, x + rad, y, rad / 2);
		red3(hdc, x, y + rad, rad / 2);

	}
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: Разместите код здесь.

	// Инициализация глобальных строк
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_OPLAB4, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Выполнить инициализацию приложения:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_OPLAB4));

	MSG msg;

	// Цикл основного сообщения:
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
}



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDC_OPLAB4));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_OPLAB4);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDC_OPLAB4));

	return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

	HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		// Разобрать выбор в меню:
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
	}
	break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		HBRUSH hBrush = static_cast<HBRUSH>(GetStockObject(HOLLOW_BRUSH));
		HGDIOBJ hOldBush = SelectObject(hdc, hBrush);
		RECT crect;
		GetClientRect(hWnd, &crect);
		int x1 = (crect.right - crect.left) / 4;
		int y = (crect.bottom - crect.top) / 2;
		int x2 = x1 * 2;
		int x3 = x1 * 3;

		
		rect(hdc, x1, y, 80); //первая часть
		light(hdc, x2, y, 80);
		circle(hdc, x3, y, 80);//
		//rocket(hdc, 900, 300, 100);//

		/*red1(hdc, 500, 400, 50);//
		red2(hdc, 500, 400, 50);// вторая часть
		red3(hdc, 500, 400, 50);//
		EndPaint(hWnd, &ps);*/
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return static_cast<INT_PTR>(TRUE);

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return static_cast<INT_PTR>(TRUE);
		}
		break;
	}
	return static_cast<INT_PTR>(FALSE);
}