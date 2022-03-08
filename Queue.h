#pragma once
#include<iostream>
#include<string>

using namespace std;

template<typename T>
class queue
{
public:
	queue()
	{
		size = 0;
	}
	~queue()
	{
		delete[] array;
		array = nullptr;
	}

	void push(T value)
	{
		size++;
		T* temp = new T[size];
		for (int i = 0; i <= size - 1; i++)
		{
			temp[i] = array[i];
		}
		delete[] array;
		array = temp;
		temp = nullptr;
		array[size - 1] = value;
	}
	T pop()
	{
		T count;
		count = array[0];
		T* temp = new T[size - 1];
		for (int i = 1; i < size; i++)
		{
			temp[i - 1] = array[i];
		}
		delete[] array;
		array = temp;
		temp = nullptr;
		size -= 1;
		return count;
	}
	void showArray()
	{
		for (int i = 0; i < size; i++)
		{
			cout << array[i] << " ";
		}
		cout << endl;
	}
	void Show(int index)
	{
		try
		{
			if (index > size - 1)
			{
				throw exception("Индекс не может быть больше размера стека.");
			}
			cout << array[index] << endl;
		}
		catch (exception ex)
		{
			cout << "Не удалось изменить элемент, так как " << ex.what() << endl;
		}
	}
	T change(int index, T value)
	{
		try
		{
			if (index > size - 1)
			{
				throw exception("Индекс не может быть больше размера стека.");
			}
			this->array[index] = value;
		}
		catch (exception ex)
		{
			cout << "Не удалось изменить элемент, так как " << ex.what() << endl;
		}
	}
private:
	int size;
	T* array = new T[size];
};