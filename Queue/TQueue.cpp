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
	TQueue <int> Q(Size);

	cout << "Вероятность пополнения очереди: ";
	cin >> p;
	p = p * 100;

	cout << "Вероятность удаления из очереди: ";
	cin >> q;
	q = q * 100;

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
		}
	}
}