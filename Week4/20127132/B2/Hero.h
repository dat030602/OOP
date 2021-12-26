#pragma once
#include "Skill.h"

class Hero
{
	string heroName;
	unsigned int heroHealth;
	unsigned int heroMana;
	unsigned int heroLevel;
	vector<Skill*> skillList;
public:
	Hero();
	Hero(string, unsigned int, unsigned int, unsigned int, vector<Skill*>);
	Hero(const Hero&);
	~Hero();
	friend ostream& operator<<(ostream& os, Hero obj);
	friend istream& operator>>(istream& is, Hero& obj);
	void deleteSkill(int);
	string getHeroName() { return heroName; }
	unsigned int getHeroHealth() { return heroHealth; }
	unsigned int getHeroMana() { return heroMana; }
	unsigned int getHeroLevel() { return heroLevel; }
	vector<Skill*> getSkillList() { return skillList; }
	void setHeroName(string heroName) { this->heroName = heroName; }
	void setHeroHealth(unsigned int heroHealth) { this->heroHealth = heroHealth; }
	void setHeroMana(unsigned int heroMana) { this->heroMana = heroMana; }
	void setHeroLevel(unsigned int heroLevel) { this->heroLevel = heroLevel; }
	void setSkillList(vector<Skill*> skillList) { this->skillList = skillList; }
};

void createList(vector<Hero>& HeroList);