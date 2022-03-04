#include <iostream>
using namespace std;

template<typename T>
class list
{
public:
	list();
	~list();
private:
	template<typename T>
	class node
	{
		node(T value, node *ptr)
		{
			this->value = value;
			this->ptrA = ptr;
		}
		~node()
		{

		}
		T value;
		node* ptrA;
	};
	node<T> head;
};

template<typename T>
list<T>::list()
{

}
template<typename T>
list<T>::~list()
{

}