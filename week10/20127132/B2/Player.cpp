#include "Player.h"
#include "LinhKhien.h"
#include "CungThu.h"

Player::Player()
{
	x = y = 0;
	dead = false;
}
Player::~Player()
{
	x = y = -1;
	dead = true;
	for (int i = 0; i < m_Linh.size(); i++)
	{
		delete m_Linh[i];
		m_Linh[i] = nullptr;
	}
}
bool Player::IsDead()
{
	return dead;
}

int Player::length() 
{ 
	return m_Linh.size(); 
}

void Player::move(char MOVING)
{
	int mX = x, mY = y;
	if (MOVING == 72)
		y--;
	else if (MOVING == 80)
		y++;
	else if (MOVING == 75)
		x--;
	else if (MOVING == 77)
		x++;
	if (x == 4)
		x--;
	else if (x == -1)
		x++;
	else
	{
		GotoXY(13 + mX * 9, 4 + 4 * mY);
		cout << "  ";
	}
	if (y == 4)
		y--;
	else if (y == -1)
		y++;
	else
	{
		GotoXY(LEFT + 4 + mX * 9, TOP + 2 + 4 * mY);
		cout << "  ";
	}
}

bool Player::IsImpact(vector<Linh*>& linh)
{
	for (int i = 0; i < linh.size(); i++)
	{
		if (linh[i]->X() == x && linh[i]->Y() == y)
		{
			m_Linh.push_back(linh[i]);
			linh.erase(linh.begin() + i);
			return true;
		}
	}
	return false;
}
bool Player::IsImpact(vector<QuaiVat*>& quai)
{
	for (int i = 0; i < quai.size(); i++)
	{
		if (quai[i]->X() == x && quai[i]->Y() == y)
		{
			for (int j = 0; j < m_Linh.size(); j++)
			{
				//nếu lính chết -> xóa
				if (m_Linh[j]->battle(quai[i]->GetDame()))
					m_Linh.erase(m_Linh.begin() + j);
				//trừ máu quái
				quai[i]->setHeal(m_Linh[j]->GetDame());
			}
			if (quai[i]->dead())
				quai.erase(quai.begin() + i);
			else // Hết lính mà quái chưa chết -> thua
				dead = true;
			return true;
		}
	}
	return false;
}
bool Player::IsImpact(CongTrinh* congtrinh)
{
	if (congtrinh->X() == x && congtrinh->Y() == y)
	{
		//công trình nâng cấp
		if (congtrinh->LevelUp())
			for (int i = 0; i < m_Linh.size(); i++)
				m_Linh[i]->LevelUp();
		//công trình thêm lính xử lý ở class Game 
		return true;
	}
	return false;
}
void Player::setPos(int x, int y)
{
	this->x = x;
	this->y = y;
}
int Player::X()
{ 
	return x; 
}
int Player::Y() 
{ 
	return y; 
}

void Player::Draw()
{
	GotoXY(LEFT + 4 + x * 9, TOP + 2 + 4 * y);
	cout << "ME";
}

