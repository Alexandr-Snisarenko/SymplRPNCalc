#include "CalcRpnExpression.h"

//Глобальные константы
const char cOper[] = "+-*/";

int CalcRpnExpression(queue<string> rpnQu, double* calcRes, string* errMsg)
{
	double res = 0; //для результов промежуточных вычислений
	double n1, n2; //для промежуточных значений операндов при вычислении операций
	int err = 0; //код ошибки
	string curTok = ""; //текущий токен
	stack <string> expStk; //рабочий стек для обработки выражения

	//віполняем обработку очереди, которая содержит выражением в порядке RPN 
	while (!rpnQu.empty())
	{
		//берем токен из очереди
		curTok = rpnQu.front();
		rpnQu.pop();
		
		//если токен - не операция - помещаем его в рабочий стек (т.о. в стеке будут только числа)
		if (strchr(cOper, curTok[0]) == NULL)
		{
			expStk.push(curTok);
		}
		else //иначе, если текущий токен - операция, то выполняем текущую операцию над двума крайними значениями из рабочего стека
		{
			//если в стеке меньше двух элементов - что то пошло не так
			if (expStk.size() < 2)
			{
				err = 1;
				*errMsg = "Expression error.";
				break;
			}

			//получаем элементы из стека и переводим их в дабл
			n2 = stod(expStk.top());
			expStk.pop();
			n1 = stod(expStk.top());
			expStk.pop();

			//выполнение операций в зависимости от значения текущего оператора
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

	//Получаем результат. Должен быть в стеке в первом (нулевом) и единственном элементе стека. Если это не так - ошибка.
	if (expStk.size() != 1)
	{
		err = 1;
		*errMsg = "Expression error (operStack not empty)";
	}
	else
	{
		*calcRes = stod(expStk.top());
	}


	return err;
}

