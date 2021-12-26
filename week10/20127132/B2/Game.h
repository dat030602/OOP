#pragma once
#include "MainHeader.h"
#include "Player.h"
#include "Linh.h"
#include "CungThu.h"
#include "LinhKhien.h"
#include "QuaiVat.h"
#include "CongTrinh.h"
#include "CongTrinhNangCap.h"
#include "CongTrinhThemLinh.h"

class Game
{
    Player* m_Player;
    CongTrinhNangCap* m_CongTrinhNangCap;
    CongTrinhThemLinh* m_CongTrinhThemLinh;
    vector<QuaiVat*> m_QuaiVat;
    vector<Linh*> m_dsLinh;
    int level;
    bool nextLevel;
public:
    Game();
    ~Game();
    void Draw();
    void move(char);
    void resetGame();
    void IsImpact();
    void clearGame();
    void findPos(int&, int&);
    int curLev();
    bool IsNextLevel();
    bool IsDead();
};