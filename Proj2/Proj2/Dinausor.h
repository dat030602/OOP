#pragma once
#include "Animal.h"

class Dinausor : public Animal
{
public:
	static const char form[][5];
	static const int width = 5, height = 3;
public:
	Dinausor() {};
	Dinausor(int, int) {};
	Dinausor(const Dinausor&) {};
	~Dinausor() {};
public:
	virtual void selfDraw();
	void move();
	void clearPath();
	Dinausor& operator=(const Dinausor& d);
};