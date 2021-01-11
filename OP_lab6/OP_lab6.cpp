#include "framework.h"
#include "OP_lab6.h"
#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>

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



// Параметры утки
int planeCx = 300;
int planeCy = 200;
// Параметры прицела
int aimX = 100;
int aimY = 100;
// Счетчики выстрелов
int ammo = 10;
int planes = 0;


int windowWidth;
int windowHeight;


void DrawAim(HDC hdc, int x, int y) {
    HPEN hPen = CreatePen(PS_SOLID, 1, RGB(128, 0, 0));
    SelectObject(hdc, hPen);
    HBRUSH hBrush = CreateSolidBrush(RGB(255, 255, 255));
    SelectObject(hdc, hBrush);
    Ellipse(hdc, x - 20, y - 20, x + 20, y + 20);
    MoveToEx(hdc, x - 20, y, NULL);
    LineTo(hdc, x + 20, y);
    MoveToEx(hdc, x, y - 20, NULL);
    LineTo(hdc, x, y + 20);
}

void DrawPlane(HDC hdc, int x, int y) {
    HBRUSH b = CreateSolidBrush(RGB(255, 130, 60));
    SelectObject(hdc, b);
    POINT p[15];

    p[0].x = x - 10;
    p[0].y = y + 70;
    p[1].x = x - 15;
    p[1].y = y + 10;

    p[2].x = x - 65;
    p[2].y = y + 10;
    p[3].x = x - 75;
    p[3].y = y;

    p[4].x = x - 75;
    p[4].y = y - 25;
    p[5].x = x - 65;
    p[5].y = y - 25;

    p[6].x = x - 50;
    p[6].y = y - 5;
    p[7].x = x - 15;
    p[7].y = y - 5;

    p[8].x = x - 10;
    p[8].y = y - 70;
    p[9].x = x;
    p[9].y = y - 70;

    p[10].x = x + 15;
    p[10].y = y - 5;
    p[11].x = x + 75;
    p[11].y = y - 5;

    p[12].x = x + 85;
    p[12].y = y + 10;
    p[13].x = x + 15;
    p[13].y = y + 10;

    p[14].x = x;
    p[14].y = y + 70;

    Polygon(hdc, p, 15);

}

void Moveplane()// добавили в 6
{
    if (planeCx < windowWidth)
    {
        planeCx += 5;
    }
    else
    {
        planeCx = rand() % 50;
    }
    if (planeCy < windowHeight)
    {
        planeCy += 5;
    }
    else
    {
        planeCy = rand() % 50;
    }
}


void moveDown() {
    aimY += 10;
}
void moveToLeft() {
    aimX -= 10;
}
void moveUp() {
    aimY -= 10;
}
void moveToRight() {
    aimX += 10;
}

bool getShotResult() {
    if (aimX < planeCx)
        return 0;
    if (aimX > planeCx + 60)
        return 0;
    if (aimY < planeCy)
        return 0;
    if (aimY > planeCy + 25)
        return 0;
    return 1;
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
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_OPLAB6, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_OPLAB6));

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
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDC_OPLAB6));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_OPLAB6);
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

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
    case WM_CREATE:// добавили в 6
        SetTimer(hWnd, 1, 100, 0);
        break;
    case WM_TIMER:// добавили в 6
        RECT rect;
        GetClientRect(hWnd, &rect);
        windowWidth = rect.right;
        windowHeight = rect.bottom;

        Moveplane();// добавили в 6
        InvalidateRect(hWnd, NULL, TRUE);
        break;

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
    case WM_KEYDOWN:
        if (ammo > 0)
        {

            switch (wParam)
            {
            case VK_DOWN:
                moveDown();
                InvalidateRect(hWnd, NULL, TRUE);
                break;
            case VK_LEFT:
                moveToLeft();
                InvalidateRect(hWnd, NULL, TRUE);
                break;
            case VK_UP:
                moveUp();
                InvalidateRect(hWnd, NULL, TRUE);
                break;
            case VK_RIGHT:
                moveToRight();
                InvalidateRect(hWnd, NULL, TRUE);
                break;
            case VK_RETURN:
                ammo--;

                if (getShotResult())
                {
                    planes++;
                    planeCx = rand() % 500;
                    planeCy = rand() % 500;
                }
                InvalidateRect(hWnd, NULL, TRUE);
                break;
            }
        }

        break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

        HFONT hFont = CreateFont(20,
            0, 0, 0, 0, 0, 0, 0,
            DEFAULT_CHARSET,
            0, 0, 0, 0,
            L"Courier New"
        );
        SelectObject(hdc, hFont);
        SetTextColor(hdc, RGB(0, 0, 128));
        TCHAR string1[] = _T("Патронов:");
        TextOut(hdc, 10, 10, string1, _tcslen(string1));
        TextOut(hdc, 570, 10, L"Летающих металлических птиц: ", 50);

        char sAmmo[5]; // локальная переменная
        TCHAR tsAmmo[5];
        sprintf_s(sAmmo, 5, "%d", ammo); // использование глобальной переменной
        OemToChar(sAmmo, tsAmmo);
        TextOut(hdc, 100, 10, tsAmmo, _tcslen(tsAmmo));
        char splanes[5];
        TCHAR tsplanes[5];
        sprintf_s(splanes, 5, "%d", planes);
        OemToChar(splanes, tsplanes);
        TextOutW(hdc, 850, 10, tsplanes, _tcslen(tsplanes));




        if (ammo > 0)
        {
            DrawPlane(hdc, planeCx, planeCy);
        }
        DrawAim(hdc, aimX, aimY);

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