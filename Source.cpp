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
				while (count != index-2)
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
	doublelist<int> one;
	one.push_back(9);
	one.push_front(3);
	one.push_back(1);
	one.push_back(4);
	for (int i = 0; i < one.GetSize(); i++)
	{
		cout << one[i] << " ";
	}
	cout << endl;
	one.insert(7, 3);
	for (int i = 0; i < one.GetSize(); i++)
	{
		cout << one[i] << " ";
	}
	cout << endl;
	one.removeAt(2);
	for (int i = 0; i < one.GetSize(); i++)
	{
		cout << one[i] << " ";
	}
	cout << endl;
	one.pop_front();
	for (int i = 0; i < one.GetSize(); i++)
	{
		cout << one[i] << " ";
	}
	cout << endl;
}