#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <stdio.h>
#include <thread>
#include <ctime>

using namespace std;

const int LEFT = 3, RIGHT = 111, TOP = 2, BOTTOM = 37;

void DisableResizeWindow();
void ShowScrollbar(BOOL Show);
void Nocursortype();
void GotoXY(int x, int y);
void FixConsoleWindow();

void drawConsole(int x, int y);
void drawMenu(int x, int y);
void drawEnemy(int x, int y, const char drawEnemy[][12], int w, int h);
void clearPath(int x, int y, int w, int h, char temp);
void reloadConsole(int x, int y, int num, int posY[]);
void runGame();

static int mSpeed = 1;
class Animal
{
public:
	static const int width = 5;
	static const int height = 3;
	
private:
	void copyAnimal(const Animal& a)
	{
		mX = a.mX;
		mY = a.mY;
	};
public:
	int mX, mY;
public:
	Animal() {
		mX = mY = 0;
	};
	Animal(int x, int y) {
		mX = x;
		mY = y;
	};
	Animal(const Animal& a) {
		copyAnimal(a);
	};
	virtual ~Animal() {};
public:
	//virtual void selfDraw() const = 0;
	virtual void move() = 0;
public:
	void setPos(int x, int y) {
		mX = x;
		mY = y;
	};
	int X() const { return mX; }
	int Y() const { return mY; }
};
class Bird : public Animal
{
public:
	static const char form[][5];
public:
	Bird() {};
	Bird(int, int) {};
	Bird(const Bird&) {};
	~Bird() {};
public:
	virtual void selfDraw() 
	{
		int row = mY - height + 1;
		int i = row, j;
		for (; row <= mY; row++)
		{
			for (j = 0; j < width; j++) 
			{
				if (mX + j < LEFT)
				{
					GotoXY(mX + j + (RIGHT - LEFT +  1), row);
					cout << form[row - i][j];
				}
				else if (mX + j > RIGHT) 
				{
					GotoXY(mX + j - (RIGHT - LEFT + 1), row);
					cout << form[row - i][j];
				}
				else
				{
					GotoXY(mX + j, row);
					cout << form[row - i][j];
				}
			}
		}
	}
	void move() {
		mX -= mSpeed;
		if (mX >= RIGHT)
			mX = mX + LEFT - RIGHT + 1;
		if (mX <= LEFT - width + 1)
			mX = mX - (LEFT - RIGHT + 1);
	}
	void clearPath()
	{
		int x1, y1;
		y1 = mY - height + 1;
		x1 = mX;
		int i = 0;
		if (RIGHT - mX - 1 < width)
		{
			for (int j = 0; j < height; j++)
			{
				GotoXY(LEFT, y1 + j);
				cout << " ";
				GotoXY(LEFT + 1, y1 + j);
				cout << " ";
			}
		}
		for (; i < height; i++)
		{
			GotoXY(x1 + width, y1 + i);
			cout << " ";
		}
	}
	Bird& operator=(const Bird& d)
	{
		Animal::operator=(d);
		return *this;
	}
};
class Dinausor : public Animal
{
public:
	static const char form[][5];
public:
	Dinausor() {};
	Dinausor(int, int) {};
	Dinausor(const Dinausor&) {};
	~Dinausor() {};
public:
	virtual void selfDraw()
	{
		int row = mY - height + 1;
		int i = row, j;
		for (; row <= mY; row++)
		{
			for (j = 0; j < width; j++)
			{
				if (mX + j < LEFT)
				{
					GotoXY(mX + j + (RIGHT - LEFT + 1), row);
					cout << form[row - i][j];
				}
				else if (mX + j > RIGHT)
				{
					GotoXY(mX + j - (RIGHT - LEFT + 1), row);
					cout << form[row - i][j];
				}
				else
				{
					GotoXY(mX + j, row);
					cout << form[row - i][j];
				}
			}
		}
	}
	void move() {
		mX += mSpeed;
		if (mX >= RIGHT)
			mX = mX + LEFT - RIGHT + 1;
		if (mX <= LEFT - width + 1)
			mX = mX - (LEFT - RIGHT + 1);
	}
	void clearPath()
	{
		int x1, y1;
		y1 = mY - height + 1;
		x1 = mX;
		int i = 0;
		if (mX - 2 < width)
		{
			for (int j = 0; j < height; j++)
			{
				GotoXY(RIGHT, y1 + j);
				cout << " ";
				GotoXY(RIGHT - 1, y1 + j);
				cout << " ";
			}
		}
		for (; i < height; i++)
		{
			GotoXY(x1 - 1, y1 + i);
			cout << " ";
		}
	}
	Dinausor& operator=(const Dinausor& d)
	{
		Animal::operator=(d);
		return *this;
	}
};
class Vehicle
{
public:
	static const int width = 12;
	static const int height = 3;
private:
	void copyVehicle(const Vehicle& a)
	{
		mX = a.mX;
		mY = a.mY;
	};
public:
	int mX, mY;
public:
	Vehicle() {
		mX = mY = 0;
	};
	Vehicle(int x, int y) {
		mX = x;
		mY = y;
	};
	Vehicle(const Vehicle& a) {
		copyVehicle(a);
	}
	;
	virtual ~Vehicle() {};
public:
	//virtual void selfDraw() const = 0;
public:
	void setPos(int x, int y) {
		mX = x;
		mY = y;
	};
	int X() const { return mX; }
	int Y() const { return mY; }
};
class Truck : public Vehicle
{
public:
	static const char form[][12];
public:
	Truck() {};
	Truck(int, int) {};
	Truck(const Truck&) {};
	~Truck() {};
public:
	virtual void selfDraw()
	{
		int row = mY - height + 1;
		int i = row, j;
		for (; row <= mY; row++)
		{
			for (j = 0; j < width; j++)
			{
				if (mX + j < LEFT)
				{
					GotoXY(mX + j + (RIGHT - LEFT + 1), row);
					cout << form[row - i][j];
				}
				else if (mX + j > RIGHT)
				{
					GotoXY(mX + j - (RIGHT - LEFT + 1), row);
					cout << form[row - i][j];
				}
				else
				{
					GotoXY(mX + j, row);
					cout << form[row - i][j];
				}
			}
		}
	}
	void clearPath()
	{
		int x1, y1;
		y1 = mY - height + 1;
		x1 = mX;
		int i = 0;
		if (mX - 2 < width)
		{
			for (int j = 0; j < height; j++)
			{
				GotoXY(RIGHT, y1 + j);
				cout << " ";
				GotoXY(RIGHT - 1, y1 + j);
				cout << " ";
			}
		}
		for (; i < height; i++)
		{
			GotoXY(x1 - 1, y1 + i);
			cout << " ";
		}
	}
	void move() {
		mX += mSpeed;
		if (mX >= RIGHT)
			mX = mX + LEFT - RIGHT + 1;
		if (mX <= LEFT - width + 1)
			mX = mX - (LEFT - RIGHT + 1);
	}
	Truck& operator=(const Truck& t)
	{
		Vehicle::operator=(t);
		return *this;
	}
};
class Car : public Vehicle
{
public:
	static const char form[][12];
public:
	Car() {};
	Car(int, int) {};
	Car(const Car&) {};
	~Car() {};
public:
	virtual void selfDraw()
	{
		int row = mY - height + 1;
		int i = row, j;
		for (; row <= mY; row++)
		{
			for (j = 0; j < width; j++)
			{
				if (mX + j < LEFT)
				{
					GotoXY(mX + j + (RIGHT - LEFT + 1), row);
					cout << form[row - i][j];
				}
				else if (mX + j > RIGHT)
				{
					GotoXY(mX + j - (RIGHT - LEFT + 1), row);
					cout << form[row - i][j];
				}
				else
				{
					GotoXY(mX + j, row);
					cout << form[row - i][j];
				}
			}
		}
	}
	void clearPath()
	{
		int x1, y1;
		y1 = mY - height + 1;
		x1 = mX;
		int i = 0;
		if (RIGHT - mX - 1 < width)
		{
			for (int j = 0; j < height; j++)
			{
				GotoXY(LEFT, y1 + j);
				cout << " ";
				GotoXY(LEFT + 1, y1 + j);
				cout << " ";
			}
		}
		for (; i < height; i++)
		{
			GotoXY(x1 + width, y1 + i);
			cout << " ";
		}
	}
	void move() {
		mX -= mSpeed;
		if (mX >= RIGHT)
			mX = mX + LEFT - RIGHT + 1;
		if (mX <= LEFT - width + 1)
			mX = mX - (LEFT - RIGHT + 1);
	}
	Car& operator=(const Car& c)
	{
		Vehicle::operator=(c);
		return *this;
	}
};
class People
{
public:
	static const char form[][3];
	static const int width = 3;
	static const int height = 3;
private:
	int mX, mY;
	//int mSpeed;
	bool mState;

