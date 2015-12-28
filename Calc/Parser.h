#pragma once
#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <sstream>
#include "Stack.h"
#define MaxLen 201
#define NumLen 100
using namespace std;

class TParser
{
public:
	char infix[MaxLen];
	char postfix[MaxLen];
	TStack<double> st_d;
	TStack<char> st_c;
	int NumbersLen[NumLen]; // массив длин чисел
public:
	TParser(char *_str);
	~TParser();
	int Priority(char _ch);
	bool IsOperation(char _ch);
	bool IsNumber(char _ch);
	bool IsFuction(char _ch);
	void InfToPost();
	double calcPost();
	void Function(char* _ch, int _k, double &_res);
};

TParser::TParser(char *_str) :st_d(100), st_c(100)
{
	for (int i = 0; i < NumLen; i++)
		NumbersLen[i] = 0;
	if (_str == NULL)
		infix[0] = '\0';
	else
		strcpy_s(infix, _str);
}
TParser :: ~TParser() {}

int TParser::Priority(char _ch)
{
	int n;
	switch (_ch)
	{
	case '(':
	case ')': n = 0; break;
	case '+':
	case '-': n = 1; break;
	case '*':
	case '/': n = 2; break;
	case '^': n = 3; break;
	default:
		n = -1; break;
	}
	return n;
}

bool TParser::IsOperation(char _ch)
{

	return (_ch == '+' || _ch == '-' || _ch == '*' || _ch == '/' || _ch == '(' || _ch == ')' || _ch == '^');
}

bool TParser::IsNumber(char _ch)
{
	return (_ch == '.' || _ch == ',' || _ch == '0' || _ch == '1' || _ch == '2' || _ch == '3' || _ch == '4' || _ch == '5' || _ch == '6' || _ch == '7' || _ch == '8' || _ch == '9' || _ch == 'e' || _ch == 'p');
}

bool TParser::IsFuction(char _ch)
{
	return (_ch == 's' || _ch == 'l' || _ch == 'c' || _ch == 't' || _ch == 'a');
}

void TParser::Function(char* _ch, int _k, double &_res)
{
	switch (_ch[_k])
	{
	case 's':
		if (_ch[_k + 3] == 'h')
		{
			_res = sinh(_res);
		}
		else
		{
			_res = sin(_res);
		}
		break;
	case 'l':
		if (_ch[_k + 3] == '1')
		{
			_res = log10(_res);
		}
		else
		{
			_res = log(_res);
		}
		break;
	case 'c':
		if (_ch[_k + 3] == 'h')
		{
			_res = cosh(_res);
		}
		else
		{
			_res = cos(_res);
		}
		break;
	case 't':
		if (_ch[_k + 3] == 'h')
		{
			_res = tanh(_res);
		}
		else
		{
			_res = tan(_res);
		}
		break;
	}
}

