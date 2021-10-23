#include "Game.h"
#include "Animal.h"
#include "People.h"
#include "Vehicle.h"
#include "MainHeader.h"
#include "Truck.h"
#include "Car.h"
#include "Bird.h"
#include "Dinausor.h"
Game::Game()
{
	srand(time(NULL));
	score = highScore = 0;
	m_currentLevel = 1;
	resetGame(1);
};
Game::Game(int level)
{
	srand(time(NULL));
	resetGame(level);
};
void Game::drawGame(char key, int &flashing)
{
	int i;
	GotoXY(125, 23);
	cout << m_currentLevel;
	if (isImpactPoint())
	{
		flashing = 0;
		score += 10;
	}
	if (flashing == 0)
	{
		updateScore();
		m_people->setPos();
		m_people->draw();
	}
	else if (flashing % 6 == 0)
	{
		m_people->clear();
		if (flashing == 60)
			flashing = 1;
	}
	else if (flashing % 3 == 0)
		m_people->draw();
	for (i = 0; i < num; ++i)
	{
		m_truck[i].selfDraw();
		m_truck[i].clearPath();
		m_car[i].selfDraw();
		m_car[i].clearPath();
		m_dinausor[i].selfDraw();
		m_dinausor[i].clearPath();
		m_bird[i].selfDraw();
		m_bird[i].clearPath();
	}
	if (key != ' ')
	{
		m_people->selfDraw();
		m_people->clearPath(key);
		m_people->reloadConsole(posY);
	}
};
Game::~Game()
{
	clearGame();
}
void Game::resetGame(int level)
{
	clearGame();
	m_currentLevel = level;
	if (level > 1)
		score += 20;
	if (level == 1)
		score = 0;
	//updateScore();
	is_running = true;
	m_people = new People((RIGHT + LEFT) / 2, BOTTOM);

	int interval = (level - 1) / 3 + 1;
	int numOfVehicles = interval + 1;// số lượng xe
	int distance = (RIGHT - LEFT - 1) / numOfVehicles; // khoảng cách xe
	int laneDistance = 4; // khoảng cách giữa 2 làn

	int row = BOTTOM - laneDistance;
	int col = LEFT + 1;
	num = numOfVehicles;
	m_truck = new Truck[num];
	for (int i = 0; i < num; ++i, col += distance)
	m_truck[i].setPos(col, row);

	row -= laneDistance;
	col = (((LEFT + 1) << 1) + distance) >> 1;
	m_car = new Car[num];
	for (int i = 0; i < num; ++i, col += distance)
		m_car[i].setPos(col, row);

	row -= laneDistance;
	col = LEFT + 1;
	m_dinausor = new Dinausor[num];
	for (int i = 0; i < num; ++i, col += distance)
		m_dinausor[i].setPos(col, row);

	row -= laneDistance;
	col = (((LEFT + 1) << 1) + distance) >> 1;
	m_bird = new Bird[num];
	for (int i = 0; i < num; ++i, col += distance)
		m_bird[i].setPos(col, row);
}
void Game::exitGame(thread* t)
{
	system("cls");
	is_running = false;
	t->join();
}
void Game::startGame()
{
	is_running = true;
}
void Game::clearGame()
{
	delete m_people;
	delete[]m_truck;
	delete[]m_car;
	delete[]m_dinausor;
	delete[]m_bird;
}
void Game::updatePosPeople(char key)
{
	if (key == 'W')
		m_people->up();

	else if (key == 'A')
		m_people->left();

	else if (key == 'S')
		m_people->down();

	else if (key == 'D')
		m_people->right();
};
void Game::updatePosVehicle()
{
	int i;
	for (i = 0; i < num; ++i)
	{
		m_truck[i].move();
		m_car[i].move();
	}
};
void Game::updatePosAnimal() {
	int i;
	for (i = 0; i < num; ++i)
	{
		m_bird[i].move();
		m_dinausor[i].move();
	}
};
void Game::updateScore()
{
	GotoXY(125, 16);
	cout << "   ";
	GotoXY(125, 16);
	cout << score;
	highScore = max(highScore, score);
	GotoXY(138, 23);
	cout << highScore;
}
bool Game::isImpactPoint()
{
	return m_people->isImpact();
}
void Game::saveGame(string file)
{
	int x, y;
	ofstream fi;
	fi.open(file);
	fi << m_currentLevel << endl;
	for (int i = 0; i < num; i++)
	{
		x = m_truck[i].X();
		y = m_truck[i].Y();
		fi << x << " " << y << " ";
	}
	fi << endl;
	for (int i = 0; i < num; i++)
	{
		x = m_car[i].X();
		y = m_car[i].Y();
		fi << x << " " << y << " ";
	}
	fi << endl;
	for (int i = 0; i < num; i++)
	{
		x = m_dinausor[i].X();
		y = m_dinausor[i].Y();
		fi << x << " " << y << " ";
	}
	fi << endl;
	for (int i = 0; i < num; i++)
	{
		x = m_bird[i].X();
		y = m_bird[i].Y();
		fi << x << " " << y << " ";
	}
	fi << endl;
	x = m_people->X();
	y = m_people->Y();
	fi << x << " " << y << endl;
	fi << score << " " << highScore;
	fi.close();
}
void Game::loadGame(string file)
{
	int x, y;
	clearGame();
	fstream fi;
	fi.open(file);
	fi >> m_currentLevel;

	int interval = (m_currentLevel - 1) / 3 + 1;
	int numOfVehicles = interval + 1;// số lượng xe
	int distance = (RIGHT - LEFT - 1) / numOfVehicles; // khoảng cách xe
	int laneDistance = 4; // khoảng cách giữa 2 làn

	num = numOfVehicles;
	m_truck = new Truck[num];
	for (int i = 0; i < num; ++i)
	{
		fi >> x >> y;
		m_truck[i].setPos(x, y);
	}

	m_car = new Car[num];
	for (int i = 0; i < num; ++i)
	{
		fi >> x >> y;
		m_car[i].setPos(x, y);
	}

	m_dinausor = new Dinausor[num];
	for (int i = 0; i < num; ++i)
	{
		fi >> x >> y;
		m_dinausor[i].setPos(x, y);
	}

	m_bird = new Bird[num];
	for (int i = 0; i < num; ++i)
	{
		fi >> x >> y;
		m_bird[i].setPos(x, y);
	}

	is_running = true;
	fi >> x >> y;
	m_people = new People(x, y);
	fi >> score >> highScore;
	fi.close();
	updateScore();
	m_people->setPos();
}
void Game::effectNextLevelDead()
{
	int y2[] = { 0,4 };
	//ngang
	int y1 = 28;
	int x = 125;
	for (int i = 0; i < 2; i++)
	{
		GotoXY(x + 1, y1 + y2[i]);
		for (int j = 0; j < 20; j++)
			cout << (char)205;
	}
	//doc
	GotoXY(x, y1);
	cout << (char)201;
	GotoXY(x + 20, y1);
	cout << (char)187;

	GotoXY(x, y1 + y2[1]);
	cout << (char)200;
	GotoXY(x + 20, y1 + y2[1]);
	cout << (char)188;

	for (int i = y1; i < y1 + y2[1]; i++)
	{
		if (i + 1 != y1 && i + 1 != y1 + y2[1])
		{
			GotoXY(x, i + 1);
			cout << (char)186;
			GotoXY(x + 20, i + 1);
			cout << (char)186;
		}
	}
}
void Game::clearEffect()
{
	int y2[] = { 0,4 };
	//ngang
	int y1 = 28;
	int x = 125;
	for (int i = 0; i < 6; i++)
	{
		GotoXY(x, y1 + i);
		for (int j = 0; j < 22; j++)
			cout << " ";
	}
}