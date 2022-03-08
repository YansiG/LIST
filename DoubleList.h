#pragma once
#include<iostream>
#include<string>

using namespace std;


template<typename T>
class doublelist
{
public:
	doublelist()
	{
		size = 0;
		head = nullptr;
		tail = nullptr;
	}
	~doublelist()
	{
		clear();
	}
	int GetSize() { return size; }
	void push_back(T value)
	{
		if (head == nullptr && tail == nullptr)
		{
			head = new node<T>(value);
			tail = head;
			size++;
		}
		else if (head == tail)
		{
			//node<T>* temp = new node<T>(value, head);
			head->ptr_next = new node<T>(value, head);
			tail = head->ptr_next;
			/*head->ptr_next = tail;
			tail->ptr_preview = head;
			tail->ptr_next = new node<T>(value, tail);
			tail = tail->ptr_next;*/
			size++;
		}
		else
		{
			tail->ptr_next = new node<T>(value, tail);
			tail = tail->ptr_next;
			/*node<T>* temp(value, tail);
			tail->ptr_next = temp;
			tail = temp;*/
			size++;
		}
	}
	void push_front(T value)
	{
		head->ptr_preview = new node<T>(value, nullptr, head);
		head = head->ptr_preview;
		size++;
	}
	T& operator[](const int index)
	{
		int count;
		if ((size / 2) > (size - (index + 1)))
		{
			//С хвоста
			count = size - 1;
			node<T>* temp = tail;
			while (count != index)
			{
				temp = temp->ptr_preview;
				count--;
			}
			return temp->data;
		}
		else
		{
			//С начала
			count = 0;
			node<T>* temp = head;
			while (count != index)
			{
				temp = temp->ptr_next;
				count++;
			}
			return temp->data;
		}
	}
	void insert(T value, const int index)
	{
		if (index == 0)
		{
			push_front(value);
		}
		else if (index == size)
		{
			push_back(value);
		}
		else
		{
			int count;
			if ((size / 2) > (size - (index + 1)))
			{
				count = size - 1;
				node<T>* temp = tail;
				while (count != index)
				{
					temp = temp->ptr_preview;
					count--;
				}
				node<T>* elem = new node<T>(value, temp->ptr_preview, temp);
				temp->ptr_preview = elem;
				while (count != index - 2)
				{
					temp = temp->ptr_preview;
					count--;
				}
				temp->ptr_next = elem;
				size++;
			}
			else
			{
				count = 0;
				node<T>* temp = head;
				while (count != index)
				{
					temp = temp->ptr_next;
					count++;
				}
				node<T>* elem = new node<T>(value, temp->ptr_preview, temp);
				temp->ptr_preview = elem;
				while (count != index - 2)
				{
					temp = temp->ptr_preview;
					count--;
				}
				temp->ptr_next = elem;
				size++;
			}

		}
	}
	void pop_front()
	{
		node<T>* temp = head;
		head = head->ptr_next;
		head->ptr_preview = nullptr;
		delete temp;
		size--;
	}
	void pop_back()
	{
		node<T>* temp = tail;
		tail = tail->ptr_preview;
		tail->ptr_next = nullptr;
		delete temp;
		size--;
	}
	void clear()
	{
		while (size)
		{
			pop_front();
		}
	}
	void removeAt(const int index)
	{
		if (index == 0)
		{
			pop_front();
		}
		else if (index == size - 1)
		{
			pop_back();
		}
		else
		{
			int count;
			if ((size / 2) > (size - (index + 1)))
			{
				count = size - 1;
				node<T>* temp = tail;
				while (count != index + 1)
				{
					temp = temp->ptr_preview;
					count--;
				}
				node<T>* tempDel = temp->ptr_preview;
				temp->ptr_preview = tempDel->ptr_preview;
				while (count != index)
				{
					temp = temp->ptr_preview;
					count--;
				}
				temp->ptr_next = tempDel->ptr_next;
				delete tempDel;
				size--;
			}
			else
			{
				count = 0;
				node<T>* temp = head;
				while (count != index - 1)
				{
					temp = temp->ptr_next;
					count++;
				}
				node<T>* tempDel = temp->ptr_next;
				temp->ptr_next = tempDel->ptr_next;
				while (count != index)
				{
					temp = temp->ptr_next;
					count++;
				}
				temp->ptr_preview = tempDel->ptr_preview;
				delete tempDel;
				size--;
			}
		}
	}
private:
	template<typename T>
	class node
	{
	public:
		node(T data, node* ptr_preview = nullptr, node* ptr_next = nullptr)
		{
			this->data = data;
			this->ptr_next = ptr_next;
			this->ptr_preview = ptr_preview;
		}
		node* ptr_next;
		node* ptr_preview;
		T data;
	};
	node<T>* head;
	node<T>* tail;
	int size;
};