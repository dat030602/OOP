#pragma once
#include <iostream>
#include <vector>
#include <Windows.h>

using namespace std;

const int LEFT = 9, RIGHT = 45;
const int TOP = 2, BOT = 18;

void GotoXY(int x, int y);
void draw();
void DisableResizeWindow();
void ShowScrollbar(BOOL Show);
void FixConsoleWindow();
void Nocursortype();
void DisableSelection();