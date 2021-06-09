#include "CalcRpnExpression.h"

string CalcRpnExpression(string rpnExpStr, string* pErrMsg)
{
	double res;
	string str = "";
	stack <string> expStk;

	for (char curChr : rpnExpStr)
	{
		if (curChr == ' ')
		{
			expStk.push(str);
			str = "";
		}
		else
		{
			str += curChr;
		}
	}



	return string();
}
