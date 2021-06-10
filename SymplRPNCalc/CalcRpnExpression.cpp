#include "CalcRpnExpression.h"

<<<<<<< HEAD
//Глобальные константы
const char cOper[] = "+-*/";

int CalcRpnExpression(queue<string> rpnQu, string* calcRes, string* errMsg)
{
	double res = 0;
	double n1, n2;
	int err = 0;
	string curTok = "";
	stack <string> expStk;

	while (!rpnQu.empty())
	{
		curTok = rpnQu.front();
		rpnQu.pop();
		
		if (strchr(cOper, curTok[0]) == NULL)
		{
			expStk.push(curTok);
		}
		else
		{
			string numStr;
			
			if (expStk.size() < 2)
			{
				err = 1;
				*errMsg = "Expression error.";
				break;
			}

			numStr = expStk.top();
			n2 = stod(numStr);
			expStk.pop();
			numStr = expStk.top();
			n1 = stod(numStr);
			expStk.pop();

			switch (curTok[0])
			{
				case '+':
					res = n1 + n2;
					expStk.push(to_string(res));
					break;
				case '-':
					res = n1 - n2;
					expStk.push(to_string(res));
					break;
				case '*':
					res = n1 * n2;
					expStk.push(to_string(res));
					break;
				case '/':
					if (n2 == 0)
					{
						err = 1;
						*errMsg = "Division on zero";
						break;
					}
					res = n1 / n2;
					expStk.push(to_string(res));
					break;
				default:
					err = 1;
					*errMsg = "Unexpected operator.";
					break;
			}


			if (err)
				break;
		}
	} //while

	if (expStk.size() != 1)
	{
		err = 1;
		*errMsg = "Expression error (operStack not empty)";
	}
	else
	{
		*calcRes = expStk.top();
	}


	return err;
}

=======
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
>>>>>>> bc41a2ed52eeeeff2fb9d76254e9f1d2c3ff8cff
