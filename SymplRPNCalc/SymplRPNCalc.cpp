#include <iostream>
#include <string>
#include <conio.h>
#include "LoadExpression.h"
#include "SyntaxCheck.h"
#include "ConverMathToRPN.h"
#include "CalcRpnExpression.h"
using namespace std;


int main()
{
  
    string resStr = "";
    string mathExpStr = "";
    string rpnExpStr = "";
    string errMsg = "";
    int exitCode = 0;
    int err = 0;

    while (exitCode != 27) //Esc
    {
        while (1)
        {
            if (err = LoadMathExpression(&mathExpStr))
            {
                errMsg = "Expression is empty";
                break;
            }

            if (err = MathExpressionSyntaxCheck(mathExpStr, &errMsg))
                break;

            ConvertMatExpresToRPN(mathExpStr, &rpnExpStr);
            

            break;
        }

        resStr = CalcRpnExpression(rpnExpStr, &errMsg);

        cout << mathExpStr<<endl;
        cout << rpnExpStr << endl;

        
        cout << err << endl;
        cout << errMsg << endl;


        cout << resStr << endl;

        cout << "For exit press 'Esc'. For continue press anykey";
        exitCode = _getch();
        cout << endl;
    }

      
 

//    system("pause");
}



