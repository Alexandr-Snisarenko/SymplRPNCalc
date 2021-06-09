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




int main()
{
  
    string calcRes = "";
    string mathExpStr = "";
    string rpnExpStr = "";
    queue<string> rpnQu;
    string errMsg = "";
    int exitCode = 0;
    int err = 0;
    cout << "Application" << endl;

    while (exitCode != 27) //Esc
    {
        calcRes = "";
        mathExpStr = "";
        rpnExpStr = "";
        rpnQu = {};

        while (1) //try / catch
        {
            if (err = LoadMathExpression(&mathExpStr))
            {
                errMsg = "Expression is empty";
                break;
            }

            if (err = MathExpressionSyntaxCheck(mathExpStr, &errMsg))
                break;

            if (err = ConvertMatExpresToRPN(mathExpStr, &rpnExpStr, &rpnQu))
            {
                errMsg = (string) "Error with convert math expression to RPN: " + rpnExpStr;
                break;
            }

            break;
        }

        err = CalcRpnExpression(rpnQu, &calcRes,  &errMsg);

        ShowCalcResults(mathExpStr, rpnExpStr, calcRes);


        cout << "For exit press 'Esc'. For continue press anykey";
        exitCode = _getch();
        cout << endl;
    }

      
 

//    system("pause");
}



