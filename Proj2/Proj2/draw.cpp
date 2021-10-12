#include "MainHeader.h"
void drawConsole(int x, int y)
{
    int y1 = y;
    for (int i = 0; i < 10; i++)
    {
        GotoXY(x, y1);
        y1 += 4;
        for (int i = 0; i < 110; i++)
            cout << (char)205;
    }
    y1 = y;
    for (int i = 0; i < 37; i++)
    {
        if (y1 == y)
        {
            GotoXY(x, y1);
            cout << (char)201;
            GotoXY(x + 110, y1++);
            cout << (char)187;
        }
        else if (y1 == y + 36)
        {
            GotoXY(x, y1);
            cout << (char)200;
            GotoXY(x + 110, y1++);
            cout << (char)188;
        }
        else if ((y1 + 2) % 4 == 0)
        {
            GotoXY(x, y1);
            cout << (char)204;
            GotoXY(x + 110, y1++);
            cout << (char)185;
        }
        else
        {
            GotoXY(x, y1);
            cout << (char)186;
            GotoXY(x + 110, y1++);
            cout << (char)186;
        }
    }
}
void drawMenu(int x, int y)
{
    int y2[] = { 0,12,18,22,38 };
    //ngang
    int y1 = y;
    GotoXY(x + 1, y1);
    for (int i = 0; i < 5; i++)
    {
        GotoXY(x + 1, y1 + y2[i]);
        for (int j = 0; j < 34; j++)
            cout << (char)205;
    }

    //doc
    GotoXY(x, y1);
    cout << (char)201;
    GotoXY(x + 34, y1);
    cout << (char)187;
    GotoXY(x, y1 + y2[1]);
    cout << (char)204;
    GotoXY(x + 34, y1 + y2[1]);
    cout << (char)185;
    GotoXY(x, y1 + y2[2]);
    cout << (char)204;
    GotoXY(x + 34, y1 + y2[2]);
    cout << (char)185;
    GotoXY(x, y1 + y2[3]);
    cout << (char)204;
    GotoXY(x + 34, y1 + y2[3]);
    cout << (char)185;
    GotoXY(x, y1 + y2[4]);
    cout << (char)200;
    GotoXY(x + 34, y1 + y2[4]);
    cout << (char)188;
    for (int i = y1; i <= y + 36; i++)
    {
        if (i + 1 != y1 && i + 1 != y1 + y2[1] && i + 1 != y1 + y2[2] && i + 1 != y1 + y2[3] && i + 1 != y1 + y2[4])
        {
            GotoXY(x, i + 1);
            cout << (char)186;
            GotoXY(x + 34, i + 1);
            cout << (char)186;
        }
    }
    for (int i = y + y2[2] + 1; i < y + y2[3]; i++)
    {
        GotoXY(x + 13, i);
        cout << (char)186;
    }
    GotoXY(x + 13, y + y2[2]);
    cout << (char)203;
    GotoXY(x + 13, y + y2[3]);
    cout << (char)202;
}

void drawEnemy(int x, int y, const char drawEnemy[][12], int w, int h)
{
    int x1 = x, y1 = y;
    
    for (int j = 0; j < w; j++)
    {
        for (int k = 0; k < h; k++)
        {
            GotoXY(x1 + k, y1);
            cout << drawEnemy[j][k];
        }
        y1++;
    }
}
void clearPath(int x, int y, int w, int h, char temp)
{
    int x1 = x, y1 = y;
    if (temp == 'A' || temp == 75)
    {
        for (int i = 0; i < w; i++)
        {
            GotoXY(x + h, y + i);
            cout << " ";
        }
    }
    else if (temp == 'W' || temp == 72)
    {
        for (int i = 0; i < h; i++)
        {
            GotoXY(x + i, y + 3);
            cout << " ";
        }
    }
    else if (temp == 'S' || temp == 80)
    {
        for (int i = 0; i < h; i++)
        {
            GotoXY(x + i, y - 1);
            cout << " ";
        }
    }
    else if (temp == 'D' || temp == 77)
    {
        for (int i = 0; i < w; i++)
        {
            GotoXY(x - 1, y + i);
            cout << (char)255;
        }
    }
}
void reloadConsole(int x, int y, int num, int posY[])
{
    for (int i = 0; i < 8; i++)
    {
        if (posY[i] >= y && posY[i] < y + num)
        {
            GotoXY(x - 1, posY[i]);
            cout << (char)205;
            GotoXY(x + num, posY[i]);
            cout << (char)205;
            break;
        }
        else if (posY[i] == y + num)
        {
            for (int j = 0; j < num; j++)
            {
                GotoXY(x + j, posY[i]);
                cout << (char)205;
            }
            break;
        }
    }
    for (int i = 7; i >=0; i--)
        if (posY[i] == y - 1)
        {
            for (int j = 0; j < num; j++)
            {
                GotoXY(x + j, posY[i]);
                cout << (char)205;
            }
            break;
        }
}