	void copyPeople(const People& p)
	{
		mX = p.mX;
		mY = p.mY;
		//mSpeed = p.mSpeed;
		mState = p.mState;
	}
public:
	People()
	{
		mX = mY = 0;
		//mSpeed = 1;
		mState = true;
	}
	People(int column, int row)
	{
		mX = column;
		mY = row;
		//mSpeed = 1;
		mState = true;
	}
	~People() {}
	People(const People& p)
	{
		copyPeople(p);
	}
	int X() { return mX; }
	int Y() { return mY; }
	void selfDraw()
	{
		int row = mY - height + 1;
		int i = row, j;
		for (; row <= mY; row++) {
			GotoXY(mX, row);
			for (j = 0; j < width; j++)
				cout << form[row - i][j];
		}
	}
	void clearPath(char key)
	{
		int i = 0;
		int x1 = mX, y1 = mY - height + 1;
		if (key == 'A' || key == 75)
		{
			for (; i < width; i++)
			{
				GotoXY(x1 + height, y1 + i);
				cout << " ";
			}
		}
		else if (key == 'W' || key == 72)
		{
			for (; i < height; i++)
			{
				GotoXY(x1 + i, y1 + 3);
				cout << " ";
			}
		}
		else if (key == 'S' || key == 80)
		{
			for (; i < height; i++)
			{
				GotoXY(x1 + i, y1 - 1);
				cout << " ";
			}
		}
		else if (key == 'D' || key == 77)
		{
			for (; i < width; i++)
			{
				GotoXY(x1 - 1, y1 + i);
				cout << (char)255;
			}
		}
	}
	void reloadConsole(static const int posY[])
	{
		int y1 = mY - height + 1;
		for (int i = 0; i < 8; i++)
		{
			if (posY[i] >= y1 && posY[i] < y1 + height)
			{
				GotoXY(mX - 1, posY[i]);
				cout << (char)205;
				GotoXY(mX + height, posY[i]);
				cout << (char)205;
				break;
			}
			else if (posY[i] == y1 + height)
			{
				for (int j = 0; j < height; j++)
				{
					GotoXY(mX + j, posY[i]);
					cout << (char)205;
				}
				break;
			}
		}
		for (int i = 7; i >= 0; i--)
			if (posY[i] == y1 - 1)
			{
				for (int j = 0; j < height; j++)
				{
					GotoXY(mX + j, posY[i]);
					cout << (char)205;
				}
				break;
			}
	}
	void setSpeed(int speed) { //mSpeed = speed;
	}
	void setPos(int x, int y)
	{
		mX = x;
		mY = y;
	}
	//void tell();
	void up()
	{
		mY -= mSpeed;
	}
	void down()
	{
		if (mY + mSpeed <= BOTTOM)
			mY += mSpeed;
	}
	void left() {
		if (mX - mSpeed >= LEFT)
			mX -= mSpeed;
		else
			mX = LEFT;
	}
	void right()
	{
		if (mX + mSpeed <= RIGHT - width + 1)
			mX += mSpeed;
		else
			mX = RIGHT - width + 1;
	}
	/*bool isImpact(const Vehicle*, int, bool);
	bool isImpact(const Animal*, int, bool);*/
	bool isFinish() { return mY <= TOP; }
	bool isDead() { return mState = false; }
	void dead() { mState == false; }
};
class Game {
	Truck* m_truck1;
	Truck* m_truck2;
	Car* m_car1;
	Car* m_car2;
	Dinausor* m_dinausor1;
	Dinausor* m_dinausor2;
	Bird* m_bird;
	People* m_people;
	int is_running;

