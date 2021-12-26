#include "Skill.h"

Skill::Skill()
{
	skillName = "";
	skillLevel = 1;
}

Skill::Skill(string skillName, unsigned int skillLevel)
{
	this->skillName = skillName;
	this->skillLevel = skillLevel;
}

Skill::Skill(const Skill& temp)
{
	this->skillName = temp.skillName;
	this->skillLevel = temp.skillLevel;
}

Skill::~Skill()
{
	skillName = "";
	skillLevel = 0;
}

string Skill::getSkillName()
{
	return skillName;
}

unsigned int Skill::getSkillLevel()
{
	return skillLevel;
}

void Skill::setSkillName(string skillName)
{
	this->skillName = skillName;
}

void Skill::setSkillLevel(unsigned int skillLevel)
{
	this->skillLevel = skillLevel;
}

istream& operator>>(istream& is, Skill& obj)
{
	cout << "Input name of skill: ";
	is.ignore();
	getline(is, obj.skillName);
	cout << "Input level of skill: ";
	is >> obj.skillLevel;
	return is;
}

ostream& operator<<(ostream& os, Skill obj)
{
	os << "\tName: " << obj.skillName << endl;
	os << "\tLevel: " << obj.skillLevel << endl;
	return os;
}