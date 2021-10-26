#include "dinosaur.h"
void dinosaur::selfDraw()
{
	int row = mY - height + 1;
	int i = row, j;
	for (; row <= mY; row++)
	{
		for (j = 0; j < width; j++)
		{
			if (mX + j < LEFT)
			{
				GotoXY(mX + j + (RIGHT - LEFT + 1), row);
				cout << form[row - i][j];
			}
			else if (mX + j > RIGHT)
			{
				GotoXY(mX + j - (RIGHT - LEFT + 1), row);
				cout << form[row - i][j];
			}
			else
			{
				GotoXY(mX + j, row);
				cout << form[row - i][j];
			}
		}
	}
}
void dinosaur::move() {
	mX += mSpeed;
	if (mX >= RIGHT)
		mX = mX + LEFT - RIGHT + 1;
	if (mX <= LEFT - width + 1)
		mX = mX - (LEFT - RIGHT + 1);
}
void dinosaur::clearPath()
{
	int x1, y1;
	y1 = mY - height + 1;
	x1 = mX;
	int i = 0;
	if (mX - width + 1 < LEFT)
	{
		for (int j = 0; j < height; j++)
		{
			GotoXY(RIGHT, y1 + j);
			cout << " ";
			GotoXY(RIGHT - 1, y1 + j);
			cout << " ";
		}
	}
	for (; i < height; i++)
	{
		GotoXY(x1 - 1, y1 + i);
		cout << " ";
	}
}
dinosaur& dinosaur::operator=(const dinosaur& d)
{
	Animal::operator=(d);
	return *this;
}