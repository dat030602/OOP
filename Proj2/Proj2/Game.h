#pragma once
#include "Animal.h"
#include "People.h"
#include "Vehicle.h"
#include "MainHeader.h"
#include "Truck.h"
#include "Car.h"
#include "Bird.h"
#include "Dinausor.h"
class Game {
	Truck* m_truck;
	Car* m_car;
	Dinausor* m_dinausor;
	Bird* m_bird;
	People* m_people;

	int is_point;
	int is_running;
	int score;
	int num;
	int m_currentLevel;
	int highScore;
public:
	static const int posY[];
public:
	Game();
	Game(int level);
	void drawGame(char, int&);
	~Game();
	People* getPeople() { return m_people; };
	Vehicle* getTrucks() const { return m_truck; }
	Vehicle* getCars() const { return m_car; }
	Animal* getDinausors() const { return m_dinausor; }
	Animal* getBirds() const { return m_bird; }
	void resetGame(int level);
	int nextLevel() { return ++m_currentLevel; }
	void exitGame(thread* t);
	void startGame();
	bool IS_RUNNING() { return is_running; };
	bool IS_POINT() { return is_point; };
	void clearGame();
	void loadGame(istream);
	void saveGame(istream);
	void pauseGame(HANDLE t)
	{
		SuspendThread(t);
	}
	void resumeGame(HANDLE t)
	{
		ResumeThread(t);
	}
	void updatePosPeople(char key);
	void updatePosVehicle();
	void updatePosAnimal();
	int NumOfEnemy() { return num; };
	bool isImpactPoint();
	void updateScore();
};