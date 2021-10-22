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
	GotoXY(123, 23);
	m_currentLevel = level;
	cout << level;
	if (level > 1)
		score += 20;
	updateScore();
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
	if (key == 'W' || key == 72)
		m_people->up();

	else if (key == 'A' || key == 75)
		m_people->left();

	else if (key == 'S' || key == 80)
		m_people->down();

	else if (key == 'D' || key == 77)
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
	cout << score;
	highScore = max(highScore, score);
	GotoXY(138, 23);
	cout << highScore;
}
bool Game::isImpactPoint()
{
	return m_people->isImpact();
}