#include "Hero.h"
#include "Skill.h"

Hero::Hero()
{
	heroName = "";
	heroHealth = heroMana = 0;
	heroLevel = 1;
}

Hero::Hero(string heroName, unsigned int heroHealth, unsigned int heroMana, unsigned int heroLevel, vector<Skill*> skillList)
{
	this->heroName = heroName;
	this->heroHealth = heroHealth;
	this->heroMana = heroMana;
	this->heroLevel = heroLevel;
	this->skillList = skillList;
}

Hero::Hero(const Hero& temp)
{
	this->heroName = temp.heroName;
	this->heroHealth = temp.heroHealth;
	this->heroMana = temp.heroMana;
	this->heroLevel = temp.heroLevel;
	this->skillList = temp.skillList;
}

Hero::~Hero()
{
	heroName = "";
	heroHealth = heroMana = heroLevel = 0;
}

istream& operator>>(istream& is, Hero& obj)
{
	cout << "Input Name of Champion: ";
	is.ignore();
	getline(is, obj.heroName);
	cout << "Input Health of Champion: ";
	is >> obj.heroHealth;
	cout << "Input Mana of Champion: ";
	is >> obj.heroMana;
	cout << "Input Level of Champion: ";
	is >> obj.heroLevel;
	int size;
	cout << "Input Quantity Skill: ";
	cin >> size;
	for (int i = 0; i < size; i++)
	{
		Skill* skill = new Skill();
		is >> *skill;
		obj.skillList.push_back(skill);
	}
	return is;
}
ostream& operator<<(ostream& os, Hero obj)
{
	bool a = false;
	int size = obj.skillList.size();
	cout << "Name of Champion: " << obj.heroName << endl;
	cout << "Health of Champion: " << obj.heroHealth << endl;
	cout << "Mana of Champion: " << obj.heroMana << endl;
	cout << "Level of Champion: " << obj.heroLevel << endl;
	for (int i = 0; i < size; i++)
	{
		if (obj.skillList[i]->getSkillLevel() <= obj.heroLevel)
		{
			os << "Skill " << i + 1 << ":\n" << *obj.skillList[i] << endl;
			a = true;
		}
	}
	if (!a)
		os << "No skills to learn\n";
	return os;
}

void Hero::deleteSkill(int n)
{
	if (n >= skillList.size())
		skillList.clear();
	else
		for (int i = 0; i < n; i++)
			skillList.pop_back();
}

void createList(vector<Hero>& HeroList)
{
	string nameHero;
	unsigned int heroHealth;
	unsigned int heroMana;
	unsigned int heroLevel;

	string nameskill;
	unsigned int level;

	fstream fi;
	fi.open("hero.txt", ios::in);
	while (!fi.eof())
	{
		Hero q;
		vector<Skill*> skillList;
		getline(fi, nameHero, '\n');
		fi >> heroHealth;
		//getline(fi, nameskill, '\n');
		fi >> heroMana;
		//getline(fi, nameskill, '\n');
		fi >> heroLevel;
		getline(fi, nameskill, '\n');
		//cout << nameHero << endl << heroHealth << endl << heroMana << endl << heroLevel << endl;
		q.setHeroName(nameHero);
		q.setHeroHealth(heroHealth);
		q.setHeroMana(heroMana);
		q.setHeroLevel(heroLevel);

		for (int i = 0; i < 4; i++)
		{
			getline(fi, nameskill, '\n');
			fi >> level;
			skillList.push_back(new Skill(nameskill, level));
			getline(fi, nameskill, '\n');
		}
		q.setSkillList(skillList);

		HeroList.push_back(q);
		//getline(fi, nameskill, '\n');
	}
	fi.close();
	return;
}