#include "SyntaxCheck.h"


//Глобальные константы
const char cLegalChr[] = "1234567890+-*/()"; //список допустимых символов
const char cNumber[] = "1234567890"; //цифры
const char cOper[] = "+-*/"; //операторы
const char cPrnts[] = "()"; //скобки

// проверка на недопустимые комбинации символов
int CheckMathSymbolCombination(char curChr, char prevChr, string* errMsg )
{
	int err = 0;
	while (true)
	{
		// 2 оператора подряд
		if (strchr(cOper, curChr) != NULL and strchr(cOper, prevChr) != NULL)
		{
			*errMsg = (string)"Double operators" + curChr + prevChr;
			err = 1;
			break;
		}
		//число перед левой скобкой 
		if (curChr == cPrnts[0] and strchr(cNumber, prevChr) != NULL)
		{
			*errMsg = (string)"Number before left parenthesis";
			err = 1;
			break;
		}
		//число после правой скобкой 
		if (strchr(cNumber, curChr) != NULL and prevChr == cPrnts[1])
		{
			*errMsg = (string)"Number after right parenthesis";
			err = 1;
			break;
		}
		//оператор перед правой скобкой 
		if (curChr == cPrnts[1] and strchr(cOper, prevChr) != NULL)
		{
			*errMsg = (string)"Operator before right parenthesis";
			err = 1;
			break;
		}
		//оператор после левой скобкой 
		if (strchr(cOper, curChr) != NULL and prevChr == cPrnts[0])
		{
			*errMsg = (string)"Operator after left parenthesis";
			err = 1;
			break;
		}

		break;
	}
	return err;

}


int MathExpressionSyntaxCheck(string mathStr, string* pErrMsg)
{


	int cntLeftLPrnts = 0; //кол-во левых скобок
	int cntRightPrnts = 0; //кол-во правых скобок
	int err = 0;
	char prevChr = NULL; //переменная для предыдущего символа при анализе последовательности символов
	*pErrMsg = "";
	
	//обход строки выражения
	for (char curChr : mathStr)
	{
		//проверяем на допустимые символы
		if (strchr(cLegalChr, curChr) == NULL)
		{
			*pErrMsg = (string) "Unexpected symbol:'" + curChr + "'";
			err = 1; 
			break;
		}

		//проверка первого символа. если оператор - ошибка
		if (strchr(cOper, mathStr[0]) != NULL)
		{
			*pErrMsg = (string)"First symbol is Operator.";
			err = 1;
			break;
		}

		//проверка крайнего символа. если оператор - ошибка
		if (strchr(cOper, mathStr[mathStr.length()-1]) != NULL)
		{
			*pErrMsg = (string)"Last symbol is Operator.";
			err = 1;
			break;
		}

		//если есть предыдущий символ - проверяем на допустимые комбинации символов
		if (prevChr != NULL and (err = CheckMathSymbolCombination(curChr, prevChr, pErrMsg)))
			break;

		//считаем скобки
		if (curChr == '(') 
			cntLeftLPrnts++;
		if (curChr == ')') 
			cntRightPrnts++;
		
		//если правых скобок больше чем левых - нарушение порядка скобок
		if (cntRightPrnts > cntLeftLPrnts)
		{
			*pErrMsg = (string)"Error of parentheses combinatios (right parenthesis before left parenthesis).";
			err = 1;
			break;
		}

		prevChr = curChr;
	}// main for
	
	if (err == 0)
	{
		//проверяем количество левых и правых скобок
		if (cntLeftLPrnts != cntRightPrnts)
		{
			*pErrMsg = (string)"Count of left parentheses not equal to count of rihgt parentheses.";
			err = 1;
		}

	}

	return err;
}
