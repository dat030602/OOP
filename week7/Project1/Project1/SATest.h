#ifndef SATest_HEADER
#define SATest_HEADER
#pragma one
#include "ProgramFrame.h"
#include "SortArray.h"

istream& operator>>(istream& is, vector<float>& a);
ostream& operator<<(ostream& os, vector<float>& a);

class SATest : public ProgramFrame
{
	SortArray* mAlg;
	vector<float> Data;
public:
	SATest(SortArray* pAlg) { mAlg = pAlg; }
	void Input(istream& is); //còn đỏ
	void Output(ostream& os);
	bool Check();
	void startMessage(ostream& os);
	void Process();
};

#endif