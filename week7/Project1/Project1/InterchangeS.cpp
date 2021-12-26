#include "InterchangeS.h"

void InterchangeS::Process(vector<float>& a)
{
	int i, j;
	int n = a.size();
	for (i = 0; i < n - 1; i++) {
		for (j = i + 1; j < n; j++) {
			if (a[i] > a[j]) {
				swap(a[i], a[j]);//hoán vị a[i] và a[j]
			}
		}
	}

}