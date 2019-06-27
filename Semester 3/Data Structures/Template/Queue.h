#pragma once

#include<iostream>

using namespace std;

template<class Type>
class queue
{
private:
	Type* q;
	int front;
	int end;
	int maxSize;
	int size;
public:
	queue(int s = 0)
	{
		q = new Type[s];
		maxSize = s;
		size = 0;
		front = -1;
		end = 0;
	}
	queue(const queue& obj)
	{
		delete q;
		front = obj.front;
		end = obj.end;
		maxSize = obj.maxSize;
		size = obj.size;
		q = new int[maxSize];
		for (int i = 0; i < maxSize; i++)
		{
			q[i] = obj.q[i];
		}
	}
	queue& operator=(const queue& obj)
	{
		delete q;
		front = obj.front;
		end = obj.end;
		maxSize = obj.maxSize;
		size = obj.size;
		q = new int[maxSize];
		for (int i = 0; i < maxSize; i++)
		{
			q[i] = obj.q[i];
		}
	}
	bool IsEmpty()
	{
		if (size == 0)
			return true;
		else
			return false;
	}
	bool IsFull()
	{
		return size == maxSize;
	}
	bool Enqueue(Type d)
	{
		if (!IsFull())
		{
			q[end] = d;
			end++;
			size++;
			if (end == maxSize)
				end = 0;
			return true;
		}
		else
			return false;
	}
	bool Dequeue(Type& d)
	{
		if (!IsEmpty())
		{
			front++;
			if (front == maxSize)
				front = 0;
			d = q[front];
			size--;
			return true;
		}
		else
			return false;
	}
};
class Set
{
private:
	int* element;
	int setSize;
public:
	Set(int n = 0)
	{
		element = new int[n];
		setSize = n;
		element[0] = 1;
	}
	Set(const Set& obj)
	{
		element = new int[obj.setSize];
		setSize = obj.setSize;
		for (int i = 0; i < setSize; i++)
		{
			element[i] = obj.element[i];
		}
	}

	Set& operator=(const Set& obj)
	{

		element = new int[obj.setSize];
		setSize = obj.setSize;
		for (int i = 0; i < setSize; i++)
		{
			element[i] = obj.element[i];
		}
		return *this;
	}
	void remove()
	{
		int* arr = new int[setSize - 1];
		for (int i = 0; i < setSize - 1; i++)
		{
			arr[i] = element[i];
		}
		delete[] element;
		setSize = setSize - 1;
		element = new int[setSize];
		for (int i = 0; i < setSize; i++)
		{
			element[i] = arr[i];
		}

	}
	void add(int x)
	{
		setSize++;
		int* arr = new int[setSize];
		for (int i = 0; i < setSize - 1; i++)
		{
			arr[i] = element[i];
		}
		delete[] element;

		element = new int[setSize];
		int i = 0;
		for (i = 0; i < setSize - 1; i++)
		{
			element[i] = arr[i];
		}
		element[i] = x;


	}
	int getlast()
	{
		if (setSize - 1 != -1)
			return element[setSize - 1];
		else
			return -1;
	}
	void setSizeSet()
	{
		setSize = 0;
	}
	void outputSet()
	{
		cout << "(";
		for (int i = 0; i < setSize; i++)
			cout << element[i] << ",";
		cout << ")";
	}
	~Set()
	{
		delete[] element;
	}
};