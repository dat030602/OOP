#ifndef ProgramFrame_HEADER
#define ProgramFrame_HEADER

#include <iostream>
#include <vector>

using namespace std;

class ProgramFrame
{
protected:
	virtual void startMessage(ostream&);
	virtual void Input(istream&) = 0;
	virtual bool Check() = 0;
	virtual void errorMessage(ostream&);
	virtual void Output(ostream&) = 0;
	virtual void Process() = 0;
	virtual bool askContinue(istream&, ostream&);
public:
	ProgramFrame() {};
	~ProgramFrame() {};

	void run(istream&, ostream&);
	friend istream& operator>>(istream& is, vector<float> a);
	friend ostream& operator<<(ostream& os, vector<float> a);
};


#endif