	int numOfTrucks;
	int numOfCars;
	int numOfDinosaurs;
	int numOfBirds;
	int m_currentLevel;
public:
	static const int posY[];
public:
	Game()
	{
		srand(time(NULL));
		resetGame(1);
	};
	Game(int level)
	{
		srand(time(NULL));
		resetGame(level);
	};
	void drawGame(char key)
	{
		int i;
		for (i = 0; i < numOfTrucks; ++i)
		{
			m_truck1[i].selfDraw();
			m_truck1[i].clearPath();
			m_truck2[i].selfDraw();
			m_truck2[i].clearPath();
			m_car1[i].selfDraw();
			m_car1[i].clearPath();
			m_car2[i].selfDraw();
			m_car2[i].clearPath();
			m_dinausor1[i].selfDraw();
			m_dinausor1[i].clearPath();
			m_dinausor2[i].selfDraw();
			m_dinausor2[i].clearPath();
			m_bird[i].selfDraw();
			m_bird[i].clearPath();
		}
		//for (i = 0; i < numOfCars; ++i)
		//{
		//	
		//}
		//for (i = 0; i < numOfDinosaurs; ++i)
		//{
		//	
		//}
		//for (i = 0; i < numOfBirds; ++i)
		//{
		//	
		//}
		m_people->selfDraw();
		m_people->clearPath(key);
		m_people->reloadConsole(posY);
	};
	~Game()
	{
		clearGame();
	}
	People* getPeople() { return m_people; };//Lấy thông tin người
	Vehicle* getTrucks1() const { return m_truck1; }
	Vehicle* getTrucks2() const { return m_truck2; }
	Vehicle* getCars1() const { return m_car1; }
	Vehicle* getCars2() const { return m_car2; }
	Animal* getDinosaurs1() const { return m_dinausor1; }
	Animal* getDinosaurs2() const { return m_dinausor2; }
	Animal* getBirds() const { return m_bird; }
	void resetGame(int level)
	{
		clearGame();
		m_currentLevel = level;
		is_running = true;
		m_people = new People((RIGHT + LEFT) / 2, BOTTOM);

		int interval = (level - 1) / 3 + 1;
		int numOfVehicles = 2 + interval;
		int carDistance = (RIGHT - LEFT - 1) / numOfVehicles;
		int laneDistance = 4;

		int row = BOTTOM - laneDistance;
		int col = LEFT + 1;
		numOfTrucks = numOfVehicles;
		//createObstacles(m_truck, numOfTrucks, row, LEFT + 1, carDistance);


		m_truck1 = new Truck[numOfTrucks];
		for (int i = 0; i < numOfTrucks; ++i, col += carDistance)
			m_truck1[i].setPos(col, row);


		row -= laneDistance;
		numOfCars = numOfVehicles;
		col = (((LEFT + 1) << 1) + carDistance) >> 1;
		//createObstacles(m_car, numOfCars, row, (((LEFT + 1) << 1) + carDistance) >> 1, carDistance);

		m_car1 = new Car[numOfCars];
		for (int i = 0; i < numOfTrucks; ++i, col += carDistance)
			m_car1[i].setPos(col, row);

		row -= laneDistance;
		numOfDinosaurs = numOfVehicles;
		col = LEFT + 1;
		//createObstacles(m_dinausor, numOfDinosaurs, row, LEFT + 1, carDistance);
		m_dinausor1 = new Dinausor[numOfDinosaurs];
		for (int i = 0; i < numOfTrucks; ++i, col += carDistance)
			m_dinausor1[i].setPos(col, row);

		row -= laneDistance;
		numOfBirds = numOfVehicles;
		col = (((LEFT + 1) << 1) + carDistance) >> 1;
		//createObstacles(m_bird, numOfBirds, row, (((LEFT + 1) << 1) + carDistance) >> 1, carDistance);
		m_bird = new Bird[numOfBirds];
		for (int i = 0; i < numOfTrucks; ++i, col += carDistance)
			m_bird[i].setPos(col, row);

		row -= laneDistance;
		col = LEFT + 1;
		numOfTrucks = numOfVehicles;
		//createObstacles(m_truck, numOfTrucks, row, LEFT + 1, carDistance);


		m_truck2 = new Truck[numOfTrucks];
		for (int i = 0; i < numOfTrucks; ++i, col += carDistance)
			m_truck2[i].setPos(col, row);


		row -= laneDistance;
		numOfCars = numOfVehicles;
		col = (((LEFT + 1) << 1) + carDistance) >> 1;
		//createObstacles(m_car, numOfCars, row, (((LEFT + 1) << 1) + carDistance) >> 1, carDistance);

		m_car2 = new Car[numOfCars];
		for (int i = 0; i < numOfTrucks; ++i, col += carDistance)
			m_car2[i].setPos(col, row);

		row -= laneDistance;
		numOfDinosaurs = numOfVehicles;
		col = LEFT + 1;
		//createObstacles(m_dinausor, numOfDinosaurs, row, LEFT + 1, carDistance);
		m_dinausor2 = new Dinausor[numOfDinosaurs];
		for (int i = 0; i < numOfTrucks; ++i, col += carDistance)
			m_dinausor2[i].setPos(col, row);
	}
	void exitGame(thread* t)
	{

		system("cls");
		is_running = false;
		t->join();
	}
	void startGame()
	{
		is_running = true;
	}
	bool IS_RUNNING() { return is_running; };
	void clearGame()
	{
		delete m_people;
		delete[]m_truck1;
		delete[]m_truck2;
		delete[]m_car1;
		delete[]m_car2;
		delete[]m_dinausor1;
		delete[]m_dinausor2;
		delete[]m_bird;
	}
	/*void loadGame(istream);
	void saveGame(istream);
	void pauseGame(HANDLE);
	void resumeGame(HANDLE);*/
	void updatePosPeople(char key)
	{
		if (key == 'W' || key ==  72)
			m_people->up();

		else if (key == 'A' || key == 75)
			m_people->left();

		else if (key == 'S' || key == 80)
			m_people->down();

		else if (key == 'D' || key == 77)
			m_people->right();
	}; //Thực hiện điều khiển di chuyển của CPEOPLE
	void updatePosVehicle()
	{
		int i;
		for (i = 0; i < numOfTrucks; ++i)
		{
			m_truck1[i].move();
			m_truck2[i].move();
		}
		for (i = 0; i < numOfCars; ++i)
		{
			m_car1[i].move();
			m_car2[i].move();
		}
	}; 
	void updatePosAnimal() {
		int i;
		for (i = 0; i < numOfDinosaurs; ++i)
		{
			m_dinausor1[i].move();
			m_dinausor2[i].move();
		}
		for (i = 0; i < numOfBirds; ++i)
			m_bird[i].move();
	};
};