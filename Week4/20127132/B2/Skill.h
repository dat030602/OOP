#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Skill
{
	string skillName;
	unsigned int skillLevel;
public:
	Skill();
	Skill(string, unsigned int);
	Skill(const Skill&);
	~Skill();
	string getSkillName();
	unsigned int getSkillLevel();
	void setSkillName(string skillName);
	void setSkillLevel(unsigned int skillLevel);
	friend istream& operator>>(istream& is, Skill& obj);
	friend ostream& operator<<(ostream& os, Skill obj);
};
