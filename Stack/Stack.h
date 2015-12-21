#pragma once

template <class T>
class TStack
{
	int MaxSize;
	int Index;
	T *Array;
public:
	TStack(int len = 10);
	TStack(const TStack &s);
	~TStack();

	TStack &operator=(const TStack &s);

	bool IsEmpty();
	bool IsFull();
	void PushElem(const T &LastElem);
	T Top();
	T Pop();
	bool CheckEquation(char *str);
};