#include "LoadExpression.h"

int LoadMathExpression(string* mathExprStr)
{
	*mathExprStr = "";
	cout << "Input Math expression: ";
	getline(cin, *mathExprStr);

	if (mathExprStr->length() > 0)
		return 0;
	else
		return 1;
}
