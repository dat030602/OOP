#pragma once
#include "CongTrinh.h"

class CongTrinhThemLinh :public CongTrinh
{
public:
    CongTrinhThemLinh();
    CongTrinhThemLinh(const CongTrinhThemLinh&);
    CongTrinhThemLinh(string, int, int, int);
    void Draw();
    bool LevelUp();
    void ThemCongTrinh();
};