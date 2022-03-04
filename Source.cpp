#include <iostream>
using namespace std;

template<typename T>
class list
{
public:
	list();
	~list();
	void push_back(T data);
	int GetSize() { return size; }
	T& operator [](const int index);
private:
	template<typename T>
	class node
	{
	public:
		node(T value, node *ptr = nullptr)
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
	node<T> *head;
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

}

template<typename T>
void list<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new node<T>(data);
	}
	else
	{
		node<T>* temp = this->head;
		while (temp->ptr_next != nullptr)
		{
			temp = temp->ptr_next;
		}
		temp->ptr_next = new node<T>(data);
	}
	size++;
}

template <typename T>
T& list<T>::operator[](const int index)
{
	int count = 0;
	node<t>* temp = head;
	while (count < index)//����������� ����������
	{
		temp = temp->ptr_next;
		count++;
	}
	return temp->value;
}

int main()
{
	list<int>one;
	one.push_back(5);
	one.push_back(8);
	one.push_back(1);
}