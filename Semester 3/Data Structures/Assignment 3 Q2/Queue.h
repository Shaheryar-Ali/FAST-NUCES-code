#pragma once

template <class T>

class Queue
{
	private:
		int size_max;
		T *que;
		int index_s;			//Points to start element
		int index_end;			//Points to last element
		int c_size;
	public:
		Queue();
		Queue(int n);
		void Enqueue(T d);
		void Dequeue(T& d);
		bool IsEmpty();
		T *extend(T *arr);
		bool IsFull();
};

template <class T>
Queue<T>::Queue(int n)
{
	size_max = n;
	T* que =new T [size_max];
	index_s = -1;
	index_end = 0;
	c_size = 0;
}

template <class T>
Queue<T>::Queue()
{
	int size_max = 1;
	T *que = new T[1];
	index_s = -1;
	index_end = 0;
	c_size = 0;
}

template <class T>
void Queue<T>::Enqueue(T d)
{
		if (IsFull())
			que = extend(que);

		que[index_end] = d;
		index_end++;
		if (index_end == size_max)
			index_end = 0;
		c_size++;
		index_s++;
}

template <class T>
T* Queue<T>::extend(T *arr)
{
	int temp = size_max;
	size_max = size_max * 2;
	T* arr2 = new T [size_max];
	for (int i = 0; i < size_max; i++)
	{
		arr2[i] = arr[i];
	}
	delete[]arr;
	return arr2;
}

template <class T>
void Queue<T>::Dequeue(T &d)
{
	if (!IsEmpty())
	{
		d = que[index_s];
		index_s++;
		if (index_s == size_max)
			index_s = 0;
	}
}

template <class T>
bool Queue<T>::IsEmpty()
{
	if (c_size == 0)
		return true;
	else
		return false;
}

template <class T>
bool Queue<T>::IsFull()
{
	if (c_size + 1 == size_max)
		return true;
	else
		return false;
}