#include "MainHeader.h"

void draw()
{
    //ngang
    for (int i = 0; i < 36; i++)
    {
        GotoXY(LEFT + 1 + i, TOP);
        cout << (char)196;
        GotoXY(LEFT + 1 + i, BOT);
        cout << (char)196;
    }
    for (int j = TOP + 1; j < 12; j += 4)
    {
        for (int i = 0; i < 36; i++)
        {
            GotoXY(LEFT + 1 + i, TOP+1 + j);
            cout << (char)196;
        }
    }

    //dọc
    for (int i = 0; i < 15; i++)
    {
        GotoXY(LEFT, TOP+1 + i);
        cout << (char)179;
        GotoXY(RIGHT, TOP + 1 + i);
        cout << (char)179;
    }
    for (int j = LEFT; j < 30; j += 9)
    {
        for (int i = 0; i < 15; i++)
        {
            GotoXY(LEFT + j, TOP + 1 + i);
            cout << (char)179;
        }
    }
    GotoXY(LEFT, TOP);
    cout << (char)218;
    GotoXY(LEFT, BOT);
    cout << (char)192;
    GotoXY(RIGHT, TOP);
    cout << (char)191;
    GotoXY(RIGHT, BOT);
    cout << (char)217;
    for (int j = LEFT; j < 30; j += 9)
    {
        for (int i = TOP + 1; i < 15; i += 4)
        {
            GotoXY(LEFT + j, TOP + 1 + i);
            cout << (char)197;
        }
    }
    for (int j = LEFT; j < 30; j += 9)
    {
        GotoXY(LEFT + j, TOP);
        cout << (char)194;
        GotoXY(LEFT + j, BOT);
        cout << (char)193;
    }
    for (int i = TOP + 1; i < 15; i += 4)
    {
        GotoXY(LEFT, TOP + 1 + i);
        cout << (char)195;
        GotoXY(RIGHT, TOP + 1 + i);
        cout << (char)180;
    }
}
void GotoXY(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void DisableSelection()
{
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);

    SetConsoleMode(hStdin, ~ENABLE_QUICK_EDIT_MODE);
}

void DisableResizeWindow()
{
    HWND hWnd = GetConsoleWindow();
    SetWindowLong(hWnd, GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE) & ~WS_SIZEBOX);
}
void ShowScrollbar(BOOL Show)
{
    HWND hWnd = GetConsoleWindow();
    ShowScrollBar(hWnd, SB_BOTH, Show);
}
void FixConsoleWindow() {
    HWND consoleWindow = GetConsoleWindow();
    LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
    style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
    SetWindowLong(consoleWindow, GWL_STYLE, style);
}
void Nocursortype()
{
    CONSOLE_CURSOR_INFO Info;
    Info.bVisible = FALSE;
    Info.dwSize = 20;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}