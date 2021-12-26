#include "Hero.h"
#include "Skill.h"

int main()
{
	vector<Hero> heroList;
	createList(heroList);
	int choose;
	while (1)
	{
		cout << "Let's choose\n";
		cout << "1. Add Hero\n";
		cout << "2. Display Hero List\n";
		cout << "3. Display Hero\n";
		cout << "4. Delete Skill of Champion\n";
		cout << "5. Exit\n";
		cout << "Input your choice: ";
		cin >> choose;
		if (choose == 1)
		{
			Hero hero;
			cin >> hero;
			heroList.push_back(hero);
		}
		else if (choose == 2)
		{
			int size = heroList.size();
			for (int i = 0; i < size; i++)
				cout << heroList[i] << endl;
		}
		else if (choose == 3)
		{
			bool a = false;
			cout << "Input Name of Champion: ";
			string name;
			cin.ignore();
			getline(cin, name);
			int size = heroList.size();
			for (int i = 0; i < size; i++)
				if (heroList[i].getHeroName() == name)
				{
					cout << heroList[i] << endl;
					a = true;
					break;
				}
			if (!a)
				cout << "Champion Not Found!\n";
		}
		else if (choose == 4)
		{
			bool a = false;
			int n;
			cout << "Input Quantity want to delete: ";
			cin >> n;
			cout << "Input Name of Champion: ";
			string name;
			cin.ignore();
			getline(cin, name);
			int size = heroList.size();
			for (int i = 0; i < size; i++)
				if (heroList[i].getHeroName() == name)
				{
					heroList[i].deleteSkill(n);
					a = true;
					break;
				}
			if (!a)
				cout << "Champion Not Found!\n";
			else
				cout << "Deleted! \n";
		}
		else if (choose == 5)
			break;
		cout << endl;
	}
	return 0;
}