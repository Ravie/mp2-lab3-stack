#pragma once 
#include <iostream>
#include <ctime>

using namespace std;
template <class T>
class TQueue
{
private:
	int begin, end, len, MaxSize;
	T *Array;
public:
	TQueue(int _MaxSize = 10)
	{
		MaxSize = _MaxSize;
		Array = new T[MaxSize];
		begin = 0;
		end = -1;
		len = 0;
	}

	~TQueue()
	{
		delete[]Array;
	}

	TQueue(const TQueue &Q)
	{
		MaxSize = Q.MaxSize;
		begin = Q.begin;
		len = Q.len;
		end = Q.end;
	}

	bool IsEmpty()
	{
		return (len == 0);
	}

	bool IsFull()
	{
		return (len == MaxSize);
	}

	void Push(const T n)
	{
		if (end < MaxSize - 1)
			end++;
		else end = 0;
		Array[end] = n;
		len++;
	}

	T Pop()
	{
		T tmp = Array[begin];
		if (IsEmpty())
			throw "Очередь пуста";
		else
		{
			if (begin < MaxSize - 1)
				begin++;
			else
				begin = 0;
		}
		len--;
		return tmp;
	}

	T Top()
	{
		if (IsEmpty())
			throw - 1;
		return Array[begin];
	}

	friend ostream& operator<<(ostream &out, const TQueue <T> &Q)
	{
		if (Q.len == 0)
			out << "Очередь пуста\n";
		else
		{
			out << "Очередь: ";
			for (int i = 0; i < Q.len; i++)
				out << Q.Array[i] << " ";
			out << "\n";
		}
		return out;
	}
};


