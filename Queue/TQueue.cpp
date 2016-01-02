#define _CRT_SECURE_NO_WARNINGS
#include "Queue.h"
using namespace std;

void main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");

	int Size;
	double p, q;
	cout << "Введите длину очереди: ";
	cin >> Size;

	cout << "Вероятность пополнения очереди: ";
	cin >> p;
	p = p * 100;

	cout << "Вероятность удаления из очереди: ";
	cin >> q;
	q = q * 100;

	for (int i = 0; i < 10; i++)
	{
		TQueue <int> Q(Size);
		while (!Q.IsFull())
		{
			double p1 = rand() % 100 + 1;
			double q1 = rand() % 100 + 1;
			if (p1 < p)
			{
				Q.Push(p1);
				cout << Q;
			}
			if (q1 < q)
			{
				if (!Q.IsEmpty())
				{
					int tmp = Q.Pop();
					cout << Q;
				}
				else
				{
					cout << "Очередь пуста\n";
					break;
				}
			}
		}
		if (!Q.IsEmpty())
		{
			cout << Q;
			cout << "Очередь заполнена\n";
		}
	}

}