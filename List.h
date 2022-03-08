#pragma once
#include<iostream>
#include<string>

using namespace std;

template<typename T>
class list
{
public:
	list();
	~list();
	void pop_front();
	void clear();
	void push_back(T value);
	int GetSize() { return size; }
	void push_front(T value);
	T& operator [](const int index);
	void insert(T value, int index);
	void removeAt(int index);
	void pop_back();
private:
	template<typename T>
	class node
	{
	public:
		node(T value, node* ptr = nullptr)
		{
			this->value = value;
			this->ptr_next = ptr;
		}
		~node()
		{

		}
		T value;
		node* ptr_next;
	};
	node<T>* head;
	int size;
};
template<typename T>
list<T>::list()
{
	size = 0;
	head = nullptr;
}
template<typename T>
list<T>::~list()
{
	clear();
}
template<typename T>
void list<T>::push_back(T value)
{
	if (head == nullptr)
	{
		head = new node<T>(value);
	}
	else
	{
		node<T>* temp = this->head;
		while (temp->ptr_next != nullptr)
		{
			temp = temp->ptr_next;
		}
		temp->ptr_next = new node<T>(value);
	}
	size++;
}
template<typename T>
void list<T>::push_front(T value)
{
	head = new node<T>(value, head);//!!!!!!!!!!!!!!!!!!!!!!!!!!!
	/*node<T>* temp(value);
	temp->ptr_next = head;
	head = temp;*/
	size++;
}
template <typename T>
T& list<T>::operator[](const int index)
{
	int count = 0;
	node<T>* temp = head;
	try
	{
		if (index > size - 1)
		{
			throw exception("Индекс не может быть больше размера стека.");
		}
		while (count < index)//собственная реализация
		{
			temp = temp->ptr_next;
			count++;
		}
	}
	catch (exception ex)
	{
		cout << "Ошибка. " << ex.what() << endl;
	}
	return temp->value;
}
template<typename T>
void list<T>::pop_front()
{
	node<T>* temp = head;
	head = head->ptr_next;
	delete temp;
	size--;
}
template<typename T>
void list<T>::clear()
{
	while (size)
	{
		pop_front();
	}
}
template<typename T>
void list<T>::insert(T value, int index)
{
	if (index == 0)
	{
		push_front(value);
	}
	else
	{
		node<T>* temp = head;
		for (int i = 0; i < index - 1; i++)
		{
			temp = temp->ptr_next;
		}
		/*node<T>* elem = new node(value, temp->ptr_next);
		temp->ptr_next = elem;*/
		temp->ptr_next = new node<T>(value, temp->ptr_next);
		size++;
	}
}
template<typename T>
void list<T>::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		node<T>* temp_previe = head;
		for (int i = 0; i < index - 1; i++)
		{
			temp_previe = temp_previe->ptr_next;
		}
		node<T>* temp_todelete = temp_previe->ptr_next;
		temp_previe->ptr_next = temp_todelete->ptr_next;
		delete temp_todelete;
	}
	size--;
}
template<typename T>
void list<T>::pop_back()
{
	removeAt(size - 1);
}