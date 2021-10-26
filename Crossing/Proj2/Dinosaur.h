#pragma once
#include "Animal.h"

class dinosaur : public Animal
{
public:
	static const char form[][5];
	static const int width = 5, height = 3;
public:
	dinosaur() {};
	dinosaur(int, int) {};
	dinosaur(const dinosaur&) {};
	~dinosaur() {};
public:
	virtual void selfDraw();
	void move();
	void clearPath();
	dinosaur& operator=(const dinosaur& d);
};