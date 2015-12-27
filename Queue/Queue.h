#pragma once

template <class T>
class TQueue
{
private:
	int begin, end, len, MaxSize;
	T *Array;
public:
	TQueue(int _maxsize = 10)
	{
		if (_maxsize <= 0)
			throw _maxsize;
		MaxSize = _maxsize;
		Array = new T[MaxSize];
		begin = 0;
		end = -1;
		len = 0;
	}

	virtual ~TQueue() 
	{ 
		delete[] Array; 
	}

	TQueue(const TQueue& q)
	{
		MaxSize = q.MaxSize;
		begin = q.begin;
		end = q.end;
		len = q.len;
		Array = new T[MaxSize];
		for (int i = 0; i < MaxSize; i++)
			Array[i] = q.Array[i];
	}

	bool IsEmpty()
	{
		return len == 0;
	}

	bool IsFull()
	{
		return len == MaxSize;
	}

	void Push(const T n)
	{
		if (len == MaxSize)
			throw len;
		if (end < MaxSize - 1)
			end++;
		else end = 0;
		len++;
		Array[end] = n;
	}

	T Pop()
	{
		if (!len)
			throw - 1;
		T tmp = Array[begin];
		if (begin < MaxSize - 1)
			begin++;
		else begin = 0;
		len--;
		return tmp;
	}

	T Front()
	{
		if (!len)
			throw - 1;
		return Array[begin];
	}

	T Back()
	{
		if (!len)
			throw - 1;
		return Array[end];
	}

	void Clear()
	{
		begin = 0;
		end = -1;
		len = 0;
	}
};
