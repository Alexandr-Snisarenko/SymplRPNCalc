#include "ShowResults.h"

void ShowCalcResults(string mathExpStr, string rpnExpStr, double calcRes)
{
	cout << endl;
	cout << "Given Expression: " << mathExpStr << endl;
	cout << "Revers Poland Notation: " << rpnExpStr << endl;
	cout << "Result of expression: " << calcRes << endl;
}

void ShowErrorMsg(string errMsg)
{
	cout << endl;
	cout << "Error!: " << errMsg << endl;
}
