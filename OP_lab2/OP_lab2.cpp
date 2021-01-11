// OP_lab2.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "OP_lab2.h"
#include <string>
#include <iostream>
#include <sstream>
#include <math.h>

using namespace std;

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
    LoadStringW(hInstance, IDC_OPLAB2, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_OPLAB2));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_OPLAB2));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_OPLAB2);
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
            HDC hdc;
            hdc = BeginPaint(hWnd, &ps);
            HBRUSH hBrush; //создаём кисть
            hBrush = CreateSolidBrush(RGB(0, 0, 0));
            SelectObject(hdc, hBrush);
            RECT crect;
            GetClientRect(hWnd, &crect);
            int cx = (crect.right - crect.left) / 4;
            int cy = (crect.bottom - crect.top) / 2;
            int l1 = 100;
            int l2 = 80;
            int l3 = 60;
            int l4 = 40;
            FillRect(hdc, &crect, hBrush);
            HPEN pen;
            pen = CreatePen(PS_SOLID, 2, RGB(200, 50, 50)); //Задаем перо толщиной 2 пикселя
            HBRUSH rbrush;
            rbrush = CreateSolidBrush(RGB(255, 0, 0));
            HBRUSH bbrush;
            bbrush = CreateSolidBrush(RGB(0, 0, 255));
            HBRUSH bbrush2;
            bbrush2 = CreateSolidBrush(RGB(0, 0, 0));
            HBRUSH wbrush;
            wbrush = CreateSolidBrush(RGB(255, 255, 255));
            HPEN bpen;
            bpen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
            HPEN bpen2;
            bpen2 = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
            HPEN wpen;
            wpen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
            

            SelectObject(hdc, rbrush);
            Ellipse(hdc, cx - l1, cy - l1, cx + l1, cy + l1);
            SelectObject(hdc, wbrush);
            Ellipse(hdc, cx - l2, cy - l2, cx + l2, cy + l2);
            SelectObject(hdc, rbrush);
            Ellipse(hdc, cx - l3, cy - l3, cx + l3, cy + l3);
            SelectObject(hdc, bbrush);
            Ellipse(hdc, cx - l4, cy - l4, cx + l4, cy + l4);

            pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
            SelectObject(hdc, wbrush);
            int starsize = 40;
            float M_PI = 3.14;

            int R = 40;
            int r = 20;
            int rad = 40;
            int n = 5;
            int a = 0;
            float k, k1;
            POINT poly[10];
            for (size_t i = 0; i < 9; i+=2)
            {
                if (!(i % 2)) {
                    k1 = (i + n / 2 - 1) % n;
                    //poly[i].x = cx + r / 2 * cos(a * M_PI / 180);
                    //poly[i].y = cy - r * sin(a * M_PI / 180);
                }
                else {
                    k1 = (i + (n - 1) / 2) % n;
                    //poly[i].x = cx + R * cos(a * M_PI / 180);
                    //poly[i].y = cy - R * sin(a * M_PI / 180);
                }
                poly[i].x = (cx + r * cos(2 * 3.14 * i / n));
                poly[i].y = (cy + r * sin(2 * 3.14 * i / n));
                poly[i + 1].x = (cx + R * cos(2 * 3.14 * k1 / n));
                poly[i + 1].y = (cy + R * sin(2 * 3.14 * k1 / n));
            }
            int f = 22;
            Ellipse(hdc, cx - f, cy - f, cx + f, cy + f);
            
                    
            stringstream ss;
            for (size_t i = 0; i < 10; i++)
            {
                ss << poly[i].x << "; " << poly[i].y << endl;
            }
                
            OutputDebugStringA(ss.str().c_str());
                
            Polygon(hdc, poly, 10);

            cx = cx * 3;
            l1 = 150;
            l2 = 100;
            l3 = 140;
            l4 = 90;
            SelectObject(hdc, wpen);
            Ellipse(hdc, cx - l1, cy - l2, cx + l1, cy + l2);
            SelectObject(hdc, bbrush2);
            Ellipse(hdc, cx - l3, cy - l4, cx + l3, cy + l4);
            SelectObject(hdc, bpen2);
            POINT poly2[4];
            poly2[0].x = cx - 30;
            poly2[0].y = cy - l2;
            poly2[1].x = cx - 45;
            poly2[1].y = cy - (l2 - 30);

            poly2[3].x = cx + 30;
            poly2[3].y = cy - l2;
            poly2[2].x = cx + 45;
            poly2[2].y = cy - (l2 - 30);

            Polygon(hdc, poly2, 4);
            SelectObject(hdc, bbrush2);
            SelectObject(hdc, bpen2);
            poly2[0].x = cx + 30;
            poly2[0].y = cy + (l2 - 30);
            poly2[1].x = cx + 40;
            poly2[1].y = cy + (l2 - 30);

            poly2[3].x = cx + 40;
            poly2[3].y = cy + l2 + 30;
            poly2[2].x = cx + 50;
            poly2[2].y = cy + l2 + 30;
            //Sleep(10000);
            Polygon(hdc, poly2, 4);
            SelectObject(hdc, wbrush);
            SelectObject(hdc, wpen);
            POINT poly3[7];
            poly3[0].x = cx - 60;
            poly3[0].y = cy + l2 + 30;
            poly3[1].x = cx - 10;
            poly3[1].y = cy - l2;
            poly3[2].x = cx + 10;
            poly3[2].y = cy - l2;
            poly3[3].x = cx + 60;
            poly3[3].y = cy + l2 + 30;
            poly3[4].x = cx + 50;
            poly3[4].y = cy + l2 + 30;
            poly3[5].x = cx;
            poly3[5].y = cy - l2 + 10;
            poly3[6].x = cx - 50;
            poly3[6].y = cy + l2 + 30;
            Polygon(hdc, poly3, 7);

            HFONT hFont = CreateFont(50, 0, 0, 0, FW_BOLD, false, false, false, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, FF_DONTCARE, L"Avenir 95 Black");
            SetTextColor(hdc, RGB(255, 0, 0));
            SetBkMode(hdc, TRANSPARENT);
            SelectObject(hdc, hFont);
            TextOut(hdc, cx - 70, cy + l2 + 35, L"CHERY", 6);

            EndPaint(hWnd, &ps);
            break;
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
