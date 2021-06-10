#include "CalcRpnExpression.h"

//���������� ���������
const char cOper[] = "+-*/";

int CalcRpnExpression(queue<string> rpnQu, double* calcRes, string* errMsg)
{
	double res = 0; //��� ��������� ������������� ����������
	double n1, n2; //��� ������������� �������� ��������� ��� ���������� ��������
	int err = 0; //��� ������
	string curTok = ""; //������� �����
	stack <string> expStk; //������� ���� ��� ��������� ���������

	//�������� ��������� �������, ������� �������� ���������� � ������� RPN 
	while (!rpnQu.empty())
	{
		//����� ����� �� �������
		curTok = rpnQu.front();
		rpnQu.pop();
		
		//���� ����� - �� �������� - �������� ��� � ������� ���� (�.�. � ����� ����� ������ �����)
		if (strchr(cOper, curTok[0]) == NULL)
		{
			expStk.push(curTok);
		}
		else //�����, ���� ������� ����� - ��������, �� ��������� ������� �������� ��� ����� �������� ���������� �� �������� �����
		{
			//���� � ����� ������ ���� ��������� - ��� �� ����� �� ���
			if (expStk.size() < 2)
			{
				err = 1;
				*errMsg = "Expression error.";
				break;
			}

			//�������� �������� �� ����� � ��������� �� � ����
			n2 = stod(expStk.top());
			expStk.pop();
			n1 = stod(expStk.top());
			expStk.pop();

			//���������� �������� � ����������� �� �������� �������� ���������
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

	//�������� ���������. ������ ���� � ����� � ������ (�������) � ������������ �������� �����. ���� ��� �� ��� - ������.
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

