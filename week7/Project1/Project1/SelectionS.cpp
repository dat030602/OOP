#pragma one
#include "SelectionS.h"

void swap(float* xp, float* yp)
{
	float temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void SelectionS::Process(vector<float>& a)
{
	int i, j, min_idx;
	int n = a.size();
	for (i = 0; i < n - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (a[j] < a[min_idx])
				min_idx = j;
		swap(&a[min_idx], &a[i]);
	}
}