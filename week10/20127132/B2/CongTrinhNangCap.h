#pragma once
#include "CongTrinh.h"

class CongTrinhNangCap :public CongTrinh
{
public:
    CongTrinhNangCap();
    CongTrinhNangCap(const CongTrinhNangCap&);
    CongTrinhNangCap(string, int, int, int);
    void Draw();
    bool LevelUp();
    void ThemCongTrinh();
};