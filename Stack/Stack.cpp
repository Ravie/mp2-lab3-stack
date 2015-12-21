// Stack.cpp: определяет точку входа для консольного приложения.
//

#include "cstdio"


template <class T> 
TStack<T>::TStack(int len = 10)
{
	if (len <= 0)
		throw "NEGATIVE_SIZE";
	MaxSize = len;
	Index = -1;
	Array = new T[MaxSize];
}

template <class T>
TStack<T>::TStack(const TStack &s)
{
	MaxSize = s.MaxSize;
	Index = s.Index;
	Array = new T[MaxSize];
	for (int i = 0; i < MaxSize; i++)
		Array[i] = s.Array[i];
}

template <class T>
TStack<T>::~TStack()
{
	delete[] Array;
	Array = nullptr;
}

template <class T>
TStack<T> &TStack<T>::operator=(const TStack &s)
{
	if (MaxSize != s.MaxSize)
	{
		delete[] Array;
		MaxSize = s.MaxSize;
		Array = new T[MaxSize];
	}
	Index = s.Index;
	for (int i = 0; i <= Index; i++)
		Array[i] = s.Array[i];
	return *this;
}

template <class T>
TStack<T> bool TStack<T>::IsEmpty()
{
	if (Index == -1)
		return true;
	return false;
}

template <class T>
TStack<T> bool TStack<T>::IsFull()
{
	return (Index == MaxSize - 1);
}

template <class T>
TStack<T> void TStack<T>::PushElem(const T &LastElem)
{
	if (IsFull())
		throw Index;
	Array[++Index] = LastElem;
}

template <class T>
TStack<T> void TStack<T>::Top()
{
	if (Index < 0)
		throw Index;
	return Array[Index];
}

template <class T>
TStack<T> void TStack<T>::Pop()
{
	if (IsEmpty())
		throw Index;
	T.tmp = Array[Index];
	Index--;
	return tmp;
}

template <class T>
TStack<T> bool TStack<T>::CheckEquation(char *str)
{
	TStack<char> S(100);
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '(')
			s.PushElem(str[i]);
		if (str[i] == ')')
		{
			if (s.IsEmpty())
				return false;
			s.Pop();
		}
	}
	if (s.IsEmpty())
		return true;
	return false;
}