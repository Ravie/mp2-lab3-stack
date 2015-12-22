// Stack.cpp: определяет точку входа для консольного приложения.
//
#define _CRT_SECURE_NO_WARNINGS
#include "Stack.h"
#include "Parser.h"
#define MaxLen 201
using namespace std;

int main()
{
	char tmpch[MaxLen];
	double result;
	while (true)
	{
		cin >> tmpch;
		if (tmpch[0] == '\0')
			break;
		TParser tmp(tmpch);
		tmp.InfToPost();
		cout << "Infix: " << tmp.infix << endl;
		cout << "Postfix: " << tmp.postfix << endl;
		result = tmp.calcPost();
		cout << "Result: " << result << endl;
	}
	return 0;
}

