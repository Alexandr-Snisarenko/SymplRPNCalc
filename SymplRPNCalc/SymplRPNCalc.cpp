#include <iostream>
#include <string>
#include <conio.h>
#include <queue>
#include "LoadExpression.h"
#include "SyntaxCheck.h"
#include "ConverMathToRPN.h"
#include "CalcRpnExpression.h"
#include "ShowResults.h"
using namespace std;

/////////////Основная программа

int main()
{
  
    double calcRes = 0; //результат вычисления выражения
    string mathExpStr = ""; //исходная строка выражения
    string rpnExpStr = ""; //строка выражения в обратной польской нотации
    queue<string> rpnQu; //очредь с токенами выражения в RPN
    string errMsg = ""; // сообщение об ошибке 
    int exitCode = 0; //код для завершения программы (ESC) 
    int err = 0; //код ошибки

    cout << "This application evaluates an arbitrary mathematical expression using reverse Polish notation." << endl;
    cout << "The original expression can only contain: integers, simple operations(+-*/ ) and parentheses." << endl;
    cout << "For example: 4-2*(10-3*2)+15-7" << endl;

    while (exitCode != 27) //Выход по клавише "Esc"
    {
        // начальная инициализация переменных
        calcRes = 0;
        mathExpStr = "";
        rpnExpStr = "";
        rpnQu = {};

        //основной блок программы с эмуляцией прерываний
        while (1) //try / catch
        {
            //загрузка исходного выражения
            if (err = LoadMathExpression(&mathExpStr))
            {
                errMsg = "Expression is empty";
                break;
            }

            //синтаксический анализ строки исходного выражения
            if (err = MathExpressionSyntaxCheck(mathExpStr, &errMsg))
                break;

            //конвертация исходного мат. выражения в обратную польскую нотацию. На выходе строка выражения в RPN  нотации и очередь с токенами выражения в RPN нотации
            if (err = ConvertMatExpresToRPN(mathExpStr, &rpnExpStr, &rpnQu))
            {
                errMsg = (string) "Error with convert math expression to RPN: " + rpnExpStr;
                break;
            }

            //вычисление выражения записанного в обратной польской нотации (на входе очередь с токенами выражения в RPN нотации) 
            err = CalcRpnExpression(rpnQu, &calcRes, &errMsg);

            break;
        }

        //если были ошибки - отображаем сообщене об ошибке
        if (err)
            ShowErrorMsg(errMsg);
        else //если ошибок нет - отображаем результат вычислений
            ShowCalcResults(mathExpStr, rpnExpStr, calcRes);

        //следующий цикл вычислений. для выхода ждем символ 'esc', для продолжения - любой другой символ
        cout << "For exit press 'Esc'.  For continue press anykey.";
        exitCode = _getch();
        cout << endl;
    }

}



