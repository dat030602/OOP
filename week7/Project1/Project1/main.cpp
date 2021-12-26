#include "ProgramFrame.h"
#include "SATest.h"
#include "InsertionS.h"
#include "InterchangeS.h"
#include "SelectionS.h"
#include "SortArray.h"

int main()
{
	cout << "Selection Sort:\n";
	SATest SATest1(new SelectionS());
	SATest1.run(cin, cout);

	cout << "\nInsertion Sort:\n";
	SATest SATest2(new InsertionS());
	SATest2.run(cin, cout);

	cout << "\Interchange Sort:\n";
	SATest SATest3(new InterchangeS());
	SATest3.run(cin, cout);
	return 0;
}