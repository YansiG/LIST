#include <iostream>
#include <string>
#include <ctime>

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




template<typename T>
class binarytree
{
public:
	binarytree(T Data)
	{
		head = new node<T>();
		//head = nullptr;
		
	}
	void push(T data)
	{

	}
private:
	template<typename T>
	class Data
	{
	public:
		Data(string name, int count, double price, string date)
		{
			this->count = count;
			this->date = date;
			this->name = name;
			this->price = price;
		}
		string name;
		int count;
		double price;
		string date;
	};
	template<typename T>
	class node
	{
	public:
		node(node* ptrRight = nullptr, node* ptrLeft = nullptr)
		{
			right = ptrRight;
			left = ptrLeft;
		}
		node<T>* right;
		node<T>* left;
		node<T>* center;
	};
	node<T>* head;
};


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
		T* temp = new T[size-1];
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

template<typename T>
class steck
{
public:
	steck()
	{
		size = 0;
	}
	~steck()
	{
		delete[] array;
		array = nullptr;
	}
	void push(T value)
	{
		T* temp = new T[size+1];
		for (int i = 0; i <= size; i++)
		{
			temp[i] = array[i];
		}
		size++;
		temp[size - 1] = value;
		delete[] array;
		array = temp;
		temp = nullptr;
	}
	T pop()
	{
		T count = array[size-1];
		T* temp = new T[size - 1];
		for (int i = 0; i < size-1; i++)
		{
			temp[i] = array[i];
		}
		size--;
		delete[] array;
		array = temp;
		temp = nullptr;
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

int main()
{
	srand(time(0));
	system("chcp 1251");
	
}