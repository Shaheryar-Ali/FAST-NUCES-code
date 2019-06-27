#pragma once

template<class Type >
class Stack
{
	Type* s;
	int size;
	int stkptr;
public:
	Stack(int n = 0)
	{
		size = n;
		s = new Type[n];
		stkptr = 0;
	}
	Stack(const Stack& obj)
	{
		size = obj.size;
		s = new Type[size];
		stkptr = obj.stkptr;
		Type* arr = new Type[size];
		for (int i = 0; i < size; i++)
			arr[i] = obj.s[i];
		for (int k = 0; k < size; k++)
			s[k] = arr[k];
	}
	Stack& operator=(const Stack& obj)
	{
		size = obj.size;
		s = new Type [size];
		stkptr = obj.stkptr;
		Type* arr = new Type[size];
		for (int i = 0; i < size; i++)
			arr[i] = obj.s[i];
		for (int k = 0; k < size; k++)
			s[k] = arr[k];
		return *this;
	}

	bool IsEmpty()
	{
		if (stkptr == 0)
			return true;
		else
			return false;
	}
	bool Isfull()
	{
		if (stkptr == size)
			return true;
		else
			return false;
	}
	bool Push(int d)
	{
		if (!Isfull()) {
			s[stkptr] = d;
			stkptr++;
			return true;

		}
		else
			return false;
	}
	bool pop(Type& d)
	{
		if (!IsEmpty()) {
			stkptr--;
			d = s[stkptr];
			return true;
		}
		else
		{
			return false;
		}
	}
	int top(Type& d)
	{
		if (!IsEmpty())
		{
			d = s[stkptr - 1];
			return (stkptr - 1);
		}
		else
			return (stkptr - 1);
	}

	int element()
	{
		return stkptr;
	}

};