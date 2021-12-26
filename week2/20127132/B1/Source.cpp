#include "MainHeader.h"
bool checkName(string s)
{
	int size = s.size();
	for (int i = 0; i < size; i++)
	{
		if (!((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122)))
			if (s[i] != ' ')
				return false;
	}
	return true;
}
bool checkPhone(string s)
{
	int size = s.size();
	for (int i = 0; i < size; i++)
		if (!(s[i] >= 48 && s[i] <= 57))
			return false;
	return true;
}