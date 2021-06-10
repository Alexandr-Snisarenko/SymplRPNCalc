#include "SyntaxCheck.h"


//���������� ���������
const char cLegalChr[] = "1234567890+-*/()"; //������ ���������� ��������
const char cNumber[] = "1234567890"; //�����
const char cOper[] = "+-*/"; //���������
const char cPrnts[] = "()"; //������

// �������� �� ������������ ���������� ��������
int CheckMathSymbolCombination(char curChr, char prevChr, string* errMsg )
{
	int err = 0;
	while (true)
	{
		// 2 ��������� ������
		if (strchr(cOper, curChr) != NULL and strchr(cOper, prevChr) != NULL)
		{
			*errMsg = (string)"Double operators" + curChr + prevChr;
			err = 1;
			break;
		}
		//����� ����� ����� ������� 
		if (curChr == cPrnts[0] and strchr(cNumber, prevChr) != NULL)
		{
			*errMsg = (string)"Number before left parenthesis";
			err = 1;
			break;
		}
		//����� ����� ������ ������� 
		if (strchr(cNumber, curChr) != NULL and prevChr == cPrnts[1])
		{
			*errMsg = (string)"Number after right parenthesis";
			err = 1;
			break;
		}
		//�������� ����� ������ ������� 
		if (curChr == cPrnts[1] and strchr(cOper, prevChr) != NULL)
		{
			*errMsg = (string)"Operator before right parenthesis";
			err = 1;
			break;
		}
		//�������� ����� ����� ������� 
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


	int cntLeftLPrnts = 0; //���-�� ����� ������
	int cntRightPrnts = 0; //���-�� ������ ������
	int err = 0;
	char prevChr = NULL; //���������� ��� ����������� ������� ��� ������� ������������������ ��������
	*pErrMsg = "";
	
	//����� ������ ���������
	for (char curChr : mathStr)
	{
		//��������� �� ���������� �������
		if (strchr(cLegalChr, curChr) == NULL)
		{
			*pErrMsg = (string) "Unexpected symbol:'" + curChr + "'";
			err = 1; 
			break;
		}

		//�������� ������� �������. ���� �������� - ������
		if (strchr(cOper, mathStr[0]) != NULL)
		{
			*pErrMsg = (string)"First symbol is Operator.";
			err = 1;
			break;
		}

		//�������� �������� �������. ���� �������� - ������
		if (strchr(cOper, mathStr[mathStr.length()-1]) != NULL)
		{
			*pErrMsg = (string)"Last symbol is Operator.";
			err = 1;
			break;
		}

		//���� ���� ���������� ������ - ��������� �� ���������� ���������� ��������
		if (prevChr != NULL and (err = CheckMathSymbolCombination(curChr, prevChr, pErrMsg)))
			break;

		//������� ������
		if (curChr == '(') 
			cntLeftLPrnts++;
		if (curChr == ')') 
			cntRightPrnts++;
		
		//���� ������ ������ ������ ��� ����� - ��������� ������� ������
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
		//��������� ���������� ����� � ������ ������
		if (cntLeftLPrnts != cntRightPrnts)
		{
			*pErrMsg = (string)"Count of left parentheses not equal to count of rihgt parentheses.";
			err = 1;
		}

	}

	return err;
}
