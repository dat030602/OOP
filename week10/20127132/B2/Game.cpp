#include "Game.h"
#include "QuaiVat.h"

Game::Game()
{
    m_Player = new Player;
    m_CongTrinhNangCap = new CongTrinhNangCap;
    m_CongTrinhThemLinh = new CongTrinhThemLinh;
    int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
    while (1)
    {
        if ((x1 == x2 && y1 == y2))
        {
            x1 = rand() % 4;
            y1 = rand() % 4;
            x2 = rand() % 4;
            y2 = rand() % 4;
        }
        else if (x1 == 0 && y1 == 0)
        {
            x1 = rand() % 4;
            y1 = rand() % 4;
        }
        else if (x2 == 0 && y2 == 0)
        {
            x2 = rand() % 4;
            y2 = rand() % 4;
        }
        else
        {
            m_CongTrinhNangCap->setPos(x1, y1);
            m_CongTrinhThemLinh->setPos(x2, y2);
            break;
        }
    }
    level = 0;
    nextLevel = false;
}
Game::~Game()
{
    delete m_Player;
    delete m_CongTrinhNangCap;
    delete m_CongTrinhThemLinh;
    for (int i = 0; i < m_QuaiVat.size(); i++)
    {
        delete m_QuaiVat[i];
        m_QuaiVat[i] = nullptr;
    }
    for (int i = 0; i < m_dsLinh.size(); i++)
    {
        delete m_dsLinh[i];
        m_dsLinh[i] = nullptr;
    }
}
void Game::Draw()
{
    m_CongTrinhNangCap->Draw();
    m_CongTrinhThemLinh->Draw();
    for (int i = 0; i < m_dsLinh.size(); i++)
        m_dsLinh[i]->Draw();
    for (int i = 0; i < m_QuaiVat.size(); i++)
        m_QuaiVat[i]->Draw();
    m_Player->Draw();
    GotoXY(LEFT + 5, BOT + 3);
    cout << "So Linh Hien Tai: " << m_Player->length();
}
void Game::move(char MOVING)
{
    m_Player->move(MOVING);
}
void Game::resetGame()
{
    clearGame();
    level++;
    m_Player = new Player;
    m_CongTrinhNangCap = new CongTrinhNangCap;
    m_CongTrinhThemLinh = new CongTrinhThemLinh;
    m_CongTrinhNangCap->ThemCongTrinh();
    m_CongTrinhThemLinh->ThemCongTrinh();
    int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
    while (1)
    {
        if ((x1 == x2 && y1 == y2))
        {
            x1 = rand() % 4;
            y1 = rand() % 4;
            x2 = rand() % 4;
            y2 = rand() % 4;
        }
        else if (x1 == 0 && y1 == 0)
        {
            x1 = rand() % 4;
            y1 = rand() % 4;
        }
        else if (x2 == 0 && y2 == 0)
        {
            x2 = rand() % 4;
            y2 = rand() % 4;
        }
        else
        {
            m_CongTrinhNangCap->setPos(x1, y1);
            m_CongTrinhThemLinh->setPos(x2, y2);
            break;
        }
    }
    for (int i = 0; i < 2; i++)
    {
        QuaiVat* temp = new QuaiVat;
        temp->ThemQuaiVat();
        findPos(x1, y1);
        temp->setPos(x1, y1);
        m_QuaiVat.push_back(temp);
    }
    for (int i = 0; i < level - 1; i++)
    {
        m_QuaiVat[0]->LevelUp();
        m_QuaiVat[1]->LevelUp();
    }
}
void Game::IsImpact()
{
    int x, y;
    //đến công trình nâng cấp
    if (m_Player->IsImpact(m_CongTrinhNangCap))
    {
        //thêm vào vị trí mới
        findPos(x, y);
        m_CongTrinhNangCap->setPos(x, y);
    }
    //đến công trình thêm lính
    else if (m_Player->IsImpact(m_CongTrinhThemLinh))
    {
        findPos(x, y);
        //nếu là lính phòng thủ thì def > dame
        if (m_CongTrinhThemLinh->LinhDef())
        {
            m_dsLinh.push_back(new LinhKhien(m_CongTrinhThemLinh->GetName(), m_CongTrinhThemLinh->GetHeal(),
                m_CongTrinhThemLinh->GetDame(), m_CongTrinhThemLinh->GetDef(), x, y));
        }
        //nếu là lính cung thủ thì def < dame
        else
            m_dsLinh.push_back(new CungThu(m_CongTrinhThemLinh->GetName(), m_CongTrinhThemLinh->GetHeal(),
                m_CongTrinhThemLinh->GetDame(), m_CongTrinhThemLinh->GetDef(), x, y));
        //thêm vào vị trí mới
        findPos(x, y);
        m_CongTrinhThemLinh->setPos(x, y);
        m_CongTrinhThemLinh->ThemCongTrinh();
    }
    //đến gặp lính thì thêm lính đó vào player, xóa trong danh sách lính
    else if (m_Player->IsImpact(m_dsLinh)){}
    //đến gặp quái vật, nếu đánh quái vật không chết -> thua
    //nếu đánh thắng thì trừ máu
    //nếu quên lính hết máu thì xóa
    else if (m_Player->IsImpact(m_QuaiVat))
    {
        if (m_QuaiVat.size() == 0)
            nextLevel = true;
    }
    Draw();
}

void Game::clearGame()
{
    delete m_Player;
    delete m_CongTrinhNangCap;
    delete m_CongTrinhThemLinh;
    for (int i = 0; i < m_QuaiVat.size(); i++)
    {
        delete m_QuaiVat[i];
        m_QuaiVat[i] = nullptr;
    }
    for (int i = 0; i < m_dsLinh.size(); i++)
    {
        delete m_dsLinh[i];
        m_dsLinh[i] = nullptr;
    }
}

//tìm vị trí chưa có đối tượng (vị trí trống)
void Game::findPos(int& x, int& y)
{
    x = rand() % 4;
    y = rand() % 4;
    bool check = true;
    while (check)
    {
        if (x == m_Player->X() && y == m_Player->Y() ||
            (x == m_CongTrinhNangCap->X() && y == m_CongTrinhNangCap->Y()) ||
            (x == m_CongTrinhThemLinh->X() && y == m_CongTrinhThemLinh->Y()))
        {
            x = rand() % 4;
            y = rand() % 4;
            check = false;
        }
        for (int i = 0; i < m_QuaiVat.size(); i++)
        {
            if (x == m_QuaiVat[i]->X() && y == m_QuaiVat[i]->Y())
            {
                x = rand() % 4;
                y = rand() % 4;
                check = false;
                break;
            }
        }
        for (int i = 0; i < m_dsLinh.size(); i++)
        {
            if (x == m_dsLinh[i]->X() && y == m_dsLinh[i]->Y())
            {
                x = rand() % 4;
                y = rand() % 4;
                check = false;
                break;
            }
        }
        if (check)
            break;
        check = true;
    }
}

int Game::curLev()
{
    return level;
}

bool Game::IsNextLevel()
{
    return nextLevel;
}

bool Game::IsDead()
{
    return m_Player->IsDead();
}