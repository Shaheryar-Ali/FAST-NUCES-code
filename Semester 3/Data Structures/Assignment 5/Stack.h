#pragma once

template<class T >
class Stack
{
	T** s;
	int size;
	int curr;
public:
	Stack(int n = 1)
	{
		size = n;
		s = new T*[n];
		curr = 0;
	}
	Stack(const Stack& obj)
	{
		size = obj.size;
		s = new T[size];
		curr = obj.curr;
		T** arr = new T*[size];
		for (int i = 0; i < size; i++)
			arr[i] = obj.s[i];
		for (int k = 0; k < size; k++)
			s[k] = arr[k];
	}
	Stack& operator=(const Stack& obj)
	{
		size = obj.size;
		s = new[size];
		curr = obj.curr;
		T** arr = new T*[size];
		for (int i = 0; i < size; i++)
			arr[i] = obj.s[i];
		for (int k = 0; k < size; k++)
			s[k] = arr[k];
		return *this;
	}

	bool IsEmpty()
	{
		if (curr == 0)
			return true;
		else
			return false;
	}
	bool Isfull()
	{
		if (curr == size)
			return true;
		else
			return false;
	}
	void Push(T* d)
	{
		if (Isfull())
		{
			s = size_inc(s);
		}
		s[curr] = d;
		curr++;
	}
	
	bool pop(T*& d)
	{
		if (!IsEmpty()) {
			curr--;
			d = s[curr];
			return true;
		}
		else
		{
			return false;
		}
	}

	T** size_inc(T** arr)
	{
		T** arr2 = new T* [size*2];
		size = size * 2;
		for(int i = 0; i < curr; i++)
		{
			arr2[i] = arr[i];
		}
		
		delete arr;
		return arr2;
	}

};