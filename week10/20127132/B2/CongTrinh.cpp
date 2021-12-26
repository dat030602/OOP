#include "CongTrinh.h"

CongTrinh::CongTrinh()
{
	name = "";
	heal = 0;
	dame = 0;
	def = 0;
}

CongTrinh::~CongTrinh()
{
	name = "";
	heal = 0;
	dame = 0;
	def = 0;
}

CongTrinh::CongTrinh(const CongTrinh& ps)
{
	this->name = ps.name;
	this->heal = ps.heal;
	this->dame = ps.dame;
	this->def = ps.def;
}

CongTrinh::CongTrinh(string name, int heal, int dame, int def)
{
	this->name = name;
	this->heal = heal;
	this->dame = dame;
	this->def = def;
}
void CongTrinh::setPos(int x, int y)
{
	this->x = x;
	this->y = y;
}
int CongTrinh::X() 
{ 
	return x; 
}
int CongTrinh::Y() 
{ 
	return y; 
}
string CongTrinh::GetName()
{
	return name;
}
int CongTrinh::GetHeal()
{
	return heal;
}
int CongTrinh::GetDame()
{
	return dame;
}
int CongTrinh::GetDef()
{
	return def;
}

bool CongTrinh::LinhDef()
{
	return dame < def;
}