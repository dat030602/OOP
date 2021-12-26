#include "MainHeader.h"
#include "Player.h"
#include "Linh.h"
#include "CungThu.h"
#include "LinhKhien.h"
#include "QuaiVat.h"
#include "Game.h"

#include <conio.h>

char MOVING;
Game g;
int main()
{
    DisableSelection();
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, 800, 420, TRUE);
    FixConsoleWindow();
    DisableResizeWindow();
    Nocursortype();
    ShowScrollbar(0);
    draw();
    g.resetGame();
    g.Draw();
    while (1)
    {
        if (g.IsNextLevel())
        {
            system("cls");
            draw();
            g.resetGame();
        }
        MOVING = toupper(_getch());
        g.move(MOVING);
        g.Draw();
        g.IsImpact();
        if (g.IsDead())
        {
            GotoXY(50, 5);
            cout << "THUA";
            return 0;
        }
        if (g.IsNextLevel() && g.curLev() == 4)
        {
            GotoXY(50, 5);
            cout << "WIN";
            return 0;
        }
    }
}