void TParser::InfToPost()
{
	st_c.ClearStack(); st_d.ClearStack();

	int i = 0, j = 0, k = 0;
	while (infix[i] != '\0')
	{
		if (IsOperation(infix[i]))
		{
			if (infix[i] == '(')
			{
				if (i == 0 || IsOperation(infix[i - 1]))
				{
					st_c.PushElem(infix[i]);
					i++;
				}
				else
				{// вставляем * в случае, если перед скобкой стоит число
					st_c.PushElem('*');
					st_c.PushElem(infix[i]);
					i++;
				}
			}
			else
			{
				if (infix[i] == ')')
				{// накопленный в предыдущей ветке st_c разбираем на ОПН
					while (st_c.Top() != '(')
						postfix[j++] = st_c.Pop();
					int tmp = st_c.Pop();
					i++;
				}
				else
				{
					if (infix[i] == '-' && (i == 0 || infix[i - 1] == '('))
					{// обработка унарного минуса
						postfix[j++] = '0';
						NumbersLen[k++] = 1;
						i++;
						while (IsNumber(infix[i]))
						{// определяем длины чисел в инф записи
							NumbersLen[k] += 1;
							postfix[j++] = infix[i++];
						}
						k++;
						postfix[j++] = '-';
					}
					else
					{
						if (st_c.IsEmpty() || Priority(infix[i]) > Priority(st_c.Top()))
						{// добавляем в стэк оператор
							st_c.PushElem(infix[i]);
							i++;
						}
						else
							if (Priority(infix[i]) < Priority(st_c.Top()))
							{// выталкиваем из стэка оператор
								while (!st_c.IsEmpty() && Priority(infix[i]) <= Priority(st_c.Top()))
								{
									postfix[j] = st_c.Pop();
									j++;
								}
								st_c.PushElem(infix[i]);
								i++;
							}
							else
							{
								st_c.PushElem(infix[i]);
								i++;
							}
					}
				}
			}
		}
		else
		{
			if (IsNumber(infix[i]))
			{// переписываем в ОПН числа, учитывая NumbersLen
				while (IsNumber(infix[i]))
				{
					NumbersLen[k] += 1;
					postfix[j] = infix[i];
					j++;
					i++;
				}
				k++;
			}
		}
		if (IsFuction(infix[i]))
		{
			int m = 0, n = i, l = 0;
			char *len = new char[195];
			while (infix[i] != '(')
				i++;
			i++;
			while (infix[i] != ')')
			{
				len[m] = infix[i];
				m++;
				i++;
			}
			i++;
			len[m] = '\0';
			TParser tmp(len);
			tmp.InfToPost();
			double reztmp = tmp.calcPost();
			Function(infix, n, reztmp); // замена строки на функцию
			char len2[30];
			sprintf(len2, "%f", reztmp);
			if (len2[0] == '-')
			{
				postfix[j] = '0';
				j++;
				NumbersLen[k] += 1;
				k++;
				l++;
				while (len2[l] != '\0')
				{
					NumbersLen[k] += 1;
					postfix[j] = len2[l];
					j++;
					l++;
				}
				k++;
				postfix[j] = '-';
				j++;
			}
			else
			{
				while (len2[l] != '\0')
				{
					NumbersLen[k] += 1;
					postfix[j] = len2[l];
					j++;
					l++;
				}
			}
			k++;
		}
	}
	while (!st_c.IsEmpty())
	{// вынимаем остальное из стэка
		postfix[j] = st_c.Pop();
		j++;
	}
	postfix[j] = '\0';
}

double TParser::calcPost()
{
	int i = 0, k = 0;
	st_c.ClearStack(); st_d.ClearStack();
	while (postfix[i] != '\0')
	{
		if (IsNumber(postfix[i]))
		{
			if (postfix[i] == 'e')
			{
				st_d.PushElem(M_E);
				i++;
			}
			else
				if (postfix[i] == 'p')
				{
					st_d.PushElem(M_PI);
					i++;
				}
				else
				{ // преобразование строкового числа
					int j = 0;
					double tmp;
					char *len3;
					len3 = new char[NumbersLen[k]];
					for (; j < NumbersLen[k]; j++)
						len3[j] = postfix[i + j];
					tmp = atof(len3);
					st_d.PushElem(tmp);
					i += NumbersLen[k];
					k++;
					delete[]len3;
				}
		}
		else
		{
			double reg1, reg2;
			reg1 = st_d.Pop();
			reg2 = st_d.Pop();
			switch (postfix[i])
			{
			case '+': st_d.PushElem(reg1 + reg2); break;
			case '-': st_d.PushElem(reg2 - reg1); break;
			case '*': st_d.PushElem(reg1 * reg2); break;
			case '/':
				if (reg1 == 0)
					throw "DIV_BY_ZERO";
				st_d.PushElem(reg2 / reg1);
				break;
			case '^': st_d.PushElem(exp(reg1*log(reg2))); break;
			}
			i++;
		}
	}
	return st_d.Pop();
}


