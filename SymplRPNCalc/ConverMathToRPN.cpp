#include "ConverMathToRPN.h"
#include <queue>

//Глобальные константы
const char cNumber[] = "1234567890";
const char cOper[] = "+-*/";
const char cOper1[] = "+-";
const char cOper2[] = "*/";
const char cPrnts[] = "()";


int ConvertMatExpresToRPN(string mathExpStr, string* pRpnExpStr, queue<string>* pRpnQu)
{

	int is_OpenPrnts = 0;
	int err = 0;
	queue<string> rpnQu;
	string numStr = "";
	stack <char> depoStk;

	pRpnExpStr->clear();
	*pRpnQu = {};

	for (char curChr : mathExpStr)
	{
		if (strchr(cNumber, curChr) != NULL)
			numStr += curChr;
		else
			if (!numStr.empty())
			{
				rpnQu.push(numStr);
				numStr.clear();
			}

		if (curChr == '(')
			depoStk.push(curChr);

		if (curChr == ')')
		{
			while (depoStk.top() != '(')
			{
				rpnQu.push(string(1, depoStk.top()));
 				depoStk.pop();

				if (depoStk.empty())
				{
					err = 1;
					*pRpnExpStr = "expression error";
					break;
				}

			}

			if (!depoStk.empty())
				depoStk.pop();
		}

		if (strchr(cOper, curChr) != NULL)
		{

			if (!depoStk.empty() and strchr(cOper, depoStk.top()) != NULL)
			{

				if ((strchr(cOper1, curChr) != NULL) or
					(strchr(cOper2, curChr) != NULL and strchr(cOper2, depoStk.top()) != NULL))
				{
					rpnQu.push(string(1, depoStk.top()));
					depoStk.pop();
				}
			}

			depoStk.push(curChr);
		}


		if (err) break;
	}

	//переносим в RPN очередь крайнее число исходной строки (если крайняя скобка - то будет пустым)
	if (!numStr.empty())
		rpnQu.push(numStr);
	
	//переносим оставшиеся операторы из "депо" в RPN очередь
	while (!depoStk.empty())
	{
		rpnQu.push(string(1, depoStk.top()));
		depoStk.pop();
	}

	*pRpnQu = rpnQu;

	//RPN очередь - в строку
	while (!rpnQu.empty())
	{
		pRpnExpStr->append(rpnQu.front() + string(1, ' '));
		rpnQu.pop();
	}

	return err;
}
