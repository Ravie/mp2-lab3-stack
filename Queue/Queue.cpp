#include "Queue.h"
#include <stdlib.h>
#include <locale.h>
#include <iostream>
using namespace std;


void main()
{
	int n;
	double p;
	double *q;
	setlocale(LC_CTYPE, "Russian");
	char c;
	do
	{
		cout << "Число задач:" << endl;
		do
		{
			cin >> n;
			if (n <= 0)
				cout << "Отрицательное значение. Введите еще раз:" << endl;
		} while (n <= 0);
		TQueue <int> a(n);
		q = new double[n];
		for (int i = 0; i < n; i++)
			q[i] = rand() % 100 / 100.0;
		cout << "Вероятность появления задачи (%):" << endl;
		do
		{
			cin >> p;
			if ((p < 0) || (p>100))
				cout << "Невозможная вероятность. Введите еще раз:" << endl;
		} while ((p < 0) || (p>100));
		p /= 100.0;
		cout << "Состояние очереди:" << endl;
		int j = 0;
		for (int i = 0; i < n; i++)
		{
			if (q[i] >= p)
				continue;
			int tmp = (rand() % 100) + 1;
			a.Push(tmp);
			j++;
			cout << "Задача №" << i << " - " << tmp << "; вероятность " << q[i] << endl;
			while ((a.Front() < a.Back()) && (!a.IsEmpty()))
				cout << "Задача выполнена - " << a.Pop() << endl;
		}
		while (!a.IsEmpty())
			cout << "Задача выполнена - " << a.Pop() << endl;
		if (!j)
			cout << "В очередь не поступило ни одной задачи" << endl;
		else cout << "Выполнено " << j << " задач" << endl;
		cout << "Введите 'y' для продолжения работы:" << endl;
		cin >> c;
	} while (c == 'y');
}