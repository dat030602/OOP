#pragma once
#include "MainHeader.h"
#include "Animal.h"
#include "Vehicle.h"
#include "Truck.h"
#include "Car.h"
#include "Bird.h"
#include "Dinausor.h"

class People
{
public:
	static const char form[][3];
	static const int width = 3;
	static const int height = 3;
protected:
	int mX, mY;
	//int mSpeed;
	bool mState;

	void copyPeople(const People& p);
public:
	People();
	People(int, int);
	~People() {}
	People(const People&);
	int X() { return mX; }
	int Y() { return mY; }
	void selfDraw();
	void clearPath(char);
	void reloadConsole(static const int posY[]);
	void setPos(int, int);
	//void tell();
	void up();
	void down();
	void left();
	void right();
	bool isImpact(const Animal*, int, bool);
	bool isImpact(const Vehicle*, int, bool);
	bool isFinish() { return mY <= TOP + 2; }
	bool isDead() { return mState == false; }
	void dead() { mState = false; }
};