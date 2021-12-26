#include "Linh.h"

Linh::Linh()
{
	name = "";
	heal = 0;
	dame = 0;
	def = 0;
}

Linh::~Linh()
{
	name = "";
	heal = 0;
	dame = 0;
	def = 0;
}

Linh::Linh(const Linh& ps)
{
	this->name = ps.name;
	this->heal = ps.heal;
	this->dame = ps.dame;
	this->def = ps.def;
}

Linh::Linh(string name, int heal, int dame, int def, int x, int y)
{
	this->name = name;
	this->heal = heal;
	this->dame = dame;
	this->def = def;
	this->x = x;
	this->y = y;
}

void Linh::setPos(int x, int y)
{
	this->x = x;
	this->y = y;
}

int Linh::X() 
{
	return x; 
}

int Linh::Y() 
{ 
	return y; 
}

int Linh::GetDame()
{
	return dame;
}

// Tấn công quái
bool Linh::battle(int dame)
{
	heal = heal - dame + def;
	return heal <= 0;
}

string Linh::GetName()
{
	return name;
}