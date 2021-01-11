// OP_lab3.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "OP_lab3.h"

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

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_OPLAB3, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_OPLAB3));

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

    return (int) msg.wParam;
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

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_OPLAB3));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_OPLAB3);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

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
void drawEars(HDC hdc, int x, int y) {
    HBRUSH e = CreateSolidBrush(RGB(227, 181, 128));
    SelectObject(hdc, e);
    POINT e0[3];
    POINT e1[3];
    INT x0 = x - 40;
    INT x1 = x + 40;

    e0[0].x = x0 - 20;
    e0[0].y = y;
    e0[1].x = x0;
    e0[1].y = y - 40;
    e0[2].x = x0 + 20;
    e0[2].y = y;
    Polygon(hdc, e0, 3);

    e1[0].x = x1 - 20;
    e1[0].y = y;
    e1[1].x = x1;
    e1[1].y = y - 40;
    e1[2].x = x1 + 20;
    e1[2].y = y;
    Polygon(hdc, e1, 3);
}
void drawEyes(HDC hdc, int x, int y) {
    HBRUSH e0 = CreateSolidBrush(RGB(9, 144, 254));
    HBRUSH e1 = CreateSolidBrush(RGB(0, 0, 0));
    SelectObject(hdc, e0);
    Ellipse(hdc, x - 30, y - 15, x - 10, y + 15);
    Ellipse(hdc, x + 10, y - 15, x + 30, y + 15);
    SelectObject(hdc, e1);
    Ellipse(hdc, x - 25, y + 10, x - 20, y - 10);
    Ellipse(hdc, x + 20, y + 10, x + 25, y - 10);
}
void drawFace1(HDC hdc, int x, int y) {
    
    HBRUSH f1 = CreateSolidBrush(RGB(216, 125, 36));
    SelectObject(hdc, f1);
    Ellipse(hdc, x - 80, y - 75, x + 80, y + 75);
    
    HBRUSH f0 = CreateSolidBrush(RGB(117, 4, 0));
    SelectObject(hdc, f0);
    Ellipse(hdc, x - 60, y - 50, x + 60, y + 50);
    drawEyes(hdc, x, y);

    drawEars(hdc, x, y - 50);

    HBRUSH f2 = CreateSolidBrush(RGB(0, 0, 0));
    SelectObject(hdc, f2);
    Ellipse(hdc, x - 10, y + 30, x + 10, y + 50);
}
void drawFace2(HDC hdc, int x, int y) {
    HBRUSH f1 = CreateSolidBrush(RGB(234, 200, 112));
    HPEN f2 = CreatePen(PS_SOLID, 5, RGB(150, 164, 175));
    SelectObject(hdc, f2);
    SelectObject(hdc, f1);
    POINT f0[12];

    f0[0].x = x - 70;
    f0[0].y = y - 10;
    f0[1].x = x - 10;
    f0[1].y = y - 10;

    f0[2].x = x - 10;
    f0[2].y = y - 70;
    f0[3].x = x + 10;
    f0[3].y = y - 70;

    f0[4].x = x + 10;
    f0[4].y = y - 10;
    f0[5].x = x + 80;
    f0[5].y = y - 10;

    f0[6].x = x + 70;
    f0[6].y = y + 10;
    f0[7].x = x + 10;
    f0[7].y = y + 10;

    f0[8].x = x + 10;
    f0[8].y = y + 120;
    f0[9].x = x - 10;
    f0[9].y = y + 120;

    f0[10].x = x - 10;
    f0[10].y = y + 10;
    f0[11].x = x - 80;
    f0[11].y = y + 10;

    Polygon(hdc, f0, 12);
}

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
            RECT crect;
            GetClientRect(hWnd, &crect);
            int x1 = (crect.right - crect.left) / 4;
            int y = (crect.bottom - crect.top) / 2;
            int x2 = x1 * 3;
            drawFace1(hdc, x1, y);
            drawFace2(hdc, x2, y);
            EndPaint(hWnd, &ps);
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
