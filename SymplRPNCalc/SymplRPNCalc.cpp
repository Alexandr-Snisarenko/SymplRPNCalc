#include <iostream>
#include <string>
#include <conio.h>
<<<<<<< HEAD
#include <queue>
=======
>>>>>>> bc41a2ed52eeeeff2fb9d76254e9f1d2c3ff8cff
#include "LoadExpression.h"
#include "SyntaxCheck.h"
#include "ConverMathToRPN.h"
#include "CalcRpnExpression.h"
<<<<<<< HEAD
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
=======
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
>>>>>>> bc41a2ed52eeeeff2fb9d76254e9f1d2c3ff8cff
        {
            if (err = LoadMathExpression(&mathExpStr))
            {
                errMsg = "Expression is empty";
                break;
            }

            if (err = MathExpressionSyntaxCheck(mathExpStr, &errMsg))
                break;

<<<<<<< HEAD
            if (err = ConvertMatExpresToRPN(mathExpStr, &rpnExpStr, &rpnQu))
            {
                errMsg = (string) "Error with convert math expression to RPN: " + rpnExpStr;
                break;
            }
=======
            ConvertMatExpresToRPN(mathExpStr, &rpnExpStr);
            
>>>>>>> bc41a2ed52eeeeff2fb9d76254e9f1d2c3ff8cff

            break;
        }

<<<<<<< HEAD
        err = CalcRpnExpression(rpnQu, &calcRes,  &errMsg);

        ShowCalcResults(mathExpStr, rpnExpStr, calcRes);

=======
        resStr = CalcRpnExpression(rpnExpStr, &errMsg);

        cout << mathExpStr<<endl;
        cout << rpnExpStr << endl;

        
        cout << err << endl;
        cout << errMsg << endl;


        cout << resStr << endl;
>>>>>>> bc41a2ed52eeeeff2fb9d76254e9f1d2c3ff8cff

        cout << "For exit press 'Esc'. For continue press anykey";
        exitCode = _getch();
        cout << endl;
    }

      
 

//    system("pause");
}



