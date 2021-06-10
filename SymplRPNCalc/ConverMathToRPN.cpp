#include "ConverMathToRPN.h"
<<<<<<< HEAD
=======
#include <queue>

>>>>>>> bc41a2ed52eeeeff2fb9d76254e9f1d2c3ff8cff

//Глобальные константы
const char cNumber[] = "1234567890";
const char cOper[] = "+-*/";
const char cOper1[] = "+-";
const char cOper2[] = "*/";
const char cPrnts[] = "()";


<<<<<<< HEAD
int ConvertMatExpresToRPN(string mathExpStr, string* pRpnExpStr, queue<string>* pRpnQu)
=======

int ConvertMatExpresToRPN(string mathExpStr, string* pRpnExpStr)
>>>>>>> bc41a2ed52eeeeff2fb9d76254e9f1d2c3ff8cff
{

	int is_OpenPrnts = 0;
	int err = 0;
<<<<<<< HEAD
	queue<string> rpnQu;
	string numStr = "";
	stack <char> depoStk;


	pRpnExpStr->clear();
	*pRpnQu = {};

=======
	string numStr = "";
	queue <string> rpnQu;
	stack <char> depoStk;

>>>>>>> bc41a2ed52eeeeff2fb9d76254e9f1d2c3ff8cff
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

<<<<<<< HEAD
	//переносим в RPN очередь крайнее число исходной строки (если крайняя скобка - то будет пустым)
	if (!numStr.empty())
		rpnQu.push(numStr);
	
	//переносим оставшиеся операторы из "депо" в RPN очередь
=======

	if (!numStr.empty())
		rpnQu.push(numStr);

>>>>>>> bc41a2ed52eeeeff2fb9d76254e9f1d2c3ff8cff
	while (!depoStk.empty())
	{
		rpnQu.push(string(1, depoStk.top()));
		depoStk.pop();
	}

<<<<<<< HEAD
	*pRpnQu = rpnQu;

	//RPN очередь - в строку
	while (!rpnQu.empty())
	{
		pRpnExpStr->append(rpnQu.front() + string(1, ' '));
		rpnQu.pop();
	}

	return err;
=======
	while (!rpnQu.empty())
	{
		*pRpnExpStr += rpnQu.front() + string(1, ' ');
		rpnQu.pop();
	}




	return 0;
>>>>>>> bc41a2ed52eeeeff2fb9d76254e9f1d2c3ff8cff
}
