#include "ConverMathToRPN.h"
#include <queue>

//Глобальные константы
const char cNumber[] = "1234567890";//цифры
const char cOper[] = "+-*/";//операторы
const char cOper1[] = "+-";//операторы нижнего приоритета
const char cOper2[] = "*/";//операторы верхнего приоритета
const char cPrnts[] = "()";//скобки


int ConvertMatExpresToRPN(string mathExpStr, string* pRpnExpStr, queue<string>* pRpnQu)
{

	int is_OpenPrnts = 0;
	int err = 0;
	queue<string> rpnQu; //очередь с результатом разбора строки в польскую нотацию
	string numStr = ""; //строка для формирования отдельных операндов из входной строки с мат. выражением
	stack <char> depoStk; //рабочий "депо" стек. для временного хранения операторов

	pRpnExpStr->clear();
	*pRpnQu = {};

	//обход строки с мат выражением
	for (char curChr : mathExpStr)
	{
		//если текущий символ - число - добавляем его к строке numStr
		if (strchr(cNumber, curChr) != NULL)
			numStr += curChr;
		else  // если текущий сивол не число, то, если строка numStr не пустая, переносим её в rpn очередь и очищаем строку numStr
			if (!numStr.empty())
			{
				rpnQu.push(numStr);
				numStr.clear();
			}

		//если текущий символ - левая скобка - в стек "депо"
		if (curChr == '(')
			depoStk.push(curChr);

		//если текущий символ - правая скобка 
		if (curChr == ')')
		{
			//то пока не встретиться левая скобка переносим операторы из депо стека в rpn очередь 
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
			
			//удаляем левую скобку из депо стека
			depoStk.pop();
		}

		//если текущий символ - оператор 
		if (strchr(cOper, curChr) != NULL)
		{
			//если депо стек не пустой и крайний элемент - опреатор
			if (!depoStk.empty() and strchr(cOper, depoStk.top()) != NULL)
			{
				//то, если текущий оператор нижнего приоритета или 
				// (текущий оператор верхнего приоритета и в стеке крайний элемент - оператор верхнего приоритета), то
				// переносим крайний элемент (оператор) из депо стека в rpn очередь
				if ((strchr(cOper1, curChr) != NULL) or
					(strchr(cOper2, curChr) != NULL and strchr(cOper2, depoStk.top()) != NULL))
				{
					rpnQu.push(string(1, depoStk.top()));
					depoStk.pop();
				}
			}

			//текущий оператор помещаем в рабочий стек
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
